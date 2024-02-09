import csv
import os
import matplotlib.pyplot as plt


def lire_csv(nom_fichier):
    """
    Transpose un fichier csv qui contient le temps et la taille des testes effectues en tuple de listes:

        nom_fichier : Nom du fichier qui contient les resultats d'un test sur un jeu de données
    
    """
    taille = []
    temps = []
    script_dir = os.path.dirname(os.path.abspath(__file__))
    nom_fichier_path = os.path.join(script_dir, nom_fichier)

    with open(nom_fichier_path, 'r') as file:
        reader = csv.reader(file, delimiter=';')
        for row in reader:
            taille.append(int(row[2]))
            temps.append(float(row[3]))

    return taille, temps

def plot_graph(taille, temps, label, color):
    """ 
    Initialisation d'un graphique multiples

        taille : liste des tailles d'un test 
        temps : liste des temps du meme test
        label : nom de legende
        color : couleur du graphique
    
    """
    plt.plot(taille, temps, marker='o', label=label, color=color)


def simple_graph(nom1, color='red'):
    """
    Graphique simple sur l'evolution d'un test sur des donnees

        nom1 : nom du fichier

    """
    data1 = lire_csv(nom1)

    plot_graph(data1[0], data1[1], 'Fichier 1 (C rouge)', color)

    #plt.figure(figsize=(10, 6))

    # affiche le tableau et ses éléments affiché, 
    plt.title('Graphique de temps d\'exécution en fonction de la taille (échelle linéaire)')
    plt.xlabel('Taille du fichier')
    plt.ylabel('Temps d\'exécution (s)')
    plt.xscale('log') # echelle d'affichage
    plt.legend()
    plt.grid(True)
    plt.show()

def multi_graph(fichiers, couleurs):
    """
    Trace des graphiques multiples pour chaque fichier specifie avec sa couleur correspondante.

    fichiers : liste de tuples contenant le chemin du fichier et le label du graphique.
    couleurs : liste des couleurs pour chaque graphique.
    """
    plt.figure(figsize=(10, 6))
    
    for (fichier, label), couleur in zip(fichiers, couleurs):
        data = lire_csv(fichier)
        plot_graph(data[0], data[1], label, couleur)

    plt.title('Graphique de temps d\'exécution en fonction de la taille (échelle linéaire)')
    plt.xlabel('Taille du fichier')
    plt.ylabel('Temps d\'exécution (s)')
    plt.xscale('log')  # ou 'linear' selon le besoin
    plt.legend()
    plt.grid(True)
    plt.show()


def main():

    nom1 = 'resultat_C/resultat_cm_1.csv', 
    nom2 = 'resultat_C/resultat_cm_2.csv'

    #simple_graph('resultat_C/resultat_cm_1.csv')

    multi_graph(
    [(nom1, 'Fichier 1 (C rouge)'), (nom2, 'Fichier 2 (C bleu)')], 
    ['red', 'blue'])


if __name__ == '__main__':
    main()
