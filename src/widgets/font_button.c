/*****************************************************************************************************************************
 * 
 * @file font_button.c
 * @brief the implementation of the functions in font_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/font_button.h"


GtkWidget *create_font_button(const gchar *default_font_name, const gchar *title, gboolean show_size, gboolean show_style, gboolean use_size, gboolean use_font)
{
    fontButtonInfos *fontButtonInformations = (fontButtonInfos *)malloc(sizeof(fontButtonInfos));
    if(!fontButtonInformations) return NULL;

    fontButtonInformations->default_font_name = g_strdup(default_font_name);
    fontButtonInformations->title = g_strdup(title);
    fontButtonInformations->show_size = show_size;
    fontButtonInformations->show_style = show_style;
    fontButtonInformations->use_size = use_size;
    fontButtonInformations->use_font = use_font;  

    GtkWidget *font_button = set_properties_font_button(fontButtonInformations);

    free(fontButtonInformations);
    return font_button;
}

GtkWidget *set_properties_font_button(fontButtonInfos *fontButtonInformations)
{
    GtkWidget *font_button = gtk_font_button_new();
    // set the default font
    gtk_font_button_set_font_name(GTK_FONT_BUTTON(font_button), fontButtonInformations->default_font_name);

    // set the title
    gtk_font_button_set_title(GTK_FONT_BUTTON(font_button), fontButtonInformations->title);

    // set the show size
    gtk_font_button_set_show_size(GTK_FONT_BUTTON(font_button), fontButtonInformations->show_size);

    // set the show style
    gtk_font_button_set_show_style(GTK_FONT_BUTTON(font_button), fontButtonInformations->show_style);

    // set the use size
    gtk_font_button_set_use_size(GTK_FONT_BUTTON(font_button), fontButtonInformations->use_size);

    // set the use style
    gtk_font_button_set_use_font(GTK_FONT_BUTTON(font_button), fontButtonInformations->use_font);

    return font_button;
}

fontButtonInfos *get_properties_font_button(GtkWidget *fontButton)
{
    fontButtonInfos *fontButtonInformations = (fontButtonInfos *)malloc(sizeof(fontButtonInfos));
    if(!fontButtonInformations) return NULL;

    fontButtonInformations->default_font_name = gtk_font_button_get_font_name(GTK_FONT_BUTTON(fontButton));
    fontButtonInformations->title = gtk_font_button_get_title(GTK_FONT_BUTTON(fontButton));
    fontButtonInformations->show_size = gtk_font_button_get_show_size(GTK_FONT_BUTTON(fontButton));
    fontButtonInformations->show_style = gtk_font_button_get_show_style(GTK_FONT_BUTTON(fontButton));
    fontButtonInformations->use_size = gtk_font_button_get_use_size(GTK_FONT_BUTTON(fontButton));
    fontButtonInformations->use_font = gtk_font_button_get_use_font(GTK_FONT_BUTTON(fontButton));

    return fontButtonInformations;
}

