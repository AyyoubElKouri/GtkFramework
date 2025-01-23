/*****************************************************************************************************************************
 * 
 * @file dialog.c
 * @brief the implementation of the functions in dialog.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 20/01/2025
 * @version 1.0 (last update 20/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../headers/windows/dialog.h"
#include <string.h>

GtkWidget *create_dialog(const gchar *title, GtkWidget *parent, GtkDialogFlags flags, gint width, gint height, double opacity, const gchar *title1, gint answer1, const gchar *title2, gint answer2, const char *title3, gint answer3)
{
    dialogInfos *dialogInformation = (dialogInfos *)malloc(sizeof(dialogInfos));
    if(!dialogInformation) return NULL;

    dialogInformation->title = g_strdup(title);
    if(!dialogInformation->title)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->parent = parent;
    dialogInformation->flags = flags;
    dialogInformation->width = width;
    dialogInformation->height = height;
    dialogInformation->opacily = opacity;

    dialogInformation->title1 = g_strdup(title1);
    if(!dialogInformation->title1)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->title2 = g_strdup(title2);
    if(!dialogInformation->title2)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->title3 = g_strdup(title3);
    if(!dialogInformation->title3)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->answer1 = answer1;
    dialogInformation->answer2 = answer2;
    dialogInformation->answer3 = answer3;

    GtkWidget *dialog = set_properties_dialog(dialogInformation);
    free(dialogInformation);

    return dialog;
}

GtkWidget *set_properties_dialog(dialogInfos *dialogInformations)
{
    GtkWidget *dialog;

    // ckeck the buttons
    if(strcmp(dialogInformations->title3, "NULL") == 0)
        if(strcmp(dialogInformations->title2, "NULL") == 0)
            if(strcmp(dialogInformations->title1, "NULL") == 0)
                dialog = gtk_dialog_new();
            else
                dialog = gtk_dialog_new_with_buttons(dialogInformations->title, GTK_WINDOW(dialogInformations->parent), dialogInformations->flags, dialogInformations->title1, dialogInformations->answer1, NULL);
        else
            dialog = gtk_dialog_new_with_buttons(dialogInformations->title, GTK_WINDOW(dialogInformations->parent), dialogInformations->flags, dialogInformations->title1, dialogInformations->answer1, dialogInformations->title2, dialogInformations->answer2, NULL);
    else
        dialog = gtk_dialog_new_with_buttons(dialogInformations->title, GTK_WINDOW(dialogInformations->parent), dialogInformations->flags, dialogInformations->title1, dialogInformations->answer1, dialogInformations->title2, dialogInformations->answer2, dialogInformations->title3, dialogInformations->answer3);
    

    // set width and height
    gtk_window_set_default_size(GTK_WINDOW(dialog), dialogInformations->width, dialogInformations->height);

    // set opacity
    gtk_widget_set_opacity(dialog, dialogInformations->opacily);

    return dialog;
}
