/*****************************************************************************************************************************
 * 
 * @file text_view.c
 * @brief the implementation of the functions in tree_view.h
 * 
 * 
 * @author Ayyoub el kouri
 * @date 01/03/2025
 * @version 1.0 (last update 01/03/2025)
 * 
 ****************************************************************************************************************************/

 #include "../../include/widgets/tree_view.h"
 #include <string.h>
 #include "../../include/GtkFramework/GtkFramework.h"
 
 struct FindParentData {
     const char *id_parent;
     GtkTreeIter *parent_iter;
     gboolean found;
 };
 
 static gboolean find_parent_cb(GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer user_data) {
     struct FindParentData *data = user_data;
     gchar *current_info = NULL;
     
     gtk_tree_model_get(model, iter, 0, &current_info, -1);
     if (g_strcmp0(current_info, data->id_parent) == 0) {
         *(data->parent_iter) = *iter;
         data->found = TRUE;
         g_free(current_info);
         return TRUE;
     }
     g_free(current_info);
     return FALSE;
 }
 
 static void on_row_activated(GtkTreeView *tree_view, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
     GtkTreeModel *model = gtk_tree_view_get_model(tree_view);
     GtkTreeIter iter;
     
     if (gtk_tree_model_get_iter(model, &iter, path)) {
         GtkWidget *widget = NULL;
         void (*callback)(gpointer) = NULL;
         gpointer data = NULL;
         gchar *closing_tag = NULL;
         gchar *widget_name = NULL;
    
         gtk_tree_model_get(model, &iter, 
                            1, &widget,
                            2, &callback,
                            3, &data,
                            5, &closing_tag,
                            6, &widget_name,
                            -1);
         
         if (callback) {
             callback(data);
         }
         g_free(closing_tag);
         g_free(widget_name);
     }
 }
 
 static void on_tree_view_realize(GtkWidget *widget, gpointer data) {
     gtk_tree_view_expand_all(GTK_TREE_VIEW(widget));
 }
 
 GtkWidget* create_tree_view() {
    GtkTreeStore *store = gtk_tree_store_new(7, 
        G_TYPE_STRING,    // 0: Information textuelle
        GTK_TYPE_WIDGET,  // 1: Widget associé
        G_TYPE_POINTER,   // 2: Fonction callback
        G_TYPE_POINTER,   // 3: Données pour le callback
        G_TYPE_POINTER,   // 4: Données personnalisées
        G_TYPE_STRING,    // 5: Closing tag
        G_TYPE_STRING     // 6: Nouveau widget_name
    );
     
     GtkWidget *tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
     g_object_unref(store);
 
     GtkCellRenderer *text_renderer = gtk_cell_renderer_text_new();
     GtkTreeViewColumn *column = gtk_tree_view_column_new();
     
     gtk_tree_view_column_pack_start(column, text_renderer, TRUE);
     gtk_tree_view_column_add_attribute(column, text_renderer, "text", 0);
     
     gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
     
     g_signal_connect(tree_view, "row-activated", G_CALLBACK(on_row_activated), NULL);
     g_signal_connect(tree_view, "realize", G_CALLBACK(on_tree_view_realize), NULL);
     
     return tree_view;
 }
 
 GtkWidget* add_to_tree(GtkWidget* tree_view, const char* id_parent, const char* information, 
                       GtkWidget* widget, void (*callback)(gpointer), gpointer callback_data, 
                       gpointer widget_data, char* closing_tag, char* widget_name) {
     GtkTreeView *tv = GTK_TREE_VIEW(tree_view);
     GtkTreeStore *store = GTK_TREE_STORE(gtk_tree_view_get_model(tv));
     GtkTreeIter parent_iter;
     gboolean parent_found = FALSE;
 
     if (id_parent) {
         struct FindParentData fdata = { id_parent, &parent_iter, FALSE };
         gtk_tree_model_foreach(gtk_tree_view_get_model(tv), find_parent_cb, &fdata);
         parent_found = fdata.found;
     }
 
     GtkTreeIter new_iter;
     gtk_tree_store_append(store, &new_iter, parent_found ? &parent_iter : NULL);
     
     gtk_tree_store_set(store, &new_iter,
        0, information,
        1, widget,
        2, callback,
        3, callback_data,
        4, widget_data,
        5, closing_tag,
        6, widget_name,
        -1);

 
     return tree_view;
 }
 
 TreeNodeIterator* tree_dfs_begin(GtkWidget *tree_view) {
     GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
     if (!model) return NULL;
 
     TreeNodeIterator *it = g_new(TreeNodeIterator, 1);
     it->model = model;
     it->stack = g_queue_new();
 
     GtkTreeIter iter;
     if (gtk_tree_model_get_iter_first(model, &iter)) {
         GQueue *roots = g_queue_new();
         do {
             GtkTreeIter *copy = g_new(GtkTreeIter, 1);
             *copy = iter;
             g_queue_push_head(roots, copy);
         } while (gtk_tree_model_iter_next(model, &iter));
         
         GList *elem = g_queue_peek_tail_link(roots);
         while (elem) {
             g_queue_push_tail(it->stack, elem->data);
             elem = elem->prev;
         }
         g_queue_free(roots);
     }
     
     return it;
 }
 
 TreeNodeIterator* tree_dfs_next(TreeNodeIterator *iterator) {
     if (g_queue_is_empty(iterator->stack)) {
         tree_dfs_end(iterator);
         return NULL;
     }
 
     GtkTreeIter *current = g_queue_pop_head(iterator->stack);
     
     GtkTreeIter child;
     if (gtk_tree_model_iter_children(iterator->model, &child, current)) {
         GQueue *children = g_queue_new();
         do {
             GtkTreeIter *copy = g_new(GtkTreeIter, 1);
             *copy = child;
             g_queue_push_head(children, copy);
         } while (gtk_tree_model_iter_next(iterator->model, &child));
         
         GList *elem = g_queue_peek_tail_link(children);
         while (elem) {
             g_queue_push_head(iterator->stack, elem->data);
             elem = elem->prev;
         }
         g_queue_free(children);
     }
     
     g_free(current);
     return iterator;
 }
 
 TreeNodeData* tree_node_get_data(GtkTreeModel *model, GtkTreeIter *iter) {
    TreeNodeData *data = g_new(TreeNodeData, 1);
    
    gtk_tree_model_get(model, iter,
                       0, &(data->information),
                       1, &(data->widget),
                       4, &(data->widget_data),
                       5, &(data->closing_tag),
                       6, &(data->widget_name),
                       -1);
    
    return data;
}

 void tree_dfs_end(TreeNodeIterator *iterator) {
     if (!iterator) return;
     
     g_queue_free_full(iterator->stack, (GDestroyNotify)g_free);
     g_free(iterator);
 }
 
 static void recursive_traverse_node(GtkTreeModel *model, GtkTreeIter *parent, TreeTraversalCallback callback, gpointer user_data) {
     GtkTreeIter child;
     gboolean has_child = gtk_tree_model_iter_children(model, &child, parent);
 
     callback(parent, user_data, TRUE);
 
     while (has_child) {
         recursive_traverse_node(model, &child, callback, user_data);
         has_child = gtk_tree_model_iter_next(model, &child);
     }
 
     callback(parent, user_data, FALSE);
 }
 
 void tree_recursive_traverse(GtkWidget *tree_view, TreeTraversalCallback callback, gpointer user_data) {
     GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
     GtkTreeIter iter;
 
     if (gtk_tree_model_get_iter_first(model, &iter)) {
         do {
             recursive_traverse_node(model, &iter, callback, user_data);
         } while (gtk_tree_model_iter_next(model, &iter));
     }
 }
 
 int tree_empty(GtkWidget *tree_view) {
     GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
     if (!model) return 1;
     
     GtkTreeIter iter;
     return !gtk_tree_model_get_iter_first(model, &iter);
 }
 
 TreeNodeData *search_tree(GtkWidget *tree_view, char* id) {
     TreeNodeIterator *it = tree_dfs_begin(tree_view);
     
     while (it && !g_queue_is_empty(it->stack)) {
         GtkTreeIter *current_iter = g_queue_peek_head(it->stack);
         TreeNodeData *node_data = tree_node_get_data(it->model, current_iter);
         
         if(strcmp(node_data->information, id) == 0) {
             tree_dfs_end(it);
             return node_data;
         }
 
         g_free(node_data->widget_name);
         g_free(node_data->information);
         g_free(node_data->closing_tag); // Libération du closing_tag
         g_free(node_data);
 
         it = tree_dfs_next(it);
     }
     tree_dfs_end(it);
     return NULL;
 }

 char* get_selected_node_id(GtkTreeView *tree_view) {
    GtkTreeSelection *selection = gtk_tree_view_get_selection(tree_view);
    GtkTreeIter selected_iter;
    char *node_id = NULL;

    if (gtk_tree_selection_get_selected(selection, NULL, &selected_iter)) {
        GtkTreeModel *model = gtk_tree_view_get_model(tree_view);
        gtk_tree_model_get(model, &selected_iter, 0, &node_id, -1);
    }

    return node_id; // Peut être NULL si aucune sélection
}

