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
     const gchar *information;
     GtkWidget *widget;
 } TreeNodeData;

 struct TreeNodeIterator {
    GtkTreeModel *model;
    GQueue *stack; // Contient des GtkTreeIter*
};
 
 GtkWidget* create_tree_view();
 GtkWidget* add_to_tree(GtkWidget* tree_view, const char* id_parent, const char* information, GtkWidget* widget, void (*callback)(gpointer), gpointer data);
 
 // Fonctions d'itération DFS
 TreeNodeIterator* tree_dfs_begin(GtkWidget *tree_view);
 TreeNodeIterator* tree_dfs_next(TreeNodeIterator *iterator);
 TreeNodeData* tree_node_get_data(TreeNodeIterator *iterator);
 void tree_dfs_end(TreeNodeIterator *iterator);
 
 
 #endif