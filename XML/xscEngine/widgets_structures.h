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

typedef struct
{
    GtkWidget *stack_widget_id_value;
    GtkWidget *stack_switcher_widget_id;
    GtkWidget *stack_transition_type_value_combo_box;
    GtkWidget *stack_duration_value_spin_button;

} stackI;

typedef struct
{
    GtkWidget *switcher_id_entry;
    GtkWidget *switcher_spacing_value_spin_button;
    GtkWidget *same_size_value_combo_box;

} switcherI;

typedef struct
{
    GtkWidget *scrolled_window_informations_id_value;
    GtkWidget *scrolled_window_informations_horizontal_value;
    GtkWidget *scrolled_window_informations_vertical_value;

} scrolled_windowI;

typedef struct
{
    GtkWidget *button_id_entry;
    GtkWidget *button_relief_combo_box;
    GtkWidget *button_label_entry;
    GtkWidget *button_use_underline_combo_box;
    GtkWidget *button_path_to_image_entry;
    GtkWidget *button_callback_entry;
    GtkWidget *button_data_entry;

} buttonI;

typedef struct
{
    GtkWidget *check_button_id_entry;
    GtkWidget *check_button_label_entry;
    GtkWidget *check_button_active_combo_box;
    GtkWidget *check_button_use_underline_combo_box;
    GtkWidget *check_button_callback_entry;
    GtkWidget *check_button_data_entry;

} check_buttonI;

typedef struct
{
    GtkWidget *color_button_id_entry;
    GtkWidget *color_button_default_color_color_button;
    GtkWidget *color_button_label_entry;
    GtkWidget *color_button_use_alpha_combo_box;

} color_buttonI;

typedef struct
{
    GtkWidget *combo_box_id_entry;

} combo_boxI;

typedef struct
{
    GtkWidget *entry_id_entry;
    GtkWidget *entry_default_text_entry;
    GtkWidget *entry_indicator_text_entry;
    GtkWidget *entry_visibility_combo_box;
    GtkWidget *entry_editable_combo_box;
    GtkWidget *entry_max_length_spin_button;
    GtkWidget *entry_alignment_spin_button;

} entryI;

typedef struct
{
    GtkWidget *font_button_id_entry;
    GtkWidget *font_button_default_font_name_entry;
    GtkWidget *font_button_title_entry;
    GtkWidget *font_button_show_size_combo_box;
    GtkWidget *font_button_show_style_combo_box;
    GtkWidget *font_button_use_size_combo_box;
    GtkWidget *font_button_use_font_combo_box;

}font_buttonI;

typedef struct
{
    GtkWidget *image_id_entry;
    GtkWidget *image_path_entry;
} imageI;

typedef struct
{
    GtkWidget *label_id_entry;
    GtkWidget *label_text_entry;
    GtkWidget *label_size_spin_button;
    GtkWidget *label_font_font_button;
    GtkWidget *label_color_color_button;
    GtkWidget *label_background_color_button;
    GtkWidget *label_justify_combo_box;
    GtkWidget *label_use_underline_combo_box;
    GtkWidget *label_pango_weight_combo_box;
    GtkWidget *label_pango_style_combo_box;
    GtkWidget *label_wrap_combo_box;

} labelI;

typedef struct
{
    GtkWidget *level_bar_id_entry;
    GtkWidget *level_bar_min_value_spin_button;
    GtkWidget *level_bar_max_value_spin_button;
    GtkWidget *level_bar_default_value_spin_button;
    GtkWidget *level_bar_mode_combo_box;
    GtkWidget *level_bar_reversed_combo_box;

} level_barI;

typedef struct
{
    GtkWidget *Link_button_id_entry;
    GtkWidget *Link_button_url_entry;
    GtkWidget *Link_button_label_entry;
} link_buttonI;

#endif //WIDGETS_STRUCTURES_H