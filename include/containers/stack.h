/*****************************************************************************************************************************
 * 
 * @file box.h
 * @brief the header file of the stack container
 * 
 * this file contains all the functions declarations and structures used in the stack container
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <gtk/gtk.h>

/**
 * @struct stackInfos
 * @brief the stack properties
 */

typedef struct
{
    GtkWidget *switcher;
    GtkStackTransitionType transition_type;
    gint transition_duration;
}stackInfos;

/**
 * @brief creates a stack
 * 
 * @param transition_type the transition type
 * @param transition_duration the transition duration
 * 
 * @return the stack widget
 */

GtkWidget *create_stack(GtkWidget *switcher, GtkStackTransitionType transition_type, gint transition_duration);

/**
 * @brief sets the properties of the stack
 * 
 * @param stackInformation the stack properties
 * 
 * @return the stack widget
 */

GtkWidget *set_properties_stack(stackInfos *stackInformation);

/**
 * @brief gets the properties of the stack
 * 
 * @param stack the stack widget
 * 
 * @return the stack properties
 */

stackInfos *get_properties_stack(GtkWidget *stack);

/**
 * @brief adds a widget to the stack
 * 
 * @param stack the stack widget
 * @param widget the widget to add
 */

void add_to_stack(GtkWidget *stack, GtkWidget *widget, const gchar *name);

#endif // STACK_H

