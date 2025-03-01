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

GtkWidget *create_combo_box()
{
    GtkWidget *combo_box = gtk_combo_box_text_new();
    return combo_box;
}

void add_to_combo_box(GtkWidget *combo_box, const gchar *item)
{
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), item);
}

char *get_selecter_item(GtkWidget *combo_box){
    char* text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo_box));
    return text;
}
