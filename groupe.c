#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>


#include "serpent.h"
#include "terrain.h"
#include "moov.h"
#include "temps.h"
#include "score.h"
#include "apple.h"
#include "obstacle.h"


/* Fonction qui remplace usleep */
void moinsuneseconde() {
  clock_t start = clock();
  clock_t current;
  do {
    current = clock();
  } while (((double)(current - start) / CLOCKS_PER_SEC) < 0.15);
}

void theEnd() {
  clock_t start = clock();
  clock_t current;
  do {
    current = clock();
  } while (((double)(current - start) / CLOCKS_PER_SEC) < 5);
}



int main(void) {
  struct Serpent serpent;
  struct Fruit fruits[FRUITS];
  struct Obstacles obstacles[OBSTACLES];
  int perdu = 0, finDuJeu = 0, direction = DROITE;
  int prochaineDirection = -1;
  int x = 0, y = 400, l = 700, h = 1000;
  int enPause = 0;
  int scores = 0;
  int choix = 0;
  
  

  InitialiserGraphique();
  srand((unsigned int)time(NULL));
  CreerFenetre(10, 10, LARGEUR_GRILLE * TAILLE_CASE + 1, HAUTEUR_GRILLE * TAILLE_CASE + 100);
  EffacerEcran(CouleurParNom("green"));
      changerObstacles(obstacles);
      bougerObstacles(obstacles);

  while(choix == 0){
    choix = afficherMenu();
    switch(choix){
      case 1:
        printf("Lancement du jeu de base\n");
        initialiserJeu(&serpent, fruits);
        break;
      case 2:
        printf("Lancement du jeu avec obstacles\n");
        initialiserJeu(&serpent, fruits);
        initialiserObstacles(obstacles);
        dessinerObstacles(obstacles, choix);
        afficherObstacles(obstacles);
        break;
      default:
        printf("Choix invalide. Veuillez selectionner une option valide.\n");
      break;
    }
  }
  while(!finDuJeu) {
    EffacerEcran(CouleurParNom("green"));
      dessinerObstacles(obstacles, choix);
      detecterCollisionsAvecObstacles(&serpent, obstacles, &perdu);

    gererInputs(&direction, &enPause, &finDuJeu, &prochaineDirection);
    if(prochaineDirection != -1) {
      direction = prochaineDirection;
    }
    if(!enPause) {
      mettreAJourJeu(&serpent, direction, &finDuJeu);
      detecterCollisionsAvecSerpent(&serpent, &perdu);
      detecterCollisionsAvecFruits(&serpent, fruits, &scores);
      dessinerSerpent(serpent);
      dessinerFruits(fruits);
      ChoisirCouleurDessin(CouleurParNom("brown"));
      RemplirRectangle(x, y, l, h);
      afficherScore(&scores);
      afficherTexte();
      moinsuneseconde();
      detecterCollisions(serpent, &perdu);

    if(choix == 2) {
      static time_t lastObstaclesChange = 0;
      time_t currentTime = time(NULL);
      if(currentTime - lastObstaclesChange >= 8){
        lastObstaclesChange = currentTime;
        changerObstacles(obstacles);
      }
    }
    if(perdu) {
      finDuJeu = 1;
      printf("perdu\n");
      
      } else {
        if( enPause && ToucheEnAttente() && Touche() == XK_space){
          while(ToucheEnAttente() && Touche() == XK_space) {}
          enPause = 0;
        }
      }
    }
  }
  theEnd();
  FermerGraphique();
  return EXIT_SUCCESS;
}