/*****************************************************************************************************************************
 * 
 * @file switch_button.c
 * @brief the implementation of the functions in switch_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/switch_button.h"

static GCallback GGcallback;
static gpointer Gdata;

GtkWidget *create_switch_button(gboolean default_state, GCallback callback, gpointer data)
{
    switchButtonInfos *switchButtonInformations = (switchButtonInfos *)malloc(sizeof(switchButtonInfos));
    if(!switchButtonInformations) return NULL;

    switchButtonInformations->default_state = default_state;
    switchButtonInformations->callback = callback;
    GGcallback = callback;
    switchButtonInformations->data = data;
    Gdata = data;

    GtkWidget *switchButton = set_properties_switch_button(switchButtonInformations);

    free(switchButtonInformations);
    return switchButton;
}

GtkWidget *set_properties_switch_button(switchButtonInfos *switchButtonInformations)
{
    // create a switch button
    GtkWidget *switchButton = gtk_switch_new();

    // set the default state
    gtk_switch_set_active(GTK_SWITCH(switchButton), switchButtonInformations->default_state);

    // set the callback and the data
    if(switchButtonInformations->callback)
        g_signal_connect(switchButton, "state-set", G_CALLBACK(switchButtonInformations->callback), switchButtonInformations->data);

    return switchButton;
}

switchButtonInfos *get_properties_switch_button(GtkWidget *switchButton)
{
    switchButtonInfos *switchButtonInformations = (switchButtonInfos *)malloc(sizeof(switchButtonInfos));
    if(!switchButtonInformations) return NULL;

    switchButtonInformations->default_state = gtk_switch_get_active(GTK_SWITCH(switchButton));

    switchButtonInformations->callback = GGcallback;
    switchButtonInformations->data = Gdata;

    return switchButtonInformations;
}
