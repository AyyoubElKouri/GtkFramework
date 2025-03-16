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
	GtkWidget *win_main = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 700, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

	GtkWidget *herder_main = create_header_bar("yassine", "Default Subtitle", NULL, TRUE);

	add_header_bar_to_window(win_main, herder_main);

	GtkWidget *scrolled_win1 = create_scrolled_window(TRUE, TRUE);

	GtkWidget *fixed_main = create_fixed();

	GtkWidget *menu_button = create_menu_button("hello", NULL, GTK_ARROW_DOWN);

	GtkWidget *menu = create_menu(TRUE, "Click me");

	GtkWidget *menu_item_1 = create_menu_item("yassine", "normal", NULL, NULL);

	add_to_menu(menu, menu_item_1);

	GtkWidget *menu_item_2 = create_menu_item("youssef", "normal", NULL, NULL);

	GtkWidget *menu_sub = create_menu(FALSE, "Click me");

	GtkWidget *menu_item_3 = create_menu_item("ahmed", "normal", NULL, NULL);

	add_to_menu(menu_sub, menu_item_3);

	GtkWidget *menu_item_4 = create_menu_item("imade", "normal", NULL, NULL);

	add_to_menu(menu_sub, menu_item_4);

	add_to_menu_item(menu_item_2, menu_sub);

	add_to_menu(menu, menu_item_2);

	add_to_menu_button(menu_button, menu);

	add_to_fixed(fixed_main, menu_button, 20, 30);

	GtkWidget *frame_check_button = create_frame("votre experience ave", 0, 1);

	GtkWidget *grid_check_button = create_grid(0, 15, TRUE, TRUE);

	GtkWidget *check_button_1 = create_check_button("faible", FALSE, TRUE, NULL, NULL);

	add_to_grid(grid_check_button, check_button_1, 0, 0, 1, 1);

	GtkWidget *check_button_2 = create_check_button("fort", FALSE, TRUE, NULL, NULL);

	add_to_grid(grid_check_button, check_button_2, 0, 1, 1, 1);

	GtkWidget *check_button_3 = create_check_button("moyenne", FALSE, TRUE, NULL, NULL);

	add_to_grid(grid_check_button, check_button_3, 0, 2, 1, 1);

	add_to_frame(frame_check_button, grid_check_button, 5, 5, 5, 5);

	add_to_fixed(fixed_main, frame_check_button, 20, 130);

	GtkWidget *frame_radio_button = create_frame("gtk", 0, 1);

	GtkWidget *grid_radio_button = create_grid(0, 0, TRUE, TRUE);

	GtkWidget *radio_1 = create_radio_button("gtk bon", NULL, NULL, FALSE);

	add_to_grid(grid_radio_button, radio_1, 0, 0, 1, 1);

	GtkWidget *radio_2 = create_radio_button("gtk pas bon", NULL, radio_1, TRUE);

	add_to_grid(grid_radio_button, radio_2, 1, 0, 1, 1);

	add_to_frame(frame_radio_button, grid_radio_button, 5, 5, 5, 5);

	add_to_fixed(fixed_main, frame_radio_button, 20, 250);

	GtkWidget *ok_button = create_button(GTK_RELIEF_NORMAL, "ok", TRUE, NULL, G_CALLBACK(on_click_submit), NULL);

	add_to_fixed(fixed_main, ok_button, 650, 550);

	GtkWidget *annuler_button = create_button(GTK_RELIEF_NORMAL, "Annuler", TRUE, NULL, NULL, NULL);

	add_to_fixed(fixed_main, annuler_button, 500, 550);

	add_to_scrolled_window(scrolled_win1, fixed_main);

	add_to_container(win_main, scrolled_win1);

	show_widget(win_main);

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
