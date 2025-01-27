/*****************************************************************************************************************************
 * 
 * @file label.h
 * @brief header file for creating label and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK label with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 21/01/2025
 * @version 1.0 (last update 21/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef LABEL_H
#define LABEL_H

#include <gtk/gtk.h>

/**
 * @struct labelInfos
 * @brief the label properties
 */

typedef struct
{
    const gchar *text;
    gint size;
    const gchar *font;
    const gchar *color;
    const gchar *background;
    GtkJustification justify;
    gboolean underline;
    PangoWeight weight;
    PangoStyle style;
    gboolean wrap;
}labelInfos;

/**
 * @brief This function sets the information in one structure and creates a label with this information.
 * 
 * @param text The text of the label.
 * @param size The size of the text.
 * @param font The font of the text.
 * @param color The color of the text.
 * @param background The background color of the label.
 * @param align The alignment of the text.
 * @param valign The vertical alignment of the text.
 * @param justify The justification of the text.
 * @param underline The underline of the text.
 * @param weight The weight of the text.
 * @param style The style of the text.
 * @param wrap The wrap of the text.
 * 
 * @return GtkWidget* A pointer to the created label.
 */

GtkWidget *create_label(const gchar *text, gint size, const gchar *font, const gchar *color, const gchar *background, GtkJustification justify, gboolean underline, PangoWeight weight, PangoStyle style, gboolean wrap);

/**
 * @brief This function sets the properties of the label.
 * 
 * @param labelInformations The structure containing the properties of the label.
 * 
 * @return GtkWidget* A pointer to the label with its properties.
 */

GtkWidget *set_properties_label(labelInfos *labelInformations);

/**
 * @brief This function gets the properties of the label.
 * 
 * @param label The label from which we want to get the properties.
 * 
 * @return labelInfos* A pointer to the structure containing the properties of the label.
 */

labelInfos *get_properties_label(GtkWidget *label);

#endif // LABEL_H
