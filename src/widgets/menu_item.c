/*****************************************************************************************************************************
 * 
 * @file menu_item.c
 * @brief the implementation of the functions in menu_item.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/menu_item.h"
#include <string.h>

static GCallback Gcallback;
static gpointer Gdata;

GtkWidget *create_menu_item(const gchar *label, const gchar *type, GtkWidget *submenu, GCallback callback, gpointer data)
{
    menuItemInfos *menuItemInformation = (menuItemInfos *)malloc(sizeof(menuItemInfos));
    if(!menuItemInformation) return NULL;

    menuItemInformation->label = g_strdup(label);
    menuItemInformation->type = g_strdup(type);
    menuItemInformation->submenu = submenu;
    menuItemInformation->callback = callback;
    Gcallback = callback;
    menuItemInformation->data = data;
    Gdata = data;

    GtkWidget *menuItem = set_properties_item(menuItemInformation);
    free(menuItemInformation);

    return menuItem;
}

GtkWidget *set_properties_item(menuItemInfos *menuItemInformation)
{
    GtkWidget *menuItem;

    // check the type of the menu item
    if(strcmp(menuItemInformation->type, "normal") == 0)
        menuItem = gtk_menu_item_new_with_label(menuItemInformation->label);
    else if(strcmp(menuItemInformation->type, "separator") == 0)
        menuItem = gtk_separator_menu_item_new();
    else if(strcmp(menuItemInformation->type, "check") == 0)
        menuItem = gtk_check_menu_item_new_with_label(menuItemInformation->label);
    else if(strcmp(menuItemInformation->type, "radio") == 0)
        menuItem = gtk_radio_menu_item_new_with_label(NULL, menuItemInformation->label);
    else
        menuItem = NULL;

    // set the submenu
    if(menuItemInformation->submenu)
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuItem), menuItemInformation->submenu);
    
    // set the callback
    if(menuItemInformation->callback)
        g_signal_connect(menuItem, "activate", menuItemInformation->callback, menuItemInformation->data);

    return menuItem;
}

menuItemInfos *get_properties_menuItem(GtkWidget *menuItem)
{
    menuItemInfos *menuItemInformation = (menuItemInfos *)malloc(sizeof(menuItemInfos));
    if(!menuItemInformation) return NULL;

    // get the label
    menuItemInformation->label = gtk_menu_item_get_label(GTK_MENU_ITEM(menuItem));

    // get the type
    if(GTK_IS_MENU_ITEM(menuItem))
        menuItemInformation->type = g_strdup("normal") ;
    else if(GTK_IS_SEPARATOR_MENU_ITEM(menuItem))
        menuItemInformation->type = g_strdup("separator") ;
    else if(GTK_IS_CHECK_MENU_ITEM(menuItem))
        menuItemInformation->type = g_strdup("check") ;
    else if(GTK_IS_RADIO_MENU_ITEM(menuItem))
        menuItemInformation->type = g_strdup("radio") ;
    else
        menuItemInformation->type = NULL;
    
    // get the submenu
    menuItemInformation->submenu = gtk_menu_item_get_submenu(GTK_MENU_ITEM(menuItem));

    // get the callback
    menuItemInformation->callback = Gcallback;
    menuItemInformation->data = Gdata;

    return menuItemInformation;
}