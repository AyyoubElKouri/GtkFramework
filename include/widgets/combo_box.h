/*****************************************************************************************************************************
 * 
 * @file Combo_box.h
 * @brief the header file of the Combo box widget
 * 
 * this file contains all the functions declarations and structures used in the Combo box widget
 * 
 * @author Ayyoub el Kouri
 * @date 07/02/2025
 * @version 1.0 (last update 07/02/2025)
 * 
 ****************************************************************************************************************************/

#ifndef COMBO_BOX_H
#define COMBO_BOX_H

#include <gtk/gtk.h>


/**
 * @brief This function creates a combo box widget.
 * 
 * @param title The title of the combo box.
 * @return GtkWidget* A pointer to the created combo box widget.
 */

GtkWidget *create_combo_box();


/**
 * @brief This function adds an item to a combo box widget.
 * 
 * @param combo_box The combo box widget to add the item to.
 * @param item The item to add to the combo box.
 */

void add_to_combo_box(GtkWidget *combo_box, const gchar *item);

char *get_selecter_item(GtkWidget *combo_box);

void set_active_item(GtkWidget *combo_box, gint index);
#endif // COMBO_BOX_H