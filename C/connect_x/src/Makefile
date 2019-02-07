CC=gcc
SRC=menu.c jeu.c grille.c joueur.c main.c affichage.c
OBJ=$(SRC:.c=.o)

p6:		$(OBJ)
	$(CC) $(OBJ) -o $@

affichage.o: jeu.h
grille.o: jeu.h grille.h affichage.h
jeu.o: jeu.h menu.h grille.h joueur.h affichage.h
joueur.o: jeu.h joueur.h 
menu.o: jeu.h menu.h affichage.h 

%.o:	%.c
	$(CC) -c -Wall $< 

clean:
	rm *.o p6
