/*****************************************************************************************************************************
 * 
 * @file dialog.c
 * @brief the implementation of the functions in dialog.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 20/01/2025
 * @version 2.0 (last update 20/01/2025)
 * 
 ****************************************************************************************************************************/

#include "../../include/windows/dialog.h"
#include <string.h>

static const gchar *Gtitle;
static GtkWidget *Gparent;
static GtkDialogFlags Gflags;
static gint Gwidth;
static gint Gheight;
static gint Gheight;
static gdouble Gopacity;
static GtkWidget *Gbox_content_area;
static const gchar *Gtitle1; 
static gint Ganswer1;
static const gchar *Gtitle2;
static gint Ganswer2;
static const char *Gtitle3;
static gint Ganswer3;


GtkWidget *create_dialog(const gchar *title, GtkWidget *parent, GtkDialogFlags flags, gint width, gint height, gdouble opacity, GtkWidget *box_content_area, const gchar *title1, gint answer1, const gchar *title2, gint answer2, const char *title3, gint answer3)
{
    dialogInfos *dialogInformation = (dialogInfos *)malloc(sizeof(dialogInfos));
    if(!dialogInformation) return NULL;

    dialogInformation->title = g_strdup(title);
    Gtitle = g_strdup(title);
    if(!dialogInformation->title)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->parent = parent;
    Gparent = parent;
    dialogInformation->flags = flags;
    Gflags = flags;
    dialogInformation->width = width;
    Gwidth = width;
    dialogInformation->height = height;
    Gheight = height;
    dialogInformation->opacily = opacity;
    Gopacity = opacity;

    dialogInformation->box_content_area = box_content_area;
    Gbox_content_area = box_content_area;

    dialogInformation->title1 = g_strdup(title1);
    Gtitle1 = g_strdup(title1);
    if(!dialogInformation->title1)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->title2 = g_strdup(title2);
    Gtitle2 = g_strdup(title2);
    if(!dialogInformation->title2)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->title3 = g_strdup(title3);
    Gtitle3 = g_strdup(title3);
    if(!dialogInformation->title3)
    {
        free(dialogInformation);
        return NULL;
    }

    dialogInformation->answer1 = answer1;
    Ganswer1 = answer1;
    dialogInformation->answer2 = answer2;
    Ganswer2 = answer2;
    dialogInformation->answer3 = answer3;
    Ganswer3 = answer3;
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

    if(dialogInformations->box_content_area)
    {
        GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        gtk_box_pack_start(GTK_BOX(content_area), dialogInformations->box_content_area, TRUE, FALSE, 0);
        gtk_widget_show_all(dialog);
    }

    return dialog;
}

dialogInfos *get_properties_dialog(GtkWidget *dialog)
{
    dialogInfos *dialogInformations = (dialogInfos *)malloc(sizeof(dialogInfos));
    if(!dialogInformations) return NULL;

    dialogInformations->title = g_strdup(Gtitle);
    dialogInformations->parent = Gparent;
    dialogInformations->flags = Gflags;
    dialogInformations->width = Gwidth;
    dialogInformations->height = Gheight;
    dialogInformations->opacily = Gopacity;
    dialogInformations->box_content_area = Gbox_content_area;
    dialogInformations->title1 = g_strdup(Gtitle1);
    dialogInformations->title2 = g_strdup(Gtitle2);
    dialogInformations->title3 = g_strdup(Gtitle3);
    dialogInformations->answer1 = Ganswer1;
    dialogInformations->answer2 = Ganswer2;
    dialogInformations->answer3 = Ganswer3;

    return dialogInformations;
    
}