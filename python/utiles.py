import csv
import time
import module_tri_shell
import os

def verification_tri(tableau):
    """ verification si le tableau est trié """
    max_value = tableau[0]
    erreur = False

    for value in tableau[1:]:
        if max_value > value:
            print("Erreur tableau")
            erreur = True
            break
        max_value = value

    if not erreur:
        print("Tableau valide\n")

def affiche_tab(tab):
    print(tab)

def copie_tab(tableau):
    """ fais une copie d'un tableau pour pouvoir le trier"""
    return list(tableau)

def lire_fichier_csv(nom_fichier):
    """ lecture des fichiers csv nombre et ecriture dans un tableau """
    tableau = []
    script_dir = os.path.dirname(__file__)  # Récupère le répertoire du script
    nom_fichier_path = os.path.join(script_dir, nom_fichier)
    with open(nom_fichier_path, 'r') as file:
        # lecture ligne par ligne du fichier csv
        reader = csv.reader(file)
        for row in reader:
            tableau.extend(map(int, row)) # ajout chaque ligne dans une tableau pour permettre un tri
    return tableau


def temps_exec(tableau, num_module_tri):
    """ calcul le temps d'execution en effectuant un tri avec ou sans sequence 100 fois"""
    module_tri_shell.tri_de_shell(tableau)
    temps_cpu_total = 0.0
    temps_cpu_copie = 0.0
    nombre_tests = 100

    for x in range(nombre_tests):
        if num_module_tri == 1:
            tableau_copie = copie_tab(tableau)
            debut = time.time()
            module_tri_shell.tri_de_shell(tableau_copie)
            fin = time.time()
            temps_cpu_total += fin - debut

        if num_module_tri == 2:
            debut = time.time()
            module_tri_shell.tri_de_shell_seq(tableau)
            fin = time.time()
            temps_cpu_total += fin - debut

        debut = time.time()
        copie_tab(tableau)
        fin = time.time()
        temps_cpu_copie += fin - debut

    temps_cpu_moyen_total = temps_cpu_total / nombre_tests

    print(f"Temps d'execution moyen (sans copie) : {temps_cpu_moyen_total} secondes\n")
    return temps_cpu_moyen_total



def sauvegarder_resultats_csv(nom_fichier, taille, temps_execution, type_run, limite):
    """ sauvegarde des resultats dans un fichier csv resultat """
    script_dir = os.path.dirname(__file__)  # Récupère le répertoire du script pour pouvoir lire les fichiers
    nom_fichier_path = os.path.join(script_dir, nom_fichier) #indique le nom du fichier avec le path avant

    with open(nom_fichier_path, 'a') as fichier:
        # ecriture dans le fichier csv des resultats
        fichier.write(f"{type_run}, {limite}, {taille}, {temps_execution}\n")


def test_tri(tableau, nom_fichier_csv, choix, verif_tab, affichage, nom_sauvegarde_csv, num_module_tri, limite):
    """ test d'un tri avec temps execution sur un fichier avec paramètre d'affichage et de vérification """
    tab = lire_fichier_csv(nom_fichier_csv)
    temps_execution = temps_exec(tab, num_module_tri)

    if verif_tab:
        verification_tri(tab)

    if affichage:
        affiche_tab(tab)

    if choix == 1 and num_module_tri == 1:
        sauvegarder_resultats_csv(nom_sauvegarde_csv, len(tab), temps_execution, "cm-1", limite)
    if choix == 1 and num_module_tri == 2:
        sauvegarder_resultats_csv(nom_sauvegarde_csv, len(tab), temps_execution, "cm-2", limite)

    if choix == 2 and num_module_tri == 1:
        sauvegarder_resultats_csv(nom_sauvegarde_csv, len(tab), temps_execution, "pc-1", limite)
    if choix == 2 and num_module_tri == 2:
        sauvegarder_resultats_csv(nom_sauvegarde_csv, len(tab), temps_execution, "pc-2", limite)

    if choix == 3 and num_module_tri == 1:
        sauvegarder_resultats_csv(nom_sauvegarde_csv, len(tab), temps_execution, "mc-1", limite)
    if choix == 3 and num_module_tri == 2:
        sauvegarder_resultats_csv(nom_sauvegarde_csv, len(tab), temps_execution, "mc-2", limite)


def test_tri_run(taille_fich, num_module_tri, Nb_tab, pas_difference, verif_tab, affichage, choix, nom_sauvegarde_csv, limite):
    """ test tri sur une run complete de fichier csv nombre fais en C """
    for i in range(1, Nb_tab + 1):
        nom_fichier = ""
        if choix == 1:
            nom_fichier = f"tableau/cm/tab_cm_{limite}_{taille_fich}_{i:03d}.csv"
        elif choix == 2:
            nom_fichier = f"tableau/pc/tab_pc_{limite}_{taille_fich}_{i:03d}.csv"
        elif choix == 3:
            nom_fichier = f"tableau/mc/tab_mc_{limite}_{taille_fich}_{i:03d}.csv"

        tab = lire_fichier_csv(nom_fichier)
        print(f"{taille_fich}\n\n=== Test pour {nom_fichier} ===")
        test_tri(tab, nom_fichier, choix, verif_tab, affichage, nom_sauvegarde_csv, num_module_tri, limite)
        taille_fich -= pas_difference
