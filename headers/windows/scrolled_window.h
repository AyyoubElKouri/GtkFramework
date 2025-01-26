/*****************************************************************************************************************************
 * 
 * @file scrolled_window.h
 * @brief header file for creating scrolled window with its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK scrolled window with its properties.
 * 
 * @note The scrolled window is a container widget that allows you to scroll content within it
 *       its soo simple he doesn't need many properties
 * 
 * @note it is preferable to add a top level widget to the scrolled window
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 1.0 (last update 26/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SCROLLED_WINDOW_H
#define SCROLLED_WINDOW_H

#include <gtk/gtk.h>

GtkWidget *create_scrolled_window();

void add_to_scrolled_window(GtkWidget *scrolled_window, GtkWidget *widget);

#endif // SCROLLED_WINDOW_H