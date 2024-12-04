#ifndef OBSTACLE_H
#define OBSTACLE_H
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



void initialiserObstacles(struct Obstacles *obstacles);
void dessinerObstacles(struct Obstacles *obstacles, int choix);
void detecterCollisionsAvecObstacles(struct Serpent *serpent, struct Obstacles *obstacles, int *perdu);
void bougerObstacles(struct Obstacles *obstacles);
void changerObstacles(struct Obstacles *obstacles);
void afficherObstacles(struct Obstacles *obstacles);



#endif /* OBSTACLE_H */
