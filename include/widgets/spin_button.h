/*****************************************************************************************************************************
 * 
 * @file spin_button.h
 * @brief header file for creating spin button and control its properties
 * 
 * This header file contains all function declarations for
 * creating a GTK spin button with its properties.
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef SPIN_BUTTON_H
#define SPIN_BUTTON_H

#include <gtk/gtk.h>

/**
 * @struct spinButtonInfos
 * @brief the spin button properties
 */

typedef struct
{
    gdouble min;
    gdouble max;
    gdouble step;
    gdouble value;
    guint digits;
    gboolean wrap;
    gboolean numeric;
}spinButtonInfos;

/**
 * @brief creates a spin button
 * 
 * @param min the minimum value of the spin button
 * @param max the maximum value of the spin button
 * @param step the step value of the spin button    
 * @param digits the number of digits of the spin button
 * @param wrap the wrap value of the spin button
 * @param numeric the numeric value of the spin button
 * 
 * @return GtkWidget* the spin button
 */

GtkWidget *create_spin_button(gdouble min, gdouble max, gdouble step, gdouble value, guint digits, gboolean wrap, gboolean numeric);

/**
 * @brief sets the properties of the spin button
 * 
 * @param spinButtonInformation the information of the spin button
 * 
 * @return GtkWidget* the spin button
 */

GtkWidget *set_properties_spin_button(spinButtonInfos *spinButtonInformation);

/**
 * @brief gets the properties of the spin button
 * 
 * @param spinButton the spin button
 * 
 * @return spinButtonInfos* the spin button information
 */

spinButtonInfos *get_properties_spin_button(GtkWidget *spinButton);


#endif // SPIN_BUTTON_H