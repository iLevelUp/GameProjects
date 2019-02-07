#ifndef JOUEUR_H___
#define JOUEUR_H___

/// Nombre de joueurs
#define NJOUEURS 5
/// Nombre de symboles
#define NSYMBOLES ((int)(sizeof(symbole)/sizeof(*symbole)))

/// Initiliase les données des joueurs
void	initJoueur(Jeu *jeu);
/// Choisit la colonne demandée par l'utilisateur
int 	choisirColonne(Jeu *jeu);
/// Demande le nom de l'utilisateur
char* 	choisirNom(int j_id);
/// Place le jeton à la colonne demandée
void 	placerJeton(Jeu *jeu, int col, int couleur);

#endif
