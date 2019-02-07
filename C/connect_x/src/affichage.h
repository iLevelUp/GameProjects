#ifndef AFFICHAGE_H___
#define AFFICHAGE_H___

/// Affiche la grille
void afficherGrille(Jeu *jeu);
/// Affiche le menu
void afficherMenu(void);
/// Affiche le score
void afficherScore(Jeu *jeu);
/// Affiche le nombre de tour
void afficherTour(int tour, char *nom);
/// Affiche le vainqueur (ou match nul)
void afficherVainqueur(int gagnant, char *nom);

#endif
