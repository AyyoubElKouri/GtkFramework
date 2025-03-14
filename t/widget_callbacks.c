/*****************************************************************************************************************************
 * 
 * @file widget_callbacks.c
 * @brief the implementation of the functions in widget_callbacks.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 06/03/2025
 * @version 1.0 (last update 06/03/2025)
 * 
 ****************************************************************************************************************************/

#include "widget_callbacks.h"

GtkWidget *test_box = NULL;
GtkWidget *global_tree;
data_widget* global_widget_data_pointer = NULL;


void on_click_window(gpointer data){
	if(global_widget_data_pointer){
		GtkWidget *obj;

		const char *widget_name = global_widget_data_pointer->widget_name;

		for (const WidgetHandler *h = widget_handlers; h->name; h++) {
			if (strcmp(widget_name, h->name) == 0) {
				obj = h->handler(global_widget_data_pointer->data);
				break;
			}
		}
		
		add_to_box(test_box, obj, START, (strcmp(widget_name, "header_bar") == 0) ? FALSE : TRUE, (strcmp(widget_name, "header_bar") == 0) ? FALSE : TRUE, 0, 0, 0, 0, 0);
		show_widget(obj);	

		char *closing_tag = malloc(100 * sizeof(char));
		if(!closing_tag) return;

		if(strcmp(global_widget_data_pointer->widget_name, "header_bar") == 0){
			sprintf(closing_tag, "</header_bar add_header_bar_to_window(%s, %s)>", (char *)data, global_widget_data_pointer->id_widget);
		} else {
			sprintf(closing_tag, "</%s add_to_container(%s, %s)>", global_widget_data_pointer->widget_name, (char *)data, global_widget_data_pointer->id_widget);
		}
		
		add_to_tree(global_tree,  (char *)data, global_widget_data_pointer->id_widget, obj, on_click_box, global_widget_data_pointer->id_widget, global_widget_data_pointer->data, closing_tag, global_widget_data_pointer->widget_name);
		global_widget_data_pointer = NULL;
	} else {

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

		GtkWidget *dialog = create_dialog("Window Information", NULL, GTK_DIALOG_MODAL, 300, 300, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_DELETE_EVENT);
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
			
		} else if (reponse == GTK_RESPONSE_DELETE_EVENT){

		}
	destroy_widget(dialog);
	}
}


void traitementWindow(GtkWidget *widget, gpointer data) {
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

	if(tree_empty(global_tree)){
		char *closing_tag = malloc(100 * sizeof(char));
		if(!closing_tag) return;

		sprintf(closing_tag, "</window show_widget(%s)>", widget_data->id_widget);
    	add_to_tree(global_tree, NULL, widget_data->id_widget, NULL, on_click_window, widget_data->id_widget, widget_data->data, closing_tag, widget_data->widget_name);
	}
	else{
		dialog = create_dialog("Erreur", NULL, GTK_DIALOG_MODAL, 300, 300, 1, NULL, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL);
		run_dialog(dialog);
		destroy_widget(dialog);
	}
}

