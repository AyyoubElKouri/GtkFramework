/*****************************************************************************************************************************
 * 
 * @file frame.c
 * @brief the implementation of the functions in frame.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/containers/frame.h"

GtkWidget *create_frame(const gchar *title, gfloat horizontal_placement, gfloat vertical_placement, GtkWidget *child)
{
    frameInfos *frameInformations = (frameInfos *)malloc(sizeof(frameInfos));
    if(!frameInformations) return NULL;

    frameInformations->title = g_strdup(title);
    frameInformations->horizontal_placement = horizontal_placement;
    frameInformations->vertical_placement = vertical_placement;
    frameInformations->child = child;

    GtkWidget *frame = set_properties_frame(frameInformations);

    free(frameInformations);
    return frame;
}

GtkWidget *set_properties_frame(frameInfos *frameInformations)
{
    GtkWidget *frame = gtk_frame_new(frameInformations->title);

    // set the horizontal placement
    gtk_frame_set_label_align(GTK_FRAME(frame), frameInformations->horizontal_placement, frameInformations->vertical_placement);

    // set the child
    gtk_container_add(GTK_CONTAINER(frame), frameInformations->child);

    return frame;
}

frameInfos *get_properties_frame(GtkWidget *frame)
{
    frameInfos *frameInformations = (frameInfos *)malloc(sizeof(frameInfos));
    if(!frameInformations) return NULL;

    frameInformations->title = gtk_frame_get_label(GTK_FRAME(frame));
    gtk_frame_get_label_align(GTK_FRAME(frame), &frameInformations->horizontal_placement, &frameInformations->vertical_placement);

    GList *children = gtk_container_get_children(GTK_CONTAINER(frame));
    frameInformations->child = GTK_WIDGET(children->data);

    return frameInformations;
}

