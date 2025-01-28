/*****************************************************************************************************************************
 * 
 * @file supp.c
 * @brief the implementation of the functions in button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../include/supp.h"

void add_to_container(GtkWidget *container, GtkWidget *widget)
{
    gtk_container_add(GTK_CONTAINER(container), widget);
}

void show_widget(GtkWidget *widget)
{
    gtk_widget_show_all(widget);
}

gint run_dialog(GtkWidget *dialog)
{
    return gtk_dialog_run(GTK_DIALOG(dialog));
}