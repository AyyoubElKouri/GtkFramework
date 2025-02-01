/*****************************************************************************************************************************
 * 
 * @file widgets_data_bases.c
 * @brief the implementation of the functions in widgets_data_bases.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 2.0 (last update 01/02/2025)
 * 
 ****************************************************************************************************************************/


#include "widgets_data_bases.h"

void window_data_bases(NodeA *widget, FILE *file)
{
    // constructing data bases of the default values of a window
    NodeA *window = NULL;
    window = insert_end(window, "widget", "window", 1);
    window = insert_end(window, "app", "NULL", 0);
    window = insert_end(window, "type", "GTK_WINDOW_TOPLEVEL", 0);
    window = insert_end(window, "title", "Default title", 1);
    window = insert_end(window, "width", "800", 0);
    window = insert_end(window, "height", "600", 0);
    window = insert_end(window, "resizable", "TRUE", 0);
    window = insert_end(window, "position", "GTK_WIN_POS_CENTER", 0);
    window = insert_end(window, "decorate", "TRUE", 0);
    window = insert_end(window, "icon", "NULL", 0);
    window = insert_end(window, "opacity", "1.0", 0);
    window = insert_end(window, "fullscreen", "FALSE", 0);

    write_to_file(widget, window, file);

    free_list(window);
}



void header_bar_data_bases(NodeA *widget, FILE *file)
{
    // constructing data bases of the default values of a header bar
    NodeA *header = NULL;
    header = insert_end(header, "widget", "headerBar", 1);
    header = insert_end(header, "title", "Default title", 1);
    header = insert_end(header, "subtitle", "Default subtitle", 1);
    header = insert_end(header, "icon_path", "NULL", 1);
    header = insert_end(header, "settings", "TRUE", 0);

    write_to_file(widget, header, file);

    free_list(header);
}

void scrolled_window_data_bases(NodeA *widget, FILE *file)
{
    // constructing data bases of the default values of a scrolled window
    NodeA *scrolled = NULL;
    scrolled = insert_end(scrolled, "widget", "scrolledWindow", 1);
    scrolled = insert_end(scrolled, "horizontal", "TRUE", 0);
    scrolled = insert_end(scrolled, "vertical", "TRUE", 0);

    write_to_file(widget, scrolled, file);

    free_list(scrolled);
}

void box_data_bases(NodeA *widget, FILE *file)
{
    NodeA *box = NULL;
    box = insert_end(box, "widget", "box", 1);
    box = insert_end(box, "orientation", "GTK_ORIENTATION_VERTICAL", 0);
    box = insert_end(box, "align", "GTK_ALIGN_CENTER", 0);
    box = insert_end(box, "spacing", "0", 0);

    write_to_file(widget, box, file);
    free_list(box);
}

void fixed_data_bases(NodeA *widget, FILE *file)
{
    NodeA *fixed = NULL;
    fixed = insert_end(fixed, "widget", "fixed", 1);

    write_to_file(widget, fixed, file);
    free_list(fixed);
}

void frame_data_bases(NodeA *widget, FILE *file)
{
    NodeA *frame = NULL;
    frame = insert_end(frame, "widget", "frame", 1);
    frame = insert_end(frame, "title", "Default title", 1);
    frame = insert_end(frame, "horizontal_placement", "0.5", 0);
    frame = insert_end(frame, "vertical_placement", "0.5", 0);

    write_to_file(widget, frame, file);
    free_list(frame);
}

void grid_data_bases(NodeA *widget, FILE *file)
{
    NodeA *grid = NULL;
    grid = insert_end(grid, "widget", "grid", 1);
    grid = insert_end(grid, "rows_spacing", "0", 0);
    grid = insert_end(grid, "columns_spacing", "0", 0);
    grid = insert_end(grid, "rows_homogeneous", "FALSE", 0);
    grid = insert_end(grid, "columns_homogeneous", "FALSE", 0);

    write_to_file(widget, grid, file);
    free_list(grid);
}

