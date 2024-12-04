#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>

#include "serpent.h"
#include "moov.h"
#include "apple.h"
#include "score.h"







void dessinerFruits(struct Fruit *fruits) {
  int j;
  for (j=0; j < FRUITS; j++){
    if(fruits[j].actif) {
      ChoisirCouleurDessin(CouleurParNom("red"));
      RemplirRectangle(fruits[j].x * TAILLE_CASE, fruits[j].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    }
  }
}


void detecterCollisionsAvecFruits(struct Serpent *serpent, struct Fruit *fruits, int *scores) {
  int i;
  for (i = 0; i < FRUITS; i++) {
    if (fruits[i].actif && serpent->segments[0].x == fruits[i].x && serpent->segments[0].y == fruits[i].y) {
      fruits[i].actif = 0;
      serpent->longueur++;       

      serpent->segments = realloc(serpent->segments, sizeof(struct Segment)* serpent->longueur);
      if(serpent->segments == NULL) {
        printf("Erreur d'allocation de mémoire pour les segments du serpent.\n");
        exit(EXIT_FAILURE);
      }    
      serpent->segments[serpent->longueur - 1].x = serpent->segments[serpent->longueur - 2].x;
      serpent->segments[serpent->longueur - 1].y = serpent->segments[serpent->longueur - 2].y;
      fruits[i].x = rand() % LARGEUR_GRILLE;
      fruits[i].y = rand() % HAUTEUR_GRILLE;
      fruits[i].actif = 1;
      *scores +=5;
      break;
    }
  }
}