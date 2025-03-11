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
extern const WidgetOnClick widget_on_click[];


void on_click_window(gpointer data);
void traitementWindow(GtkWidget *widget, gpointer data);

void on_click_box(gpointer data);
void traitementBox(GtkWidget *widget, gpointer data);

void traitementHeaderBar(GtkWidget *widget, gpointer data);

void traitement_fixed(GtkWidget *widget, gpointer data);

void traitement_frame(GtkWidget *widget, gpointer data);

void on_click_grid(gpointer data);

void on_click_paned(gpointer data);

void on_click_stack(gpointer data);

void on_click_switcher(gpointer data);

void on_click_button(gpointer data);

void on_click_check_button(gpointer data);

void on_click_color_button(gpointer data);

void on_click_combo_box(gpointer data);

void on_click_entry(gpointer data);

void on_click_font_button(gpointer data);

void on_click_image(gpointer data);

void on_click_label(gpointer data);

void on_click_level_bar(gpointer data);

void on_click_link_button(gpointer data);

void on_click_menu_button(gpointer data);

void on_click_menu_item(gpointer data);

void on_click_menu(gpointer data);

void on_click_progress_bar(gpointer data);

void on_click_radio_button(gpointer data);

void on_click_scale(gpointer data);

void on_click_separator(gpointer data);

void on_click_spin_button(gpointer data);

void on_click_spinner(gpointer data);

void on_click_switch_button(gpointer data);

#endif