#include <stdio.h>
#include "module.h"


// ############# fonction tri de shell avec sequence d'intervalle optimisé ##############
void tri_de_shell_seq(int tableau[], int taille) {
    // Séquence d'intervalles pré-optimisée
    int intervalles[] = {701, 301, 132, 57, 23, 10, 4, 1};

    // Boucle sur les intervalles de la séquence
    for (int k = 0; k < sizeof(intervalles) / sizeof(intervalles[0]); k++) {
        int gap = intervalles[k];

        // Tri par insertion avec l'intervalle actuel
        for (int i = gap; i < taille; i++) {
            int cle = tableau[i];
            int j = i;

            while (j >= gap && cle < tableau[j - gap]) {
                tableau[j] = tableau[j - gap];
                j -= gap;
            }

            tableau[j] = cle;
        }
    }
}

// ############# fonction tri de shell sans sequence d'intervalle optimisé ##############
// on peut faire un intervalle divisé par trois mais j'ai choisis celui la
void tri_de_shell(int tableau[], int taille) {
    int intervalle = taille / 2;

    while (intervalle > 0) {
        for (int i = intervalle; i < taille; i++) {
            int cle = tableau[i];
            int j = i;

            while (j >= intervalle && cle < tableau[j - intervalle]) {
                tableau[j] = tableau[j - intervalle];
                j -= intervalle;
            }

            tableau[j] = cle;
        }

        intervalle /= 2;
    }
}
