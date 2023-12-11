import csv
import os
import matplotlib.pyplot as plt

def lire_csv(nom_fichier):
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
    plt.plot(taille, temps, marker='o', label=label, color=color)

def main():
    fichier1 = 'resultat_C/resultat_cm_1.csv'
    fichier2 = 'resultat_python/py_resultat_cm_1.csv'

    data1 = lire_csv(fichier1)
    data2 = lire_csv(fichier2)

    plt.figure(figsize=(10, 6))

    plot_graph(data1[0], data1[1], 'Fichier 1 (Rouge)', 'red')
    plot_graph(data2[0], data2[1], 'Fichier 2 (Bleu)', 'blue')

    plt.title('Graphique de temps d\'exécution en fonction de la taille (échelle linéaire)')
    plt.xlabel('Taille du fichier')
    plt.ylabel('Temps d\'exécution (s)')
    plt.xscale('linear')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    main()
