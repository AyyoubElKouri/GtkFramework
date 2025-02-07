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



#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
//#include "DossierForTesting/test_project_1/project_header.h"
//#include "DossierForTesting/test_project_2/project_header_2.h"





static void activate(GtkApplication *app, gpointer data)
{

    // let only the project you want to run
    // comment the others
    // after choosing the project all you want to do is to run the program

    // i hope you like it
    // Ayyoub el Kouri
 
//    project1(app);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Default title");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);


    GtkWidget *combo = create_combo_box();

    add_to_combo_box(combo, "Item 1");
    add_to_combo_box(combo, "Item 2");
    add_to_combo_box(combo, "Item 3");
    add_to_combo_box(combo, "Item 4");
    add_to_combo_box(combo, "Item 5");


    GtkWidget *box1 = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
    GtkWidget *box2 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_CENTER, 5);

    add_to_box(box2, combo, START, FALSE, FALSE, 0, 0, 0, 0, 0);
    add_to_box(box1, box2, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    add_to_container(window, box1);
    show_widget(window);
//    project2(app);
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


