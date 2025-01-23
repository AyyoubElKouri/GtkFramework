/*****************************************************************************************************************************
 * 
 * @file text_view.h
 * @brief header file of the text view widget
 * 
 * this file contains all the functions declarations and structures used in the text view widget
 * 
 * @author Ayyoub el Kouri
 * @date 23/01/2025
 * @version 1.0 (last update 23/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include <gtk/gtk.h>

/**
 * @brief the structure that contains the informations of the text view
 * 
 * @warning the size of the text view is the same as the size of the text view in the file
 */

typedef struct
{
    const gchar *text;
    gint size;
    const gchar *font;
    const gchar *color;
    const gchar *background;
    GtkJustification justify;
    PangoWeight weight;
    PangoStyle style;
    gboolean wrap;
    gboolean cursor_visible;
    gboolean editable;
    gint cursor_position;
} textViewInfos;


/**
 * @brief create a text view
 * 
 * this function creates a text view
 * 
 * @param text the text of the text view
 * @param size the size of the text
 * @param font the font of the text
 * @param color the color of the text
 * @param background the background of the text
 * @param justify the justification of the text
 * @param weight the weight of the text
 * @param style the style of the text
 * @param wrap if the text should wrap
 * @param cursor_visible if the cursor should be visible
 * @param editable if the text should be editable
 * 
 * @return GtkWidget* the text view
 */

GtkWidget *create_text_view(const gchar *text, gint size, const gchar *font, const gchar *color, const gchar *background, GtkJustification justify, PangoWeight weight, PangoStyle style, gboolean wrap, gboolean cursor_visible, gboolean editable);

/**
 * @brief set the properties of the text view
 * 
 * @param textViewInformation the informations of the text view
 * 
 * @return GtkWidget* the text view
 */

GtkWidget *set_properties_text_view(textViewInfos *textViewInformation);

/**
 * @brief get the properties of the text view
 * 
 * @param textView the text view
 * 
 * @return textViewInfos* the informations of the text view
 */

textViewInfos *get_properties_text_view(GtkWidget *textView);

#endif // TEXT_VIEW_H