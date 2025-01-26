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
 * @version 1.0 (last update 24/01/2025)
 * 
 *****************************************************************************************************************************/


#include <gtk/gtk.h>
#include "widgets_includes.h"
#include "data_structres_includes.h"


static void activate(GtkApplication *app, gpointer data)
{
    // GtkWidget *window;
    // GtkWidget *dialog;
    // GtkWidget *label;
    // GtkWidget *image;
    // GtkWidget *spinner;
    // GtkWidget *textView;
    // GtkWidget *levelBar;
    // GtkWidget *progressBar;
    // GtkWidget *scale;
    // GtkWidget *separator;
    // GtkWidget *button;
    // GtkWidget *checkButton;
    // GtkWidget *linkButton;
    // GtkWidget *menuItem;

    GtkWidget *window;
    GtkWidget *dialog;

    window = create_window(app, GTK_WINDOW_TOPLEVEL, "hello", 900, 660, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    dialog = create_dialog("hhhhhhh", window, GTK_DIALOG_MODAL, 70, 70, 1, "BUTTON", GTK_RESPONSE_OK, "hello", GTK_RESPONSE_CANCEL, "NULL", GTK_RESPONSE_OK);
    
    GtkWidget *image = create_image("assets/cppIcon.png");
    GtkWidget *label = create_label("cpp 1", 14, "consolas", "#FFFFFF", "#000000", GTK_JUSTIFY_CENTER, TRUE, PANGO_WEIGHT_NORMAL, PANGO_STYLE_ITALIC, TRUE);

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, 5);
    add_box(box, image, START, FALSE, FALSE, 2, 0, 0, 60, 60);
    add_box(box, label, START, FALSE, FALSE, 3, 0, 0, 90, 90);
    
    gtk_container_add(GTK_CONTAINER(window), box);
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