void on_click_box(gpointer data){

	char *parent_id = get_selected_node_id(GTK_TREE_VIEW(global_tree));
	GtkWidget *obj;
	
	if(global_widget_data_pointer){
		const char *widget_name = global_widget_data_pointer->widget_name;
		for (const WidgetHandler *h = widget_handlers; h->name; h++) {
			if (strcmp(widget_name, h->name) == 0) {
				obj = h->handler(global_widget_data_pointer->data);
				break;
			}
		}
		// Closing Tag;
		char *closing_tag = NULL;
		TreeNodeData *parent_data = search_tree(global_tree, parent_id);
		if(strcmp(parent_data->widget_name, "box") == 0){
			closing_tag = box_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "header_bar") == 0){
			closing_tag = header_bar_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "fixed") == 0){
			closing_tag = fixed_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "frame") == 0){
			closing_tag = frame_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "grid") == 0){
			closing_tag = grid_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "paned") == 0){
			closing_tag = paned_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "stack") == 0){
			closing_tag = stack_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "scrolled_window")== 0){
			closing_tag = scrolled_window_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "button")== 0){
			closing_tag = button_container_properties(parent_id, obj);
		} else if(strcmp(parent_data->widget_name, "check_button") == 0){
			closing_tag = check_button_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "color_button") == 0){
			closing_tag = color_button_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "combo_box") == 0){
			closing_tag = combo_box_container_properties(parent_id, obj);
		} else if(strcmp(parent_data->widget_name, "switcher")) {
			closing_tag = switcher_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "entry") == 0){
			closing_tag = entry_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "font_button") == 0){
			closing_tag = entry_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "image") == 0){
			closing_tag = image_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "label") == 0){
			closing_tag = label_container_properties(parent_id, obj);
		} else if (strcmp(parent_data->widget_name, "level_bar") == 0){
			closing_tag = level_bar_container_properties(parent_id, obj);
		}

		add_to_tree(global_tree, parent_id, global_widget_data_pointer->id_widget, obj, on_click_box, global_widget_data_pointer->id_widget, global_widget_data_pointer->data, closing_tag, global_widget_data_pointer->widget_name);
		
		show_widget(obj);	
		global_widget_data_pointer = NULL;
	}
	else {
		TreeNodeData *widget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));
		if(strcmp(widget->widget_name, "box") == 0){
			box_widget_properties();
		} else if (strcmp(widget->widget_name, "header_bar") == 0){
			header_bar_widget_properties();
		} else if (strcmp(widget->widget_name, "fixed") == 0){
			fixed_widget_properties();
		} else if (strcmp(widget->widget_name, "frame") == 0){
			frame_widget_properties();
		} else if (strcmp(widget->widget_name, "grid") == 0){
			grid_widget_properties();
		} else if (strcmp(widget->widget_name, "paned") == 0){
			paned_widget_properties();
		} else if (strcmp(widget->widget_name, "stack") == 0){
			stack_widget_properties();
		} else if (strcmp(widget->widget_name, "scrolled_window") == 0){
			scrolled_window_widget_properties();
		} else if (strcmp(widget->widget_name, "button") == 0){
			button_widget_properties();
		} else if(strcmp(widget->widget_name, "check_button") == 0){
			check_button_widget_properties();
		} else if(strcmp(widget->widget_name, "color_button") == 0){
			color_button_widget_properties();
		} else if (strcmp(widget->widget_name, "combo_box") == 0){
			combo_box_widget_properties();
		} else if(strcmp(widget->widget_name, "switcher") == 0) {
			switcher_widget_properties();
		} else if (strcmp(widget->widget_name, "entry") == 0){
			entry_widget_properties();
		} else if (strcmp(widget->widget_name, "font_button") == 0){
			font_button_widget_properties();
		} else if (strcmp(widget->widget_name, "image") == 0){
			image_widget_properties();
		} else if (strcmp(widget->widget_name, "label") == 0){
			label_widget_properties();
		} else if (strcmp(widget->widget_name, "level_bar") == 0){
			level_bar_widget_properties();
		}
	}
}

