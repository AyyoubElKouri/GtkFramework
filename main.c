/******************************************************************************************************************************
 * 
 * @project: GTK3 project
 * @file main.c
 * @brief the main file of the project
 * 
 * This file contains the main function of the project.
 * 
 * @author Ayyoub el kouri
 * @date 20/01/2025
 * @version 1.0 (last update 23/01/2025)
 * 
 *****************************************************************************************************************************/


#include <gtk/gtk.h>
#include "includes.h"

static void activate(GtkApplication *app, gpointer data)
{
    GtkWidget *window;
    GtkWidget *dialog;
    GtkWidget *label;
    GtkWidget *image;
    GtkWidget *spinner;
    GtkWidget *textView;
    window = create_window(app, GTK_WINDOW_TOPLEVEL, "hello", 900, 660, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    dialog = create_dialog("hhhhhhh", window, GTK_DIALOG_MODAL, 70, 70, 1, "BUTTON", GTK_RESPONSE_OK, "hello", GTK_RESPONSE_CANCEL, "NULL", GTK_RESPONSE_OK);
    label = create_label("is meee", 16, "consolas", "#80a30d", "#ff1100", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_BOLD, PANGO_STYLE_ITALIC, FALSE);
    image = create_image("/home/ayyoub/Téléchargements/hie.png");
    spinner = create_spinner(TRUE);
    textView = create_text_view("Bonjour mes amis icihhhhh kkkkkkkk kkkkkkkkkkk kkkkkkkkkkkk khhhhhhh hhhhhh h hhhhh hhhhhhh hhhhhh hhhhhhh hhhh hhhhhhh hhhhhh hhhh hhh hh hhhhhh hy hhhhhhhh hhhhhhhhh hhhhhhhhh h hksjdql dkj", 12, "consolas", "#000100", "#FFFFFF", GTK_JUSTIFY_CENTER, PANGO_WEIGHT_NORMAL, PANGO_STYLE_ITALIC, TRUE, FALSE, TRUE);


    labelInfos *labelInformation = get_properties_label(label);
    printf("text: %s\nsize: %d\nfont: %s\ncolor: %s\nbackground: %s\njustify: %d\nunderline: %d\nweight: %d\nstyle: %d\nwrap: %d\n", labelInformation->text, labelInformation->size, labelInformation->font, labelInformation->color, labelInformation->background, labelInformation->justify, labelInformation->underline, labelInformation->weight, labelInformation->style, labelInformation->wrap);

    
    imageInfos *imageInformation = get_properties_image(image);
    printf("path: %s\n", imageInformation->path);

    spinnerInfos *spinnerInformation = get_properties_spinner(spinner);
    printf("active: %d\n", spinnerInformation->active);

    textViewInfos *textViewInformation = get_properties_text_view(textView);
    printf("text: %s\nsize: %d\nfont: %s\ncolor: %s\nbackground: %s\njustify: %d\nweight: %d\nstyle: %d\nwrap: %d\ncursor_visible: %d\neditable: %d\n", textViewInformation->text, textViewInformation->size, textViewInformation->font, textViewInformation->color, textViewInformation->background, textViewInformation->justify, textViewInformation->weight, textViewInformation->style, textViewInformation->wrap, textViewInformation->cursor_visible, textViewInformation->editable);

    gtk_container_add(GTK_CONTAINER(window), textView);

    gtk_widget_show_all(window);
    gtk_widget_show_all(dialog);
}


int main(int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("id.gtk", G_APPLICATION_DEFAULT_FLAGS);
    int status = 0;
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

