/*****************************************************************************************************************************
 * 
 * @file xml_style.c
 * @brief the implementation of the functions in xml_style.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 2.0 (last update 01/02/2025)
 * 
 ****************************************************************************************************************************/


#include "xml_style.h"

void use_xml_style_file(GtkApplication *app, arg *myarg)
{
    char line[MAX_LINE_SIZE]; // to store the line
    int status; // to check the line (-1 for empty line, -2 for line with EOF, 0 for valid line)

    // if the source file is not provided
    if(myarg->argc < 2)
    {
        perror("file path is required\n");
        exit(1);
    }

    // if the extension is not .elkouri
    if(!valid_extension(myarg->argv[1]))
    {
        perror("invalid extension, must be end with .x\n");
        exit(1);
    }

    // open the source file
    FILE *file_to_read = fopen(myarg->argv[1], "r");
    if(!file_to_read)
    {
        perror("file not found");
        exit(1);
    }

    // open the output file
    FILE *temp = fopen("gtk.c", "w");
    
    // if the file is not valie
    if(!valid_file(file_to_read))
    {
        perror("file is not valid\n");
        exit(1);
    }

    // rewind the file to the beginning
    rewind(file_to_read);

    // write the headers 
    fprintf(temp, "#include <gtk/gtk.h>\n");
    fprintf(temp, "#include \"../include/GtkFramework/GtkFramework.h\"\n");

    // check if the signals file is provided
    if(myarg->argc > 2)
    {
        // if the signals file is provided but not exist
        FILE *signals = fopen(myarg->argv[2], "r");
        if(!signals)
        {
            perror("signals file not found");
            exit(1);
        }

        do
        {

        if((status = read_line(line, signals)) != -1)
            fprintf(temp, "%s\n", line);

        } while(status != -2);

        fclose(signals); 
    }


    fprintf(temp, "static void activate(GtkApplication *app, gpointer data){\n");


    char car;
    
    do
    {

    // read line and check if the line is empty (if it is empty, continue to the next line)
    if((status = read_line(line, file_to_read)) == -1) continue;

    // if the line is a comment, continue to the next line
    if(is_comment(line)) continue;

    // if the line is a closing tag, write the closing tag function after extracting his name and his arguments in the output file
    if(is_close_tag(line))
    {
        fprintf(temp, "%s;\n", extraire_contenu(line));
        continue;
    }

    // soo the line is a opening tag
    // parse the line and extract the widget name and its arguments to a linked list
    NodeA *widget = parse_widget(line);
    
    // call the database function corresponding to the widget name
    call_database_function(widget, file_to_read);
    
    free_list(widget);

    } while(status != -2);

    printf("ici\n");
    
    fprintf(temp, "}\n");
    fprintf(temp, "int main(int argc, char *argv[]){\n");
    fprintf(temp, "    GtkApplication *app = gtk_application_new(\"org.example.app\", G_APPLICATION_DEFAULT_FLAGS);\n");
    fprintf(temp, "    g_signal_connect(app, \"activate\", G_CALLBACK(activate), NULL);\n");
    fprintf(temp, "    int status = g_application_run(G_APPLICATION(app), argc, argv);\n");
    fprintf(temp, "    g_object_unref(app);\n");
    fprintf(temp, "    return status;\n");
    fprintf(temp, "}\n");

    fclose(temp);
    fclose(file_to_read);
    // remove("temp.c");
}

    
int main(int argc, char *argv[])
{
    arg myarg;
    myarg.argc = argc;
    myarg.argv = argv;
    use_xml_style_file(NULL, &myarg);

    system("make");
    system("application");
    return 0;
}