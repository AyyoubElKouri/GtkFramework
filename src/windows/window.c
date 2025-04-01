/*****************************************************************************************************************************
 * 
 * @file window.c
 * @brief the implementation of the functions in window.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 20/01/2025
 * @version 1.0 (last update 20/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/windows/window.h"
#include <string.h>
#include <stdlib.h>

GtkWidget *create_window(GtkApplication *app, GtkWindowType type, gchar *title, gint width, gint height, gboolean resizable, GtkWindowPosition position, gboolean decorate, GdkPixbuf *icon, double opacity, gboolean fullscrean, char *background_color, char *background_image)
{
    // The structure of the window
    windowInfos *windowInformations = (windowInfos *)malloc(sizeof(windowInfos));
    if(!windowInformations) return NULL;

    // Filling the properties in the structure windowInformations
    windowInformations->app = app;
    windowInformations->type = type;

    windowInformations->title = g_strdup(title);
    if(!windowInformations->title)
    {
        free(windowInformations);
        return NULL;
    }

    windowInformations->width = width;
    windowInformations->height = height;
    windowInformations->resizable = resizable;
    windowInformations->position = position;
    windowInformations->decorate = decorate;
    windowInformations->icon = icon;
    windowInformations->opacity = opacity;
    windowInformations->fullscreen = fullscrean;
    if(background_color)
        windowInformations->background_color = g_strdup(background_color);
    else
        windowInformations->background_color = NULL;

    if(background_image)    
        windowInformations->background_image = g_strdup(background_image);
    else 
        windowInformations->background_image = NULL;

    // Receiving the window and freeing the memory
    GtkWidget *window = set_properties_window(windowInformations);
    free(windowInformations);

    return window;
}

GtkWidget *set_properties_window(windowInfos *windowInformations)
{
    // Create a window
    GtkWidget *window;
    if(windowInformations->app)
        window = gtk_application_window_new(windowInformations->app);
    else    
        window = gtk_window_new(windowInformations->type);
    
    // Set the title
    gtk_window_set_title(GTK_WINDOW(window), windowInformations->title);
    
    // Set the width and height
    gtk_window_set_default_size(GTK_WINDOW(window), windowInformations->width, windowInformations->height);

    // Set resizable option
    gtk_window_set_resizable(GTK_WINDOW(window), windowInformations->resizable);

    // Set position
    gtk_window_set_position(GTK_WINDOW(window), windowInformations->position);

    // Set decorate
    gtk_window_set_decorated(GTK_WINDOW(window), windowInformations->decorate);

    // Set icon
    if(windowInformations->icon)
        gtk_window_set_icon(GTK_WINDOW(window), windowInformations->icon);
    
    // Set opacity
    gtk_widget_set_opacity(window, windowInformations->opacity);

    // Set fullscreen option
    if(windowInformations->fullscreen)
        gtk_window_fullscreen(GTK_WINDOW(window));

        if (windowInformations->background_color || windowInformations->background_image) {
            GtkCssProvider *provider = gtk_css_provider_new();
            
            // Construire la chaîne CSS
            GString *css = g_string_new("window {");
        
            if (windowInformations->background_color) {
                g_string_append_printf(css, " background-color: %s;", windowInformations->background_color);
            }
        
            if (windowInformations->background_image) {
                g_string_append_printf(css, " background-image: url(\"%s\"); background-repeat: no-repeat; background-size: cover;", windowInformations->background_image);
            }
        
            g_string_append(css, " }");
        
            // Charger le CSS
            gtk_css_provider_load_from_data(provider, css->str, -1, NULL);
            g_string_free(css, TRUE); // Libérer la mémoire
        
            // Appliquer le CSS au GtkWindow
            GtkStyleContext *context = gtk_widget_get_style_context(window);
            gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            
        }
        

    return window;
}

void add_header_bar_to_window(GtkWidget *window, GtkWidget *headerBar)
{
    // Add the header bar to the window
    gtk_window_set_titlebar(GTK_WINDOW(window), headerBar);
}