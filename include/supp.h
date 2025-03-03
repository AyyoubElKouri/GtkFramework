/*****************************************************************************************************************************
 * 
 * @file supp.h
 * @brief header file for creating support functions 
 * 
 * This header file contains all function declarations for
 * creating support functions that are used in the main file
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.0 (last update 28/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SUPP_H
#define SUPP_H

#include <gtk/gtk.h>

typedef struct{
    char* id_widget;
    gpointer data;
} data_widget;


void add_to_container(GtkWidget *container, GtkWidget *widget);

void show_widget(GtkWidget *widget);

gint run_dialog(GtkWidget *dialog);

void destroy_widget(GtkWidget *widget);
#endif // SUPP_H
