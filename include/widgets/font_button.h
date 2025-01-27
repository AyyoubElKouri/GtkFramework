/*****************************************************************************************************************************
 * 
 * @file font_button.h
 * @brief the header file of the font button widget
 * 
 * this file contains all the functions declarations and structures used in the font button widget
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef FONT_BUTTON_H
#define FONT_BUTTON_H

#include <gtk/gtk.h>

typedef struct
{
    const gchar *default_font_name;
    const gchar *title;
    gboolean show_size;
    gboolean show_style;
    gboolean use_size;
    gboolean use_font;
}fontButtonInfos;

/**
 * @brief creates a font button widget
 * 
 * @param default_font_name the default font name
 * @param title the title of the font button
 * @param show_size whether to show the size of the font
 * @param show_style whether to show the style of the font
 * @param use_size whether to use the size of the font
 * @param use_font whether to use the font
 * 
 * @return the font button widget
 */

GtkWidget *create_font_button(const gchar *default_font_name, const gchar *title, gboolean show_size, gboolean show_style, gboolean use_size, gboolean use_font);

/**
 * @brief sets the properties of the font button widget
 * 
 * @param fontButtonInformations the properties of the font button widget
 * 
 * @return the font button widget
 */

GtkWidget *set_properties_font_button(fontButtonInfos *fontButtonInformations);

/**
 * @brief gets the properties of the font button widget
 * 
 * @param fontButton the font button widget
 * 
 * @return the properties of the font button widget
 */

fontButtonInfos *get_properties_font_button(GtkWidget *fontButton);

#endif // FONT_BUTTON_H