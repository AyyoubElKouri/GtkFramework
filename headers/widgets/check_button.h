/*****************************************************************************************************************************
 * 
 * @file check_button.h
 * @brief the header file of the check button widget
 * 
 * this file contains all the functions declarations and structures used in the check button widget
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef CHECK_BUTTON_H
#define CHECK_BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct checkButtonInfos
 * @brief the check button properties
 */

typedef struct
{
    const char *label;
    gboolean active;
    gboolean use_underline;
    GCallback callback;
    gpointer data;
}checkButtonInfos;

/**
 * @brief create a check button
 * 
 * this function creates a check button
 * 
 * @param label the label of the check button
 * @param active the activity of the check button
 * @param use_underline if the label contains an underline
 *  * 
 * @return GtkWidget* the check button
 */

GtkWidget *create_check_button(const char *label, gboolean active, gboolean use_underline, GCallback callback, gpointer data);

/**
 * @brief set the properties of the check button
 * 
 * this function sets the properties of the check button
 * 
 * @param checkButtonInformation the informations of the check button
 * 
 * @return GtkWidget* the check button
 */

GtkWidget *set_properties_check_button(checkButtonInfos *checkButtonInformation);

/**
 * @brief get the properties of the check button
 * 
 * this function gets the properties of the check button
 * 
 * @param checkButton the check button
 * 
 * @return checkButtonInfos* the informations of the check button
 */

checkButtonInfos *get_properties_check_button(GtkWidget *checkButton);

#endif // CHECK_BUTTON_H