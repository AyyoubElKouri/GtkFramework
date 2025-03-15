/*****************************************************************************************************************************
 * 
 * @file widget_callbacks.h
 * @brief tthe header file of the widget callbacks
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 06/03/2025
 * @version 1.0 (last update 06/03/2025)
 * 
 ****************************************************************************************************************************/

#ifndef WIDGET_CALLBACKS_H
#define WIDGET_CALLBACKS_H

#include "../include/GtkFramework/GtkFramework.h"
#include "../XML/xscEngine/widgets_structures.h"
#include "widgets_properties.h"

typedef struct{
    char* id_widget;
    char *widget_name;
    gpointer data;
} data_widget;

typedef struct {
    const char *name;
    void *(*handler)(void *data);
} WidgetHandler;

typedef struct {
    const char *name;
    void (*handler)(gpointer data);
} WidgetOnClick;

typedef void (*WidgetPropertiesHandler)();



extern const WidgetHandler widget_handlers[];


void on_click_window(gpointer data);

void on_click(gpointer data);

void traitementWindow(GtkWidget *widget, gpointer data);

void traitementBox(GtkWidget *widget, gpointer data);

void traitementHeaderBar(GtkWidget *widget, gpointer data);

void traitement_fixed(GtkWidget *widget, gpointer data);

void traitement_frame(GtkWidget *widget, gpointer data);

void traitement_grid(GtkWidget *widget, gpointer data);

void traitement_paned(GtkWidget *widget, gpointer data);

void traitement_stack(GtkWidget *widget, gpointer data);

void traitement_switcher(GtkWidget *widget, gpointer data);

void traitement_scrolled_window(GtkWidget *widget, gpointer data);

void traitement_button(GtkWidget *widget, gpointer data);

void traitement_check_button(GtkWidget *widget, gpointer data);

void traitement_color_button(GtkWidget *widget, gpointer data);

void traitement_combo_box(GtkWidget *widget, gpointer data);

void traitement_entry(GtkWidget *widget, gpointer data);

void traitement_font_button(GtkWidget *widget, gpointer data);

void traitement_image(GtkWidget *widget, gpointer data);

void traitement_label(GtkWidget *widget, gpointer data);

void traitement_level_bar(GtkWidget *widget, gpointer data);

void traitement_link_button(GtkWidget *widget, gpointer data);

void traitement_menu_button(GtkWidget *widget, gpointer data);

void traitement_menu(GtkWidget *widget, gpointer data);

void traitement_menu_item(GtkWidget *widget, gpointer data);

void traitement_radio_button(GtkWidget *widget, gpointer data);

void cancel(GtkWidget *button, gpointer data);

void drag(GtkWidget *button);

void drop(GtkWidget *button);
#endif