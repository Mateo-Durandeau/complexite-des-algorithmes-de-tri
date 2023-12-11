import utiles



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