void traitementBox(GtkWidget *widget, gpointer data){

	boxI *mybox = (boxI*)data;

	boxInfos *infos = malloc(sizeof(boxInfos));
	if(!infos) exit(EXIT_FAILURE);

	char *orientation = get_selecter_item(mybox->Box_case_informations_orientation_value);
	if(!orientation){
		infos->orientation = GTK_ORIENTATION_VERTICAL;
	}
	else{
		if(strcmp(orientation, "GTK_ORIENTATION_VERTICAL") == 0)
			infos->orientation = GTK_ORIENTATION_VERTICAL;
		else
			infos->orientation = GTK_ORIENTATION_HORIZONTAL;
	}
	
	char *align = get_selecter_item(mybox->Box_case_informations_align_value);
	if(!align){
		infos->align = GTK_ALIGN_CENTER;
	}
	else{
		if(strcmp(align, "GTK_ALIGN_CENTER") == 0)
			infos->align = GTK_ALIGN_CENTER;
		else if(strcmp(align, "GTK_ALIGN_START") == 0)
			infos->align = GTK_ALIGN_START;
		else if(strcmp(align, "GTK_ALIGN_END") == 0)
			infos->align = GTK_ALIGN_END;
		else
			infos->align = -1;
	}

	infos->spacing = get_value_spin_button(mybox->Box_case_informations_spacing_value);

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(mybox->Box_case_informations_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "box";

	global_widget_data_pointer = widget_data;
}


void traitementHeaderBar(GtkWidget *widget, gpointer data){
	headerBarI *myheaderBar = (headerBarI*)data;

	headerBarInfos *infos = malloc(sizeof(headerBarInfos));
	if(!infos) exit(EXIT_FAILURE);

	infos->title = get_text(myheaderBar->header_bar_informations_title_value);
	if(strcmp(infos->title, "") == 0){
		infos->title = "Default Title";
	}

	infos->icon_path = get_text(myheaderBar->header_bar_informations_icon_value);
	if(strcmp(infos->icon_path, "") == 0)
		infos->icon_path = NULL;

	infos->subtitle = get_text(myheaderBar->header_bar_informations_subtitle_value);
	if(strcmp(infos->subtitle, "") == 0){
		infos->subtitle = "Default Subtitle";
	}
	char *settings = get_selecter_item(myheaderBar->header_bar_informations_settings_value);
	if(!settings)
		infos->settings = TRUE;
	else if ((strcmp(settings, "TRUE") == 0))
		infos->settings = TRUE;
	else 
		infos->settings = FALSE;	

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);	

	widget_data->id_widget = get_text(myheaderBar->header_bar_id_value);
	widget_data->data = infos;
	widget_data->widget_name = "header_bar";

	global_widget_data_pointer = widget_data;
}

void traitement_fixed(GtkWidget *widget, gpointer data){
	fixedI *myfixed = (fixedI*)data;

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myfixed->Fixed_id_entry);
	widget_data->data = NULL;
	widget_data->widget_name = "fixed";

	global_widget_data_pointer = widget_data;
}

void traitement_frame(GtkWidget *widget, gpointer data){
	frameI *myframe = (frameI *)data;
	frameInfos *frameInformations = malloc(sizeof(frameInfos));
	if(!frameInformations) return;

	frameInformations->title = get_text(myframe->Frame_title_value);
	frameInformations->vertical_placement = get_value_spin_button(myframe->Frame_vertical_placement_value);
	frameInformations->horizontal_placement = get_value_spin_button(myframe->Frame_horizontal_placement_value);
	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);	

	widget_data->id_widget = get_text(myframe->Frame_id_entry);
	widget_data->data = frameInformations;
	widget_data->widget_name = "frame";

	global_widget_data_pointer = widget_data;
}

