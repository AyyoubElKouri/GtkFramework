

void dialog_function(GtkWidget *widget, gpointer data){
    GtkWidget *box = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 0);

    GtkWidget *image = create_image("../assets/w160/ar.png");

    add_to_box(box, image, START, TRUE, TRUE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Faire un choix", NULL, GTK_DIALOG_MODAL, 300, 300, 1, box, "OK", 1, "Annuler", 2, NULL, 3);
	gint reponse = run_dialog(dialog);
    destroy_widget(dialog);

    if(reponse == 1){
        GtkWidget *dialog = create_dialog("Vous avez clicker sur ok", NULL, GTK_DIALOG_MODAL, 30, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 2, NULL, 3);
        gint reponse = run_dialog(dialog);
        destroy_widget(dialog);
    } else {
        GtkWidget *dialog = create_dialog("Vous avez clicker sur Annuler", NULL, GTK_DIALOG_MODAL, 30, 30, 1, NULL, "                                               OK                                               ", 1, NULL, 2, NULL, 3);
        gint reponse = run_dialog(dialog);
        destroy_widget(dialog);
    }
}

void exit_function(GtkWidget *widget, gpointer data){
    g_application_quit(G_APPLICATION(data));
}