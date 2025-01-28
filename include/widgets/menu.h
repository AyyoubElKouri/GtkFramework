/*****************************************************************************************************************************
 * 
 * @file menu.h
 * @brief header file for creating menu and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK menu with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef MENU_H
#define MENU_H

#include <gtk/gtk.h>
#include "../../data_structres_includes.h"

/**
 * @struct menuInfos
 * @brief the menu properties
 */

typedef struct
{
    gboolean is_primary;
    const gchar *label;
    LinkedList *items;
}menuInfos;

/**
 * @brief creates a menu
 * 
 * @param attached_to the widget to attach the menu to
 * @param items the items of the menu
 * 
 * @return the created menu
 */

GtkWidget *create_menu(gboolean is_primary, const gchar *label);

/**
 * @brief sets the properties of the menu
 * 
 * @param menuInformation the properties of the menu
 * 
 * @return the created menu
 */

GtkWidget *set_properties_menu(menuInfos *menuInformation);

/**
 * @brief gets the properties of the menu
 * 
 * @param menu the menu
 * 
 * @return the properties of the menu
 */

menuInfos *get_properties_menu(GtkWidget *menu);

/**
 * @brief adds an item to the menu
 * 
 * @param menu the menu
 * @param menu_item the item to add
 */

void add_to_menu(GtkWidget *menu, GtkWidget *menu_item);

#endif // MENU_H