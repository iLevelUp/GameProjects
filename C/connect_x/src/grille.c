#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "grille.h"
#include "affichage.h"

/**
 * Initialise la grille en mettant tous les éléments
 * de la grille à VIDE.
 */
void initGrille(Jeu *jeu) {
	int pos;
	for(pos = 0; pos < jeu->ligne * jeu->col; pos++)
		jeu->grille[pos] = VIDE;
}

/**
 * Vérifie si la grille est pleine en parcourant toute
 * la grille et en cherchant si il existe un élément
 * qui vaut VIDE. Si c'est le cas, la fonction retourne
 * 0 sinon elle retourne 1
 */
int plein(Jeu *jeu) {
	int pos;
	for(pos = 0; pos < jeu->ligne * jeu->col; pos++) {
		if(jeu->grille[pos] == VIDE)
			return 0;
	}

	return 1;
}

/**
 * Vérifie si la position du jeton est valide c'est-à-dire
 * si il ne sort pas de l'écran (inférieur à 0 ou supérieur
 * aux dimensions de la grille)
 */
int positionValide(Jeu *jeu, int *lignes, int *colonnes, int id) {
	return (lignes[id] >= 0 && lignes[id] < jeu->ligne &&
			colonnes[id] >= 0 && colonnes[id] < jeu->col);
}

/**
 * Vérifie si il existe des alignements en partant d'un 
 * point et en parcourant sur deux directions (L dans 
 * quatres angles). Si à chaque parcours des directions,
 * il s'agit du même jeton alors on incrémente le
 * le compteur sinon on arrête de parcourir les directions
 * et on retourne 0. On retourne 1 si le compteur est
 * équivalent à NCMPT (c'est-à-dire au compteur max)
 */
int verifierAlignement(Jeu *jeu, int couleur, int ligne, int colonne, int dy, int dx, int dy0, int dx0) {
	if(couleur == VIDE)
		return 0;
	
	
	int i, compteur = 1;
	int lignes[2] = {ligne + dy, ligne + dy0}, 
		colonnes[2] = {colonne + dx, colonne + dx0};

	while(positionValide(jeu, lignes, colonnes, 0) ||
		  positionValide(jeu, lignes, colonnes, 1)) {

		for(i = 0; i < sizeof(lignes)/sizeof(*lignes); i++) {
 
			if(positionValide(jeu, lignes, colonnes, i) &&
			   jeu->grille[lignes[i] * jeu->col + colonnes[i]] ==  couleur)
				compteur++;

			if(compteur == NCMPT)
				return 1;

			if (lignes[i] >= 0 && colonnes[i] >= 0) {
				if(jeu->grille[lignes[i] * jeu->col + colonnes[i]] != couleur)
					lignes[i] = colonnes[i] = -1;

				else {
					lignes[i] += (i == 0 ? dy : dy0);
					colonnes[i] += (i == 0 ? dx : dx0);
				}
			}
		}
	}

	return 0;
}

/**
 * Vérifie si il existe un gagnant en parcourant la grille
 * et en appelant la fonction "verifierAlignement" qui vérifie
 * si il existe des alignements. Si il existe un nombre de jetons
 * alignés équivalent à NCMPT (nombre de jetons alignés max demandé)
 * alors on retourne 1 sinon on retourne 0
 */
int estGagnant(Jeu *jeu) {
	const int dirx[] = {-1,  0, 1, 0};
	const int diry[] = { 0, -1, 0, 1};
	const int jeton_dir[NALIGN][NDIR] = {
		{diry[HAUT], dirx[HAUT], diry[DROITE], dirx[DROITE]},
		{diry[HAUT], dirx[HAUT], diry[GAUCHE], dirx[GAUCHE]},
		{diry[BAS], dirx[BAS], diry[GAUCHE], dirx[GAUCHE]},
		{diry[BAS], dirx[BAS], diry[DROITE], dirx[DROITE]}
	};

	int l, c, align;
	for(l = 0; l < jeu->ligne; l++) {
		for(c = 0; c < jeu->col; c++) {
			for(align = 0; align < NALIGN; align++) 
				if(verifierAlignement(jeu, 
									  jeu->grille[l * jeu->col + c], 
									  l, c, 
									  jeton_dir[align][0], jeton_dir[align][1], jeton_dir[align][2], jeton_dir[align][3]))
					return 1;
		}
	}
	
	return 0;
}
