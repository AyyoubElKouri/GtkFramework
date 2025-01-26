
/*****************************************************************************************************************************
 * 
 * @file button.h
 * @brief the header file of the button widget
 * 
 * this file contains all the functions declarations and structures used in the button widget
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct buttonInfos
 * @brief the button properties
 */

typedef struct
{
    GtkReliefStyle relief;
    const gchar *label;
    gboolean use_underline;
    const gchar *path_to_image;
    GCallback callback;
    gpointer data;
}buttonInfos;

/**
 * @brief create a button
 * 
 * this function creates a button
 * 
 * @param label the label of the button
 * @param use_underline if the label contains an underline
 * @param path_to_image the path to the image of the button
 * @param callback the callback function of the button
 * @param data the data to pass to the callback function
 * 
 * @return GtkWidget* the button
 */

GtkWidget *create_button(GtkReliefStyle relief, const gchar *label, gboolean use_underline, const gchar *path_to_image, GCallback callback, gpointer data);

/**
 * @brief set the properties of the button
 * 
 * this function sets the properties of the button
 * 
 * @param buttonInformation the informations of the button
 * 
 * @return GtkWidget* the button
 */

GtkWidget *set_properties_button(buttonInfos *buttonInformation);

/**
 * @brief get the properties of the button
 * 
 * this function gets the properties of the button
 * 
 * @param button the button
 * 
 * @return buttonInfos* the informations of the button
 */

buttonInfos *get_properties_button(GtkWidget *button);



#endif // BUTTON_H