#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

/**
 * Affiche la grille en parcourant l'ensemble de la grille
 * et en affichant le code ASCII de chaque case 
 */
void afficherGrille(Jeu *jeu) {
	int l, c;
	for(l = jeu->ligne-1; l >= 0; l--) {
		for(c = 0; c < jeu->col; c++)
			printf(" %c ", jeu->grille[l * jeu->col + c]);
		printf("\n\n");
	}
}

/**
 * Affiche le menu : 1 pour jouer, 2 pour le tableau de score
 * et 3 pour quitter
 */
void afficherMenu(void) {
	printf("\n ** PUISSANCE 6 ** \n\n"
		   "-Menu :\n"
		   "1. Jouer \n"
		   "2. Tableau de scores\n"
		   "3. Quitter \n\n"
		  );
}

/**
 * Affiche le tour actuelle dans la partie et le nom de la 
 * personne qui doit jouer (passés en paramètre)
 */
void afficherTour(int tour, char *nom) {
	printf("\n--------\n");
	printf("Tour [%d] : %s\n", tour+1, nom);
}

/**
 * Affiche le nom du vainqueur (passée en paramètre),
 * ou match nul en vérifiant la valeur "gagnant" passée 
 * en paramètre.
 */
void afficherVainqueur(int gagnant, char *nom) {
 	(gagnant) ? printf("Vainqueur : %s\n", nom) :
 				printf("Match nul...\n"); 
}

/**
 * Affiche le score en ouvrant le fichier "score.txt"
 * en mode lecture et lisant caractère par caractère
 * le fichier txt
 */
void afficherScore(Jeu *jeu) {
	int c;
	FILE *fichier = fopen("score.txt", "r");
	printf("\nSCORE : \n");
	printf("-------\n");
	while((c=fgetc(fichier)) != EOF) {
		printf("%c", c);
	}
	printf("-------\n\n");
}
