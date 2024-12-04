#include<stdlib.h>
#include<stdio.h>
#include <graph.h>

#include "serpent.h"
#include "terrain.h"
#include "apple.h"
#include "moov.h"







void gererInputs(int *direction, int *enPause, int *finDuJeu, int *prochaineDirection) {
    if(ToucheEnAttente()) {
        KeySym touchePressee = Touche();

        if (touchePressee == XK_Up) {
            *direction = HAUT;
        } else if(touchePressee == XK_Down) {
            *direction = BAS;
        } else if(touchePressee == XK_Left) {
            *direction = GAUCHE;
        } else if(touchePressee == XK_Right) {
            *direction = DROITE;
        }else if(touchePressee == XK_Escape) {
            *finDuJeu = 1;
        }else if(touchePressee == XK_space) {
          *enPause = !(*enPause);
        }
    }
}




int mettreAJourDirection(struct Serpent serpent) {
  int prochaineDirection = -1;
  if(ToucheEnAttente()) {
    int presser = Touche();
    if(presser == XK_Up || presser == XK_Down || presser == XK_Left || presser == XK_Right){
      prochaineDirection = presser;
    }
  }
  return prochaineDirection;
}


