/*****************************************************************************************************************************
 * 
 * @file button.c
 * @brief the implementation of the functions in button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/button.h"

gchar *Gfile_name;
GCallback Gcallback;
gpointer Gdata;

GtkWidget *create_button(GtkReliefStyle relief, const gchar *label, gboolean use_underline, const gchar *path_to_image, GCallback callback, gpointer data)
{
    buttonInfos *buttonInformation = (buttonInfos *)malloc(sizeof(buttonInfos));
    if(!buttonInformation) return NULL;

    buttonInformation->relief = relief;
    buttonInformation->label = (label) ? g_strdup(label) : NULL;

    buttonInformation->use_underline = use_underline;
    buttonInformation->path_to_image = (path_to_image) ? g_strdup(path_to_image) : NULL;
    buttonInformation->callback = callback;
    Gcallback = callback;
    buttonInformation->data = data;
    Gdata = data;

    GtkWidget *button = set_properties_button(buttonInformation);
    free(buttonInformation);

    return button;
}

GtkWidget *set_properties_button(buttonInfos *buttonInformation)
{
    // create the button with the label if it exists
    GtkWidget *button;
    if(buttonInformation->label)
        button = gtk_button_new_with_label(buttonInformation->label);
    else
        button = gtk_button_new();

    // set the relief
    gtk_button_set_relief(GTK_BUTTON(button), buttonInformation->relief);

    // set the underline if it exists
        gtk_button_set_use_underline(GTK_BUTTON(button), buttonInformation->use_underline);

    // set the image if it existsc
    if(buttonInformation->path_to_image)
    {
        GtkWidget *image = gtk_image_new_from_file(buttonInformation->path_to_image);
        gtk_button_set_image(GTK_BUTTON(button), image);
        Gfile_name = g_strdup(buttonInformation->path_to_image);
    }

    // set the callback if it exists
    if(buttonInformation->callback)
        g_signal_connect(button, "clicked", G_CALLBACK(buttonInformation->callback), buttonInformation->data);

    return button;
}


buttonInfos *get_properties_button(GtkWidget *button)
{
    buttonInfos *buttonInformation = (buttonInfos *)malloc(sizeof(buttonInfos));
    if(!buttonInformation) return NULL;

    // get the relief
    buttonInformation->relief = gtk_button_get_relief(GTK_BUTTON(button));

    // get the label
    buttonInformation->label = gtk_button_get_label(GTK_BUTTON(button));

    // get the underline
    buttonInformation->use_underline = gtk_button_get_use_underline(GTK_BUTTON(button));

    // get the image
    if(Gfile_name)
        buttonInformation->path_to_image = Gfile_name;
    
    // get the callback
    buttonInformation->callback = Gcallback;

    // get the data
    buttonInformation->data = Gdata;
    
    return buttonInformation;
}

