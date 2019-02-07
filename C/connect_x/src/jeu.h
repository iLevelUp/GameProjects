#ifndef JEU_H___
#define JEU_H___

/// Nombre de lignes dans la grille
#define LIGNES 11
/// Nombre de colonnes dans la grille
#define COLONNES 13

typedef struct jeu Jeu;
typedef struct joueur Joueur;

/// Initialise le jeu
void 	initJeu(Jeu *jeu);
/// Demande si l'utilisateur souhaite rejouer
int 	choisirRejouer(void);
/// Permet à l'utilisateur de jouer
void 	jouer(Jeu *jeu);

/// Données concernant le joueur
struct joueur {
	char* nom;		///< Nom du joueur
	int couleur;	///< Couleur du jeton du joueur
	int score;		///< Score du joueur
};

/// Données concernant le jeu 
struct jeu {
	int ligne;		///< Nombre de lignes de la grille
	int col;		///< Nombre de colonnes de la grille
	int *grille;	///< Tableau correspondant à la grille du jeu
	Joueur *joueur; ///< L'ensemble des joueurs qui participent au jeu
};

#endif	
