/*****************************************************************************************************************************
 * 
 * @file switcher.c
 * @brief the implementation of the functions in switcher.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/containers/switcher.h"

GtkWidget *create_switcher(gint spacing, gboolean buttons_same_size)
{
    switcherInfos *switcherInformations = (switcherInfos *)malloc(sizeof(switcherInfos));
    if(!switcherInformations) return NULL;

    switcherInformations->spacing = spacing;
    switcherInformations->buttons_same_size = buttons_same_size;

    GtkWidget *switcher = set_properties_switcher(switcherInformations);

    free(switcherInformations);
    return switcher;
}

GtkWidget *set_properties_switcher(switcherInfos *switcherInformations)
{
    GtkWidget *switcher = gtk_stack_switcher_new();

    gtk_box_set_spacing(GTK_BOX(switcher), switcherInformations->spacing);
    gtk_box_set_homogeneous(GTK_BOX(switcher), switcherInformations->buttons_same_size);

    return switcher;
}

switcherInfos *get_properties_switcher(GtkWidget *switcher)
{
    switcherInfos *switcherInformations = (switcherInfos *)malloc(sizeof(switcherInfos));
    if(!switcherInformations) return NULL;

    switcherInformations->spacing = gtk_box_get_spacing(GTK_BOX(switcher));
    switcherInformations->buttons_same_size = gtk_box_get_homogeneous(GTK_BOX(switcher));

    return switcherInformations;
}

