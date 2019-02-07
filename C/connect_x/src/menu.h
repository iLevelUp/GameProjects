#ifndef MENU_H___
#define MENU_H___

/// Choisit l'option que l'utilisateur souhaite prendre
int 	choisirOption(void);
/// Accède à l'une des options selon l'option demandée par l'utilisateur
void 	menu(Jeu *jeu);
/// Sauvegarde le score du gagnant
void 	sauvegarder(Jeu *jeu, int tour);

/// Ensemble des options
enum {
	JOUER, SCORE, QUITTER, NOPTIONS
};

#endif
