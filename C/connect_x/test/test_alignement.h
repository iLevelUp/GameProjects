#ifndef ALIGNEMENT_H___
#define ALIGNEMENT_H___

#define LIGNES 11
#define COLONNES 13
#define NCMPT 6
#define NALIGN 4

enum {
	GAUCHE, HAUT, DROITE, BAS, NDIR
};

enum {
	VIDE = '.'
};

typedef struct jeu Jeu;

// Structure jeu qui comporte les informations nécessaires pour jouer
struct jeu {
	int ligne;		// Nombre de lignes
	int col;		// Nombre de colonnes
	int *grille;	// Grille du jeu
	int max_cmpt;	// Compte le nombre d'alignement max
};

void 	initGrille(Jeu *jeu);
void 	poserJeton(Jeu *jeu, int couleur, int x, int y);
int 	verifierAlignement(Jeu *jeu, int couleur, int ligne, int colonne, int dy, int dx, int dy0, int dx0);
void 	afficherGrille(Jeu *jeu);
int 	estGagnant(Jeu *jeu);
char* 	afficherGagnant(int gagnant);

#endif
