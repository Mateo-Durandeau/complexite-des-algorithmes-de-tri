#include "utiles.h"
#include "module.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
    * fonction permettant la lecture automatique des fichiers et du traitement du temps d'execution
    * séparation des fonctions pour une utilisation individuel ou bien d'une run complète généré via tab_creation
    * création des tableaux de facon dynamique pour utiliser la limite de taille d'un INT 32 bit (éviter les limites de stack)
    * verifier la localisation du fichier tableau ou sont stocké les fichiers
*/

// ######################## fonction de vérification de l'état de tri d'un tableau ###########################
void verification_tri(int tableau[], int taille) {
    int max = tableau[0];
    int erreur = 0;
    // parcours du tableau
    for(int i = 1; i < taille; i++)
        {
            // si un element est inferieur au précedent alors afficher erreur de tri
            if (max > tableau[i])
            {
                printf("erreur tableau \n");
                erreur = 1;
                break;
            }
            max = tableau[i-1];
        }
        if (erreur == 0)
            printf("tableau valide \n\n");
}

// ######################## fonction affichage d'un tableau ###########################
void affiche_tab(int tab[], int taille){

    // parcours du tableau
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
}

// ######################## fonction de copie d'un tableau ###########################
//    - utilisation d'un tableau qui contient la liste de nombre initial et d'un second qui sert de copie
void copie_tab(int tableau_base[], int destination_tab[], int taille) {
    // copie des éléments un par un dans le parcours du tableau
    for (int i = 0; i < taille; i++) {
        destination_tab[i] = tableau_base[i];
    }
}

// ######################## fonction de lecture d'un fichier CSV ###########################
int lire_fichier_csv(const char *nom_fichier, int *tableau, int taille_attendue) {
    // init des variables qui stockent les valeurs du fichier lors du parcours
    int nombre;
    int index = 0;
    // Ouvrir le fichier en mode lecture
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;  // Retourner une valeur d'erreur
    }

    // Lire les nombres depuis le fichier et les stocker dans le tableau
    while (fscanf(fichier, "%d", &nombre) == 1) {
        tableau[index] = nombre;
        index++;
    }
    // Fermer le fichier
    fclose(fichier);
    // Retourner le nombre d'éléments lus (evite les problèmes de taille)
    return index;
}


// ######################## fonction du calcul du temps d'execution ###########################
//     - utlisation d'un tableau copie pour tester 100 fois l'execution d'un tri pour une meilleur précision
//     - le temps d'execution de la copie n'est pas pris en compte mais peut être affiché
float temps_exec(int tableau[], int taille, int num_module_tri) {
    // initialisation des variables
    clock_t debut; /* temps initial en ticks d’horloge */
    clock_t fin;   /* temps final en ticks d’horloge */
    float temps_cpu_total = 0.0; /* temps total en secondes */
    float temps_cpu_copie = 0.0; /* temps de copie du tableau en secondes */
    const int nombre_tests = 100;

    // nombre de fois que l'on fais le test du temps d'execution
    for (int i = 0; i < nombre_tests; i++) {
        // tri du tableau d'origine
        if(i==0)
            tri_de_shell(tableau, taille);

        // creation dynamique du tableau de copie
        int *tableau_copie = malloc(taille * sizeof(int));
        if (tableau_copie == NULL) {
            perror("Erreur lors de l'allocation de mémoire pour la copie du tableau");
            exit(EXIT_FAILURE);
        }

        // calcul du temps d'execution de la copie
        debut = clock();
        copie_tab(tableau, tableau_copie, taille);
        fin = clock();

        temps_cpu_copie += (float)(fin - debut) / CLOCKS_PER_SEC;

        // choix entre le tri avec ou sans séquence + calcul temps execution
        if (num_module_tri == 1) {
            debut = clock();
            tri_de_shell(tableau_copie, taille);
            fin = clock();
        }
        if (num_module_tri == 2) {
            debut = clock();
            tri_de_shell_seq(tableau_copie, taille);
            fin = clock();
        }

        temps_cpu_total += (float)(fin - debut) / CLOCKS_PER_SEC;
        free(tableau_copie);
    }
    float temps_cpu_moyen_total = temps_cpu_total / nombre_tests;
    float temps_cpu_moyen_copie = temps_cpu_copie / nombre_tests;
    printf("Temps d'execution moyen (sans copie) : %f secondes\n", temps_cpu_moyen_total);
    return temps_cpu_moyen_total;
}

