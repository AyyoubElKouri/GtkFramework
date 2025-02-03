/*****************************************************************************************************************************
 * 
 * @file analyzer.c
 * @brief the implementation of the functions in analyzer.h
 * 
 * 
 * @author Ayyoub el Kouri
 * @date 26/01/2025
 * @version 2.0 (last update 01/02/2025)
 * 
 ****************************************************************************************************************************/


#include "analyzer.h"

// Helper function to create a new NodeA
NodeA *create_node(const char *key, const char *val, int is_string)
{
    NodeA *new_node = (NodeA *)malloc(sizeof(NodeA));
    if (!new_node) return NULL;

    new_node->key = my_strdup(key);
    new_node->val = my_strdup(val);
    new_node->is_string = is_string;
    new_node->next = NULL;
    return new_node;
}

// Helper function to free the linked list
void free_list(NodeA *head)
{
    while (head) {
        NodeA *temp = head;
        head = head->next;
        free(temp->key);
        free(temp->val);
        free(temp);
    }
    
}

// Main parsing function
NodeA *parse_widget(const char *input)
{
    if (!input || *input != '<') return NULL;

    NodeA *head = NULL;
    NodeA *current = NULL;
    const char *p = input + 1;  // Skip '<'

    // Parse widget type
    while (*p && isspace(*p)) p++;
    const char *widget_start = p;
    while (*p && !isspace(*p) && *p != '>' && *p != '/') p++;
    char *widget_type = my_strndup(widget_start, p - widget_start);
    head = create_node("widget", widget_type, 1);
    free(widget_type);
    current = head;

    // Parse attributes
    while (*p && *p != '>') {
        // Skip whitespace
        while (*p && isspace(*p)) p++;
        if (*p == '>' || *p == '/') break;

        // Get key
        const char *key_start = p;
        while (*p && !isspace(*p) && *p != '=') p++;
        char *key = my_strndup(key_start, p - key_start);

        // Skip to '='
        while (*p && *p != '=') p++;
        if (*p) p++;  // Skip '='

        // Skip whitespace after '='
        while (*p && isspace(*p)) p++;

        // Get value
        char quote = 0;
        if (*p == '"' || *p == '\'') {
            quote = *p;
            p++;
        }
        const char *val_start = p;
        while (*p && ((quote && *p != quote) || (!quote && !isspace(*p) && *p != '>'))) p++;
        char *val = my_strndup(val_start, p - val_start);
        if (quote && *p == quote) p++;  // Skip closing quote

        // Add to list
        current->next = create_node(key, val, 1);
        current = current->next;
        free(key);
        free(val);
    }

    return head;
}

