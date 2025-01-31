#include "widgets_data_bases.h"
/*****************************************************************************************************************************
 * 
 * Windows :
 * 
 * window:
 *      GtkWidget *create_window(GtkApplication *app, GtkWindowType type, const gchar *title, gint width, gint height, gboolean resizable, GtkWindowPosition position, gboolean decorate, GdkPixbuf *icon, double opacity, gboolean fullscrean)
 *      <window id = "id window" app = "app" type = "GTK_WINDOW_TOP_LEVEL"  title = "window title" width = "200" height = "400" resizable = "TRUE" position = "GTK_WIN_POS_CENTER" decorate = "TRUE" icon = "icon" opacity = "1" fusscreen = "TRUE">
 * 
 * header bar:
 *      GtkWidget *create_header_bar(const gchar *title, const gchar *subtitle, const gchar *icon_path, gboolean settings);
 *      <headerBar id = "id header" title = "Countries" subtitle = "Project 1" icon_path = "assets/Application_icon/apple.png" settings = "TRUE" >
 * 
 * scrolled window:
 *      GtkWidget *create_scrolled_window(gboolean horizontal, gboolean vertical);  
 *      <scrolledWindow horizontal = "FALSE" vertical = "TRUE">
 *
 *
 * 
 * Containers:
 * 
 * box:
 *      GtkWidget *create_box(GtkOrientation orientation, GtkAlign align, gint spacing);
 *      <box id = "box id" orientation = GTK_OREINTATION_VERTICAL align = GTK_ALIGNT_CENTER spacing = 10)
 * 
 * fixed: 
 *      GtkWidget *create_fixed();
 *      <fixed id = "fixed id">
 *          
 * frame:
 *      GtkWidget *create_frame(const gchar *title, gfloat horizontal_placement, gfloat vertical_placement);
 *      <frame id = "frame id" title = "title frame" horizontal_placement = 1 vertical_placement = 0.5>
 * 
 * grid:
 *      GtkWidget *create_grid(guint rows_spacing, guint columns_spacing, gboolean rows_homogeneous, gboolean columns_homogeneous);
 *      <grid id = "grid id" rows_spacing = 10 columns_spacing = 10 rows_homogeneous columns_homogeneous>
 * 
 * paned:
 *      GtkWidget *create_paned(GtkOrientation orientation, gint default_position, gboolean show_handle);
 *      <paned id = "paned id" orientation = GTK_ORIENTATION_VERTICAL default_position = 100 show_handle = true>
 * 
 * stack:
 *      GtkWidget *create_stack(GtkStackTransitionType transition_type, gint transition_duration);
 *      <stack id = "stack id" GTK transition_type = GTK_HH transition_duration = 200>
 * 
 * switcher:
 *      GtkWidget *create_switcher(gint spacing, gboolean buttons_same_size);
 *      <switcher id = "id_switcher" button_same_size = true>
 * 
 * 
 * Widgets: 
 * 
 * button: 
 *      GtkWidget *create_button(GtkReliefStyle relief, const gchar *label, gboolean use_underline, const gchar *path_to_image, GCallback callback, gpointer data);
 *      <button id = "id button" relief = GTK_RELIF_STYLE label = "Click me" use_underline = true path_to_image = NULL callback = NULL data = NULL> 
 * 
 * check button:
 *      GtkWidget *create_check_button(const char *label, gboolean active, gboolean use_underline, GCallback callback, gpointer data);
 *      <check_button id = "check button" label = "Click me" active = true use_underline = false callback = NULL data = NULL>
 * 
 * color button: 
 *      GtkWidget *create_color_button(const gchar *default_color, const gchar *title, gboolean use_alpha);
 *      <color_button id = "button " default_color = "#FFFFFF" title = "coloring" use_alpha = true>
 * 
 * entry: 
 *      GtkWidget *create_entry(const gchar *default_text, const gchar *indicator_text, gboolean visible, gboolean editable, gint max_length, gdouble alignment);
 *      <entry id = "id entry" default_text = NULL indicator_text = "username" visibile = true editable = true max_lenght = 20 alignment = 0.5 >
 * 
 * font button:
 *      GtkWidget *create_font_button(const gchar *default_font_name, const gchar *title, gboolean show_size, gboolean show_style, gboolean use_size, gboolean use_font);
 *      <font_button id = "font button" default_font_name = "Arial" title = "font" show_size = true show_style = true use_size = true use_font = true>
 * 
 * image:
 *      GtkWidget *create_image(const gchar *path);
 *      <image id = "image id" path = "assets/Application_icon/apple.png">
 * 
 * label:
 *      GtkWidget *create_label(const gchar *text, gint size, const gchar *font, const gchar *color, const gchar *background, GtkJustification justify, gboolean underline, PangoWeight weight, PangoStyle style, gboolean wrap);
 *      <label id = "label id" text = "Hello" size = 10 font = "Arial" color = "#FFFFFF" background = "#000000" justify = "GTK_JUSTIFY_CENTER" underline = FALSE weight = 0 style = 0 wrap = TRUE>
 * 
 * level_bar:
 *      GtkWidget *create_level_bar(gdouble min_value, gdouble max_value, gdouble default_value, GtkLevelBarMode mode, gboolean inverted);
 *      <level_bar id = "level bar" min_value = 0 max_value = 100 default_value = 50 mode = GTK_LEVEL_BAR_MODE_HORIZONTAL inverted = false>
 * 
 * link_button:
 *      GtkWidget *create_link_button(const gchar *uri, const gchar *label);
 *      <link_button id = "link button" uri = "https://www.google.com" label = "Click me">
 * 
 * menu_button:
 *      GtkWidget *create_menu_button(const gchar *label, const gchar *path_to_image, GtkArrowType arrow_type);
 *      <menu_button id = "menu button" label = "Click me" path_to_image = "assets/Application_icon/apple.png" arrow_type = GTK_ARROW_DOWN>
 * 
 * menu_item:
 *      GtkWidget *create_menu_item(const gchar *label, const gchar *type, GtkWidget *submenu, GCallback callback, gpointer data);
 *      <menu_item id = "menu item" label = "Click me" type = "normal" submenu = NULL callback = NULL data = NULL>
 * 
 * menu: 
 *      GtkWidget *create_menu(gboolean is_primary, const gchar *label);
 *      <menu id = "menu id" is_primary = true label = "Click me">
 * 
 * progress_bar:
 *      GtkWidget *create_progress_bar(const gchar *text, gdouble fraction, gboolean show_text, gboolean pulse, gboolean inverted);
 *      <progress_bar id = "progress bar" text = "Click me" fraction = 0.5 show_text = true pulse = false inverted = false>
 * 
 * radio_button:
 *       GtkWidget *create_radio_button(const gchar *label, const gchar *path_to_image, GtkWidget *radio_group_member, gboolean default_state);
 *       <radio_button id = "radio button" label = "Click me" path_to_image = "assets/Application_icon/apple.png" id_radio_group_member = NULL default_state = false>
 * 
 * scale:
 *      GtkWidget *create_scale(GtkOrientation orientation, gdouble min_value, gdouble max_value, gdouble step, gdouble mark_value, GtkPositionType mark_position, const gchar *text, gint digits, GtkPositionType value_pos);
 *      <scale id = "scale id" orientation = GTK_ORIENTATION_VERTICAL min_value = 0 max_value = 100 step = 1 mark_value = 50 mark_position = 0.5 text = "Click me" digits = 0 value_pos = 0.5>
 * 
 * separator:
 *      GtkWidget *create_separator(GtkOrientation orientation);
 *      <separator id = "separator id" orientation = GTK_ORIENTATION_VERTICAL>
 * 
 * spin_button:
 *      GtkWidget *create_spin_button(gdouble min, gdouble max, gdouble step, gdouble value, guint digits, gboolean wrap, gboolean numeric);
 *      <spin_button id = "spin button" min = 0 max = 100 step = 1 value = 50 digits = 0 wrap = false numeric = false>
 * 
 * spinner:
 *      GtkWidget *create_spinner(gboolean active);
 *      <spinner id = "spinner id" active = true>
 * 
 * switch button:
 *      GtkWidget *create_switch_button(gboolean default_state, GCallback callback, gpointer data);
 *      <switch_button id = "switch button" default_state = true callback = NULL data = NULL>
 * 
 * text_view:
 *      GtkWidget *create_text_view(const gchar *text, gint size, const gchar *font, const gchar *color, const gchar *background, GtkJustification justify, PangoWeight weight, PangoStyle style, gboolean wrap, gboolean cursor_visible, gboolean editable);
 *      <text_view id = "text view" text = "Click me" size = 10 font = "Arial" color = "#FFFFFF" background = "#000000" justify = "GTK_JUSTIFY_CENTER" wrap = TRUE cursor_visible = true editable = true>
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 **********************************************************************************************/

// GtkWidget *create_window(GtkApplication *app, GtkWindowType type, const gchar *title, gint width, gint height, gboolean resizable, GtkWindowPosition position, gboolean decorate, GdkPixbuf *icon, double opacity, gboolean fullscrean);

void window_data_bases(NodeA *widget, FILE *file)
{
    // constructing data bases of the default values of a window
    NodeA *window = NULL;
    window = insert_end(window, "widget", "window", 1);
    window = insert_end(window, "app", "NULL", 0);
    window = insert_end(window, "type", "GTK_WINDOW_TOP_LEVEL", 0);
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

// GtkWidget *create_header_bar(const gchar *title, const gchar *subtitle, const gchar *icon_path, gboolean settings);


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
    switcher = insert_end(switcher, "buttons_same_size", "FALSE", 0);

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
    menu_item = insert_end(menu_item, "type", "normal", 0);
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
