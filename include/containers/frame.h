/*****************************************************************************************************************************
 * 
 * @file frame.h
 * @brief the header file of the frame container
 * 
 * this file contains all the functions declarations and structures used in the frame container
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ******************************************************************************************************************************/

#ifndef FRAME_H
#define FRAME_H

#include <gtk/gtk.h>

/**
 * @struct frameInfos
 * @brief the frame properties
 */

typedef struct
{
    const gchar *title;
    gfloat horizontal_placement;
    gfloat vertical_placement;
} frameInfos;

/**
 * @brief This function creates a frame container with its properties
 * 
 * @param title The title of the frame
 * @param horizontal_placement The horizontal placement of the frame
 * @param vertical_placement The vertical placement of the frame
 * 
 * @return GtkWidget pointer to the frame
 */

GtkWidget *create_frame(const gchar *title, gfloat horizontal_placement, gfloat vertical_placement);

/**
 * @brief This function sets the properties of the frame
 * 
 * @param frameInformation The information of the frame
 * 
 * @return GtkWidget pointer to the frame
 */

GtkWidget *set_properties_frame(frameInfos *frameInformation);

/**
 * @brief This function gets the properties of the frame
 * 
 * @param frame The frame
 * 
 * @return frameInfos pointer to the frame information
 */

frameInfos *get_properties_frame(GtkWidget *frame);

/**
 * @brief This function adds a widget to the frame
 * 
 * @param frame The frame
 * @param widget The widget to add
 */

void add_to_frame(GtkWidget *frame, GtkWidget *widget, gint top, gint bottom, gint left, gint right);

#endif // FRAME_H