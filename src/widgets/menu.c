/*****************************************************************************************************************************
 * 
 * @file menu.c
 * @brief the implementation of the functions in menu.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/menu.h"

static gboolean Gis_primary;
static gchar *Glabel;

GtkWidget *create_menu(gboolean is_primary, const gchar *label)
{
    menuInfos *menuInformation = (menuInfos *)malloc(sizeof(menuInfos));
    if(!menuInformation) return NULL;

    menuInformation->is_primary = is_primary;
    Gis_primary = is_primary;
    menuInformation->label = g_strdup(label);
    Glabel = g_strdup(label);

    GtkWidget *menu = set_properties_menu(menuInformation);
    free(menuInformation);

    return menu;
}

GtkWidget *set_properties_menu(menuInfos *menuInformation)
{
    // create the menu
    GtkWidget *menu = gtk_menu_new();

    if(menuInformation->is_primary)
        gtk_widget_show_all(menu);
    
    return menu;
}

menuInfos *get_properties_menu(GtkWidget *menu)
{
    menuInfos *menuInformation = (menuInfos *)malloc(sizeof(menuInfos));
    if(!menuInformation) return NULL;

    menuInformation->is_primary = Gis_primary;
    menuInformation->label = g_strdup(Glabel);

    return menuInformation;
}

void add_to_menu(GtkWidget *menu, GtkWidget *menu_item)
{
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
}