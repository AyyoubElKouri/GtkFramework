#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
#include "XML/xscEngine/widgets_structures.h"
#include "XML/xscEngine/widgets_tree.h"

GtkWidget *test_box = NULL;
GtkWidget *global_tree;
data_widget* global_widget_data_pointer = NULL;

static void traitementHeaderBar(GtkWidget *widget, gpointer data){
	headerBarI *myheaderBar = (headerBarI*)data;

	headerBarInfos *infos = malloc(sizeof(headerBarInfos));
	if(!infos) exit(EXIT_FAILURE);

	infos->title = get_text(myheaderBar->header_bar_informations_title_value);
	infos->icon_path = get_text(myheaderBar->header_bar_informations_icon_value);
	if(strcmp(infos->icon_path, "") == 0)
		infos->icon_path = NULL;
	infos->subtitle = get_text(myheaderBar->header_bar_informations_subtitle_value);
	if(strcmp(get_selecter_item(myheaderBar->header_bar_informations_settings_value),"TRUE") == 0)
		infos->settings = TRUE;
	else
		infos->settings = FALSE;

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);	

	widget_data->id_widget = get_text(myheaderBar->header_bar_id_value);
	widget_data->data = infos;
	widget_data->widget_name = "headerBar";

	global_widget_data_pointer = widget_data;
}

