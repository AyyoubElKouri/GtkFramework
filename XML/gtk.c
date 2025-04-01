#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *w = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 750, 440, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE, NULL, "../assets/w160/ar.png");

	GtkWidget *fqs = create_header_bar("d", "Default Subtitle", NULL, TRUE);

	add_header_bar_to_window(w, fqs);

	show_widget(w);

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
