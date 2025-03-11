/*****************************************************************************************************************************
 * 
 * @file widgets_properties.c
 * @brief the implementation of the functions in widgets_properties.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 09/03/2025
 * @version 1.0 (last update 09/03/2025)
 * 
 ****************************************************************************************************************************/

 #include "widgets_properties.h"

 extern GtkWidget *global_tree;
 extern data_widget* global_widget_data_pointer;

 char * box_container_properties(char *parent_id, GtkWidget *obj){

     
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
    
    GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

        GtkWidget *position_label = create_label("Position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, position_label, 0, 0, 1, 1);

        GtkWidget *position = create_combo_box();
            add_to_combo_box(position, "START");
            add_to_combo_box(position, "END");
        add_to_grid(grid, position, 0, 1, 1, 1);	

        GtkWidget *expand_label = create_label("Expand", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, expand_label, 1, 0, 1, 1);

        GtkWidget *expand = create_combo_box();
            add_to_combo_box(expand, "TRUE");
            add_to_combo_box(expand, "FALSE");
        add_to_grid(grid, expand, 1, 1, 1, 1);

        GtkWidget *fill_label = create_label("Fill", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, fill_label, 2, 0, 1, 1);

        GtkWidget *fill = create_combo_box();
            add_to_combo_box(fill, "TRUE");
            add_to_combo_box(fill, "FALSE");
        add_to_grid(grid, fill, 2, 1, 1, 1);

        GtkWidget *padding_label = create_label("Padding", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, padding_label, 3, 0, 1, 1);

        GtkWidget *padding = create_spin_button(0, 100, 5, 0, 0, TRUE, TRUE);
        add_to_grid(grid, padding, 3, 1, 1, 1);
        
        GtkWidget *margin_top_label = create_label("Top Margin", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, margin_top_label, 4, 0, 1, 1);
        
        GtkWidget *margin_top = create_spin_button(0, 100, 5, 0, 0, TRUE, TRUE);
        add_to_grid(grid, margin_top, 4, 1, 1, 1);
        
        GtkWidget *margin_button_label = create_label("Button Margin", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, margin_button_label, 5, 0, 1, 1);
        
        GtkWidget *margin_buttom = create_spin_button(0, 100, 5, 0, 0, TRUE, TRUE);
        add_to_grid(grid, margin_buttom, 5, 1, 1, 1);
        
        GtkWidget *margin_right_label = create_label("Right Margin", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, margin_right_label, 6, 0, 1, 1);
        
        GtkWidget *margin_right = create_spin_button(0, 100, 5, 0, 0, TRUE, TRUE);
        add_to_grid(grid, margin_right, 6, 1, 1, 1);
        
        GtkWidget *left_label = create_label("Left Margin", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
        add_to_grid(grid, left_label, 7, 0, 1, 1);
        
        GtkWidget *left = create_spin_button(0, 100, 5, 0, 0, TRUE, TRUE);
        add_to_grid(grid, left, 7, 1, 1, 1);
        
    add_to_box(box, grid, START, TRUE, TRUE, 0, 0, 0, 1, 1);
    
    GtkWidget *dialog = create_dialog("Box Properties", NULL, GTK_DIALOG_MODAL, 300, 300, 1, box, "OK", GTK_RESPONSE_OK , NULL, GTK_RESPONSE_ACCEPT, NULL, GTK_RESPONSE_ACCEPT);
    run_dialog(dialog);
    
    
    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);
    
    
    add_to_box(dataWidget->widget, obj, (strcmp(get_selecter_item(position),"START") == 0) ? START : END, (strcmp(get_selecter_item(expand),"TRUE") == 0) ? TRUE : FALSE, (strcmp(get_selecter_item(fill),"TRUE") == 0) ? TRUE : FALSE, get_value_spin_button(padding),
    get_value_spin_button(margin_top),
    get_value_spin_button(margin_buttom),
    get_value_spin_button(margin_right),
    get_value_spin_button(left));

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;
    sprintf(closing_tag, "</%s add_to_box(%s, %s, %s, %s, %s, %.0f, %.0f, %.0f, %.0f, %.0f)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, (strcmp(get_selecter_item(position),"START") == 0) ? "START" : "END", (strcmp(get_selecter_item(expand),"TRUE") == 0) ? "TRUE" : "FALSE", (strcmp(get_selecter_item(fill),"TRUE") == 0) ? "TRUE" : "FALSE", get_value_spin_button(padding),
    get_value_spin_button(margin_top),
    get_value_spin_button(margin_buttom),
    get_value_spin_button(margin_right),
    get_value_spin_button(left));


    destroy_widget(dialog);

    return closing_tag;
}

    
void box_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Box_case_informations_grid = create_grid(5, 5, TRUE, TRUE);

    GtkWidget *Box_case_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

    add_to_grid(Box_case_informations_grid, Box_case_informations_id_label, 0, 0, 1, 1);

    GtkWidget *Box_case_informations_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

    set_text(Box_case_informations_id_entry, dataWidget->information);

    add_to_grid(Box_case_informations_grid, Box_case_informations_id_entry, 0, 1, 1, 1);

    GtkWidget *Box_case_informations_align_label = create_label("Align", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

    add_to_grid(Box_case_informations_grid, Box_case_informations_align_label, 1, 0, 1, 1);

    GtkWidget *Box_case_informations_align_value = create_combo_box();

    add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_START");

    add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_END");

    add_to_combo_box(Box_case_informations_align_value, "GTK_ALIGN_CENTER");

    add_to_combo_box(Box_case_informations_align_value, "-1");

    if(((boxInfos *)(dataWidget->widget_data))->align == GTK_ALIGN_START){
        set_active_item(Box_case_informations_align_value, 0);
    } else if (((boxInfos *)(dataWidget->widget_data))->align == GTK_ALIGN_END){
        set_active_item(Box_case_informations_align_value, 1);
    } else if (((boxInfos *)(dataWidget->widget_data))->align == GTK_ALIGN_CENTER){
        set_active_item(Box_case_informations_align_value, 2);
    } else {
        set_active_item(Box_case_informations_align_value, 3);
    }

    add_to_grid(Box_case_informations_grid, Box_case_informations_align_value, 1, 1, 1, 1);

    GtkWidget *Box_case_informations_spacing_label = create_label("Spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

    add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_label, 3, 0, 1, 1);

    GtkWidget *Box_case_informations_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, FALSE);

    set_value_spin_button(Box_case_informations_spacing_value, ((boxInfos *)(dataWidget->widget_data))->spacing);

    add_to_grid(Box_case_informations_grid, Box_case_informations_spacing_value, 3, 1, 1, 1);
    
    add_to_box(box, Box_case_informations_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Box Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){

        char *align = get_selecter_item(Box_case_informations_align_value);
        if(strcmp(align, "GTK_ALIGN_START") == 0){
            ((boxInfos *)(dataWidget->widget_data))->align = GTK_ALIGN_START;
        } else if (strcmp(align, "GTK_ALIGN_END") == 0) {
            ((boxInfos *)(dataWidget->widget_data))->align = GTK_ALIGN_END;
        } else if (strcmp(align, "GTK_ALIGN_CENTER") == 0){
            ((boxInfos *)(dataWidget->widget_data))->align = GTK_ALIGN_CENTER;
        } else {
            ((boxInfos *)(dataWidget->widget_data))->align = -1;
        }

        ((boxInfos *)(dataWidget->widget_data))->spacing = get_value_spin_button(Box_case_informations_spacing_value);
        
        modify_box(dataWidget->widget, (boxInfos *)(dataWidget->widget_data));
    } else if (response == GTK_RESPONSE_REJECT) {
        if(is_child(global_tree)){
            TreeNodeData *widget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));
            destroy_widget(widget->widget);
            delete_selected_element(global_tree);
            
        } else {
            GtkWidget *dialog = create_dialog("Your cannot remove a parent widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 1, NULL, 1);
            run_dialog(dialog);
            destroy_widget(dialog);
        }
    } 
    destroy_widget(dialog);
}

