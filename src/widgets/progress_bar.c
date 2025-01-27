/*****************************************************************************************************************************
 * 
 * @file progress_bar.c
 * @brief the implementation of the functions in progress_bar.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 24/01/2025
 * @version 1.0 (last update 24/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/progress_bar.h"

gboolean Gpulse;

GtkWidget *create_progress_bar(const gchar *text, gdouble fraction, gboolean show_text, gboolean pulse, gboolean inverted)
{
    progressBarInfos *progressBarInformation = (progressBarInfos *)malloc(sizeof(progressBarInfos));
    if(!progressBarInformation) return NULL;

    progressBarInformation->text = g_strdup(text);
    if(!progressBarInformation->text)
    {
        free(progressBarInformation);
        return NULL;
    }

    progressBarInformation->fraction = fraction;
    progressBarInformation->show_text = show_text;
    progressBarInformation->pulse = pulse;
    Gpulse = pulse;
    progressBarInformation->inverted = inverted;

    GtkWidget *progressBar = set_properties_progress_bar(progressBarInformation);
    free(progressBarInformation);

    return progressBar;
}

GtkWidget *set_properties_progress_bar(progressBarInfos *progressBarInformation)
{
    // create the progress bar
    GtkWidget *progressBar = gtk_progress_bar_new();

    // set the text
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressBar), progressBarInformation->text);

    // set the fraction
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressBar), progressBarInformation->fraction);

    // show the text
    if(progressBarInformation->show_text)
        gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressBar), TRUE);

    // set the pulse
    if(progressBarInformation->pulse)
        gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progressBar));

    // set the inverted
        gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(progressBar), progressBarInformation->inverted);

    return progressBar;
}

progressBarInfos *get_properties_progress_bar(GtkWidget *progressBar)
{
    progressBarInfos *progressBarInformation = (progressBarInfos *)malloc(sizeof(progressBarInfos));
    if(!progressBarInformation) return NULL;

    // get the text
    progressBarInformation->text = gtk_progress_bar_get_text(GTK_PROGRESS_BAR(progressBar));

    // get the fraction
    progressBarInformation->fraction = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(progressBar));

    // get the show text
    progressBarInformation->show_text = gtk_progress_bar_get_show_text(GTK_PROGRESS_BAR(progressBar));

    // get the pulse
    progressBarInformation->pulse = Gpulse;

    // get the inverted
    progressBarInformation->inverted = gtk_progress_bar_get_inverted(GTK_PROGRESS_BAR(progressBar));

    return progressBarInformation;
}