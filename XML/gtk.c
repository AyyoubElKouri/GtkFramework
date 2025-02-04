#include <gtk/gtk.h>
#include "../include/GtkFramework/GtkFramework.h"
static void hhh(GtkWidget *widget , gpointer data)
{
printf("hello world\n");
}

static void activate(GtkApplication *app, gpointer data){
GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "hi", 900, 800, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);
GtkWidget *header = create_header_bar("Ayyoub el Kouri", "hello is is is", NULL, TRUE);
add_header_bar_to_window(window, header);
GtkWidget *Click = create_button(GTK_RELIEF_NORMAL, "Click me", FALSE, NULL, G_CALLBACK(hhh), NULL);
add_to_container(window, Click);
show_widget(window);
}
int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