char * header_bar_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
        GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

            GtkWidget *position_label = create_label("Position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, position_label, 0, 0, 1, 1);

            GtkWidget *position_value = create_combo_box();
                add_to_combo_box(position_value, "RIGHT");
                add_to_combo_box(position_value, "LEFT");
            add_to_grid(grid, position_value, 0, 1, 1, 1);
        add_to_box(box, grid, START, TRUE, TRUE, 0, 0, 0, 1, 1);

    GtkWidget *dialog = create_dialog("Header Bar Properties", NULL, GTK_DIALOG_MODAL, 300, 300, 1, box, "OK", GTK_RESPONSE_OK , NULL, GTK_RESPONSE_ACCEPT, NULL, GTK_RESPONSE_ACCEPT);
    run_dialog(dialog);

    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_header_bar(dataWidget->widget, obj, (strcmp(get_selecter_item(position_value),"RIGHT") == 0) ? RIGHT : LEFT);
    
    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_header_bar(%s, %s, %s)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, (strcmp(get_selecter_item(position_value),"RIGHT") == 0) ? "RIGHT" : "LEFT");

    destroy_widget(dialog);

    return closing_tag;
}


void header_bar_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

	GtkWidget *header_bar_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *header_bar_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_id_label, 0, 0, 1, 1);

	GtkWidget *header_bar_id_value = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 200, 0.5);

    set_text(header_bar_id_value, dataWidget->information);

	add_to_grid(header_bar_informations_grid, header_bar_id_value, 0, 1, 1, 1);

	GtkWidget *header_bar_informations_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_title_label, 1, 0, 1, 1);

	GtkWidget *header_bar_informations_title_value = create_entry(NULL, "title", TRUE, TRUE, 200, 0.5);

    set_text(header_bar_informations_title_value, ((headerBarInfos *)(dataWidget->widget_data))->title);

	add_to_grid(header_bar_informations_grid, header_bar_informations_title_value, 1, 1, 1, 1);

	GtkWidget *header_bar_informations_subtitle_label = create_label("Subtitle", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_label, 2, 0, 1, 1);

	GtkWidget *header_bar_informations_subtitle_value = create_entry(NULL, "subtitle", TRUE, TRUE, 200, 0.5);

    set_text(header_bar_informations_subtitle_value, ((headerBarInfos *)(dataWidget->widget_data))->subtitle);

	add_to_grid(header_bar_informations_grid, header_bar_informations_subtitle_value, 2, 1, 1, 1);

	GtkWidget *header_bar_informations_icon_label = create_label("Icon", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_icon_label, 3, 0, 1, 1);

	GtkWidget *header_bar_informations_icon_value = create_entry(NULL, "icon path", TRUE, TRUE, 200	, 0.5);

    if(((headerBarInfos *)(dataWidget->widget_data))->icon_path != NULL)
        set_text(header_bar_informations_icon_value, ((headerBarInfos *)(dataWidget->widget_data))->icon_path);
    else
        set_text(header_bar_informations_icon_value, "");

	add_to_grid(header_bar_informations_grid, header_bar_informations_icon_value, 3, 1, 1, 1);

	GtkWidget *header_bar_informations_settings_label = create_label("Settings", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(header_bar_informations_grid, header_bar_informations_settings_label, 4, 0, 1, 1);

	GtkWidget *header_bar_informations_settings_value = create_combo_box();

	add_to_combo_box(header_bar_informations_settings_value, "TRUE");

	add_to_combo_box(header_bar_informations_settings_value, "FALSE");

    if(((headerBarInfos *)(dataWidget->widget_data))->settings)
        set_active_item(header_bar_informations_settings_value, 0);
    else
        set_active_item(header_bar_informations_settings_value, 1);

	add_to_grid(header_bar_informations_grid, header_bar_informations_settings_value, 4, 1, 1, 1);

    add_to_box(box, header_bar_informations_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Header Bar Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        strcpy(((headerBarInfos *)(dataWidget->widget_data))->title, get_text(header_bar_informations_title_value));
        strcpy(((headerBarInfos *)(dataWidget->widget_data))->subtitle, get_text(header_bar_informations_subtitle_value));
        if(strcmp(get_text(header_bar_informations_icon_value), "") != 0){
            if(!((headerBarInfos *)(dataWidget->widget_data))->icon_path){
                ((headerBarInfos *)(dataWidget->widget_data))->icon_path = malloc(sizeof(char) * (strlen(get_text(header_bar_informations_icon_value)) + 1));
            }
            strcpy(((headerBarInfos *)(dataWidget->widget_data))->icon_path, get_text(header_bar_informations_icon_value));
        } else 
            ((headerBarInfos *)(dataWidget->widget_data))->icon_path = NULL;

        ((headerBarInfos *)(dataWidget->widget_data))->settings = strcmp(get_selecter_item(header_bar_informations_settings_value), "TRUE") == 0 ? TRUE : FALSE;

        modify_header_bar(dataWidget->widget, ((headerBarInfos *)(dataWidget->widget_data)));
    } else if (response == GTK_RESPONSE_REJECT){
        if(is_child(global_tree)){
            TreeNodeData *widget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));
            destroy_widget(widget->widget);
            delete_selected_element(global_tree);
            
        } else {
            GtkWidget *dialog = create_dialog("Your cannot remove a parent widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 1, NULL, 1);
            run_dialog(dialog);
            destroy_widget(dialog);
        }
    }
    destroy_widget(dialog);
}

