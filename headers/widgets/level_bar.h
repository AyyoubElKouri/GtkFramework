/*****************************************************************************************************************************
 * 
 * @file level_bar.h
 * @brief header file for creating level bar and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK level bar with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 24/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef LEVEL_BAR_H
#define LEVEL_BAR_H

#include <gtk/gtk.h>

/**
 * @struct levelBarInfos
 * @brief the level bar properties
 */

typedef struct
{
    gdouble min_value;
    gdouble max_value;
    gdouble default_value;
    GtkLevelBarMode mode;
    gboolean inverted;

}levelBarInfos;

/**
 * @brief This function sets the information in one structure and creates a level bar with this information.
 * 
 * @param min_value The minimum value of the level bar.
 * @param max_value The maximum value of the level bar.
 * @param default_value The default value of the level bar.
 * @param mode The mode of the level bar.
 * @param inverted The inverted of the level bar.
 * 
 * @return GtkWidget* A pointer to the created level bar.
 */

GtkWidget *create_level_bar(gdouble min_value, gdouble max_value, gdouble default_value, GtkLevelBarMode mode, gboolean inverted);

/**
 * @brief set the properties of the level bar
 * 
 * this function sets the properties of the level bar
 * 
 * @param levelBarInformation the informations of the level bar
 * 
 * @return GtkWidget* the level bar
 */

GtkWidget *set_properties_level_bar(levelBarInfos *levelBarInformation);

/**
 * @brief get the properties of the level bar
 * 
 * this function gets the properties of the level bar
 * 
 * @param levelBar the level bar
 * 
 * @return levelBarInfos* the informations of the level bar
 */

levelBarInfos *get_properties_level_bar(GtkWidget *levelBar);

#endif // LEVEL_BAR_H