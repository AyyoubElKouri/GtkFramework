/*****************************************************************************************************************************
 * 
 * @file xml_style.h
 * @brief the header file of the engine of the xml style
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 3.0 (last update 05/02/2025)
 * 
 ****************************************************************************************************************************/



#ifndef XML_STYLE_H
#define XML_STYLE_H

#include "../../include/GtkFramework/GtkFramework.h"
#include "widgets_data_bases.h"

typedef struct
{
    int argc;
    char **argv;
}arg;

typedef void (*WidgetHandler)(NodeA *, FILE *);

typedef struct {
    const char *widget_name;
    WidgetHandler data_base_function;
} WidgetMap;

WidgetMap widget_map[] = {
    {"window", window_data_bases},
    {"header_bar", header_bar_data_bases},
    {"scrolled_window", scrolled_window_data_bases},
    {"box", box_data_bases},
    {"fixed", fixed_data_bases},
    {"frame", frame_data_bases},
    {"grid", grid_data_bases},
    {"paned", paned_data_bases},
    {"stack", stack_data_bases},
    {"switcher", switcher_data_bases},
    {"button", button_data_bases},
    {"check_button", check_button_data_bases},
    {"color_button", color_button_data_bases},
    {"entry", entry_data_bases},
    {"font_button", font_button_data_bases},
    {"image", image_data_bases},
    {"label", label_data_bases},
    {"level_bar", level_bar_data_bases},
    {"link_button", link_button_data_bases},
    {"menu_button", menu_button_data_bases},
    {"menu_item", menu_item_data_bases},
    {"menu", menu_data_bases},
    {"progress_bar", progress_bar_data_bases},
    {"radio_button", radio_button_data_bases},
    {"scale", scale_data_bases},
    {"separator", separator_data_bases},
    {"spin_button", spin_button_data_bases},
    {"spinner", spinner_data_bases},
    {"switch_button", switch_button_data_bases},
    {"text_view", text_view_data_bases},
    {NULL, NULL} // Marqueur de fin
};


void call_database_function(NodeA *widget, FILE *file);

void use_xml_style_file(GtkApplication *app, arg *myarg);

#endif