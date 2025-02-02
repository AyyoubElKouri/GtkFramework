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
    if(myarg->argc < 2)
    {
        printf("file path is required\n");
        exit(1);
    }

    
    FILE *file_to_read = fopen(myarg->argv[1], "r");
    if(!file_to_read)
    {
        perror("file not found");
        exit(1);
    }


    
    FILE *temp = fopen("../temp.c", "w");
    
    if(!analyse(file_to_read))
    {
        printf("file is not valid\n");
        exit(1);
    }
    else
        printf("file valide\n");

    rewind(file_to_read);

    fprintf(temp, "#include <gtk/gtk.h>\n");
    fprintf(temp, "#include \"include/GtkFramework/GtkFramework.h\"\n");

    fprintf(temp, "static void activate(GtkApplication *app, gpointer data){\n");
    // printf("ddd\n");

    char car;
    
    do{
    char line[2000];
    int index = 0;


    while((car = fgetc(file_to_read)) == ' ');
    if(car == '\n') continue;


    while(car != '\n' && car != EOF)
    {
        line[index] = car;
        index++;
        car = fgetc(file_to_read);
    }

    line[index] = '\0';
    index = 0;

    if(is_comment(line)) continue;
    if(is_close_tag(line))
    {
        fprintf(temp, "%s;\n", extraire_contenu(line));
        continue;
    }

    NodeA *widget = parse_widget(line);
    
    if(strcmp(widget->val, "window") == 0) window_data_bases(widget, temp);
    else if(strcmp(widget->val, "header_bar") == 0) header_bar_data_bases(widget, temp);
    else if(strcmp(widget->val, "scrolled_window") == 0) scrolled_window_data_bases(widget, temp);
    else if(strcmp(widget->val, "box") == 0) box_data_bases(widget, temp);
    else if(strcmp(widget->val, "fixed") == 0) fixed_data_bases(widget, temp);
    else if(strcmp(widget->val, "frame") == 0) frame_data_bases(widget, temp);
    else if(strcmp(widget->val, "grid") == 0) grid_data_bases(widget, temp);
    else if(strcmp(widget->val, "paned") == 0) paned_data_bases(widget, temp);
    else if(strcmp(widget->val, "stack") == 0) stack_data_bases(widget, temp);
    else if(strcmp(widget->val, "switcher") == 0) switcher_data_bases(widget, temp);
    else if(strcmp(widget->val, "button") == 0) button_data_bases(widget, temp);
    else if(strcmp(widget->val, "check_button") == 0) check_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "color_button") == 0) color_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "entry") == 0) entry_data_bases(widget, temp);
    else if(strcmp(widget->val, "font_button") == 0) font_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "image") == 0) image_data_bases(widget, temp);
    else if(strcmp(widget->val, "label") == 0) label_data_bases(widget, temp);
    else if(strcmp(widget->val, "level_bar") == 0) level_bar_data_bases(widget, temp);
    else if(strcmp(widget->val, "link_button") == 0) link_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "menu_button") == 0) menu_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "menu_item") == 0) menu_item_data_bases(widget, temp);
    else if(strcmp(widget->val, "menu") == 0) menu_data_bases(widget, temp);
    else if(strcmp(widget->val, "progress_bar") == 0) progress_bar_data_bases(widget, temp);
    else if(strcmp(widget->val, "radio_button") == 0) radio_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "scale") == 0) scale_data_bases(widget, temp);
    else if(strcmp(widget->val, "separator") == 0) separator_data_bases(widget, temp);
    else if(strcmp(widget->val, "spin_button") == 0) spin_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "spinner") == 0) spinner_data_bases(widget, temp);
    else if(strcmp(widget->val, "switch_button") == 0) switch_button_data_bases(widget, temp);
    else if(strcmp(widget->val, "text_view") == 0) text_view_data_bases(widget, temp);
    else
    {
        printf("the widgets : %s not exist in our databases!\n", widget->val);
        exit(-1);
    }   
    

    free_list(widget);

    } while(car != EOF);

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
}