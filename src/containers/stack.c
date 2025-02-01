/*****************************************************************************************************************************
 * 
 * @file stack.c
 * @brief the implementation of the functions in stack.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/containers/stack.h"

GtkWidget *create_stack(GtkWidget *switcher, GtkStackTransitionType transition_type, gint transition_duration)
{
    stackInfos *stackInformations = (stackInfos *)malloc(sizeof(stackInfos));
    if(!stackInformations) return NULL;

    stackInformations->switcher = switcher;
    stackInformations->transition_type = transition_type;
    stackInformations->transition_duration = transition_duration;

    GtkWidget *stack = set_properties_stack(stackInformations);
    return stack;
}

GtkWidget *set_properties_stack(stackInfos *stackInformations)
{
    GtkWidget *stack = gtk_stack_new();

    // set the switcher
    gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(stackInformations->switcher), GTK_STACK(stack));

    // set the transition type
    gtk_stack_set_transition_type(GTK_STACK(stack), stackInformations->transition_type);

    // set the transition duration
    gtk_stack_set_transition_duration(GTK_STACK(stack), stackInformations->transition_duration);

    return stack;
}

stackInfos *get_properties_stack(GtkWidget *stack)
{
    stackInfos *stackInformations = (stackInfos *)malloc(sizeof(stackInfos));
    if(!stackInformations) return NULL;

    stackInformations->transition_type = gtk_stack_get_transition_type(GTK_STACK(stack));
    stackInformations->transition_duration = gtk_stack_get_transition_duration(GTK_STACK(stack));

    return stackInformations;
}

void add_to_stack(GtkWidget *stack, GtkWidget *widget, const gchar *name)
{
    // Add the widget to the stack
    gtk_stack_add_titled(GTK_STACK(stack), widget, name, name);
}
