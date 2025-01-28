/*****************************************************************************************************************************
 * 
 * @file paned.h
 * @brief the header file of the paned container
 * 
 * this file contains all the functions declarations and structures used in the paned container
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef PANED_H
#define PANED_H

#include <gtk/gtk.h>

/**
 * @struct panedInfos
 * @brief the paned properties
 */

typedef struct {
    GtkOrientation orientation;
    gint default_position;
    gboolean show_handle;
} panedInfos;

/**
 * @enum FIRST_OR_SECOND
 * @brief the first or second widget of the paned container
 */

typedef enum
{
    FIRST,
    SECOND
}FIRST_OR_SECOND;

/**
 * @brief create a paned container
 * 
 * @param orientation the orientation of the paned container
 * @param default_position the default position of the paned container
 * @param show_handle show the handle of the paned container
 * 
 * @return GtkWidget* the paned container
 */

GtkWidget *create_paned(GtkOrientation orientation, gint default_position, gboolean show_handle);

/**
 * @brief set the properties of the paned container
 * 
 * @param panedInformation the informations of the paned container
 * 
 * @return GtkWidget* the paned container
 */

GtkWidget *set_properties_paned(panedInfos *panedInformation);

/**
 * @brief get the properties of the paned container
 * 
 * @param paned the paned container
 * 
 * @return panedInfos* the informations of the paned container
 */

panedInfos *get_properties_paned(GtkWidget *paned);


void add_to_paned(GtkWidget *paned, GtkWidget *widget, FIRST_OR_SECOND first_or_second);

#endif // PANED_H