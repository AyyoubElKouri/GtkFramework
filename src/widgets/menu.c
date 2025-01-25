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

#include "../../headers/widgets/menu.h"

static gboolean Gis_primary;
static LinkedList *Gitems;
static gchar *Glabel;

GtkWidget *create_menu(gboolean is_primary, const gchar *label, LinkedList *items)
{
    menuInfos *menuInformation = (menuInfos *)malloc(sizeof(menuInfos));
    if(!menuInformation) return NULL;

    menuInformation->is_primary = is_primary;
    Gis_primary = is_primary;
    menuInformation->label = g_strdup(label);
    Glabel = g_strdup(label);
    menuInformation->items = items;
    Gitems = items;

    GtkWidget *menu = set_properties_menu(menuInformation);
    free(menuInformation);

    return menu;
}

GtkWidget *set_properties_menu(menuInfos *menuInformation)
{
    // create the menu
    GtkWidget *menu = gtk_menu_new();

    // set the items
    Node *current = menuInformation->items->head;
    while(current)
    {
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), current->widget);
        current = current->next;
    }

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
    menuInformation->items = Gitems;

    return menuInformation;
}