// ######################## fonction de sauvegarde dans un fichier des resultats ###########################
void sauvegarder_resultats_csv(const char *nom_fichier, int taille, float temps_execution, const char *type_run, int limite) {
    FILE *fichier = fopen(nom_fichier, "a");  // Ouvrir le fichier en mode ajout
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }
    // Écrire le type de run, la taille et le temps d'exécution dans le fichier CSV
    fprintf(fichier, "%s, %d, %d, %f\n", type_run, limite, taille, temps_execution);
    fclose(fichier);
}

// ######################## fonction de test de tri sur un fichier avec calcul de temps d'éxecution ###########################
void test_tri(int tableau[], int taille, const char *nom_fichier_csv, int choix, int verif_tab, int affichage, const char *nom_sauvegarde_csv, int num_module_tri, int limite)
{
    // création du tableau dynamiquement
    // Utiliser le même tableau pour la lecture et le tri
    int *tab = malloc(taille * sizeof(int));
    if (tab == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour le tableau");
        exit(EXIT_FAILURE);
    }
    // lecture d'un fichier
    int nb_elements = lire_fichier_csv(nom_fichier_csv, tab, taille);

    // calcul du temps d'execution
    // Utiliser le tableau local pour le tri
    float temps_execution = temps_exec(tab, nb_elements, num_module_tri);

    // verification et affichage du tableau
    if (verif_tab == 1)
        verification_tri(tab, nb_elements);

    if (affichage == 1)
        affiche_tab(tab, nb_elements);

    // sauvegarde du resultats des tests dans un fichiers
    if (choix == 1 && num_module_tri == 1)
        sauvegarder_resultats_csv(nom_sauvegarde_csv, taille, temps_execution, "cm-1", limite);
    if (choix == 1 && num_module_tri == 2)
        sauvegarder_resultats_csv(nom_sauvegarde_csv, taille, temps_execution, "cm-2", limite);

    if (choix == 2 && num_module_tri == 1)
        sauvegarder_resultats_csv(nom_sauvegarde_csv, taille, temps_execution, "pc-1", limite);
    if (choix == 2 && num_module_tri == 2)
        sauvegarder_resultats_csv(nom_sauvegarde_csv, taille, temps_execution, "pc-2", limite);

    if (choix == 3 && num_module_tri == 1)
        sauvegarder_resultats_csv(nom_sauvegarde_csv, taille, temps_execution, "mc-1", limite);
    if (choix == 3 && num_module_tri == 2)
        sauvegarder_resultats_csv(nom_sauvegarde_csv, taille, temps_execution, "mc-2", limite);

    free(tab);
}

// ######################## fonction de test de tri d'une run sur un ensemble de fichier avec calcul de temps d'éxecution ###########################
void test_tri_run(int taille_fich, int num_module_tri, int Nb_tab, int pas_difference, int verif_tab, int affichage, int choix, const char *nom_sauvegarde_csv, int limite) {

    for (int i = 1; i <= Nb_tab; i++) {
        char nom_fichier[70];

        // cas moyen
        if (choix == 1)
        {
            // Construire le nom de fichier en utilisant snprintf
            snprintf(nom_fichier, sizeof(nom_fichier), "tableau/cm/tab_cm_%d_%d_%03d", limite, taille_fich, i);
            strcat(nom_fichier, ".csv");
        }
        // pire cas
        if (choix == 2)
        {
            // Construire le nom de fichier en utilisant snprintf
            snprintf(nom_fichier, sizeof(nom_fichier), "tableau/pc/tab_pc_%d_%d_%03d", limite, taille_fich, i);
            strcat(nom_fichier, ".csv");
        }
        // meilleur cas
        if (choix == 3)
        {
            // Construire le nom de fichier en utilisant snprintf
            snprintf(nom_fichier, sizeof(nom_fichier), "tableau/mc/tab_mc_%d_%d_%03d", limite, taille_fich, i);
            strcat(nom_fichier, ".csv");
        }
        // Lire et trier le fichier, puis afficher les résultats
        printf("%d", taille_fich);

        // Utilisation d'un tableau dynamique
        int *tab = malloc(taille_fich * sizeof(int));
        if (tab == NULL) {
            perror("Erreur d'allocation de mémoire");
            exit(EXIT_FAILURE);
        }
        //lire_fichier_csv(nom_fichier, tab, taille_fich);
        printf("\n\n=== Test pour %s ===\n", nom_fichier);
        test_tri(tab, taille_fich, nom_fichier, choix, verif_tab, affichage, nom_sauvegarde_csv, num_module_tri, limite);
        free(tab);
        // decrémentation du pas
        taille_fich = taille_fich - pas_difference;
    }
}
