/*****************************************************************************************************************************
 * 
 * @file progress_bar.h
 * @brief header file for creating progress bar and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK progress bar with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 24/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <gtk/gtk.h>

/**
 * @struct progressBarInfos
 * @brief the progress bar properties
 */

typedef struct
{
    const gchar *text;
    gdouble fraction;
    gboolean show_text;
    gboolean pulse;
    gboolean inverted;
}progressBarInfos;

/**
 * @brief This function sets the information in one structure and creates a progress bar with this information.
 * 
 * @param text The text of the progress bar.
 * @param fraction The fraction of the progress bar.
 * @param show_text The show text of the progress bar.
 * @param pulse The pulse of the progress bar.
 * @param inverted The inverted of the progress bar.
 * 
 * @return GtkWidget* A pointer to the created progress bar.
 */

GtkWidget *create_progress_bar(const gchar *text, gdouble fraction, gboolean show_text, gboolean pulse, gboolean inverted);

/**
 * @brief set the properties of the progress bar
 * 
 * this function sets the properties of the progress bar
 * 
 * @param progressBarInformation the informations of the progress bar
 * 
 * @return GtkWidget* the progress bar
 */

GtkWidget *set_properties_progress_bar(progressBarInfos *progressBarInformation);

/**
 * @brief get the properties of the progress bar
 * 
 * this function gets the properties of the progress bar
 * 
 * @param progressBar the progress bar
 * 
 * @return progressBarInfos* the informations of the progress bar
 */

progressBarInfos *get_properties_progress_bar(GtkWidget *progressBar);

#endif // PROGRESS_BAR_H