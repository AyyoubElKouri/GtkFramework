

void exit_function(GtkWidget *widget, gpointer data){
    g_application_quit(G_APPLICATION(data));
}


void ok_function(GtkWidget *widget, gpointer data){

    GtkWidget *box = create_box(GTK_ORIENTATION_VERTICAL, -1, 0);

    GtkWidget *button = create_button(GTK_RELIEF_NORMAL, "Add  ", FALSE, NULL, NULL, NULL);
    add_to_box(box, button, START, FALSE, FALSE, 0, 0, 0, 0, 0);

    GtkWidget *dialog = create_dialog("Window Information", NULL, GTK_DIALOG_MODAL, 300, 300, 1, box, "OK", 1, "Annuler", 2, NULL, 3);
	gint reponse = run_dialog(dialog);
    destroy_widget(dialog);

    if(reponse == 1){
        g_application_quit(G_APPLICATION(data));
    } else if (reponse == 2){
        
    }
    
}