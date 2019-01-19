

void menuCr(){

	FILE*fc;
		fc=fopen("Create.txt","r");
		int d;
		for (d=fgetc(fc); d != EOF; d = fgetc(fc))
		{
			printf("%c",d);
		}

}
void menuRech(){

	FILE*fc;
		fc=fopen("recherche.txt","r");
		int d;
		for (d=fgetc(fc); d != EOF; d = fgetc(fc))
		{
			printf("%c",d);
		}

}
void menuAff(){

	FILE*fc;
		fc=fopen("Afficher.txt","r");
		int d;
		for (d=fgetc(fc); d != EOF; d = fgetc(fc))
		{
			printf("%c",d);
		}

}
void menuMatch(){

	FILE*fc;
		fc=fopen("match.txt","r");
		int d;
		for (d=fgetc(fc); d != EOF; d = fgetc(fc))
		{
			printf("%c",d);
		}

}
void menuSup(){

	FILE*fc;
		fc=fopen("Supprimer.txt","r");
		int d;
		for (d=fgetc(fc); d != EOF; d = fgetc(fc))
		{
			printf("%c",d);
		}

}
void menuMod(){

	FILE*fc;
		fc=fopen("modifier.txt","r");
		int d;
		for (d=fgetc(fc); d != EOF; d = fgetc(fc))
		{
			printf("%c",d);
		}

}


int rech(int jourech)
{
	FILE*F;
	F = fopen("marseille.txt","r");
/* Je vais lire tant qu'il y a une ligne dans le Fichier*/
do{
/* cette structure permet de lire une ligne à partir de Fichier,*/
fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%s ;%d ;%s ;%d \n",&jou.Num,jou.Nom,jou.Prenom,jou.Age,jou.team,jou.pays,&jou.bu,jou.post,&jou.maillot,jou.taille,&jou.poids);

if(jou.Num==jourech)
{
	fclose(F);
	return 1;
}
}
while(!feof(F));
fclose(F);
return -1;
}

char *generecle(int longueur)
// longueur: la clé générée fera 'longueur' caractère
{
    char alphabet[] = "0123456789abcdef"; // les lettre aléatoires seront choisies dans ce tableau.
    char *cle; // on stock dans une clé
    int i; // srt pour l'indiçage du tableau
    cle = (char *)malloc( (longueur+1) * sizeof(char) ); // on réserve dynamiquement un tableau de longueur+1 case pour stocker le résultat
    for (i = 0; i< longueur; i++)
    {
      cle[i] = alphabet[(rand() % strlen(alphabet))] ; // on initialise chaque case de la cle a une valeur comprise dans "0123456789ABCDEF"
    }
    cle[i]='\0';// pour que le résultat soit affichable via printf entre autre, on transforme la chaine en chaine A Zero Terminal
    return cle; // on retourne l'adresse du tableau que l'on a cree.
}
 
void CreerPerso()

