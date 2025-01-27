/*****************************************************************************************************************************
 * 
 * @file scrolled_window.c
 * @brief the implementation of the functions in scrolled_window.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 26/01/2025
 * @version 1.0 (last update 26/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/windows/scrolled_window.h"

GtkWidget *create_scrolled_window()
{
    // Create a scrolled window
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    
    return scrolled_window;
}

void add_to_scrolled_window(GtkWidget *scrolled_window, GtkWidget *widget)
{
    // Add the widget to the scrolled window
    gtk_container_add(GTK_CONTAINER(scrolled_window), widget);
}