void paned_data_bases(NodeA *widget, FILE *file)
{
    NodeA *paned = NULL;
    paned = insert_end(paned, "widget", "paned", 1);
    paned = insert_end(paned, "orientation", "GTK_ORIENTATION_HORIZONTAL", 0);
    paned = insert_end(paned, "default_position", "100", 0);
    paned = insert_end(paned, "show_handle", "TRUE", 0);

    write_to_file(widget, paned, file);
    free_list(paned);
}

void stack_data_bases(NodeA *widget, FILE *file)
{
    NodeA *stack = NULL;
    stack = insert_end(stack, "widget", "stack", 1);
    stack = insert_end(stack, "switcher", "NULL", 1);
    stack = insert_end(stack, "transition_type", "GTK_STACK_TRANSITION_TYPE_CROSSFADE", 0);
    stack = insert_end(stack, "transition_duration", "500", 0);

    write_to_file(widget, stack, file);
    free_list(stack);
}

void switcher_data_bases(NodeA *widget, FILE *file)
{
    NodeA *switcher = NULL;
    switcher = insert_end(switcher, "widget", "switcher", 1);
    switcher = insert_end(switcher, "spacing", "0", 0);
    switcher = insert_end(switcher, "buttons_same_size", "TRUE", 0);

    write_to_file(widget, switcher, file);
    free_list(switcher);
}

void button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *button = NULL;
    button = insert_end(button, "widget", "button", 1);
    button = insert_end(button, "relief", "GTK_RELIEF_NORMAL", 0);
    button = insert_end(button, "label", "Click me", 1);
    button = insert_end(button, "use_underline", "FALSE", 0);
    button = insert_end(button, "path_to_image", "NULL", 1);
    button = insert_end(button, "callback", "NULL", 1);
    button = insert_end(button, "data", "NULL", 1);

    write_to_file(widget, button, file);
    free_list(button);
}

void check_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *check_button = NULL;
    check_button = insert_end(check_button, "widget", "check_button", 1);
    check_button = insert_end(check_button, "label", "Click me", 1);
    check_button = insert_end(check_button, "active", "TRUE", 0);
    check_button = insert_end(check_button, "use_underline", "FALSE", 0);
    check_button = insert_end(check_button, "callback", "NULL", 1);
    check_button = insert_end(check_button, "data", "NULL", 1);

    write_to_file(widget, check_button, file);
    free_list(check_button);
}

void color_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *color_button = NULL;
    color_button = insert_end(color_button, "widget", "color_button", 1);
    color_button = insert_end(color_button, "default_color", "#FFFFFF", 1);
    color_button = insert_end(color_button, "title", "coloring", 1);
    color_button = insert_end(color_button, "use_alpha", "TRUE", 0);

    write_to_file(widget, color_button, file);
    free_list(color_button);
}

void entry_data_bases(NodeA *widget, FILE *file)
{
    NodeA *entry = NULL;
    entry = insert_end(entry, "widget", "entry", 1);
    entry = insert_end(entry, "default_text", "NULL", 1);
    entry = insert_end(entry, "indicator_text", "NULL", 1);
    entry = insert_end(entry, "visible", "TRUE", 0);
    entry = insert_end(entry, "editable", "TRUE", 0);
    entry = insert_end(entry, "max_length", "20", 0);
    entry = insert_end(entry, "alignment", "0.5", 0);

    write_to_file(widget, entry, file);
    free_list(entry);
}

void font_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *font_button = NULL;
    font_button = insert_end(font_button, "widget", "font_button", 1);
    font_button = insert_end(font_button, "default_font_name", "Arial", 1);
    font_button = insert_end(font_button, "title", "font", 1);
    font_button = insert_end(font_button, "show_size", "TRUE", 0);
    font_button = insert_end(font_button, "show_style", "TRUE", 0);
    font_button = insert_end(font_button, "use_size", "TRUE", 0);
    font_button = insert_end(font_button, "use_font", "TRUE", 0);

    write_to_file(widget, font_button, file);
    free_list(font_button);
}

