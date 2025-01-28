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
 * @version 2.0 (last update 28/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SCROLLED_WINDOW_H
#define SCROLLED_WINDOW_H

#include <gtk/gtk.h>

/**
 * @struct scrolledWindowInfos
 * @brief the scrolled window properties
 */

typedef struct 
{
    gboolean horizontal;
    gboolean vertical;
} scrolledWindowInfos;

/**
 * @brief this is a function that creates a scrolled window
 * 
 * @param horizontal if the scrolled window is horizontal
 * @param vertical if the scrolled window is vertical
 * 
 * @return GtkWidget pointer (you need to create a GtkWidget pointer to receive it)
 */

GtkWidget *create_scrolled_window(gboolean horizontal, gboolean vertical);

/**
 * @brief this is a function that sets the properties of the scrolled window
 * 
 * @param scrolledwindowInformations the properties of the scrolled window
 * 
 * @return GtkWidget pointer (you need to create a GtkWidget pointer to receive it)
 */

GtkWidget *set_properties_scrolled_window(scrolledWindowInfos *scrolledwindowInformations);

/**
 * @brief this is a function that gets the properties of the scrolled window
 * 
 * @param scrolled_window the scrolled window
 * 
 * @return scrolledWindowInfos pointer to the scrolled window information
 */

scrolledWindowInfos *get_scrolled_window_properties(GtkWidget *scrolled_window);

/**
 * @brief this is a function that adds a widget to the scrolled window
 * 
 * @param scrolled_window the scrolled window
 * @param widget the widget to add
 * 
 * @note it is preferable to add a top level widget to the scrolled window
 */

void add_to_scrolled_window(GtkWidget *scrolled_window, GtkWidget *widget);

#endif // SCROLLED_WINDOW_H