/*****************************************************************************************************************************
 * 
 * @file radio_button.c
 * @brief the implementation of the functions in radio_button.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 27/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/widgets/radio_button.h"

static gchar *Gfile_name;
static GtkWidget *Ggroup_member;

GtkWidget *create_radio_button(const gchar *label, const gchar *path_to_image, GtkWidget *radio_group_member, gboolean default_state)
{
    radioButtonInfos *buttonRadioInformations = (radioButtonInfos *)malloc(sizeof(radioButtonInfos));
    if(!buttonRadioInformations) return NULL;

    buttonRadioInformations->label = g_strdup(label);
    buttonRadioInformations->path_to_image = g_strdup(path_to_image);
    Gfile_name = g_strdup(path_to_image);
    buttonRadioInformations->radio_group_member = radio_group_member;
    Ggroup_member = radio_group_member;
    buttonRadioInformations->default_state = default_state;

    GtkWidget *radioButton = set_properties_radio_button(buttonRadioInformations);
    free(buttonRadioInformations);

    return radioButton;
}

GtkWidget *set_properties_radio_button(radioButtonInfos *buttonRadioInformations)
{
    GtkWidget *radio_button;
    // create the radio button
    if(buttonRadioInformations->label)
        radio_button = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(buttonRadioInformations->radio_group_member), buttonRadioInformations->label);
    else
    {
        radio_button = gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(buttonRadioInformations->radio_group_member));
        gtk_button_set_image(GTK_BUTTON(radio_button), gtk_image_new_from_file(buttonRadioInformations->path_to_image));
    }

    // set the default state
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio_button), buttonRadioInformations->default_state);
    
    return radio_button;
}

radioButtonInfos *get_properties_radio_button(GtkWidget *radioButton)
{
    radioButtonInfos *buttonRadioInformations = (radioButtonInfos *)malloc(sizeof(radioButtonInfos));
    if(!buttonRadioInformations) return NULL;

    buttonRadioInformations->label = gtk_button_get_label(GTK_BUTTON(radioButton));
    if(!buttonRadioInformations->label)
        buttonRadioInformations->path_to_image = g_strdup(Gfile_name);
    else
        buttonRadioInformations->path_to_image = NULL;
    
    buttonRadioInformations->radio_group_member = Ggroup_member;
    buttonRadioInformations->default_state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioButton));
    
    return buttonRadioInformations;
}