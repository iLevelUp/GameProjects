#ifndef GRILLE_H___
#define GRILLE_H___

/// Compteur max, le nombre de jetons alignés identiques
#define NCMPT 6
/// Le nombre d'alignements possibles dans le jeu
#define NALIGN 4

/// Initialise la grille
void	initGrille(Jeu *jeu);
/// Vérifie si la grille est pleine
int 	plein(Jeu *jeu);
/// Vérifie si la position est valide
int 	positionValide(Jeu *jeu, int *lignes, int *colonnes, int id);
/// Vérifie les alignements 
int 	verifierAlignement(Jeu *jeu, int couleur, int ligne, int colonne, int dy, int dx, int dy0, int dx0);
/// Vérifie si il existe un gagnant
int 	estGagnant(Jeu *jeu);

/// VIDE qui représente la case vide dans la grille
enum {
	VIDE = '.'
};

/// Ensemble de directions 
enum {
	GAUCHE, HAUT, DROITE, BAS, NDIR
};

#endif
