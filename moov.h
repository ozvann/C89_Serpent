#ifndef MOOV_H
#define MOOV_H
#include "struct.h"


#define LARGEUR_GRILLE 60
#define HAUTEUR_GRILLE 40
#define TAILLE_CASE 10
#define FRUITS 5
#define MAX_SEGMENTS 600
#define OBSTACLES 10

/* Définition des constantes pour les directions */
#define HAUT 0
#define BAS 1
#define GAUCHE 2
#define DROITE 3



void gererInputs(int *direction, int*enPause, int *finDuJeu, int *prochaineDirection);
int mettreAJourDirection(struct Serpent serpent);








#endif /* MOOV_H */
