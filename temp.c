#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
static void activate(GtkApplication *app, gpointer data){
GtkWidget *hello = create_window(app, GTK_WINDOW_TOPLEVEL, "Default title", 900, 200, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *header_bar = create_header_bar("myApp", "this is a subtitle", "assets/ma.png", TRUE);
add_header_bar_to_window(hello, header_bar);
show_widget(hello);
}
int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
