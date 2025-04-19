#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *w = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE, NULL, NULL);

	GtkWidget *c = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *cw = create_radio_button("ffff", NULL, NULL, FALSE);

	add_to_box(c, cw, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	GtkWidget *cws = create_radio_button("ss", NULL, cw, FALSE);

	add_to_box(c, cws, START, TRUE, FALSE, 0, 0, 0, 0, 0);

	add_to_container(w, c);

	show_widget(w);

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
