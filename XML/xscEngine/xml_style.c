/*****************************************************************************************************************************
 * 
 * @file xml_style.c
 * @brief the implementation of the functions in xml_style.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 3.0 (last update 05/02/2025)
 * 
 ****************************************************************************************************************************/


#include "xml_style.h"

void call_database_function(NodeA *widget_linked_list, FILE *file)
{

    if(strcmp(widget_linked_list->val, "combo_box") == 0)
        printf("the widget is combo_box\n");
    for (int i = 0; widget_map[i].widget_name != NULL; i++)
    {
        if (strcmp(widget_linked_list->val, widget_map[i].widget_name) == 0)
        {
            widget_map[i].data_base_function(widget_linked_list, file);
            return;
        }
    }
    
    fprintf(stderr, "widget %s not found in our database\n", widget_linked_list->val);
    exit(EXIT_FAILURE);
}


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
    FILE *file_to_write = fopen("gtk.c", "w");
    
    // if the file is not valid
    if(!valid_file(file_to_read))
    {
        perror("file is not valid\n");
        exit(1);
    }

    // rewind the file to the beginning
    rewind(file_to_read);

    // write the headers 
    fprintf(file_to_write, "#include <gtk/gtk.h>\n");
    fprintf(file_to_write, "#include \"../include/GtkFramework/GtkFramework.h\"\n");

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
            // if the line is not empty, write it in the output file
            if((status = read_line(line, signals)) != -1)
                fprintf(file_to_write, "%s\n", line);

        } while(status != -2); // while not EOF

        fclose(signals); 
    }

    // start the activate function
    fprintf(file_to_write, "static void activate(GtkApplication *app, gpointer data){\n");

    // read the source file line by line and do the corresponding actions
    do
    {
        // read line and check if the line is empty (if it is empty, continue to the next line)
        if((status = read_line(line, file_to_read)) == -1) continue;

        // if the line is a comment, continue to the next line
        if(is_comment(line)) continue;

        // if the line is a closing tag, write the closing tag function after extracting his name and his arguments in the output file
        if(is_close_tag(line))
        {
            fprintf(file_to_write, "%s;\n", extraire_contenu(line));
            continue;
        }

        // soo the line is a opening tag
        // parse the line and extract the widget name and its attributes to a linked list containing
        // the name of the widgets and its attributes
        NodeA *widget_linked_list = parse_widget_to_linked_list(line);
        
        // call the database function corresponding to the widget name
        call_database_function(widget_linked_list, file_to_write);
        
        free_list(widget_linked_list);

    } while(status != -2);


    // end the activate function    
    fprintf(file_to_write, "}\n");

    // the main function
    fprintf(file_to_write, "int main(int argc, char *argv[]){\n");
    fprintf(file_to_write, "    GtkApplication *app = gtk_application_new(\"org.example.app\", G_APPLICATION_DEFAULT_FLAGS);\n");
    fprintf(file_to_write, "    g_signal_connect(app, \"activate\", G_CALLBACK(activate), NULL);\n");
    fprintf(file_to_write, "    int status = g_application_run(G_APPLICATION(app), argc, argv);\n");
    fprintf(file_to_write, "    g_object_unref(app);\n");
    fprintf(file_to_write, "    return status;\n");
    fprintf(file_to_write, "}\n");

    // Close the files
    fclose(file_to_write);
    fclose(file_to_read);
}


int main(int argc, char *argv[])
{
    arg myarg;
    myarg.argc = argc;
    myarg.argv = argv;
    use_xml_style_file(NULL, &myarg);

    // auto compile and run
    system("make");
    system("application");
    return 0;
}