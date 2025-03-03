/*****************************************************************************************************************************
 * 
 * @file tree_view.h
 * @brief header file of the tree view widget
 * 
 * this file contains all the functions declarations and structures used in the tree view widget
 * 
 * @author Ayyoub el Kouri
 * @date 01/03/2025
 * @version 1.0 (last update 01/03/2025)
 * 
 ****************************************************************************************************************************/

#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include <gtk/gtk.h>

typedef struct TreeNodeIterator TreeNodeIterator;

typedef struct {
const gchar *information;  // Texte affiché dans l'arbre
GtkWidget *widget;         // Widget associé au nœud
gpointer widget_data;      // Données personnalisées du widget
} TreeNodeData;

struct TreeNodeIterator {
GtkTreeModel *model;
GQueue *stack; // Contient des GtkTreeIter*
};

GtkWidget* create_tree_view();
GtkWidget* add_to_tree(
GtkWidget* tree_view, 
const char* id_parent, 
const char* information, 
GtkWidget* widget, 
void (*callback)(gpointer), 
gpointer callback_data,
gpointer widget_data); 


// Fonctions d'itération DFS
TreeNodeIterator* tree_dfs_begin(GtkWidget *tree_view);
TreeNodeIterator* tree_dfs_next(TreeNodeIterator *iterator);
TreeNodeData* tree_node_get_data(GtkTreeModel *model, GtkTreeIter *iter);
void tree_dfs_end(TreeNodeIterator *iterator);


typedef void (*TreeTraversalCallback)(GtkTreeIter *iter, gpointer user_data, gboolean is_opening);

void tree_recursive_traverse(GtkWidget *tree_view, TreeTraversalCallback callback, gpointer user_data);

static TreeNodeIterator* create_temp_iterator(GtkTreeModel *model, GtkTreeIter *iter);

int tree_empty(GtkWidget *tree_view);

#endif