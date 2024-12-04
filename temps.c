#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>

#include "temps.h"





void afficherTexte() {
  static long startTime = 0;
  char texte[20];  
  int taille = 1;
  long currentTime = (long)time(NULL);
  long elapsedTime = currentTime - startTime;

  int minutes = (int)(elapsedTime / 60);
  int seconds = (int)(elapsedTime % 60);
  int x = 400;
  int y = 475;

  sprintf(texte, "Temps : %02d : %02d", minutes, seconds);
  ChoisirCouleurDessin(CouleurParComposante(0, 0, 0));
  
  EcrireTexte(x, y, texte, taille);

  if (startTime == 0) {
    startTime = (long)time(NULL);
  }
}
