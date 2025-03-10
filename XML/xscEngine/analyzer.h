/*****************************************************************************************************************************
 * 
 * @file analyzer.h
 * @brief the header file of the functions and algorithms used for the analyzer xml style file
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 3.0 (last update 05/02/2025)
 * 
 ****************************************************************************************************************************/



#ifndef ANALYZER_H
#define ANALYZER_H

#define MAX_STACK_SIZE 1000
#define STRING_SIZE 20
#define MAX_LINE_SIZE 2000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>


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

NodeA *parse_widget_to_linked_list(const char *input);

NodeA* insert_end(NodeA *head, const char *key, const char *val, int is_string);

void write_to_file(NodeA *widget, NodeA *default_values, FILE *file);

void empiler(pileA *mapile, char *string_to_empiler);

void depiler(pileA *mapile, char *string_to_recive);

int est_vide(pileA *mapile);

int valid_file(FILE *file);

int is_comment(char *line);

int is_close_tag(char *line);

char* extraire_contenu(const char* chaine);

char* my_strdup(const char* str);

char* my_strndup(const char* str, size_t n);

size_t my_strnlen(const char* str, size_t maxlen);

int valid_extension(const char* filename);

int read_line(char *line, FILE *file);

#endif


