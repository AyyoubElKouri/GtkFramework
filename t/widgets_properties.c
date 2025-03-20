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
 static int combo_box_items = 0;
 extern GtkCssProvider *provider;


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

    char *position_chaine = (get_selecter_item(position)) ? get_selecter_item(position) : "START";
    char *expand_chaine = (get_selecter_item(expand)) ? (get_selecter_item(expand)) : "TRUE";
    char *fill_chaine = (get_selecter_item(fill)) ? (get_selecter_item(fill)) : "TRUE";


    add_to_box(dataWidget->widget, obj, (strcmp(position_chaine, "START") == 0) ? START : END, (strcmp(expand_chaine,"TRUE") == 0) ? TRUE : FALSE, (strcmp(fill_chaine,"TRUE") == 0) ? TRUE : FALSE, get_value_spin_button(padding),
    get_value_spin_button(margin_top),
    get_value_spin_button(margin_buttom),
    get_value_spin_button(margin_right),
    get_value_spin_button(left));

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;
    sprintf(closing_tag, "</%s add_to_box(%s, %s, %s, %s, %s, %.0f, %.0f, %.0f, %.0f, %.0f)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, (strcmp(position_chaine, "START") == 0) ? "START" : "END", (strcmp(expand_chaine,"TRUE") == 0) ? "TRUE" : "FALSE", (strcmp(fill_chaine,"TRUE") == 0) ? "TRUE" : "FALSE", get_value_spin_button(padding),
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

    GtkWidget *Box_case_informations_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

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

	GtkWidget *header_bar_id_value = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 200, 0.5);

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

        if(strcmp(get_text(header_bar_informations_title_value), "") != 0)
        {
            ((headerBarInfos *)(dataWidget->widget_data))->title = g_strdup(get_text(header_bar_informations_title_value));

        } else if (((headerBarInfos *)(dataWidget->widget_data))->title) {

                g_free(((headerBarInfos *)(dataWidget->widget_data))->title);
                ((headerBarInfos *)(dataWidget->widget_data))->title = NULL;

        }

        if(strcmp(get_text(header_bar_informations_subtitle_value), "") != 0){
            ((headerBarInfos *)(dataWidget->widget_data))->subtitle = g_strdup(get_text(header_bar_informations_subtitle_value));
        } else if (((headerBarInfos *)(dataWidget->widget_data))->subtitle){
            g_free(((headerBarInfos *)(dataWidget->widget_data))->subtitle);
            ((headerBarInfos *)(dataWidget->widget_data))->subtitle = NULL;
        }
        

        if(strcmp(get_text(header_bar_informations_icon_value), "") != 0){
            if(((headerBarInfos *)(dataWidget->widget_data))->icon_path){
                g_free(((headerBarInfos *)(dataWidget->widget_data))->icon_path);
            }

            ((headerBarInfos *)(dataWidget->widget_data))->icon_path = g_strdup(get_text(header_bar_informations_icon_value));

        } else{
            g_free(((headerBarInfos *)(dataWidget->widget_data))->icon_path);
            ((headerBarInfos *)(dataWidget->widget_data))->icon_path = NULL;
        }

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

	GtkWidget *Frame_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

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

    GtkWidget *dialog = create_dialog   (
                                             "Header Bar Properties",
                                                                NULL, 
                                                    GTK_DIALOG_MODAL, 
                                                                  30,
                                                                  30, 
                                                                   1, 
                                                                 box, 
                                                                "OK", 
                                                     GTK_RESPONSE_OK, 
                                                           "Annuler",
                                                 GTK_RESPONSE_CANCEL, 
                                                         "Supprimer",
                                                GTK_RESPONSE_REJECT
                                        );

    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        g_free(((frameInfos *)(dataWidget->widget_data))->title);
        ((frameInfos *)(dataWidget->widget_data))->title                = g_strdup(get_text(Frame_title_value));

        ((frameInfos *)(dataWidget->widget_data))->horizontal_placement = get_value_spin_button(Frame_horizontal_placement_value);

        ((frameInfos *)(dataWidget->widget_data))->vertical_placement   = get_value_spin_button(Frame_vertical_placement_value);

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

char * grid_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
        GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

            GtkWidget *row_label = create_label("Row", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, row_label, 0, 0, 1, 1);
            GtkWidget *row_value = create_spin_button(0, 100, 1, 0, 0, TRUE, TRUE);
            add_to_grid(grid, row_value, 0, 1, 1, 1);

            GtkWidget *column_label = create_label("Column", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, column_label, 1, 0, 1, 1);
            GtkWidget *column_value = create_spin_button(0, 100, 1, 0, 0, TRUE, TRUE);
            add_to_grid(grid, column_value, 1, 1, 1, 1);

            GtkWidget *row_span_label = create_label("Row Span", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, row_span_label, 2, 0, 1, 1);
            GtkWidget *row_span_value = create_spin_button(0, 10, 1, 1, 0, TRUE, TRUE);
            add_to_grid(grid, row_span_value, 2, 1, 1, 1);

            GtkWidget *column_span_label = create_label("Column Span", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, column_span_label, 3, 0, 1, 1);
            GtkWidget *column_span_value = create_spin_button(0, 10, 1, 1, 0, TRUE, TRUE);
            add_to_grid(grid, column_span_value, 3, 1, 1, 1);

        add_to_box(box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Grid Container Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL, NULL, GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    gint row_spacing = get_value_spin_button(row_value);
    gint column_spacing = get_value_spin_button(column_value);
    gint row_span = get_value_spin_button(row_span_value);
    gint column_span = get_value_spin_button(column_span_value);

    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_grid(dataWidget->widget, obj, row_spacing, column_spacing, column_span, row_span);

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_grid(%s, %s, %d, %d, %d, %d)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, row_spacing, column_spacing, column_span, row_span);

    destroy_widget(dialog);

    return closing_tag;
}


