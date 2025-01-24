/*****************************************************************************************************************************
 * 
 * @file scale.h
 * @brief header file for creating scale and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK scale with its properties
 * 
 * @author Ayyoub el Kouri
 * @date 24/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SCALE_H
#define SCALE_H

#include <gtk/gtk.h>

/**
 * @struct scaleInfos
 * @brief the scale properties
 */

typedef struct
{
    GtkOrientation orientation;
    gdouble min_value;
    gdouble max_value;
    gdouble step;
    gdouble mark_value;
    GtkPositionType mark_position;
    const gchar *text;
    gint digits;
    GtkPositionType value_pos;
}scaleInfos;

/**
 * @brief This function sets the information in one structure and creates a scale with this information.
 * 
 * @param orientation The orientation of the scale.
 * @param min_value The minimum value of the scale.
 * @param max_value The maximum value of the scale.
 * @param step The step of the scale.
 * @param mark_value The mark value of the scale.
 * @param mark_position The position of the mark.
 * @param text The text of the scale.
 * @param digits The digits of the scale.
 * @param value_pos The value position of the scale.
 * 
 * @return GtkWidget* A pointer to the created scale.
 */

GtkWidget *create_scale(GtkOrientation orientation, gdouble min_value, gdouble max_value, gdouble step, gdouble mark_value, GtkPositionType mark_position, const gchar *text, gint digits, GtkPositionType value_pos);

/**
 * @brief set the properties of the scale
 * 
 * this function sets the properties of the scale
 * 
 * @param scaleInformation the informations of the scale
 * 
 * @return GtkWidget* the scale
 */

GtkWidget *set_properties_scale(scaleInfos *scaleInformation);

/**
 * @brief get the properties of the scale
 * 
 * this function gets the properties of the scale
 * 
 * @param scale the scale
 * 
 * @return scaleInfos* the informations of the scale
 */

scaleInfos *get_properties_scale(GtkWidget *scale);

#endif // SCALE_H