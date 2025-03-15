
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