void image_data_bases(NodeA *widget, FILE *file)
{
    NodeA *image = NULL;
    image = insert_end(image, "widget", "image", 1);
    image = insert_end(image, "path", "assets/Application_icon/apple.png", 1);

    write_to_file(widget, image, file);
    free_list(image);
}

void label_data_bases(NodeA *widget, FILE *file)
{
    NodeA *label = NULL;
    label = insert_end(label, "widget", "label", 1);
    label = insert_end(label, "text", "Hello", 1);
    label = insert_end(label, "size", "10", 0);
    label = insert_end(label, "font", "Arial", 1);
    label = insert_end(label, "color", "#FFFFFF", 1);
    label = insert_end(label, "background", "#000000", 1);
    label = insert_end(label, "justify", "GTK_JUSTIFY_CENTER", 0);
    label = insert_end(label, "underline", "FALSE", 0);
    label = insert_end(label, "weight", "0", 0);
    label = insert_end(label, "style", "0", 0);
    label = insert_end(label, "wrap", "TRUE", 0);

    write_to_file(widget, label, file);
    free_list(label);
}

void level_bar_data_bases(NodeA *widget, FILE *file)
{
    NodeA *level_bar = NULL;
    level_bar = insert_end(level_bar, "widget", "level_bar", 1);
    level_bar = insert_end(level_bar, "min_value", "0", 0);
    level_bar = insert_end(level_bar, "max_value", "100", 0);
    level_bar = insert_end(level_bar, "default_value", "50", 0);
    level_bar = insert_end(level_bar, "mode", "GTK_LEVEL_BAR_MODE_HORIZONTAL", 0);
    level_bar = insert_end(level_bar, "inverted", "FALSE", 0);

    write_to_file(widget, level_bar, file);
    free_list(level_bar);
}

void link_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *link_button = NULL;
    link_button = insert_end(link_button, "widget", "link_button", 1);
    link_button = insert_end(link_button, "uri", "https://www.google.com", 1);
    link_button = insert_end(link_button, "label", "Click me", 1);

    write_to_file(widget, link_button, file);
    free_list(link_button);
}

void menu_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *menu_button = NULL;
    menu_button = insert_end(menu_button, "widget", "menu_button", 1);
    menu_button = insert_end(menu_button, "label", "Click me", 1);
    menu_button = insert_end(menu_button, "path_to_image", "NULL", 1);
    menu_button = insert_end(menu_button, "arrow_type", "GTK_ARROW_DOWN", 0);

    write_to_file(widget, menu_button, file);
    free_list(menu_button);
}

void menu_item_data_bases(NodeA *widget, FILE *file)
{
    NodeA *menu_item = NULL;
    menu_item = insert_end(menu_item, "widget", "menu_item", 1);
    menu_item = insert_end(menu_item, "label", "Click me", 1);
    menu_item = insert_end(menu_item, "type", "normal", 1);
    menu_item = insert_end(menu_item, "submenu", "NULL", 1);
    menu_item = insert_end(menu_item, "callback", "NULL", 1);
    menu_item = insert_end(menu_item, "data", "NULL", 1);

    write_to_file(widget, menu_item, file);
    free_list(menu_item);
}

void menu_data_bases(NodeA *widget, FILE *file)
{
    NodeA *menu = NULL;
    menu = insert_end(menu, "widget", "menu", 1);
    menu = insert_end(menu, "is_primary", "TRUE", 0);
    menu = insert_end(menu, "label", "Click me", 1);

    write_to_file(widget, menu, file);
    free_list(menu);
}

void progress_bar_data_bases(NodeA *widget, FILE *file)
{
    NodeA *progress_bar = NULL;
    progress_bar = insert_end(progress_bar, "widget", "progress_bar", 1);
    progress_bar = insert_end(progress_bar, "text", "Click me", 1);
    progress_bar = insert_end(progress_bar, "fraction", "0.5", 0);
    progress_bar = insert_end(progress_bar, "show_text", "TRUE", 0);
    progress_bar = insert_end(progress_bar, "pulse", "FALSE", 0);
    progress_bar = insert_end(progress_bar, "inverted", "FALSE", 0);

    write_to_file(widget, progress_bar, file);
    free_list(progress_bar);
}

