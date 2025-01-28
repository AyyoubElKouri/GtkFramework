/*****************************************************************************************************************************
 * 
 * @file fixed.c
 * @brief the source file of the fixed container
 * 
 * this file contains all implementations for the fixed container functions
 * 
 * @author Ayyoub el Kouri
 * @date 28/01/2025
 * @version 1.0 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#include "../../include/containers/fixed.h"

GtkWidget *create_fixed()
{
    return gtk_fixed_new();
}

void add_to_fixed(GtkWidget *fixed, GtkWidget *widget, gint x, gint y)
{
    gtk_fixed_put(GTK_FIXED(fixed), widget, x, y);
}

// soo simple, see!! hhhh