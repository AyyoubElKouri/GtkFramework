#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
static void activate(GtkApplication *app, gpointer data){
GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *header_bar = create_header_bar("Login Page", "this is a login page", NULL, TRUE);
GtkWidget *menu_button = create_menu_button("Menu", NULL, GTK_ARROW_DOWN);
GtkWidget *menu = create_menu(TRUE, "Menu");
GtkWidget *menu_item1 = create_menu_item("Ayyoub", "normal", NULL, NULL);
GtkWidget *submenu = create_menu(TRUE, "Submenu");
GtkWidget *Ayyoub = create_menu_item("Maroc", "normal", NULL, NULL);
add_to_menu(submenu, Ayyoub);
GtkWidget *Yassine = create_menu_item("France", "normal", NULL, NULL);
add_to_menu(submenu, Yassine);
add_to_menu_item(menu_item1, submenu);
add_to_menu(menu, menu_item1);
GtkWidget *menu_item2 = create_menu_item("Yassine", "normal", NULL, NULL);
add_to_menu(menu, menu_item2);
GtkWidget *menu_item3 = create_menu_item("Maryem", "normal", NULL, NULL);
add_to_menu(menu, menu_item3);
GtkWidget *menu_item4 = create_menu_item("Imane", "normal", NULL, NULL);
add_to_menu(menu, menu_item4);
add_to_menu_button(menu_button, menu);
add_to_header_bar(header_bar, menu_button, RIGHT);
add_header_bar_to_window(window, header_bar);
GtkWidget *main_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_CENTER, 0);
GtkWidget *login_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);
GtkWidget *main_grid = create_grid(10, 10, FALSE, TRUE);
GtkWidget *username_entry = create_entry(NULL, "Username", TRUE, TRUE, 20, 0.5);
add_to_grid(main_grid, username_entry, 0, 0, 1, 1);
GtkWidget *password_entry = create_entry(NULL, "Password", FALSE, TRUE, 20, 0.5);
add_to_grid(main_grid, password_entry, 1, 0, 1, 1);
GtkWidget *check = create_check_button("your are +18 ?", FALSE, FALSE, NULL, NULL);
add_to_grid(main_grid, check, 2, 0, 1, 1);
GtkWidget *radio1 = create_radio_button("Men", NULL, NULL, FALSE);
add_to_grid(main_grid, radio1, 3, 0, 1, 1);
GtkWidget *radio2 = create_radio_button("Women", NULL, radio1, FALSE);
add_to_grid(main_grid, radio2, 4, 0, 1, 1);
GtkWidget *submit_button = create_button(GTK_RELIEF_NORMAL, "Submit", FALSE, NULL, NULL, NULL);
add_to_grid(main_grid, submit_button, 5, 0, 1, 1);
add_to_box(login_box, main_grid, START, TRUE, FALSE, 0, 0, 0, 0, 0);
add_to_box(main_box, login_box, START, TRUE, FALSE, 0, 0, 0, 0, 0);
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
