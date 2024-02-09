# Complexité des algorithmes de tri en C et en Python

- DURANDEAU Matéo
- Projet de SAE

## Installation de la librairie matplotlib

Exécutez `pip install matplotlib` dans le terminal Python.

## Comment ça marche :

### 1. Création d'un jeu de données pour les tests composé de : 
  - Cas moyen
  - Meilleur cas
  - Pire cas

Pour cela, utilisez la fonction : `generation_run(10000, 1, 100, 100, 100);` dans le `main` avec les paramètres suivants :
  - taille
  - numéro du cas
  - nombre de fichiers
  - pas de différence
  - X : Pour le cas moyen : la taille des nombres entre 1 et X

Sinon, enlevez les commentaires pour créer le jeu de données prédéfini.

#### Important : 
Mettez les fichiers du jeu de données dans un répertoire nommé : `tableau/`

### 2. Effectuer les tests sur l'algorithme de tri choisi :

#### Pour le Python 
Tout d'abord, déposez l'algorithme de tri dans le fichier : `module_tri.py`. 
Ensuite, dans la fonction `utiles.py`, ajoutez le bout de code indiqué dans la fonction : `temps_exec`.
Pour finir, lancez l'exécution de la fonction `utiles.test_tri_run` avec les paramètres indiqués dans le `main.py`.

#### Pour le C
Étapes similaires pour l'ajout de l'algorithme de tri et l'ajout du bout de code dans la fonction `temps_exec` dans le fichier : `utiles.c`.
Lancez la fonction `test_tri_run` avec les paramètres indiqués dans le `main.c`.

### 3. Afficher les résultats sous forme de graphiques pour effectuer des comparaisons : 
Voir le fichier `graphique.py` qui fait les graphiques sous matplotlib. 
Exécutez la fonction : `multi_graph(fichiers, couleurs)` avec les paramètres suivants : 
une liste qui contient les noms de sauvegarde des fichiers résultats et le label,
une liste de couleur pour chaque graphique (en anglais).

Exemple :
```python
multi_graph(
    [(nom1, 'Fichier 1 (C rouge)'), (nom2, 'Fichier 2 (C bleu)')], 
    ['red', 'blue']
)
