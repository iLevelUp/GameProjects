#include "game.h"
#include "driver.h"
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

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
"DDDDDAAAAAAAAAAAAAAAACAAAAAAFCCCACCCADDDDD"
"DDDDDACCCCCCACCCCCAAAAAACCCCACCCACCCADDDDD"
"DDDDDAAAGAAAAAAAAAAACCCACCCCAAAAAAAAADDDDD"
"DDDDDAAAACCCCCCACACCCCCACCCCACCCCCCCADDDDD"
"DDDDDCACAAAAAACACACCCAAAFAAAAAAAAAAAADDDDD"
"DDDDDCACACCCCACACACCCACCCACCCCCCCCCACDDDDD"
"DDDDDCACACAAAACACACCCACCCACAAAAAAACACDDDDD"
"DDDDDCACACACCACACAAAAACCCACAAAFAAACACDDDDD"
"DDDDDAHCACACCACACACCCACCCACACCCCCACACDDDDD"
"DDDDDACCACAAAACACACCCTCCCACACCCCCACACDDDDD"
"DDDDDACCACACCCCACAAAAAAAAACAAAAAAACACDDDDD"
"DDDDDAAAACAAAAAACACCCACCAACCCAACCCCACDDDDD"
"DDDDDACCACFCCCCCCACCCGCCAACCCAACCCCACDDDDD"
"DDDDDACCAAAAAAAAAACCCACCAACCCAACCCCAADDDDD"
"DDDDDACCCCCCCCCCCACCCAAAAAAAAAAAAAAAADDDDD"
"DDDDDAGAAAACCAAAAAAAAAAAAAHAAAACCCACCDDDDD"
"DDDDDACCCCACCACCCCCCCAACCCCCCAACCCACCDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"
};

static unsigned char bg[H * W];

static Entity entity[3];
static int dirx[] = {0, -1, 1, 0, 0 };

static int diry[] = {0, 0, 0, -1, 1};


/***You Lose***/
 void lose(){

  if((entity[0].x == entity[1].x && entity[0].y == entity[1].y)||
    (entity[0].x == entity[2].x && entity[0].y == entity[2].y))
    
    {
    entity[0].life--;
    if(entity[0].life>0){
    g.entity[0].x = W/2;
    g.entity[0].y = 5;
    g.entity[0].essence = 5000;
    g.entity[2].x = 15;
    g.entity[2].y = 10;
    g.entity[1].x = 5;
    g.entity[1].y = 20;
    }
  }
  
  if(entity[0].life == 0){
    bg[entity[0].y * W +entity[0].x] = GameOver;
    g.entity[0].x = 50;
    g.entity[0].y = 50;
    g.entity[1].x = 50;
    g.entity[1].y = 50;
    g.entity[2].x = 50;
    g.entity[2].y = 50;


    printf("Votre score est de %d\n", entity[0].score);
    printf("A cours d'essence\n");
  } 

}

/*****déplacement du personnage*****/
static void process_move(int move){

        if(move!=0)
            entity[0].essence-=10;
        if(entity[0].essence<=0){
            move=0;
            entity[0].x += dirx[move];
            entity[0].y += diry[move];
            entity[0].essence=0;
            return;
}
  
        
         entity[0].dir = move;
         int nextx = entity[0].x + dirx[move];
         int nexty = entity[0].y + diry[move];
         entity[0].dir = move;
         
         switch(move)
         {
            case Left:
            if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )
	       ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke))
            {
                move = 3;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;
                }
                break;
            
            case Right:
             if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )
	    ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke))
             {
                move = 4;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;}
                break;
                
            case Up:
              if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
	      ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )
	      ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke))
              {
                move = 1;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;


             }
             break;

             case Down:
              if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
            ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )
	    ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke)){
                move = 2;
                nextx= entity[0].x + dirx[move];
                nexty= entity[0].y + diry[move];
                entity[0].dir = move;
             }
             break;
                  }
            if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )
	       ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower)
	       ||(nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke))
                return;

    entity[0].x = nextx;
    entity[0].y = nexty;
   

    
    lose();

}

/*****Calcul de la distance Eucleudienne*****/
int distance(int x1, int x2, int y1, int y2){

    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
}

/*****La meilleur direction à choisir*****/
static int ennemy_dire(int entx,int ennx, int enty, int enny) {
int best=0, m, mindist = H*W;int nextx,minD,nexty;


    for(int m=0;m<5;m++){
        nextx = ennx + dirx[m];
        nexty = enny + diry[m];
        if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )||
          (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower)||
          (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[enny * W + ennx] == Smoke )||
	   (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke)){
            continue;
        }


        minD= distance(entx,nextx,enty,nexty);
        if(minD<mindist){
            mindist=minD;
            best  = m;
        }
    }
       return best;
}