void traitement_grid(GtkWidget *widget, gpointer data){
	gridI *mygrid = (gridI*)data;

	gridInfos *infos = malloc(sizeof(gridInfos));
	if(!infos) exit(EXIT_FAILURE);

	infos->rows_spacing = get_value_spin_button(mygrid->Grid_rows_spacing_value);
	infos->columns_spacing = get_value_spin_button(mygrid->Grid_columns_spacing_value);
	char *rows_homogeneous = get_selecter_item(mygrid->Grid_rows_homogeneous_value);
	if(!rows_homogeneous){
		infos->rows_homogeneous = TRUE;
	}
	else{
		if(strcmp(rows_homogeneous, "TRUE") == 0)
			infos->rows_homogeneous = TRUE;
		else
			infos->rows_homogeneous = FALSE;
	}

	char *columns_homogeneous = get_selecter_item(mygrid->Grid_columns_homogeneous_value);
	if(!columns_homogeneous){
		infos->columns_homogeneous = TRUE;
	}
	else{
		if(strcmp(columns_homogeneous, "TRUE") == 0)
			infos->columns_homogeneous = TRUE;
		else
			infos->columns_homogeneous = FALSE;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(mygrid->Grid_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "grid";

	global_widget_data_pointer = widget_data;
}

void traitement_paned(GtkWidget *widget, gpointer data){
	panedI *mypaned = (panedI *)data;

	panedInfos *infos = malloc(sizeof(panedInfos));
	if(!infos) return;

	infos->default_position = get_value_spin_button(mypaned->Paned_default_position_value);
	char *orientation = get_selecter_item(mypaned->Paned_orientation_value);
	char *show_handle = get_selecter_item(mypaned->Paned_show_handle_combo_box);

	if(!orientation){
		infos->orientation = GTK_ORIENTATION_HORIZONTAL;
	} else if (strcmp(orientation, "GTK_ORIENTATION_HORIZONTAL") == 0){
		infos->orientation = GTK_ORIENTATION_HORIZONTAL;
	} else {
		infos->orientation = GTK_ORIENTATION_VERTICAL;
	}

	if(!show_handle){
		infos->show_handle = TRUE;
	} else if (strcmp(show_handle, "TRUE") == 0){
		infos->show_handle = TRUE;
	} else {
		infos->show_handle = FALSE;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(mypaned->Paned_id_value);
	widget_data->data = infos;
	widget_data->widget_name = "paned";

	global_widget_data_pointer = widget_data;	
}

void traitement_stack(GtkWidget *widget, gpointer data){
	stackI *mystack = (stackI *)data;
	stackInfos *infos = malloc(sizeof(stackInfos));
	if(!infos) return;

	infos->id_switcher = get_text(mystack->stack_switcher_widget_id);;
	
	TreeNodeData *switcher = search_tree(global_tree, infos->id_switcher);
	infos->switcher = switcher->widget;

	char *transmition = get_selecter_item(mystack->stack_transition_type_value_combo_box);

	if(strcmp(transmition, "GTK_STACK_TRANSITION_TYPE_CROSSFADE") == 0){
		infos->transition_type = GTK_STACK_TRANSITION_TYPE_CROSSFADE;
	} else if (strcmp(transmition, "GTK_STACK_TRANSITION_TYPE_NONE") == 0){
		infos->transition_type = GTK_STACK_TRANSITION_TYPE_NONE;
	} else if (strcmp(transmition, "GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT")){
		infos->transition_type = GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT;
	} else {
		infos->transition_type = GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT;
	}

	infos->transition_duration = get_value_spin_button(mystack->stack_duration_value_spin_button);

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(mystack->stack_widget_id_value);
	widget_data->data = infos;
	widget_data->widget_name = "stack";

	global_widget_data_pointer = widget_data;	
}

void traitement_switcher(GtkWidget *widget, gpointer data){
	switcherI *myswitcher = (switcherI *)data;
	switcherInfos *infos = malloc(sizeof(switcherInfos));
	if(!infos) return;

	infos->spacing = get_value_spin_button(myswitcher->switcher_spacing_value_spin_button);
	char *same_size = get_selecter_item(myswitcher->same_size_value_combo_box);

	if(strcmp(same_size, "TRUE") == 0){
		infos->buttons_same_size = TRUE;
	} else {
		infos->buttons_same_size = FALSE;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myswitcher->switcher_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "switcher";

	global_widget_data_pointer = widget_data;	
}

void traitement_scrolled_window(GtkWidget *widget, gpointer data){
	scrolled_windowI *myScrolled_window = (scrolled_windowI *)data;
	scrolledWindowInfos *infos = malloc(sizeof(scrolledWindowInfos));
	if(!infos) return;

	infos->horizontal = (strcmp(get_selecter_item(myScrolled_window->scrolled_window_informations_horizontal_value), "TRUE") == 0) ? TRUE : FALSE;
	infos->vertical = (strcmp(get_selecter_item(myScrolled_window->scrolled_window_informations_vertical_value), "TRUE") == 0) ? TRUE : FALSE;

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myScrolled_window->scrolled_window_informations_id_value);
	widget_data->data = infos;
	widget_data->widget_name = "scrolled_window";

	global_widget_data_pointer = widget_data;		
}

void traitement_button(GtkWidget *widget, gpointer data){
	buttonI *mybutton = (buttonI *)data;
	buttonInfos *infos = malloc(sizeof(buttonInfos));
	if(!infos) return;

	infos->label = get_text(mybutton->button_label_entry);
	if(strcmp(infos->label, "") == 0){
		infos->label = NULL;
	}

	infos->path_to_image = get_text(mybutton->button_path_to_image_entry);
	if(strcmp(infos->path_to_image, "") == 0){
		infos->path_to_image = NULL;
	}

	infos->callback_name = get_text(mybutton->button_callback_entry);
	if(strcmp(infos->callback_name, "") == 0){
		infos->callback_name = NULL;
	}

	infos->data_name = get_text(mybutton->button_data_entry);
	if(strcmp(infos->data_name, "") == 0){
		infos->data_name = NULL;
	}

	infos->callback = NULL;
	infos->data = NULL;

	char *relief = get_selecter_item(mybutton->button_relief_combo_box);

	if(!relief){
		infos->relief = GTK_RELIEF_NORMAL;
	} else if (strcmp(relief, "GTK_RELIEF_NORMAL") == 0){
		infos->relief = GTK_RELIEF_NORMAL;
	} else {
		infos->relief = GTK_RELIEF_NONE;
	}

	char *use = get_selecter_item(mybutton->button_use_underline_combo_box);
	if(!use){
		infos->use_underline = TRUE;
	} else if (strcmp(use, "TRUE") == 0){
		infos->use_underline = TRUE;
	} else {
		infos->use_underline = FALSE;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(mybutton->button_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "button";

	global_widget_data_pointer = widget_data;	
}

void traitement_check_button(GtkWidget *widget, gpointer data){
	check_buttonI *myCheck_button = (check_buttonI *)data;
	checkButtonInfos *infos = malloc(sizeof(checkButtonInfos));
	if(!infos) return;

	char *chaine = get_text(myCheck_button->check_button_label_entry);
	if(strcmp(chaine, "") == 0){
		infos->label = NULL;
	} else {
		infos->label = chaine;
	}

	chaine = get_selecter_item(myCheck_button->check_button_active_combo_box);

	if(!chaine){
		infos->active = TRUE;
	} else if(strcmp(chaine, "TRUE") == 0){
		infos->active = TRUE;
	} else
		infos->active = FALSE;

	chaine = get_selecter_item(myCheck_button->check_button_use_underline_combo_box);

	if(!chaine){
		infos->use_underline = TRUE;
	} else if(strcmp(chaine, "TRUE") == 0){
		infos->use_underline = TRUE;
	} else
		infos->use_underline = FALSE;

	chaine = get_text(myCheck_button->check_button_callback_entry);

	if(strcmp(chaine, "") == 0){
		infos->callback_name = NULL;
	} else {
		infos->callback_name = chaine;
	}

	chaine = get_text(myCheck_button->check_button_data_entry);

	if(strcmp(chaine, "") == 0){
		infos->data_name = NULL;
	} else {
		infos->data_name = chaine;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	infos->callback = NULL;
	infos->data = NULL;

	widget_data->id_widget = get_text(myCheck_button->check_button_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "check_button";

	global_widget_data_pointer = widget_data;
}

void traitement_color_button(GtkWidget *widget, gpointer data){
	color_buttonI *myColor_button = (color_buttonI *)data;
	colorButtonInfos *infos = malloc(sizeof(colorButtonInfos));
	if(!infos) return;

	char *chaine = get_text(myColor_button->color_button_label_entry);
	if(strcmp(chaine, "") == 0){
		infos->title = NULL;
	} else {
		infos->title = chaine;
	}

	chaine = get_color(myColor_button->color_button_default_color_color_button);
	if(!chaine){
		infos->default_color = NULL;
	}else {
		infos->default_color = chaine;
	}

	chaine = get_selecter_item(myColor_button->color_button_use_alpha_combo_box);
	if(!chaine){
		infos->use_alpha = TRUE;
	} else if (strcmp(chaine, "TRUE") == 0){
		infos->use_alpha = TRUE;
	} else 
		infos->use_alpha = FALSE;

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myColor_button->color_button_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "color_button";

	global_widget_data_pointer = widget_data;
}

void traitement_combo_box(GtkWidget *widget, gpointer data){
	combo_boxI *myCombo_box = (combo_boxI *)data;
	
	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myCombo_box->combo_box_id_entry);
	widget_data->data = NULL;
	widget_data->widget_name = "combo_box";

	global_widget_data_pointer = widget_data;
}

void traitement_entry(GtkWidget *widget, gpointer data){
	entryI *myentry = (entryI *)data;
	entryInfos *infos = malloc(sizeof(entryI));
	if(!infos) return;

	char *chaine = get_text(myentry->entry_default_text_entry);
	if(strcmp(chaine, "") == 0){
		infos->default_text = NULL;
	} else {
		infos->default_text = chaine;
	}

	chaine = get_text(myentry->entry_indicator_text_entry);
	if(strcmp(chaine, "") == 0){
		infos->indicator_text = NULL;
	} else {
		infos->indicator_text = chaine;
	}

	chaine = get_selecter_item(myentry->entry_editable_combo_box);
	if(!chaine){
		infos->editable = TRUE;
	} else if (strcmp(chaine, "TRUE") == 0){
		infos->editable = TRUE;
	} else {
		infos->editable = FALSE;
	}

	chaine = get_selecter_item(myentry->entry_visibility_combo_box);
	if(!chaine){
		infos->visible = TRUE;
	} else if(strcmp(chaine, "TRUE") == 0){
		infos->visible = TRUE;
	} else {
		infos->visible = FALSE;
	}

	infos->alignment = get_value_spin_button(myentry->entry_alignment_spin_button);
	infos->max_length = get_value_spin_button(myentry->entry_max_length_spin_button);

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myentry->entry_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "entry";

	global_widget_data_pointer = widget_data;
}

void traitement_font_button(GtkWidget *widget, gpointer data){
	font_buttonI *myFont_button = (font_buttonI *)data;
	fontButtonInfos *infos = malloc(sizeof(fontButtonInfos));
	if(!infos) return;

	char *chaine = get_text(myFont_button->font_button_title_entry);
	
	if(strcmp(chaine, "") == 0){
		infos->title = NULL;
	} else {
		infos->title = chaine;
	}

	chaine = get_text(myFont_button->font_button_default_font_name_entry);

	if(strcmp(chaine, "") == 0){
		infos->default_font_name = "consolas";
	} else {
		infos->default_font_name = chaine;
	}

	chaine = get_selecter_item(myFont_button->font_button_use_font_combo_box);

	if(!chaine){
		infos->use_font = TRUE;
	} else if(strcmp(chaine, "TRUE") == 0){
		infos->use_font = TRUE;
	} else {
		infos->use_font = FALSE;
	}

	chaine = get_selecter_item(myFont_button->font_button_use_size_combo_box);

	if(!chaine){
		infos->use_size = TRUE;
	} else if(strcmp(chaine, "TRUE") == 0){
		infos->use_size = TRUE;
	} else {
		infos->use_size = FALSE;
	}

	chaine = get_selecter_item(myFont_button->font_button_show_size_combo_box);
	if(!chaine){
		infos->show_size = TRUE;
	} else if(strcmp(chaine, "TRUE") == 0){
		infos->show_size = TRUE;
	} else {
		infos->show_size = FALSE;
	}


	chaine = get_selecter_item(myFont_button->font_button_show_style_combo_box);

	if(!chaine){
		infos->show_style = TRUE;
	} else if (strcmp(chaine, "TRUE") == 0){
		infos->show_style = TRUE;
	} else {
		infos->show_style = FALSE;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myFont_button->font_button_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "font_button";

	global_widget_data_pointer = widget_data;
}

void traitement_image(GtkWidget *widget, gpointer data){
	imageI *myimage = (imageI *)data;
	imageInfos *infos = malloc(sizeof(imageInfos));
	if(!infos) return;

	char *chaine = get_text(myimage->image_path_entry);
	if(strcmp(chaine, "")== 0){
		infos->path = NULL;
	} else {
		infos->path = chaine;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myimage->image_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "image";

	global_widget_data_pointer = widget_data;
}

void traitement_label(GtkWidget *widget, gpointer data){

	labelI *mylabel = (labelI *)data;

	labelInfos *infos = malloc(sizeof(labelInfos));
	if(!infos) return;

	infos->color = get_color(mylabel->label_color_color_button);
	infos->background = get_color(mylabel->label_background_color_button);
	
	char *chaine = get_selecter_item(mylabel->label_justify_combo_box);

	if(!chaine){
		infos->justify = GTK_JUSTIFY_CENTER;
	} else if (strcmp(chaine, "GTK_JUSTIFY_CENTER") == 0){
		infos->justify = GTK_JUSTIFY_CENTER;
	} else if (strcmp(chaine, "GTK_JUSTIFY_LEFT") == 0){
		infos->justify = GTK_JUSTIFY_LEFT;
	} else {
		infos->justify = GTK_JUSTIFY_RIGHT;
	}

	chaine = get_selecter_item(mylabel->label_pango_style_combo_box);

	if(!chaine){
		infos->style = PANGO_STYLE_NORMAL;
	} else if (strcmp(chaine, "PANGO_STYLE_NORMAL") == 0){
		infos->style = PANGO_STYLE_NORMAL;
	} else {
		infos->style = 	PANGO_STYLE_ITALIC;
	}

	chaine = get_selecter_item(mylabel->label_pango_weight_combo_box);

	if(!chaine){
		infos->weight = PANGO_WEIGHT_NORMAL;
	} else if (strcmp(chaine, "PANGO_WEIGHT_NORMAL") == 0){
		infos->weight = PANGO_WEIGHT_NORMAL;
	} else {
		infos->weight = PANGO_WEIGHT_BOLD;
	}

	chaine = get_selecter_item(mylabel->label_use_underline_combo_box);

	if(!chaine){
		infos->underline = FALSE;
	} else if (strcmp(chaine, "TRUE") == 0){
		infos->underline = TRUE;
	} else {
		infos->underline = FALSE;
	}

	chaine = get_selecter_item(mylabel->label_wrap_combo_box);

	if(!chaine){
		infos->wrap = FALSE;
	} else if (strcmp(chaine, "TRUE")){
		infos->wrap = TRUE;
	} else {
		infos->wrap = TRUE;
	}

	infos->size = get_value_spin_button(mylabel->label_size_spin_button);
	
	chaine = get_text(mylabel->label_text_entry);
	
	if(!chaine){
		infos->text = NULL;
	} else {
		infos->text = chaine;
	}

	infos->font = get_font(mylabel->label_font_font_button);

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(mylabel->label_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "label";

	global_widget_data_pointer = widget_data;
}

void traitement_level_bar(GtkWidget *widget, gpointer data){
	level_barI *myLevel_bar = (level_barI *)data;
	levelBarInfos *infos = malloc(sizeof(levelBarInfos));
	if(!infos) return;

	infos->default_value = get_value_spin_button(myLevel_bar->level_bar_default_value_spin_button);
	infos->min_value = get_value_spin_button(myLevel_bar->level_bar_min_value_spin_button);
	infos->max_value = get_value_spin_button(myLevel_bar->level_bar_max_value_spin_button);

	char *chaine = get_selecter_item(myLevel_bar->level_bar_mode_combo_box);
	
	if(!chaine){
		infos->mode = GTK_LEVEL_BAR_MODE_CONTINUOUS;
	} else if (strcmp(chaine, "GTK_LEVEL_BAR_MODE_CONTINUOUS") == 0){
		infos->mode = GTK_LEVEL_BAR_MODE_CONTINUOUS;
	} else {
		infos->mode = GTK_LEVEL_BAR_MODE_DISCRETE;
	}

	chaine = get_selecter_item(myLevel_bar->level_bar_reversed_combo_box);
	if(!chaine){
		infos->inverted = FALSE;
	} else if (strcmp(chaine, "TRUE") == 0){
		infos->inverted = TRUE;
	} else {
		infos->inverted = FALSE;
	}

	data_widget *widget_data = malloc(sizeof(data_widget));
	if(!widget_data) exit(EXIT_FAILURE);

	widget_data->id_widget = get_text(myLevel_bar->level_bar_id_entry);
	widget_data->data = infos;
	widget_data->widget_name = "level_bar";

	global_widget_data_pointer = widget_data;
}

void on_click_grid(gpointer data){}

void on_click_paned(gpointer data){}

void on_click_stack(gpointer data){}

void on_click_switcher(gpointer data){}

void on_click_button(gpointer data){}

void on_click_check_button(gpointer data){}

void on_click_color_button(gpointer data){}

void on_click_combo_box(gpointer data){}

void on_click_entry(gpointer data){}

void on_click_font_button(gpointer data){}

void on_click_image(gpointer data){}

void on_click_label(gpointer data){}

void on_click_level_bar(gpointer data){}

void on_click_link_button(gpointer data){}

void on_click_menu_button(gpointer data){}

void on_click_menu_item(gpointer data){}

void on_click_menu(gpointer data){}

void on_click_progress_bar(gpointer data){}

void on_click_radio_button(gpointer data){}

void on_click_scale(gpointer data){}

void on_click_separator(gpointer data){}

void on_click_spin_button(gpointer data){}

void on_click_spinner(gpointer data){}

void on_click_switch_button(gpointer data){}




const WidgetHandler widget_handlers[] = {
    {"header_bar", (void*(*)(void*))set_properties_header_bar},
	{"scrolled_window", (void*(*)(void*))set_properties_scrolled_window},
    {"box", (void*(*)(void*))set_properties_box},
    {"fixed", (void*(*)(void*))create_fixed},
    {"frame", (void*(*)(void*))set_properties_frame},
    {"grid", (void*(*)(void*))set_properties_grid},
    {"paned", (void*(*)(void*))set_properties_paned},
    {"stack", (void*(*)(void*))set_properties_stack},
    {"switcher", (void*(*)(void*))set_properties_switcher},
    {"button", (void*(*)(void*))set_properties_button},
    {"check_button", (void*(*)(void*))set_properties_check_button},
    {"color_button", (void*(*)(void*))set_properties_color_button},
    {"combo_box", (void*(*)(void*))create_combo_box},
    {"entry", (void*(*)(void*))set_properties_entry},
    {"font_button", (void*(*)(void*))set_properties_font_button},
    {"image", (void*(*)(void*))set_properties_image},
    {"label", (void*(*)(void*))set_properties_label},
    {"level_bar", (void*(*)(void*))set_properties_level_bar},
    {"link_button", (void*(*)(void*))set_properties_link_button},
    {"menu_button", (void*(*)(void*))set_properties_menuButton},
    {"item", (void*(*)(void*))set_properties_item},
    {"menu", (void*(*)(void*))set_properties_menu},
    {"progress_bar", (void*(*)(void*))set_properties_progress_bar},
    {"radio_button", (void*(*)(void*))set_properties_radio_button},
    {"scale", (void*(*)(void*))set_properties_scale},
    {"separator", (void*(*)(void*))set_properties_separator},
    {"spin_button", (void*(*)(void*))set_properties_spin_button},
    {"spinner", (void*(*)(void*))set_properties_spinner},
    {"switch_button", (void*(*)(void*))set_properties_switch_button},
    {NULL, NULL}
};


const WidgetOnClick widget_on_click[] = {
    {"window", on_click_window},
    {"box", on_click_box},
    {"grid", on_click_grid},
    {"paned", on_click_paned},
    {"stack", on_click_stack},
    {"switcher", on_click_switcher},
    {"button", on_click_button},
    {"check_button", on_click_check_button},
    {"color_button", on_click_color_button},
    {"combo_box", on_click_combo_box},
    {"entry", on_click_entry},
    {"font_button", on_click_font_button},
    {"image", on_click_image},
    {"label", on_click_label},
    {"level_bar", on_click_level_bar},
    {"link_button", on_click_link_button},
    {"menu_button", on_click_menu_button},
    {"menu_item", on_click_menu_item},
    {"menu", on_click_menu},
    {"progress_bar", on_click_progress_bar},
    {"radio_button", on_click_radio_button},
    {"scale", on_click_scale},
    {"separator", on_click_separator},
    {"spin_button", on_click_spin_button},
    {"spinner", on_click_spinner},
    {"switch_button", on_click_switch_button},
    {NULL, NULL}
};
