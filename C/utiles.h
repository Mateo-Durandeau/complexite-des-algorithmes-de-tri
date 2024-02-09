#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED

extern void verification_tri(int [], int);
extern void affiche_tab(int [], int);

extern void copie_tab(int [], int [], int );

extern int lire_fichier_csv(const char *, int *, int);
extern float temps_exec(int [], int, int);

extern void sauvegarder_resultats_csv(const char *, int , float , const char *, int);
extern void test_tri(int [], int , const char *, int, int, int,  const char *, int, int);

extern void test_tri_run(int , int , int , int , int , int , int, const char *, int);

#endif // UTILES_H_INCLUDED
