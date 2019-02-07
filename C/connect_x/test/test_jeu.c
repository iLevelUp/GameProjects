#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_alignement.h"

static int Grille[LIGNES * COLONNES]; 

/* Deux types de vérifications (simples et pousées) */
int main(void) {

	/* Initialisation de la structure jeu */
	Jeu jeu;
	jeu.ligne = LIGNES;
	jeu.col = COLONNES;
	jeu.grille = Grille;
	int i, idx, idy, l, c, couleur, verif = 0, gagnant = 1;

	initGrille(&jeu);

	/* Vérification simple -- boucle for */

	/* Vérifie horizontalement */
	jeu.max_cmpt = 0;
	for(l = 0; l < jeu.ligne; l++) {
		for(c = 0; c < jeu.col; c++) {
			jeu.max_cmpt = 0;
			for(idx = 0; idx < NCMPT && c+idx < jeu.col; idx++) {
				poserJeton(&jeu, '+', c+idx, l);
			}

			verif = estGagnant(&jeu);
			gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_HOR
			afficherGrille(&jeu);
			printf("MAX COMPTEUR HORIZONTALEMENT = %d\n", jeu.max_cmpt);
			printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
			assert(verif == gagnant);
			initGrille(&jeu);
			jeu.max_cmpt = 0;
		}
	}
	printf("CORRECT HORIZONTALEMENT !\n");


	/* Vérifie verticalement */
	for(c = 0; c < jeu.col; c++) {
		for(l = 0; l < jeu.ligne; l++) {
			jeu.max_cmpt = 0;
			for(idy = 0; idy < NCMPT && l+idy < jeu.ligne; idy++) {
				poserJeton(&jeu, '+', c, l+idy);
			}

			verif = estGagnant(&jeu);
			gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_VER
			afficherGrille(&jeu);
			printf("MAX COMPTEUR VERTICALEMENT = %d\n", jeu.max_cmpt);
			printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
			assert(verif == gagnant);
			initGrille(&jeu);
			jeu.max_cmpt = 0;
		}
	}
	printf("CORRECT VERTICALEMENT !\n");


	/* Vérifie premier cas de L -- L à 0°C */
	for(l = 0; l < jeu.ligne; l++) {
		for(c = 0; c < jeu.col; c++) {
			for(i = 1; i <= NCMPT; i++) {
				jeu.max_cmpt = 0;
				for(idy = 0; idy < NCMPT-i && l+idy < jeu.ligne; idy++) {
					poserJeton(&jeu, '+', c, l+idy);
				}

				for(idx = 1; idx < NCMPT-idy+1 && c+idx < jeu.col; idx++) {
					poserJeton(&jeu,'+', c+idx, l);
				}

				verif = estGagnant(&jeu);
				gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L1
				afficherGrille(&jeu);
				printf("MAX COMPTEUR L à 0°C = %d\n", jeu.max_cmpt);
				printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif		
				assert(verif == gagnant);
				initGrille(&jeu);
				jeu.max_cmpt = 0;
			}
		}
	}
	printf("CORRECT L tourné à 0°C !\n");


	/* Vérifie deuxième cas de L -- L à 90°C */
	jeu.max_cmpt = 0;
	for(l = 0; l < jeu.ligne; l++) {
		for(c = 0; c < jeu.col; c++) {
			for(i = 1; i <= NCMPT; i++) {
				jeu.max_cmpt = 0;
				for(idy = 0; idy < NCMPT-i && l+idy < jeu.ligne; idy++) {
					poserJeton(&jeu, '+', c, l+idy);
				}

				for(idx = 1; idx < NCMPT-idy+1 && c-idx >= 0; idx++) {
					poserJeton(&jeu,'+', c-idx, l);
				}

				verif = estGagnant(&jeu);
				gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L2
				afficherGrille(&jeu);
				printf("MAX COMPTEUR L à 90°C = %d\n", jeu.max_cmpt);
				printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif			
				assert(verif == gagnant);
				initGrille(&jeu);
				jeu.max_cmpt = 0;
			}
		}
	}
	printf("CORRECT L tourné à 90°C !\n");


	/* Vérifie troisième cas de L -- L à 180°C */
	jeu.max_cmpt = 0;
	for(l = 0; l < jeu.ligne; l++) {
		for(c = 0; c < jeu.col; c++) {
			for(i = 1; i <= NCMPT; i++) {
				jeu.max_cmpt = 0;
				for(idy = 0; idy < NCMPT-i && l-idy >= 0; idy++) {
					poserJeton(&jeu, '+', c, l-idy);
				}

				for(idx = 1; idx < NCMPT-idy+1 && c-idx >= 0; idx++) {
					poserJeton(&jeu,'+', c-idx, l);
				}

				verif = estGagnant(&jeu);
				gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L3
				afficherGrille(&jeu);
				printf("MAX COMPTEUR L à 180°C = %d\n", jeu.max_cmpt);
				printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
				assert(verif == gagnant);
				initGrille(&jeu);
				jeu.max_cmpt = 0;
			}
		}
	}

	printf("CORRECT L tourné à 180°C !\n");


	/* Vérifie quatrième cas de L -- L à 270°C */
	jeu.max_cmpt = 0;
	for(l = 0; l < jeu.ligne; l++) {
		for(c = 0; c < jeu.col; c++) {
			for(i = 1; i <= NCMPT; i++) {
				jeu.max_cmpt = 0;
				for(idy = 0; idy < NCMPT-i && l-idy >= 0; idy++) {
					poserJeton(&jeu, '+', c, l-idy);
				}

				for(idx = 1; idx < NCMPT-idy+1 && c+idx < jeu.col; idx++) {
					poserJeton(&jeu,'+', c+idx, l);
				}
				verif = estGagnant(&jeu);
				gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L4
				afficherGrille(&jeu);
				printf("MAX COMPTEUR L à 270°C = %d\n", jeu.max_cmpt);
				printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
				assert(verif == gagnant);
				initGrille(&jeu);
				jeu.max_cmpt = 0;
			}
		}
	}

	printf("CORRECT L tourné à 270°C !\n");


	/* Vérifie horizontalement en plaçant des jetons adverses */
	jeu.max_cmpt = 0;
	for(c = 0; c < jeu.col; c++) {
		jeu.max_cmpt = 0;
		for(idx = 0; c+idx < jeu.col; idx++) {
			couleur = ((idx%NCMPT) ? '+' : 'O');
			poserJeton(&jeu, couleur, c+idx, 0);
		}

		verif = estGagnant(&jeu);
		gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_HOR_ADV
		afficherGrille(&jeu);
		printf("MAX COMPTEUR HORIZONTALEMENT = %d\n", jeu.max_cmpt);
		printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
		assert(verif == gagnant);
		jeu.max_cmpt = 0;
	}

	printf("CORRECT HORIZONTALEMENT AVEC JETONS ADVERSES !\n");


	/* Vérifie verticalement en plaçant des jetons adverses */
	jeu.max_cmpt = 0;
	for(l = 0; l < jeu.ligne; l++) {
		for(idy = 0; l+idy < jeu.ligne; idy++) {
			couleur = ((idy%NCMPT) ? '+' : 'O');
			poserJeton(&jeu, couleur, 0, l+idy);
		}

		verif = estGagnant(&jeu);
		gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_VER_ADV
		afficherGrille(&jeu);
		printf("MAX COMPTEUR VERTICALEMENT = %d\n", jeu.max_cmpt);
		printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
		assert(verif == gagnant);
		jeu.max_cmpt = 0;
	}

	printf("CORRECT VERTICALEMENT AVEC JETONS ADVERSES !\n");


	/* Vérifie premier cas de L (à 0°C) en plaçant des jetons adverses */
	jeu.max_cmpt = 0;
	for(i = 1; i <= NCMPT; i++) {
		jeu.max_cmpt = 0;
		for(idy = 0; idy < jeu.ligne; idy++) {
			couleur = ((idy%NCMPT) ? '+' : 'O');
			poserJeton(&jeu, couleur, 0, idy);
		}

		for(idx = 1; idx < jeu.col; idx++) {
			couleur = ((idx%NCMPT) ? '+' : 'O');
			poserJeton(&jeu, couleur, idx, 0);
		}

		verif = estGagnant(&jeu);
		gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L1_ADV
		afficherGrille(&jeu);
		printf("MAX COMPTEUR L à 0°C = %d\n", jeu.max_cmpt);
		printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
		assert(verif == gagnant);
		initGrille(&jeu);
		jeu.max_cmpt = 0;
	}

	printf("CORRECT L tourné à 0°C AVEC JETONS ADVERSES !\n");


	/* Vérifie deuxième cas de L (à 90°C) en plaçant des jetons adverses */
	jeu.max_cmpt = 0;
	for(idy = 0; idy < jeu.ligne; idy++) {
		couleur = ((idy%NCMPT) ? '+' : 'O');
		poserJeton(&jeu, couleur, jeu.col-1, idy);
	}

	for(idx = 0; idx < jeu.col; idx++) {
		couleur = ((idx%NCMPT) ? '+' : 'O');
		poserJeton(&jeu, couleur, idx, 0);
	}

	verif = estGagnant(&jeu);
	gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L2_ADV
	afficherGrille(&jeu);
	printf("MAX COMPTEUR L à 90°C = %d\n", jeu.max_cmpt);
	printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
	assert(verif == gagnant);
	initGrille(&jeu);
	jeu.max_cmpt = 0;
	printf("CORRECT L tourné à 90°C !\n");


	/* Vérifie troisième cas de L (à 180°C) en plaçant des jetons adverses */
	jeu.max_cmpt = 0;
	for(idy = 0; idy < jeu.ligne; idy++) {
		couleur = ((idy%NCMPT) ? '+' : 'O');
		poserJeton(&jeu, couleur, jeu.col-1, idy);
	}

	for(idx = 1; idx < jeu.col; idx++) {
		couleur = ((idx%NCMPT) ? '+' : 'O');
		poserJeton(&jeu, couleur, idx, jeu.ligne-1);
	}

	verif = estGagnant(&jeu);
	gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L3_ADV
	afficherGrille(&jeu);
	printf("MAX COMPTEUR L à 180°C = %d\n", jeu.max_cmpt);
	printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif

	assert(verif == gagnant);
	initGrille(&jeu);
	jeu.max_cmpt = 0;
	printf("CORRECT L tourné à 180°C AVEC JETONS ADVERSES !\n");


	/* Vérifie quatrième cas de L (à 270°C) en plaçant des jetons adverses */
	jeu.max_cmpt = 0;
	for(idy = 0; idy < jeu.ligne; idy++) {
		couleur = ((idy%NCMPT) ? '+' : 'O');
		poserJeton(&jeu, couleur, 0, idy);
	}

	for(idx = 0; idx < jeu.col; idx++) {
		couleur = ((idx%NCMPT) ? '+' : 'O');
		poserJeton(&jeu, couleur, idx, jeu.ligne-1);
	}

	verif = estGagnant(&jeu);
	gagnant = ((jeu.max_cmpt >= NCMPT) ? 1 : 0);
#ifdef DEBUG_L4_ADV
	afficherGrille(&jeu);
	printf("MAX COMPTEUR L à 270°C = %d\n", jeu.max_cmpt);
	printf("GAGNANT ? %s\n", afficherGagnant(gagnant));
#endif
	assert(verif == gagnant);
	initGrille(&jeu);
	jeu.max_cmpt = 0;
	printf("CORRECT L tourné à 270°C AVEC JETONS ADVERSES !\n");



	/* Vérification poussée -- étape par étape */

	/* Vérifie horizontalement */
	// Compteur à 1 en plaçant un 'O' à (2;0)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 2, 0);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 1);

	// Compteur à 2 en plaçant deux 'O' horizontalement
	// un 'O' à (2;0) et un autre à (3;0)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 3, 0);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 2);

	// Compteur à 3 en plaçant trois 'O' horizontalement
	// premier 'O' à (2;0), le deuxième 'O' à (3;0) et le dernier 'O' à (4;0)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 4, 0);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 3);

	// Compteur à 1 en plaçant deux 'O' séparés d'un '+'
	// 'O' à (2;0), '+' à (3;0), 'O' à (4;0)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, '+', 3, 0);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 1);


	/* Vérifie verticalement */
	initGrille(&jeu);
	// Compteur à 3 en plaçant trois 'O' verticalement
	// 'O' à (4;2), 'O' à (4;1), 'O' à (4;3)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 4, 1);
	poserJeton(&jeu, 'O', 4, 2);
	poserJeton(&jeu, 'O', 4, 3);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 3);

	// Compteur à 1 en plaçant deux 'O' séparés et un '+' verticalement
	// 'O' à (4;1), '+' à (4;2), 'O' à (4;3)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 4, 1);
	poserJeton(&jeu, '+', 4, 2);
	poserJeton(&jeu, 'O', 4, 3);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 1);

	/* Vérifie des cas de L (1) */
	initGrille(&jeu);
	// Compteur à 3 en plaçant des 'O' en escalier
	// 'O' à (0;0), (1;0), (1;1), (2;1), (2;2), (3;2); (3;3)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 0, 0); poserJeton(&jeu, 'O', 1, 0); poserJeton(&jeu, 'O', 1, 1); 
	poserJeton(&jeu, 'O', 2, 1); poserJeton(&jeu, 'O', 2, 2); poserJeton(&jeu, 'O', 3, 2);
	poserJeton(&jeu, 'O', 3, 3); poserJeton(&jeu, 'O', 4, 3);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 3);


	/* Vérifie des cas de L (2) */
	initGrille(&jeu);
	// Compteur à 2 en plaçant un '+' sur le point d'intersection du trait horizontal et vertical du L
	// 'O' à (1;2), à (2;3), à (2;4), à (3;2), à (4;2) et '+' à (2;2)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, '+', 2, 2); poserJeton(&jeu, 'O', 2, 3); poserJeton(&jeu, 'O', 2, 4); 
	poserJeton(&jeu, 'O', 3, 2); poserJeton(&jeu, 'O', 4, 2); poserJeton(&jeu, 'O', 1, 2);
	poserJeton(&jeu, 'O', 2, 1);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 2);

	/* Vérifie des cas de L (3) */
	initGrille(&jeu);
	// Compteur à 5 en plaçant un '+' à une case stratégique ne permettant pas la victoire
	// 'O' à (5;5), à (6;5), à (7;5), à (8;5), à (8;6), à (8;8) et '+' à (8;7)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, '+', 8, 7); poserJeton(&jeu, 'O', 5, 5); poserJeton(&jeu, 'O', 6, 5); 
	poserJeton(&jeu, 'O', 7, 5); poserJeton(&jeu, 'O', 8, 5); poserJeton(&jeu, 'O', 8, 6);
	poserJeton(&jeu, 'O', 8, 8);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 5);

	/* Vérifie des cas de L (4) */
	initGrille(&jeu);
	// Compteur à 1 en plaçant des jetons en diagonale
	// 'O' à (10;10), à (9;9), à (8;8), à (7;7), à (6,6), à (6;4), à (5;3), à (4;2), à (3;1)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 10, 10); poserJeton(&jeu, 'O', 9, 9); poserJeton(&jeu, 'O', 5, 7); 
	poserJeton(&jeu, 'O', 8, 8); poserJeton(&jeu, 'O', 7, 7); poserJeton(&jeu, 'O', 9, 5);
	poserJeton(&jeu, 'O', 8, 6); poserJeton(&jeu, 'O', 10, 4); poserJeton(&jeu, 'O', 6, 6);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 1);

	/* Vérifie des de cas L (5) */
	initGrille(&jeu);
	// Compteur à 5 en créant un O (ce qui créera 4 séries à 5 pions identiques) 
	// 'O' à (0;0), à (1;0), à (2;0), à (2;1), à (2,2), à (1;2) et à (0;2)
	jeu.max_cmpt = 0;
	poserJeton(&jeu, 'O', 0, 0); poserJeton(&jeu, 'O', 1, 0); poserJeton(&jeu, 'O', 2, 0); 
	poserJeton(&jeu, 'O', 2, 1); poserJeton(&jeu, 'O', 2, 2); poserJeton(&jeu, 'O', 1, 2);
	poserJeton(&jeu, 'O', 0, 2); poserJeton(&jeu, 'O', 0, 1);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 5);


	/* Vérifie avec la grille pleine */
	initGrille(&jeu);
	// Compteur à 1 en plaçant un '+', 'O' à tour de rôle
	jeu.max_cmpt = 0;
	for(i = 0; i < LIGNES * COLONNES; i++)
		poserJeton(&jeu, (i%2) ? 'O' : '+', i%COLONNES, i/COLONNES);
	verif = estGagnant(&jeu);
	assert(jeu.max_cmpt == 1);


	printf("CORRECT - VERIFICATION POUSSÉE !\n");
	return 0;
}
