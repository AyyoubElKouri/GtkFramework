/*****************************************************************************************************************************
 * 
 * @file radio_button.h
 * @brief the header file of the radio button widget
 * 
 * this file contains all the functions declarations and structures used in the radio button widget
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 257/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef RADIO_BUTTON_H
#define RADIO_BUTTON_H


#include <gtk/gtk.h>

/**
 * @struct buttonRadioInfos
 * @brief the button radio properties
 */

typedef struct
{
    const gchar *label;
    const gchar *path_to_image;
    GtkWidget *radio_group_member;
    gboolean default_state;
} radioButtonInfos;

/**
 * @brief creates a radio button widget
 * 
 * @param label the label of the radio button
 * @param path_to_image the path to the image of the radio button
 * @param radio_group_member the radio group member of the radio button
 * @param default_state the default state of the radio button
 * 
 * @note you can only chose one, label or path_to_image
 * @warning the default state must be TRUE for one radio button in a group
 * 
 * @return the radio button widget
 */

GtkWidget *create_radio_button(const gchar *label, const gchar *path_to_image, GtkWidget *radio_group_member, gboolean default_state);

/**
 * @brief sets the properties of the radio button widget
 * 
 * @param buttonRadioInformations the structure containing the properties of the radio button widget
 * 
 * @return the radio button widget
*/

GtkWidget *set_properties_radio_button(radioButtonInfos *buttonRadioInformations);

/**
 * @brief gets the properties of the radio button widget
 * 
 * @param radioButton the radio button widget
 * 
 * @return the properties of the radio button widget
 */

radioButtonInfos *get_properties_radio_button(GtkWidget *radioButton);

#endif // RADIO_BUTTON_H
