#include "game.h"
#include "driver.h"

#include <stdio.h>

#define H 27
#define W 42

Game g;

static const char* level1 = {
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDAAAAAAAAAAAAAAACCCCCCCCAAAAAAAAADDDDD"
"DDDDDACCCACCCCCACCAAAAAACCCCACCCCCCCADDDDD"
"DDDDDACCCACCCCCACCAAACAACCCCAAAAAAAAADDDDD"
"DDDDDAAAAAAAAAAAAAAAACAAAAAAACCCACCCADDDDD"
"DDDDDACCCCCCACCCCCAAAAAACCCCACCCACCCADDDDD"
"DDDDDAAAAAAAAAAAAAAACCCACCCCAAAAAAAAADDDDD"
"DDDDDAAAACCCCCCACACCCCCACCCCACCCCCCCADDDDD"
"DDDDDCACAAAAAACACACCCAAAFAAAAAAAAAAAADDDDD"
"DDDDDCACACCCCACACACCCACCCACCCCCCCCCACDDDDD"
"DDDDDCACACAAAACACACCCACCCACAAAAAAACACDDDDD"
"DDDDDCACACACCACACAAAAACCCACAAAAAAACACDDDDD"
"DDDDDAACACACCACACACCCACCCACACCCCCACACDDDDD"
"DDDDDACCACAAAACACACCCACCCACACCCCCACACDDDDD"
"DDDDDACCACACCCCACAAAAAAAAACAAAAAAACACDDDDD"
"DDDDDAAAACAAAAAACACCCACCAACCCAACCCCACDDDDD"
"DDDDDACCACACCCCCCACCCACCAACCCAACCCCACDDDDD"
"DDDDDACCAAAAAAAAAACCCACCAACCCAACCCCAADDDDD"
"DDDDDACCCCCCCCCCCACCCAAAAAAAAAAAAAAAADDDDD"
"DDDDDAAAAAACCAAAAAAAAAAAAAAAAAACCCACCDDDDD"
"DDDDDACCCCACCACCCCCCCAACCCCCCAACCCACCDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
};

static unsigned char bg[H * W];
//Augmente le i en fonction des images à afficher vu que ton process move prend un i mtn donc pour chaque fichier
// oublie pas que entity est utilisé dans draw_entity qui utilise le nb de sprites
static Entity entity[3];
static Brumme brumme[1];
//dirx de nothing c {0,0}
static int dirx[] = {0, -1, 1, 0, 0 };

static int diry[] = {0, 0, 0, -1, 1 };




//déplacement du personnage
static void process_move(int move){
  
          /*if(move>= 0 && move >=5){
        
            switch(entity[0].dir){
                case Right:
                    bg[entity[0].y * W + entity[0].x-1] = Brume;
                    return;
                case Left:
                    bg[entity[0].y * W + entity[0].x+1] = Brume;
                    return;
                case Up:
                    bg[entity[0].y+1 * W + entity[0].x] = Brume;
                    return;
                case Down:
                    bg[entity[0].y-1 * W + entity[0].x] = Brume;
                    return;
            }
         }*/
         /*entity[0].dir = move;
         int nextx = entity[0].x + dirx[move];
         int nexty = entity[0].y + diry[move];
         entity[0].dir = move;
         /*if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
             if(move == 1){

                nextx= entity[0].x + dirx[move+2];
                nexty= entity[0].y + diry[move+2];
                entity[0].dir = move + 2;

             }
         
            if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
             if(move == 2){

                nextx= entity[0].x + dirx[move+2];
                nexty= entity[0].y + diry[move+2];
                entity[0].dir = move +2;


             }
             if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
             if(move == 3 ){

                nextx= entity[0].x + dirx[move-2];
                nexty= entity[0].y + diry[move-2];
                entity[0].dir = move -2;


             }
             if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
             if(move == 4 ){

                nextx= entity[0].x + dirx[move-2];
                nexty= entity[0].y + diry[move-2];
                entity[0].dir = move -2;
             }
             if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
             return;
         switch(move)
         {
            case Left:
            if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
            {
                move = 3;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;
                }
                break;
            
            case Right:
             if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
             {
                move = 4;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;}
                break;
                
            case Up:
              if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
              {
                move = 1;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;


             }
             break;

             case Down:
              if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )){
                move = 2;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;
             }
             break;
                  }
            if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower ))
                return;


        entity[0].x = nextx;
         entity[0].y = nexty;*/
         entity[0].dir = move;
    printf("%d\n", entity[0].dir);
    int nextx = entity[0].x + dirx[move];
    int nexty = entity[0].y + diry[move];
    entity[0].dir = move;
    if(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill)
        return;
    entity[0].x = nextx;
    entity[0].y = nexty;
    entity[0].move_x += dirx[move];
    entity[0].move_y += diry[move];

}


