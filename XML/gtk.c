#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 500, 500, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

	GtkWidget *header_id = create_header_bar("UIBuilder", "Build Your App", NULL, TRUE);

	add_header_bar_to_window(window, header_id);

	GtkWidget *box_id = create_box(GTK_ORIENTATION_HORIZONTAL, -1, 5);

	GtkWidget *fixed_id = create_fixed();

	GtkWidget *header_id1 = create_header_bar("UIBuilder", "Build Your App", NULL, TRUE);

	add_to_fixed(fixed_id, header_id1, 40, 0);

	add_to_box(box_id, fixed_id, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	GtkWidget *fixed_id_2 = create_fixed();

	GtkWidget *header_id2 = create_header_bar("UIBuilder", "Build Your App", NULL, TRUE);

	add_to_fixed(fixed_id_2, header_id2, 20, 80);

	add_to_box(box_id, fixed_id_2, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_container(window, box_id);

	show_widget(window);

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
