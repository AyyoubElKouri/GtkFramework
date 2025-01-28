/*****************************************************************************************************************************
 * 
 * @file paned.c
 * @brief the source file of the paned container
 * 
 * this file contains all implementations for the paned container functions
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#include "../../include/containers/paned.h"

static GtkOrientation Gorientation;

GtkWidget *create_paned(GtkOrientation orientation, gint default_position, gboolean show_handle)
{
    panedInfos *panedInformations = (panedInfos *)malloc(sizeof(panedInfos));
    if(!panedInformations) return NULL;

    panedInformations->orientation = orientation;
    Gorientation = orientation;
    panedInformations->default_position = default_position;
    panedInformations->show_handle = show_handle;

    GtkWidget *paned = set_properties_paned(panedInformations);

    free(panedInformations);

    return paned;
}

GtkWidget *set_properties_paned(panedInfos *panedInformations)
{
    GtkWidget *paned = gtk_paned_new(panedInformations->orientation);

    // set the default position
    if(panedInformations->default_position != -1)
        gtk_paned_set_position(GTK_PANED(paned), panedInformations->default_position);

    // set the show handle
    gtk_paned_set_wide_handle(GTK_PANED(paned), panedInformations->show_handle);

    return paned;
}

panedInfos *get_properties_paned(GtkWidget *paned)
{
    panedInfos *panedInformations = (panedInfos *)malloc(sizeof(panedInfos));
    if(!panedInformations) return NULL;

    panedInformations->orientation = Gorientation;
    panedInformations->default_position = gtk_paned_get_position(GTK_PANED(paned));
    panedInformations->show_handle = gtk_paned_get_wide_handle(GTK_PANED(paned));

    return panedInformations;
}

void add_to_paned(GtkWidget *paned, GtkWidget *widget, FIRST_OR_SECOND first_or_second)
{
    if(first_or_second == FIRST)
        gtk_paned_add1(GTK_PANED(paned), widget);
    else
        gtk_paned_add2(GTK_PANED(paned), widget);
}