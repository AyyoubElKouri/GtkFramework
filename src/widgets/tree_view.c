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

    GtkTreeStore *store = gtk_tree_store_new(5, 
        G_TYPE_STRING,    // 0: Information textuelle
        GTK_TYPE_WIDGET,  // 1: Widget associé
        G_TYPE_POINTER,   // 2: Fonction callback
        G_TYPE_POINTER,   // 3: Données pour le callback
        G_TYPE_POINTER    // 4: NOUVEAU: Données personnalisées du widget
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

GtkWidget* add_to_tree( GtkWidget* tree_view, const char* id_parent, const char* information, GtkWidget* widget, void (*callback)(gpointer), gpointer callback_data, gpointer widget_data )
{
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
    // Ajout du widget_data dans la colonne 4
    gtk_tree_store_set(store, &new_iter,
        0, information,
        1, widget,
        2, callback,
        3, callback_data,
        4, widget_data,  // Stockage des données personnalisées
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
TreeNodeData* tree_node_get_data(GtkTreeModel *model, GtkTreeIter *iter) {
    TreeNodeData *data = g_new(TreeNodeData, 1);
    
    gtk_tree_model_get(model, iter,
                       0, &(data->information),
                       1, &(data->widget),
                       4, &(data->widget_data),
                       -1);
    
    return data;
}

// Libère l'itérateur
void tree_dfs_end(TreeNodeIterator *iterator) {
    if (!iterator) return;
    
    g_queue_free_full(iterator->stack, (GDestroyNotify)g_free);
    g_free(iterator);
}

// Fonction helper récursive interne
static void recursive_traverse_node(GtkTreeModel *model, GtkTreeIter *parent, TreeTraversalCallback callback, gpointer user_data) {
    GtkTreeIter child;
    gboolean has_child = gtk_tree_model_iter_children(model, &child, parent);

    // Traiter le noeud avant les enfants (ouverture de balise)
    callback(parent, user_data, TRUE);

    while (has_child) {
        // Appel récursif pour chaque enfant
        recursive_traverse_node(model, &child, callback, user_data);
        has_child = gtk_tree_model_iter_next(model, &child);
    }

    // Traiter le noeud après les enfants (fermeture de balise)
    callback(parent, user_data, FALSE);
}

// Fonction d'initiation du parcours
void tree_recursive_traverse(GtkWidget *tree_view, TreeTraversalCallback callback, gpointer user_data) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(tree_view));
    GtkTreeIter iter;

    if (gtk_tree_model_get_iter_first(model, &iter)) {
        do {
            recursive_traverse_node(model, &iter, callback, user_data);
        } while (gtk_tree_model_iter_next(model, &iter));
    }
}

// Helper pour créer un itérateur temporaire depuis un GtkTreeIter
static TreeNodeIterator* create_temp_iterator(GtkTreeModel *model, GtkTreeIter *iter) {
    TreeNodeIterator *temp_it = g_new(TreeNodeIterator, 1);
    temp_it->model = model;
    temp_it->stack = g_queue_new();
    
    GtkTreeIter *copy = g_new(GtkTreeIter, 1);
    *copy = *iter;
    g_queue_push_head(temp_it->stack, copy);
    
    return temp_it;
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
        // Récupérer les données du nœud courant
        GtkTreeIter *current_iter = g_queue_peek_head(it->stack);
        TreeNodeData *node_data = tree_node_get_data(it->model, current_iter);
        
        // Afficher l'information (colonne 0) et l'ID (colonne 4 si utilisé)
        if(strcmp(node_data->information, id) == 0) {
            return node_data;
        }

        // Libérer les données du nœud
        g_free(node_data->information);
        g_free(node_data);

        // Passer au nœud suivant
        it = tree_dfs_next(it);
    }
    tree_dfs_end(it); // Nettoyer
}