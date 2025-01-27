
/*****************************************************************************************************************************
 * 
 * @file menu_item.h
 * @brief header file for creating menu item and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK menu item with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/
#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <gtk/gtk.h>


/**
 * @struct menuItemInfos
 * @brief the menu item properties
 */

typedef struct
{
    const gchar *label;
    const gchar *type;
    GtkWidget *submenu;
    GCallback callback;
    gpointer data;
}menuItemInfos;

/**
 * @brief This function creates the menu item and sets its properties.
 * 
 * @param label The label of the menu item
 * @param type The type of the menu item
 * @param submenu The submenu of the menu item
 * @param callback The callback of the menu item
 * @param data The data of the menu item
 * 
 * @return GtkWidget pointer to the menu item
 */

GtkWidget *create_menu_item(const gchar *label, const gchar *type, GtkWidget *submenu, GCallback callback, gpointer data);

/**
 * @brief This function sets the information in one structure and creates a menu item with this information
 * 
 * @param menuItemInformation The properties of the menu item
 * 
 * @return GtkWidget pointer to the menu item
 */

GtkWidget *set_properties_item(menuItemInfos *menuItemInformation);

/**
 * @brief This function gets the properties of the menu item
 * 
 * @param menuItem The menu item
 * 
 * @return menuItemInfos The properties of the menu item
 */

menuItemInfos *get_properties_menuItem(GtkWidget *menuItem);

#endif