// Example usage
void print_list(NodeA *head)
{
    while (head) {
        printf("(%s, %s)", head->key, head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

// Insert new NodeA at the end of the list
NodeA* insert_end(NodeA *head, const char *key, const char *val, int is_string)
{
    NodeA *new_node = create_node(key, val, is_string);
    if (!new_node) return head;

    if (!head) {
        return new_node;
    }

    NodeA *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void write_to_file(NodeA *widget, NodeA *default_values, FILE *file)
{
    // write in the file "GtkWidget *id = create_widget("
    NodeA *id = widget->next;
    fprintf(file, "GtkWidget *%s = create_%s(", id->val, widget->val);

    // skip the id of the default_values
    widget = widget->next->next;
    // start to write the rest of the data bases
    NodeA *current = default_values->next;
    NodeA *widgetFirstValue = widget;
    int exist = 0;

    // the first value
    while(widget)
    {
        if(strcmp(current->key, widget->key) == 0)
        {
            exist = 1;
            if(current->is_string)
                if(strcmp(widget->val, "NULL") == 0)
                    fprintf(file, "NULL");
                else
                    fprintf(file, "\"%s\"", widget->val);
            else
                fprintf(file, "%s", widget->val);
        }
        widget = widget->next;
    }
    widget = widgetFirstValue;

    if(exist == 0)
        if(current->is_string)
            if(strcmp(current->val, "NULL") == 0)
                fprintf(file, "NULL");
            else
                fprintf(file, "\"%s\"", current->val);
        else
            fprintf(file, "%s", current->val);
    
    exist = 0;
    current = current->next;

    // the rest of the values
    while(current)
    {
        while(widget)
        {
            if(strcmp(current->key, widget->key) == 0)
            {
                exist = 1;
                if(current->is_string)
                    if(strcmp(widget->val, "NULL") == 0)
                        fprintf(file, ", NULL");
                    else
                        fprintf(file, ", \"%s\"", widget->val);
                else
                    fprintf(file, ", %s", widget->val);
            }
            widget = widget->next;
        }
        widget = widgetFirstValue;
        

        if(exist == 0)
            if(current->is_string)
                if(strcmp(current->val, "NULL") == 0)
                    fprintf(file, ", NULL");
                else
                    fprintf(file, ", \"%s\"", current->val);
            else
                fprintf(file, ", %s", current->val);
        
        exist = 0;
        current = current->next;
    }

    // close the function
    fprintf(file, ");\n");
}

void empiler(pileA *mapile, char *string_to_empiler) 
{
    if (mapile->top >= MAX_STACK_SIZE - 1)
        return;
    mapile->top++;  // Incrémenter l'indice du sommet
    strncpy(mapile->data[mapile->top], string_to_empiler, STRING_SIZE - 1);  // Copier la chaîne
    mapile->data[mapile->top][STRING_SIZE - 1] = '\0';  // Assurer la terminaison de la chaîne
}

void depiler(pileA *mapile, char *string_to_recive)
{
    if (mapile->top < 0) {
        string_to_recive[0] = '\0';  // Retourner une chaîne vide en cas d'erreur
        return;
    }
    strncpy(string_to_recive, mapile->data[mapile->top], STRING_SIZE - 1);  // Copier la chaîne
    string_to_recive[STRING_SIZE - 1] = '\0';  // Assurer la terminaison de la chaîne
    mapile->top--;  // Décrémenter l'indice du sommet
}

int est_vide(pileA *mapile)
{
    if (mapile->top < 0) {
        return 1;  // La pile est vide
    } else {
        return 0;  // La pile n'est pas vide
    }
}

int analyse(FILE *file)
{
    // read the file character by character
    char character;
    int ligne = 1;
    char chaine[20];
    pileA maPile = { .top = -1 };


    while((character = fgetc(file)) != EOF)
    {
        // increment the line counter if the character is a newline
        if(character == '\n')
        {
            ligne++;
            continue;
        }

        // check if the character is valid
        if(character != '<' && character != ' ')
        {
            fprintf(stderr, "invalid character in line %d\n", ligne);
            exit(1);
        }
        else
        {
            char temp = fgetc(file);
            if(character == '<' && temp != '/' && temp != '!')
            {
                while((character = fgetc(file)) == ' ');
                chaine[0] = temp;
                chaine[1] = character;
                int index = 2;

                while((character = fgetc(file)) != ' ' && character != '>')
                {
                    chaine[index] = character;
                    index++;
                }

                chaine[index] = '\0';
                empiler(&maPile, chaine);

                if(character != '>')
                    while((character = fgetc(file)) != '>');
            }
            else if(character == '<' && temp == '/' && temp != '!')
            {
                while((character = fgetc(file)) == ' ');
                chaine[0] = character;
                int index = 1;

                while((character = fgetc(file)) != ' ' && character != '>')
                {
                    chaine[index] = character;
                    index++;
                }

                chaine[index] = '\0';

                char chaine2[20];
                depiler(&maPile, chaine2);

                if(strcmp(chaine, chaine2) != 0)
                {
                    fprintf(stderr, "Error in line %d\n", ligne);
                    exit(1);
                }
                if(character != '>')
                    while((character = fgetc(file)) != '>');
            }
            else
                while((character = fgetc(file)) != '\n' && character != EOF);   
        }
    }

    return est_vide(&maPile) ? 1 : 0;
}

int is_comment(char *line)
{
    int i = -1;
    while(line[++i] == ' ');
    return (line[i] == '<' && line[i+1] == '!') ? 1 : 0;
}

int is_close_tag(char *line)
{
    int i = -1;
    while(line[++i] == ' ');
    return (line[i] == '<' && line[i+1] == '/') ? 1 : 0;
}

char* extraire_contenu(const char* chaine)
{
    // Vérifier le format de base : commence par "</" et finit par ">"
    size_t len = strlen(chaine);
    if (len < 3 || strncmp(chaine, "</", 2) != 0 || chaine[len-1] != '>') {
        return NULL;
    }

    // Trouver la fin du nom de la balise (après "</")
    const char* debut_nom = chaine + 2; // Après "</"
    const char* fin_nom = debut_nom;
    
    // Avancer jusqu'au premier espace/tabulation
    while (*fin_nom && !isspace(*fin_nom) && (fin_nom < chaine + len - 1)) {
        fin_nom++;
    }

    // Trouver le début du contenu (après les espaces)
    const char* debut_contenu = fin_nom;
    while (isspace(*debut_contenu) && debut_contenu < chaine + len - 1) {
        debut_contenu++;
    }

    // Trouver la fin du contenu (avant le '>' final)
    const char* fin_contenu = chaine + len - 1; // Position avant '>'
    while (fin_contenu > debut_contenu && isspace(*(fin_contenu - 1))) {
        fin_contenu--;
    }

    // Calculer la longueur du contenu
    size_t contenu_len = fin_contenu - debut_contenu;
    if (contenu_len <= 0) {
        return NULL;
    }

    // Allouer et copier
    char* resultat = malloc(contenu_len + 1);
    if (!resultat) return NULL;
    
    memcpy(resultat, debut_contenu, contenu_len);
    resultat[contenu_len] = '\0';

    return resultat;
}

#include <stdlib.h>
#include <string.h>

char* my_strdup(const char* str)
{
    if (str == NULL) {
        return NULL;
    }

    // Calculate the length of the string
    size_t len = strlen(str) + 1; // +1 for the null terminator

    // Allocate memory for the new string
    char* new_str = (char*)malloc(len);

    if (new_str != NULL) {
        // Copy the original string into the new memory location
        memcpy(new_str, str, len);
    }

    return new_str;
}

char* my_strndup(const char* str, size_t n)
{
    if (str == NULL) {
        return NULL;
    }

    // Calculate the length to copy (up to n characters or the end of the string)
    size_t len = my_strnlen(str, n); // strnlen is safer than strlen for bounded lengths

    // Allocate memory for the new string (+1 for the null terminator)
    char* new_str = (char*)malloc(len + 1);

    if (new_str != NULL) {
        // Copy the characters from the original string
        memcpy(new_str, str, len);

        // Add the null terminator
        new_str[len] = '\0';
    }

    return new_str;
}


#include <stddef.h>

size_t my_strnlen(const char* str, size_t maxlen)
{
    size_t len = 0;
    while (len < maxlen && str[len] != '\0') {
        len++;
    }
    return len;
}