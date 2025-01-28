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
 * @version 1.0 (last update 27/01/2025)
 * 
 *****************************************************************************************************************************/


/* *********************************************** this file is not structured yet********************************************/

#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
    
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

