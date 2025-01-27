/*****************************************************************************************************************************
 * 
 * @file color_button.c
 * @brief the implementation of the functions in color_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/color_button.h"

GtkWidget *create_color_button(const gchar *default_color, const gchar *title, gboolean use_alpha)
{
    colorButtonInfos *colorButtonInformations = (colorButtonInfos *)malloc(sizeof(colorButtonInfos));
    if(!colorButtonInformations) return NULL;

    colorButtonInformations->default_color = g_strdup(default_color);
    if(!colorButtonInformations->default_color)
    {
        free(colorButtonInformations);
        return NULL;
    }

    colorButtonInformations->title = g_strdup(title);
    if(!colorButtonInformations->title)
    {
        free(colorButtonInformations);
        return NULL;
    }

    colorButtonInformations->use_alpha = use_alpha;

    GtkWidget *color_button = set_properties_color_button(colorButtonInformations);
    free(colorButtonInformations);

    return color_button;
}

GtkWidget *set_properties_color_button(colorButtonInfos *colorButtonInformation)
{
    GtkWidget *color_button = gtk_color_button_new();

    // set the default color
    GdkColor gdk_color;
    gdk_color_parse(colorButtonInformation->default_color, &gdk_color);
    gtk_color_button_set_color(GTK_COLOR_BUTTON(color_button), &gdk_color);

    // det the title
    gtk_color_button_set_title(GTK_COLOR_BUTTON(color_button), colorButtonInformation->title);

    // set the use alpha
    gtk_color_button_set_use_alpha(GTK_COLOR_BUTTON(color_button), colorButtonInformation->use_alpha);

    return color_button;
}

colorButtonInfos *get_properties_color_button(GtkWidget *colorButton)
{
    colorButtonInfos *colorButtonInformations = (colorButtonInfos *)malloc(sizeof(colorButtonInfos));
    if(!colorButtonInformations) return NULL;

    // get the default color
    GdkColor gdk_color;
    gtk_color_button_get_color(GTK_COLOR_BUTTON(colorButton), &gdk_color);
    char *hex_color = (char *)malloc(8);
    snprintf(hex_color, 8, "#%02x%02x%02x", gdk_color.red>>8, gdk_color.green>>8, gdk_color.blue>>8);   
    
    colorButtonInformations->default_color = g_strdup(hex_color);
    free(hex_color);

    // get the title
    colorButtonInformations->title = gtk_color_button_get_title(GTK_COLOR_BUTTON(colorButton));

    // get the use alpha
    colorButtonInformations->use_alpha = gtk_color_button_get_use_alpha(GTK_COLOR_BUTTON(colorButton));

    return colorButtonInformations;
}