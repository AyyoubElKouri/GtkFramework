/*****************************************************************************************************************************
 * 
 * @file linked_list.c
 * @brief the implementation of the functions in linked_list.h 
 * 
 * This file contains the implementation of the functions in linked_list.h
 * 
 * @author Ayyoub el kouri
 * @date 25/01/2025
 * @version 1.0 (last update 25/01/2025)
 * 
 ****************************************************************************************************************************/

#include "linked_list.h"
#include <stdlib.h>

// Create and initialize a new linked list
LinkedList* create_linked_list() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL; // Memory allocation failed
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Insert a widget at the beginning of the list
void insert_at_beginning(LinkedList *list, GtkWidget *widget) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return; // Memory allocation failed
    }
    new_node->widget = widget;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

// Insert a widget at the end of the list
void insert_at_end(LinkedList *list, GtkWidget *widget) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return; // Memory allocation failed
    }
    new_node->widget = widget;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// Insert a widget at a specific position in the list
void insert_at_position(LinkedList *list, GtkWidget *widget, int position) {
    if (position < 0 || position > list->size) {
        return; // Invalid position
    }

    if (position == 0) {
        insert_at_beginning(list, widget);
    } else if (position == list->size) {
        insert_at_end(list, widget);
    } else {
        Node *new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
            return; // Memory allocation failed
        }
        new_node->widget = widget;

        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->size++;
    }
}

// Delete the first node in the list
void delete_at_beginning(LinkedList *list) {
    if (list->head == NULL) {
        return; // List is empty
    }
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

// Delete the last node in the list
void delete_at_end(LinkedList *list) {
    if (list->head == NULL) {
        return; // List is empty
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->size--;
}

// Delete a node at a specific position in the list
void delete_at_position(LinkedList *list, int position) {
    if (position < 0 || position >= list->size) {
        return; // Invalid position
    }

    if (position == 0) {
        delete_at_beginning(list);
    } else if (position == list->size - 1) {
        delete_at_end(list);
    } else {
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
        list->size--;
    }
}

// Get the size of the list
int get_size(LinkedList *list) {
    return list->size;
}

// Free the entire linked list
void free_linked_list(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}