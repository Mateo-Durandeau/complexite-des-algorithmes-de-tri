#include "tab_creation.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    * génération des fichiers csv pour effectuer les tests de tri
*/
// ########### fonction création d'un fichier cas moyen (aléatoire) de n taille #############
void generer_nombres_csv_cm(const char *nom_fichier, int nb_element, int limite) {
    // Initialisation du générateur aléatoire
    srand((unsigned int)time(NULL));

    // Ouvrir le fichier en mode écriture
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    printf("Tirage de %d nombres aleatoires entre 0 et %d\n", nb_element, limite);
    // Tirage et écriture des nombres dans le fichier
    for (int i = 0; i < nb_element; i++) {
        // Tirage d'un nombre aléatoire dans l'intervalle [0,limite[
        int nb = (int)(((float)rand() / RAND_MAX) * limite);
        // Écrire le nombre dans le fichier CSV
        fprintf(fichier, "%d\n", nb);
    }
    fclose(fichier);
}

// ########### fonction création d'un fichier meilleur cas (croissant) de n taille #############
void generer_nombres_csv_mc(const char *nom_fichier, int nb_element) {
    // Ouvrir le fichier en mode écriture
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    printf("Tirage de %d nombres croissant\n", nb_element);
    // Tirage et écriture des nombres dans le fichier
    for (int i = 0; i < nb_element; i++) {
        int nb = i;
        // Écrire le nombre dans le fichier CSV
        fprintf(fichier, "%d\n", nb);
    }
    fclose(fichier);
}

// ########### fonction création d'un fichier pire cas (décroissant) de n taille #############
void generer_nombres_csv_pc(const char *nom_fichier, int nb_element) {
    // Ouvrir le fichier en mode écriture
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    printf("Tirage de %d nombres decroissants\n", nb_element);
    // Tirage et écriture des nombres dans le fichier
    for (int i = nb_element; i >= 1; i--) {
        // Écrire le nombre dans le fichier CSV
        fprintf(fichier, "%d\n", i);
    }
    fclose(fichier);
}

// ########### fonction création d'une run de fichier de n taille et au choix du cas #############
void generation_run(int taille_fich, int choix_cas, int Nb_tab, int pas_difference, int limite) {
    // choix cas : 1 = cas moyen (hasard)
                // 2 = pire cas
                // 3 = meilleur cas

    // Nb_tab = nombre de tableau
    // taille_fich = taille du premier fichier
    // pas_difference = difference entre la taille - pas

    for (int i = 1; i <= Nb_tab; i++) {
        // Construire le nom de fichier en utilisant snprintf
        char nom_fichier[40];  // Ajustez la taille en conséquence
        if (choix_cas == 1)
            snprintf(nom_fichier, sizeof(nom_fichier), "tableau/cm/tab_cm_%d_%d_%03d", limite, taille_fich, i);
        if (choix_cas == 2)
            snprintf(nom_fichier, sizeof(nom_fichier), "tableau/pc/tab_pc_%d_%d_%03d", limite, taille_fich, i);
        if (choix_cas == 3)
            snprintf(nom_fichier, sizeof(nom_fichier), "tableau/mc/tab_mc_%d_%d_%03d", limite, taille_fich, i);
        // Ajouter l'extension .csv au nom du fichier
        strcat(nom_fichier, ".csv");

        // Appeler la fonction pour générer le fichier CSV
        if (choix_cas == 1)
            generer_nombres_csv_cm(nom_fichier, taille_fich, limite);
        if (choix_cas == 2)
            generer_nombres_csv_pc(nom_fichier, taille_fich);
        if (choix_cas == 3)
            generer_nombres_csv_mc(nom_fichier, taille_fich);

        taille_fich = taille_fich - pas_difference;
        // affichage du nombre restant de fichier à générer
        printf("%d / %d fini", i, Nb_tab);
    }
}
