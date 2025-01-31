



#ifndef ANALYZER_H
#define ANALYZER_H
#define MAX_STACK_SIZE 1000
#define STRING_SIZE 20


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct {
    char data[MAX_STACK_SIZE][STRING_SIZE];  
    int top;                                 
} pileA;



typedef struct NodeA {
    char *key;
    char *val;
    int is_string;
    struct NodeA *next;
} NodeA;

NodeA *create_node(const char *key, const char *val, int is_string);

void free_list(NodeA *head);

NodeA *parse_widget(const char *input);

void print_list(NodeA *head);

NodeA* insert_end(NodeA *head, const char *key, const char *val, int is_string);

void write_to_file(NodeA *widget, NodeA *default_values, FILE *file);


void empiler(pileA *mapile, char *string_to_empiler);

void depiler(pileA *mapile, char *string_to_recive);

int est_vide(pileA *mapile);

int analyse(FILE *file);

int is_comment(char *line);

int is_close_tag(char *line);


#endif