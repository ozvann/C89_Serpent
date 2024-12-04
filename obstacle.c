#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "struct.h"
#include "obstacle.h"




void initialiserObstacles(struct Obstacles *obstacles){
  int i;
  for(i=0; i < OBSTACLES; i++){
    obstacles[i].x = rand() % LARGEUR_GRILLE;
    obstacles[i].y = rand() % HAUTEUR_GRILLE;
  }
}

void dessinerObstacles(struct Obstacles *obstacles, int choix){
  int i;
  if(choix == 2){
  for(i=0; i < OBSTACLES; i++){
    ChoisirCouleurDessin(CouleurParNom("blue"));
    RemplirRectangle(obstacles[i].x * TAILLE_CASE, obstacles[i].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
  }
 }
}
void detecterCollisionsAvecObstacles(struct Serpent *serpent, struct Obstacles *obstacles, int *perdu){
  int i, j;
  for(i=0; i<serpent->longueur; i++){
    for(j=0; j < OBSTACLES; j++){
      if(serpent->segments[i].x == obstacles[j].x && serpent->segments[i].y == obstacles[j].y){
        *perdu = 1;
        return;
      }
    }
  }
}

void bougerObstacles(struct Obstacles *obstacles){
  int i;
  for(i=0; i < OBSTACLES; i++){
    obstacles[i].x = (obstacles[i].x + 1) % LARGEUR_GRILLE;
    obstacles[i].y = (obstacles[i].y + 1) % HAUTEUR_GRILLE;
  }
}

void changerObstacles(struct Obstacles *obstacles){
  int i;
     for(i=0; i < OBSTACLES; i++){
      obstacles[i].x = rand () % LARGEUR_GRILLE;
      obstacles[i].y = rand () % HAUTEUR_GRILLE;
     }
  }
void afficherObstacles(struct Obstacles *obstacles){
  int i;
  for(i=0; i < OBSTACLES; i++){
    ChoisirCouleurDessin(CouleurParNom("blue"));
    RemplirRectangle(obstacles[i].x * TAILLE_CASE, obstacles[i].y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
  }
}

