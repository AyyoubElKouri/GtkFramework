/*****************************************************************************************************************************
 * 
 * @file box.h
 * @brief the header file of the box container
 * 
 * this file contains all the functions declarations and structures used in the box container
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef BOX_H   
#define BOX_H

#include <gtk/gtk.h>


/**
 * @struct boxInfos
 * @brief the box properties
 */

typedef struct
{
    GtkOrientation orientation;
    GtkAlign align;
    gint spacing;
}boxInfos;

/**
 * @enum BoxPosition
 * @brief the enum is for the child position in the box
 */

typedef enum
{
    START,
    END
}BoxPosition;

/**
 * @brief create a box
 * 
 * this function creates a box
 * 
 * @param orientation the orientation of the box
 * @param spacing
 * 
 * @return GtkWidget* the box
 */

GtkWidget *create_box(GtkOrientation orientation, GtkAlign align, gint spacing);

/**
 * @brief set the properties of the box
 * 
 * this function sets the properties of the box
 * 
 * @param boxInformation the informations of the box
 * 
 * @return GtkWidget* the box
 */

GtkWidget *set_properties_box(boxInfos *boxInformations);

/**
 * @brief get the properties of the box
 * 
 * this function gets the properties of the box
 * 
 * @param button the box
 * 
 * @return buttonInfos* the informations of the box
 */

boxInfos *get_properties_box(GtkWidget *box);

void add_to_box(GtkWidget *box, GtkWidget *child, BoxPosition position , gboolean expand, gboolean fill, guint padding, gint margin_top, gint margin_buttom, gint margin_right, gint left);

#endif // BOX_H