#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
#include "XML/xscEngine/widgets_structures.h"
#include "t/widget_callbacks.h"
#include "t/xml_generate.h"

extern GtkWidget *test_box;
extern GtkWidget *global_tree;
extern data_widget* global_widget_data_pointer;
extern GtkWidget *drag_button;



static void activate(GtkApplication *app, gpointer data)
{
    GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Hello world", 700, 550, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE, "#9bd461", NULL);

    
    
    show_widget(window);
}



int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}