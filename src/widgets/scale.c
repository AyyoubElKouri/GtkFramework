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


GtkWidget *create_scale(GtkOrientation orientation, gdouble min_value, gdouble max_value, gdouble step)
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

    GtkWidget *scale = set_properties_scale(scaleInformation);
    free(scaleInformation);

    return scale;
}

GtkWidget *set_properties_scale(scaleInfos *scaleInformation)
{
    // create the scale
    GtkWidget *scale = gtk_scale_new_with_range(scaleInformation->orientation, scaleInformation->min_value, scaleInformation->max_value, scaleInformation->step);

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

    return scaleInformation;
}

