#ifndef SERPENT_H
#define SERPENT_H
#include "struct.h"


#define FRUITS 5
#define LARGEUR_GRILLE 60
#define HAUTEUR_GRILLE 40
#define TAILLE_CASE 10
#define MAX_SEGMENTS 600
#define HAUT 0
#define BAS 1
#define GAUCHE 2
#define DROITE 3


void dessinerSerpent(struct Serpent serpent);
void mettreAJourJeu(struct Serpent *serpent, int direction, int *finDuJeu);
void detecterCollisions(struct Serpent serpent, int *perdu);
void detecterCollisionsAvecSerpent(struct Serpent *serpent, int *perdu);




#endif /* SERPENT_H */
