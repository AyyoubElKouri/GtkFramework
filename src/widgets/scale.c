/*****************************************************************************************************************************
 * 
 * @file scale.c
 * @brief the implementation of the functions in scale.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 24/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/scale.h"

GtkOrientation Gorientation;
gdouble Gmin_value;
gdouble Gmax_value;
gdouble Gstep;
gdouble Gmark_value;
GtkPositionType Gmark_position;
const gchar *Gtext;
gint Gdigits;
GtkPositionType Gvalue_pos;


GtkWidget *create_scale(GtkOrientation orientation, gdouble min_value, gdouble max_value, gdouble step, gdouble mark_value, GtkPositionType mark_position, const gchar *text, gint digits, GtkPositionType value_pos)
{
    scaleInfos *scaleInformation = (scaleInfos *)malloc(sizeof(scaleInfos));
    if(!scaleInformation) return NULL;

    scaleInformation->orientation = orientation;
    Gorientation = orientation;
    scaleInformation->min_value = min_value;
    Gmin_value = min_value;
    scaleInformation->max_value = max_value;
    Gmax_value = max_value;
    scaleInformation->step = step;
    Gstep = step;
    scaleInformation->mark_value = mark_value;
    Gmark_value = mark_value;
    scaleInformation->mark_position = mark_position;
    Gmark_position = mark_position;
    scaleInformation->text = g_strdup(text);
    if(!scaleInformation->text)
    {
        free(scaleInformation);
        return NULL;
    }
    Gtext = g_strdup(text);

    scaleInformation->digits = digits;
    Gdigits = digits;
    scaleInformation->value_pos = value_pos;
    Gvalue_pos = value_pos;

    GtkWidget *scale = set_properties_scale(scaleInformation);
    free(scaleInformation);

    return scale;
}

GtkWidget *set_properties_scale(scaleInfos *scaleInformation)
{
    // create the scale
    GtkWidget *scale = gtk_scale_new_with_range(scaleInformation->orientation, scaleInformation->min_value, scaleInformation->max_value, scaleInformation->step);

    // set the mark value
    if(scaleInformation->mark_value != 0)
        gtk_scale_add_mark(GTK_SCALE(scale), scaleInformation->mark_value, scaleInformation->mark_position, scaleInformation->text);

    // set the position of the scale
    gtk_scale_set_value_pos(GTK_SCALE(scale), scaleInformation->value_pos);

    // set the digits
    gtk_scale_set_digits(GTK_SCALE(scale), scaleInformation->digits);

    return scale;
}

scaleInfos *get_properties_scale(GtkWidget *scale)
{
    scaleInfos *scaleInformation = (scaleInfos *)malloc(sizeof(scaleInfos));
    if(!scaleInformation) return NULL;

    // get the orientation
    scaleInformation->orientation = Gorientation;

    // get the min value
    scaleInformation->min_value = Gmin_value;

    // get the max value
    scaleInformation->max_value = Gmax_value;

    // get the step
    scaleInformation->step = Gstep;

    // get the mark value
    scaleInformation->mark_value = Gmark_value;

    // get the mark position
    scaleInformation->mark_position = Gmark_position;

    // get the text
    scaleInformation->text = Gtext;

    // get the digits
    scaleInformation->digits = Gdigits;

    // get the value position
    scaleInformation->value_pos = Gvalue_pos;

    return scaleInformation;
}

