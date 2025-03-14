/*****************************************************************************************************************************
 * 
 * @file image.c
 * @brief the implementation of the functions in image.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 22/01/2025
 * @version 1.0 (last update 22/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/image.h"
char path[100];

GtkWidget *create_image(gchar *path)
{
    imageInfos *imageInformation = (imageInfos *)malloc(sizeof(imageInfos));
    if(!imageInformation) return NULL;

    imageInformation->path = g_strdup(path);
    if(!imageInformation->path)
    {
        free(imageInformation);
        return NULL;
    }

    GtkWidget *image = set_properties_image(imageInformation);
    free(imageInformation);

    return image;
}

GtkWidget *set_properties_image(imageInfos *imageInformation)
{
    GtkWidget *image;
    if(imageInformation->path)
        image = gtk_image_new_from_file(imageInformation->path);
    else
        image = gtk_image_new();
    // save the path of the image

    return image;
}

imageInfos *get_properties_image(GtkWidget *image)
{
    imageInfos *imageInformation = (imageInfos *)malloc(sizeof(imageInfos));
    if(!imageInformation) return NULL;

    imageInformation->path = g_strdup(path);

    return imageInformation;
}
 

void modify_image(GtkWidget *image, imageInfos *imageInformation){
    gtk_image_set_from_file(GTK_IMAGE(image), imageInformation->path);
}