int distance(int x1, int x2, int y1, int y2){

    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
}
static int ennemy_dire(int entx,int ennx, int enty, int enny) {
int best=0, m, mindist = H*W;int nextx,minD,nexty; char *rien="je ne sers à rien en fait";


for(int m=0;m<5;m++){
     nextx = ennx + dirx[m];
     nexty = enny + diry[m];
    if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brume )){
        continue;}

        // avec continue tu ne fais pas l'itération suivante, je fais rien en gros c'est comme ce que j'avais mis avec le char

        minD= distance(entx,nextx,enty,nexty);
    if(minD<mindist){
        mindist=minD;
        best  = m;
            }
       }
       return best;
   }

   static int ennemy_diren(int entx,int ennx, int enty, int enny) {
    int best=0, m, mindist = H*W;int nextx,minD,nexty; char *rien="je ne sers à rien en fait";


for(int m=0;m<5;m++){
     nextx = ennx + dirx[m];
     nexty = enny + diry[m];
    if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brume )) 
            {
        continue;
    }
    if(nextx==entity[1].x && nexty==entity[1].y)
    return;
        // avec continue tu ne fais pas l'itération suivante, je fais rien en gros c'est comme ce que j'avais mis avec le char

        minD= distance(entx,nextx,enty,nexty);
    if(minD<mindist){
        mindist=minD;
        best  = m;
            }
       }
       return best;
   }
   
static void ennemy_move(int i,int ennemy_dir){
    //Pour chaque ennemi, j'aurais pu aussi simplement créer un i qui remplace l'entité dans [];
    entity[i].dir = ennemy_dir;
    entity[i].x += dirx[ennemy_dir];
    entity[i].y += diry[ennemy_dir];
    entity[i].dir = ennemy_dir;

}

static void same(){
     if(entity[1].x==entity[2].x && entity[1].y==entity[2].y)

    exit(1);
}
static void smoke(int move){

/* De cette façon il mettera la fumé a l'ancienne place du joueur, vu que le joueur avancera, bah ca marchera
si tu mets -1 il mettera a la position -1 avant que joueur avance donc il sera en deux cases avant*/
   if(bg[entity[0].y * W + entity[0].x] == Grass){
    bg[entity[0].y* W +entity[0].x] = Brume; 
}
}

static void callback(void* d) {
    const Driver* dr = (Driver*)d;  
    static int tmp;
    static int decompte = 20;
    int move= dr->get_move();
   // int best = ennemy_dire(entity[0].x,entity[1].x,entity[0].y,entity[1].y);
   // int best[2] = {ennemy_dire(entity[0].x,entity[1].x,entity[0].y,entity[1].y), 
     //   ennemy_diren(entity[0].x,entity[2].x,entity[0].y,entity[2].y)};

    
   /* if(decompte <= 0)
    {
        for(int i = 0; i < H * W; ++i)
        {
            if(bg[i] == Brume)
                bg[i] += 'A' - 'E';
        }
        decompte = 20;
    }

    if(move != 50)
        tmp = move;
  
    else if(move == 50)
        smoke(tmp);
  
    move = tmp;*/
    process_move(move);
    //ennemy_move(1,best[0]); 
    //ennemy_move(2,best[1]); 
    
    dr->draw_bg();
    dr->draw_entity(0);
  //  dr->draw_entity(1); 
  //  dr->draw_entity(2);
    dr->update();
    //decompte-=1;


    
}

void init_game(const Driver* dr) {
    int i;
    g.h = H;
    g.w = W;
    g.screen_w = W/2;
    g.screen_h = H/2;
    g.screen_x = 0;
    g.screen_y = 0;
    g.background = bg;
    g.entity = entity;
    g.brumme =  brumme;
    for(int i = 0; i < H * W; ++i)
        g.background[i] = level1[i] - 'A';
    g.entity[0].x = 7;
    g.entity[0].y = 10;
    g.entity[0].id = 0;
    g.entity[0].move_x = g.entity[0].move_y = 0;
    g.entity[0].dir = Right;
    g.entity[1].x = 5;
    g.entity[1].y = 20;
    g.entity[1].move_x = g.entity[1].move_y = 0;
    g.entity[1].dir = Right;
    g.entity[2].x = 15;
    g.entity[2].y = 10;
    g.entity[2].move_x = g.entity[1].move_y = 0;
    g.entity[2].dir = Right;
    dr->init(&g);
    g.background[i] = level1[i] - 'A';
    dr->start(callback);
    
}

