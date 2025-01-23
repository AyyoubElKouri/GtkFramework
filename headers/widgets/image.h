/*****************************************************************************************************************************
 * 
 * @file label.h
 * @brief the header file of the image widget
 * 
 * this file contains all the functions declarations and structures used in the image widget
 * 
 * @author Ayyoub el Kouri
 * @date 22/01/2025
 * @version 1.0 (last update 22/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef IMAGE_H
#define IMAGE_H

#include <gtk/gtk.h>

/**
 * @brief the structure that contains the informations of the label
 * 
 * this structure contains the informations of the label
 * 
 * @warning the size of the image is the same as the size of the image in the file
 */

typedef struct
{
    const gchar *path;   
} imageInfos;

/**
 * @brief create an image
 * 
 * this function creates an image
 * 
 * @param path the path of the image
 * 
 * @return GtkWidget* the image
 */

GtkWidget *create_image(const gchar *path);

/**
 * @brief set the properties of the image
 * 
 * this function sets the properties of the image
 * 
 * @param imageInformation the informations of the image
 * 
 * @return GtkWidget* the image
 */

GtkWidget *set_properties_image(imageInfos *imageInformation);

/**
 * @brief get the properties of the image
 * 
 * this function gets the properties of the image
 * 
 * @param image the image
 * 
 * @return imageInfos* the informations of the image
 */

imageInfos *get_properties_image(GtkWidget *image);

#endif // LABEL_H