/***A défaut de rendre l'un rapide que l'autre,impossibilité d'être à la même case que l'autre***/
static int ennemy2_dire(int entx,int ennx, int enty, int enny) {
int best=0, m, mindist = H*W;int nextx,minD,nexty; char *rien="je ne sers à rien en fait";


    for(int m=0;m<5;m++){
        nextx = ennx + dirx[m];
        nexty = enny + diry[m];
        if((nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Hill )||
            (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Flower )||
            (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[enny * W + ennx] == Smoke )||
	   (nextx < 0 || nextx >= W || nexty < 0 || nexty >= H || bg[nexty * W + nextx] == Brownsmoke)){
            continue;
        }

        if(nextx==entity[1].x && nexty==entity[1].y)
            return 0;

        minD= distance(entx,nextx,enty,nexty);
        if(minD<mindist){
            mindist=minD;
            best  = m;
        }
    }
       return best;
}
/*****Déplacement de l'ennemi avec la direction optimale****/
static void ennemy_move(int ent_id,int ennemy_dir){

    entity[ent_id].dir = ennemy_dir;
    entity[ent_id].x += dirx[ennemy_dir];
    entity[ent_id].y += diry[ennemy_dir];
    entity[ent_id].dir = ennemy_dir;
}

/* Ejection fumée */
static void smoke(int move){

   if(bg[entity[0].y * W + entity[0].x] == Grass){
        bg[entity[0].y* W +entity[0].x] = Smoke; 
    }
}


/***Gestion du score***/
static int score(void) {
     int point=0; int c = Grass;

    if(bg[entity[0].y*W+entity[0].x]== Flag)
       { 
            point += 100;
            entity[0].essence+=100;
            c = HundredP;
         
        }
    if(bg[entity[0].y*W+entity[0].x]== Flagl)
         { 
            point += 200;
            entity[0].essence+=200;
            c = THundredP;
         
        }
    if(bg[entity[0].y*W+entity[0].x]== Flags)
        { 
            point += 300;
            entity[0].essence+=300;
            c = TrHundredP;
         
        }
    int posflag =entity[0].y*W+entity[0].x;
            bg[posflag]= c;
            entity[0].score +=  point;

     if(entity[0].score == 1600)
    entity[0].score+= entity[0].essence;
   

}



void win(){
    for(int i =0; i < H*W;i++){

        if(entity[0].score >= 1600){
	  sleep(2);
        printf(" YOU WIN \n");
	 printf("Votre score est de %d\n", entity[0].score);
	 printf("A cours d'essence\n");
        exit(1);
        }   
    }
}


static void callback(void* d) {
    const Driver* dr = (Driver*)d;  
    static int tmp;
    static int decompte = 30;
    int move= dr->get_move();
   int best[2] = {ennemy_dire(entity[0].x,entity[1].x,entity[0].y,entity[1].y), 
        ennemy2_dire(entity[0].x,entity[2].x,entity[0].y,entity[2].y)};
        entity[1].essence=best[1];
        entity[2].essence=best[1];
    
    if(decompte <= 0)
    {
        for(int i = 0; i < H * W; ++i)
        {
            if((bg[i] == Smoke)||
                (bg[i] == HundredP)||
                (bg[i] == THundredP)||
                (bg[i] == TrHundredP)){


                bg[i] = Grass;
                
            }

        }
        decompte = 30;
    }

    if(move != 50)
        tmp = move;
   
    else if(move == 50)
        smoke(tmp);
  
    move = tmp;
    process_move(move);
    ennemy_move(1,best[0]); 
    ennemy_move(2,best[1]); 
    
    dr->draw_bg(); 
    dr->draw_entity(0);
    dr->draw_entity(1); 
    dr->draw_entity(2);
    lose();
    win();
    score();
    dr->update();
    decompte-=1;
 
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
    for(int i = 0; i < H * W; ++i)
        g.background[i] = level1[i] - 'A';
    g.entity[0].x = W/2;
    g.entity[0].y =5;
    g.entity[0].id = 0;
    g.entity[0].move_x = g.entity[0].move_y = 0;
    g.entity[0].dir = Right;
    g.entity[0].life = 3;
    g.entity[0].score = 0;
    g.entity[0].essence = 5000;
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