void radio_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *radio_button = NULL;
    radio_button = insert_end(radio_button, "widget", "radio_button", 1);
    radio_button = insert_end(radio_button, "label", "Click me", 1);
    radio_button = insert_end(radio_button, "path_to_image", "NULL", 1);
    radio_button = insert_end(radio_button, "radio_group_member", "NULL", 1);
    radio_button = insert_end(radio_button, "default_state", "FALSE", 0);

    write_to_file(widget, radio_button, file);
    free_list(radio_button);
}

void scale_data_bases(NodeA *widget, FILE *file)
{
    NodeA *scale = NULL;
    scale = insert_end(scale, "widget", "scale", 1);
    scale = insert_end(scale, "orientation", "GTK_ORIENTATION_VERTICAL", 0);
    scale = insert_end(scale, "min_value", "0", 0);
    scale = insert_end(scale, "max_value", "10", 0);
    scale = insert_end(scale, "step", "1", 0);
    scale = insert_end(scale, "mark_value", "1", 0);
    scale = insert_end(scale, "mark_position", "0.5", 0);
    scale = insert_end(scale, "text", "Click me", 1);
    scale = insert_end(scale, "digits", "0", 0);
    scale = insert_end(scale, "value_pos", "0.5", 0);

    write_to_file(widget, scale, file);
    free_list(scale);
}

void separator_data_bases(NodeA *widget, FILE *file)
{
    NodeA *separator = NULL;
    separator = insert_end(separator, "widget", "separator", 1);
    separator = insert_end(separator, "orientation", "GTK_ORIENTATION_VERTICAL", 0);

    write_to_file(widget, separator, file);
    free_list(separator);
}

void spin_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *spin_button = NULL;
    spin_button = insert_end(spin_button, "widget", "spin_button", 1);
    spin_button = insert_end(spin_button, "min", "0", 0);
    spin_button = insert_end(spin_button, "max", "10", 0);
    spin_button = insert_end(spin_button, "step", "1", 0);
    spin_button = insert_end(spin_button, "value", "1", 0);
    spin_button = insert_end(spin_button, "digits", "0", 0);
    spin_button = insert_end(spin_button, "wrap", "FALSE", 0);
    spin_button = insert_end(spin_button, "numeric", "FALSE", 0);

    write_to_file(widget, spin_button, file);
    free_list(spin_button);
}

void spinner_data_bases(NodeA *widget, FILE *file)
{
    NodeA *spinner = NULL;
    spinner = insert_end(spinner, "widget", "spinner", 1);
    spinner = insert_end(spinner, "active", "TRUE", 0);

    write_to_file(widget, spinner, file);
    free_list(spinner);
}

void switch_button_data_bases(NodeA *widget, FILE *file)
{
    NodeA *switch_button = NULL;
    switch_button = insert_end(switch_button, "widget", "switch_button", 1);
    switch_button = insert_end(switch_button, "default_state", "TRUE", 0);
    switch_button = insert_end(switch_button, "callback", "NULL", 1);
    switch_button = insert_end(switch_button, "data", "NULL", 1);

    write_to_file(widget, switch_button, file);
    free_list(switch_button);
}

void text_view_data_bases(NodeA *widget, FILE *file)
{
    NodeA *text_view = NULL;
    text_view = insert_end(text_view, "widget", "text_view", 1);
    text_view = insert_end(text_view, "text", "Click me", 1);
    text_view = insert_end(text_view, "size", "10", 0);
    text_view = insert_end(text_view, "font", "Arial", 1);
    text_view = insert_end(text_view, "color", "#FFFFFF", 1);
    text_view = insert_end(text_view, "background", "#000000", 1);
    text_view = insert_end(text_view, "justify", "GTK_JUSTIFY_CENTER", 0);
    text_view = insert_end(text_view, "wrap", "TRUE", 0);
    text_view = insert_end(text_view, "cursor_visible", "TRUE", 0);
    text_view = insert_end(text_view, "editable", "TRUE", 0);

    write_to_file(widget, text_view, file);
    free_list(text_view);
}
