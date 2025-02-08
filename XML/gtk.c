#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"
static void activate(GtkApplication *app, gpointer data){
GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 5000, 5000, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *Header_bar = create_header_bar("UIBuilder", "Build your UI Application", NULL, TRUE);
add_header_bar_to_window(window, Header_bar);
GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *app_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *main_paned = create_paned(GTK_ORIENTATION_HORIZONTAL, 240, TRUE);
GtkWidget *hierarchy_widgets_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *hierarchy_widgets_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
GtkWidget *hierarchy_widgets_label = create_label("Widgets Hierarchy", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);
add_to_box(hierarchy_widgets_label_box, hierarchy_widgets_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);
add_to_box(hierarchy_widgets_box, hierarchy_widgets_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);
GtkWidget *test_button = create_button(GTK_RELIEF_NORMAL, "This space is reserved for\n the Widgets Hierarchy", FALSE, NULL, NULL, NULL);
add_to_box(hierarchy_widgets_box, test_button, START, TRUE, TRUE, 0, 7, 0, 0, 7);
add_to_paned(main_paned, hierarchy_widgets_box, FIRST);
GtkWidget *build_space_paned = create_paned(GTK_ORIENTATION_HORIZONTAL, 860, TRUE);
GtkWidget *first_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *contents_space_paned = create_paned(GTK_ORIENTATION_VERTICAL, 500, TRUE);
GtkWidget *working_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *working_space_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
GtkWidget *working_space_label = create_label("Working Space", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);
add_to_box(working_space_label_box, working_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);
add_to_box(working_space_box, working_space_label_box, START, FALSE, FALSE, 0, 0, 0, 12, 7);
GtkWidget *test_button3 = create_button(GTK_RELIEF_NORMAL, "This space is reserved for the Working Space", FALSE, NULL, NULL, NULL);
add_to_box(working_space_box, test_button3, START, TRUE, TRUE, 0, 7, 0, 0, 0);
add_to_paned(contents_space_paned, working_space_box, FIRST);
GtkWidget *widgets_informations_space = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *widgets_informations_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
GtkWidget *widgets_informations_label = create_label("Widgets Informations", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);
add_to_box(widgets_informations_label_box, widgets_informations_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);
add_to_box(widgets_informations_space, widgets_informations_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);
GtkWidget *widgets_informations_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *button_test4 = create_button(GTK_RELIEF_NORMAL, "This space is reserved for the Widgets Informations", FALSE, NULL, NULL, NULL);
add_to_box(widgets_informations_box, button_test4, START, TRUE, TRUE, 0, 7, 0, 0, 0);
add_to_box(widgets_informations_space, widgets_informations_box, START, TRUE, TRUE, 0, 7, 0, 0, 0);
add_to_paned(contents_space_paned, widgets_informations_space, SECOND);
add_to_box(first_space_box, contents_space_paned, START, TRUE, TRUE, 0, 7, 0, 7, 7);
add_to_paned(build_space_paned, first_space_box, FIRST);
GtkWidget *second_space_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *second_space_label_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 0);
GtkWidget *second_space_label = create_label("Widgets Catalog", 14, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);
add_to_box(second_space_label_box, second_space_label, START, TRUE, FALSE, 0, 0, 0, 0, 7);
add_to_box(second_space_box, second_space_label_box, START, FALSE, FALSE, 0, 7, 0, 12, 7);
GtkWidget *widgets_catalog_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *test_button2 = create_button(GTK_RELIEF_NORMAL, "This space is reserved for\n the Widgets Catalog", FALSE, NULL, NULL, NULL);
add_to_box(widgets_catalog_box, test_button2, START, TRUE, TRUE, 0, 0, 0, 0, 0);
add_to_box(second_space_box, widgets_catalog_box, START, TRUE, TRUE, 0, 7, 0, 7, 0);
add_to_paned(build_space_paned, second_space_box, SECOND);
add_to_paned(main_paned, build_space_paned, SECOND);
add_to_box(app_box, main_paned, START, TRUE, TRUE, 0, 0, 0, 0, 0);
add_to_box(main_box, app_box, START, TRUE, TRUE, 0, 7, 0, 7, 7);
GtkWidget *control_box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);
GtkWidget *generate_button = create_button(GTK_RELIEF_NORMAL, "Generate", FALSE, NULL, NULL, NULL);
add_to_box(control_box, generate_button, START, FALSE, FALSE, 0, 0, 0, 0, 7);
GtkWidget *drag_button = create_button(GTK_RELIEF_NORMAL, "Drag", FALSE, NULL, NULL, NULL);
add_to_box(control_box, drag_button, START, TRUE, TRUE, 0, 0, 0, 0, 0);
add_to_box(main_box, control_box, START, FALSE, FALSE, 0, 7, 7, 7, 7);
add_to_container(window, main_box);
show_widget(window);
}
int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
