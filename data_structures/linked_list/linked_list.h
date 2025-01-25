/*****************************************************************************************************************************
 * 
 * @file linked_list.h
 * @brief the header file of the linked list
 * 
 * This header file contains all the function declarations and structures used to
 * create and manage a linked list.
 * 
 * @author Ayyoub el Kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <gtk/gtk.h>

// Structure for a node in the linked list
typedef struct Node {
    GtkWidget *widget;       // Pointer to the GTK widget
    struct Node *next;       // Pointer to the next node
} Node;

// Structure for the linked list
typedef struct {
    Node *head;              // Pointer to the first node
    int size;                // Size of the list
} LinkedList;

// Function prototypes
LinkedList* create_linked_list();                        // Create and initialize a new linked list
void insert_at_beginning(LinkedList *list, GtkWidget *widget); // Insert a widget at the beginning
void insert_at_end(LinkedList *list, GtkWidget *widget);       // Insert a widget at the end
void insert_at_position(LinkedList *list, GtkWidget *widget, int position); // Insert at a specific position
void delete_at_beginning(LinkedList *list);                   // Delete the first node
void delete_at_end(LinkedList *list);                         // Delete the last node
void delete_at_position(LinkedList *list, int position);      // Delete a node at a specific position
int get_size(LinkedList *list);                               // Get the size of the list
void free_linked_list(LinkedList *list);                      // Free the entire linked list

#endif // LINKED_LIST_H