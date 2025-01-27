/*****************************************************************************************************************************
 * 
 * @file link_button.c
 * @brief header file for creating link button and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK link button with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef LINK_BUTTON_H
#define LINK_BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct linkButtonInfos
 * @brief the link button properties
 */

typedef struct
{
    const gchar *uri;
    const gchar *label;
}linkButtonInfos;

/**
 * @brief This function sets the information in one structure and creates a link button with this information.
 * 
 * @param uri The uri of the link button.
 * @param label The label of the link button.
 * 
 * @return GtkWidget* A pointer to the created link button.
 */

GtkWidget *create_link_button(const gchar *uri, const gchar *label);

/**
 * @brief set the properties of the link button
 * 
 * this function sets the properties of the link button
 * 
 * @param linkButtonInformation the informations of the link button
 * 
 * @return GtkWidget* the link button
 */

GtkWidget *set_properties_link_button(linkButtonInfos *linkButtonInformation);

/**
 * @brief get the properties of the link button
 * 
 * this function gets the properties of the link button
 * 
 * @param linkButton the link button
 * 
 * @return linkButtonInfos* the informations of the link button
 */

linkButtonInfos *get_properties_link_button(GtkWidget *linkButton);

#endif // LINK_BUTTON_H