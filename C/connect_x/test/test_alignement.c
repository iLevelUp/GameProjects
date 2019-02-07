#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test_alignement.h"


/* Initialise la grille */
void initGrille(Jeu *jeu) {
	int pos;
	for (pos = 0; pos < jeu->col * jeu->ligne; pos++)
		jeu->grille[pos] = VIDE;
}

/* Pose le jeton dans la grille (sans gravité) */
void poserJeton(Jeu *jeu, int couleur, int x, int y) {
	jeu->grille[y * jeu->col + x] = couleur;
}

/* Vérifie si la position est valide */
int positionValide(Jeu *jeu, int *lignes, int *colonnes, int id) {
	return (lignes[id] >= 0 && lignes[id] < jeu->ligne &&
			colonnes[id] >= 0 && colonnes[id] < jeu->col);
}

/* Vérifie si il y a une série de NCMPT jetons de même couleur dans la grille */
int verifierAlignement(Jeu *jeu, int couleur, int ligne, int colonne, int dy, int dx, int dy0, int dx0) {
	if(couleur == VIDE)
		return 0;
	
	int max = 0, i, compteur = 1;
	int lignes[2] = {ligne + dy, ligne + dy0}, 
		colonnes[2] = {colonne + dx, colonne + dx0};

	while(positionValide(jeu, lignes, colonnes, 0) ||
		  positionValide(jeu, lignes, colonnes, 1)) {

		for(i = 0; i < sizeof(lignes)/sizeof(*lignes); i++) {

			if(positionValide(jeu, lignes, colonnes, i) &&
			   jeu->grille[lignes[i] * jeu->col + colonnes[i]] ==  couleur)
				compteur++;

			if(compteur > max)
				max = compteur;

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

	if(max > jeu->max_cmpt)
		jeu->max_cmpt = max;
	return (max >= NCMPT);
}


/* Affiche la grille */
void afficherGrille(Jeu *jeu) {
	int l, c;
	for(l = jeu->ligne-1; l >= 0; l--) {
		for(c = 0; c < jeu->col; c++)
			printf(" %c ", jeu->grille[l * jeu->col + c]);
		printf("\n\n");
	}
}


/* Vérifie si il existe un gagnant dans la partie */
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


/* Retourne VRAI si il y a un vainqueur sinon FAUX */
char* afficherGagnant(int gagnant) {
	char *nom_gagnant;
	if(gagnant)
		nom_gagnant = strdup("VRAI");
	else
		nom_gagnant = strdup("FAUX");

	return nom_gagnant;
}
