#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *wind = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

	GtkWidget *sfdsg = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *gsdfg = create_grid(0, 0, TRUE, TRUE);

	GtkWidget *gfdgf = create_level_bar(0, 10, 2, 1, FALSE);

	add_to_grid(gsdfg, gfdgf, 0, 0, 1, 1);

	add_to_box(sfdsg, gsdfg, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_container(wind, sfdsg);

	show_widget(wind);

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
