/*****************************************************************************************************************************
 * 
 * @file switcher.h
 * @brief the header file of the switcher container
 * 
 * this file contains all the functions declarations and structures used in the switcher container
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef SWITCHER_H
#define SWITCHER_H

#include <gtk/gtk.h>

/**
 * @struct switcherInfos
 * @brief the switcher properties
 */

typedef struct
{
    gint spacing;
    gboolean buttons_same_size;

}switcherInfos;

/**
 * @brief creates a switcher container
 * 
 * @param spacing the spacing between the buttons
 * @param buttons_same_size if the buttons have the same size
 * 
 * @return the switcher container
 */

GtkWidget *create_switcher(gint spacing, gboolean buttons_same_size);

/**
 * @brief sets the properties of the switcher container
 * 
 * @param switcherInformations the properties of the switcher container
 * 
 * @return the switcher container
 */

GtkWidget *set_properties_switcher(switcherInfos *switcherInformations);

/**
 * @brief gets the properties of the switcher container
 * 
 * @param switcher the switcher container
 * 
 * @return the properties of the switcher container
 */

switcherInfos *get_properties_switcher(GtkWidget *switcher);



#endif // SWITCHER_H
