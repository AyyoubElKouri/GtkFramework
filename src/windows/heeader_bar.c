/*****************************************************************************************************************************
 * 
 * @file heeader_bar.c
 * @brief the implementation of the functions in heeader_bar.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 26/01/2025
 * @version 1.0 (last update 26/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../headers/windows/header_bar.h"

static GtkWidget *Gwindow;
static const gchar * Gicon_path;
static LinkedList *Gstart_widgets_liste;
static LinkedList *Gend_widgets_liste;

GtkWidget *create_header_bar(GtkWidget *window, const gchar *title, const gchar *subtitle, const gchar *icon_path, gboolean settings, LinkedList *start_widgets_liste, LinkedList *end_widgets_liste)
{
    headerBarInfos *headerBarInformations = (headerBarInfos *)malloc(sizeof(headerBarInfos));
    if(!headerBarInformations) return NULL;

    headerBarInformations->window = window;
    headerBarInformations->title = g_strdup(title);
    if(!headerBarInformations->title)
    {
        free(headerBarInformations);
        return NULL;
    }
    headerBarInformations->subtitle = g_strdup(subtitle);
    if(!headerBarInformations->subtitle)
    {
        free(headerBarInformations);
        return NULL;
    }
    headerBarInformations->icon_path = g_strdup(icon_path);
    Gicon_path = g_strdup(icon_path);
    headerBarInformations->settings = settings;
    headerBarInformations->start_widgets_liste = start_widgets_liste;
    Gstart_widgets_liste = start_widgets_liste;
    headerBarInformations->end_widgets_liste = end_widgets_liste;
    Gend_widgets_liste = end_widgets_liste;

    GtkWidget *header_bar = set_properties_header_bar(headerBarInformations);
    free(headerBarInformations);

    return header_bar;
}

GtkWidget *set_properties_header_bar(headerBarInfos *headerBarInformations)
{
    GtkWidget *header_bar = gtk_header_bar_new();

    // set the window
    gtk_window_set_titlebar(GTK_WINDOW(headerBarInformations->window), header_bar);
    Gwindow = headerBarInformations->window;

    // set the title 
    if(headerBarInformations->title)
        gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), headerBarInformations->title);
    else
        gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "Default title");

    // set the subtitle
    if(headerBarInformations->subtitle)
        gtk_header_bar_set_subtitle(GTK_HEADER_BAR(header_bar), headerBarInformations->subtitle);
    else
        gtk_header_bar_set_subtitle(GTK_HEADER_BAR(header_bar), "Default subtitle");

    // set the icon
    if(headerBarInformations->icon_path)
    {
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(headerBarInformations->icon_path, NULL);
        if(!pixbuf)
        {
            perror("Failed to load icon\n");
            exit(EXIT_FAILURE);
        }
        GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 32, 32, GDK_INTERP_BILINEAR);
        GtkWidget *image = gtk_image_new_from_pixbuf(scaled_pixbuf);

        gtk_header_bar_pack_start(GTK_HEADER_BAR(header_bar), image);
        g_object_unref(pixbuf);
        g_object_unref(scaled_pixbuf);
    }

    // set the settings button
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), headerBarInformations->settings);

    // set the start widgets
    if(headerBarInformations->start_widgets_liste)
    {
        Node *current = headerBarInformations->start_widgets_liste->head;
        while(current)
        {
            gtk_header_bar_pack_start(GTK_HEADER_BAR(header_bar), current->widget);
            current = current->next;
        }
    }

    // set the end widgets
    if(headerBarInformations->end_widgets_liste)
    {
        Node *current = headerBarInformations->end_widgets_liste->head;
        while(current)
        {
            gtk_header_bar_pack_end(GTK_HEADER_BAR(header_bar), current->widget);
            current = current->next;
        }
    }

    return header_bar;
}

headerBarInfos *get_properties_header_bar(GtkWidget *headerBar)
{
    headerBarInfos *headerBarInformations = (headerBarInfos *)malloc(sizeof(headerBarInfos));
    if(!headerBarInformations) return NULL;

    headerBarInformations->window = Gwindow;
    headerBarInformations->title = gtk_header_bar_get_title(GTK_HEADER_BAR(headerBar));
    headerBarInformations->subtitle = gtk_header_bar_get_subtitle(GTK_HEADER_BAR(headerBar));
    headerBarInformations->icon_path = g_strdup(Gicon_path);
    headerBarInformations->settings = gtk_header_bar_get_show_close_button(GTK_HEADER_BAR(headerBar));
    headerBarInformations->start_widgets_liste = Gstart_widgets_liste;
    headerBarInformations->end_widgets_liste = Gend_widgets_liste;

    return headerBarInformations;
}