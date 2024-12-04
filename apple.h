#ifndef APPLE_H
#define APPLE_H
#include "struct.h"

#define FRUITS 5
#define LARGEUR_GRILLE 60
#define HAUTEUR_GRILLE 40


void dessinerFruits(struct Fruit *fruit);
void detecterCollisionsAvecFruits(struct Serpent *serpent, struct Fruit *fruits, int *scores);

#endif /* APPLE_H */
