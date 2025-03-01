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
        
        gtk_tree_model_get(model, &iter, 
                           1, &widget,     // Récupère le widget associé
                           2, &callback,   // Récupère le callback
                           3, &data,       // Récupère les données
                           -1);
        
        if (callback) {
            callback(data); // Appel du callback avec les données
        }
    }
}

static void on_tree_view_realize(GtkWidget *widget, gpointer data) {
    gtk_tree_view_expand_all(GTK_TREE_VIEW(widget));
}

GtkWidget* create_tree_view() {
    // Crée le modèle avec 4 colonnes : info, widget, callback, données
    GtkTreeStore *store = gtk_tree_store_new(4, 
        G_TYPE_STRING,    // Information textuelle
        GTK_TYPE_WIDGET,  // Widget associé
        G_TYPE_POINTER,   // Fonction callback
        G_TYPE_POINTER    // Données utilisateur
    );
    
    GtkWidget *tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
    g_object_unref(store);

    // Colonne d'affichage avec deux rendus
    GtkCellRenderer *text_renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column = gtk_tree_view_column_new();
    
    // Ajout du rendu pour le texte
    gtk_tree_view_column_pack_start(column, text_renderer, TRUE);
    gtk_tree_view_column_add_attribute(column, text_renderer, "text", 0);
    
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
    
    // Configuration de l'arbre
    g_signal_connect(tree_view, "row-activated", G_CALLBACK(on_row_activated), NULL);
    g_signal_connect(tree_view, "realize", G_CALLBACK(on_tree_view_realize), NULL);
    
    return tree_view;
}

GtkWidget* add_to_tree(GtkWidget* tree_view, const char* id_parent, const char* information, GtkWidget* widget, void (*callback)(gpointer), gpointer data) {
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
                       0, information,      // Texte affiché
                       1, widget,          // Widget associé (peut être NULL)
                       2, callback,        // Callback stocké
                       3, data,            // Données utilisateur
                       -1);

    return tree_view;
}

TreeNodeIterator* tree_dfs_begin(GtkWidget *tree_view) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
    if (!model) return NULL;

    TreeNodeIterator *it = g_new(TreeNodeIterator, 1);
    it->model = model;
    it->stack = g_queue_new();

    // Récupérer tous les éléments racine dans l'ordre inverse
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

// Avance l'itérateur au prochain élément DFS
TreeNodeIterator* tree_dfs_next(TreeNodeIterator *iterator) {
    if (g_queue_is_empty(iterator->stack)) {
        tree_dfs_end(iterator);
        return NULL;
    }

    GtkTreeIter *current = g_queue_pop_head(iterator->stack);
    
    // Ajouter les enfants dans l'ordre inverse
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

// Récupère les données du nœud courant
TreeNodeData* tree_node_get_data(TreeNodeIterator *iterator) {
    if (g_queue_is_empty(iterator->stack)) return NULL;
    
    GtkTreeIter *current = g_queue_peek_head(iterator->stack);
    TreeNodeData *data = g_new(TreeNodeData, 1);
    
    gchar *info = NULL;
    GtkWidget *widget = NULL;
    gtk_tree_model_get(iterator->model, current,
                       0, &info,
                       1, &widget,
                       -1);
    
    data->information = info;
    data->widget = widget;
    return data;
}

// Libère l'itérateur
void tree_dfs_end(TreeNodeIterator *iterator) {
    if (!iterator) return;
    
    g_queue_free_full(iterator->stack, (GDestroyNotify)g_free);
    g_free(iterator);
}