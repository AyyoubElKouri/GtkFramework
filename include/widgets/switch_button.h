/*****************************************************************************************************************************
 * 
 * @file check_button.h
 * @brief the header file of the switch button widget
 * 
 * this file contains all the functions declarations and structures used in the switch button widget
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SWITCH_BUTTON_H
#define SWITCH_BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct switchButtonInfos
 * @brief the switch button properties
 */

typedef struct
{
    gboolean default_state;
    GCallback callback;
    gpointer data;
} switchButtonInfos;

/**
 * @brief creates a switch button widget
 * 
 * @param default_state the default state of the switch button
 * @param callback the callback function to be called when the switch button is toggled
 * @param data the data to be passed to the callback function
 * 
 * @return the switch button widget
 */

GtkWidget *create_switch_button(gboolean default_state, GCallback callback, gpointer data);

/**
 * @brief sets the properties of a switch button widget
 * 
 * @param switchButtonInformation the switch button properties
 * 
 * @return the switch button widget
 */

GtkWidget *set_properties_switch_button(switchButtonInfos *switchButtonInformation);

/**
 * @brief gets the properties of a switch button widget
 * 
 * @param switchButton the switch button widget
 * 
 * @return the properties of the switch button widget
 */

switchButtonInfos *get_properties_switch_button(GtkWidget *switchButton);



#endif // SWITCH_BUTTON_H