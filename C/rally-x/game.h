typedef struct Game Game;
typedef struct Driver Driver;
typedef struct Entity Entity;


struct Entity {
    int x;
    int y;
    int id;
    int dir;
    int life;
    int score;
    int essence;
    int move_x;
    int move_y;
};


struct Game {
    int h;
    int w;
    int screen_h;
    int screen_w;
    int screen_x;
    int screen_y;
    unsigned char* background;
    Entity* entity;
};
enum {
    Grass,
    Water,
    Hill,
    Flower,
    Smoke,
    Flag,
    Flagl,
    Flags,
    HundredP,
    THundredP,
    TrHundredP,
    FrHundredP,
    FHundredP,
    SxHundredP,
    SHundredP,
    EHundredP,
    NHundredP,
    Thousand,
    GameOver,
    Brownsmoke,
    NCell
};

enum {
    Bender,
    Vide,   
    tt,
    Tictac,
    enemmin,
    ennemis,
    ennemir,
    ennemil,
    NSprite
    
};

enum 
{
    Pet = 50,
};

enum {
    Nothing, Left, Right, Up, Down,
     
};

void init_game(const Driver*);

