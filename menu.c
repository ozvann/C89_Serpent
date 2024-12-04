#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>






int afficherMenu() {
  int SourisX, SourisY;
  int choix = 0;
  int x = 100, y = 100;
  EffacerEcran(CouleurParNom("green"));

  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(x,y, "Menu Principal", 2);

  y+=50;

  EcrireTexte(x, y, "1. Jeu de Base",1);
  y+=30;

  EcrireTexte(x, y, "2. Jeu avec des obstacles", 1);
  y+=30;

  while(!SourisCliquee()){
   SourisPosition();
   SourisX = _X;
   SourisY = _Y;

  if(SourisX > 130 && SourisY < 160 ){
    choix = 1;
  }else if(SourisX > 160 && SourisY > 190){
    choix = 2;
  }
}
  return choix;
}
