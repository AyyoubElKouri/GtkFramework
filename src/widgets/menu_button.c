/*****************************************************************************************************************************
 * 
 * @file menu_button.c
 * @brief the implementation of the functions in menu_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/menu_button.h"

static const gchar *Gpath_to_image;

GtkWidget *create_menu_button(gchar *label, gchar *path_to_image, GtkArrowType arrow_type)
{
    menuButtonInfos *menuButtonInformation = (menuButtonInfos *)malloc(sizeof(menuButtonInfos));
    if(!menuButtonInformation) return NULL;

    menuButtonInformation->label = g_strdup(label);
    menuButtonInformation->path_to_image = g_strdup(path_to_image);
    Gpath_to_image = g_strdup(path_to_image);
    menuButtonInformation->arrow_type = arrow_type;

    GtkWidget *menuButton = set_properties_menuButton(menuButtonInformation);
    free(menuButtonInformation);    

    return menuButton;
}

GtkWidget *set_properties_menuButton(menuButtonInfos *menuButtonInformation)
{
    GtkWidget *menuButton = gtk_menu_button_new();;

    // set the label or the image
    if(menuButtonInformation->label)
        {
            gtk_button_set_label(GTK_BUTTON(menuButton), menuButtonInformation->label);
        }
    else
        {
            GtkWidget *image = gtk_image_new_from_file(menuButtonInformation->path_to_image);
            if(!image)
            {
                fprintf(stderr, "image not found: %s\n", menuButtonInformation->path_to_image);
                exit(EXIT_FAILURE);
            }
            gtk_button_set_image(GTK_BUTTON(menuButton), image);
        }
    
    // set the menu

    // set the arrow direction
    gtk_menu_button_set_direction(GTK_MENU_BUTTON(menuButton), menuButtonInformation->arrow_type);

    return menuButton;
}

menuButtonInfos *get_properties_menuButton(GtkWidget *menuButton)
{
    menuButtonInfos *menuButtonInformation = (menuButtonInfos *)malloc(sizeof(menuButtonInfos));
    if(!menuButtonInformation) return NULL;

    menuButtonInformation->label = gtk_button_get_label(GTK_BUTTON(menuButton));
    menuButtonInformation->path_to_image = g_strdup(Gpath_to_image);
    menuButtonInformation->arrow_type = gtk_menu_button_get_direction(GTK_MENU_BUTTON(menuButton));

    return menuButtonInformation;
}

void add_to_menu_button(GtkWidget *menuButton, GtkWidget *menu)
{
    gtk_menu_button_set_popup(GTK_MENU_BUTTON(menuButton), menu);
    gtk_widget_show_all(menu);
}

void modify_menu_button(GtkWidget *menuButton, menuButtonInfos *menuButtonInformation){

    // set the label or the image
    if(menuButtonInformation->label)
        {
            gtk_button_set_label(GTK_BUTTON(menuButton), menuButtonInformation->label);
        }
    else
        {
            GtkWidget *image = gtk_image_new_from_file(menuButtonInformation->path_to_image);
            if(!image)
            {
                fprintf(stderr, "image not found: %s\n", menuButtonInformation->path_to_image);
            } else 
                gtk_button_set_image(GTK_BUTTON(menuButton), image);
        }
    
    // set the arrow direction
    gtk_menu_button_set_direction(GTK_MENU_BUTTON(menuButton), menuButtonInformation->arrow_type);

}