/*****************************************************************************************************************************
 * 
 * @file separator.c
 * @brief the implementation of the functions in separator.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/separator.h"

static GtkOrientation Gorientation;

GtkWidget *create_separator(GtkOrientation orientation)
{
    separatorInfos *separatorInformation = (separatorInfos *)malloc(sizeof(separatorInfos));
    if(!separatorInformation) return NULL;

    separatorInformation->orientation = orientation;
    Gorientation = orientation;

    GtkWidget *separator = set_properties_separator(separatorInformation);
    free(separatorInformation);

    return separator;
}

GtkWidget *set_properties_separator(separatorInfos *separatorInformation)
{
    GtkWidget *separator = gtk_separator_new(separatorInformation->orientation);

    return separator;
}

separatorInfos *get_properties_separator(GtkWidget *separator)
{
    separatorInfos *separatorInformation = (separatorInfos *)malloc(sizeof(separatorInfos));
    if(!separatorInformation) return NULL;

    separatorInformation->orientation = Gorientation;

    return separatorInformation;
}