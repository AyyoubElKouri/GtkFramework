/*****************************************************************************************************************************
 * 
 * @file menu_button.h
 * @brief header file for creating menu button and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK menu button with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct menuButtonInfos
 * @brief the menu button properties
 */

typedef struct 
{
    const gchar *label;
    const gchar *path_to_image;
    GtkArrowType arrow_type;
    
} menuButtonInfos;

/**
 * @brief create a menu button
 * 
 * @param label the label of the menu button
 * @param path_to_image the path to the image of the menu button
 * @param arrow_type the arrow type of the menu button
 * 
 * @return GtkWidget pointer to the menu button
 * 
 * @warning you can chose only one between label and path_to_image, give NULL to the other
 */

GtkWidget *create_menu_button(const gchar *label, const gchar *path_to_image, GtkArrowType arrow_type);

/**
 * @brief set the properties of the menu button
 * 
 * @param menuButtonInformation the properties of the menu button
 * 
 * @return GtkWidget pointer to the menu button
 */

GtkWidget *set_properties_menuButton(menuButtonInfos *menuButtonInformation);

/**
 * @brief get the properties of the menu button
 * 
 * @param menuButton the menu button
 * 
 * @return menuButtonInfos* the properties of the menu button
 */

menuButtonInfos *get_properties_menuButton(GtkWidget *menuButton);

/**
 * @brief add a menu to the menu button
 * 
 * @param menuButton the menu button
 * @param menu the menu
 */

void add_to_menu_button(GtkWidget *menuButton, GtkWidget *menu);


#endif // MENU_BUTTON_H
