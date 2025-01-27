/*****************************************************************************************************************************
 * 
 * @file entry.h
 * @brief the header file of the entry widget
 * 
 * this file contains all the functions declarations and structures used in the entry widget
 * 
 * @author Ayyoub el Kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef ENTRY_H
#define ENTRY_H

#include <gtk/gtk.h>

/**
 * @struct entryInfos
 * @brief the entry properties
 */

typedef struct
{
    const gchar *default_text;
    const gchar *indicator_text;
    gboolean visible;
    gboolean editable;
    gint max_length;
    gdouble alignment;
} entryInfos;

/**
 * @brief creates an entry widget
 * 
 * @param default_text the default text of the entry
 * @param indicator_text the indicator text of the entry
 * @param visible whether the entry is visible or not
 * @param editable whether the entry is editable or not
 * @param max_length the maximum length of the entry
 * @param alignment the alignment of the entry
 * 
 * @note the default text, indicator text are optional
 *       pass NULL if you don't want to set it
 * 
 * @return the entry widget
 */

GtkWidget *create_entry(const gchar *default_text, const gchar *indicator_text, gboolean visible, gboolean editable, gint max_length, gdouble alignment);

/**
 * @brief sets the properties of the entry
 * 
 * @param entryInformation the entry properties
 * 
 * @return the entry widget
 */

GtkWidget *set_properties_entry(entryInfos *entryInformation);

/**
 * @brief gets the entry properties
 * 
 * @param entry the entry widget
 * 
 * @return the entry properties
 */

entryInfos *get_properties_entry(GtkWidget *entry);


#endif // ENTRY_H
