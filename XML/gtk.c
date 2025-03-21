#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "title", 750, 440, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE, "#e6cce0", NULL);

	GtkWidget *header_bar = create_header_bar("Ayyoub", "El kouri", NULL, TRUE);

	add_header_bar_to_window(window, header_bar);

	GtkWidget *main_box = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *main_box_2 = create_box(GTK_ORIENTATION_VERTICAL, GTK_ALIGN_CENTER, 0);

	GtkWidget *image = create_image("../assets/w160/ar.png");

	add_to_box(main_box_2, image, START, TRUE, TRUE, 0, 0, 0, 0, 0);

	add_to_box(main_box, main_box_2, START, TRUE, TRUE, 0, 0, 0, 0, 0);

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
