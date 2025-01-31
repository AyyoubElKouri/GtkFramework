#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"
static void activate(GtkApplication *app, gpointer data){
GtkWidget *12 = create_window(app, GTK_WINDOW_TOP_LEVEL, "mywindow", 1000, 2000, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *EE = create_box(GTK_ORIENTATION_HORIZONTAL, GTK_ALIGN_START, 10);
GtkWidget *window = create_window(app, GTK_WINDOW_TOP_LEVEL, "Default title", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
}
int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
