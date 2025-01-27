/*****************************************************************************************************************************
 * 
 * @file check_button.c
 * @brief the implementation of the functions in check_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/check_button.h"

static GCallback Gcallback;
static gpointer Gdata;

GtkWidget *create_check_button(const char *label, gboolean active, gboolean use_underline, GCallback callback, gpointer data)
{
    checkButtonInfos *checkButtonInformation = (checkButtonInfos *)malloc(sizeof(checkButtonInfos));
    if(!checkButtonInformation) return NULL;

    checkButtonInformation->label = g_strdup(label);
    checkButtonInformation->active = active;
    checkButtonInformation->use_underline = use_underline;
    checkButtonInformation->callback = callback;
    Gcallback = callback;
    checkButtonInformation->data = data;
    Gdata = data;


    GtkWidget *checkButton = set_properties_check_button(checkButtonInformation);
    free(checkButtonInformation);

    return checkButton;
}

GtkWidget *set_properties_check_button(checkButtonInfos *checkButtonInformation)
{

    GtkWidget *checkButton;
    if(checkButtonInformation->label)
        checkButton = gtk_check_button_new_with_label(checkButtonInformation->label);
    else
        checkButton = gtk_check_button_new();

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkButton), checkButtonInformation->active);

    gtk_button_set_use_underline(GTK_BUTTON(checkButton), checkButtonInformation->use_underline);

    if(checkButtonInformation->callback)
        g_signal_connect(G_OBJECT(checkButton), "toggled", G_CALLBACK(checkButtonInformation->callback), checkButtonInformation->data);
    
    return checkButton;
}

checkButtonInfos *get_properties_check_button(GtkWidget *checkButton)
{
    checkButtonInfos *checkButtonInformation = (checkButtonInfos *)malloc(sizeof(checkButtonInfos));
    if(!checkButtonInformation) return NULL;

    checkButtonInformation->label = gtk_button_get_label(GTK_BUTTON(checkButton));
    checkButtonInformation->active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkButton));
    checkButtonInformation->use_underline = gtk_button_get_use_underline(GTK_BUTTON(checkButton));
    
    checkButtonInformation->callback = Gcallback;
    checkButtonInformation->data = Gdata;
    
    return checkButtonInformation;
}