char * fixed_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
        GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

            GtkWidget *x_label = create_label("x position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, x_label, 0, 0, 1, 1);
            GtkWidget *x_value = create_spin_button(0, 1000, 10, 0, 0, TRUE, TRUE);
            add_to_grid(grid, x_value, 0, 1, 1, 1);

            GtkWidget *y_label = create_label("y position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, y_label, 1, 0, 1, 1);
            GtkWidget *y_value = create_spin_button(0, 1000, 10, 0, 0, TRUE, TRUE);
            add_to_grid(grid, y_value, 1, 1, 1, 1);
        add_to_box(box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Fixed Container Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL, NULL, GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    int x = get_value_spin_button(x_value);
    int y = get_value_spin_button(y_value);
    
    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_fixed(dataWidget->widget, obj, x, y);

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_fixed(%s, %s, %d, %d)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, x, y);

    destroy_widget(dialog);

    return closing_tag;
}
void fixed_widget_properties(){
    GtkWidget *dialog = create_dialog("Fixed Has No Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, NULL, "OK", GTK_RESPONSE_OK, "Supprimer", GTK_RESPONSE_REJECT, NULL, GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_REJECT){
        if(is_child(global_tree)){
            TreeNodeData *widget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));
            destroy_widget(widget->widget);
            delete_selected_element(global_tree);
            
        } else {
            GtkWidget *dialog = create_dialog("Your cannot remove a parent widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 1, NULL, 1);
            run_dialog(dialog);
            destroy_widget(dialog);
        }
    }

    destroy_widget(dialog);
}

