#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "jeu.h"
#include "grille.h"
#include "joueur.h"

/**
 * Initialise les informations concernant les joueurs :
 * couleur (symbole prédéfini à l'aide d'un tableau),
 * nom (utilisation de scanf pour que l'utilisateur
 * entre son nom), score à 0 au départ pour tout le
 * monde 
 */
void initJoueur(Jeu *jeu) {
	int j_id;
	const char symbole[] = {'X', '0', '#', 'Y', 'I', '+', '-', 'M', '$', 'W'};

	if(NJOUEURS > NSYMBOLES) {
		fprintf(stderr, "Erreur : Pas assez de symboles (%d) pour le nombre de joueurs demandé (%d).\n",
						NSYMBOLES, NJOUEURS);
		exit(0);
	}

	for(j_id = 0; j_id < NJOUEURS; j_id++) {
		jeu->joueur[j_id].couleur = symbole[j_id];
		jeu->joueur[j_id].nom = strdup(choisirNom(j_id));
		jeu->joueur[j_id].score = 0;	
	}
}

/**
 * Demande à l'utilisateur d'entrer son nom à l'aide d'un "scanf" et
 * continuera de demander tant que le nom ne contiendra ni tiret ni
 * point
 */
char* choisirNom(int j_id) {
	char *nom = malloc(256 * sizeof(*nom));
	assert(nom);
	do {
		printf("Nom J%d : ", j_id);
		scanf("%s", nom);
	} while(strstr(nom, "-") || strstr(nom, "."));

	return nom;
}

/**
 * Choisit la colonne que souhaite jouer l'utilisateur à l'aide
 * d'un "scanf". L'utilisateur devra forcément entrer un nombre
 * entre 1 et le nombre de colonne, et devra choisir une colonne
 * qui n'est pas pleine. Sinon il ne sortira pas de la boucle
 * while.
 * On retourne la valeur entrée par l'utilisateur
 */
int choisirColonne(Jeu *jeu) {
	int col = 0; 
	do {
		printf("Veuillez choisir une colonne : ");
		scanf("%d", &col);
		col--;
	} while(col < 0 || (col+1) > jeu->col || jeu->grille[(jeu->ligne-1) * jeu->col + col] != VIDE);

	return col;
}

/**
 * Place le jeton de couleur X (passée en paramètre selon la 
 * colonne demandée (passée en paramètre également) en coulissant 
 * le jeton jusqu'à ce qu'il soit sur une case VIDE
 */
void placerJeton(Jeu *jeu, int col, int couleur) {
	int l;
	for(l = 0; l < jeu->ligne; l++) {
		if(jeu->grille[l * jeu->col + col] == VIDE) {
			jeu->grille[l * jeu->col + col] = couleur;
			return;
		}
	}
}
