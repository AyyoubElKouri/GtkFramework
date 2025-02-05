#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"
static void close_new(GtkWidget *widget, gpointer data)
{
g_application_quit(G_APPLICATION(data));
// printf("hello\n");
}

static void activate(GtkApplication *app, gpointer data){
GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 800, 650, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *header_bar = create_header_bar("Widgets display", "This project is made to display our widgets", "../assets/Header_bar_icon/apple.png", FALSE);
GtkWidget *close_button = create_button(GTK_RELIEF_NORMAL, NULL, FALSE, "../assets/Application_icon/close-icon.png", G_CALLBACK(close_new), app);
add_to_header_bar(header_bar, close_button, RIGHT);
GtkWidget *more_menu_button = create_menu_button(NULL, "../assets/Application_icon/burger-bar.png", GTK_ARROW_DOWN);
GtkWidget *more_menu = create_menu(TRUE, "Click me");
GtkWidget *ho_made_this = create_menu_item("Ho Made This", "normal", NULL, NULL);
add_to_menu(more_menu, ho_made_this);
GtkWidget *who_is_our_supervisor = create_menu_item("Who is our supervisor", "normal", NULL, NULL);
add_to_menu(more_menu, who_is_our_supervisor);
GtkWidget *contact_me = create_menu_item("Contact me", "normal", NULL, NULL);
add_to_menu(more_menu, contact_me);
add_to_menu_button(more_menu_button, more_menu);
add_to_header_bar(header_bar, more_menu_button, RIGHT);
add_header_bar_to_window(window, header_bar);
GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 5);
GtkWidget *grid_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_CENTER, 5);
GtkWidget *grid = create_grid(10, 0, TRUE, FALSE);
GtkWidget *username = create_entry(NULL, "Username", TRUE, TRUE, 20, 0.5);
add_to_grid(grid, username, 0, 0, 1, 1);
GtkWidget *password = create_entry(NULL, "Password", FALSE, TRUE, 20, 0.5);
add_to_grid(grid, password, 1, 0, 1, 1);
GtkWidget *login = create_button(GTK_RELIEF_NORMAL, "Login", FALSE, NULL, NULL, NULL);
add_to_grid(grid, login, 2, 0, 1, 1);
add_to_box(grid_box, grid, START, FALSE, FALSE, 0, 0, 0, 0, 0);
add_to_box(main_box, grid_box, START, FALSE, FALSE, 0, 0, 0, 0, 0);
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