void grid_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Grid_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Grid_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
	
	add_to_grid(Grid_grid, Grid_id_label, 0, 0, 1, 1);

	GtkWidget *Grid_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(Grid_id_entry, dataWidget->information);

	add_to_grid(Grid_grid, Grid_id_entry, 0, 1, 1, 1);
	
	GtkWidget *Grid_rows_spacing_label = create_label("Rows spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_rows_spacing_label, 1, 0, 1, 1);

	GtkWidget *Grid_rows_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, TRUE);

    set_value_spin_button(Grid_rows_spacing_value, ((gridInfos *)(dataWidget->widget_data))->rows_spacing);

	add_to_grid(Grid_grid, Grid_rows_spacing_value, 1, 1, 1, 1);
	
	GtkWidget *Grid_columns_spacing_label = create_label("Columns spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_columns_spacing_label, 2, 0, 1, 1);

	GtkWidget *Grid_columns_spacing_value = create_spin_button(0, 100, 5, 0, 0, FALSE, TRUE);

    set_value_spin_button(Grid_columns_spacing_value, ((gridInfos *)(dataWidget->widget_data))->columns_spacing);

	add_to_grid(Grid_grid, Grid_columns_spacing_value, 2, 1, 1, 1);

	GtkWidget *Grid_rows_homogeneous_label = create_label("Rows homogeneous", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_rows_homogeneous_label, 3, 0, 1, 1);

	GtkWidget *Grid_rows_homogeneous_value = create_combo_box();

	add_to_combo_box(Grid_rows_homogeneous_value, "TRUE");

	add_to_combo_box(Grid_rows_homogeneous_value, "FALSE");

    if(((gridInfos *)(dataWidget->widget_data))->rows_homogeneous)
        set_active_item(Grid_rows_homogeneous_value, 0);
    else
        set_active_item(Grid_rows_homogeneous_value, 1);    

	add_to_grid(Grid_grid, Grid_rows_homogeneous_value, 3, 1, 1, 1);

	GtkWidget *Grid_columns_homogeneous_label = create_label("Columns homogeneous", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Grid_grid, Grid_columns_homogeneous_label, 4, 0, 1, 1);

	GtkWidget *Grid_columns_homogeneous_value = create_combo_box();

	add_to_combo_box(Grid_columns_homogeneous_value, "TRUE");

	add_to_combo_box(Grid_columns_homogeneous_value, "FALSE");

    if(((gridInfos *)(dataWidget->widget_data))->columns_homogeneous)
        set_active_item(Grid_columns_homogeneous_value, 0);
    else
        set_active_item(Grid_columns_homogeneous_value, 1);

	add_to_grid(Grid_grid, Grid_columns_homogeneous_value, 4, 1, 1, 1);

    add_to_box(box, Grid_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Grid Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        ((gridInfos *)(dataWidget->widget_data))->rows_spacing = get_value_spin_button(Grid_rows_spacing_value);
        ((gridInfos *)(dataWidget->widget_data))->columns_spacing = get_value_spin_button(Grid_columns_spacing_value);
        ((gridInfos *)(dataWidget->widget_data))->rows_homogeneous = (strcmp(get_selecter_item(Grid_rows_homogeneous_value), "TRUE") == 0) ? TRUE : FALSE;
        ((gridInfos *)(dataWidget->widget_data))->columns_homogeneous = (strcmp(get_selecter_item(Grid_columns_homogeneous_value), "TRUE") == 0) ? TRUE : FALSE;

        modify_grid(dataWidget->widget, ((gridInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char * paned_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
        GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

            GtkWidget *first_or_second_label = create_label("First Or Second", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, first_or_second_label, 0, 0, 1, 1);

            GtkWidget *first_or_second_value = create_combo_box();
                add_to_combo_box(first_or_second_value, "FIRST");
                add_to_combo_box(first_or_second_value, "SECOND");
            add_to_grid(grid, first_or_second_value, 0, 1, 1, 1);
        add_to_box(box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

        GtkWidget *dialog = create_dialog("Paned Container Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL, NULL, GTK_RESPONSE_REJECT);
        gint response = run_dialog(dialog);
        
        FIRST_OR_SECOND first_or_second;
        char *fos = get_selecter_item(first_or_second_value);

        if(!fos){
            first_or_second = FIRST;
        } else if(strcmp(fos, "FIRST") == 0){
            first_or_second = FIRST;
        } else 
            first_or_second = SECOND;

    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_paned(dataWidget->widget, obj, first_or_second);

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_paned(%s, %s, %d)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, first_or_second);

    destroy_widget(dialog);

    return closing_tag;        
}

void paned_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Paned_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Paned_id_label = create_label("ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_id_label, 0, 0, 1, 1);

	GtkWidget *Paned_id_value = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(Paned_id_value, dataWidget->information);

	add_to_grid(Paned_grid, Paned_id_value, 0, 1, 1, 1);

	GtkWidget *Paned_default_position_label = create_label("Default position", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_default_position_label, 1, 0, 1, 1);

	GtkWidget *Paned_default_position_value = create_spin_button(0, 1000, 100, 500, 0, FALSE, TRUE);

    set_value_spin_button(Paned_default_position_value, ((panedInfos *)(dataWidget->widget_data))->default_position);

	add_to_grid(Paned_grid, Paned_default_position_value, 1, 1, 1, 1);

	GtkWidget *Paned_show_handle_label = create_label("Show Handle", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Paned_grid, Paned_show_handle_label, 2, 0, 1, 1);

	GtkWidget *Paned_show_handle_combo_box = create_combo_box();

	add_to_combo_box(Paned_show_handle_combo_box, "TRUE");

	add_to_combo_box(Paned_show_handle_combo_box, "FALSE");

    if(((panedInfos *)(dataWidget->widget_data))->show_handle){
        set_active_item(Paned_show_handle_combo_box, 0);
    } else {
        set_active_item(Paned_show_handle_combo_box, 1);
    }

	add_to_grid(Paned_grid, Paned_show_handle_combo_box, 2, 1, 1, 1);

    add_to_box(box, Paned_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Paned Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        ((panedInfos *)(dataWidget->widget_data))->default_position = get_value_spin_button(Paned_default_position_value);
        ((panedInfos *)(dataWidget->widget_data))->show_handle = (strcmp(get_selecter_item(Paned_show_handle_combo_box), "TRUE") == 0) ? TRUE : FALSE;

        modify_paned(dataWidget->widget, ((panedInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char * stack_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
        GtkWidget *grid = create_grid(5, 5, TRUE, TRUE);

            GtkWidget *name_label = create_label("Name ", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
            add_to_grid(grid, name_label, 0, 0, 1, 1);

            GtkWidget *name_value = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);            
            add_to_grid(grid, name_value, 0, 1, 1, 1);

        add_to_box(box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);
    
    GtkWidget *dialog = create_dialog("Stack Container Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, NULL, GTK_RESPONSE_CANCEL, NULL, GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    char *name = get_text(name_value);
    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_stack(dataWidget->widget, obj, name);

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_stack(%s, %s, \"%s\")>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget, name);

    destroy_widget(dialog);

    return closing_tag;

}

void stack_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Stack_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *stack_widget_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_widget_id_label, 0, 0, 1, 1);

	GtkWidget *stack_widget_id_value = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(stack_widget_id_value, dataWidget->widget_name);

	add_to_grid(Stack_grid, stack_widget_id_value, 0, 1, 1, 1);
	
	GtkWidget *stack_switcher_widget_label = create_label("Switcher ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_switcher_widget_label, 1, 0, 1, 1);

	GtkWidget *stack_switcher_widget_id = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(stack_switcher_widget_id, ((stackInfos *)(dataWidget->widget_data))->id_switcher);

	add_to_grid(Stack_grid, stack_switcher_widget_id, 1, 1, 1, 1);

	GtkWidget *stack_transition_type_label = create_label("Transition Type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_transition_type_label, 2, 0, 1, 1);

	GtkWidget *stack_transition_type_value_combo_box = create_combo_box();

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_CROSSFADE");

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_NONE");

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT");

	add_to_combo_box(stack_transition_type_value_combo_box, "GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT");

    if(((stackInfos *)(dataWidget->widget_data))->transition_type == GTK_STACK_TRANSITION_TYPE_CROSSFADE){
        set_active_item(stack_transition_type_value_combo_box, 0);
    } else if (((stackInfos *)(dataWidget->widget_data))->transition_type == GTK_STACK_TRANSITION_TYPE_NONE){
        set_active_item(stack_transition_type_value_combo_box, 1);
    } else if (((stackInfos *)(dataWidget->widget_data))->transition_type == GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT){
        set_active_item(stack_transition_type_value_combo_box, 2);
    } else {
        set_active_item(stack_transition_type_value_combo_box, 3);
    }

	add_to_grid(Stack_grid, stack_transition_type_value_combo_box, 2, 1, 1, 1);

	GtkWidget *stack_duration_label = create_label("Duration", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Stack_grid, stack_duration_label, 3, 0, 1, 1);

	GtkWidget *stack_duration_value_spin_button = create_spin_button(0, 1000, 100, 500, 0, FALSE, TRUE);

    set_value_spin_button(stack_duration_value_spin_button, ((stackInfos *)(dataWidget->widget_data))->transition_duration);

	add_to_grid(Stack_grid, stack_duration_value_spin_button, 3, 1, 1, 1);

    add_to_box(box, Stack_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Stack Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        ((stackInfos *)(dataWidget->widget_data))->transition_duration = get_value_spin_button(stack_duration_value_spin_button);
        
        char *transmition = get_selecter_item(stack_transition_type_value_combo_box);
        if(strcmp(transmition, "GTK_STACK_TRANSITION_TYPE_CROSSFADE") == 0){
            ((stackInfos *)(dataWidget->widget_data))->transition_type = GTK_STACK_TRANSITION_TYPE_CROSSFADE;
        } else if (strcmp(transmition, "GTK_STACK_TRANSITION_TYPE_NONE") == 0){
            ((stackInfos *)(dataWidget->widget_data))->transition_type = GTK_STACK_TRANSITION_TYPE_NONE;
        } else if (strcmp(transmition, "GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT") == 0){
            ((stackInfos *)(dataWidget->widget_data))->transition_type = GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT;
        } else {
            ((stackInfos *)(dataWidget->widget_data))->transition_type = GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT;
        }

        modify_stack(dataWidget->widget, ((stackInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char * switcher_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add element to a switcher!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void switcher_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Switcher_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *switcher_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, switcher_id_label, 0, 0, 1, 1);

	GtkWidget *switcher_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(switcher_id_entry, dataWidget->information);

	add_to_grid(Switcher_grid, switcher_id_entry, 0, 1, 1, 1);

	GtkWidget *switcher_spacing_label = create_label("Spacing", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, switcher_spacing_label, 1, 0, 1, 1);
    
	GtkWidget *switcher_spacing_value_spin_button = create_spin_button(0, 100, 5, 5, 0, FALSE, TRUE);

    set_value_spin_button(switcher_spacing_value_spin_button, ((switcherInfos *)dataWidget->widget_data)->spacing);

	add_to_grid(Switcher_grid, switcher_spacing_value_spin_button, 1, 1, 1, 1);

	GtkWidget *same_size_label = create_label("Same Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Switcher_grid, same_size_label, 2, 0, 1, 1);

	GtkWidget *same_size_value_combo_box = create_combo_box();

	add_to_combo_box(same_size_value_combo_box, "TRUE");

	add_to_combo_box(same_size_value_combo_box, "FALSE");

    if(((switcherInfos *)dataWidget->widget_data)->buttons_same_size)
        set_active_item(same_size_value_combo_box, 0);
    else
        set_active_item(same_size_value_combo_box, 1);

	add_to_grid(Switcher_grid, same_size_value_combo_box, 2, 1, 1, 1);

    add_to_box(box, Switcher_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Switcher Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        ((switcherInfos *)dataWidget->widget_data)->spacing = get_value_spin_button(switcher_spacing_value_spin_button);
        ((switcherInfos *)dataWidget->widget_data)->buttons_same_size = (strcmp(get_selecter_item(same_size_value_combo_box), "TRUE") == 0) ? TRUE : FALSE;

        modify_switcher(dataWidget->widget, ((switcherInfos *)dataWidget->widget_data));
    } else if(response == GTK_RESPONSE_REJECT){
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

char * scrolled_window_container_properties(char *parent_id, GtkWidget *obj){
    
    TreeNodeData *dataWidget = search_tree(global_tree, parent_id);

    add_to_scrolled_window(dataWidget->widget, obj);

    char *closing_tag = malloc(100 * sizeof(char));
    if(!closing_tag) return NULL;

    sprintf(closing_tag, "</%s add_to_scrolled_window(%s, %s)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget);

    return closing_tag;
}

void scrolled_window_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *scrolled_window_informations_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *scrolled_window_informations_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_label, 0, 0, 1, 1);

	GtkWidget *scrolled_window_informations_id_value = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(scrolled_window_informations_id_value, dataWidget->widget_name);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_id_value, 0, 1, 1, 1);

	GtkWidget *scrolled_window_informations_horizontal_label = create_label("Horizontal", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_label, 1, 0, 1, 1);

	GtkWidget *scrolled_window_informations_horizontal_value = create_combo_box();

	add_to_combo_box(scrolled_window_informations_horizontal_value, "TRUE");

	add_to_combo_box(scrolled_window_informations_horizontal_value, "FALSE");

    if(((scrolledWindowInfos *)(dataWidget->widget_data))->horizontal){
        set_active_item(scrolled_window_informations_horizontal_value, 0);
    } else {
        set_active_item(scrolled_window_informations_horizontal_value, 1);
    }

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_horizontal_value, 1, 1, 1, 1);

	GtkWidget *scrolled_window_informations_vertical_label = create_label("Vertical", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_label, 2, 0, 1, 1);

	GtkWidget *scrolled_window_informations_vertical_value = create_combo_box();

	add_to_combo_box(scrolled_window_informations_vertical_value, "TRUE");

	add_to_combo_box(scrolled_window_informations_vertical_value, "FALSE");

    if(((scrolledWindowInfos *)(dataWidget->widget_data))->vertical){
        set_active_item(scrolled_window_informations_vertical_value, 0);
    } else {
        set_active_item(scrolled_window_informations_vertical_value, 1);
    }

	add_to_grid(scrolled_window_informations_grid, scrolled_window_informations_vertical_value, 2, 1, 1, 1);

    add_to_box(box, scrolled_window_informations_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Scrolled Window Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        ((scrolledWindowInfos *)(dataWidget->widget_data))->horizontal = (strcmp(get_selecter_item(scrolled_window_informations_horizontal_value), "TRUE") == 0) ? TRUE : FALSE;
        ((scrolledWindowInfos *)(dataWidget->widget_data))->vertical = (strcmp(get_selecter_item(scrolled_window_informations_vertical_value), "TRUE") == 0) ? TRUE : FALSE;

        modify_scrolled_window(dataWidget->widget, ((scrolledWindowInfos *)dataWidget->widget_data));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *button_container_properties(char *parent_id, GtkWidget *obj){

    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}


void button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_id_label, 0, 0, 1, 1);

	GtkWidget *button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(button_id_entry, dataWidget->information);

	add_to_grid(button_grid, button_id_entry, 0, 1, 1, 1);

	GtkWidget *button_relief_label = create_label("Relief", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_relief_label, 1, 0, 1, 1);

	GtkWidget *button_relief_combo_box = create_combo_box();

	add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NONE");

	add_to_combo_box(button_relief_combo_box, "GTK_RELIEF_NORMAL");

    if(((buttonInfos *)(dataWidget->widget_data))->relief == GTK_RELIEF_NONE){
        set_active_item(button_relief_combo_box, 0);
    } else {
        set_active_item(button_relief_combo_box, 1);
    }

	add_to_grid(button_grid, button_relief_combo_box, 1, 1, 1, 1);

	GtkWidget *button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_label_label, 2, 0, 1, 1);

	GtkWidget *button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    if(!((buttonInfos *)(dataWidget->widget_data))->label){
        set_text(button_label_entry, "");
    }else
        set_text(button_label_entry, ((buttonInfos *)(dataWidget->widget_data))->label);

	add_to_grid(button_grid, button_label_entry, 2, 1, 1, 1);

	GtkWidget *button_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_use_underline_label, 3, 0, 1, 1);

	GtkWidget *button_use_underline_combo_box = create_combo_box();

	add_to_combo_box(button_use_underline_combo_box, "TRUE");

	add_to_combo_box(button_use_underline_combo_box, "FALSE");

    if(((buttonInfos *)(dataWidget->widget_data))->use_underline == TRUE){
        set_active_item(button_use_underline_combo_box, 0);
    } else {
        set_active_item(button_use_underline_combo_box, 1);
    }

	add_to_grid(button_grid, button_use_underline_combo_box, 3, 1, 1, 1);

	GtkWidget *button_path_to_image_label = create_label("Path to Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_path_to_image_label, 4, 0, 1, 1);

	GtkWidget *button_path_to_image_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    if(!((buttonInfos *)(dataWidget->widget_data))->path_to_image){
        set_text(button_path_to_image_entry, "");
    }else 
        set_text(button_path_to_image_entry, ((buttonInfos *)(dataWidget->widget_data))->path_to_image);

	add_to_grid(button_grid, button_path_to_image_entry, 4, 1, 1, 1);

	GtkWidget *button_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_callback_label, 5, 0, 1, 1);

	GtkWidget *button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    if(!((buttonInfos *)(dataWidget->widget_data))->callback_name){
        set_text(button_callback_entry, "");
    }else
        set_text(button_callback_entry, ((buttonInfos *)(dataWidget->widget_data))->callback_name);

	add_to_grid(button_grid, button_callback_entry, 5, 1, 1, 1);

	GtkWidget *button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(button_grid, button_data_label, 6, 0, 1, 1);

	GtkWidget *button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    if(!((buttonInfos *)(dataWidget->widget_data))->data_name){
        set_text(button_data_entry, "");
    }else
        set_text(button_data_entry, ((buttonInfos *)(dataWidget->widget_data))->data_name);

	add_to_grid(button_grid, button_data_entry, 6, 1, 1, 1);

    add_to_box(box, button_grid, START, FALSE, FALSE, 0, 0, 0 , 0, 0);

    GtkWidget *dialog = create_dialog("Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        char *chaine = ((buttonInfos *)(dataWidget->widget_data))->label;

        if(strcmp(get_text(button_label_entry), "") == 0)
            ((buttonInfos *)(dataWidget->widget_data))->label = NULL;
        else if(!chaine){
            ((buttonInfos *)(dataWidget->widget_data))->label = malloc(sizeof(get_text(button_label_entry)));
        }
        if((strcmp(get_text(button_label_entry), "") != 0))
        strcpy(((buttonInfos *)(dataWidget->widget_data))->label, get_text(button_label_entry));

        chaine = ((buttonInfos *)(dataWidget->widget_data))->path_to_image;

        if(strcmp(get_text(button_path_to_image_entry), "") == 0){
            ((buttonInfos *)(dataWidget->widget_data))->path_to_image = NULL;
        } else if(!chaine){
            ((buttonInfos *)(dataWidget->widget_data))->path_to_image = malloc(sizeof(get_text(button_path_to_image_entry)));
        }
        if(strcmp(get_text(button_path_to_image_entry), "") != 0)
            strcpy(((buttonInfos *)(dataWidget->widget_data))->path_to_image, get_text(button_path_to_image_entry));

        if(strcmp(get_text(button_callback_entry), "") == 0){
            ((buttonInfos *)(dataWidget->widget_data))->callback_name = NULL;
        } else if(!chaine){
            ((buttonInfos *)(dataWidget->widget_data))->callback_name = malloc(sizeof(get_text(button_callback_entry)));
        }

        if(strcmp(get_text(button_callback_entry), "") != 0)
            strcpy(((buttonInfos *)(dataWidget->widget_data))->callback_name, get_text(button_callback_entry));

        chaine = ((buttonInfos *)(dataWidget->widget_data))->data_name;

        if(strcmp(get_text(button_data_entry), "") == 0){
            ((buttonInfos *)(dataWidget->widget_data))->data_name = NULL;
        } else if(!chaine){
            ((buttonInfos *)(dataWidget->widget_data))->data_name = malloc(sizeof(get_text(button_data_entry)));
        }

        if(strcmp(get_text(button_data_entry), "") != 0)
            strcpy(((buttonInfos *)(dataWidget->widget_data))->data_name, get_text(button_data_entry));

        ((buttonInfos *)(dataWidget->widget_data))->relief = (strcmp(get_selecter_item(button_relief_combo_box), "GTK_RELIEF_NONE") == 0) ? GTK_RELIEF_NONE : GTK_RELIEF_NORMAL;
        ((buttonInfos *)(dataWidget->widget_data))->use_underline = (strcmp(get_selecter_item(button_use_underline_combo_box), "TRUE") == 0) ? TRUE : FALSE;


        modify_button(dataWidget->widget, ((buttonInfos *)dataWidget->widget_data));

    } else if(response == GTK_RESPONSE_REJECT){
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

char *check_button_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void check_button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *check_button_grid = create_grid(7, 0, FALSE, FALSE);

	GtkWidget *check_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_id_label, 0, 0, 1, 1);

	GtkWidget *check_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(check_button_id_entry, dataWidget->information);

	add_to_grid(check_button_grid, check_button_id_entry, 0, 1, 1, 1);

	GtkWidget *check_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_label_label, 1, 0, 1, 1);

	GtkWidget *check_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((checkButtonInfos *)(dataWidget->widget_data))->label;
    if(!chaine){
        set_text(check_button_label_entry, "");
    } else {
        set_text(check_button_label_entry, chaine);
    }

	add_to_grid(check_button_grid, check_button_label_entry, 1, 1, 1, 1);

	GtkWidget *check_button_active_label = create_label("Active", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_active_label, 2, 0, 1, 1);

	GtkWidget *check_button_active_combo_box = create_combo_box();

	add_to_combo_box(check_button_active_combo_box, "TRUE");

	add_to_combo_box(check_button_active_combo_box, "FALSE");

    if(((checkButtonInfos *)(dataWidget->widget_data))->active){
        set_active_item(check_button_active_combo_box, 0);
    } else {
        set_active_item(check_button_active_combo_box, 1);
    }

	add_to_grid(check_button_grid, check_button_active_combo_box, 2, 1, 1, 1);

	GtkWidget *check_button_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_use_underline_label, 3, 0, 1, 1);

	GtkWidget *check_button_use_underline_combo_box = create_combo_box();

	add_to_combo_box(check_button_use_underline_combo_box, "TRUE");

	add_to_combo_box(check_button_use_underline_combo_box, "FALSE");


    if(((checkButtonInfos *)(dataWidget->widget_data))->use_underline){
        set_active_item(check_button_use_underline_combo_box, 0);
    } else {
        set_active_item(check_button_use_underline_combo_box, 1);
    }

	add_to_grid(check_button_grid, check_button_use_underline_combo_box, 3, 1, 1, 1);

	GtkWidget *check_button_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_callback_label, 4, 0, 1, 1);

	GtkWidget *check_button_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((checkButtonInfos *)(dataWidget->widget_data))->callback_name;

    if(!chaine){
        set_text(check_button_callback_entry, "");
    } else{
        set_text(check_button_callback_entry, chaine);
    }

	add_to_grid(check_button_grid, check_button_callback_entry, 4, 1, 1, 1);

	GtkWidget *check_button_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(check_button_grid, check_button_data_label, 5, 0, 1, 1);

	GtkWidget *check_button_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((checkButtonInfos *)(dataWidget->widget_data))->data_name;

    if(!chaine){
        set_text(check_button_data_entry, "");
    } else{
        set_text(check_button_data_entry, chaine);
    }
    
	add_to_grid(check_button_grid, check_button_data_entry, 5, 1, 1, 1);

    add_to_box(box, check_button_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Check Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        chaine = get_text(check_button_label_entry);
        if(strcmp(chaine, "") == 0){
            ((checkButtonInfos *)(dataWidget->widget_data))->label = NULL;
        } else if(!((checkButtonInfos *)(dataWidget->widget_data))->label){
            ((checkButtonInfos *)(dataWidget->widget_data))->label = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((checkButtonInfos *)(dataWidget->widget_data))->label, chaine);
        }

        chaine = get_selecter_item(check_button_active_combo_box);
        if(!chaine){
            ((checkButtonInfos *)(dataWidget->widget_data))->active = TRUE;
        } else if(strcmp(chaine, "TRUE") == 0){
            ((checkButtonInfos *)(dataWidget->widget_data))->active = TRUE;
        } else {
            ((checkButtonInfos *)(dataWidget->widget_data))->active = FALSE;
        }
        

        chaine = get_selecter_item(check_button_use_underline_combo_box);
        if(!chaine){
            ((checkButtonInfos *)(dataWidget->widget_data))->use_underline = FALSE;
        } else if(strcmp(chaine, "TRUE") == 0){
            ((checkButtonInfos *)(dataWidget->widget_data))->use_underline = TRUE;
        } else {
            ((checkButtonInfos *)(dataWidget->widget_data))->use_underline = FALSE;
        }


        chaine = get_text(check_button_callback_entry);
        if(strcmp(chaine, "") == 0){
            ((checkButtonInfos *)(dataWidget->widget_data))->callback_name = NULL;
        } else if(!((checkButtonInfos *)(dataWidget->widget_data))->callback_name){
            ((checkButtonInfos *)(dataWidget->widget_data))->callback_name = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((checkButtonInfos *)(dataWidget->widget_data))->callback_name, chaine);
        }

        chaine = get_text(check_button_data_entry);
        if(strcmp(chaine, "") == 0){
            ((checkButtonInfos *)(dataWidget->widget_data))->data_name = NULL;
        } else if(!((checkButtonInfos *)(dataWidget->widget_data))->data_name){
            ((checkButtonInfos *)(dataWidget->widget_data))->data_name = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((checkButtonInfos *)(dataWidget->widget_data))->data_name, chaine);
        }

        modify_check_button(dataWidget->widget, (checkButtonInfos *)(dataWidget->widget_data));

    } else if(response == GTK_RESPONSE_REJECT){
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

char *color_button_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void color_button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *color_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *color_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_id_label, 0, 0, 1, 1);

	GtkWidget *color_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(color_button_id_entry, dataWidget->information);

	add_to_grid(color_button_grid, color_button_id_entry, 0, 1, 1, 1);

	GtkWidget *color_button_default_color_label = create_label("Default Color", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_default_color_label, 1, 0, 1, 1);

	GtkWidget *color_button_default_color_color_button = create_color_button("#FFFFFF", "coloring", TRUE);

	add_to_grid(color_button_grid, color_button_default_color_color_button, 1, 1, 1, 1);

	GtkWidget *color_button_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_title_label, 2, 0, 1, 1);

	GtkWidget *color_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((colorButtonInfos *)(dataWidget->widget_data))->title;
    if(!chaine){
        set_text(color_button_label_entry, "");
    } else {
        set_text(color_button_label_entry, chaine);
    }

	add_to_grid(color_button_grid, color_button_label_entry, 2, 1, 1, 1);

	GtkWidget *color_button_use_alpha_label = create_label("Use Alpha", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(color_button_grid, color_button_use_alpha_label, 3, 0, 1, 1);

	GtkWidget *color_button_use_alpha_combo_box = create_combo_box();

	add_to_combo_box(color_button_use_alpha_combo_box, "TRUE");

	add_to_combo_box(color_button_use_alpha_combo_box, "FALSE");

    if(((colorButtonInfos *)(dataWidget->widget_data))->use_alpha == TRUE){
        set_active_item(color_button_use_alpha_combo_box, 0);
    } else {
        set_active_item(color_button_use_alpha_combo_box, 1);
    }

	add_to_grid(color_button_grid, color_button_use_alpha_combo_box, 3, 1, 1, 1);

    add_to_box(box, color_button_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Color Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        char *chaine = get_color(color_button_default_color_color_button);
        if(strcmp(chaine, "") == 0){
            ((colorButtonInfos *)(dataWidget->widget_data))->default_color = NULL;
        } else if(!((colorButtonInfos *)(dataWidget->widget_data))->default_color){
            ((colorButtonInfos *)(dataWidget->widget_data))->default_color = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0)
            strcpy(((colorButtonInfos *)(dataWidget->widget_data))->default_color, chaine);

        chaine = get_text(color_button_label_entry);
        if(strcmp(chaine, "") == 0){
            ((colorButtonInfos *)(dataWidget->widget_data))->title = NULL;
        } else if(!((colorButtonInfos *)(dataWidget->widget_data))->title){
            ((colorButtonInfos *)(dataWidget->widget_data))->title = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0)
            strcpy(((colorButtonInfos *)(dataWidget->widget_data))->title, chaine);

        chaine = get_selecter_item(color_button_use_alpha_combo_box);

        if(!chaine){
            ((colorButtonInfos *)(dataWidget->widget_data))->use_alpha = TRUE;
        } else if(strcmp(chaine, "TRUE") == 0){
            ((colorButtonInfos *)(dataWidget->widget_data))->use_alpha = TRUE;
        } else {
            ((colorButtonInfos *)(dataWidget->widget_data))->use_alpha = FALSE;
        }

        modify_color_button(dataWidget->widget, (colorButtonInfos *)(dataWidget->widget_data));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *combo_box_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your can add only a text to a combo box!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void combo_box_widget_properties(){
    
    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *grid = create_grid(7, 7 , TRUE, FALSE);

    GtkWidget *attention = create_label("You can delete only the last item added\nOne operation at time", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

    add_to_grid(grid, attention, 0, 0, 2, 1);

    GtkWidget *delete_item_label = create_label("Delete item", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);
    
    add_to_grid(grid, delete_item_label, 1, 0, 1, 1);

    GtkWidget *delete_item_value = create_spin_button(0, 100, 1, 100, 0, TRUE, TRUE);

    add_to_grid(grid, delete_item_value, 1, 1, 1, 1);

    GtkWidget *add_item_label = create_label("Add item", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

    add_to_grid(grid, add_item_label, 2, 0, 1, 1);

    GtkWidget *add_item_value = create_entry(NULL, NULL, TRUE, TRUE, 30, 0.5);

    add_to_grid(grid, add_item_value, 2, 1, 1, 1);

    add_to_box(box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);


    GtkWidget *dialog = create_dialog("Combo box Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        int delete = get_value_spin_button(delete_item_value);
        if(delete != 100){
            remove_from_combo_box(dataWidget->widget, delete);
            char ch[2];
            ch[0] = '0' + delete;
            ch[1] = '\0';

        
            select_element_by_id(global_tree, ch);
            delete_selected_element(global_tree);

            --combo_box_items;
        }

        char *add = get_text(add_item_value);
        if(strcmp(add, "") != 0){
            add_to_combo_box(dataWidget->widget, add);
            TreeNodeData *parent = get_selected_parent_node_data(GTK_TREE_VIEW(global_tree));

            char *closing_tag = malloc(100 *sizeof(char));
            if(!closing_tag) return;

            char ch[2];
            ch[0] = '0' + combo_box_items;
            ch[1] = '\0';
            sprintf(closing_tag, "</combo_box_item add_to_combo_box(%s, \"%s\")>", dataWidget->information, add);

            add_to_tree(global_tree, dataWidget->information, ch, NULL, NULL, NULL, NULL, closing_tag, "combo_box_item");

            ++combo_box_items;
        }
    } else if(response == GTK_RESPONSE_REJECT){
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

char *entry_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void entry_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *entry_box_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *entry_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_id_label, 0, 0, 1, 1);

	GtkWidget *entry_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(entry_id_entry, dataWidget->information);

	add_to_grid(entry_box_grid, entry_id_entry, 0, 1, 1, 1);

	GtkWidget *entry_default_text_label = create_label("Default Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_default_text_label, 1, 0, 1, 1);

	GtkWidget *entry_default_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((entryInfos *)(dataWidget->widget_data))->default_text;
    if(!chaine){
        set_text(entry_default_text_entry, "");
    } else {
        set_text(entry_default_text_entry, chaine);
    }

	add_to_grid(entry_box_grid, entry_default_text_entry, 1, 1, 1, 1);

	GtkWidget *entry_indicator_text_label = create_label("Indicator Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_indicator_text_label, 2, 0, 1, 1);

	GtkWidget *entry_indicator_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((entryInfos *)(dataWidget->widget_data))->indicator_text;

    if(!chaine){
        set_text(entry_indicator_text_entry, "");
    } else {
        set_text(entry_indicator_text_entry, chaine);
    }

	add_to_grid(entry_box_grid, entry_indicator_text_entry, 2, 1, 1, 1);

	GtkWidget *entry_visibility_label = create_label("Visibility", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_visibility_label, 3, 0, 1, 1);

	GtkWidget *entry_visibility_combo_box = create_combo_box();

	add_to_combo_box(entry_visibility_combo_box, "TRUE");

	add_to_combo_box(entry_visibility_combo_box, "FALSE");

    if(((entryInfos *)(dataWidget->widget_data))->visible == TRUE){
        set_active_item(entry_visibility_combo_box, 0);
    } else {
        set_active_item(entry_visibility_combo_box, 1);
    }

	add_to_grid(entry_box_grid, entry_visibility_combo_box, 3, 1, 1, 1);

	GtkWidget *entry_editable_label = create_label("Editable", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_editable_label, 4, 0, 1, 1);

	GtkWidget *entry_editable_combo_box = create_combo_box();

	add_to_combo_box(entry_editable_combo_box, "TRUE");

	add_to_combo_box(entry_editable_combo_box, "FALSE");

    if(((entryInfos *)(dataWidget->widget_data))->editable == TRUE){
        set_active_item(entry_editable_combo_box, 0);
    } else {

        set_active_item(entry_editable_combo_box, 1);
    }


	add_to_grid(entry_box_grid, entry_editable_combo_box, 4, 1, 1, 1);

	GtkWidget *entry_max_length_label = create_label("Max Length", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_max_length_label, 5, 0, 1, 1);

	GtkWidget *entry_max_length_spin_button = create_spin_button(0, 100, 5, 20, 0, FALSE, FALSE);

    set_value_spin_button(entry_max_length_spin_button, ((entryInfos *)(dataWidget->widget_data))->max_length);

	add_to_grid(entry_box_grid, entry_max_length_spin_button, 5, 1, 1, 1);

	GtkWidget *entry_alignment_label = create_label("Alignment", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(entry_box_grid, entry_alignment_label, 6, 0, 1, 1);

	GtkWidget *entry_alignment_spin_button = create_spin_button(0, 1, 0.5, 0, 1, FALSE, FALSE);

    set_value_spin_button(entry_alignment_spin_button, ((entryInfos *)(dataWidget->widget_data))->alignment);

	add_to_grid(entry_box_grid, entry_alignment_spin_button, 6, 1, 1, 1);

    add_to_box(box, entry_box_grid, START , FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Entry Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){
        
        char *chaine = get_text(entry_default_text_entry);
        if(strcmp(chaine, "") == 0){
            ((entryInfos *)(dataWidget->widget_data))->default_text = NULL;
        } else {
            ((entryInfos *)(dataWidget->widget_data))->default_text = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((entryInfos *)(dataWidget->widget_data))->default_text, chaine);
        }

        chaine = get_text(entry_indicator_text_entry);
        if(strcmp(chaine, "") == 0){
            ((entryInfos *)(dataWidget->widget_data))->indicator_text = NULL;
        } else {
            ((entryInfos *)(dataWidget->widget_data))->indicator_text = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((entryInfos *)(dataWidget->widget_data))->indicator_text, chaine);
        }

        chaine = get_selecter_item(entry_visibility_combo_box);

        if(!chaine){
            ((entryInfos *)(dataWidget->widget_data))->visible = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((entryInfos *)(dataWidget->widget_data))->visible = TRUE;
        } else {
            ((entryInfos *)(dataWidget->widget_data))->visible = FALSE;
        }

        chaine = get_selecter_item(entry_editable_combo_box);

        if(!chaine){
            ((entryInfos *)(dataWidget->widget_data))->editable = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((entryInfos *)(dataWidget->widget_data))->editable = TRUE;
        } else {
            ((entryInfos *)(dataWidget->widget_data))->editable = FALSE;
        }


        ((entryInfos *)(dataWidget->widget_data))->max_length = get_value_spin_button(entry_max_length_spin_button);
        ((entryInfos *)(dataWidget->widget_data))->alignment = get_value_spin_button(entry_alignment_spin_button);

        modify_entry(dataWidget->widget, ((entryInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *font_button_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void font_button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *font_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *font_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_id_label, 0, 0, 1, 1);

	GtkWidget *font_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(font_button_id_entry, dataWidget->information);

	add_to_grid(font_button_grid, font_button_id_entry, 0, 1, 1, 1);

	GtkWidget *font_button_default_font_name_label = create_label("Default Font Name", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_default_font_name_label, 1, 0, 1, 1);

	GtkWidget *font_button_default_font_name_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((fontButtonInfos *)(dataWidget->widget_data))->default_font_name;

    if(!chaine){
        set_text(font_button_default_font_name_entry, "");
    } else {
        set_text(font_button_default_font_name_entry, chaine);
    }

	add_to_grid(font_button_grid, font_button_default_font_name_entry, 1, 1, 1, 1);

	GtkWidget *font_button_title_label = create_label("Title", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_title_label, 2, 0, 1, 1);

	GtkWidget *font_button_title_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((fontButtonInfos *)(dataWidget->widget_data))->title;

    if(!chaine){
        set_text(font_button_title_entry, "");
    } else {
        set_text(font_button_title_entry, chaine);
    }

	add_to_grid(font_button_grid, font_button_title_entry, 2, 1, 1, 1);

	GtkWidget *font_button_show_size_label = create_label("Show Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_show_size_label, 3, 0, 1, 1);

	GtkWidget *font_button_show_size_combo_box = create_combo_box();

	add_to_combo_box(font_button_show_size_combo_box, "TRUE");

	add_to_combo_box(font_button_show_size_combo_box, "FALSE");

    if(((fontButtonInfos *)(dataWidget->widget_data))->show_size){
        set_active_item(font_button_show_size_combo_box, 0);
    } else {
        set_active_item(font_button_show_size_combo_box, 1);
    }

	add_to_grid(font_button_grid, font_button_show_size_combo_box, 3, 1, 1, 1);

	GtkWidget *font_button_show_style_label = create_label("Show Style", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_show_style_label, 4, 0, 1, 1);

	GtkWidget *font_button_show_style_combo_box = create_combo_box();

	add_to_combo_box(font_button_show_style_combo_box, "TRUE");

	add_to_combo_box(font_button_show_style_combo_box, "FALSE");

    if(((fontButtonInfos *)(dataWidget->widget_data))->show_style){
        set_active_item(font_button_show_style_combo_box, 0);
    } else {
        set_active_item(font_button_show_style_combo_box, 1);
    }

	add_to_grid(font_button_grid, font_button_show_style_combo_box, 4, 1, 1, 1);

	GtkWidget *font_button_use_size_label = create_label("Use Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_use_size_label, 5, 0, 1, 1);

	GtkWidget *font_button_use_size_combo_box = create_combo_box();

	add_to_combo_box(font_button_use_size_combo_box, "TRUE");

	add_to_combo_box(font_button_use_size_combo_box, "FALSE");

    if(((fontButtonInfos *)(dataWidget->widget_data))->use_size){
        set_active_item(font_button_use_size_combo_box, 0);
    } else {
        set_active_item(font_button_use_size_combo_box, 1);
    }

	add_to_grid(font_button_grid, font_button_use_size_combo_box, 5, 1, 1, 1);

	GtkWidget *font_button_use_font_label = create_label("Use Font", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(font_button_grid, font_button_use_font_label, 6, 0, 1, 1);

	GtkWidget *font_button_use_font_combo_box = create_combo_box();

	add_to_combo_box(font_button_use_font_combo_box, "TRUE");

	add_to_combo_box(font_button_use_font_combo_box, "FALSE");

    if(((fontButtonInfos *)(dataWidget->widget_data))->use_font){
        set_active_item(font_button_use_font_combo_box, 0);
    } else {
        set_active_item(font_button_use_font_combo_box, 1);
    }

	add_to_grid(font_button_grid, font_button_use_font_combo_box, 6, 1, 1, 1);

    add_to_box(box, font_button_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Font Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    if(response == GTK_RESPONSE_OK){

        char *chaine = get_text(font_button_title_entry);

        if(strcmp(chaine, "") == 0){
            ((fontButtonInfos *)(dataWidget->widget_data))->title = NULL;
        } else {
            ((fontButtonInfos *)(dataWidget->widget_data))->title = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((fontButtonInfos *)(dataWidget->widget_data))->title, chaine);
        }

        chaine = get_text(font_button_default_font_name_entry);

        if(strcmp(chaine, "") == 0){
            ((fontButtonInfos *)(dataWidget->widget_data))->default_font_name = NULL;
        } else {
            ((fontButtonInfos *)(dataWidget->widget_data))->default_font_name = malloc(sizeof(chaine));
        }
        if(strcmp(chaine, "") != 0)
            strcpy(((fontButtonInfos *)(dataWidget->widget_data))->default_font_name, chaine);

        chaine = get_selecter_item(font_button_show_size_combo_box);
        
        if(!chaine){
            ((fontButtonInfos *)(dataWidget->widget_data))->show_size = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((fontButtonInfos *)(dataWidget->widget_data))->show_size = TRUE;
        } else {
            ((fontButtonInfos *)(dataWidget->widget_data))->show_size = FALSE;
        }

        chaine = get_selecter_item(font_button_show_style_combo_box);
        
        if(!chaine){
            ((fontButtonInfos *)(dataWidget->widget_data))->show_style = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((fontButtonInfos *)(dataWidget->widget_data))->show_style = TRUE;
        } else {
            ((fontButtonInfos *)(dataWidget->widget_data))->show_style = FALSE;
        }

        chaine = get_selecter_item(font_button_use_size_combo_box);
        
        if(!chaine){
            ((fontButtonInfos *)(dataWidget->widget_data))->use_size = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((fontButtonInfos *)(dataWidget->widget_data))->use_size = TRUE;
        } else {
            ((fontButtonInfos *)(dataWidget->widget_data))->use_size = FALSE;
        }

        chaine = get_selecter_item(font_button_use_font_combo_box);

        if(!chaine){
            ((fontButtonInfos *)(dataWidget->widget_data))->use_font = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((fontButtonInfos *)(dataWidget->widget_data))->use_size = TRUE;
        } else {
            ((fontButtonInfos *)(dataWidget->widget_data))->use_size = FALSE;
        }

        modify_font_button(dataWidget->widget, ((fontButtonInfos *)(dataWidget->widget_data)));

    } else if(response == GTK_RESPONSE_REJECT){
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

char *image_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void image_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *image_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *image_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(image_grid, image_id_label, 0, 0, 1, 1);

	GtkWidget *image_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(image_id_entry, dataWidget->information);

	add_to_grid(image_grid, image_id_entry, 0, 1, 1, 1);

	GtkWidget *image_path_label = create_label("Path", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(image_grid, image_path_label, 1, 0, 1, 1);

	GtkWidget *image_path_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

    char *chaine = ((imageInfos *)(dataWidget->widget_data))->path;
    
    if(!chaine){
        set_text(image_path_entry, "");
    } else {
        set_text(image_path_entry, chaine);
    }

	add_to_grid(image_grid, image_path_entry, 1, 1, 1, 1);

    add_to_box(box, image_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Font Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){
        char *chaine = get_text(image_path_entry);
        if(strcmp(chaine, "") == 0){
            ((imageInfos *)(dataWidget->widget_data))->path = NULL;
        } else {
            ((imageInfos *)(dataWidget->widget_data))->path = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((imageInfos *)(dataWidget->widget_data))->path, chaine);
        }

        modify_image(dataWidget->widget, (imageInfos *)(dataWidget->widget_data));
    } else  if(response == GTK_RESPONSE_REJECT){
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

char *label_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void label_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *label_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *label_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *label_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_id_label, 0, 0, 1, 1);

	GtkWidget *label_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(label_id_entry, dataWidget->information);

	add_to_grid(label_grid, label_id_entry, 0, 1, 1, 1);

	GtkWidget *label_text_label = create_label("Text", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_text_label, 1, 0, 1, 1);

	GtkWidget *label_text_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((labelInfos *)(dataWidget->widget_data))->text;

    if(!chaine){
        set_text(label_text_entry, "");
    } else {
        set_text(label_text_entry, chaine);
    }

	add_to_grid(label_grid, label_text_entry, 1, 1, 1, 1);

	GtkWidget *label_size_label = create_label("Size", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_size_label, 2, 0, 1, 1);

	GtkWidget *label_size_spin_button = create_spin_button(0, 100, 5, 0, 0, FALSE, FALSE);

    set_value_spin_button(label_size_spin_button, ((labelInfos *)(dataWidget->widget_data))->size);

	add_to_grid(label_grid, label_size_spin_button, 2, 1, 1, 1);

	GtkWidget *label_font_label = create_label("Font", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_font_label, 3, 0, 1, 1);

	GtkWidget *label_font_font_button = create_font_button("Arial", "font", TRUE, TRUE, FALSE, FALSE);

    chaine = ((labelInfos *)(dataWidget->widget_data))->font;

    set_font(label_font_font_button, chaine);

	add_to_grid(label_grid, label_font_font_button, 3, 1, 1, 1);

	GtkWidget *label_color_label = create_label("Color", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_color_label, 4, 0, 1, 1);

	GtkWidget *label_color_color_button = create_color_button("#FFFFFF", "coloring", TRUE);

    chaine = ((labelInfos *)(dataWidget->widget_data))->color;

    set_color(label_color_color_button, chaine);

	add_to_grid(label_grid, label_color_color_button, 4, 1, 1, 1);

	GtkWidget *label_background_label = create_label("Background", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_background_label, 5, 0, 1, 1);

	GtkWidget *label_background_color_button = create_color_button("#000000", "coloring", TRUE);
    
    chaine = ((labelInfos *)(dataWidget->widget_data))->background;
    
    set_color(label_background_color_button, chaine);

	add_to_grid(label_grid, label_background_color_button, 5, 1, 1, 1);

	GtkWidget *label_justify_label = create_label("Justify", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_justify_label, 6, 0, 1, 1);

	GtkWidget *label_justify_combo_box = create_combo_box();

	add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_CENTER");

	add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_LEFT");

	add_to_combo_box(label_justify_combo_box, "GTK_JUSTIFY_RIGHT");

    if(((labelInfos *)(dataWidget->widget_data))->justify == GTK_JUSTIFY_CENTER){
        set_active_item(label_justify_combo_box, 0);
    } else if (((labelInfos *)(dataWidget->widget_data))->justify == GTK_JUSTIFY_LEFT){
        set_active_item(label_justify_combo_box, 1);
    } else {
        set_active_item(label_justify_combo_box, 2);
    }

	add_to_grid(label_grid, label_justify_combo_box, 6, 1, 1, 1);

	GtkWidget *label_use_underline_label = create_label("Use Underline", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_use_underline_label, 7, 0, 1, 1);

	GtkWidget *label_use_underline_combo_box = create_combo_box();

	add_to_combo_box(label_use_underline_combo_box, "TRUE");

	add_to_combo_box(label_use_underline_combo_box, "FALSE");

    if(((labelInfos *)(dataWidget->widget_data))->underline == TRUE){
        set_active_item(label_use_underline_combo_box, 0);
    } else {
        set_active_item(label_use_underline_combo_box, 1);
    }

	add_to_grid(label_grid, label_use_underline_combo_box, 7, 1, 1, 1);

	GtkWidget *label_pango_weight_label = create_label("Pango Weight", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_pango_weight_label, 8, 0, 1, 1);

	GtkWidget *label_pango_weight_combo_box = create_combo_box();

	add_to_combo_box(label_pango_weight_combo_box, "PANGO_WEIGHT_NORMAL");

	add_to_combo_box(label_pango_weight_combo_box, "PANGO_WEIGHT_BOLD");

    if(((labelInfos *)(dataWidget->widget_data))->weight == PANGO_WEIGHT_NORMAL){
        set_active_item(label_pango_weight_combo_box, 0);
    } else {
        set_active_item(label_pango_weight_combo_box, 1);
    }

	add_to_grid(label_grid, label_pango_weight_combo_box, 8, 1, 1, 1);

	GtkWidget *label_pango_style_label = create_label("Pango Style", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_pango_style_label, 9, 0, 1, 1);

	GtkWidget *label_pango_style_combo_box = create_combo_box();

	add_to_combo_box(label_pango_style_combo_box, "PANGO_STYLE_NORMAL");

	add_to_combo_box(label_pango_style_combo_box, "PANGO_STYLE_ITALIC");

    if(((labelInfos *)(dataWidget->widget_data))->style == PANGO_STYLE_NORMAL){
        set_active_item(label_pango_style_combo_box, 0);
    } else {
        set_active_item(label_pango_style_combo_box, 1);
    }

	add_to_grid(label_grid, label_pango_style_combo_box, 9, 1, 1, 1);

	GtkWidget *label_wrap_label = create_label("Wrap", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(label_grid, label_wrap_label, 10, 0, 1, 1);

	GtkWidget *label_wrap_combo_box = create_combo_box();

	add_to_combo_box(label_wrap_combo_box, "TRUE");

	add_to_combo_box(label_wrap_combo_box, "FALSE");

    if(((labelInfos *)(dataWidget->widget_data))->wrap == TRUE){
        set_active_item(label_wrap_combo_box, 0);
    } else {
        set_active_item(label_wrap_combo_box, 1);
    }

	add_to_grid(label_grid, label_wrap_combo_box, 10, 1, 1, 1);

    add_to_box(box, label_grid, START, FALSE, FALSE , 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Label Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){
        char *chaine = get_text(label_text_entry);
        if(strcmp(chaine, "") == 0){
            ((labelInfos *)(dataWidget->widget_data))->text = NULL;
        } else{
            ((labelInfos *)(dataWidget->widget_data))->text = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((labelInfos *)(dataWidget->widget_data))->text, chaine);
        }

        ((labelInfos *)(dataWidget->widget_data))->size = get_value_spin_button(label_size_spin_button);

        chaine = get_font(label_font_font_button);
        ((labelInfos *)(dataWidget->widget_data))->font = chaine;

        chaine = get_color(label_color_color_button);
        ((labelInfos *)(dataWidget->widget_data))->color = malloc(sizeof(chaine));
        strcpy(((labelInfos *)(dataWidget->widget_data))->color, chaine);

        chaine = get_color(label_background_color_button);
        ((labelInfos *)(dataWidget->widget_data))->background = get_color(label_background_color_button);
        strcpy(((labelInfos *)(dataWidget->widget_data))->background, chaine);

        chaine = get_selecter_item(label_justify_combo_box);
        if(!chaine){
            ((labelInfos *)(dataWidget->widget_data))->justify = GTK_JUSTIFY_CENTER;
        } else if (strcmp(chaine, "GTK_JUSTIFY_CENTER") == 0){
            ((labelInfos *)(dataWidget->widget_data))->justify = GTK_JUSTIFY_CENTER;
        } else if (strcmp(chaine, "GTK_JUSTIFY_LEFT") == 0){
            ((labelInfos *)(dataWidget->widget_data))->justify = GTK_JUSTIFY_LEFT;
        } else {
            ((labelInfos *)(dataWidget->widget_data))->justify = GTK_JUSTIFY_RIGHT;
        }

        chaine = get_selecter_item(label_use_underline_combo_box);

        if(!chaine){
            ((labelInfos *)(dataWidget->widget_data))->underline = TRUE;
        } else if (strcmp(chaine , "TRUE") == 0){
            ((labelInfos *)(dataWidget->widget_data))->underline = TRUE;
        } else {
            ((labelInfos *)(dataWidget->widget_data))->underline = FALSE;
        }

        chaine = get_selecter_item(label_pango_weight_combo_box);
        
        if(!chaine){
            ((labelInfos *)(dataWidget->widget_data))->weight  = PANGO_WEIGHT_NORMAL;
        } else if(strcmp(chaine , "PANGO_WEIGHT_NORMAL") == 0){
            ((labelInfos *)(dataWidget->widget_data))->weight  = PANGO_WEIGHT_NORMAL;
        } else {
            ((labelInfos *)(dataWidget->widget_data))->weight  = PANGO_WEIGHT_BOLD;
        }

        chaine = get_selecter_item(label_pango_style_combo_box);

        if(!chaine){
            ((labelInfos *)(dataWidget->widget_data))->style = PANGO_STYLE_NORMAL;
        } else if (strcmp(chaine, "PANGO_STYLE_NORMAL") == 0){
            ((labelInfos *)(dataWidget->widget_data))->style = PANGO_STYLE_NORMAL;
        } else {
            ((labelInfos *)(dataWidget->widget_data))->style = PANGO_STYLE_ITALIC;
        }

        chaine = get_selecter_item(label_wrap_combo_box);
        if(!chaine){
            ((labelInfos *)(dataWidget->widget_data))->wrap = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((labelInfos *)(dataWidget->widget_data))->wrap = TRUE;
        } else {
            ((labelInfos *)(dataWidget->widget_data))->wrap = FALSE;
        }

        modify_label(dataWidget->widget, (labelInfos *)(dataWidget->widget_data));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *level_bar_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void level_bar_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *level_bar_grid = create_grid(7, 7, TRUE, FALSE);
    
    GtkWidget *level_bar_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_id_label, 0, 0, 1, 1);

	GtkWidget *level_bar_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(level_bar_id_entry, dataWidget->information);

	add_to_grid(level_bar_grid, level_bar_id_entry, 0, 1, 1, 1);

	GtkWidget *level_bar_min_value_label = create_label("Min Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_min_value_label, 1, 0, 1, 1);

	GtkWidget *level_bar_min_value_spin_button = create_spin_button(0, 100, 1, 0, 0, FALSE, FALSE);

    set_value_spin_button(level_bar_min_value_spin_button, ((levelBarInfos *)(dataWidget->widget_data))->min_value);

	add_to_grid(level_bar_grid, level_bar_min_value_spin_button, 1, 1, 1, 1);

	GtkWidget *level_bar_max_value_label = create_label("Max Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_max_value_label, 2, 0, 1, 1);

	GtkWidget *level_bar_max_value_spin_button = create_spin_button(0, 100, 1, 10, 0, FALSE, FALSE);

    set_value_spin_button(level_bar_max_value_spin_button, ((levelBarInfos *)(dataWidget->widget_data))->max_value);

	add_to_grid(level_bar_grid, level_bar_max_value_spin_button, 2, 1, 1, 1);

	GtkWidget *level_bar_default_value_label = create_label("Default Value", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_default_value_label, 3, 0, 1, 1);

	GtkWidget *level_bar_default_value_spin_button = create_spin_button(0, 100, 1, 50, 0, FALSE, FALSE);

    set_value_spin_button(level_bar_default_value_spin_button, ((levelBarInfos *)(dataWidget->widget_data))->default_value);

	add_to_grid(level_bar_grid, level_bar_default_value_spin_button, 3, 1, 1, 1);

	GtkWidget *level_bar_mode_label = create_label("Mode", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_mode_label, 4, 0, 1, 1);

	GtkWidget *level_bar_mode_combo_box = create_combo_box();

	add_to_combo_box(level_bar_mode_combo_box, "GTK_LEVEL_BAR_MODE_CONTINUOUS");

	add_to_combo_box(level_bar_mode_combo_box, "GTK_LEVEL_BAR_MODE_DISCRETE");

    if(((levelBarInfos *)(dataWidget->widget_data))->mode == GTK_LEVEL_BAR_MODE_CONTINUOUS){
        set_active_item(level_bar_mode_combo_box, 0);
    } else {
        set_active_item(level_bar_mode_combo_box, 1);
    }

	add_to_grid(level_bar_grid, level_bar_mode_combo_box, 4, 1, 1, 1);

	GtkWidget *level_bar_reversed_label = create_label("Reversed", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(level_bar_grid, level_bar_reversed_label, 5, 0, 1, 1);

	GtkWidget *level_bar_reversed_combo_box = create_combo_box();

	add_to_combo_box(level_bar_reversed_combo_box, "FALSE");

	add_to_combo_box(level_bar_reversed_combo_box, "TRUE");

    if(((levelBarInfos *)(dataWidget->widget_data))->inverted){
        set_active_item(level_bar_reversed_combo_box, 1);
    } else {
        set_active_item(level_bar_reversed_combo_box, 0);
    }

	add_to_grid(level_bar_grid, level_bar_reversed_combo_box, 5, 1, 1, 1);

    add_to_box(box, level_bar_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Level Bar Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){
        ((levelBarInfos *)(dataWidget->widget_data))->default_value = get_value_spin_button(level_bar_default_value_spin_button);
        ((levelBarInfos *)(dataWidget->widget_data))->min_value = get_value_spin_button(level_bar_min_value_spin_button);
        ((levelBarInfos *)(dataWidget->widget_data))->max_value = get_value_spin_button(level_bar_max_value_spin_button);

        char *chaine = get_selecter_item(level_bar_mode_combo_box);

        if(!chaine){
            ((levelBarInfos *)(dataWidget->widget_data))->mode = GTK_LEVEL_BAR_MODE_CONTINUOUS;
        } else if (strcmp(chaine, "GTK_LEVEL_BAR_MODE_CONTINUOUS") == 0){
            ((levelBarInfos *)(dataWidget->widget_data))->mode = GTK_LEVEL_BAR_MODE_CONTINUOUS;
        } else {
            ((levelBarInfos *)(dataWidget->widget_data))->mode = GTK_LEVEL_BAR_MODE_DISCRETE;
        }

        chaine = get_selecter_item(level_bar_reversed_combo_box);

        if(!chaine){
            ((levelBarInfos *)(dataWidget->widget_data))->inverted = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((levelBarInfos *)(dataWidget->widget_data))->inverted = TRUE;
        } else {
            ((levelBarInfos *)(dataWidget->widget_data))->inverted = FALSE;
        }

        modify_level_bar(dataWidget->widget, ((levelBarInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *link_button_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void link_button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *Link_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *Link_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_id_label, 0, 0, 1, 1);

	GtkWidget *Link_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(Link_button_id_entry, dataWidget->information);

	add_to_grid(Link_button_grid, Link_button_id_entry, 0, 1, 1, 1);

	GtkWidget *Link_button_url_label = create_label("URL", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_url_label, 1, 0, 1, 1);

	GtkWidget *Link_button_url_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

    char *chaine = ((linkButtonInfos *)(dataWidget->widget_data))->url;

    if(!chaine){
        set_text(Link_button_url_entry, "");
    } else {
        set_text(Link_button_url_entry, chaine);
    }

	add_to_grid(Link_button_grid, Link_button_url_entry, 1, 1, 1, 1);

	GtkWidget *Link_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(Link_button_grid, Link_button_label_label, 2, 0, 1, 1);

	GtkWidget *Link_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((linkButtonInfos *)(dataWidget->widget_data))->label;

    if(!chaine){
        set_text(Link_button_label_entry, "");
    } else {
        set_text(Link_button_label_entry, chaine);
    }

	add_to_grid(Link_button_grid, Link_button_label_entry, 2, 1, 1, 1);

    add_to_box(box, Link_button_grid,START, FALSE, FALSE,  0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Link Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){
        
        char *chaine = get_text(Link_button_label_entry);

        if(strcmp(chaine, "") == 0){
            ((linkButtonInfos *)(dataWidget->widget_data))->label = NULL;
        } else {
            ((linkButtonInfos *)(dataWidget->widget_data))->label = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((linkButtonInfos *)(dataWidget->widget_data))->label, chaine);
        }

        chaine = get_text(Link_button_url_entry);

        if(strcmp(chaine, "") == 0){
            ((linkButtonInfos *)(dataWidget->widget_data))->url = NULL;
        } else {
            ((linkButtonInfos *)(dataWidget->widget_data))->url = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((linkButtonInfos *)(dataWidget->widget_data))->url, chaine);
        }

        modify_link_button(dataWidget->widget, ((linkButtonInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *menu_button_container_properties(char *parent_id, GtkWidget *obj){

    GtkWidget *dialog = create_dialog("Make sure that you are adding a menu to a menu button", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                            yes                                                            ", 1, "No!", 2, NULL, 1);
    int response = run_dialog(dialog);

    if(response == 1){

        TreeNodeData *dataWidget = search_tree(global_tree, parent_id);
        char *closing_tag;

        add_to_menu_button(dataWidget->widget, obj);
    
        closing_tag = malloc(100 * sizeof(char));
        if(!closing_tag) return NULL;
    
        sprintf(closing_tag, "</%s add_to_menu_button(%s, %s)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget);
        destroy_widget(dialog);
    
        return closing_tag;
    }

    destroy_widget(dialog);
    return NULL;
}

void menu_button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *menu_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_button_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_id_label, 0, 0, 1, 1);

	GtkWidget *menu_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);
    
    set_text(menu_button_id_entry, dataWidget->information);

	add_to_grid(menu_button_grid, menu_button_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_label_label, 1, 0, 1, 1);

	GtkWidget *menu_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((menuButtonInfos *)(dataWidget->widget_data))->label;

    if(!chaine){
        set_text(menu_button_label_entry, "");
    } else {
        set_text(menu_button_label_entry, chaine);
    }

	add_to_grid(menu_button_grid, menu_button_label_entry, 1, 1, 1, 1);

	GtkWidget *menu_button_path_to_image_label = create_label("Path to image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_path_to_image_label, 2, 0, 1, 1);

	GtkWidget *menu_button_path_to_image_entry = create_entry(NULL, "Chose image or lable", TRUE, TRUE, 20, 0.5);

    chaine = ((menuButtonInfos *)(dataWidget->widget_data))->path_to_image;

    if(!chaine){
        set_text(menu_button_path_to_image_entry, "");
    } else {
        set_text(menu_button_path_to_image_entry, chaine);
    }

	add_to_grid(menu_button_grid, menu_button_path_to_image_entry, 2, 1, 1, 1);

	GtkWidget *menu_button_arrow_type_label = create_label("Arrow type", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_button_grid, menu_button_arrow_type_label, 3, 0, 1, 1);

	GtkWidget *menu_button_arrow_type_combo_box = create_combo_box();

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_DOWN");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_UP");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_LEFT");

	add_to_combo_box(menu_button_arrow_type_combo_box, "GTK_ARROW_RIGHT");

    if(((menuButtonInfos *)(dataWidget->widget_data))->arrow_type == GTK_ARROW_DOWN){
        gtk_combo_box_set_active(GTK_COMBO_BOX(menu_button_arrow_type_combo_box), 0);
    } else if (((menuButtonInfos *)(dataWidget->widget_data))->arrow_type == GTK_ARROW_UP){
        gtk_combo_box_set_active(GTK_COMBO_BOX(menu_button_arrow_type_combo_box), 1);
    } else if (((menuButtonInfos *)(dataWidget->widget_data))->arrow_type == GTK_ARROW_LEFT){
        gtk_combo_box_set_active(GTK_COMBO_BOX(menu_button_arrow_type_combo_box), 2);
    } else {
        gtk_combo_box_set_active(GTK_COMBO_BOX(menu_button_arrow_type_combo_box), 3);
    }

	add_to_grid(menu_button_grid, menu_button_arrow_type_combo_box, 3, 1, 1, 1);

    add_to_box(box, menu_button_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Link Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){

        char *chaine = get_text(menu_button_label_entry);

        if(strcmp(chaine, "") == 0){
            ((menuButtonInfos *)(dataWidget->widget_data))->label = NULL;
        } else {
            ((menuButtonInfos *)(dataWidget->widget_data))->label = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((menuButtonInfos *)(dataWidget->widget_data))->label, chaine);
        }

        chaine = get_text(menu_button_path_to_image_entry);

        if(strcmp(chaine, "") == 0){
            ((menuButtonInfos *)(dataWidget->widget_data))->path_to_image = NULL;
        } else {
            ((menuButtonInfos *)(dataWidget->widget_data))->path_to_image = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((menuButtonInfos *)(dataWidget->widget_data))->path_to_image, chaine);
        }

        chaine = get_selecter_item(menu_button_arrow_type_combo_box);

        if(!chaine){
            ((menuButtonInfos *)(dataWidget->widget_data))->arrow_type = GTK_ARROW_DOWN;
        } else if (strcmp(chaine, "GTK_ARROW_DOWN") == 0){
            ((menuButtonInfos *)(dataWidget->widget_data))->arrow_type = GTK_ARROW_DOWN;
        } else if (strcmp(chaine, "GTK_ARROW_UP") == 0){
            ((menuButtonInfos *)(dataWidget->widget_data))->arrow_type = GTK_ARROW_UP;
        } else if (strcmp(chaine, "GTK_ARROW_LEFT") == 0){
            ((menuButtonInfos *)(dataWidget->widget_data))->arrow_type = GTK_ARROW_LEFT;
        } else {
            ((menuButtonInfos *)(dataWidget->widget_data))->arrow_type = GTK_ARROW_RIGHT;
        }

        modify_menu_button(dataWidget->widget, ((menuButtonInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *menu_container_properties(char *parent_id, GtkWidget *obj){

    GtkWidget *dialog = create_dialog("Make sure that you are adding a menu item to a menu", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                            yes                                                            ", 1, "No!", 2, NULL, 1);
    int response = run_dialog(dialog);

    if(response == 1){
        
        TreeNodeData *dataWidget = search_tree(global_tree, parent_id);
        char *closing_tag;


        add_to_menu(dataWidget->widget, obj);

    
        closing_tag = malloc(100 * sizeof(char));
        if(!closing_tag) return NULL;
    

        sprintf(closing_tag, "</%s add_to_menu(%s, %s)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget);
        destroy_widget(dialog);
    
        return closing_tag;
    }

    destroy_widget(dialog);
    return NULL;
}

void menu_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *menu_grid_frame = create_frame(NULL, 0.5, 0.5);

	GtkWidget *menu_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_id_label, 0, 0, 1, 1);

	GtkWidget *menu_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(menu_id_entry, dataWidget->information);

	add_to_grid(menu_grid, menu_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_is_primary_label = create_label("Is Primary", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_is_primary_label, 1, 0, 1, 1);

	GtkWidget *menu_is_primary_combo_box = create_combo_box();

	add_to_combo_box(menu_is_primary_combo_box, "TRUE");

	add_to_combo_box(menu_is_primary_combo_box, "FALSE");

    if(((menuInfos *)(dataWidget->widget_data))->is_primary){
        set_active_item(menu_is_primary_combo_box, 0);
    } else {
        set_active_item(menu_is_primary_combo_box, 1);
    }

	add_to_grid(menu_grid, menu_is_primary_combo_box, 1, 1, 1, 1);

	GtkWidget *menu_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_grid, menu_label_label, 2, 0, 1, 1);

	GtkWidget *menu_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((menuInfos *)(dataWidget->widget_data))->label;

    if(!chaine){
        set_text(menu_label_entry, "");
    } else {
        set_text(menu_label_entry, chaine);
    }

	add_to_grid(menu_grid, menu_label_entry, 2, 1, 1, 1);

    add_to_box(box, menu_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Menu Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){

        char *chaine = get_selecter_item(menu_is_primary_combo_box);

        if(!chaine){
            ((menuInfos *)(dataWidget->widget_data))->is_primary = TRUE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((menuInfos *)(dataWidget->widget_data))->is_primary = TRUE;
        } else {
            ((menuInfos *)(dataWidget->widget_data))->is_primary = FALSE;
        }

        chaine = get_text(menu_label_entry);

        if(strcmp(chaine, "") == 0){
            ((menuInfos *)(dataWidget->widget_data))->label = NULL;
        } else {
            ((menuInfos *)(dataWidget->widget_data))->label = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((menuInfos *)(dataWidget->widget_data))->label, chaine);
        }

        modify_menu(dataWidget->widget, ((menuInfos *)(dataWidget->widget_data)));
    } else if(response == GTK_RESPONSE_REJECT){
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

char *menu_item_container_properties(char *parent_id, GtkWidget *obj){

    GtkWidget *dialog = create_dialog("Make sure that you are adding a submenu to a menu item", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                            yes                                                            ", 1, "No!", 2, NULL, 1);
    int response = run_dialog(dialog);

    if(response == 1){

        TreeNodeData *dataWidget = search_tree(global_tree, parent_id);
        char *closing_tag;

        add_to_menu_item(dataWidget->widget, obj);
    
        closing_tag = malloc(100 * sizeof(char));
        if(!closing_tag) return NULL;
    
        sprintf(closing_tag, "</%s add_to_menu_item(%s, %s)>", global_widget_data_pointer->widget_name, parent_id, global_widget_data_pointer->id_widget);
        destroy_widget(dialog);
    
        return closing_tag;
    }

    destroy_widget(dialog);
    return NULL;

}

void menu_item_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *menu_item_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *menu_item_id_label = create_label("Widget ID", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_id_label, 0, 0, 1, 1);

	GtkWidget *menu_item_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(menu_item_id_entry, dataWidget->information);

	add_to_grid(menu_item_grid, menu_item_id_entry, 0, 1, 1, 1);

	GtkWidget *menu_item_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_label_label, 1, 0, 1, 1);

	GtkWidget *menu_item_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((menuItemInfos *)(dataWidget->widget_data))->label;

    if(!chaine){
        set_text(menu_item_label_entry, "");
    } else {
        set_text(menu_item_label_entry, chaine);
    }

	add_to_grid(menu_item_grid, menu_item_label_entry, 1, 1, 1, 1);


	GtkWidget *menu_item_callback_label = create_label("Callback", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_callback_label, 2, 0, 1, 1);

	GtkWidget *menu_item_callback_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((menuItemInfos *)(dataWidget->widget_data))->callback_name;

    if(!chaine){
        set_text(menu_item_callback_entry, "");
    } else {
        set_text(menu_item_callback_entry, chaine);
    }

	add_to_grid(menu_item_grid, menu_item_callback_entry, 2, 1, 1, 1);

	GtkWidget *menu_item_data_label = create_label("Data", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(menu_item_grid, menu_item_data_label, 3, 0, 1, 1);

	GtkWidget *menu_item_data_entry = create_entry(NULL, NULL, TRUE, TRUE, 200, 0.5);

    chaine = ((menuItemInfos *)(dataWidget->widget_data))->data_name;

    if(!chaine){
        set_text(menu_item_data_entry, "");
    } else {
        set_text(menu_item_data_entry, chaine);
    }

	add_to_grid(menu_item_grid, menu_item_data_entry, 3, 1, 1, 1);

    add_to_box(box, menu_item_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Menu Item Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){

        chaine = get_text(menu_item_label_entry);

        if(strcmp(chaine, "") == 0){
            ((menuItemInfos *)(dataWidget->widget_data))->label = NULL;
        } else {
            ((menuItemInfos *)(dataWidget->widget_data))->label = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((menuItemInfos *)(dataWidget->widget_data))->label, chaine);
        }

        chaine = get_text(menu_item_callback_entry);

        if(strcmp(chaine, "") == 0){
            ((menuItemInfos *)(dataWidget->widget_data))->callback_name = NULL;
        } else {
            ((menuItemInfos *)(dataWidget->widget_data))->callback_name = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((menuItemInfos *)(dataWidget->widget_data))->callback_name, chaine);
        }

        chaine = get_text(menu_item_data_entry);

        if(strcmp(chaine, "") == 0){
            ((menuItemInfos *)(dataWidget->widget_data))->data_name = NULL;
        } else {
            ((menuItemInfos *)(dataWidget->widget_data))->data_name = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((menuItemInfos *)(dataWidget->widget_data))->data_name, chaine);
        }

        modify_menu_item(dataWidget->widget, ((menuItemInfos *)(dataWidget->widget_data)));

    } else if(response == GTK_RESPONSE_REJECT){
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

char *radio_button_container_properties(char *parent_id, GtkWidget *obj){
    GtkWidget *dialog = create_dialog("Your cannot add widgets to a no container widget!!!", NULL, GTK_DIALOG_MODAL, 300, 30, 1, NULL, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
    run_dialog(dialog);
    destroy_widget(dialog);
}

void radio_button_widget_properties(){

    TreeNodeData *dataWidget = search_tree(global_tree, get_selected_node_id(GTK_TREE_VIEW(global_tree)));

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *radio_button_grid = create_grid(7, 7, TRUE, FALSE);

	GtkWidget *radio_button_id_label = create_label("Widget Id", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_id_label, 0, 0, 1, 1);

	GtkWidget *radio_button_id_entry = create_entry(NULL, "must be unique and no space", TRUE, FALSE, 20, 0.5);

    set_text(radio_button_id_entry, dataWidget->information);

	add_to_grid(radio_button_grid, radio_button_id_entry, 0, 1, 1, 1);

	GtkWidget *radio_button_label_label = create_label("Label", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_label_label, 1, 0, 1, 1);

	GtkWidget *radio_button_label_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    char *chaine = ((radioButtonInfos *)(dataWidget->widget_data))->label;

    if(!chaine){
        set_text(radio_button_label_entry, "");
    } else {
        set_text(radio_button_label_entry, chaine);
    }

	add_to_grid(radio_button_grid, radio_button_label_entry, 1, 1, 1, 1);

	GtkWidget *radio_button_path_image_label = create_label("Path Image", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_path_image_label, 2, 0, 1, 1);

	GtkWidget *radio_button_path_image_entry = create_entry(NULL, "if you chose label let this NULL", TRUE, TRUE, 20, 0.5);

    chaine = ((radioButtonInfos *)(dataWidget->widget_data))->path_to_image;

    if(!chaine){
        set_text(radio_button_path_image_entry, "");
    } else {
        set_text(radio_button_path_image_entry, chaine);
    }

	add_to_grid(radio_button_grid, radio_button_path_image_entry, 2, 1, 1, 1);

	GtkWidget *radio_button_id_radio_group_member_label = create_label("Id Radio Group Member", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_id_radio_group_member_label, 3, 0, 1, 1);

	GtkWidget *radio_button_id_radio_group_member_entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);

    chaine = ((radioButtonInfos *)(dataWidget->widget_data))->radio_group_member_name;

    if(!chaine){
        set_text(radio_button_id_radio_group_member_entry, "");
    } else {
        set_text(radio_button_id_radio_group_member_entry, chaine);
    }

	add_to_grid(radio_button_grid, radio_button_id_radio_group_member_entry, 3, 1, 1, 1);

	GtkWidget *radio_button_default_state_label = create_label("Default State", 12, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_LEFT, FALSE, 0, 0, TRUE);

	add_to_grid(radio_button_grid, radio_button_default_state_label, 4, 0, 1, 1);

	GtkWidget *radio_button_default_state_combo_box = create_combo_box();

	add_to_combo_box(radio_button_default_state_combo_box, "FALSE");

	add_to_combo_box(radio_button_default_state_combo_box, "TRUE");

    if(((radioButtonInfos *)(dataWidget->widget_data))->default_state == TRUE){
        set_active_item(radio_button_default_state_combo_box, 1);
    } else {
        set_active_item(radio_button_default_state_combo_box, 0);
    }

	add_to_grid(radio_button_grid, radio_button_default_state_combo_box, 4, 1, 1, 1);

    add_to_box(box, radio_button_grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Radio Button Properties", NULL, GTK_DIALOG_MODAL, 30, 30, 1, box, "OK", GTK_RESPONSE_OK, "Annuler", GTK_RESPONSE_CANCEL, "Supprimer", GTK_RESPONSE_REJECT);
    gint response = run_dialog(dialog);

    
    if(response == GTK_RESPONSE_OK){

        char *chaine = get_text(radio_button_label_entry);
        
        if(strcmp(chaine, "") == 0){
            ((radioButtonInfos *)(dataWidget->widget_data))->label = NULL;
        } else {
            ((radioButtonInfos *)(dataWidget->widget_data))->label = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((radioButtonInfos *)(dataWidget->widget_data))->label, chaine);
        }

        chaine = get_text(radio_button_path_image_entry);

        if(strcmp(chaine, "") == 0){
            ((radioButtonInfos *)(dataWidget->widget_data))->path_to_image = NULL;
        } else {
            ((radioButtonInfos *)(dataWidget->widget_data))->path_to_image = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((radioButtonInfos *)(dataWidget->widget_data))->path_to_image, chaine);
        }

        chaine = get_text(radio_button_id_radio_group_member_entry);

        if(strcmp(chaine, "") == 0){
            ((radioButtonInfos *)(dataWidget->widget_data))->radio_group_member_name = NULL;
        } else {
            ((radioButtonInfos *)(dataWidget->widget_data))->radio_group_member_name = malloc(sizeof(chaine));
        }

        if(strcmp(chaine, "") != 0){
            strcpy(((radioButtonInfos *)(dataWidget->widget_data))->radio_group_member_name, chaine);
        }

        chaine = get_selecter_item(radio_button_default_state_combo_box);
        if(!chaine){
            ((radioButtonInfos *)(dataWidget->widget_data))->default_state = FALSE;
        } else if (strcmp(chaine, "TRUE") == 0){
            ((radioButtonInfos *)(dataWidget->widget_data))->default_state = TRUE;
        } else {
            ((radioButtonInfos *)(dataWidget->widget_data))->default_state = FALSE;
        }


        modify_radio_button(dataWidget->widget, ((radioButtonInfos *)(dataWidget->widget_data)), global_tree);
    }

    else if(response == GTK_RESPONSE_REJECT){
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