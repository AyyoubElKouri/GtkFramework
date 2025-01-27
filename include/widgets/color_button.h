/*****************************************************************************************************************************
 * 
 * @file color_button.h
 * @brief the header file of the color button widget
 * 
 * this file contains all the functions declarations and structures used in the color button widget
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef COLOR_BUTTON_H
#define COLOR_BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct colorButtonInfos
 * @brief the color button properties
 */

typedef struct
{
    const gchar *default_color;
    const gchar *title;
    gboolean use_alpha;
}colorButtonInfos;

/**
 * @brief creates a color button widget
 * 
 * @param default_color the default color of the color button
 * @param title the title of the color button
 * @param use_alpha whether to use alpha or not
 * 
 * @return the color button widget
 */

GtkWidget *create_color_button(const gchar *default_color, const gchar *title, gboolean use_alpha);

/**
 * @brief sets the properties of the color button widget
 * 
 * @param colorButtonInformation the properties of the color button widget
 * 
 * @return the color button widget
 */

GtkWidget *set_properties_color_button(colorButtonInfos *colorButtonInformation);

/**
 * @brief gets the properties of the color button widget
 * 
 * @param colorButton the color button widget
 * 
 * @return the properties of the color button widget
 */

colorButtonInfos *get_properties_color_button(GtkWidget *colorButton);

#endif // COLOR_BUTTON_H