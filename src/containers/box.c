/*****************************************************************************************************************************
 * 
 * @file box.c
 * @brief the implementation of the functions in box.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 26/01/2025
 * @version 1.1 (last update 28/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/containers/box.h"

static GtkOrientation Gorientation;

GtkWidget *create_box(GtkOrientation orientation, GtkAlign align, gint spacing)
{
    boxInfos *boxInformations = (boxInfos *)malloc(sizeof(boxInfos));
    if(!boxInformations) return NULL;

    boxInformations->orientation = orientation;
    Gorientation = orientation;
    boxInformations->align = align;
    boxInformations->spacing = spacing;

    GtkWidget *box = set_properties_box(boxInformations);

    free(boxInformations);

    return box;
}

GtkWidget *set_properties_box(boxInfos *boxInformations)
{
    GtkWidget *box = gtk_box_new(boxInformations->orientation, boxInformations->spacing);
    
    // align the box
    if(boxInformations->orientation == GTK_ORIENTATION_HORIZONTAL)
        gtk_widget_set_halign(box, boxInformations->align);
    else
        gtk_widget_set_valign(box, boxInformations->align);

    return box;
}

boxInfos *get_properties_box(GtkWidget *box)
{
    boxInfos *boxInformations = (boxInfos *)malloc(sizeof(boxInfos));
    if(!boxInformations) return NULL;

    boxInformations->orientation = Gorientation;
    if(boxInformations->align != -1)
        if(Gorientation == GTK_ORIENTATION_HORIZONTAL)
            boxInformations->align = gtk_widget_get_halign(box);
        else
            boxInformations->align = gtk_widget_get_valign(box);
    

    boxInformations->spacing = gtk_box_get_spacing(GTK_BOX(box));

    return boxInformations;
}

void add_to_box(GtkWidget *box, GtkWidget *child, BoxPosition position , gboolean expand, gboolean fill, guint padding, gint margin_top, gint margin_buttom, gint margin_right, gint margin_left)
{
    // check the position
    if(position == START)
        gtk_box_pack_start(GTK_BOX(box), child, expand, fill, padding);
    else
        gtk_box_pack_end(GTK_BOX(box), child, expand, fill, padding);
    
    gtk_widget_set_margin_top(child, margin_top);
    gtk_widget_set_margin_bottom(child, margin_buttom);
    gtk_widget_set_margin_start(child, margin_right);
    gtk_widget_set_margin_end(child, margin_left);

}