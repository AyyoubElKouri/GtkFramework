#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *w = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

	GtkWidget *gdsfg = create_paned(1, 300, TRUE);

	GtkWidget *lkes = create_header_bar("sgsdg", "hs", NULL, TRUE);

	add_to_paned(gdsfg, lkes, 0);

	GtkWidget *lkesg = create_header_bar("sgsdg", "hs", NULL, TRUE);

	add_to_paned(gdsfg, lkesg, 1);

	add_to_container(w, gdsfg);

	show_widget(w);

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
