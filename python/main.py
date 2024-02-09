import utiles

# Pour appeler la fonction test_tri_run : 
#   Args: 
#         Taille du nombres de nombres
#         nombre de tableau créer
#         pas de difference
#         numéro d'algorithme de tri définis dans le script utile.py
#         1 = verifier si le tableau est trié 
#         1 = afficher le tableau de nombres trié  
#         Choix du cas de test : 1 = cm ; 2 = pc ; 3 = mc
#         Nom du fichier de save 
#         nombres d'élément en 1 et x pour le cas moyen

utiles.test_tri_run(10000, 1, 100, 100, 1, 0, 1, "py_resultat_cm_1.csv", 100)
utiles.test_tri_run(10000, 1, 100, 100, 1, 0, 1, "py_resultat_cm_1.csv", 1000)
utiles.test_tri_run(1000000, 1, 9, 100000, 1, 0, 1, "py_resultat_cm_1.csv", 100)
utiles.test_tri_run(1000000, 1, 9, 100000, 1, 0, 1, "py_resultat_cm_1.csv", 1000)

utiles.test_tri_run(10000, 2, 100, 100, 1, 0, 1, "py_resultat_cm_2.csv", 100)
utiles.test_tri_run(10000, 2, 100, 100, 1, 0, 1, "py_resultat_cm_2.csv", 1000)
utiles.test_tri_run(1000000, 2, 9, 100000, 1, 0, 1, "py_resultat_cm_2.csv", 100)
utiles.test_tri_run(1000000, 2, 9, 100000, 1, 0, 1, "py_resultat_cm_2.csv", 1000)


utiles.test_tri_run(10000, 1, 100, 100, 1, 0, 2, "py_resultat_pc_1.csv", 100)
utiles.test_tri_run(1000000, 1, 9, 100000, 1, 0, 2, "py_resultat_pc_1.csv", 100)

utiles.test_tri_run(10000, 2, 100, 100, 1, 0, 2, "py_resultat_pc_2.csv", 100)
utiles.test_tri_run(1000000, 2, 9, 100000, 1, 0, 2, "py_resultat_pc_2.csv", 100)


utiles.test_tri_run(10000, 1, 100, 100, 1, 0, 3, "py_resultat_mc_1.csv", 100)
utiles.test_tri_run(1000000, 1, 9, 100000, 1, 0, 3, "py_resultat_mc_1.csv", 100)

utiles.test_tri_run(10000, 2, 100, 100, 1, 0, 3, "py_resultat_mc_2.csv", 100)
utiles.test_tri_run(1000000, 2, 9, 100000, 1, 0, 3, "py_resultat_mc_2.csv", 100)
