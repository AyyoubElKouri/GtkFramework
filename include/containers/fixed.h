/*****************************************************************************************************************************
 * 
 * @file fixed.h
 * @brief the header file of the fixed container
 * 
 * this file contains all the functions declarations and structures used in the fixed container
 * 
 * @note this container doesn't need many properties
 *       the idea is simple, you have a container that you can add widgets at specific positions
 *       is not compatible with the redimensionning of the window
 *       preferably used for fixed or simple layouts that don't need to be redimensionned when the window is resized
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef FIXED_H
#define FIXED_H

#include <gtk/gtk.h>

GtkWidget *create_fixed();

void add_to_fixed(GtkWidget *fixed, GtkWidget *widget, gint x, gint y);

#endif // FIXED_H