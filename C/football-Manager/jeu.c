#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "fonction.h"
#include "mod.h"

void main(){

    	FILE*fd;
    	fd=fopen("affiche.txt","r");
    	int c;

    		
    	system("clear");

    	for (c=fgetc(fd); c != EOF; c = fgetc(fd))
    	{
    		printf("%c",c);
    	}
    	
    	
    		int Choix;char rep;
    		do
    		{
    			
    			printf("       							***********MENU**********\n");
    			printf("							1- Simuler\n");
    			printf("							2- LOTO - AJOUTER UN JOUEUR\n");
    			printf("							3- RECHERCHER UN JOUEUR\n");
    			printf("							- SUPPRIMER UN JOUEUR\n");
    			printf("							- MODIFIER UN JOUEUR\n");
    			printf("							4- AFFICHER LES EQUIPES\n");
    			printf("							5- Quitter \n \n");
    		do
    		{
    			printf("\n Entrer votre Choix:");
    			scanf("%d",&Choix);
    		}
    		while(Choix<0||Choix>6);
    		switch(Choix)
    		{
    			case 1:jeu();
    			break;
    			case 2:CreerPerso();
    			break;
    			case 3:recherche();
    			break;
    			/*case 3:supprimerJoueur();
    			break;*/
    			case 4:Modifier();
    			break;
    			case 5:DisplayALL();
    			break;
    			case 6:exit(0);	
    		}
    		printf("Voulez-vous continuer o/n:\n");
    		scanf("%s",&rep);

    		
    		}
    		while(rep=='o'||rep=='O');
    		fclose(fd);

    	} 

    	
