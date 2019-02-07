#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "menu.h"
#include "affichage.h"

/**
 * Choisit l'option que souhaite jouer l'utilisateur à l'aide
 * d'un "scanf". L'utilisateur devra forcément entrer un nombre
 * entre 1 et le nombre d'option NOPTIONS. Sinon il ne sortira 
 * pas de la boucle while.
 * On retourne la valeur entrée par l'utilisateur
 */
int choisirOption(void) {
	int option = 0;

	do {
		printf("Que voulez-vous : ");
		scanf("%d", &option);
		option--;	
	} while(option < 0 || option > NOPTIONS);

	return option;
}

/**
 * Sauvegarde le score du (dernier) gagnant (le nombre de partie 
 * remportée lors du lancement du jeu) en ouvrant le fichier
 * "score.txt" en écriture (ajout), et écrivant à l'aide de "fprintf"
 * dans le fichier txt
 */
void sauvegarder(Jeu *jeu, int vainqueur) {
	FILE * fichier = fopen("score.txt", "a");
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	fprintf(fichier, "%s [%s] =  %d victoire*s\n\n",
						asctime(tm), jeu->joueur[vainqueur].nom, jeu->joueur[vainqueur].score);
	fclose(fichier);
}

/**
 * Demande à l'utilisateur si il souhaite jouer, afficher le tableau
 * de scores, ou quitter
 */
void menu(Jeu *jeu) {
	afficherMenu();
	switch(choisirOption()) {
		case JOUER:
			break;
		case SCORE:
			afficherScore(jeu);
			break;
		case QUITTER:
			exit(0);
	}
}
