#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>


#include "score.h"
#include "apple.h"
#include "serpent.h"









void afficherScore(int *scores) {
  static long startTime = 0;
  char texte[20];  
  int taille = 1;
  /*long currentTime = (long)time(NULL);*/
  /*long elapsedTime = currentTime - startTime;*/

  int x = 20;
  int y = 475;

  sprintf(texte, "score : %02d", *scores);
  ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
  EcrireTexte(x, y, texte, taille);

  if (startTime == 0) {
    startTime = (long)time(NULL);
  }
}