char * frame_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
        GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

            GtkWidget *top_label = create_label("Top", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, top_label, 0, 0, 1, 1);
            GtkWidget *top_value = create_spin_button(0, 20, 1, 2, 0, TRUE, TRUE);
            add_to_grid(grid, top_value, 0, 1, 1, 1);

            GtkWidget *bottom_label = create_label("Bottom", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, bottom_label, 1, 0, 1, 1);
            GtkWidget *bottom_value = create_spin_button(0, 20, 1, 2, 0, TRUE, TRUE);
            add_to_grid(grid, bottom_value, 1, 1, 1, 1);

            GtkWidget *left_label = create_label("Left", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, left_label, 2, 0, 1, 1);
            GtkWidget *left_value = create_spin_button(0, 20, 1, 2, 0, TRUE, TRUE);
            add_to_grid(grid, left_value, 2, 1, 1, 1);

            GtkWidget *right_label = create_label("Right", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, right_label, 3, 0, 1, 1);
            GtkWidget *right_value = create_spin_button(0, 20, 1, 2, 0, TRUE, TRUE);
            add_to_grid(grid, right_value, 3, 1, 1, 1);

        add_to_box(box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Frame Container Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL, NULL, GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    gint top = get_value_spin_button(top_value);
    gint bottom = get_value_spin_button(bottom_value);
    gint left = get_value_spin_button(left_value);
    gint right = get_value_spin_button(right_value);
        
    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_frame(dataWidget->widget, obj, top, bottom, left, right);

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_frame(%s, %s, %d, %d, %d, %d)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, top, bottom, left, right);

    destroy_widget(dialog);

    return closing_tag;

}
void frame_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Frame_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Frame_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_id_label, 0, 0, 1, 1);

	GtkWidget *Frame_id_entry = create_entry(NULL, "must be unique and no space", TRUE, TRUE, 20, 0.5);

    set_text(Frame_id_entry, dataWidget->information);

	add_to_grid(Frame_grid, Frame_id_entry, 0, 1, 1, 1);

	GtkWidget *Frame_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_title_label, 1, 0, 1, 1);

	GtkWidget *Frame_title_value = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    set_text(Frame_title_value, ((frameInfos *)(dataWidget->widget_data))->title);

	add_to_grid(Frame_grid, Frame_title_value, 1, 1, 1, 1);

	GtkWidget *Frame_horizontal_placement_label = create_label("Horizontal placement", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_horizontal_placement_label, 2, 0, 1, 1);

	GtkWidget *Frame_horizontal_placement_value = create_spin_button(0, 1, 0.5, 0.5, 1, FALSE, TRUE);

    set_value_spin_button(Frame_horizontal_placement_value, ((frameInfos *)(dataWidget->widget_data))->horizontal_placement);

	add_to_grid(Frame_grid, Frame_horizontal_placement_value, 2, 1, 1, 1);

	GtkWidget *Frame_vertical_placement_label = create_label("Vertical placement", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Frame_grid, Frame_vertical_placement_label, 3, 0, 1, 1);
    
	GtkWidget *Frame_vertical_placement_value = create_spin_button(0, 1, 0.5, 0.5, 1, FALSE, TRUE);
    
    set_value_spin_button(Frame_vertical_placement_value, ((frameInfos *)(dataWidget->widget_data))->vertical_placement);

	add_to_grid(Frame_grid, Frame_vertical_placement_value, 3, 1, 1, 1);

    add_to_box(box, Frame_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Header Bar Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        ((frameInfos *)(dataWidget->widget_data))->title = g_strdup(get_text(Frame_title_value));

        ((frameInfos *)(dataWidget->widget_data))->horizontal_placement = get_value_spin_button(Frame_horizontal_placement_value);

        ((frameInfos *)(dataWidget->widget_data))->vertical_placement = get_value_spin_button(Frame_vertical_placement_value);

        modify_frame(dataWidget->widget, ((frameInfos *)(dataWidget->widget_data)));
    } else if (response == GTK_RESPONSE_REJECT){
        if(is_child(global_tree)){
            TreeNodeData *widget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));
            destroy_widget(widget->widget);
            delete_selected_element(global_tree);
            
        } else {
            GtkWidget *dialog = create_dialog("Your cannot remove a parent widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 1, NULL, 1);
            run_dialog(dialog);
            destroy_widget(dialog);
        }
    }

    destroy_widget(dialog);
}

char * grid_container_properties(char *parent_id, GtkWidget *obj){}
void grid_widget_properties(){}

char * paned_container_properties(char *parent_id, GtkWidget *obj){}
void paned_widget_properties(){}

char * stack_container_properties(char *parent_id, GtkWidget *obj){}
void stack_widget_properties(){}

char * switcher_container_properties(char *parent_id, GtkWidget *obj){}
void switcher_widget_properties(){}