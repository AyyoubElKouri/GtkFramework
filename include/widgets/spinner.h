/*****************************************************************************************************************************
 * 
 * @file spinner.h
 * @brief header file for creating spinner and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK spinner with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 22/01/2025
 * @version 1.0 (last update 22/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SPINNER_H
#define SPINNER_H

#include <gtk/gtk.h>

/**
 * @struct spinnerInfos
 * @brief the spinner properties
 */

typedef struct
{
    gboolean active;
}spinnerInfos;

/**
 * @brief This function sets the information in one structure and creates a spinner with this information.
 * 
 * @param active The activity of the spinner.
 * @param size The size of the spinner.
 * 
 * @return GtkWidget* A pointer to the created spinner.
 */

GtkWidget *create_spinner(gboolean active);

/**
 * @brief set the properties of the spinner
 * 
 * this function sets the properties of the spinner
 * 
 * @param spinnerInformation the informations of the spinner
 * 
 * @return GtkWidget* the spinner
 */

GtkWidget *set_properties_spinner(spinnerInfos *spinnerInformation);

/**
 * @brief get the properties of the spinner
 * 
 * this function gets the properties of the spinner
 * 
 * @param spinner the spinner
 * 
 * @return
 */

spinnerInfos *get_properties_spinner(GtkWidget *spinner);

/**
 * @brief start the spinner
 * 
 * @param spinner the spinner
 * 
 * @return spinnerInfos* the informations of the spinner
 */

void start_spinner(GtkWidget *spinner);

/**
 * @brief stop the spinner
 * 
 * @param spinner the spinner
 * 
 * @return spinnerInfos* the informations of the spinner
 */

void stop_spinner(GtkWidget *spinner);

#endif // SPINNER_H