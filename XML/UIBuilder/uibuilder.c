/******************************************************************************************************************************
 * 
 * @project: GTK3 project
 * @file uibuilder.c
 * @brief the main file of the uibuiler software
 * 
 * This file contains the main function of the uibuilder.
 * 
 * @author Ayyoub el kouri
 * @date 07/02/2025
 * @version 1.0 (last update 07/02/2025)
 * 
 *****************************************************************************************************************************/

#include "../../include/GtkFramework/GtkFramework.h"

static void activate(GtkApplication *app, gpointer data)
{
    // Create the main window and the header bar
    GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Title", 1000, 650, FALSE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
    GtkWidget *header_bar = create_header_bar("UIBuilder", "Build your app", NULL, TRUE);

    show_widget(window);
}

int main(int argc, char **argv)
{
    GtkWidget *app = gtk_application_new("app.id", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(app, argc, argv);
    g_object_unref(app);
    return status;
}