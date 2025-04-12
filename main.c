#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
#include "XML/xscEngine/widgets_structures.h"
#include "t/widget_callbacks.h"
#include "t/xml_generate.h"

typedef enum{
	Windows,
	Containers,
	Widgets
} Section;

typedef void (*Callback)(GtkWidget *widget, gpointer data);


extern GtkWidget *test_box;
extern GtkWidget *global_tree;
extern data_widget* global_widget_data_pointer;
extern GtkWidget *drag_button;
extern GtkWidget *box_test;
 GtkWidget *window_case;
 GtkWidget *Windows_box;
 GtkWidget *Containers_box ;
 GtkWidget *Widgets_box;

GtkWidget *working_stack = NULL;


void function(){
	printf("test\n");
}


void AjouterButton(void (*function)()){
	GtkWidget *button = create_button(GTK_RELIEF_NORMAL, "click", FALSE, NULL, NULL, NULL);
	add_to_box(window_case, button, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	g_signal_connect(button, "clicked", G_CALLBACK(function), NULL);
}



void charger_fichier(GtkWidget *widget, gpointer data){
	char *chemin = get_text((GtkWidget *)data);

	char *commande = malloc(100 * sizeof(char));
	sprintf(commande, "cd XML; xsc %s", chemin);



	system(commande);
}


void onglet_fichier(GtkWidget *widget, gpointer data){
	char *chaine = get_text((GtkWidget *)data);
	box_test =create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
	add_to_stack(working_stack, box_test, chaine);
	show_widget(working_stack);
	show_widget(box_test);
}

void addEvents(char *buttonName, Section section, int size, char *color,  Callback callback)
{
	GtkWidget *button = create_button(GTK_RELIEF_NORMAL, buttonName, FALSE, NULL, G_CALLBACK(callback), NULL);
    gtk_button_set_relief(GTK_BUTTON(button) , GTK_RELIEF_NONE);

    GtkCssProvider *provider = gtk_css_provider_new();
    char *mycolor = g_strdup_printf("button { background-color: %s; }", color);
    gtk_css_provider_load_from_data(provider, mycolor, -1, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);

	GtkWidget *charge_frame = create_frame(buttonName, 0.5, 1);

	GtkWidget *charge_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 10);

	add_to_box(charge_box, button, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(charge_frame, charge_box, 2, 2, 2, 2);

	if(section == Windows) add_to_box(Windows_box, charge_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);
	else if (section == Containers) add_to_box(Containers_box, charge_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);
	else add_to_box(Widgets_box, charge_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);
}

void printhello(GtkWidget *widget, gpointer data){
	printf("hello\n");
}


static void activate(GtkApplication *app, gpointer data)
{
	global_tree = create_tree_view();
	GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 5000, 5000, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE, NULL, NULL);

	GtkWidget *Header_bar = create_header_bar("UIBuilder", "Build your UI Application", NULL, TRUE);

	add_header_bar_to_window(window, Header_bar);

	GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *app_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *main_paned = create_paned(GTK_ORIENTATION_HORIZONTAL, 215, TRUE);

	GtkWidget *hierarchy_widgets_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *hierarchy_widgets_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);

	GtkWidget *hierarchy_widgets_label = create_label("Widgets Hierarchy", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_box(hierarchy_widgets_label_box, hierarchy_widgets_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);

	add_to_box(hierarchy_widgets_box, hierarchy_widgets_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);

	GtkWidget *hierarchy_widgets_box_content = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *test_button = create_button(GTK_RELIEF_NORMAL, "This space is reserved for\n the Widgets Hierarchy", FALSE, NULL, NULL, NULL);

	add_to_box(hierarchy_widgets_box_content, global_tree, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(hierarchy_widgets_box, hierarchy_widgets_box_content, START, TRUE, TRUE, 0, 7, 0, 0, 7);

	add_to_paned(main_paned, hierarchy_widgets_box, FIRST);

	GtkWidget *build_space_paned = create_paned(GTK_ORIENTATION_HORIZONTAL, 750, TRUE);

	GtkWidget *first_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *contents_space_paned = create_paned(GTK_ORIENTATION_VERTICAL, 515, TRUE);

	GtkWidget *working_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *working_space_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);

	GtkWidget *working_space_label = create_label("Working Space", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_box(working_space_label_box, working_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);

	add_to_box(working_space_box, working_space_label_box, START, FALSE, FALSE, 0, 0, 0, 12, 7);

	GtkWidget *working_space_box_content = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *working_space_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *working_switcher = create_switcher(5, TRUE);

	add_to_box(working_space_box_content, working_switcher, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	working_stack = create_stack(working_switcher, 1, 600);

	test_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	add_to_stack(working_stack, test_box, "Principale");

	add_to_frame(working_space_frame, working_stack, 5, 5, 5, 5);

	add_to_box(working_space_box_content, working_space_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(working_space_box, working_space_box_content, START, TRUE, TRUE, 0, 7, 7, 0, 0);

	add_to_paned(contents_space_paned, working_space_box, FIRST);

	GtkWidget *widgets_informations_space = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *widgets_informations_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);

	GtkWidget *widgets_informations_label = create_label("Creatores", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_box(widgets_informations_label_box, widgets_informations_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);

	add_to_box(widgets_informations_space, widgets_informations_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);

	GtkWidget *widgets_informations_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *creators_grid = create_grid(0, 0, TRUE, TRUE);

	GtkWidget *creators_frame = create_frame(NULL, 1, 1);

	GtkWidget *Ayyoub_frame = create_frame(NULL, 1, 1);

	GtkWidget *Ayyoub = create_label("Ayyoub EL KOURI", 14, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);
	
	add_to_frame(Ayyoub_frame, Ayyoub, 5, 5, 5, 5);

	add_to_grid(creators_grid, Ayyoub_frame, 0, 0, 1, 1);

	GtkWidget *Yassine_frame = create_frame(NULL, 1, 1);

	GtkWidget *Yassine = create_label("Yassine EL Barni", 14, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_frame(Yassine_frame, Yassine, 5, 5, 5, 5);

	add_to_grid(creators_grid, Yassine_frame, 1, 0, 1, 1);

	GtkWidget *Maryem_frame = create_frame(NULL, 1, 1);

	GtkWidget *Maryem = create_label("Maryem SAMANI", 14, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_frame(Maryem_frame, Maryem, 5, 5, 5, 5);

	add_to_grid(creators_grid, Maryem_frame, 0, 1, 1, 1);

	GtkWidget *Imane_frame = create_frame(NULL, 1, 1);

	GtkWidget *Imane = create_label("Imane BELAYACHI", 14, "consolas", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_frame(Imane_frame, Imane, 5, 5, 5, 5);

	add_to_grid(creators_grid, Imane_frame, 1, 1, 1, 1);

	add_to_frame(creators_frame, creators_grid, 5, 5, 5, 5);

	add_to_box(widgets_informations_box, creators_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(widgets_informations_space, widgets_informations_box, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	add_to_paned(contents_space_paned, widgets_informations_space, SECOND);

	add_to_box(first_space_box, contents_space_paned, START, TRUE, TRUE, 0, 7, 0, 7, 7);

	add_to_paned(build_space_paned, first_space_box, FIRST);

	GtkWidget *second_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *second_space_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);

	GtkWidget *second_space_label = create_label("Widgets Catalog", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_box(second_space_label_box, second_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);

	add_to_box(second_space_box, second_space_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);

	GtkWidget *widgets_catalog_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *switcher_catalog = create_switcher(2, TRUE);

	add_to_box(widgets_catalog_box, switcher_catalog, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *stack_catalog = create_stack(switcher_catalog, GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT, 500);

	GtkWidget *scrolled_window_window = create_scrolled_window(FALSE, TRUE);

	Windows_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 7);

	window_case = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *window_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *window_label = create_label("Window", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_frame(window_label_frame, window_label, 5, 5, 0, 0);

	add_to_box(window_case, window_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *window_informations_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *window_informations_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *window_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *window_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_id_label, 0, 0, 1, 1);

	GtkWidget *window_informations_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(window_informations_grid, window_informations_id_value, 0, 1, 1, 1);

	GtkWidget *window_informations_app_label = create_label("Window", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_app_label, 1, 0, 1, 1);

	GtkWidget *window_informations_app_value = create_entry("app", "Chose App for TOPLEVEL", TRUE, TRUE, 200, 0.5);

	add_to_grid(window_informations_grid, window_informations_app_value, 1, 1, 1, 1);

	GtkWidget *window_informations_type_label = create_label("Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_type_label, 2, 0, 1, 1);

	GtkWidget *window_informations_type_value = create_entry("GTK_WINDOW_TOPLEVEL", "Chose Type of the window", TRUE, TRUE, 200, 0.5);

	add_to_grid(window_informations_grid, window_informations_type_value, 2, 1, 1, 1);

	GtkWidget *window_informations_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_title_label, 3, 0, 1, 1);

	GtkWidget *window_informations_title_value = create_entry("title", "Chose Title for TOPLEVEL", TRUE, TRUE, 200, 0.5);

	add_to_grid(window_informations_grid, window_informations_title_value, 3, 1, 1, 1);

	GtkWidget *window_informations_width_label = create_label("Width", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_width_label, 4, 0, 1, 1);

	GtkWidget *window_informations_width_value = create_spin_button(0, 1000, 10, 800, 0, FALSE, TRUE);

	set_value_spin_button(window_informations_width_value, 750);

	add_to_grid(window_informations_grid, window_informations_width_value, 4, 1, 1, 1);

	GtkWidget *window_informations_height_label = create_label("Height", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_height_label, 5, 0, 1, 1);

	GtkWidget *window_informations_height_value = create_spin_button(0, 1000, 10, 600, 0, FALSE, TRUE);

	set_value_spin_button(window_informations_height_value, 440);

	add_to_grid(window_informations_grid, window_informations_height_value, 5, 1, 1, 1);

	GtkWidget *window_informations_resizable_label = create_label("Resizable", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_resizable_label, 6, 0, 1, 1);

	GtkWidget *window_informations_resizable_value = create_combo_box();

	add_to_combo_box(window_informations_resizable_value, "TRUE");

	add_to_combo_box(window_informations_resizable_value, "FALSE");

	add_to_grid(window_informations_grid, window_informations_resizable_value, 6, 1, 1, 1);

	GtkWidget *window_informations_position_label = create_label("Position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_position_label, 7, 0, 1, 1);

	GtkWidget *window_informations_position_value = create_combo_box();

	add_to_combo_box(window_informations_position_value, "CENTER");

	add_to_combo_box(window_informations_position_value, "ON_PARENT");

	add_to_combo_box(window_informations_position_value, "MOUSE");
	
	add_to_grid(window_informations_grid, window_informations_position_value, 7, 1, 1, 1);

	GtkWidget *window_informations_decorate_label = create_label("Decorate", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_decorate_label, 8, 0, 1, 1);
	
	GtkWidget *window_informations_decorate_value = create_combo_box();
	
	add_to_combo_box(window_informations_decorate_value, "TRUE");

	add_to_combo_box(window_informations_decorate_value, "FALSE");

	add_to_grid(window_informations_grid, window_informations_decorate_value, 8, 1, 1, 1);

	GtkWidget *window_informations_icon_label = create_label("Icon", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_icon_label, 9, 0, 1, 1);

	GtkWidget *window_informations_icon_value = create_entry(NULL, "icon path", TRUE, TRUE, 200, 0.5);

	add_to_grid(window_informations_grid, window_informations_icon_value, 9, 1, 1, 1);

	GtkWidget *window_informations_opacity_label = create_label("Opacity", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_opacity_label, 10, 0, 1, 1);

	GtkWidget *window_informations_opacity_value = create_spin_button(0, 1, 0.1, 1, 1, FALSE, TRUE);

	add_to_grid(window_informations_grid, window_informations_opacity_value, 10, 1, 1, 1);

	GtkWidget *window_informations_fullscreen_label = create_label("Fullscreen", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_fullscreen_label, 11, 0, 1, 1);

	GtkWidget *window_informations_fullscreen_value = create_combo_box();
	
	add_to_combo_box(window_informations_fullscreen_value, "TRUE");

	add_to_combo_box(window_informations_fullscreen_value, "FALSE");

	set_active_item(window_informations_fullscreen_value, 1);
	
	add_to_grid(window_informations_grid, window_informations_fullscreen_value, 11, 1, 1, 1);

	GtkWidget *window_informations_color_label = create_label("Color", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_color_label, 12, 0, 1, 1);

	GtkWidget *window_informations_color_entry = create_entry(NULL, NULL, TRUE, TRUE, 100, 0.5);

	add_to_grid(window_informations_grid, window_informations_color_entry, 12, 1, 1, 1);

	GtkWidget *window_informations_image_label = create_label("Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_image_label, 13, 0, 1, 1);

	GtkWidget *window_informations_image_entry = create_entry(NULL, NULL, TRUE, TRUE, 100, 0.5);

	add_to_grid(window_informations_grid, window_informations_image_entry, 13, 1, 1, 1);
	
	windowI* mywindow = malloc(sizeof(windowI));
	if(!mywindow) exit(EXIT_FAILURE);

	mywindow->window_informations_app_value = window_informations_app_value;
	mywindow->window_informations_type_value = window_informations_type_value;
	mywindow->window_informations_title_value = window_informations_title_value;
	mywindow->window_informations_width_value = window_informations_width_value;
	mywindow->window_informations_height_value = window_informations_height_value;
	mywindow->window_informations_resizable_value = window_informations_resizable_value;
	mywindow->window_informations_position_value = window_informations_position_value;
	mywindow->window_informations_decorate_value = window_informations_decorate_value;
	mywindow->window_informations_icon_value = window_informations_icon_value;
    mywindow->window_informations_fullscreen_value = window_informations_fullscreen_value;
    mywindow->window_informations_id_value = window_informations_id_value;
    mywindow->window_informations_opacity_value = window_informations_opacity_value;
	mywindow->window_informations_color_entry = window_informations_color_entry;
	mywindow->window_informations_image_entry = window_informations_image_entry;

	GtkWidget *window_informations_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitementWindow), mywindow);

	add_to_grid(window_informations_grid, window_informations_add_button, 14, 0, 2, 1);

	add_to_box(window_informations_main_box, window_informations_grid, START, TRUE, FALSE, 0, 21, 21, 21, 21);

	add_to_frame(window_informations_frame, window_informations_main_box, 0, 0, 0, 0);

	add_to_box(window_case, window_informations_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Windows_box, window_case, START, FALSE, FALSE, 0, 7, 0, 0, 0);

	GtkWidget *Header_bar_case = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *header_bar_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *header_bar_label = create_label("Header Bar", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(header_bar_label_frame, header_bar_label, 5, 5, 0, 0);

	add_to_box(Header_bar_case, header_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *header_bar_informations_main_box_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *header_bar_informations_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *header_bar_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *header_bar_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_id_label, 0, 0, 1, 1);

	GtkWidget *header_bar_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(header_bar_informations_grid, header_bar_id_value, 0, 1, 1, 1);

	GtkWidget *header_bar_informations_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_title_label, 1, 0, 1, 1);

	GtkWidget *header_bar_informations_title_value = create_entry(NULL, "title", TRUE, TRUE, 200, 0.5);

	add_to_grid(header_bar_informations_grid, header_bar_informations_title_value, 1, 1, 1, 1);

	GtkWidget *header_bar_informations_subtitle_label = create_label("Subtitle", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_label, 2, 0, 1, 1);

	GtkWidget *header_bar_informations_subtitle_value = create_entry(NULL, "subtitle", TRUE, TRUE, 200, 0.5);

	add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_value, 2, 1, 1, 1);

	GtkWidget *header_bar_informations_icon_label = create_label("Icon", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_icon_label, 3, 0, 1, 1);

	GtkWidget *header_bar_informations_icon_value = create_entry(NULL, "icon path", TRUE, TRUE, 200	, 0.5);

	add_to_grid(header_bar_informations_grid, header_bar_informations_icon_value, 3, 1, 1, 1);

	GtkWidget *header_bar_informations_settings_label = create_label("Settings", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_settings_label, 4, 0, 1, 1);

	GtkWidget *header_bar_informations_settings_value = create_combo_box();

	add_to_combo_box(header_bar_informations_settings_value, "TRUE");

	add_to_combo_box(header_bar_informations_settings_value, "FALSE");

	add_to_grid(header_bar_informations_grid, header_bar_informations_settings_value, 4, 1, 1, 1);
	
	headerBarI *myHeaderBar = malloc(sizeof(headerBarI));
	if(!myHeaderBar) exit(EXIT_FAILURE);

	myHeaderBar->header_bar_id_value = header_bar_id_value;
	myHeaderBar->header_bar_informations_icon_value = header_bar_informations_icon_value;
	myHeaderBar->header_bar_informations_settings_value = header_bar_informations_settings_value;
	myHeaderBar->header_bar_informations_subtitle_value = header_bar_informations_subtitle_value;
	myHeaderBar->header_bar_informations_title_value = header_bar_informations_title_value;

	GtkWidget *header_bar_informations_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitementHeaderBar), myHeaderBar);

	add_to_grid(header_bar_informations_grid, header_bar_informations_add_button, 5, 0, 2, 1);

	add_to_box(header_bar_informations_main_box, header_bar_informations_grid, START, TRUE, FALSE, 0, 21, 21, 21, 21);

	add_to_frame(header_bar_informations_main_box_frame, header_bar_informations_main_box, 0, 0, 0, 0);

	add_to_box(Header_bar_case, header_bar_informations_main_box_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Windows_box, Header_bar_case, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *scrolled_window_case = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *scrolled_window_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *scrolled_window_label = create_label("scrolled window", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(scrolled_window_label_frame, scrolled_window_label, 5, 5, 0, 0);

	add_to_box(scrolled_window_case, scrolled_window_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *scrolled_window_informations_main_box_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *scrolled_window_informations_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *scrolled_window_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *scrolled_window_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_label, 0, 0, 1, 1);

	GtkWidget *scrolled_window_informations_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_value, 0, 1, 1, 1);

	GtkWidget *scrolled_window_informations_horizontal_label = create_label("Horizontal", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_label, 1, 0, 1, 1);

	GtkWidget *scrolled_window_informations_horizontal_value = create_combo_box();

	add_to_combo_box(scrolled_window_informations_horizontal_value, "TRUE");

	add_to_combo_box(scrolled_window_informations_horizontal_value, "FALSE");

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_value, 1, 1, 1, 1);

	GtkWidget *scrolled_window_informations_vertical_label = create_label("Vertical", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_label, 2, 0, 1, 1);

	GtkWidget *scrolled_window_informations_vertical_value = create_combo_box();

	add_to_combo_box(scrolled_window_informations_vertical_value, "TRUE");

	add_to_combo_box(scrolled_window_informations_vertical_value, "FALSE");

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_value, 2, 1, 1, 1);

	scrolled_windowI *myScrolled_window = malloc(sizeof(scrolled_windowI));
	if(!myScrolled_window) return;

	myScrolled_window->scrolled_window_informations_id_value = scrolled_window_informations_id_value;
	myScrolled_window->scrolled_window_informations_horizontal_value = scrolled_window_informations_horizontal_value;
	myScrolled_window->scrolled_window_informations_vertical_value = scrolled_window_informations_vertical_value;

	GtkWidget *scrolled_window_informations_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_scrolled_window), myScrolled_window);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_add_button, 3, 0, 2, 1);

	add_to_box(scrolled_window_informations_main_box, scrolled_window_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0);

	add_to_frame(scrolled_window_informations_main_box_frame, scrolled_window_informations_main_box, 0, 18, 14, 0);

	add_to_box(scrolled_window_case, scrolled_window_informations_main_box_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Windows_box, scrolled_window_case, START, FALSE, FALSE, 0, 25, 0, 0, 0);

	GtkWidget *charge_frame = create_frame("Charger une fichier", 0.5, 1);

	GtkWidget *charge_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 10);

	GtkWidget *charge_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_box(charge_box, charge_entry, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *charge_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(charger_fichier), charge_entry);

	add_to_box(charge_box, charge_button, START, FALSE, FALSE, 0, 0, 0, 0, 0);


	add_to_frame(charge_frame, charge_box, 2, 2, 2, 2);


	add_to_box(Windows_box, charge_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);


	//-----------------

	GtkWidget *onglet_frame = create_frame("Ongletr une fichier", 0.5, 1);

	GtkWidget *onglet_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 10);

	GtkWidget *onglet_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_box(onglet_box, onglet_entry, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *onglet_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(onglet_fichier), onglet_entry);

	add_to_box(onglet_box, onglet_button, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(onglet_frame, onglet_box, 2, 2, 2, 2);

	add_to_box(Windows_box, onglet_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_scrolled_window(scrolled_window_window, Windows_box);

	add_to_stack(stack_catalog, scrolled_window_window, "Windows");

	GtkWidget *scrolled_containers_window = create_scrolled_window(FALSE, TRUE);

	Containers_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 7);

	GtkWidget *Box_case = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *Box_case_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Box_case_label = create_label("Box", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Box_case_label_frame, Box_case_label, 5, 5, 0, 0);

	add_to_box(Box_case, Box_case_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *Box_case_informations_main_box_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Box_case_informations_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Box_case_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Box_case_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_id_label, 0, 0, 1, 1);

	GtkWidget *Box_case_informations_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Box_case_informations_grid, Box_case_informations_id_entry, 0, 1, 1, 1);

	GtkWidget *Box_case_informations_orientation_label = create_label("Orientation", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_label, 1, 0, 1, 1);

	GtkWidget *Box_case_informations_orientation_value = create_combo_box();

	add_to_combo_box(Box_case_informations_orientation_value, "HORIZONTAL");

	add_to_combo_box(Box_case_informations_orientation_value, "VERTICAL");

	add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_value, 1, 1, 1, 1);

	GtkWidget *Box_case_informations_align_label = create_label("Align", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_align_label, 2, 0, 1, 1);

	GtkWidget *Box_case_informations_align_value = create_combo_box();

	add_to_combo_box(Box_case_informations_align_value, "START");

	add_to_combo_box(Box_case_informations_align_value, "END");

	add_to_combo_box(Box_case_informations_align_value, "CENTER");

	add_to_combo_box(Box_case_informations_align_value, "-1");

	add_to_grid(Box_case_informations_grid, Box_case_informations_align_value, 2, 1, 1, 1);

	GtkWidget *Box_case_informations_spacing_label = create_label("Spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_label, 3, 0, 1, 1);

	GtkWidget *Box_case_informations_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, FALSE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_value, 3, 1, 1, 1);

	boxI* mybox = malloc(sizeof(boxI));
	if(!mybox) exit(EXIT_FAILURE);

	mybox->Box_case_informations_id_entry = Box_case_informations_id_entry;
	mybox->Box_case_informations_orientation_value = Box_case_informations_orientation_value;
	mybox->Box_case_informations_align_value = Box_case_informations_align_value;
	mybox->Box_case_informations_spacing_value = Box_case_informations_spacing_value;

	GtkWidget *Box_case_informations_add = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitementBox), mybox);

	add_to_grid(Box_case_informations_grid, Box_case_informations_add, 4, 0, 2, 1);

	add_to_box(Box_case_informations_main_box, Box_case_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0);

	add_to_frame(Box_case_informations_main_box_frame, Box_case_informations_main_box, 5, 18, 14, 0);

	add_to_box(Box_case, Box_case_informations_main_box_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Box_case, START, FALSE, FALSE, 0, 14, 0, 0, 0);

	GtkWidget *Fixed_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Fixed_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Fixed_label = create_label("Fixed", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Fixed_label_frame, Fixed_label, 5, 5, 0, 0);

	add_to_box(Fixed_box, Fixed_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Fixed_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *fixed_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Fixed_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Fixed_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Fixed_grid, Fixed_id_label, 0, 0, 1, 1);

	GtkWidget *Fixed_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Fixed_grid, Fixed_id_entry, 0, 1, 1, 1);

	fixedI *myfixed = malloc(sizeof(fixedI));
	if(!myfixed) exit(EXIT_FAILURE);
	myfixed->Fixed_id_entry = Fixed_id_entry;

	GtkWidget *Fixed_add = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_fixed), myfixed);

	add_to_grid(Fixed_grid, Fixed_add, 1, 0, 2, 1);

	add_to_box(fixed_main_box, Fixed_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Fixed_grid_frame, fixed_main_box, 14, 14, 14, 0);

	add_to_box(Fixed_box, Fixed_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Fixed_box, START, FALSE, FALSE, 0, 14, 0, 0, 0);

	GtkWidget *Frame_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Frame_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Frame_label = create_label("Frame", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Frame_label_frame, Frame_label, 5, 5, 0, 0);

	add_to_box(Frame_box, Frame_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Frame_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *frame_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Frame_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Frame_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_id_label, 0, 0, 1, 1);

	GtkWidget *Frame_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Frame_grid, Frame_id_entry, 0, 1, 1, 1);

	GtkWidget *Frame_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_title_label, 1, 0, 1, 1);

	GtkWidget *Frame_title_value = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(Frame_grid, Frame_title_value, 1, 1, 1, 1);

	GtkWidget *Frame_horizontal_placement_label = create_label("Horizontal placement", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_horizontal_placement_label, 2, 0, 1, 1);

	GtkWidget *Frame_horizontal_placement_value = create_spin_button(0, 1, 0.5, 0.5, 1, FALSE, TRUE);

	add_to_grid(Frame_grid, Frame_horizontal_placement_value, 2, 1, 1, 1);

	GtkWidget *Frame_vertical_placement_label = create_label("Vertical placement", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_vertical_placement_label, 3, 0, 1, 1);

	GtkWidget *Frame_vertical_placement_value = create_spin_button(0, 1, 0.5, 0.5, 1, FALSE, TRUE);

	add_to_grid(Frame_grid, Frame_vertical_placement_value, 3, 1, 1, 1);

	frameI *myframe = malloc(sizeof(frameI));
	if(!myframe) return;

	myframe->Frame_id_entry = Frame_id_entry;
	myframe->Frame_title_value = Frame_title_value;
	myframe->Frame_vertical_placement_value = Frame_vertical_placement_value;
	myframe->Frame_horizontal_placement_value = Frame_horizontal_placement_value;
	
	GtkWidget *Frame_add = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_frame), myframe);

	add_to_grid(Frame_grid, Frame_add, 4, 0, 2, 1);

	add_to_box(frame_main_box, Frame_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Frame_grid_frame, frame_main_box, 14, 14, 14, 0);

	add_to_box(Frame_box, Frame_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Frame_box, START, FALSE, FALSE, 0, 14, 0, 0, 0);

	GtkWidget *Grid_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Grid_label_frame = create_frame(NULL, 0.5, 0.5);
	
	GtkWidget *Grid_label = create_label("Grid", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Grid_label_frame, Grid_label, 5, 5, 0, 0);

	add_to_box(Grid_box, Grid_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Grid_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *grid_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Grid_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Grid_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
	
	add_to_grid(Grid_grid, Grid_id_label, 0, 0, 1, 1);

	GtkWidget *Grid_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Grid_grid, Grid_id_entry, 0, 1, 1, 1);
	
	GtkWidget *Grid_rows_spacing_label = create_label("Rows spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_rows_spacing_label, 1, 0, 1, 1);

	GtkWidget *Grid_rows_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, TRUE);

	add_to_grid(Grid_grid, Grid_rows_spacing_value, 1, 1, 1, 1);
	
	GtkWidget *Grid_columns_spacing_label = create_label("Columns spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_columns_spacing_label, 2, 0, 1, 1);

	GtkWidget *Grid_columns_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, TRUE);

	add_to_grid(Grid_grid, Grid_columns_spacing_value, 2, 1, 1, 1);

	GtkWidget *Grid_rows_homogeneous_label = create_label("Rows homogeneous", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_rows_homogeneous_label, 3, 0, 1, 1);

	GtkWidget *Grid_rows_homogeneous_value = create_combo_box();

	add_to_combo_box(Grid_rows_homogeneous_value, "TRUE");

	add_to_combo_box(Grid_rows_homogeneous_value, "FALSE");

	add_to_grid(Grid_grid, Grid_rows_homogeneous_value, 3, 1, 1, 1);

	GtkWidget *Grid_columns_homogeneous_label = create_label("Columns homogeneous", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_columns_homogeneous_label, 4, 0, 1, 1);

	GtkWidget *Grid_columns_homogeneous_value = create_combo_box();

	add_to_combo_box(Grid_columns_homogeneous_value, "TRUE");

	add_to_combo_box(Grid_columns_homogeneous_value, "FALSE");

	add_to_grid(Grid_grid, Grid_columns_homogeneous_value, 4, 1, 1, 1);

	gridI *mygrid = malloc(sizeof(gridI));
	if(!mygrid){
		exit(EXIT_FAILURE);
	}
	mygrid->Grid_id_entry = Grid_id_entry;
	mygrid->Grid_rows_spacing_value = Grid_rows_spacing_value;
	mygrid->Grid_columns_spacing_value = Grid_columns_spacing_value;
	mygrid->Grid_rows_homogeneous_value = Grid_rows_homogeneous_value;
	mygrid->Grid_columns_homogeneous_value = Grid_columns_homogeneous_value;

	GtkWidget *Grid_add = create_button(GTK_RELIEF_NORMAL, "Add", FALSE, NULL, G_CALLBACK(traitement_grid), mygrid);

	add_to_grid(Grid_grid, Grid_add, 5, 0, 2, 1);

	add_to_box(grid_main_box, Grid_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Grid_grid_frame, grid_main_box, 14, 14, 14, 0);

	add_to_box(Grid_box, Grid_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Grid_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Paned_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Paned_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Paned_label = create_label("Paned", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Paned_label_frame, Paned_label, 7, 7, 14, 0);

	add_to_box(Paned_box, Paned_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Paned_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *paned_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Paned_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Paned_id_label = create_label("ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_id_label, 0, 0, 1, 1);

	GtkWidget *Paned_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Paned_grid, Paned_id_value, 0, 1, 1, 1);

	GtkWidget *Paned_orientation_label = create_label("Orientation", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_orientation_label, 1, 0, 1, 1);

	GtkWidget *Paned_orientation_value = create_combo_box();

	add_to_combo_box(Paned_orientation_value, "HORIZONTAL");

	add_to_combo_box(Paned_orientation_value, "VERTICAL");

	add_to_grid(Paned_grid, Paned_orientation_value, 1, 1, 1, 1);

	GtkWidget *Paned_default_position_label = create_label("Default position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_default_position_label, 2, 0, 1, 1);

	GtkWidget *Paned_default_position_value = create_spin_button(0, 1000, 100, 500, 0, FALSE, TRUE);

	add_to_grid(Paned_grid, Paned_default_position_value, 2, 1, 1, 1);

	GtkWidget *Paned_show_handle_label = create_label("Show Handle", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_show_handle_label, 3, 0, 1, 1);

	GtkWidget *Paned_show_handle_combo_box = create_combo_box();

	add_to_combo_box(Paned_show_handle_combo_box, "TRUE");

	add_to_combo_box(Paned_show_handle_combo_box, "FALSE");

	add_to_grid(Paned_grid, Paned_show_handle_combo_box, 3, 1, 1, 1);

	panedI *mypaned = malloc(sizeof(panedI));
	if(!mypaned) {
		exit(EXIT_FAILURE);
	}

	mypaned->Paned_id_value = Paned_id_value;
	mypaned->Paned_orientation_value = Paned_orientation_value;
	mypaned->Paned_default_position_value = Paned_default_position_value;
	mypaned->Paned_show_handle_combo_box = Paned_show_handle_combo_box;

	GtkWidget *Paned_add = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_paned), mypaned);

	add_to_grid(Paned_grid, Paned_add, 4, 0, 2, 1);

	add_to_box(paned_main_box, Paned_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Paned_grid_frame, paned_main_box, 14, 14, 14, 0);

	add_to_box(Paned_box, Paned_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Paned_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Stack_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Stack_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Stack_label = create_label("Stack", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Stack_label_frame, Stack_label, 7, 7, 14, 0);

	add_to_box(Stack_box, Stack_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Stack_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *stack_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Stack_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *stack_widget_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_widget_id_label, 0, 0, 1, 1);

	GtkWidget *stack_widget_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Stack_grid, stack_widget_id_value, 0, 1, 1, 1);
	
	GtkWidget *stack_switcher_widget_label = create_label("Switcher ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_switcher_widget_label, 1, 0, 1, 1);

	GtkWidget *stack_switcher_widget_id = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Stack_grid, stack_switcher_widget_id, 1, 1, 1, 1);

	GtkWidget *stack_transition_type_label = create_label("Transition Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_transition_type_label, 2, 0, 1, 1);

	GtkWidget *stack_transition_type_value_combo_box = create_combo_box();

	add_to_combo_box(stack_transition_type_value_combo_box, "CROSSFADE");

	add_to_combo_box(stack_transition_type_value_combo_box, "NONE");

	add_to_combo_box(stack_transition_type_value_combo_box, "SLIDE_LEFT");

	add_to_combo_box(stack_transition_type_value_combo_box, "SLIDE_RIGHT");

	add_to_grid(Stack_grid, stack_transition_type_value_combo_box, 2, 1, 1, 1);

	GtkWidget *stack_duration_label = create_label("Duration", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_duration_label, 3, 0, 1, 1);

	GtkWidget *stack_duration_value_spin_button = create_spin_button(0, 1000, 100, 500, 0, FALSE, TRUE);

	add_to_grid(Stack_grid, stack_duration_value_spin_button, 3, 1, 1, 1);

	stackI *mystack = malloc(sizeof(stackI));
	if(!mystack) return;

	mystack->stack_widget_id_value = stack_widget_id_value;
	mystack->stack_switcher_widget_id = stack_switcher_widget_id;
	mystack->stack_transition_type_value_combo_box = stack_transition_type_value_combo_box;
	mystack->stack_duration_value_spin_button = stack_duration_value_spin_button;

	GtkWidget *stack_informations_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_stack), mystack);

	add_to_grid(Stack_grid, stack_informations_add_button, 4, 0, 2, 1);

	add_to_box(stack_main_box, Stack_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Stack_grid_frame, stack_main_box, 14, 14, 14, 14);

	add_to_box(Stack_box, Stack_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Stack_box, START, FALSE, FALSE, 0, 14, 0, 0, 0);

	GtkWidget *Switcher_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Switcher_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Switcher_label = create_label("Switcher", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Switcher_label_frame, Switcher_label, 7, 7, 14, 0);

	add_to_box(Switcher_box, Switcher_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Switcher_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *switcher_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Switcher_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *switcher_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, switcher_id_label, 0, 0, 1, 1);

	GtkWidget *switcher_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Switcher_grid, switcher_id_entry, 0, 1, 1, 1);

	GtkWidget *switcher_spacing_label = create_label("Spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, switcher_spacing_label, 1, 0, 1, 1);

	GtkWidget *switcher_spacing_value_spin_button = create_spin_button(0, 100, 5, 5, 0, FALSE, TRUE);

	add_to_grid(Switcher_grid, switcher_spacing_value_spin_button, 1, 1, 1, 1);

	GtkWidget *same_size_label = create_label("Same Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, same_size_label, 2, 0, 1, 1);

	GtkWidget *same_size_value_combo_box = create_combo_box();

	add_to_combo_box(same_size_value_combo_box, "TRUE");

	add_to_combo_box(same_size_value_combo_box, "FALSE");

	add_to_grid(Switcher_grid, same_size_value_combo_box, 2, 1, 1, 1);

	switcherI *myswitcher = malloc(sizeof(switcherI));
	if(!myswitcher) return;

	myswitcher->switcher_id_entry = switcher_id_entry;
	myswitcher->switcher_spacing_value_spin_button = switcher_spacing_value_spin_button;
	myswitcher->same_size_value_combo_box = same_size_value_combo_box;

	GtkWidget *switcher_informations_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_switcher), myswitcher);

	add_to_grid(Switcher_grid, switcher_informations_add_button, 3, 0, 2, 1);

	add_to_box(switcher_main_box, Switcher_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Switcher_grid_frame, switcher_main_box, 14, 14, 14, 14);

	add_to_box(Switcher_box, Switcher_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Switcher_box, START, FALSE, FALSE, 0, 14, 0, 0, 0);

	add_to_scrolled_window(scrolled_containers_window, Containers_box);

	add_to_stack(stack_catalog, scrolled_containers_window, "Containers");

	GtkWidget *scrolled_widgets_window = create_scrolled_window(FALSE, TRUE);

	Widgets_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 7);

	GtkWidget *button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *button_label = create_label("Button", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(button_label_frame, button_label, 7, 7, 14, 0);

	add_to_box(button_box, button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *button_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_id_label, 0, 0, 1, 1);

	GtkWidget *button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(button_grid, button_id_entry, 0, 1, 1, 1);

	GtkWidget *button_relief_label = create_label("Relief", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_relief_label, 1, 0, 1, 1);

	GtkWidget *button_relief_combo_box = create_combo_box();

	add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NONE");

	add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NORMAL");

	add_to_grid(button_grid, button_relief_combo_box, 1, 1, 1, 1);

	GtkWidget *button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_label_label, 2, 0, 1, 1);

	GtkWidget *button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(button_grid, button_label_entry, 2, 1, 1, 1);

	GtkWidget *button_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_use_underline_label, 3, 0, 1, 1);

	GtkWidget *button_use_underline_combo_box = create_combo_box();

	add_to_combo_box(button_use_underline_combo_box, "TRUE");

	add_to_combo_box(button_use_underline_combo_box, "FALSE");

	add_to_grid(button_grid, button_use_underline_combo_box, 3, 1, 1, 1);

	GtkWidget *button_path_to_image_label = create_label("Path to Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_path_to_image_label, 4, 0, 1, 1);

	GtkWidget *button_path_to_image_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(button_grid, button_path_to_image_entry, 4, 1, 1, 1);

	GtkWidget *button_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_callback_label, 5, 0, 1, 1);

	GtkWidget *button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(button_grid, button_callback_entry, 5, 1, 1, 1);

	GtkWidget *button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_data_label, 6, 0, 1, 1);

	GtkWidget *button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(button_grid, button_data_entry, 6, 1, 1, 1);

	buttonI *mybutton = malloc(sizeof(buttonI));
	if(!mybutton) return;

	mybutton->button_id_entry = button_id_entry;
    mybutton->button_relief_combo_box = button_relief_combo_box;
    mybutton->button_label_entry = button_label_entry;
    mybutton->button_use_underline_combo_box = button_use_underline_combo_box;
    mybutton->button_path_to_image_entry = button_path_to_image_entry;
    mybutton->button_callback_entry = button_callback_entry;
    mybutton->button_data_entry = button_data_entry;

	GtkWidget *button_add = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_button), mybutton);

	add_to_grid(button_grid, button_add, 7, 0, 2, 1);

	add_to_box(button_main_box, button_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(button_grid_frame, button_main_box, 14, 14, 14, 14);

	add_to_box(button_box, button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, button_box, START, FALSE, FALSE, 0, 7, 0, 0, 0);

	GtkWidget *check_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *check_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *check_button_label = create_label("Check Button", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(check_button_label_frame, check_button_label, 7, 7, 14, 14);

	add_to_box(check_button_box, check_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *check_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *check_button_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *check_button_grid = create_grid(7, 0, FALSE, FALSE);

	GtkWidget *check_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_id_label, 0, 0, 1, 1);

	GtkWidget *check_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(check_button_grid, check_button_id_entry, 0, 1, 1, 1);

	GtkWidget *check_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_label_label, 1, 0, 1, 1);

	GtkWidget *check_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(check_button_grid, check_button_label_entry, 1, 1, 1, 1);

	GtkWidget *check_button_active_label = create_label("Active", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_active_label, 2, 0, 1, 1);

	GtkWidget *check_button_active_combo_box = create_combo_box();

	add_to_combo_box(check_button_active_combo_box, "TRUE");

	add_to_combo_box(check_button_active_combo_box, "FALSE");

	add_to_grid(check_button_grid, check_button_active_combo_box, 2, 1, 1, 1);

	GtkWidget *check_button_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_use_underline_label, 3, 0, 1, 1);

	GtkWidget *check_button_use_underline_combo_box = create_combo_box();

	add_to_combo_box(check_button_use_underline_combo_box, "TRUE");

	add_to_combo_box(check_button_use_underline_combo_box, "FALSE");

	add_to_grid(check_button_grid, check_button_use_underline_combo_box, 3, 1, 1, 1);

	GtkWidget *check_button_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_callback_label, 4, 0, 1, 1);

	GtkWidget *check_button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(check_button_grid, check_button_callback_entry, 4, 1, 1, 1);

	GtkWidget *check_button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_data_label, 5, 0, 1, 1);

	GtkWidget *check_button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(check_button_grid, check_button_data_entry, 5, 1, 1, 1);

	check_buttonI *myCheck_button = malloc(sizeof(check_buttonI));
	if(!myCheck_button) return;

	myCheck_button->check_button_id_entry = check_button_id_entry;
    myCheck_button->check_button_label_entry = check_button_label_entry;
    myCheck_button->check_button_active_combo_box = check_button_active_combo_box;
    myCheck_button->check_button_use_underline_combo_box = check_button_use_underline_combo_box;
    myCheck_button->check_button_callback_entry = check_button_callback_entry;
    myCheck_button->check_button_data_entry = check_button_data_entry;

	GtkWidget *check_button_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_check_button), myCheck_button);

	add_to_grid(check_button_grid, check_button_add_button, 6, 0, 2, 1);

	add_to_box(check_button_main_box, check_button_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(check_button_grid_frame, check_button_main_box, 14, 14, 14, 14);

	add_to_box(check_button_box, check_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, check_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *color_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *color_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *color_button_label_label = create_label("Color Button", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(color_button_label_frame, color_button_label_label, 7, 7, 14, 0);

	add_to_box(color_button_box, color_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *color_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *color_button_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *color_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *color_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_id_label, 0, 0, 1, 1);

	GtkWidget *color_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(color_button_grid, color_button_id_entry, 0, 1, 1, 1);

	GtkWidget *color_button_default_color_label = create_label("Default Color", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_default_color_label, 1, 0, 1, 1);

	GtkWidget *color_button_default_color_color_button = create_color_button("#FFFFFF", "coloring", TRUE);

	add_to_grid(color_button_grid, color_button_default_color_color_button, 1, 1, 1, 1);

	GtkWidget *color_button_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_title_label, 2, 0, 1, 1);

	GtkWidget *color_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(color_button_grid, color_button_label_entry, 2, 1, 1, 1);

	GtkWidget *color_button_use_alpha_label = create_label("Use Alpha", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_use_alpha_label, 3, 0, 1, 1);

	GtkWidget *color_button_use_alpha_combo_box = create_combo_box();

	add_to_combo_box(color_button_use_alpha_combo_box, "TRUE");

	add_to_combo_box(color_button_use_alpha_combo_box, "FALSE");

	add_to_grid(color_button_grid, color_button_use_alpha_combo_box, 3, 1, 1, 1);

	color_buttonI *myColor_button = malloc(sizeof(color_buttonI));
	if(!myCheck_button) return;

	myColor_button->color_button_id_entry = color_button_id_entry;
    myColor_button->color_button_default_color_color_button = color_button_default_color_color_button;
    myColor_button->color_button_label_entry = color_button_label_entry;
    myColor_button->color_button_use_alpha_combo_box = color_button_use_alpha_combo_box;

	GtkWidget *color_button_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_color_button), myColor_button);

	add_to_grid(color_button_grid, color_button_add_button, 4, 0, 2, 1);

	add_to_box(color_button_main_box, color_button_grid, START, TRUE, FALSE , 0, 0, 0, 0, 0);

	add_to_frame(color_button_grid_frame, color_button_main_box, 14, 14, 14, 14);

	add_to_box(color_button_box, color_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, color_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *combo_box_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *combo_box_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *combo_box_label_label = create_label("Combo Box", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(combo_box_label_frame, combo_box_label_label, 7, 7, 14, 0);

	add_to_box(combo_box_box, combo_box_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *combo_box_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *combo_box_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *combo_box_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *combo_box_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(combo_box_grid, combo_box_id_label, 0, 0, 1, 1);

	GtkWidget *combo_box_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(combo_box_grid, combo_box_id_entry, 0, 1, 1, 1);

	combo_boxI *myCombo_box = malloc(sizeof(combo_boxI));
	if(!myCombo_box) return;

	myCombo_box->combo_box_id_entry = combo_box_id_entry;

	GtkWidget *combo_box_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_combo_box), myCombo_box);

	add_to_grid(combo_box_grid, combo_box_add_button, 1, 0, 2, 1);

	add_to_box(combo_box_main_box, combo_box_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(combo_box_grid_frame, combo_box_main_box, 14, 14, 14, 14);

	add_to_box(combo_box_box, combo_box_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, combo_box_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *entry_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *entry_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *entry_label_label = create_label("Entry", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(entry_label_frame, entry_label_label, 7, 7, 14, 0);

	add_to_box(entry_box, entry_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *entry_box_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *entry_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *entry_box_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *entry_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_id_label, 0, 0, 1, 1);

	GtkWidget *entry_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(entry_box_grid, entry_id_entry, 0, 1, 1, 1);

	GtkWidget *entry_default_text_label = create_label("Default Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_default_text_label, 1, 0, 1, 1);

	GtkWidget *entry_default_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(entry_box_grid, entry_default_text_entry, 1, 1, 1, 1);

	GtkWidget *entry_indicator_text_label = create_label("Indicator Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_indicator_text_label, 2, 0, 1, 1);

	GtkWidget *entry_indicator_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(entry_box_grid, entry_indicator_text_entry, 2, 1, 1, 1);

	GtkWidget *entry_visibility_label = create_label("Visibility", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_visibility_label, 3, 0, 1, 1);

	GtkWidget *entry_visibility_combo_box = create_combo_box();

	add_to_combo_box(entry_visibility_combo_box, "TRUE");

	add_to_combo_box(entry_visibility_combo_box, "FALSE");

	add_to_grid(entry_box_grid, entry_visibility_combo_box, 3, 1, 1, 1);

	GtkWidget *entry_editable_label = create_label("Editable", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_editable_label, 4, 0, 1, 1);

	GtkWidget *entry_editable_combo_box = create_combo_box();

	add_to_combo_box(entry_editable_combo_box, "TRUE");

	add_to_combo_box(entry_editable_combo_box, "FALSE");

	add_to_grid(entry_box_grid, entry_editable_combo_box, 4, 1, 1, 1);

	GtkWidget *entry_max_length_label = create_label("Max Length", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_max_length_label, 5, 0, 1, 1);

	GtkWidget *entry_max_length_spin_button = create_spin_button(0, 100, 5, 20, 0, FALSE, FALSE);

	add_to_grid(entry_box_grid, entry_max_length_spin_button, 5, 1, 1, 1);

	GtkWidget *entry_alignment_label = create_label("Alignment", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_alignment_label, 6, 0, 1, 1);

	GtkWidget *entry_alignment_spin_button = create_spin_button(0, 1, 0.5, 0, 1, FALSE, FALSE);

	add_to_grid(entry_box_grid, entry_alignment_spin_button, 6, 1, 1, 1);

	entryI *myentry = malloc(sizeof(entryI));
	if(!myentry) return;

	myentry->entry_id_entry = entry_id_entry;
    myentry->entry_default_text_entry = entry_default_text_entry;
    myentry->entry_indicator_text_entry = entry_indicator_text_entry;
    myentry->entry_visibility_combo_box = entry_visibility_combo_box;
    myentry->entry_editable_combo_box = entry_editable_combo_box;
    myentry->entry_max_length_spin_button = entry_max_length_spin_button;
    myentry->entry_alignment_spin_button = entry_alignment_spin_button;

	GtkWidget *entry_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_entry), myentry);

	add_to_grid(entry_box_grid, entry_add_button, 7, 0, 2, 1);

	add_to_box(entry_main_box, entry_box_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(entry_box_grid_frame, entry_main_box, 14, 14, 14, 14);

	add_to_box(entry_box, entry_box_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, entry_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *font_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *font_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *font_button_label = create_label("Font Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(font_button_label_frame, font_button_label, 7, 7, 14, 14);

	add_to_box(font_button_box, font_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *font_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *font_button_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *font_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *font_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_id_label, 0, 0, 1, 1);

	GtkWidget *font_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(font_button_grid, font_button_id_entry, 0, 1, 1, 1);

	GtkWidget *font_button_default_font_name_label = create_label("Default Font Name", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_default_font_name_label, 1, 0, 1, 1);

	GtkWidget *font_button_default_font_name_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(font_button_grid, font_button_default_font_name_entry, 1, 1, 1, 1);

	GtkWidget *font_button_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_title_label, 2, 0, 1, 1);

	GtkWidget *font_button_title_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(font_button_grid, font_button_title_entry, 2, 1, 1, 1);

	GtkWidget *font_button_show_size_label = create_label("Show Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_show_size_label, 3, 0, 1, 1);

	GtkWidget *font_button_show_size_combo_box = create_combo_box();

	add_to_combo_box(font_button_show_size_combo_box, "TRUE");

	add_to_combo_box(font_button_show_size_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_show_size_combo_box, 3, 1, 1, 1);

	GtkWidget *font_button_show_style_label = create_label("Show Style", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_show_style_label, 4, 0, 1, 1);

	GtkWidget *font_button_show_style_combo_box = create_combo_box();

	add_to_combo_box(font_button_show_style_combo_box, "TRUE");

	add_to_combo_box(font_button_show_style_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_show_style_combo_box, 4, 1, 1, 1);

	GtkWidget *font_button_use_size_label = create_label("Use Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_use_size_label, 5, 0, 1, 1);

	GtkWidget *font_button_use_size_combo_box = create_combo_box();

	add_to_combo_box(font_button_use_size_combo_box, "TRUE");

	add_to_combo_box(font_button_use_size_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_use_size_combo_box, 5, 1, 1, 1);

	GtkWidget *font_button_use_font_label = create_label("Use Font", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_use_font_label, 6, 0, 1, 1);

	GtkWidget *font_button_use_font_combo_box = create_combo_box();

	add_to_combo_box(font_button_use_font_combo_box, "TRUE");

	add_to_combo_box(font_button_use_font_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_use_font_combo_box, 6, 1, 1, 1);

	font_buttonI *myFont_button = malloc(sizeof(font_buttonI));
	if(!myFont_button) return;

	myFont_button->font_button_id_entry = font_button_id_entry;
    myFont_button->font_button_default_font_name_entry = font_button_default_font_name_entry;
    myFont_button->font_button_title_entry = font_button_title_entry;
    myFont_button->font_button_show_size_combo_box = font_button_show_size_combo_box;
	myFont_button->font_button_show_style_combo_box = font_button_show_style_combo_box;
    myFont_button->font_button_use_size_combo_box = font_button_use_size_combo_box;
    myFont_button->font_button_use_font_combo_box = font_button_use_font_combo_box;

	GtkWidget *font_button_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_font_button), myFont_button);

	add_to_grid(font_button_grid, font_button_add_button, 7, 0, 2, 1);

	add_to_box(font_button_main_box, font_button_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(font_button_grid_frame, font_button_main_box, 14, 14, 14, 14);

	add_to_box(font_button_box, font_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, font_button_box, START, FALSE, FALSE, 0, 7, 0, 0, 0);

	GtkWidget *image_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *image_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *image_label = create_label("Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(image_label_frame, image_label, 7, 7, 14, 14);

	add_to_box(image_box, image_label_frame, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *image_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *image_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *image_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *image_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(image_grid, image_id_label, 0, 0, 1, 1);

	GtkWidget *image_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(image_grid, image_id_entry, 0, 1, 1, 1);

	GtkWidget *image_path_label = create_label("Path", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(image_grid, image_path_label, 1, 0, 1, 1);

	GtkWidget *image_path_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(image_grid, image_path_entry, 1, 1, 1, 1);

	imageI *myimage = malloc(sizeof(imageI));
	if(!myimage) return;

	myimage->image_id_entry = image_id_entry;
    myimage->image_path_entry = image_path_entry;

	GtkWidget *image_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_image), myimage);

	add_to_grid(image_grid, image_add_button, 2, 0, 2, 1);

	add_to_box(image_main_box, image_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(image_grid_frame, image_main_box, 14, 14, 14, 14);

	add_to_box(image_box, image_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, image_box, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *label_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *label_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(label_label_frame, label_label, 7, 7, 14, 14);

	add_to_box(label_box, label_label_frame, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *label_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *label_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *label_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *label_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_id_label, 0, 0, 1, 1);

	GtkWidget *label_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(label_grid, label_id_entry, 0, 1, 1, 1);

	GtkWidget *label_text_label = create_label("Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_text_label, 1, 0, 1, 1);

	GtkWidget *label_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(label_grid, label_text_entry, 1, 1, 1, 1);

	GtkWidget *label_size_label = create_label("Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_size_label, 2, 0, 1, 1);

	GtkWidget *label_size_spin_button = create_spin_button(0, 100, 5, 0, 0, FALSE, FALSE);

	add_to_grid(label_grid, label_size_spin_button, 2, 1, 1, 1);

	GtkWidget *label_font_label = create_label("Font", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_font_label, 3, 0, 1, 1);

	GtkWidget *label_font_font_button = create_font_button("Arial", "font", TRUE, TRUE, FALSE, FALSE);

	add_to_grid(label_grid, label_font_font_button, 3, 1, 1, 1);

	GtkWidget *label_color_label = create_label("Color", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_color_label, 4, 0, 1, 1);

	GtkWidget *label_color_color_button = create_color_button("#FFFFFF", "coloring", TRUE);

	add_to_grid(label_grid, label_color_color_button, 4, 1, 1, 1);

	GtkWidget *label_background_label = create_label("Background", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_background_label, 5, 0, 1, 1);

	GtkWidget *label_background_color_button = create_color_button("#000000", "coloring", TRUE);

	add_to_grid(label_grid, label_background_color_button, 5, 1, 1, 1);

	GtkWidget *label_justify_label = create_label("Justify", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_justify_label, 6, 0, 1, 1);

	GtkWidget *label_justify_combo_box = create_combo_box();

	add_to_combo_box(label_justify_combo_box, "CENTER");

	add_to_combo_box(label_justify_combo_box, "LEFT");

	add_to_combo_box(label_justify_combo_box, "RIGHT");

	add_to_grid(label_grid, label_justify_combo_box, 6, 1, 1, 1);

	GtkWidget *label_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_use_underline_label, 7, 0, 1, 1);

	GtkWidget *label_use_underline_combo_box = create_combo_box();

	add_to_combo_box(label_use_underline_combo_box, "TRUE");

	add_to_combo_box(label_use_underline_combo_box, "FALSE");

	add_to_grid(label_grid, label_use_underline_combo_box, 7, 1, 1, 1);

	GtkWidget *label_pango_weight_label = create_label("Pango Weight", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_pango_weight_label, 8, 0, 1, 1);

	GtkWidget *label_pango_weight_combo_box = create_combo_box();

	add_to_combo_box(label_pango_weight_combo_box, "NORMAL");

	add_to_combo_box(label_pango_weight_combo_box, "BOLD");

	add_to_grid(label_grid, label_pango_weight_combo_box, 8, 1, 1, 1);

	GtkWidget *label_pango_style_label = create_label("Pango Style", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_pango_style_label, 9, 0, 1, 1);

	GtkWidget *label_pango_style_combo_box = create_combo_box();

	add_to_combo_box(label_pango_style_combo_box, "NORMAL");

	add_to_combo_box(label_pango_style_combo_box, "ITALIC");

	add_to_grid(label_grid, label_pango_style_combo_box, 9, 1, 1, 1);

	GtkWidget *label_wrap_label = create_label("Wrap", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_wrap_label, 10, 0, 1, 1);

	GtkWidget *label_wrap_combo_box = create_combo_box();

	add_to_combo_box(label_wrap_combo_box, "TRUE");

	add_to_combo_box(label_wrap_combo_box, "FALSE");

	add_to_grid(label_grid, label_wrap_combo_box, 10, 1, 1, 1);

	labelI *mylabel = malloc(sizeof(labelI));
	if(!mylabel) return;

	mylabel->label_id_entry = label_id_entry;
    mylabel->label_text_entry = label_text_entry;
    mylabel->label_size_spin_button = label_size_spin_button;
    mylabel->label_font_font_button = label_font_font_button;
    mylabel->label_color_color_button = label_color_color_button;
    mylabel->label_background_color_button = label_background_color_button;
    mylabel->label_justify_combo_box = label_justify_combo_box;
    mylabel->label_use_underline_combo_box = label_use_underline_combo_box;
    mylabel->label_pango_weight_combo_box = label_pango_weight_combo_box;
    mylabel->label_pango_style_combo_box = label_pango_style_combo_box;
    mylabel->label_wrap_combo_box = label_wrap_combo_box;

	GtkWidget *label_button_add = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_label), mylabel);

	add_to_grid(label_grid, label_button_add, 11, 0, 2, 1);

	add_to_box(label_main_box, label_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(label_grid_frame, label_main_box, 14, 14, 14, 14);

	add_to_box(label_box, label_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, label_box, START, FALSE, FALSE, 0, 7, 0, 0, 0);

	GtkWidget *level_bar_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *level_bar_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *level_bar_label = create_label("Level Bar", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(level_bar_label_frame, level_bar_label, 7, 7, 14, 0);

	add_to_box(level_bar_box, level_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *level_bar_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *level_bar_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *level_bar_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *level_bar_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_id_label, 0, 0, 1, 1);

	GtkWidget *level_bar_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(level_bar_grid, level_bar_id_entry, 0, 1, 1, 1);

	GtkWidget *level_bar_min_value_label = create_label("Min Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_min_value_label, 1, 0, 1, 1);

	GtkWidget *level_bar_min_value_spin_button = create_spin_button(0, 100, 1, 0, 0, FALSE, FALSE);

	add_to_grid(level_bar_grid, level_bar_min_value_spin_button, 1, 1, 1, 1);

	GtkWidget *level_bar_max_value_label = create_label("Max Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_max_value_label, 2, 0, 1, 1);

	GtkWidget *level_bar_max_value_spin_button = create_spin_button(0, 100, 1, 10, 0, FALSE, FALSE);

	add_to_grid(level_bar_grid, level_bar_max_value_spin_button, 2, 1, 1, 1);

	GtkWidget *level_bar_default_value_label = create_label("Default Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_default_value_label, 3, 0, 1, 1);

	GtkWidget *level_bar_default_value_spin_button = create_spin_button(0, 100, 1, 50, 0, FALSE, FALSE);

	add_to_grid(level_bar_grid, level_bar_default_value_spin_button, 3, 1, 1, 1);

	GtkWidget *level_bar_mode_label = create_label("Mode", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_mode_label, 4, 0, 1, 1);

	GtkWidget *level_bar_mode_combo_box = create_combo_box();

	add_to_combo_box(level_bar_mode_combo_box, "CONTINUOUS");

	add_to_combo_box(level_bar_mode_combo_box, "DISCRETE");

	add_to_grid(level_bar_grid, level_bar_mode_combo_box, 4, 1, 1, 1);

	GtkWidget *level_bar_reversed_label = create_label("Reversed", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_reversed_label, 5, 0, 1, 1);

	GtkWidget *level_bar_reversed_combo_box = create_combo_box();

	add_to_combo_box(level_bar_reversed_combo_box, "FALSE");

	add_to_combo_box(level_bar_reversed_combo_box, "TRUE");

	add_to_grid(level_bar_grid, level_bar_reversed_combo_box, 5, 1, 1, 1);

	level_barI *myLevel_bar = malloc(sizeof(level_barI));
	if(!myLevel_bar) return;

	myLevel_bar->level_bar_id_entry = level_bar_id_entry;
    myLevel_bar->level_bar_min_value_spin_button = level_bar_min_value_spin_button;
    myLevel_bar->level_bar_max_value_spin_button = level_bar_max_value_spin_button;
    myLevel_bar->level_bar_default_value_spin_button = level_bar_default_value_spin_button;
    myLevel_bar->level_bar_mode_combo_box = level_bar_mode_combo_box;
    myLevel_bar->level_bar_reversed_combo_box = level_bar_reversed_combo_box;

	GtkWidget *level_bar_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_level_bar), myLevel_bar);

	add_to_grid(level_bar_grid, level_bar_add_button, 6, 0, 2, 1);

	add_to_box(level_bar_main_box, level_bar_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(level_bar_grid_frame, level_bar_main_box, 14, 14, 14, 14);

	add_to_box(level_bar_box, level_bar_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, level_bar_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Link_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *Link_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Link_button_label = create_label("Link Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Link_button_label_frame, Link_button_label, 7, 7, 14, 1);

	add_to_box(Link_button_box, Link_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *Link_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *link_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *Link_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Link_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_id_label, 0, 0, 1, 1);

	GtkWidget *Link_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(Link_button_grid, Link_button_id_entry, 0, 1, 1, 1);

	GtkWidget *Link_button_url_label = create_label("URL", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_url_label, 1, 0, 1, 1);

	GtkWidget *Link_button_url_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	set_text(Link_button_url_entry, "https://www.google.com/");

	add_to_grid(Link_button_grid, Link_button_url_entry, 1, 1, 1, 1);

	GtkWidget *Link_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_label_label, 2, 0, 1, 1);

	GtkWidget *Link_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(Link_button_grid, Link_button_label_entry, 2, 1, 1, 1);

	link_buttonI *myLink_button = malloc(sizeof(link_buttonI));
	if(!myLink_button) return;

	myLink_button->Link_button_id_entry = Link_button_id_entry;
	myLink_button->Link_button_url_entry = Link_button_url_entry;
	myLink_button->Link_button_label_entry = Link_button_label_entry;

	GtkWidget *Link_button_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_link_button), myLink_button);

	add_to_grid(Link_button_grid, Link_button_add_button, 3, 0, 2, 1);

	add_to_box(link_main_box, Link_button_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(Link_button_grid_frame, link_main_box, 14, 14, 14, 14);

	add_to_box(Link_button_box, Link_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, Link_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *menu_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *menu_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_button_label = create_label("Menu Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(menu_button_label_frame, menu_button_label, 7, 7, 14, 1);

	add_to_box(menu_button_box, menu_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_button_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *menu_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_id_label, 0, 0, 1, 1);

	GtkWidget *menu_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_button_grid, menu_button_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_label_label, 1, 0, 1, 1);

	GtkWidget *menu_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_button_grid, menu_button_label_entry, 1, 1, 1, 1);

	GtkWidget *menu_button_path_to_image_label = create_label("Path to image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_path_to_image_label, 2, 0, 1, 1);

	GtkWidget *menu_button_path_to_image_entry = create_entry(NULL, "Chose image or lable", TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_button_grid, menu_button_path_to_image_entry, 2, 1, 1, 1);

	GtkWidget *menu_button_arrow_type_label = create_label("Arrow type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_arrow_type_label, 3, 0, 1, 1);

	GtkWidget *menu_button_arrow_type_combo_box = create_combo_box();

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_DOWN");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_UP");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_LEFT");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_RIGHT");

	add_to_grid(menu_button_grid, menu_button_arrow_type_combo_box, 3, 1, 1, 1);

	menu_buttonI *myMenu_button = malloc(sizeof(menu_buttonI));
	if(!myMenu_button) return;

	myMenu_button->menu_button_id_entry = menu_button_id_entry;
	myMenu_button->menu_button_label_entry = menu_button_label_entry;
	myMenu_button->menu_button_path_to_image_entry = menu_button_path_to_image_entry;
	myMenu_button->menu_button_arrow_type_combo_box = menu_button_arrow_type_combo_box;

	GtkWidget *menu_button_add_button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, G_CALLBACK(traitement_menu_button), myMenu_button);

	add_to_grid(menu_button_grid, menu_button_add_button, 4, 0, 2, 1);
	
	add_to_box(menu_button_main_box, menu_button_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(menu_button_grid_frame, menu_button_main_box, 14, 14, 14, 14);

	add_to_box(menu_button_box, menu_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, menu_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *menu_item_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *menu_item_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_item_label = create_label("Menu Item", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(menu_item_label_frame, menu_item_label, 7, 7, 14, 1);

	add_to_box(menu_item_box, menu_item_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_item_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_item_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *menu_item_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_item_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_id_label, 0, 0, 1, 1);

	GtkWidget *menu_item_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_item_grid, menu_item_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_item_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_label_label, 1, 0, 1, 1);

	GtkWidget *menu_item_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_item_grid, menu_item_label_entry, 1, 1, 1, 1);

	GtkWidget *menu_item_type_label = create_label("Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_type_label, 2, 0, 1, 1);

	GtkWidget *menu_item_type_combo_box = create_combo_box();

	add_to_combo_box(menu_item_type_combo_box, "normal");

	add_to_combo_box(menu_item_type_combo_box, "separator");

	add_to_combo_box(menu_item_type_combo_box, "check");

	add_to_combo_box(menu_item_type_combo_box, "radio");

	add_to_grid(menu_item_grid, menu_item_type_combo_box, 2, 1, 1, 1);

	GtkWidget *menu_item_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_callback_label, 3, 0, 1, 1);

	GtkWidget *menu_item_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_item_grid, menu_item_callback_entry, 3, 1, 1, 1);

	GtkWidget *menu_item_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_data_label, 4, 0, 1, 1);

	GtkWidget *menu_item_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_item_grid, menu_item_data_entry, 4, 1, 1, 1);

	menu_itemI *myMenu_item = malloc(sizeof(menu_itemI));
	if(!myMenu_item) return;

	myMenu_item->menu_item_id_entry = menu_item_id_entry;
    myMenu_item->menu_item_label_entry = menu_item_label_entry;
    myMenu_item->menu_item_type_combo_box = menu_item_type_combo_box;
    myMenu_item->menu_item_callback_entry = menu_item_callback_entry;
    myMenu_item->menu_item_data_entry = menu_item_data_entry;

	GtkWidget *menu_item_add_button = create_button(GTK_RELIEF_NORMAL, "Add ", FALSE, NULL, G_CALLBACK(traitement_menu_item), myMenu_item);

	add_to_grid(menu_item_grid, menu_item_add_button, 5, 0, 2, 1);

	add_to_box(menu_item_main_box, menu_item_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(menu_item_grid_frame, menu_item_main_box, 14, 14, 14, 14);

	add_to_box(menu_item_box, menu_item_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, menu_item_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *menu_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *menu_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_label = create_label("Menu", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(menu_label_frame, menu_label, 7, 7, 14, 1);

	add_to_box(menu_box, menu_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *menu_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_id_label, 0, 0, 1, 1);

	GtkWidget *menu_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_grid, menu_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_is_primary_label = create_label("Is Primary", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_is_primary_label, 1, 0, 1, 1);

	GtkWidget *menu_is_primary_combo_box = create_combo_box();

	add_to_combo_box(menu_is_primary_combo_box, "TRUE");

	add_to_combo_box(menu_is_primary_combo_box, "FALSE");

	add_to_grid(menu_grid, menu_is_primary_combo_box, 1, 1, 1, 1);

	GtkWidget *menu_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_label_label, 2, 0, 1, 1);

	GtkWidget *menu_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(menu_grid, menu_label_entry, 2, 1, 1, 1);

	menuI *mymenu = malloc(sizeof(menuI));
	if(!mymenu) return;

	mymenu->menu_id_entry = menu_id_entry;
    mymenu->menu_is_primary_combo_box = menu_is_primary_combo_box;
    mymenu->menu_label_entry = menu_label_entry;

	GtkWidget *menu_add_button = create_button(GTK_RELIEF_NORMAL, "Add ", FALSE, NULL, G_CALLBACK(traitement_menu), mymenu);

	add_to_grid(menu_grid, menu_add_button, 3, 0, 2, 1);

	add_to_box(menu_main_box, menu_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(menu_grid_frame, menu_main_box, 14, 14, 14, 14);

	add_to_box(menu_box, menu_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, menu_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *radio_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *radio_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *radio_button_label = create_label("Radio Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(radio_button_label_frame, radio_button_label, 7, 7, 14, 1);

	add_to_box(radio_button_box, radio_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *radio_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *radio_button_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *radio_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *radio_button_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_id_label, 0, 0, 1, 1);

	GtkWidget *radio_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

	add_to_grid(radio_button_grid, radio_button_id_entry, 0, 1, 1, 1);

	GtkWidget *radio_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_label_label, 1, 0, 1, 1);

	GtkWidget *radio_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(radio_button_grid, radio_button_label_entry, 1, 1, 1, 1);

	GtkWidget *radio_button_path_image_label = create_label("Path Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_path_image_label, 2, 0, 1, 1);

	GtkWidget *radio_button_path_image_entry = create_entry(NULL, "if you chose label let this NULL", TRUE, TRUE, 200, 0.5);

	add_to_grid(radio_button_grid, radio_button_path_image_entry, 2, 1, 1, 1);

	GtkWidget *radio_button_id_radio_group_member_label = create_label("Id Radio Group Member", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_id_radio_group_member_label, 3, 0, 1, 1);

	GtkWidget *radio_button_id_radio_group_member_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

	add_to_grid(radio_button_grid, radio_button_id_radio_group_member_entry, 3, 1, 1, 1);

	GtkWidget *radio_button_default_state_label = create_label("Default State", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_default_state_label, 4, 0, 1, 1);

	GtkWidget *radio_button_default_state_combo_box = create_combo_box();

	add_to_combo_box(radio_button_default_state_combo_box, "FALSE");

	add_to_combo_box(radio_button_default_state_combo_box, "TRUE");

	add_to_grid(radio_button_grid, radio_button_default_state_combo_box, 4, 1, 1, 1);

	radio_buttonI * myRadio_button = malloc(sizeof(radio_buttonI));
	if(!myRadio_button) return;

	myRadio_button->radio_button_id_entry = radio_button_id_entry;
    myRadio_button->radio_button_label_entry = radio_button_label_entry;
    myRadio_button->radio_button_path_image_entry = radio_button_path_image_entry;
    myRadio_button->radio_button_id_radio_group_member_entry = radio_button_id_radio_group_member_entry;
    myRadio_button->radio_button_default_state_combo_box = radio_button_default_state_combo_box;

	GtkWidget *radio_button_add_button = create_button(GTK_RELIEF_NORMAL, "Add", FALSE, NULL, G_CALLBACK(traitement_radio_button), myRadio_button);

	add_to_grid(radio_button_grid, radio_button_add_button, 5, 0, 2, 1);

	add_to_box(radio_button_main_box, radio_button_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_frame(radio_button_grid_frame, radio_button_main_box, 14, 14, 14, 14);

	add_to_box(radio_button_box, radio_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, radio_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_scrolled_window(scrolled_widgets_window, Widgets_box);

	add_to_stack(stack_catalog, scrolled_widgets_window, "Widgets");

	add_to_box(widgets_catalog_box, stack_catalog, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(second_space_box, widgets_catalog_box, START, TRUE, TRUE, 0, 7, 0, 7, 0);

	add_to_paned(build_space_paned, second_space_box, SECOND);

	add_to_paned(main_paned, build_space_paned, SECOND);

	add_to_box(app_box, main_paned, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(main_box, app_box, START, TRUE, TRUE, 0, 7, 0, 7, 7);

	GtkWidget *control_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *generate_button = create_button(GTK_RELIEF_NORMAL, "Generate", FALSE, NULL, G_CALLBACK(start_generate), NULL);

	add_to_box(control_box, generate_button, START, FALSE, FALSE, 0, 0, 0, 0, 7);

	drag_button = create_button(GTK_RELIEF_NORMAL, "Drag/Drop", FALSE, NULL, G_CALLBACK(cancel), NULL);

	add_to_box(control_box, drag_button, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(main_box, control_box, START, FALSE, FALSE, 0, 7, 7, 7, 7);

	add_to_container(window, main_box);

	AjouterButton(function);

	// Module 2
	// ----------------------------------------------------------------------------------------------------------------------
	addEvents("Test", Windows, 20, "#FF11FF",  NULL);


	



	// ----------------------------------------------------------------------------------------------------------------------

	show_widget(window);

    

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
