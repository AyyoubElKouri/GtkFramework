#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lire_fichier_dans_chaine(const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "rb");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return NULL;
    }

    fseek(fichier, 0, SEEK_END);
    long taille = ftell(fichier);
    rewind(fichier);

    char* buffer = malloc(taille + 1);
    if (buffer == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(fichier);
        return NULL;
    }

    size_t lu = fread(buffer, 1, taille, fichier);
    buffer[lu] = '\0';

    fclose(fichier);
    return buffer;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Utilisation : %s fichier_a_inserer\n", argv[0]);
        return 1;
    }

    const char *nom_fichier = "main.c";
    const char *chaine_cible = "show_widget(window);";

    // Lire le texte à insérer
    char *chaine_a_inserer = lire_fichier_dans_chaine(argv[1]);
    if (chaine_a_inserer == NULL)
        return 1;

    // Lire le contenu du fichier à modifier
    char *contenu = lire_fichier_dans_chaine(nom_fichier);
    if (contenu == NULL) {
        free(chaine_a_inserer);
        return 1;
    }

    // Chercher la position de la chaîne cible
    char *pos = strstr(contenu, chaine_cible);
    if (pos == NULL) {
        printf("Chaîne '%s' non trouvée dans %s.\n", chaine_cible, nom_fichier);
        free(chaine_a_inserer);
        free(contenu);
        return 1;
    }

    size_t index = pos - contenu;
    size_t len_cible = strlen(chaine_cible);
    size_t nouvelle_taille = strlen(contenu) + strlen(chaine_a_inserer) + 1;

    // Créer le nouveau contenu avec insertion AVANT la chaîne cible
    char *nouveau_contenu = malloc(nouvelle_taille);
    if (!nouveau_contenu) {
        perror("Erreur d'allocation mémoire");
        free(chaine_a_inserer);
        free(contenu);
        return 1;
    }

    // Construire le nouveau contenu
    strncpy(nouveau_contenu, contenu, index);
    nouveau_contenu[index] = '\0';
    strcat(nouveau_contenu, chaine_a_inserer);
    strcat(nouveau_contenu, contenu + index);

    // Écrire le résultat dans le fichier
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        perror("Erreur ouverture fichier écriture");
        free(chaine_a_inserer);
        free(contenu);
        free(nouveau_contenu);
        return 1;
    }

    fputs(nouveau_contenu, fichier);
    fclose(fichier);

    // Libération mémoire
    free(chaine_a_inserer);
    free(contenu);
    free(nouveau_contenu);

    printf("Insertion AVANT la chaîne cible effectuée avec succès.\n");
    return 0;
}
    