TreeNodeData* get_tree_root(GtkWidget *tree_view) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
    if(!model) return NULL;

    GtkTreeIter root_iter;
    if(!gtk_tree_model_get_iter_first(model, &root_iter)) {
        return NULL; // Arbre vide
    }

    return tree_node_get_data(model, &root_iter);
}

TreeNodeData *get_selected_parent_node_data(GtkTreeView *tree_view) {
    GtkTreeSelection *selection = gtk_tree_view_get_selection(tree_view);
    GtkTreeIter selected_iter;
    TreeNodeData *parent_data = NULL;

    if (gtk_tree_selection_get_selected(selection, NULL, &selected_iter)) {
        GtkTreeModel *model = gtk_tree_view_get_model(tree_view);
        GtkTreeIter parent_iter;

        // Récupérer l'itérateur du parent
        if (gtk_tree_model_iter_parent(model, &parent_iter, &selected_iter)) {
            parent_data = tree_node_get_data(model, &parent_iter);
        }
    }

    return parent_data; // NULL si pas de parent ou non sélectionné
}

int is_child(GtkWidget *tree_view) {
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree_view));
    GtkTreeIter selected_iter;
    
    if (gtk_tree_selection_get_selected(selection, NULL, &selected_iter)) {
        GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
        return !gtk_tree_model_iter_has_child(model, &selected_iter);
    }
    
    return 0; // Aucune sélection ou erreur
}

void delete_selected_element(GtkWidget *tree_view) {
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree_view));
    GtkTreeModel *model;
    GtkTreeIter iter;
    
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        GtkTreeStore *store = GTK_TREE_STORE(model);
        gtk_tree_store_remove(store, &iter); // Suppression récursive avec enfants
    }
}