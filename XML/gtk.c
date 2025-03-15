#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"
void on_click(GtkWidget *widget, gpointer data){
GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *entry = create_entry(NULL, NULL, TRUE, FALSE, 20, 0.5);
set_text(entry, (char *)data);
add_to_box(box, entry, START, TRUE, FALSE, 0, 0, 0, 0, 0);
GtkWidget *dialog = create_dialog("Results", NULL, GTK_DIALOG_MODAL, 300, 30, 1, box, "                                                       OK                                                       ", 1, NULL, 1, NULL, 1);
run_dialog(dialog);
destroy_widget(dialog);
}
void on_click_submit(GtkWidget *widget, gpointer data){
	GtkWidget *window = create_window(NULL, GTK_WINDOW_TOPLEVEL, "Default title", 500, 500, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
	GtkWidget *header_bar = create_header_bar("UIBuilder", "Build your UI Application", NULL, TRUE);
add_header_bar_to_window(window, header_bar);
GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);
GtkWidget *label = create_label("Monsieur Bekkoucha", 50, "Arial", "#000000", "#f6f5f4", GTK_JUSTIFY_RIGHT, FALSE, 0, 0, TRUE);
add_to_box(main_box, label, START, TRUE, FALSE, 0, 0, 0, 0, 0);
GtkWidget *entry = create_entry(NULL, NULL, TRUE, TRUE, 20, 0.5);
add_to_box(main_box, entry, START, TRUE, FALSE, 0, 0, 0, 0, 0);
char *chaine = get_text(entry);
GtkWidget *button = create_button(GTK_RELIEF_NORMAL, "Click here to see another think", FALSE, NULL, G_CALLBACK(on_click), "ilisi");
add_to_box(main_box, button, START, TRUE, FALSE, 0, 0, 0, 0, 0);
add_to_container(window, main_box);
show_widget(window);
}


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

	GtkWidget *header_bar = create_header_bar("Ayyoub", "test", NULL, TRUE);

	GtkWidget *menu_button = create_menu_button("Home", NULL, GTK_ARROW_DOWN);

	GtkWidget *menu = create_menu(TRUE, "menuee");

	GtkWidget *Ayyoub = create_menu_item("Ayyoub", "normal", NULL, NULL);

	GtkWidget *submenu = create_menu(FALSE, "menuee");

	GtkWidget *Ayyoub_1 = create_menu_item("Ayyoub_1", "normal", NULL, NULL);

	add_to_menu(submenu, Ayyoub_1);

	GtkWidget *Ayyoub_2 = create_menu_item("Ayyoub_2", "normal", NULL, NULL);

	add_to_menu(submenu, Ayyoub_2);

	add_to_menu_item(Ayyoub, submenu);

	add_to_menu(menu, Ayyoub);

	GtkWidget *Yassine = create_menu_item("Yassine", "normal", NULL, NULL);

	add_to_menu(menu, Yassine);

	GtkWidget *Maryem = create_menu_item("Maryem", "normal", NULL, NULL);

	add_to_menu(menu, Maryem);

	add_to_menu_button(menu_button, menu);

	add_to_header_bar(header_bar, menu_button, LEFT);

	add_header_bar_to_window(window, header_bar);

	GtkWidget *main_box = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *main_box_1 = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *main_frame = create_frame("Gtk Projet", 0, 1);

	GtkWidget *main_grid = create_grid(10, 10, TRUE, FALSE);

	GtkWidget *username_label = create_label("Password", 15, "Arial", "#000000", "#f6f5f4", 2, FALSE, 400, 0, FALSE);

	add_to_grid(main_grid, username_label, 0, 0, 1, 1);

	GtkWidget *username_entry = create_entry(NULL, "password", TRUE, TRUE, 25, 0.5);

	add_to_grid(main_grid, username_entry, 0, 1, 1, 1);

	GtkWidget *password_label = create_label("Password", 15, "Arial", "#000000", "#f6f5f4", 2, FALSE, 400, 0, FALSE);

	add_to_grid(main_grid, password_label, 1, 0, 1, 1);

	GtkWidget *password_entry = create_entry(NULL, "password", FALSE, TRUE, 25, 0.5);

	add_to_grid(main_grid, password_entry, 1, 1, 1, 1);

	GtkWidget *check1 = create_check_button("check button 2", TRUE, TRUE, NULL, NULL);

	add_to_grid(main_grid, check1, 2, 0, 1, 1);

	GtkWidget *check2 = create_check_button("check button 2", FALSE, TRUE, NULL, NULL);

	add_to_grid(main_grid, check2, 3, 0, 1, 1);

	GtkWidget *radio1 = create_radio_button("Yassine", NULL, NULL, FALSE);

	add_to_grid(main_grid, radio1, 4, 1, 1, 1);

	GtkWidget *radio2 = create_radio_button("Yassine", NULL, radio1, FALSE);

	add_to_grid(main_grid, radio2, 5, 1, 2, 1);

	GtkWidget *button_submit = create_button(GTK_RELIEF_NORMAL, "Submit", TRUE, NULL, G_CALLBACK(on_click_submit), NULL);

	add_to_grid(main_grid, button_submit, 6, 1, 2, 1);

	add_to_frame(main_frame, main_grid, 2, 2, 2, 2);

	add_to_box(main_box_1, main_frame, START, FALSE, FALSE, 0, 0, 0, 0, 0);

	add_to_box(main_box, main_box_1, START, FALSE, FALSE, 0, 0, 0, 0, 0);

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
