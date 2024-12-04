#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>

#include "struct.h"
#include "terrain.h"
#include "apple.h"
#include "serpent.h"
#include "moov.h"






  void dessinerSerpent(struct Serpent serpent) {
    int i;
    ChoisirCouleurDessin(CouleurParNom("yellow"));
    for(i=0; i < serpent.longueur; i++) {
      RemplirRectangle(serpent.segments[i].x * TAILLE_CASE, serpent.segments[i].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
     }
  }



void mettreAJourJeu(struct Serpent *serpent, int direction, int *finDuJeu) {
    int i;
    
    int queueX = serpent->segments[serpent->longueur - 1].x;
    int queueY = serpent->segments[serpent->longueur - 1].y;

    /* Déplacement commun pour toutes les directions sauf le cas par défaut*/
    for(i = serpent->longueur - 1; i > 0; i--) {
        serpent->segments[i].x = serpent->segments[i - 1].x;
        serpent->segments[i].y = serpent->segments[i - 1].y;
    }

    /* Déplacement spécifique en fonction de la direction*/
    switch(direction) {
        case HAUT:
            serpent->segments[0].y--;
            break;
        case BAS:
            serpent->segments[0].y++;
            break;
        case GAUCHE:
            serpent->segments[0].x--;
            break;
        case DROITE:
            serpent->segments[0].x++;
            break;
        default:
            break;
    }
 }




void detecterCollisions(struct Serpent serpent, int *perdu) {
  int i;

  /* Vérifier les collisions avec les bords de la grille*/
  for (i = 0; i < serpent.longueur; i++) {
    if (serpent.segments[i].x < 0 || serpent.segments[i].x >= LARGEUR_GRILLE ||
        serpent.segments[i].y < 0 || serpent.segments[i].y >= HAUTEUR_GRILLE) {
      *perdu = 1;
      break;
    }
  }
}



 void detecterCollisionsAvecSerpent(struct Serpent *serpent, int *perdu) {
   int i;
   for(i = 1; i < serpent->longueur; i++){
    if(serpent->segments[0].x == serpent->segments[i].x && 
      serpent->segments[0].y == serpent->segments[i].y) {
      *perdu = 1;
      break;
    }
  }
}