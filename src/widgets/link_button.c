/*****************************************************************************************************************************
 * 
 * @file link_button.c
 * @brief the implementation of the functions in link_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/link_button.h"

GtkWidget *create_link_button(gchar *uri, gchar *label)
{
    linkButtonInfos *linkButtonInformation = (linkButtonInfos *)malloc(sizeof(linkButtonInfos));
    if(!linkButtonInformation) return NULL;

    linkButtonInformation->url = g_strdup(uri);
    linkButtonInformation->label = g_strdup(label);

    GtkWidget *linkButton = set_properties_link_button(linkButtonInformation);
    free(linkButtonInformation);

    return linkButton;
}

GtkWidget *set_properties_link_button(linkButtonInfos *linkButtonInformation)
{
    GtkWidget *linkButton = gtk_link_button_new(linkButtonInformation->url);

    if(linkButtonInformation->label)
        gtk_button_set_label(GTK_BUTTON(linkButton), linkButtonInformation->label);
    return linkButton;
}

linkButtonInfos *get_properties_link_button(GtkWidget *linkButton)
{
    linkButtonInfos *linkButtonInformation = (linkButtonInfos *)malloc(sizeof(linkButtonInfos));
    if(!linkButtonInformation) return NULL;

    linkButtonInformation->url = gtk_link_button_get_uri(GTK_LINK_BUTTON(linkButton));
    linkButtonInformation->label = gtk_button_get_label(GTK_BUTTON(linkButton));

    return linkButtonInformation;
}

void modify_link_button(GtkWidget *linkButton, linkButtonInfos *linkButtonInformation){
    if(linkButtonInformation->url)
        gtk_link_button_set_uri(GTK_LINK_BUTTON(linkButton), linkButtonInformation->url);

    if(linkButtonInformation->label)
        gtk_button_set_label(GTK_BUTTON(linkButton), linkButtonInformation->label);
}