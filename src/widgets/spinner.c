/*****************************************************************************************************************************
 * 
 * @file spinner.c
 * @brief the implementation of the functions in spinner.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 22/01/2025
 * @version 1.0 (last update 22/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/spinner.h"
gboolean active;

GtkWidget *create_spinner(gboolean active)
{
    spinnerInfos *spinnerInformation = (spinnerInfos *)malloc(sizeof(spinnerInfos));
    if(!spinnerInformation) return NULL;

    spinnerInformation->active = active;

    GtkWidget *spinner = set_properties_spinner(spinnerInformation);
    free(spinnerInformation);

    return spinner;
}

GtkWidget *set_properties_spinner(spinnerInfos *spinnerInformation)
{
    GtkWidget *spinner = gtk_spinner_new();

    gtk_spinner_start(GTK_SPINNER(spinner));
    active = TRUE;

    if(!spinnerInformation->active)
    {
        gtk_spinner_stop(GTK_SPINNER(spinner));
        active = FALSE;
    }

    return spinner;
}

spinnerInfos *get_properties_spinner(GtkWidget *spinner)
{
    spinnerInfos *spinnerInformation = (spinnerInfos *)malloc(sizeof(spinnerInfos));
    if(!spinnerInformation) return NULL;

    spinnerInformation->active = active;
    return spinnerInformation;
}

void start_spinner(GtkWidget *spinner)
{
    gtk_spinner_start(GTK_SPINNER(spinner));
    active = TRUE;
}

void stop_spinner(GtkWidget *spinner)
{
    gtk_spinner_stop(GTK_SPINNER(spinner));
    active = FALSE;
}

