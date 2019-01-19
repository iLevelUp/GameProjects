struct joueur
{

int Num;
char Nom[100];
char Prenom[100];
char Age[10]; 
char team[50];
char pays[50];
int bu;
char post[50];
int maillot;
int chancebut;
char taille[5];
int poids;
};
struct joueur jou;

void menuCr();
void menuRech();
void menuAff();
void menuMatch();
void menuMod();
void menuSup();
int rech(int jourech);

typedef struct Equipe Equipe;
struct Equipe {
    char nom[15];
    int attaque;
    int milieu;
    int defense;
    int gardien;
    char nomGardien[15];
    int score;
    int points;
};

void jeu(void);
void AirMatch(Equipe * A, Equipe * B);
void initEquipes(void);
char *generecle(int longueur);
void CreerPerso();
void recherche();
void DisplayALL();
void LookatScore(Equipe A, Equipe B);
void DisplayRank(Equipe A, Equipe B, Equipe C, Equipe D, Equipe E, Equipe F, Equipe G, Equipe H);
//Equipe Paris = {"", 0, 0, 0, 0, "", 0, 0}, Marseille = {"", 0, 0, 0, 0, "", 0, 0}, Nice = {"", 0, 0, 0, 0, "", 0, 0}, Nancy = {"", 0, 0, 0, 0, "", 0, 0},Angers = {"", 0, 0, 0, 0, "", 0, 0}, Caens = {"", 0, 0, 0, 0, "", 0, 0}, Lille = {"", 0, 0, 0, 0, "", 0, 0}, Bordeaux = {"", 0, 0, 0, 0, "", 0, 0};
enum equipeName
{
	Paris, Marseille, Nice, Nancy, Angers, Bordeaux, Lille, Caens
};
Equipe tab[10];