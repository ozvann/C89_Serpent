#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>


#include "apple.h"
#include "moov.h"
#include "serpent.h"
#include "temps.h"
#include "score.h"
#include "terrain.h"




void initialiserJeu(struct Serpent *serpent, struct Fruit *fruits) {
  int i, j;
  int snake = 10;
  if (LARGEUR_GRILLE <= 0 || HAUTEUR_GRILLE <= 0) {
    printf("Les dimensions de la grille doivent être supérieures à 0.\n");
    exit(EXIT_FAILURE);
  }

  /* struct Segment pastilles[FRUITS];*/
  serpent->longueur = snake;
  serpent->segments = malloc(sizeof(struct Segment) * snake);
  for (i = 0; i < snake; i++) {
    serpent->segments[i].x = LARGEUR_GRILLE / 2 - i;
    serpent->segments[i].y = HAUTEUR_GRILLE / 2;
  }


  for(j=0; j < FRUITS; j++){
    fruits[j].x = rand() % LARGEUR_GRILLE;
    fruits[j].y = rand() % HAUTEUR_GRILLE;
    fruits[j].actif = 1;
   }
}