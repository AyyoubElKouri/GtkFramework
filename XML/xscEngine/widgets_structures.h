/*****************************************************************************************************************************
 * 
 * @file widgets_structures.h
 * @brief the header file of the widgets_structures
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 01/03/2025
 * @version 1.0 (last update 01/03/2025)
 * 
 ****************************************************************************************************************************/

#ifndef WIDGETS_STRUCTURES_H
#define WIDGETS_STRUCTURES_H

#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *window_informations_id_value;
    GtkWidget *window_informations_app_value;
    GtkWidget *window_informations_type_value;
    GtkWidget *window_informations_title_value;
    GtkWidget *window_informations_width_value;
    GtkWidget *window_informations_height_value;
    GtkWidget *window_informations_resizable_value;
    GtkWidget *window_informations_position_value;
    GtkWidget *window_informations_decorate_value;
    GtkWidget *window_informations_icon_value;
    GtkWidget *window_informations_opacity_value;
    GtkWidget *window_informations_fullscreen_value;
} windowI;

typedef struct 
{
    GtkWidget *header_bar_id_value;
    GtkWidget *header_bar_informations_title_value;
    GtkWidget *header_bar_informations_subtitle_value;
    GtkWidget *header_bar_informations_icon_value;
    GtkWidget *header_bar_informations_settings_value;
} headerBarI;

typedef struct
{
    GtkWidget *Box_case_informations_id_entry;
    GtkWidget *Box_case_informations_orientation_value;
    GtkWidget *Box_case_informations_align_value;
    GtkWidget *Box_case_informations_spacing_value;
} boxI;

typedef struct
{
    GtkWidget *Fixed_id_entry;
} fixedI;

typedef struct
{
    GtkWidget *Frame_id_entry;
    GtkWidget *Frame_title_value;
    GtkWidget *Frame_horizontal_placement_value;
    GtkWidget *Frame_vertical_placement_value;
} frameI;

typedef struct
{
    GtkWidget *Grid_id_entry;
    GtkWidget *Grid_rows_spacing_value;
    GtkWidget *Grid_columns_spacing_value;
    GtkWidget *Grid_rows_homogeneous_value;
    GtkWidget *Grid_columns_homogeneous_value;
} gridI;

typedef struct
{
    GtkWidget *Paned_id_value;
    GtkWidget *Paned_orientation_value;
    GtkWidget *Paned_default_position_value;
    GtkWidget *Paned_show_handle_combo_box;
} panedI;

#endif //WIDGETS_STRUCTURES_H