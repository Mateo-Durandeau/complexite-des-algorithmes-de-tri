#tri de shell avec des seq d'intervalles normalement pré-optimisé.
def tri_de_shell_seq(tab):
    # Séquence d'intervalles pré-optimisée
    intervalles = [701, 301, 132, 57, 23, 10, 4, 1]

    # Boucle qui parcours le tableau intervalles
    for gap in intervalles: 
        # Tri par insertion avec l'intervalle actuel
        # boucle de range gap jusqu'a la taille du tableau
        for i in range(gap, len(tab)):
            cle = tab[i]
            j = i

            while j >= gap and cle < tab[j - gap]:
                tab[j] = tab[j - gap]
                j -= gap

            tab[j] = cle

#tri de shell avec sans seq d'intervalles normalement pré-optimisé.
def tri_de_shell(tab):
    intervalle = len(tab) // 2

    while intervalle > 0:
        for i in range(intervalle, len(tab)):
            cle = tab[i]
            j = i

            while j >= intervalle and cle < tab[j - intervalle]:
                tab[j] = tab[j - intervalle]
                j -= intervalle

            tab[j] = cle

        intervalle //= 2

        
# AJOUTER LES ALGORITHMES DE TRI
