/*****************************************************************************************************************************
 * 
 * @file header_bar.h
 * @brief header file for creating header bar with its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK header bar with its properties.
 * 
 * 
 * @note it is preferable to add a window top level widget to the header bar
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 1.0 (last update 26/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef HEADER_BAR_H
#define HEADER_BAR_H

#include <gtk/gtk.h>
#include "../../data_structres_includes.h"

/**
 * @struct headerBarInfos
 * @brief the header bar properties
 */

typedef struct
{
    const gchar *title;
    const gchar *subtitle;
    const gchar *icon_path;
    gboolean settings;
    LinkedList *start_widgets_liste;
    LinkedList *end_widgets_liste;
}headerBarInfos;

typedef enum
{
    LEFT,
    RIGHT
}HeaderBarPosition;


/**
 * @brief create a header bar with its properties
 * 
 * @param infos the header bar properties
 * @return a header bar
 */

GtkWidget *create_header_bar(const gchar *title, const gchar *subtitle, const gchar *icon_path, gboolean settings);

/**
 * @brief set the properties of the header bar
 * 
 * @param infos the header bar properties
 * @return a header bar
 */

GtkWidget *set_properties_header_bar(headerBarInfos *headerBarInformations);

/**
 * @brief get the properties of the header bar
 * 
 * @param headerBar the header bar
 * @return headerBarInfos* the informations of the header bar
 */

headerBarInfos *get_properties_header_bar(GtkWidget *headerBar);

void add_to_header_bar(GtkWidget *header_bar, GtkWidget *widget, HeaderBarPosition LEFT_OR_RIGHT);

#endif // HEADER_BAR_H