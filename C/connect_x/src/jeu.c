#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "menu.h"
#include "grille.h"
#include "joueur.h"
#include "affichage.h"

/// Tableau d'entier qui représente la grille du jeu
static int Grille[LIGNES * COLONNES];
/// Tableau de la structure Joueur qui représente l'ensemble des joueurs
static Joueur Jeton[NJOUEURS];

/**
 * Boucle principale qui appelle les autres fonctions (affichage, 
 * placement, vérification...). La boucle s'arrêtera que lorsqu'il
 * y a un gagnant ou lorsque la grille est pleine.
 * A la sortie de la boucle, on affiche le vainqueur, et on demande
 * à l'utilisateur si il souhaite rejouer. Et ensuite, on sauvegarde
 * le score dans un fichier txt
 */
void jouer(Jeu *jeu) {
	int gagnant;
	int tour;

	for(;;) {
		gagnant = tour = 0;
		while(!gagnant) {
			afficherTour(tour, jeu->joueur[tour%NJOUEURS].nom);
			placerJeton(jeu, choisirColonne(jeu), jeu->joueur[tour%NJOUEURS].couleur);
			afficherGrille(jeu);
	 		if(estGagnant(jeu)) {
	 			gagnant = 1;
	 			jeu->joueur[tour%NJOUEURS].score++;
				break;
	 		}
	 		if(plein(jeu)) break;
			tour++;
	 	}

	 	afficherVainqueur(gagnant, jeu->joueur[tour%NJOUEURS].nom);
		if(!choisirRejouer()) break;
		initGrille(jeu);
	 }

	sauvegarder(jeu,tour%NJOUEURS);
}

/**
 * Demande à l'utilisateur si il souhaite rejouer à l'aide
 * d'un "scanf". L'utilisateur doit entrer soit un nombre
 * strictement supérieur à 0 (pour rejouer), soit 0 (pour 
 * quitter). Si il entre un autre nombre, il devra réessayer.
 * On retourne la valeur donnée par l'utilisateur
 */
int choisirRejouer(void) {
	int rejouer = 0;
	printf("\nVoulez-vous rejouer (1/0) ? ");
	do {
		scanf("%d", &rejouer);
	} while (rejouer < 0);

	return rejouer;
}

/**
 * Initialise le jeu, en déclarant les données pour la 
 * structure principale "jeu", initialisant les informations
 * concernant les joueurs, en affichant le menu, 
 * en initialisant la grille, et en lançant la boucle demandant 
 * si l'on veut continuer à jouer 
 */
void initJeu(Jeu *jeu) {
	jeu->ligne = LIGNES;
	jeu->col = COLONNES;
	jeu->grille = Grille;
	jeu->joueur = Jeton;

	menu(jeu);
	initJoueur(jeu);
	initGrille(jeu);
	jouer(jeu);
}
