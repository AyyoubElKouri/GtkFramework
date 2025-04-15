#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 1000000 // Taille maximale du fichier (modifiable)

char* lire_fichier_dans_chaine(const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "rb"); // "rb" = lecture binaire
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return NULL;
    }

    // Aller à la fin pour connaître la taille du fichier
    fseek(fichier, 0, SEEK_END);
    long taille = ftell(fichier);
    rewind(fichier); // Retour au début du fichier

    // Allouer de la mémoire pour le contenu + caractère de fin de chaîne
    char* buffer = malloc(taille + 1);
    if (buffer == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(fichier);
        return NULL;
    }

    // Lire le contenu du fichier
    size_t lu = fread(buffer, 1, taille, fichier);
    buffer[lu] = '\0'; // Terminer la chaîne

    fclose(fichier);
    return buffer;
}

int main(int argc, char **argv) {
    const char *nom_fichier = "main.c";
    const char *chaine_cible = "show_widget(window);";
    const char *chaine_a_lire = lire_fichier_dans_chaine(argv[1]);
    printf("\n\nLire : %s\n", chaine_a_lire);

    // Ouvrir le fichier en mode lecture
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Lire tout le contenu du fichier en mémoire
    char buffer[TAILLE_MAX];
    size_t taille_lue = fread(buffer, 1, TAILLE_MAX - 1, fichier);
    buffer[taille_lue] = '\0'; // Assurer la terminaison de la chaîne

    // Chercher la première occurrence de la chaîne
    char *position = strstr(buffer, chaine_cible);
    if (position == NULL) {
        printf("Chaîne '%s' non trouvée dans le fichier.\n", chaine_cible);
        fclose(fichier);
        return 1;
    }

    // Calcul de l'offset : position dans le fichier juste après la chaîne
    long offset = position - buffer + strlen(chaine_cible);
    printf("Offset trouvé : %ld (juste après 'show_widget(window);')\n", offset);

    // Fermer et rouvrir le fichier pour positionner le curseur
    fclose(fichier);
    fichier = fopen(nom_fichier, "r+"); // Mode lecture/écriture
    if (fichier == NULL) {
        perror("Erreur lors de la réouverture du fichier");
        return 1;
    }

    // Positionner le curseur
    fseek(fichier, offset, SEEK_SET);

    // Exemple : écrire un commentaire à cet emplacement
    fputs(chaine_a_lire, fichier);

    fclose(fichier);
    printf("Insertion terminée.\n");
    return 0;
}
