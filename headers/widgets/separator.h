/*****************************************************************************************************************************
 * 
 * @file separator.h
 * @brief header file for creating separator and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK separator with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SEPARATOR_H
#define SEPARATOR_H

#include <gtk/gtk.h>

/**
 * @struct separatorInfos
 * @brief the separator properties
 */

typedef struct
{
    GtkOrientation orientation;
}separatorInfos;

/**
 * @brief This function sets the information in one structure and creates a separator with this information.
 * 
 * @param orientation The orientation of the separator.
 * 
 * @return GtkWidget* A pointer to the created separator.
 */

GtkWidget *create_separator(GtkOrientation orientation);

/**
 * @brief set the properties of the separator
 * 
 * this function sets the properties of the separator
 * 
 * @param separatorInformation the informations of the separator
 * 
 * @return GtkWidget* the separator
 */

GtkWidget *set_properties_separator(separatorInfos *separatorInformation);

/**
 * @brief get the properties of the separator
 * 
 * this function gets the properties of the separator
 * 
 * @param separator the separator
 * 
 * @return separatorInfos* the informations of the separator
 */

separatorInfos *get_properties_separator(GtkWidget *separator);

#endif // SEPARATOR_H