#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 1000000 // Taille maximale du fichier (modifiable)

int main() {
    const char *nom_fichier = "main.c";
    const char *chaine_cible = "show_widget(window);";

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
    fputs("\n// << Texte inséré ici >>\n", fichier);

    fclose(fichier);
    printf("Insertion terminée.\n");
    return 0;
}
