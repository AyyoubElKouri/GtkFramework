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

GtkWidget *create_scrolled_window(gboolean horizontal, gboolean vertical)
{
    scrolledWindowInfos *scrolledwindowInformations = (scrolledWindowInfos *)malloc(sizeof(scrolledWindowInfos));
    if(!scrolledwindowInformations) return NULL;

    scrolledwindowInformations->horizontal = horizontal;
    scrolledwindowInformations->vertical = vertical;

    GtkWidget *scrolled_window = set_properties_scrolled_window(scrolledwindowInformations);

    free(scrolledwindowInformations);
    return scrolled_window;
}

GtkWidget *set_properties_scrolled_window(scrolledWindowInfos *scrolledwindowInformations)
{
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);

    // Set the properties of the scrolled window
    if(scrolledwindowInformations->horizontal && scrolledwindowInformations->vertical)
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
    else if(scrolledwindowInformations->horizontal)
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_ALWAYS, GTK_POLICY_NEVER);
    else if(scrolledwindowInformations->vertical)
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
    else
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_NEVER);

    return scrolled_window;
}

scrolledWindowInfos *get_scrolled_window_properties(GtkWidget *scrolled_window)
{
    scrolledWindowInfos *scrolledwindowInformations = (scrolledWindowInfos *)malloc(sizeof(scrolledWindowInfos));
    if(!scrolledwindowInformations) return NULL;

    GtkPolicyType *horizontal, *vertical;

    gtk_scrolled_window_get_policy(GTK_SCROLLED_WINDOW(scrolled_window), horizontal, vertical);

    if(horizontal == GTK_POLICY_ALWAYS)
        scrolledwindowInformations->horizontal = TRUE;
    else
        scrolledwindowInformations->horizontal = FALSE;
    
    if(vertical == GTK_POLICY_ALWAYS)
        scrolledwindowInformations->vertical = TRUE;
    else
        scrolledwindowInformations->vertical = FALSE;

    return scrolledwindowInformations;
}

void add_to_scrolled_window(GtkWidget *scrolled_window, GtkWidget *widget)
{
    // Add the widget to the scrolled window
    gtk_container_add(GTK_CONTAINER(scrolled_window), widget);
}