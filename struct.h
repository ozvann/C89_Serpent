#ifndef STRUCT_H
#define STRUCT_H

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


struct Obstacles {
  int x,y;

};

struct Fruit {
  int x,y;
  int actif;
};
struct Segment {
  int x, y;
};

struct Serpent {
  int longueur;
  struct Segment *segments;
};



#endif /* STRUCT_H */
