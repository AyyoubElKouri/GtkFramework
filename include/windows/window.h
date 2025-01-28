/*****************************************************************************************************************************
 * 
 * @file window.h
 * @brief header file for creating window with its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK window with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 20/01/2025
 * @version 1.0 (last update 20/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

/**
 * @struct windowInfos
 * @brief The window properties
 */

typedef struct
{
    GtkApplication *app;
    GtkWindowType type;
    const gchar *title;
    gint width;
    gint height;
    gboolean resizable;
    GtkWindowPosition position;
    gboolean decorate;
    GdkPixbuf *icon;
    double opacity;
    gboolean fullscreen;
} windowInfos;

/**
 * @brief This function sets the information in one structure and creates a window with this information
 * 
 * @param app If the window is a gtk_application_window (NULL if not)
 * @param type The type of the windowlogiciel
 * @param title The title of the window
 * @param width The default width of the window
 * @param height The default height of the window
 * @param resizable If the window is resizable (FALSE if not)
 * @param position The default position of the window on the screen
 * @param decorate Whether the window has a border (FALSE if not)
 * @param icon The icon of the window (it is visible in the top right of the header bar and in the taskbar) (you can pass NULL)
 * @param opacity The opacity of the window (from 0 to 1)
 * @param fullscreen Whether the window should be shown in fullscreen or in the default size 
 * 
 * @return GtkWidget pointer (you need to create a GtkWidget pointer to receive it) or NULL if no memory space is available for the window
 */

GtkWidget *create_window(GtkApplication *app, GtkWindowType type, const gchar *title, gint width, gint height, gboolean resizable, GtkWindowPosition position, gboolean decorate, GdkPixbuf *icon, double opacity, gboolean fullscreen);

/**
 * @brief This function creates the window and sets its properties.
 * 
 * @param windowInformations The properties of the window
 * @return GtkWidget pointer to the window
 */

GtkWidget *set_properties_window(windowInfos *windowInformations);

/**
 * @brief This function adds a header bar to the window.
 * 
 * @param window The window to add the header bar to
 * @param headerBar The header bar to add to the window
 */

void add_header_bar_to_window(GtkWidget *window, GtkWidget *headerBar);

#endif // WINDOW_H