static void on_click_window(gpointer data){
	if(global_widget_data_pointer){
		if(strcmp(global_widget_data_pointer->widget_name, "headerBar") == 0){

			GtkWidget *headerBar = set_properties_header_bar((headerBarInfos *)global_widget_data_pointer->data);
			add_to_box(test_box, headerBar, START, FALSE, FALSE, 0, 0, 0, 0, 0);
			show_widget(headerBar);
		}
		add_to_tree(global_tree,  (char *)data, global_widget_data_pointer->id_widget, NULL, NULL, NULL, global_widget_data_pointer->data);
		global_widget_data_pointer = NULL;
	}
	else
	{
		GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
		GtkWidget *window_informations_grid = create_grid(7, 7, TRUE, FALSE);

		TreeNodeData *dataWidget = search_tree(global_tree, (char *)data);

	GtkWidget *window_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_id_label, 0, 0, 1, 1);

	GtkWidget *window_informations_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	set_text(window_informations_id_value, (char *)data);

	add_to_grid(window_informations_grid, window_informations_id_value, 0, 1, 1, 1);

	GtkWidget *window_informations_app_label = create_label("Window", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_app_label, 1, 0, 1, 1);

	GtkWidget *window_informations_app_value = create_entry("app", "Chose App for TOPLEVEL", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_app_value, 1, 1, 1, 1);

	GtkWidget *window_informations_type_label = create_label("Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_type_label, 2, 0, 1, 1);

	GtkWidget *window_informations_type_value = create_entry("GTK_WINDOW_TOPLEVEL", "Chose Type of the window", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_type_value, 2, 1, 1, 1);

	GtkWidget *window_informations_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_title_label, 3, 0, 1, 1);

	GtkWidget *window_informations_title_value = create_entry("title", "Chose Title for TOPLEVEL", TRUE, TRUE, 20, 0.5);

	set_text(window_informations_title_value, ((windowInfos *)(dataWidget->widget_data))->title);

	add_to_grid(window_informations_grid, window_informations_title_value, 3, 1, 1, 1);

	GtkWidget *window_informations_width_label = create_label("Width", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	
	add_to_grid(window_informations_grid, window_informations_width_label, 4, 0, 1, 1);
	
	GtkWidget *window_informations_width_value = create_spin_button(0, 1000, 10, 800, 0, FALSE, TRUE);
	
	set_value_spin_button(window_informations_width_value, ((windowInfos *)(dataWidget->widget_data))->width);

	add_to_grid(window_informations_grid, window_informations_width_value, 4, 1, 1, 1);

	GtkWidget *window_informations_height_label = create_label("Height", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_height_label, 5, 0, 1, 1);

	GtkWidget *window_informations_height_value = create_spin_button(0, 1000, 10, 600, 0, FALSE, TRUE);

	set_value_spin_button(window_informations_height_value, ((windowInfos *)(dataWidget->widget_data))->height);

	add_to_grid(window_informations_grid, window_informations_height_value, 5, 1, 1, 1);

	GtkWidget *window_informations_resizable_label = create_label("Resizable", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_resizable_label, 6, 0, 1, 1);

	GtkWidget *window_informations_resizable_value = create_combo_box();

	add_to_combo_box(window_informations_resizable_value, "TRUE");

	add_to_combo_box(window_informations_resizable_value, "FALSE");

	if(((windowInfos *)(dataWidget->widget_data))->resizable == TRUE){
		set_active_item(window_informations_resizable_value, 0);
	} else {
		set_active_item(window_informations_resizable_value, 1);
	}

	add_to_grid(window_informations_grid, window_informations_resizable_value, 6, 1, 1, 1);

	GtkWidget *window_informations_position_label = create_label("Position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_position_label, 7, 0, 1, 1);

	GtkWidget *window_informations_position_value = create_combo_box();

	add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_CENTER");

	add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_CENTER_ON_PARENT");

	add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_MOUSE");

	if(((windowInfos *)(dataWidget->widget_data))->position == GTK_WIN_POS_CENTER){
		set_active_item(window_informations_position_value, 0);
	} else if(((windowInfos *)(dataWidget->widget_data))->position == GTK_WIN_POS_CENTER_ON_PARENT){
		set_active_item(window_informations_position_value, 1);
	} else {
		set_active_item(window_informations_position_value, 2);
	}
	
	add_to_grid(window_informations_grid, window_informations_position_value, 7, 1, 1, 1);

	GtkWidget *window_informations_decorate_label = create_label("Decorate", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_decorate_label, 8, 0, 1, 1);
	
	GtkWidget *window_informations_decorate_value = create_combo_box();
	
	add_to_combo_box(window_informations_decorate_value, "TRUE");

	add_to_combo_box(window_informations_decorate_value, "FALSE");

	if(((windowInfos *)(dataWidget->widget_data))->decorate == TRUE){
		set_active_item(window_informations_decorate_value, 0);
	} else {
		set_active_item(window_informations_decorate_value, 1);
	}

	add_to_grid(window_informations_grid, window_informations_decorate_value, 8, 1, 1, 1);

	GtkWidget *window_informations_icon_label = create_label("Icon", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_icon_label, 9, 0, 1, 1);

	GtkWidget *window_informations_icon_value = create_entry(NULL, "icon path", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_icon_value, 9, 1, 1, 1);

	GtkWidget *window_informations_opacity_label = create_label("Opacity", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_opacity_label, 10, 0, 1, 1);

	GtkWidget *window_informations_opacity_value = create_spin_button(0, 1, 0.1, 1, 1, FALSE, TRUE);

	set_value_spin_button(window_informations_opacity_value, ((windowInfos *)(dataWidget->widget_data))->opacity);

	add_to_grid(window_informations_grid, window_informations_opacity_value, 10, 1, 1, 1);

	GtkWidget *window_informations_fullscreen_label = create_label("Fullscreen", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_fullscreen_label, 11, 0, 1, 1);

	GtkWidget *window_informations_fullscreen_value = create_combo_box();
	
	add_to_combo_box(window_informations_fullscreen_value, "TRUE");

	add_to_combo_box(window_informations_fullscreen_value, "FALSE");

	if(((windowInfos *)(dataWidget->widget_data))->fullscreen == TRUE){
		set_active_item(window_informations_fullscreen_value, 0);
	} else {
		set_active_item(window_informations_fullscreen_value, 1);
	}
	
	add_to_grid(window_informations_grid, window_informations_fullscreen_value, 11, 1, 1, 1);

	add_to_box(box, window_informations_grid, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *dialog = create_dialog("Window Information", NULL, GTK_DIALOG_MODAL, 300, 300, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, NULL, GTK_RESPONSE_CANCEL);
	gint reponse = run_dialog(dialog);
	if(reponse == GTK_RESPONSE_OK){

		windowInfos *infos = malloc(sizeof(windowInfos));
		if(!infos) exit(EXIT_FAILURE);

		if(get_text(window_informations_app_value)){
			GtkApplication *app = gtk_application_new("ici.id.ta", G_APPLICATION_DEFAULT_FLAGS);
			infos->app = app;
		}
		else{
			infos->app = NULL;
		}

		infos->title = get_text(window_informations_title_value);

		char *decorate = get_selecter_item(window_informations_decorate_value);

		if(!decorate){
			infos->decorate = TRUE;
		}
		else{
			if(strcmp(decorate, "TRUE") == 0)
				infos->decorate = TRUE;
			else
				infos->decorate = FALSE;
		}

		char *fullscreen = get_selecter_item(window_informations_fullscreen_value);

		if(!fullscreen){
			infos->fullscreen = TRUE;
		}
		else{
			if(strcmp(fullscreen, "TRUE") == 0)
				infos->fullscreen = TRUE;
			else
				infos->fullscreen = FALSE;
		}

		char *resizable = get_selecter_item(window_informations_resizable_value);

		if(!resizable){
			infos->resizable = TRUE;
		}
		else{
			if(strcmp(resizable, "TRUE") == 0)
				infos->resizable = TRUE;
			else
				infos->resizable = FALSE;
		}

		if(strcmp(get_text(window_informations_icon_value), "") != 0){
			GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(get_text(window_informations_icon_value), NULL);
			if(!pixbuf){
				perror("Failed to load icon\n");
			} else {
			GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 32, 32, GDK_INTERP_BILINEAR);
			infos->icon = scaled_pixbuf;
			g_object_unref(pixbuf);
			}
		}

		char *position = get_selecter_item(window_informations_position_value);
		if(strcmp(position, "GTK_WIN_POS_CENTER") == 0)
			infos->position = GTK_WIN_POS_CENTER;
		else if(strcmp(position, "GTK_WIN_POS_CENTER_ON_PARENT") == 0)
			infos->position = GTK_WIN_POS_CENTER_ON_PARENT;
		else
			infos->position = GTK_WIN_POS_MOUSE;


		infos->opacity = get_value_spin_button(window_informations_opacity_value);
		infos->width = get_value_spin_button(window_informations_width_value);
		infos->height = get_value_spin_button(window_informations_height_value);
		
		
		infos->type = GTK_WINDOW_TOPLEVEL; // TOUJOURS TOPLEVEL

		((windowInfos *)(dataWidget->widget_data))->app = infos->app;
		strcpy(((windowInfos *)(dataWidget->widget_data))->title,infos->title);
		((windowInfos *)(dataWidget->widget_data))->decorate = infos->decorate;
		((windowInfos *)(dataWidget->widget_data))->fullscreen = infos->fullscreen;
		((windowInfos *)(dataWidget->widget_data))->resizable = infos->resizable;
		((windowInfos *)(dataWidget->widget_data))->icon = infos->icon;
		((windowInfos *)(dataWidget->widget_data))->opacity = infos->opacity;
		((windowInfos *)(dataWidget->widget_data))->width = infos->width;
		((windowInfos *)(dataWidget->widget_data))->height = infos->height;
		((windowInfos *)(dataWidget->widget_data))->position = infos->position;
		
	}
	destroy_widget(dialog);
	}
}


static void traitementWindow(GtkWidget *widget, gpointer data) {
	windowInfos* infos = malloc(sizeof(windowInfos));
	if(!infos) exit(EXIT_FAILURE);

	windowI *mywindow = (windowI*)data;

	if(get_text(mywindow->window_informations_app_value)){
        GtkApplication *app = gtk_application_new("ici.id.ta", G_APPLICATION_DEFAULT_FLAGS);
        infos->app = app;
    }
    else{
        infos->app = NULL;
    }

	infos->title = get_text(mywindow->window_informations_title_value);

    char *decorate = get_selecter_item(mywindow->window_informations_decorate_value);
    
    if(!decorate){
        infos->decorate = TRUE;
    }
    else{
        if(strcmp(decorate, "TRUE") == 0)
            infos->decorate = TRUE;
        else
            infos->decorate = FALSE;
    }

    char *fullscreen = get_selecter_item(mywindow->window_informations_fullscreen_value);
	
    if(!fullscreen){
        infos->fullscreen = TRUE;
    }
    else{
		if(strcmp(fullscreen, "TRUE") == 0)
		infos->fullscreen = TRUE;
        else
		infos->fullscreen = FALSE;
    }
    
	
    infos->height = get_value_spin_button(mywindow->window_informations_height_value);
    infos->width = get_value_spin_button(mywindow->window_informations_width_value);

    char * icon = get_text(mywindow->window_informations_icon_value);

    if(icon){
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(icon, NULL);
        infos->icon = pixbuf;
    }
    else{
        infos->icon = NULL;
    }

    infos->opacity = get_value_spin_button(mywindow->window_informations_opacity_value);

    char *position = get_selecter_item(mywindow->window_informations_position_value);
	
    if(!position){
		infos->position = GTK_WIN_POS_CENTER;
    }
    else{
		if(strcmp(position, "GTK_WIN_POS_CENTER") == 0)
		infos->position = GTK_WIN_POS_CENTER;
        else if(strcmp(position, "GTK_WIN_POS_CENTER_ON_PARENT") == 0)
		infos->position = GTK_WIN_POS_CENTER_ON_PARENT;
        else
		infos->position = GTK_WIN_POS_MOUSE;
    }
	
	
    char *resizable = get_selecter_item(mywindow->window_informations_resizable_value);
	
    if(!resizable){
		infos->resizable = TRUE;
    }
    else{
        if(strcmp(resizable, "TRUE") == 0)
		infos->resizable = TRUE;
        else
            infos->resizable = FALSE;
    }

    if(get_text(mywindow->window_informations_type_value) == "GTK_WINDOW_TOPLEVEL"){
        infos->type = GTK_WINDOW_TOPLEVEL;
    }

	data_widget *widget_data = malloc(sizeof(data_widget));

	widget_data->id_widget = get_text(mywindow->window_informations_id_value);
	widget_data->data = infos;
	widget_data->widget_name = "window";

	GtkWidget *dialog;

	if(tree_empty(global_tree))
    	add_to_tree(global_tree, NULL, widget_data->id_widget, NULL, on_click_window, widget_data->id_widget, widget_data->data);
	else{
		dialog = create_dialog("Erreur", NULL, GTK_DIALOG_MODAL, 300, 300, 1, NULL, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL);
		run_dialog(dialog);
		destroy_widget(dialog);
	}
}

static void hello(GtkWidget *widget, gpointer data) {
	
	printf("La widget id est : %s\n", global_widget_data_pointer->id_widget);
	
	if(((windowInfos *)global_widget_data_pointer->data)->app)
	printf("L'application est app\n");
	else
		printf("L'application est non app\n");

	printf("Le titre est : %s\n", ((windowInfos *)global_widget_data_pointer->data)->title);

	if(((windowInfos *)global_widget_data_pointer->data)->decorate)
		printf("decorate TRUE \n");
	else
		printf("decorate FALSE\n");

	if(((windowInfos *)global_widget_data_pointer->data)->fullscreen)
		printf("fullscreen TRUE\n");
	else
		printf("fullscreen FALSE\n");

    printf("height : %d\n", ((windowInfos *)global_widget_data_pointer->data)->height);
    printf("width : %d\n", ((windowInfos *)global_widget_data_pointer->data)->width);
    printf("Opacity : %f\n", ((windowInfos *)global_widget_data_pointer->data)->opacity);

	if(((windowInfos *)global_widget_data_pointer->data)->icon)
		printf("icon chosie\n");
	else
		printf("icon non choisi\n");
	
	if(((windowInfos *)global_widget_data_pointer->data)->position == GTK_WIN_POS_CENTER)
		printf("c'est : GTK_WIN_POS_CENTER\n");
	else if(((windowInfos *)global_widget_data_pointer->data)->position == GTK_WIN_POS_CENTER_ON_PARENT)
		printf("c'est : GTK_WIN_POS_CENTER_ON_PARENT\n");
	else
		printf("c'est : GTK_WIN_POS_MOUSE\n");


	if(((windowInfos *)global_widget_data_pointer->data)->resizable == TRUE)
		printf("resizable is : TRUE\n");
	else
		printf("resizable is FALSE");

	if(((windowInfos *)global_widget_data_pointer->data)->type == GTK_WINDOW_TOPLEVEL)
		printf("c'est GTK_WINDOW_TOP_LEVEL\n");
	else
		printf("c'est autre Type\n");
	
}

static void activate(GtkApplication *app, gpointer data)
{
	global_tree = create_tree_view();
	GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 5000, 5000, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

	GtkWidget *Header_bar = create_header_bar("UIBuilder", "Build your UI Application", NULL, TRUE);

	add_header_bar_to_window(window, Header_bar);

	GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *app_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *main_paned = create_paned(GTK_ORIENTATION_HORIZONTAL, 240, TRUE);

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

	GtkWidget *build_space_paned = create_paned(GTK_ORIENTATION_HORIZONTAL, 625, TRUE);

	GtkWidget *first_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *contents_space_paned = create_paned(GTK_ORIENTATION_VERTICAL, 400, TRUE);

	GtkWidget *working_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *working_space_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);

	GtkWidget *working_space_label = create_label("Working Space", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_box(working_space_label_box, working_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);

	add_to_box(working_space_box, working_space_label_box, START, FALSE, FALSE, 0, 0, 0, 12, 7);

	GtkWidget *working_space_box_content = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *working_space_frame = create_frame(NULL, 0.5, 0.5);

	test_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	add_to_frame(working_space_frame, test_box, 5, 5, 5, 5);

	add_to_box(working_space_box_content, working_space_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(working_space_box, working_space_box_content, START, TRUE, TRUE, 0, 7, 7, 0, 0);

	add_to_paned(contents_space_paned, working_space_box, FIRST);

	GtkWidget *widgets_informations_space = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *widgets_informations_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);

	GtkWidget *widgets_informations_label = create_label("Widgets Informations", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_box(widgets_informations_label_box, widgets_informations_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);

	add_to_box(widgets_informations_space, widgets_informations_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);

	GtkWidget *widgets_informations_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *button_test4 = create_button(GTK_RELIEF_NORMAL, "This space is reserved for the Widgets Informations", FALSE, NULL, NULL, NULL);

	add_to_box(widgets_informations_box, button_test4, START, TRUE, TRUE, 0, 7, 0, 0, 0);

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

	GtkWidget *Windows_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 7);

	GtkWidget *window_case = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *window_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *window_label = create_label("Window", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);

	add_to_frame(window_label_frame, window_label, 5, 5, 0, 0);

	add_to_box(window_case, window_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *window_informations_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *window_informations_main_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *window_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *window_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_id_label, 0, 0, 1, 1);

	GtkWidget *window_informations_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_id_value, 0, 1, 1, 1);

	GtkWidget *window_informations_app_label = create_label("Window", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_app_label, 1, 0, 1, 1);

	GtkWidget *window_informations_app_value = create_entry("app", "Chose App for TOPLEVEL", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_app_value, 1, 1, 1, 1);

	GtkWidget *window_informations_type_label = create_label("Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_type_label, 2, 0, 1, 1);

	GtkWidget *window_informations_type_value = create_entry("GTK_WINDOW_TOPLEVEL", "Chose Type of the window", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_type_value, 2, 1, 1, 1);

	GtkWidget *window_informations_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_title_label, 3, 0, 1, 1);

	GtkWidget *window_informations_title_value = create_entry("title", "Chose Title for TOPLEVEL", TRUE, TRUE, 20, 0.5);

	add_to_grid(window_informations_grid, window_informations_title_value, 3, 1, 1, 1);

	GtkWidget *window_informations_width_label = create_label("Width", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_width_label, 4, 0, 1, 1);

	GtkWidget *window_informations_width_value = create_spin_button(0, 1000, 10, 800, 0, FALSE, TRUE);

	add_to_grid(window_informations_grid, window_informations_width_value, 4, 1, 1, 1);

	GtkWidget *window_informations_height_label = create_label("Height", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_height_label, 5, 0, 1, 1);

	GtkWidget *window_informations_height_value = create_spin_button(0, 1000, 10, 600, 0, FALSE, TRUE);

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

	add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_CENTER");

	add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_CENTER_ON_PARENT");

	add_to_combo_box(window_informations_position_value, "GTK_WIN_POS_MOUSE");
	
	add_to_grid(window_informations_grid, window_informations_position_value, 7, 1, 1, 1);

	GtkWidget *window_informations_decorate_label = create_label("Decorate", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_decorate_label, 8, 0, 1, 1);
	
	GtkWidget *window_informations_decorate_value = create_combo_box();
	
	add_to_combo_box(window_informations_decorate_value, "TRUE");

	add_to_combo_box(window_informations_decorate_value, "FALSE");

	add_to_grid(window_informations_grid, window_informations_decorate_value, 8, 1, 1, 1);

	GtkWidget *window_informations_icon_label = create_label("Icon", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(window_informations_grid, window_informations_icon_label, 9, 0, 1, 1);

	GtkWidget *window_informations_icon_value = create_entry(NULL, "icon path", TRUE, TRUE, 20, 0.5);

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
	
	add_to_grid(window_informations_grid, window_informations_fullscreen_value, 11, 1, 1, 1);
	
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

	GtkWidget *window_informations_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, G_CALLBACK(traitementWindow), mywindow);

	add_to_grid(window_informations_grid, window_informations_add_button, 12, 0, 2, 1);

	add_to_box(window_informations_main_box, window_informations_grid, START, TRUE, FALSE, 0, 21, 21, 0, 0);

	add_to_frame(window_informations_frame, window_informations_main_box, 0, 0, 0, 0);

	add_to_box(window_case, window_informations_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Windows_box, window_case, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *Header_bar_case = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *header_bar_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *header_bar_label = create_label("Header Bar", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(header_bar_label_frame, header_bar_label, 5, 5, 0, 0);

	add_to_box(Header_bar_case, header_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *header_bar_informations_main_box_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *header_bar_informations_main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

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

	GtkWidget *header_bar_informations_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, G_CALLBACK(traitementHeaderBar), myHeaderBar);

	add_to_grid(header_bar_informations_grid, header_bar_informations_add_button, 5, 0, 2, 1);

	add_to_box(header_bar_informations_main_box, header_bar_informations_grid, START, TRUE, FALSE, 0, 14, 0, 14, 0);

	add_to_frame(header_bar_informations_main_box_frame, header_bar_informations_main_box, 0, 18, 0, 0);

	add_to_box(Header_bar_case, header_bar_informations_main_box_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Windows_box, Header_bar_case, START, TRUE, TRUE, 0, 25, 0, 0, 0);

	GtkWidget *scrolled_window_case = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *scrolled_window_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *scrolled_window_label = create_label("scrolled window", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(scrolled_window_label_frame, scrolled_window_label, 5, 5, 0, 0);

	add_to_box(scrolled_window_case, scrolled_window_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *scrolled_window_informations_main_box_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *scrolled_window_informations_main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *scrolled_window_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *scrolled_window_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_label, 0, 0, 1, 1);

	GtkWidget *scrolled_window_informations_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

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

	GtkWidget *scrolled_window_informations_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_add_button, 3, 0, 2, 1);

	add_to_box(scrolled_window_informations_main_box, scrolled_window_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0);

	add_to_frame(scrolled_window_informations_main_box_frame, scrolled_window_informations_main_box, 0, 18, 14, 0);

	add_to_box(scrolled_window_case, scrolled_window_informations_main_box_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Windows_box, scrolled_window_case, START, TRUE, TRUE, 0, 25, 0, 0, 0);

	add_to_scrolled_window(scrolled_window_window, Windows_box);

	add_to_stack(stack_catalog, scrolled_window_window, "Windows");

	GtkWidget *scrolled_containers_window = create_scrolled_window(FALSE, TRUE);

	GtkWidget *Containers_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 7);

	GtkWidget *Box_case = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *Box_case_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Box_case_label = create_label("Box", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Box_case_label_frame, Box_case_label, 5, 5, 0, 0);

	add_to_box(Box_case, Box_case_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *Box_case_informations_main_box_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Box_case_informations_main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Box_case_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Box_case_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_id_label, 0, 0, 1, 1);

	GtkWidget *Box_case_informations_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(Box_case_informations_grid, Box_case_informations_id_entry, 0, 1, 1, 1);

	GtkWidget *Box_case_informations_orientation_label = create_label("Orientation", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_label, 1, 0, 1, 1);

	GtkWidget *Box_case_informations_orientation_value = create_combo_box();

	add_to_combo_box(Box_case_informations_orientation_value, "GTK_ORIENTATION_HORIZONTAL");

	add_to_combo_box(Box_case_informations_orientation_value, "GTK_ORIENTATION_VERTICAL");

	add_to_grid(Box_case_informations_grid, Box_case_informations_orientation_value, 1, 1, 1, 1);

	GtkWidget *Box_case_informations_align_label = create_label("Align", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_align_label, 2, 0, 1, 1);

	GtkWidget *Box_case_informations_align_value = create_combo_box();

	add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_START");

	add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_END");

	add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_CENTER");

	add_to_combo_box(Box_case_informations_align_value, "-1");

	add_to_grid(Box_case_informations_grid, Box_case_informations_align_value, 2, 1, 1, 1);

	GtkWidget *Box_case_informations_spacing_label = create_label("Spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_label, 3, 0, 1, 1);

	GtkWidget *Box_case_informations_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, FALSE);

	add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_value, 3, 1, 1, 1);

	GtkWidget *Box_case_informations_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Box_case_informations_grid, Box_case_informations_add, 4, 0, 2, 1);

	add_to_box(Box_case_informations_main_box, Box_case_informations_grid, START, TRUE, FALSE, 0, 14, 0, 0, 0);

	add_to_frame(Box_case_informations_main_box_frame, Box_case_informations_main_box, 5, 18, 14, 0);

	add_to_box(Box_case, Box_case_informations_main_box_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Box_case, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Fixed_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Fixed_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Fixed_label = create_label("Fixed", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Fixed_label_frame, Fixed_label, 5, 5, 0, 0);

	add_to_box(Fixed_box, Fixed_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Fixed_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Fixed_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Fixed_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Fixed_grid, Fixed_id_label, 0, 0, 1, 1);

	GtkWidget *Fixed_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(Fixed_grid, Fixed_id_entry, 0, 1, 1, 1);

	GtkWidget *Fixed_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Fixed_grid, Fixed_add, 1, 0, 2, 1);

	add_to_frame(Fixed_grid_frame, Fixed_grid, 14, 14, 14, 0);

	add_to_box(Fixed_box, Fixed_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Fixed_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Frame_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Frame_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Frame_label = create_label("Frame", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Frame_label_frame, Frame_label, 5, 5, 0, 0);

	add_to_box(Frame_box, Frame_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Frame_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Frame_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Frame_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_id_label, 0, 0, 1, 1);

	GtkWidget *Frame_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(Frame_grid, Frame_id_entry, 0, 1, 1, 1);

	GtkWidget *Frame_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_title_label, 1, 0, 1, 1);

	GtkWidget *Frame_title_value = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(Frame_grid, Frame_title_value, 1, 1, 1, 1);

	GtkWidget *Frame_horizontal_placement_label = create_label("Horizontal placement", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_horizontal_placement_label, 2, 0, 1, 1);

	GtkWidget *Frame_horizontal_placement_value = create_spin_button(0, 1, 0.5, 0.5, 1, FALSE, TRUE);

	add_to_grid(Frame_grid, Frame_horizontal_placement_value, 2, 1, 1, 1);

	GtkWidget *Frame_vertical_placement_label = create_label("Vertical placement", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_vertical_placement_label, 3, 0, 1, 1);

	GtkWidget *Frame_vertical_placement_value = create_spin_button(0, 1, 0.5, 0.5, 1, FALSE, TRUE);

	add_to_grid(Frame_grid, Frame_vertical_placement_value, 3, 1, 1, 1);

	GtkWidget *Frame_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Frame_grid, Frame_add, 4, 0, 2, 1);

	add_to_frame(Frame_grid_frame, Frame_grid, 14, 14, 14, 0);

	add_to_box(Frame_box, Frame_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Frame_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Grid_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Grid_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Grid_label = create_label("Grid", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Grid_label_frame, Grid_label, 5, 5, 0, 0);

	add_to_box(Grid_box, Grid_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Grid_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Grid_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Grid_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_id_label, 0, 0, 1, 1);

	GtkWidget *Grid_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

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

	GtkWidget *Grid_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Grid_grid, Grid_add, 5, 0, 2, 1);

	add_to_frame(Grid_grid_frame, Grid_grid, 14, 14, 14, 0);

	add_to_box(Grid_box, Grid_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Grid_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Paned_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Paned_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Paned_label = create_label("Paned", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Paned_label_frame, Paned_label, 7, 7, 14, 0);

	add_to_box(Paned_box, Paned_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Paned_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Paned_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Paned_id_label = create_label("ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_id_label, 0, 0, 1, 1);

	GtkWidget *Paned_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(Paned_grid, Paned_id_value, 0, 1, 1, 1);

	GtkWidget *Paned_orientation_label = create_label("Orientation", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_orientation_label, 1, 0, 1, 1);

	GtkWidget *Paned_orientation_value = create_combo_box();

	add_to_combo_box(Paned_orientation_value, "GTK_ORIENTATION_HORIZONTAL");

	add_to_combo_box(Paned_orientation_value, "GTK_ORIENTATION_VERTICAL");

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

	GtkWidget *Paned_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Paned_grid, Paned_add, 4, 0, 2, 1);

	add_to_frame(Paned_grid_frame, Paned_grid, 14, 14, 14, 0);

	add_to_box(Paned_box, Paned_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Paned_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Stack_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Stack_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Stack_label = create_label("Stack", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Stack_label_frame, Stack_label, 7, 7, 14, 0);

	add_to_box(Stack_box, Stack_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Stack_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Stack_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *stack_switcher_widget_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_switcher_widget_label, 0, 0, 1, 1);

	GtkWidget *stack_switcher_widget_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(Stack_grid, stack_switcher_widget_entry, 0, 1, 1, 1);

	GtkWidget *stack_transition_type_label = create_label("Transition Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_transition_type_label, 1, 0, 1, 1);

	GtkWidget *stack_transition_type_value_combo_box = create_combo_box();

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_CROSSFADE");

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_NONE");

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT");

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT");

	add_to_grid(Stack_grid, stack_transition_type_value_combo_box, 1, 1, 1, 1);

	GtkWidget *stack_duration_label = create_label("Duration", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_duration_label, 2, 0, 1, 1);

	GtkWidget *stack_duration_value_spin_button = create_spin_button(0, 1000, 100, 500, 0, FALSE, TRUE);

	add_to_grid(Stack_grid, stack_duration_value_spin_button, 2, 1, 1, 1);

	GtkWidget *stack_informations_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Stack_grid, stack_informations_add_button, 3, 0, 2, 1);

	add_to_frame(Stack_grid_frame, Stack_grid, 14, 14, 14, 14);

	add_to_box(Stack_box, Stack_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Stack_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	GtkWidget *Switcher_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *Switcher_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Switcher_label = create_label("Switcher", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Switcher_label_frame, Switcher_label, 7, 7, 14, 0);

	add_to_box(Switcher_box, Switcher_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *Switcher_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Switcher_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *switcher_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, switcher_id_label, 0, 0, 1, 1);

	GtkWidget *switcher_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

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

	GtkWidget *switcher_informations_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Switcher_grid, switcher_informations_add_button, 3, 0, 2, 1);

	add_to_frame(Switcher_grid_frame, Switcher_grid, 14, 14, 14, 14);

	add_to_box(Switcher_box, Switcher_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Containers_box, Switcher_box, START, TRUE, TRUE, 0, 14, 0, 0, 0);

	add_to_scrolled_window(scrolled_containers_window, Containers_box);

	add_to_stack(stack_catalog, scrolled_containers_window, "Containers");

	GtkWidget *scrolled_widgets_window = create_scrolled_window(FALSE, TRUE);

	GtkWidget *Widgets_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 7);

	GtkWidget *button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *button_label = create_label("Button", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(button_label_frame, button_label, 7, 7, 14, 0);

	add_to_box(button_box, button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_id_label, 0, 0, 1, 1);

	GtkWidget *button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(button_grid, button_id_entry, 0, 1, 1, 1);

	GtkWidget *button_relief_label = create_label("Relief", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_relief_label, 1, 0, 1, 1);

	GtkWidget *button_relief_combo_box = create_combo_box();

	add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NONE");

	add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NORMAL");

	add_to_grid(button_grid, button_relief_combo_box, 1, 1, 1, 1);

	GtkWidget *button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_label_label, 2, 0, 1, 1);

	GtkWidget *button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(button_grid, button_label_entry, 2, 1, 1, 1);

	GtkWidget *button_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_use_underline_label, 3, 0, 1, 1);

	GtkWidget *button_use_underline_combo_box = create_combo_box();

	add_to_combo_box(button_use_underline_combo_box, "TRUE");

	add_to_combo_box(button_use_underline_combo_box, "FALSE");

	add_to_grid(button_grid, button_use_underline_combo_box, 3, 1, 1, 1);

	GtkWidget *button_path_to_image_label = create_label("Path to Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_path_to_image_label, 4, 0, 1, 1);

	GtkWidget *button_path_to_image_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(button_grid, button_path_to_image_entry, 4, 1, 1, 1);

	GtkWidget *button_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_callback_label, 5, 0, 1, 1);

	GtkWidget *button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(button_grid, button_callback_entry, 5, 1, 1, 1);

	GtkWidget *button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_data_label, 6, 0, 1, 1);

	GtkWidget *button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(button_grid, button_data_entry, 6, 1, 1, 1);

	GtkWidget *button_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(button_grid, button_add, 7, 0, 2, 1);

	add_to_frame(button_grid_frame, button_grid, 14, 14, 14, 14);

	add_to_box(button_box, button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, button_box, START, FALSE, FALSE, 0, 7, 0, 0, 0);

	GtkWidget *check_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *check_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *check_button_label = create_label("Check Button", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(check_button_label_frame, check_button_label, 7, 7, 14, 14);

	add_to_box(check_button_box, check_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *check_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *check_button_grid = create_grid(7, 0, FALSE, FALSE);

	GtkWidget *check_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_id_label, 0, 0, 1, 1);

	GtkWidget *check_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(check_button_grid, check_button_id_entry, 0, 1, 1, 1);

	GtkWidget *check_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_label_label, 1, 0, 1, 1);

	GtkWidget *check_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

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

	GtkWidget *check_button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(check_button_grid, check_button_callback_entry, 4, 1, 1, 1);

	GtkWidget *check_button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_data_label, 5, 0, 1, 1);

	GtkWidget *check_button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(check_button_grid, check_button_data_entry, 5, 1, 1, 1);

	GtkWidget *check_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(check_button_grid, check_button_add_button, 6, 0, 2, 1);

	add_to_frame(check_button_grid_frame, check_button_grid, 14, 14, 14, 14);

	add_to_box(check_button_box, check_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, check_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *color_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *color_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *color_button_label_label = create_label("Color Button", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(color_button_label_frame, color_button_label_label, 7, 7, 14, 0);

	add_to_box(color_button_box, color_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *color_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *color_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *color_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_id_label, 0, 0, 1, 1);

	GtkWidget *color_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(color_button_grid, color_button_id_entry, 0, 1, 1, 1);

	GtkWidget *color_button_default_color_label = create_label("Default Color", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_default_color_label, 1, 0, 1, 1);

	GtkWidget *color_button_default_color_color_button = create_color_button("#FFFFFF", "coloring", TRUE);

	add_to_grid(color_button_grid, color_button_default_color_color_button, 1, 1, 1, 1);

	GtkWidget *color_button_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_title_label, 2, 0, 1, 1);

	GtkWidget *color_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(color_button_grid, color_button_label_entry, 2, 1, 1, 1);

	GtkWidget *color_button_use_alpha_label = create_label("Use Alpha", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_use_alpha_label, 3, 0, 1, 1);

	GtkWidget *color_button_use_alpha_combo_box = create_combo_box();

	add_to_combo_box(color_button_use_alpha_combo_box, "TRUE");

	add_to_combo_box(color_button_use_alpha_combo_box, "FALSE");

	add_to_grid(color_button_grid, color_button_use_alpha_combo_box, 3, 1, 1, 1);

	GtkWidget *color_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(color_button_grid, color_button_add_button, 4, 0, 2, 1);

	add_to_frame(color_button_grid_frame, color_button_grid, 14, 14, 14, 14);

	add_to_box(color_button_box, color_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, color_button_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *combo_box_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *combo_box_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *combo_box_label_label = create_label("Combo Box", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(combo_box_label_frame, combo_box_label_label, 7, 7, 14, 0);

	add_to_box(combo_box_box, combo_box_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *combo_box_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *combo_box_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *combo_box_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(combo_box_grid, combo_box_id_label, 0, 0, 1, 1);

	GtkWidget *combo_box_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(combo_box_grid, combo_box_id_entry, 0, 1, 1, 1);

	GtkWidget *combo_box_item1_label = create_label("Item 1", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(combo_box_grid, combo_box_item1_label, 1, 0, 1, 1);

	GtkWidget *combo_box_item1_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(combo_box_grid, combo_box_item1_entry, 1, 1, 1, 1);

	GtkWidget *combo_box_item2_label = create_label("Item 2", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(combo_box_grid, combo_box_item2_label, 2, 0, 1, 1);

	GtkWidget *combo_box_item2_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(combo_box_grid, combo_box_item2_entry, 2, 1, 1, 1);

	GtkWidget *combo_box_item3_label = create_label("Item 3", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(combo_box_grid, combo_box_item3_label, 3, 0, 1, 1);

	GtkWidget *combo_box_item3_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(combo_box_grid, combo_box_item3_entry, 3, 1, 1, 1);

	GtkWidget *combo_box_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(combo_box_grid, combo_box_add_button, 4, 0, 2, 1);

	add_to_frame(combo_box_grid_frame, combo_box_grid, 14, 14, 14, 14);

	add_to_box(combo_box_box, combo_box_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, combo_box_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *entry_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *entry_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *entry_label_label = create_label("Entry", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(entry_label_frame, entry_label_label, 7, 7, 14, 0);

	add_to_box(entry_box, entry_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *entry_box_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *entry_box_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *entry_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_id_label, 0, 0, 1, 1);

	GtkWidget *entry_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(entry_box_grid, entry_id_entry, 0, 1, 1, 1);

	GtkWidget *entry_default_text_label = create_label("Default Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_default_text_label, 1, 0, 1, 1);

	GtkWidget *entry_default_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(entry_box_grid, entry_default_text_entry, 1, 1, 1, 1);

	GtkWidget *entry_indicator_text_label = create_label("Indicator Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_indicator_text_label, 2, 0, 1, 1);

	GtkWidget *entry_indicator_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

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

	GtkWidget *entry_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(entry_box_grid, entry_add_button, 7, 0, 2, 1);

	add_to_frame(entry_box_grid_frame, entry_box_grid, 14, 14, 14, 14);

	add_to_box(entry_box, entry_box_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, entry_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *font_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_START, 0);

	GtkWidget *font_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *font_button_label = create_label("Font Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(font_button_label_frame, font_button_label, 7, 7, 14, 14);

	add_to_box(font_button_box, font_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *font_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *font_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *font_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_id_label, 0, 0, 1, 1);

	GtkWidget *font_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(font_button_grid, font_button_id_entry, 0, 1, 1, 1);

	GtkWidget *font_button_default_font_name_label = create_label("Default Font Name", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_default_font_name_label, 1, 0, 1, 1);

	GtkWidget *font_button_default_font_name_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(font_button_grid, font_button_default_font_name_entry, 1, 1, 1, 1);

	GtkWidget *font_button_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_title_label, 2, 0, 1, 1);

	GtkWidget *font_button_title_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(font_button_grid, font_button_title_entry, 2, 1, 1, 1);

	GtkWidget *font_button_show_size_label = create_label("Show Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_show_size_label, 3, 0, 1, 1);

	GtkWidget *font_button_show_size_combo_box = create_combo_box();

	add_to_combo_box(font_button_show_size_combo_box, "TRUE");

	add_to_combo_box(font_button_show_size_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_show_size_combo_box, 3, 1, 1, 1);

	GtkWidget *font_button_use_size_label = create_label("Use Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_use_size_label, 4, 0, 1, 1);

	GtkWidget *font_button_use_size_combo_box = create_combo_box();

	add_to_combo_box(font_button_use_size_combo_box, "TRUE");

	add_to_combo_box(font_button_use_size_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_use_size_combo_box, 4, 1, 1, 1);

	GtkWidget *font_button_use_font_label = create_label("Use Font", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_use_font_label, 5, 0, 1, 1);

	GtkWidget *font_button_use_font_combo_box = create_combo_box();

	add_to_combo_box(font_button_use_font_combo_box, "TRUE");

	add_to_combo_box(font_button_use_font_combo_box, "FALSE");

	add_to_grid(font_button_grid, font_button_use_font_combo_box, 5, 1, 1, 1);

	GtkWidget *font_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(font_button_grid, font_button_add_button, 6, 0, 2, 1);

	add_to_frame(font_button_grid_frame, font_button_grid, 14, 14, 14, 14);

	add_to_box(font_button_box, font_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, font_button_box, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *image_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *image_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *image_label = create_label("Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(image_label_frame, image_label, 7, 7, 14, 14);

	add_to_box(image_box, image_label_frame, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *image_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *image_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *image_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(image_grid, image_id_label, 0, 0, 1, 1);

	GtkWidget *image_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(image_grid, image_id_entry, 0, 1, 1, 1);

	GtkWidget *image_path_label = create_label("Path", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(image_grid, image_path_label, 1, 0, 1, 1);

	GtkWidget *image_path_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(image_grid, image_path_entry, 1, 1, 1, 1);

	GtkWidget *image_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(image_grid, image_add_button, 2, 0, 2, 1);

	add_to_frame(image_grid_frame, image_grid, 14, 14, 14, 14);

	add_to_box(image_box, image_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, image_box, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *label_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *label_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(label_label_frame, label_label, 7, 7, 14, 14);

	add_to_box(label_box, label_label_frame, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *label_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *label_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *label_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_id_label, 0, 0, 1, 1);

	GtkWidget *label_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(label_grid, label_id_entry, 0, 1, 1, 1);

	GtkWidget *label_text_label = create_label("Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_text_label, 1, 0, 1, 1);

	GtkWidget *label_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

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

	add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_CENTER");

	add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_LEFT");

	add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_RIGHT");

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

	add_to_combo_box(label_pango_weight_combo_box, "PANGO_WEIGHT_NORMAL");

	add_to_combo_box(label_pango_weight_combo_box, "PANGO_WEIGHT_BOLD");

	add_to_grid(label_grid, label_pango_weight_combo_box, 8, 1, 1, 1);

	GtkWidget *label_pango_style_label = create_label("Pango Style", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_pango_style_label, 9, 0, 1, 1);

	GtkWidget *label_pango_style_combo_box = create_combo_box();

	add_to_combo_box(label_pango_style_combo_box, "PANGO_STYLE_NORMAL");

	add_to_combo_box(label_pango_style_combo_box, "PANGO_STYLE_ITALIC");

	add_to_grid(label_grid, label_pango_style_combo_box, 9, 1, 1, 1);

	GtkWidget *label_wrap_label = create_label("Wrap", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_wrap_label, 10, 0, 1, 1);

	GtkWidget *label_wrap_combo_box = create_combo_box();

	add_to_combo_box(label_wrap_combo_box, "TRUE");

	add_to_combo_box(label_wrap_combo_box, "FALSE");

	add_to_grid(label_grid, label_wrap_combo_box, 10, 1, 1, 1);

	GtkWidget *label_button_add = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(label_grid, label_button_add, 11, 0, 2, 1);

	add_to_frame(label_grid_frame, label_grid, 14, 14, 14, 14);

	add_to_box(label_box, label_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, label_box, START, TRUE, TRUE, 0, 7, 0, 0, 0);

	GtkWidget *level_bar_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *level_bar_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *level_bar_label = create_label("Level Bar", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(level_bar_label_frame, level_bar_label, 7, 7, 14, 0);

	add_to_box(level_bar_box, level_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *level_bar_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *level_bar_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *level_bar_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_id_label, 0, 0, 1, 1);

	GtkWidget *level_bar_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

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

	add_to_combo_box(level_bar_mode_combo_box, "GTK_LEVEL_BAR_MODE_CONTINUOUS");

	add_to_combo_box(level_bar_mode_combo_box, "GTK_LEVEL_BAR_MODE_DISCRETE");

	add_to_grid(level_bar_grid, level_bar_mode_combo_box, 4, 1, 1, 1);

	GtkWidget *level_bar_reversed_label = create_label("Reversed", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_reversed_label, 5, 0, 1, 1);

	GtkWidget *level_bar_reversed_combo_box = create_combo_box();

	add_to_combo_box(level_bar_reversed_combo_box, "FALSE");

	add_to_combo_box(level_bar_reversed_combo_box, "TRUE");

	add_to_grid(level_bar_grid, level_bar_reversed_combo_box, 5, 1, 1, 1);

	GtkWidget *level_bar_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(level_bar_grid, level_bar_add_button, 6, 0, 2, 1);

	add_to_frame(level_bar_grid_frame, level_bar_grid, 14, 14, 14, 14);

	add_to_box(level_bar_box, level_bar_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, level_bar_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *Link_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *Link_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Link_button_label = create_label("Link Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(Link_button_label_frame, Link_button_label, 7, 7, 14, 1);

	add_to_box(Link_button_box, Link_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *Link_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *Link_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Link_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_id_label, 0, 0, 1, 1);

	GtkWidget *Link_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(Link_button_grid, Link_button_id_entry, 0, 1, 1, 1);

	GtkWidget *Link_button_url_label = create_label("URL", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_url_label, 1, 0, 1, 1);

	GtkWidget *Link_button_url_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(Link_button_grid, Link_button_url_entry, 1, 1, 1, 1);

	GtkWidget *Link_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_label_label, 2, 0, 1, 1);

	GtkWidget *Link_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(Link_button_grid, Link_button_label_entry, 2, 1, 1, 1);

	GtkWidget *Link_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(Link_button_grid, Link_button_add_button, 3, 0, 2, 1);

	add_to_frame(Link_button_grid_frame, Link_button_grid, 14, 14, 14, 14);

	add_to_box(Link_button_box, Link_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, Link_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_button_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *menu_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_button_label = create_label("Menu Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(menu_button_label_frame, menu_button_label, 7, 7, 14, 1);

	add_to_box(menu_button_box, menu_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_id_label, 0, 0, 1, 1);

	GtkWidget *menu_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_button_grid, menu_button_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_label_label, 1, 0, 1, 1);

	GtkWidget *menu_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_button_grid, menu_button_label_entry, 1, 1, 1, 1);

	GtkWidget *menu_button_path_to_image_label = create_label("Path to image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_path_to_image_label, 2, 0, 1, 1);

	GtkWidget *menu_button_path_to_image_entry = create_entry(NULL, "Chose image or lable", TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_button_grid, menu_button_path_to_image_entry, 2, 1, 1, 1);

	GtkWidget *menu_button_arrow_type_label = create_label("Arrow type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_arrow_type_label, 3, 0, 1, 1);

	GtkWidget *menu_button_arrow_type_combo_box = create_combo_box();

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_DOWN");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_UP");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_LEFT");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_RIGHT");

	add_to_grid(menu_button_grid, menu_button_arrow_type_combo_box, 3, 1, 1, 1);

	GtkWidget *menu_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                               ", FALSE, NULL, NULL, NULL);

	add_to_grid(menu_button_grid, menu_button_add_button, 4, 0, 2, 1);

	add_to_frame(menu_button_grid_frame, menu_button_grid, 14, 14, 14, 14);

	add_to_box(menu_button_box, menu_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, menu_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_item_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *menu_item_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_item_label = create_label("Menu Item", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(menu_item_label_frame, menu_item_label, 7, 7, 14, 1);

	add_to_box(menu_item_box, menu_item_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_item_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_item_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_item_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_id_label, 0, 0, 1, 1);

	GtkWidget *menu_item_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_item_grid, menu_item_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_item_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_label_label, 1, 0, 1, 1);

	GtkWidget *menu_item_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

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

	GtkWidget *menu_item_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_item_grid, menu_item_callback_entry, 3, 1, 1, 1);

	GtkWidget *menu_item_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_data_label, 4, 0, 1, 1);

	GtkWidget *menu_item_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_item_grid, menu_item_data_entry, 4, 1, 1, 1);

	GtkWidget *menu_item_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                              ", FALSE, NULL, NULL, NULL);

	add_to_grid(menu_item_grid, menu_item_add_button, 5, 0, 2, 1);

	add_to_frame(menu_item_grid_frame, menu_item_grid, 14, 14, 14, 14);

	add_to_box(menu_item_box, menu_item_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, menu_item_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *menu_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_label = create_label("Menu", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(menu_label_frame, menu_label, 7, 7, 14, 1);

	add_to_box(menu_box, menu_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *menu_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_id_label, 0, 0, 1, 1);

	GtkWidget *menu_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_grid, menu_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_is_primary_label = create_label("Is Primary", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_is_primary_label, 1, 0, 1, 1);

	GtkWidget *menu_is_primary_combo_box = create_combo_box();

	add_to_combo_box(menu_is_primary_combo_box, "TRUE");

	add_to_combo_box(menu_is_primary_combo_box, "FALSE");

	add_to_grid(menu_grid, menu_is_primary_combo_box, 1, 1, 1, 1);

	GtkWidget *menu_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_label_label, 2, 0, 1, 1);

	GtkWidget *menu_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(menu_grid, menu_label_entry, 2, 1, 1, 1);

	GtkWidget *menu_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                              ", FALSE, NULL, NULL, NULL);

	add_to_grid(menu_grid, menu_add_button, 3, 0, 2, 1);

	add_to_frame(menu_grid_frame, menu_grid, 14, 14, 14, 14);

	add_to_box(menu_box, menu_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, menu_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *progress_bar_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *progress_bar_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *progress_bar_label = create_label("Progress Bar", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(progress_bar_label_frame, progress_bar_label, 7, 7, 14, 1);

	add_to_box(progress_bar_box, progress_bar_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *progress_bar_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *progress_bar_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *progress_bar_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(progress_bar_grid, progress_bar_id_label, 0, 0, 1, 1);

	GtkWidget *progress_bar_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(progress_bar_grid, progress_bar_id_entry, 0, 1, 1, 1);

	GtkWidget *progress_bar_text_label = create_label("Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(progress_bar_grid, progress_bar_text_label, 1, 0, 1, 1);

	GtkWidget *progress_bar_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(progress_bar_grid, progress_bar_text_entry, 1, 1, 1, 1);

	GtkWidget *progress_bar_fraction_label = create_label("Fraction", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(progress_bar_grid, progress_bar_fraction_label, 2, 0, 1, 1);

	GtkWidget *progress_bar_fraction_spin_button = create_spin_button(0, 1, 0.1, 0.0, 1, FALSE, FALSE);

	add_to_grid(progress_bar_grid, progress_bar_fraction_spin_button, 2, 1, 1, 1);

	GtkWidget *level_bar_show_text_label = create_label("Show Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(progress_bar_grid, level_bar_show_text_label, 3, 0, 1, 1);

	GtkWidget *level_bar_show_text_combo_box = create_combo_box();

	add_to_combo_box(level_bar_show_text_combo_box, "TRUE");

	add_to_combo_box(level_bar_show_text_combo_box, "FALSE");

	add_to_grid(progress_bar_grid, level_bar_show_text_combo_box, 3, 1, 1, 1);

	GtkWidget *progress_bar_pulse_label = create_label("Pulse", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(progress_bar_grid, progress_bar_pulse_label, 4, 0, 1, 1);

	GtkWidget *progress_bar_pulse_combo_box = create_combo_box();

	add_to_combo_box(progress_bar_pulse_combo_box, "TRUE");

	add_to_combo_box(progress_bar_pulse_combo_box, "FALSE");

	add_to_grid(progress_bar_grid, progress_bar_pulse_combo_box, 4, 1, 1, 1);

	GtkWidget *progress_bar_inverted_label = create_label("Inverted", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(progress_bar_grid, progress_bar_inverted_label, 5, 0, 1, 1);

	GtkWidget *progress_bar_inverted_combo_box = create_combo_box();

	add_to_combo_box(progress_bar_inverted_combo_box, "TRUE");

	add_to_combo_box(progress_bar_inverted_combo_box, "FALSE");

	add_to_grid(progress_bar_grid, progress_bar_inverted_combo_box, 5, 1, 1, 1);

	GtkWidget *progress_bar_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(progress_bar_grid, progress_bar_add_button, 6, 0, 2, 1);

	add_to_frame(progress_bar_grid_frame, progress_bar_grid, 14, 14, 14, 14);

	add_to_box(progress_bar_box, progress_bar_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, progress_bar_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *radio_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *radio_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *radio_button_label = create_label("Radio Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(radio_button_label_frame, radio_button_label, 7, 7, 14, 1);

	add_to_box(radio_button_box, radio_button_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *radio_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *radio_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *radio_button_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_id_label, 0, 0, 1, 1);

	GtkWidget *radio_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

	add_to_grid(radio_button_grid, radio_button_id_entry, 0, 1, 1, 1);

	GtkWidget *radio_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_label_label, 1, 0, 1, 1);

	GtkWidget *radio_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(radio_button_grid, radio_button_label_entry, 1, 1, 1, 1);

	GtkWidget *radio_button_path_image_label = create_label("Path Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_path_image_label, 2, 0, 1, 1);

	GtkWidget *radio_button_path_image_entry = create_entry(NULL, "if you chose label let this NULL", TRUE, TRUE, 20, 0.5);

	add_to_grid(radio_button_grid, radio_button_path_image_entry, 2, 1, 1, 1);

	GtkWidget *radio_button_id_radio_group_member_label = create_label("Id Radio Group Member", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_id_radio_group_member_label, 3, 0, 1, 1);

	GtkWidget *radio_button_id_radio_group_member_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(radio_button_grid, radio_button_id_radio_group_member_entry, 3, 1, 1, 1);

	GtkWidget *radio_button_default_state_label = create_label("Default State", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_default_state_label, 4, 0, 1, 1);

	GtkWidget *radio_button_default_state_combo_box = create_combo_box();

	add_to_combo_box(radio_button_default_state_combo_box, "FALSE");

	add_to_combo_box(radio_button_default_state_combo_box, "TRUE");

	add_to_grid(radio_button_grid, radio_button_default_state_combo_box, 4, 1, 1, 1);

	GtkWidget *radio_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(radio_button_grid, radio_button_add_button, 5, 0, 2, 1);

	add_to_frame(radio_button_grid_frame, radio_button_grid, 14, 14, 14, 14);

	add_to_box(radio_button_box, radio_button_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, radio_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *scale_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *scale_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *scale_label = create_label("Scale", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(scale_label_frame, scale_label, 7, 7, 14, 1);

	add_to_box(scale_box, scale_label_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *scale_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *scale_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *scale_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scale_grid, scale_id_label, 0, 0, 1, 1);

	GtkWidget *scale_id_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(scale_grid, scale_id_entry, 0, 1, 1, 1);

	GtkWidget *scale_orientation_label = create_label("Orientation", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scale_grid, scale_orientation_label, 1, 0, 1, 1);

	GtkWidget *scale_oreintation_combo_box = create_combo_box();

	GtkWidget *combo_box_item1 = create_combo_box();

	add_to_combo_box(scale_oreintation_combo_box, "GTK_ORIENTATION_HORIZONTAL");

	GtkWidget *combo_box_item2 = create_combo_box();

	add_to_combo_box(scale_oreintation_combo_box, "GTK_ORIENTATION_VERTICAL");

	add_to_grid(scale_grid, scale_oreintation_combo_box, 1, 1, 1, 1);

	GtkWidget *scale_min_value_label = create_label("Min Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scale_grid, scale_min_value_label, 2, 0, 1, 1);

	GtkWidget *scale_min_value_spin_button = create_spin_button(0, 100, 10, 0, 0, FALSE, FALSE);

	add_to_grid(scale_grid, scale_min_value_spin_button, 2, 1, 1, 1);

	GtkWidget *scale_max_value_label = create_label("Max Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scale_grid, scale_max_value_label, 3, 0, 1, 1);

	GtkWidget *scale_max_value_spin_button = create_spin_button(0, 100, 10, 100, 0, FALSE, FALSE);

	add_to_grid(scale_grid, scale_max_value_spin_button, 3, 1, 1, 1);

	GtkWidget *scale_step_label = create_label("Step", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scale_grid, scale_step_label, 4, 0, 1, 1);

	GtkWidget *scale_step_spin_button = create_spin_button(0, 50, 2, 10, 0, FALSE, FALSE);

	add_to_grid(scale_grid, scale_step_spin_button, 4, 1, 1, 1);

	GtkWidget *scale_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(scale_grid, scale_add_button, 5, 0, 2, 1);

	add_to_frame(scale_grid_frame, scale_grid, 14, 14, 14, 14);

	add_to_box(scale_box, scale_grid_frame, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, scale_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *separator_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *separator_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *separator_label = create_label("Separator", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(separator_label_frame, separator_label, 7, 7, 14, 1);

	add_to_box(separator_box, separator_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *separator_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *separator_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *separator_widget_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(separator_grid, separator_widget_id_label, 0, 0, 1, 1);

	GtkWidget *separator_widget_id_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(separator_grid, separator_widget_id_entry, 0, 1, 1, 1);

	GtkWidget *separator_orientation_label = create_label("Orientation", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(separator_grid, separator_orientation_label, 1, 0, 1, 1);

	GtkWidget *separator_orientation_combobox = create_combo_box();

	add_to_combo_box(separator_orientation_combobox, "GTK_ORIENTATION_HORIZONTAL");

	add_to_combo_box(separator_orientation_combobox, "GTK_ORIENTATION_VERTICAL");

	add_to_grid(separator_grid, separator_orientation_combobox, 1, 1, 1, 1);

	GtkWidget *separator_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(separator_grid, separator_add_button, 2, 0, 2, 1);

	add_to_frame(separator_grid_frame, separator_grid, 14, 14, 14, 14);

	add_to_box(separator_box, separator_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, separator_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *spin_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *spin_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *spin_button_label = create_label("Spin Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(spin_button_label_frame, spin_button_label, 7, 7, 14, 1);

	add_to_box(spin_button_box, spin_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *spin_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *spin_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *spin_button_widget_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_widget_id_label, 0, 0, 1, 1);

	GtkWidget *spin_button_widget_id_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(spin_button_grid, spin_button_widget_id_entry, 0, 1, 1, 1);

	GtkWidget *spin_button_min_value_label = create_label("Min Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_min_value_label, 1, 0, 1, 1);

	GtkWidget *spin_button_min_value_spin_button = create_spin_button(0, 100, 10, 0, 0, FALSE, FALSE);

	add_to_grid(spin_button_grid, spin_button_min_value_spin_button, 1, 1, 1, 1);

	GtkWidget *spin_button_max_value_label = create_label("Max Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_max_value_label, 2, 0, 1, 1);

	GtkWidget *spin_button_max_value_spin_button = create_spin_button(0, 100, 10, 100, 0, FALSE, FALSE);

	add_to_grid(spin_button_grid, spin_button_max_value_spin_button, 2, 1, 1, 1);

	GtkWidget *spin_button_Default_Value_label = create_label("Default Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_Default_Value_label, 3, 0, 1, 1);

	GtkWidget *spin_button_Default_Value_spin_button = create_spin_button(0, 100, 10, 50, 0, FALSE, FALSE);

	add_to_grid(spin_button_grid, spin_button_Default_Value_spin_button, 3, 1, 1, 1);

	GtkWidget *spin_button_digits_label = create_label("Digits", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_digits_label, 4, 0, 1, 1);

	GtkWidget *spin_button_digits_spin_button = create_spin_button(0, 5, 1, 0, 0, FALSE, FALSE);

	add_to_grid(spin_button_grid, spin_button_digits_spin_button, 4, 1, 1, 1);

	GtkWidget *spin_button_wrap_label = create_label("Wrap", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_wrap_label, 5, 0, 1, 1);

	GtkWidget *spin_button_wrap_combo_box = create_combo_box();

	add_to_combo_box(spin_button_wrap_combo_box, "TRUE");

	add_to_combo_box(spin_button_wrap_combo_box, "FALSE");

	add_to_grid(spin_button_grid, spin_button_wrap_combo_box, 5, 1, 1, 1);

	GtkWidget *spin_button_numeric_label = create_label("Numeric", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spin_button_grid, spin_button_numeric_label, 6, 0, 1, 1);

	GtkWidget *spin_button_numeric_combo_box = create_combo_box();

	add_to_combo_box(spin_button_numeric_combo_box, "TRUE");

	add_to_combo_box(spin_button_numeric_combo_box, "FALSE");

	add_to_grid(spin_button_grid, spin_button_numeric_combo_box, 6, 1, 1, 1);

	GtkWidget *spin_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(spin_button_grid, spin_button_add_button, 7, 0, 2, 1);

	add_to_frame(spin_button_grid_frame, spin_button_grid, 14, 14, 14, 14);

	add_to_box(spin_button_box, spin_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, spin_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *spinner_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *spinner_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *spinner_label = create_label("Spinner", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(spinner_label_frame, spinner_label, 7, 7, 14, 1);

	add_to_box(spinner_box, spinner_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *spinner_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *spinner_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *spinner_widget_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spinner_grid, spinner_widget_id_label, 0, 0, 1, 1);

	GtkWidget *spinner_widget_id_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(spinner_grid, spinner_widget_id_entry, 0, 1, 1, 1);

	GtkWidget *spinner_active_label = create_label("Active", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(spinner_grid, spinner_active_label, 1, 0, 1, 1);

	GtkWidget *spinner_active_combo_box = create_combo_box();

	add_to_combo_box(spinner_active_combo_box, "TRUE");

	add_to_combo_box(spinner_active_combo_box, "FALSE");

	add_to_grid(spinner_grid, spinner_active_combo_box, 1, 1, 1, 1);

	GtkWidget *spinner_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(spinner_grid, spinner_add_button, 2, 0, 2, 1);

	add_to_frame(spinner_grid_frame, spinner_grid, 14, 14, 14, 14);

	add_to_box(spinner_box, spinner_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, spinner_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *switch_button_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *switch_button_label_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *switch_button_label = create_label("Switch Button", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_frame(switch_button_label_frame, switch_button_label, 7, 7, 14, 1);

	add_to_box(switch_button_box, switch_button_label_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *switch_button_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *switch_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *switch_button_widget_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(switch_button_grid, switch_button_widget_id_label, 0, 0, 1, 1);

	GtkWidget *switch_button_widget_id_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(switch_button_grid, switch_button_widget_id_entry, 0, 1, 1, 1);

	GtkWidget *switch_button_default_state_label = create_label("Default State", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(switch_button_grid, switch_button_default_state_label, 1, 0, 1, 1);

	GtkWidget *switch_button_default_state_combo_box = create_combo_box();

	add_to_combo_box(switch_button_default_state_combo_box, "TRUE");

	add_to_combo_box(switch_button_default_state_combo_box, "FALSE");

	add_to_grid(switch_button_grid, switch_button_default_state_combo_box, 1, 1, 1, 1);

	GtkWidget *switch_button_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(switch_button_grid, switch_button_callback_label, 2, 0, 1, 1);

	GtkWidget *switch_button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(switch_button_grid, switch_button_callback_entry, 2, 1, 1, 1);

	GtkWidget *switch_button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(switch_button_grid, switch_button_data_label, 3, 0, 1, 1);

	GtkWidget *switch_button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

	add_to_grid(switch_button_grid, switch_button_data_entry, 3, 1, 1, 1);

	GtkWidget *switch_button_add_button = create_button(GTK_RELIEF_NORMAL, "                                                               Add                                                             ", FALSE, NULL, NULL, NULL);

	add_to_grid(switch_button_grid, switch_button_add_button, 4, 0, 2, 1);

	add_to_frame(switch_button_grid_frame, switch_button_grid, 14, 14, 14, 14);

	add_to_box(switch_button_box, switch_button_grid_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(Widgets_box, switch_button_box, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_scrolled_window(scrolled_widgets_window, Widgets_box);

	add_to_stack(stack_catalog, scrolled_widgets_window, "Widgets");

	add_to_box(widgets_catalog_box, stack_catalog, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(second_space_box, widgets_catalog_box, START, TRUE, TRUE, 0, 7, 0, 7, 0);

	add_to_paned(build_space_paned, second_space_box, SECOND);

	add_to_paned(main_paned, build_space_paned, SECOND);

	add_to_box(app_box, main_paned, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(main_box, app_box, START, TRUE, TRUE, 0, 7, 0, 7, 7);

	GtkWidget *control_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

	GtkWidget *generate_button = create_button(GTK_RELIEF_NORMAL, "Generate", FALSE, NULL, NULL, NULL);

	add_to_box(control_box, generate_button, START, FALSE, FALSE, 0, 0, 0, 0, 7);

	GtkWidget *drag_button = create_button(GTK_RELIEF_NORMAL, "Drag", FALSE, NULL, NULL, NULL);

	add_to_box(control_box, drag_button, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(main_box, control_box, START, FALSE, FALSE, 0, 7, 7, 7, 7);

	add_to_container(window, main_box);

	show_widget(window);

    


}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
