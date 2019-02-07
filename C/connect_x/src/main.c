/*
 ! \fichier main.c
 * \Lancement du jeu PUISSANCE 6. Possibilité de jouer, de consulter
 * l'historique ou encore quitter. Aligner 6 pions horizontalement,
 * verticalement, ou en carré afin de gagner.
 * \auteur: LOKO Loic, lloicloko@gmail.com
 * \date Vendredi 13 Avril 2018
 */

#include "jeu.h"

/**
 * Déclare de la structure principale "jeu" et appelle
 * la fonction "initJeu" qui initialise les différentes
 * paramètres du jeu
 */
int main(void) {
	Jeu jeu;
	initJeu(&jeu);
	return 0;
}