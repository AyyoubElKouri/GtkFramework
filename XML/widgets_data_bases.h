/*****************************************************************************************************************************
 * 
 * @file widgets_data_bases.h
 * @brief the header file of the widgets data bases
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 2.0 (last update 01/02/2025)
 * 
 ****************************************************************************************************************************/



#include "analyzer.h"
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
 **********************************************************************************************/


void window_data_bases(NodeA *widget, FILE *file);

void header_bar_data_bases(NodeA *widget, FILE *file);

void scrolled_window_data_bases(NodeA *widget, FILE *file);

void box_data_bases(NodeA *widget, FILE *file);

void fixed_data_bases(NodeA *widget, FILE *file);

void frame_data_bases(NodeA *widget, FILE *file);

void grid_data_bases(NodeA *widget, FILE *file);

void paned_data_bases(NodeA *widget, FILE *file);

void stack_data_bases(NodeA *widget, FILE *file);

void switcher_data_bases(NodeA *widget, FILE *file);

void button_data_bases(NodeA *widget, FILE *file);

void check_button_data_bases(NodeA *widget, FILE *file);

void color_button_data_bases(NodeA *widget, FILE *file);

void entry_data_bases(NodeA *widget, FILE *file);

void font_button_data_bases(NodeA *widget, FILE *file);

void image_data_bases(NodeA *widget, FILE *file);

void label_data_bases(NodeA *widget, FILE *file);

void level_bar_data_bases(NodeA *widget, FILE *file);

void link_button_data_bases(NodeA *widget, FILE *file);

void menu_button_data_bases(NodeA *widget, FILE *file);

void menu_item_data_bases(NodeA *widget, FILE *file);

void menu_data_bases(NodeA *widget, FILE *file);

void progress_bar_data_bases(NodeA *widget, FILE *file);

void radio_button_data_bases(NodeA *widget, FILE *file);

void scale_data_bases(NodeA *widget, FILE *file);

void separator_data_bases(NodeA *widget, FILE *file);

void spin_button_data_bases(NodeA *widget, FILE *file);

void spinner_data_bases(NodeA *widget, FILE *file);

void switch_button_data_bases(NodeA *widget, FILE *file);

void text_view_data_bases(NodeA *widget, FILE *file);