/*****************************************************************************************************************************
 * 
 * @file entry.h
 * @brief the implementation of the functions in entry.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/entry.h"

GtkWidget *create_entry(const gchar *default_text, const gchar *indicator_text, gboolean visible, gboolean editable, gint max_length, gdouble alignment)
{
    entryInfos *entryInformations = (entryInfos *)malloc(sizeof(entryInfos));
    if(!entryInformations) return NULL;

    entryInformations->default_text = g_strdup(default_text);

    entryInformations->indicator_text = g_strdup(indicator_text);

    entryInformations->visible = visible;
    entryInformations->editable = editable;
    entryInformations->max_length = max_length;
    entryInformations->alignment = alignment;

    GtkWidget *entry = set_properties_entry(entryInformations);
    free(entryInformations);

    return entry;
}

GtkWidget *set_properties_entry(entryInfos *entryInformations)
{
    GtkWidget *entry = gtk_entry_new();

    // set the default text if there is one
    if(entryInformations->default_text)
        gtk_entry_set_text(GTK_ENTRY(entry), entryInformations->default_text);

    // set the indicator text if there is one
    if(entryInformations->indicator_text)
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry), entryInformations->indicator_text);

    // set the visibility option
    gtk_entry_set_visibility(GTK_ENTRY(entry), entryInformations->visible);

    // set the editable obtion
    gtk_editable_set_editable(GTK_EDITABLE(entry), entryInformations->editable);

    // set the max length
    gtk_entry_set_max_length(GTK_ENTRY(entry), entryInformations->max_length);

    // set the alignment
    gtk_entry_set_alignment(GTK_ENTRY(entry), entryInformations->alignment);
    
    return entry;
}

entryInfos *get_properties_entry(GtkWidget *entry)
{
    entryInfos *entryInformations = (entryInfos *)malloc(sizeof(entryInfos));
    if(!entryInformations) return NULL;

    // get the default text
    entryInformations->default_text = gtk_entry_get_text(GTK_ENTRY(entry));

    // get the indicator text
    entryInformations->indicator_text = gtk_entry_get_placeholder_text(GTK_ENTRY(entry));

    // get the visibility option
    entryInformations->visible = gtk_entry_get_visibility(GTK_ENTRY(entry));

    // get the editable option
    entryInformations->editable = gtk_editable_get_editable(GTK_EDITABLE(entry));

    // get the max length
    entryInformations->max_length = gtk_entry_get_max_length(GTK_ENTRY(entry));

    // get the alignment
    entryInformations->alignment = gtk_entry_get_alignment(GTK_ENTRY(entry));

    return entryInformations;
}