{

    int n = 64;   
    long long decimal,decimal2,decimal3,decimal4,decimal5, place;
    int i = 0, val,val2,val3,val4,val5,len,len2,len3,len4,len5,j,f,g,h,p,sap,sop;
    decimal = 0;
    decimal2 = 0;
    decimal3 = 0;
    decimal4 = 0;
    decimal5 = 0;
    place = 1;
   srand(time(NULL));
   char *cle = generecle(64);
   printf("clef: %s\n", cle);
    
    len2 = 4;
    len2 --;
    len3= 4;
    len3 --;
    len4 = 4;
    len4 --;

    len = strlen(cle);
    printf("%d",len);
  
    
      sop = len-12;
      len -= sop+1;

    char X[4] = {cle[sop],cle[sop+1],cle[sop+2],cle[sop+3]};
    char X1[4]= {cle[sop+4],cle[sop+5],cle[sop+6],cle[sop+7]};
    char X2[4]= {cle[sop+8],cle[sop+9],cle[sop+10],cle[sop+11]};
    for(i=sop; cle[i] !='\0'; i++)
    {
  
         
        if(cle[i]>='0' && cle[i]<='9')
        {
            val = cle[i] - 48;
        }
        else if(cle[i]>='a' && cle[i]<='f')
        {
           
            val = cle[i] - 97 + 10;
        }
        else if(cle[i]>='A' && cle[i]<='F')
        {
            val = cle[i] - 65 + 10;
        }
        decimal += val * pow(16, len);
        len--;
    }

    for(f=0; f<4; f++)
    {
  
     
        
        if(X[f]>='0' && X[f]<='9')
        {
            val2 = X[f] - 48;

        }
        else if(X[f]>='a' && X[f]<='f')
        {
            
            val2 = X[f] - 97 + 10;

        }
        else if(X[f]>='A' && X[f]<='F')
        {
            val2 = X[f] - 65 + 10;
        }
        decimal2 += val2 * pow(16, len2);
        len2--;
    }
    for(j=0; j<4; j++)
    {
  
       
        
        if(X1[j]>='0' && X1[j]<='9')
        {
            val3 = X1[j] - 48;

        }
        else if(X1[j]>='a' && X1[j]<='f')
        {
            
            val3 = X1[j] - 97 + 10;

        }
        else if(X1[j]>='A' && X1[j]<='F')
        {
            val3 = X1[j] - 65 + 10;
        }
        decimal3 += val3 * pow(16, len3);
        len3--;
    }
    for(g=0; g<4; g++)
    {
  
        /*
         * Find the decimal representation of cle[i]::*/
        
        if(X2[g]>='0' && X2[g]<='9')
        {
            val4 = X2[g] - 48;

        }
        else if(X2[g]>='a' && X2[g]<='f')
        {
            
            val4 = X2[g] - 97 + 10;

        }
        else if(X2[g]>='A' && X2[g]<='F')
        {
            val4 = X2[g] - 65 + 10;
        }
        decimal4 += val4 * pow(16, len4);
        len4--;
    }
    printf("%lld\n",decimal2);
    decimal2/= 2520.5769;
    decimal3/= 2520.5769;
    decimal4/= 2520.5769;
  
    //177284952041499
    printf("Bienvenue au Loto à la base nous convertissons les 12 derniers pour obtenir 4 X, s'ils sont FOOT, vous avez gagné mais aujourd'hui si vous avez au moins L au premier X ou O au deuxième X ou W au 3ème X  au tirage vous pourrez créer votre propre personnage dans l'équipe Angers ! !\n");
    printf("le nombre en cleadecimal = %s\n", cle);
    printf("Nous prenons les 12 derniers ... %s %s %s\n",X,X1,X2);
    printf("Nous les séparons en 4 bits; %s %s %s\n",X,X1,X2);
    printf("Conversion en cours ...\n");
    printf("le nombre en décimal avant d'être séparé= %lld\n", decimal);
    printf("le nombre en décimal étant séparé = %lld %lld %lld\n ", decimal2,decimal3,decimal4);
    //douze(tableau,64);
    char Tableau[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char NomR[10];

  for(h=decimal2-1;h<decimal2;h++)
  {

    printf("\n%c\n",Tableau[h]);
    
  }
  for(h=decimal3-1;h<decimal3;h++)
  {
    printf("%c\n",Tableau[h]);
  }
  for(h=decimal4-1;h<decimal4;h++)
  {
    printf("%c\n",Tableau[h]);
  }
  
  if((decimal2==12 || decimal2 == 15)||decimal3 == 15||decimal4==23){
  		menuCr();
	FILE*F;
	int num;
	F = fopen("Angers.txt","a");
	printf("\n Entrer le numéro du joueur que vous voulez ajouter :");
	
	scanf("%d",&num);
	 while(rech(num)==1){
	 	printf("\n Ce num existe déja:/");
	 	printf("\n Entrer le num du joueur");
	 	scanf("%d",&num);
	 }
	 jou.Num=num;
	 printf("\n Entrez le nom :");
	 scanf("%s",jou.Nom);
	 
	 printf("\n Entrez le prenom :");
	 scanf("%s",jou.Prenom);
	 
	 printf("\n Entrez l'âge :");
	 scanf("%s",jou.Age);

	 printf("\n Entrez son club :");
	 scanf("%s",jou.team);

	 printf("\n Entrez son pays d'origine:");
	 scanf("%s",jou.pays);

	 printf("\n Nombres de buts:");
	 scanf("%d",&jou.bu);

	 printf("\n son Post ? :");
	 scanf("%s",jou.post);

	 printf("\n son maillot :");
	 scanf("%d",&jou.maillot);

	 printf("\n Entrez sa taille :");
	 scanf("%s",jou.taille);

	 printf("\n Entrez son poids :");
	 scanf("%d",&jou.poids);
	 /*-----fprintf te sert à écrire dans le Fichier ok ??-----*/
	 fprintf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%s ;%d ;%s ;%d \n",jou.Num,jou.Nom,jou.Prenom,jou.Age,jou.team,jou.pays,jou.bu,jou.post,jou.maillot,jou.taille,jou.poids);

	 fclose(F);
	 free(cle);
  }else printf("tu n'as pas gagné le loto aucune de tes lettres est un A ou un M ou un W\n");}// quand on n'as plus besoin du tableau, on pense a libérer la mémoire.
   

/*-----recherche et afFicheAge :)-----*/
	 void recherche()

{

	menuRech();
	int NumR;
	char NomR[20] = {0};
	int ret;
	printf("Consigne : vérifier le nom du joueur avant de le rechercher dans l'option 4\n Par exemple Silva ou Trapp ? \n Par contre pour l'esthétique de la liste des joueurs(ref a la fonction -5), pour les joueurs de plus de 5 lettres, vous devriez saisir les 4 premières suivies d'un . \n Exemple Balot. pour Balotelli ! \n");
	printf("Entrez le numéro ou nom du joueur à rechercher :");

	//viderBuffer();
	scanf("%s",NomR);
	int valeur,i;
	

	FILE * F;
	char * fileNames[]={"marseille.txt","Paris.txt","Lille.txt","Nancy.txt","Nice.txt","Caen.txt"};
	for(i=0;i<6;i++)
	{
		F= fopen(fileNames[i],"r");
	
		while(!feof(F))
		{	/* à chaque fois tu lis une ligne et tu la met dans la structure :) */
		 fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%s ;%d ;%s ;%d \n",&jou.Num,&(jou.Nom[0]),jou.Prenom,jou.Age,jou.team,jou.pays,&jou.bu,jou.post,&jou.maillot,jou.taille,&jou.poids);
		 
		 valeur = strcmp (NomR, jou.Nom);
		 if(valeur == 0)
 //Est ce que le nom que tu cherches est dans la sztructure ?
/* si c'est le cas tu m'afFichees les informations*/
		 {
		 	
		 	printf("---------Informations sur le joueur-------------\n");
		 	printf("Num:\t %d\n",jou.Num);
		 	printf("Nom:\t %s\n",&(jou.Nom[0]));
		 	printf("Prenom:\t %s\n",jou.Prenom);
		 	printf("Age:\t %s\n",jou.Age);
		 	printf("Equipe:\t %s\n",jou.team);
		 	printf("Pays:\t %s\n",jou.pays);
		 	printf("Buts:\t %d\n",jou.bu);
		 	printf("Poste:\t %s\n",jou.post);
		 	printf("N°Mail:\t %d\n",jou.maillot);
		 	printf("Taille:\t %s\n",jou.taille);
		 	printf("Poids:\t %d\n",jou.poids);

		 	break;
		 }

		

		 

		}
	fclose(F);
	F=NULL;
	}
	
	if(valeur !=0 ) printf("Ce joueur n'existe pas\n");
	}


void DisplayALL(){
	menuAff();
	int i;
	FILE * F;
	char * fileNames[]={"Paris.txt","marseille.txt","Lille.txt","Nancy.txt","Nice.txt","Caen.txt"};
	for(i=0;i<6;i++)
	{
		F= fopen(fileNames[i],"r");
	
	printf("\n \n");
	printf("num\t|nom\t|Prenom\t|Age\t|Equipe\t|Pays\t|Buts\t|Post\t|N°Mail\t|Taille\t|Poids\n");

	printf("-----------------------------------------------------------------------------------------\n");
	
	do
	{
		fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%s ;%d ;%s ;%d \n",&jou.Num,&(jou.Nom[0]),jou.Prenom,jou.Age,jou.team,jou.pays,&jou.bu,jou.post,&jou.maillot,jou.taille,&jou.poids);
		

		printf("|%d\t",jou.Num);
		printf("|%s\t",jou.Nom);
		printf("|%s\t",jou.Prenom);

		printf("|%s\t",jou.Age);
		printf("|%s\t",jou.team);

		printf("|%s\t",jou.pays);
		printf("|%d\t",jou.bu);
		printf("|%s\t",jou.post);
		printf("|%d\t",jou.maillot);
		printf("|%s\t",jou.taille);
		printf("|%d\t",jou.poids);
		printf("|\n");
	}
	while(!feof(F));
	fclose(F);
	F = NULL;
}
}
 
void tri(int *index){
    int randI=0, randJ=0;
for(int i=0;i<4;i++){
    randI=rand()%4;
    randJ=rand()%4;
    int tmp =index[randJ];
    index[randJ]=index[randI];
    index[randI]=tmp;
}
//AirMatch(&tab[index[0]], &tab[index[1]]);
tab[index[0]];
tab[index[1]];
tab[index[0]];
tab[index[2]];
    }
void jeu(void)
{
    printf("\n");
    menuMatch();
    printf("\nBienvenue dans le jeu de football Linux\n");
    getchar();
    initEquipes();
    AirMatch(&tab[Paris], &tab[Marseille]);
    AirMatch(&tab[Nice], &tab[Nancy]);
    AirMatch(&tab[Lille], &tab[Bordeaux]);
    AirMatch(&tab[Caens], &tab[Angers]);
    DisplayRank(tab[Paris], tab[Marseille], tab[Nice], tab[Nancy], tab[Angers], tab[Bordeaux], tab[Lille], tab[Caens]);
}
 
void AirMatch(Equipe * A, Equipe * B)
{
    

    int i = 0, Terrain = 1, randA = 0, randB = 0;
 
    srand(time(NULL));
 
    for (i = 0; i < 20; i++) {
        randA = rand() % 3;
        randB = rand() % 3;

        
        switch (Terrain) {    
            case 0:
            if (randB * B->attaque > randA * A->defense) {
                if (randB * B->attaque > randA * A->gardien) {
                    printf("Goal!!");
                    B->score++;
                    Terrain = 1;
                    LookatScore(*A, *B);
                } else {
                    printf("Arret de %s", A->nomGardien);
                }
            } else if (randB * B->attaque < randA * A->defense) {
                printf("Renvoi de la défense");
                Terrain ++;
            } else {
                printf("%s continue à presser", B->nom);
            }
            break;
            case 1:
            if (randA * A->milieu > randB * B->milieu) {
                Terrain ++;
                printf("%s attaque!", A->nom);
            } else if (randA * A->milieu < randB * B->milieu) {
                Terrain --;
                printf("%s part à l'attaque!", B->nom);
            } else {
                printf("Le ballon tourne au centre du terrain");
            }
            break;
            case 2:
            if (randA * A->attaque > randB * (*B).defense) {
                if (randA * A->attaque > randB * B->gardien) {
                    printf("Goal!!");
                    A->score++;
                    Terrain = 1;
                    LookatScore(*A, *B);
                } else {
                    printf("Arret de %s!", B->nomGardien);
                }
            } else if (randA * A->attaque < randB * B->defense) {
                printf("Renvoi de la défense");
                Terrain--;
            } else {
                printf("Ca chauffe pour %s", B->nom);
            }
            break;
        }
        getchar();
    }
    printf("\nFin du match !\n\n");
    LookatScore(*A,* B);
    if (A->score >= B->score) {
        if (A->score > B->score) {
            A->points += 3;
        } else {
            A->points += 1;
            B->points += 1;
        }
    } else {
        B->points += 3;
    }
    printf("%s %d points\n%s %d points\n", A->nom, A->points, B->nom, B->points);
}
 
void LookatScore(Equipe A, Equipe B)
{
 
    printf("\n%s %d - %d %s\n", A.nom, A.score, B.score, B.nom);
}
 
int Comparons(const void *Param1, const void *Param2)
{
    const Equipe* equipe1 = (Equipe*) Param1;
    const Equipe* equipe2 = (Equipe*) Param2;
 
    if (equipe1->points == equipe2->points) {
        return 0;
    } else if (equipe1->points < equipe2->points) {
        return -1;
    } else {
        return 1;
    }
}
 
void DisplayRank(Equipe A, Equipe B, Equipe C, Equipe D, Equipe E, Equipe F, Equipe G, Equipe H)
{
    Equipe classement[8];
    int i;
 
    strcpy(classement[0].nom, A.nom);
    classement[0].points = A.points;
    strcpy(classement[1].nom, B.nom);
    classement[1].points = B.points;
    strcpy(classement[2].nom, C.nom);
    classement[2].points = C.points;
    strcpy(classement[3].nom, D.nom);
    classement[3].points = D.points;
    strcpy(classement[4].nom, E.nom);
    classement[4].points = E.points;
    strcpy(classement[5].nom, F.nom);
    classement[5].points = F.points;
    strcpy(classement[6].nom, G.nom);
    classement[6].points = G.points;
    strcpy(classement[7].nom, H.nom);
    classement[7].points = H.points;
    for(i = 0; i < 8; i++) {
        printf("%d %s %d\n", i + 1, classement[i].nom, classement[i].points);
    }
     
    qsort(classement, 8, sizeof(Equipe), &Comparons);
 
    for(i = 0; i < 8; i++) {
        printf("%d %s %d\n", i + 1, classement[i].nom, classement[i].points);
        FILE*F;
        
        F=fopen("Classement.txt","a");
        fprintf(F,"%d %s %d\n", i + 1, classement[i].nom, classement[i].points);
    }
}
 
void initEquipes(void)
{

    

    strcpy(tab[Paris].nom, "Paris");
    tab[Paris].attaque = 10;
    tab[Paris].milieu = 9;
    tab[Paris].defense = 8;
    tab[Paris].gardien = 6;
    tab[Paris].score = 0;
    strcpy(tab[Paris].nomGardien, "Trapp");

 
    strcpy(tab[Marseille].nom, "Marseille");
    tab[Marseille].attaque = 9;
    tab[Marseille].milieu = 8;
    tab[Marseille].defense = 9;
    tab[Marseille].gardien = 8;
    tab[Marseille].score = 0;
    strcpy(tab[Marseille].nomGardien, "Pelé");
 
    strcpy(tab[Nice].nom, "Nice");
    tab[Nice].attaque = 10;
    tab[Nice].milieu = 8;
    tab[Nice].defense = 8;
    tab[Nice].gardien = 8;
    tab[Nice].score = 0;
    strcpy(tab[Nice].nomGardien, "Cardinale");
 
    strcpy(tab[Nancy].nom, "Nancy");
    tab[Nancy].attaque = 9;
    tab[Nancy].milieu = 9;
    tab[Nancy].defense = 8;
    tab[Nancy].gardien = 8;
    tab[Nancy].score = 0;
    strcpy(tab[Nancy].nomGardien, "Chernik");

    strcpy(tab[Angers].nom, "Angers");
    tab[Angers].attaque = 10;
    tab[Angers].milieu = 9;
    tab[Angers].defense = 8;
    tab[Angers].gardien = 6;
    tab[Angers].score = 0;
    strcpy(tab[Angers].nomGardien, "nigga");
 
    strcpy(tab[Caens].nom, "Caens");
    tab[Caens].attaque = 9;
    tab[Caens].milieu = 8;
    tab[Caens].defense = 9;
    tab[Caens].gardien = 8;
    tab[Caens].score = 0;
    strcpy(tab[Caens].nomGardien, "wouaahh");
 
    strcpy(tab[Lille].nom, "Lille");
    tab[Lille].attaque = 10;
    tab[Lille].milieu = 8;
    tab[Lille].defense = 8;
    tab[Lille].gardien = 8;
    tab[Lille].score = 0;
    strcpy(tab[Lille].nomGardien, "tki");
 
    strcpy(tab[Bordeaux].nom, "Bordeaux");
    tab[Bordeaux].attaque = 9;
    tab[Bordeaux].milieu = 9;
    tab[Bordeaux].defense = 8;
    tab[Bordeaux].gardien = 8;
    tab[Bordeaux].score = 0;
    strcpy(tab[Bordeaux].nomGardien, "bg");
}

void Modifier(){
    menuMod();
    FILE*F,*Fiche;
    int num,i;
    char rep[10];
    printf("\n Entrez le num du joueur a Modifier, on modifie pour le moment marseille.txt :");
    scanf("%d",&num);
    printf("%d\n",num); 
    
    if(rech(num)==1)
    {
        printf("\n Voulez-vous vraiment modifier o/n ?");
        scanf("%s",rep);
        
        
        printf("%c",rep[0]);
        if(rep[0] =='o' || rep[0] =='O')
        {
                
                F=fopen("marseille.txt","r");
            Fiche =fopen("TempParis.txt","a");


            do
             {
                fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%s ;%d ;%s ;%d \n",&jou.Num,&(jou.Nom[0]),jou.Prenom,jou.Age,jou.team,jou.pays,&jou.bu,jou.post,&jou.maillot,jou.taille,&jou.poids);
                if(num==jou.Num)
                {
                    jou.Num = num;
                     printf("\n Entrez le nom :");
                    scanf("%s",jou.Nom);
         
                     printf("\n Entrez le prenom :");
                     scanf("%s",jou.Prenom);     
                     printf("\n Entrez l'âge :");
                    scanf("%s",jou.Age);
                 }
            fprintf(Fiche,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%s ;%d ;%s ;%d \n",jou.Num,jou.Nom,jou.Prenom,jou.Age,jou.team,jou.pays,jou.bu,jou.post,jou.maillot,jou.taille,jou.poids);
    }
    while (!feof(F));
            fclose(Fiche);
            fclose(F);
            remove("marseille.txt");
            rename("TempParis.txt","marseille.txt");
            printf("\n la modification a réussi");
            }
            else {
                printf("mod annulé\n");
        }}
            else {printf("Joueur pas trouvé ! \n");
        }
            

        }


    
    	