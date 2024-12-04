# CHAPITRE 1 : BUT FINAL

but : game

# CHAPITRE 2 : VARIABLES

OFILES = apple.o \
         moov.o \
	 serpent.o \
	 terrain.o \
	 temps.o \
	 score.o \
	 menu.o \
	 obstacle.o \
	 groupe.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g -lgraph

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

apple.o : apple.h serpent.h score.h moov.h struct.h

moov.o : moov.h apple.h serpent.h terrain.h struct.h

serpent.o : serpent.h apple.h terrain.h moov.h struct.h

terrain.o : terrain.h temps.h score.h moov.h serpent.h struct.h

temps.o : temps.h struct.h

score.o : score.h serpent.h apple.h struct.h

groupe.o : apple.h moov.h serpent.h terrain.h temps.h score.h menu.h obstacle.h

menu.o : menu.h

obstacle.o : obstacle.h menu.h struct.h



#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES


game : $(OFILES)
	$(CC) $(CFLAGS) -o game $(OFILES)

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) game

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean


run :
	./game
