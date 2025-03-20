/*****************************************************************************************************************************
 * 
 * @file combo_box.c
 * @brief the implementation of the functions in combo_box.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 07/02/2025
 * @version 1.0 (last update 07/02/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/combo_box.h"
#include "../../include/widgets/tree_view.h"

GtkWidget *create_combo_box()
{
    GtkWidget *combo_box = gtk_combo_box_text_new();
    return combo_box;
}


void add_to_combo_box(GtkWidget *combo_box, const gchar *item)
{
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), item);
}

void remove_from_combo_box(GtkWidget *combo_box, int index){
    gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(combo_box), index);
}

char *get_selecter_item(GtkWidget *combo_box){
    char* text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo_box));
    return text;
}

void set_active_item(GtkWidget *combo_box, gint index){
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), index);
}