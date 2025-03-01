#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"



void mon_callback(gpointer data) {
    g_print("Données associées : %s\n", (char*)data);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_resize(GTK_WINDOW(window), 400, 300);
    GtkWidget *tree = create_tree_view();
    
    // Crée un widget personnalisé pour démonstration
    GtkWidget *custom_widget = gtk_label_new("Widget personnalisé");
    
    // Ajout d'éléments
    add_to_tree(tree, NULL, "Racine", NULL, mon_callback, "Data racine");
    add_to_tree(tree, "Racine", "Enfant", NULL, mon_callback, "Data enfant");
    add_to_tree(tree, "Racine", "Enfant 2", custom_widget, mon_callback, "Data enfant 2");
    add_to_tree(tree, "Racine", "Enfant 3", NULL, mon_callback, "Data enfant 3");

    TreeNodeIterator *it = tree_dfs_begin(tree);
    while (tree_node_get_data(it)) {
        TreeNodeData *data = tree_node_get_data(it);
        g_print("Information : %s\n", data->information);
        if(data->widget == custom_widget) {
            g_print("Widget personnalisé trouvé !\n");
        }
        tree_dfs_next(it);
    };
    
    gtk_container_add(GTK_CONTAINER(window), tree);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    
    gtk_main();
    return 0;
}