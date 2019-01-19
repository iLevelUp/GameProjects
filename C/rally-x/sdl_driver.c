#include "game.h"
#include "driver.h"
#include <stdio.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include <SDL.h>
#include <SDL_image.h>


static int init(const Game* game);
static void start(void(*callback)(void*));
static int get_move(void);
static int get_brume(void);
static void draw_bg(void);
static void draw_entity(int ent_id);
static void update(void);
int tmp=0;
Game gg;
Driver sdl_driver = {
    .game = NULL,
    .init = init,
    .start = start,
    .get_move = get_move,
    .draw_bg = draw_bg,
    .draw_entity = draw_entity,
    .update = update
};

static int dirx[] = {0, -1, 1, 0, 0};

static int diry[] = {0, 0, 0, -1, 1};

#define GAME (sdl_driver.game)

static SDL_Window *win;
static SDL_Renderer *ren;
static SDL_Texture* tiles[NCell];
static const char* tiles_files[] = {"fichier/ground.png","fichier/flower.png","fichier/grass.png","fichier/flower.png",
                                    "fichier/smoken.png","fichier/flag.png","fichier/flagf.png","fichier/flags.png",
                                    "fichier/100.png","fichier/200.png","fichier/300.png","fichier/400.png",
                                    "fichier/500.png","fichier/600.png","fichier/700.png","fichier/800.png",
                                    "fichier/900.png","fichier/1000.png","fichier/lose.png","fichier/brownsmoke.png"};
static SDL_Texture* sprites[NSprite];
static const char* sprites_files[] = {"fichier/care.png","fichier/caro.png","fichier/carn.png","fichier/cars.png","fichier/redo.png","fichier/rede.png","fichier/redn.png","fichier/reds.png" };

enum { SZ = 25};
enum { SZ1 = 5};
enum { FPS = 15 };

static int load_sprites(void) {
    int i;
    SDL_Surface *png;
    for(i = 0; i < NSprite; ++i) {
        png = IMG_Load(sprites_files[i]);
        if (png == NULL){
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            printf("Error: %s\n", SDL_GetError());
            SDL_Quit();
            return 1;
        }
        sprites[i] = SDL_CreateTextureFromSurface(ren, png);
        SDL_FreeSurface(png);
    }
    return 0;
}


static int load_tiles(void) {
    int i;
    SDL_Surface *png;
    for(i = 0; i < NCell; ++i) {
        png = IMG_Load(tiles_files[i]);
        if (png == NULL){
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            printf("Error: %s\n", SDL_GetError());
            SDL_Quit();
            return 1;
        }
        tiles[i] = SDL_CreateTextureFromSurface(ren, png);
        SDL_FreeSurface(png);
    }
    return 0;
}

static int init(const Game* game) {
    int i;

    GAME = game;
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("SDL_Init Error: %s\n",  SDL_GetError());
        return 1;
    }
    
    win = SDL_CreateWindow("Game", 0, 0, GAME->w * SZ, GAME->h * SZ, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
    if(load_tiles())
        return 1;
    
    if(load_sprites())
        return 1;
    Game gg;
Driver sdl_driver = {
    .game = NULL,
    .init = init,
    .start = start,
    .get_move = get_move,
    .draw_bg = draw_bg,
    .draw_entity = draw_entity,
    .update = update
};
    return 0;
}

static void start(void(*callback)(void*)) {
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(callback, &sdl_driver, FPS, 0);
#else
    for(;;) {
        callback(&sdl_driver);
        clock_t debut = clock();
        usleep(100000);
        clock_t ecoule = clock() - debut;
    }
#endif
}
static int get_move(void){
    SDL_PumpEvents();
    static int move=0;
    const Uint8 * state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_P]){
        SDL_Quit();
        exit(1);
    }
    if(state[SDL_SCANCODE_UP])
        move= Up;
    if(state[SDL_SCANCODE_LEFT])
        move = Left;
    if(state[SDL_SCANCODE_RIGHT])
        move = Right;
    if(state[SDL_SCANCODE_DOWN])
       move = Down;
    if(state[SDL_SCANCODE_X])
        return 50;
    
    return move;


}


static void draw_bg(void) {
    SDL_RenderClear(ren);
    static int xx= 1008, yy = 300 ;
    static int x2= 980, y2 = 300 ;
    static int x3= 940, y3 = 300 ;
    static int x4= 1045, y4 = 0 ;
    static int w1= 1000, h1 = 20 ;

    int x,y;
    int l, c;
    int move = get_move();
    SDL_Rect dst = {.x = 0, .y = 0, .w = SZ, .h = SZ };
    for(y = 0; y < GAME->h; ++y) {
        for(x = 0; x < GAME->w; ++x) {
            dst.x = x * SZ;
            dst.y = y * SZ;
            int typecell = GAME->background[y * GAME->w + x];
            SDL_RenderCopy(ren, tiles[typecell], NULL, &dst);
        }
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 100);
    SDL_Rect dataRect = { .x = (GAME->w -5) * SZ, .y = 0, .w = 5* SZ, .h = GAME->h * SZ };
    SDL_RenderFillRect(ren, &dataRect);

    SDL_SetRenderDrawColor(ren, 0, 200, 0, 100);
    SDL_Rect dataRect2 = { xx += dirx[move], yy+= diry[move], .w = 5, .h = 5 };
    SDL_RenderFillRect(ren, &dataRect2);
    
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 100);
    SDL_Rect dataRect3 = { x2 += dirx[GAME->entity[1].essence], y2+= diry[GAME->entity[1].essence], .w = 5, .h = 5 };
    SDL_RenderFillRect(ren, &dataRect3);
    
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 100);
    SDL_Rect dataRect4 = { x3 += dirx[GAME->entity[2].essence], y3+= diry[GAME->entity[2].essence], .w = 5, .h = 5 };
    SDL_RenderFillRect(ren, &dataRect4);

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 100);
    SDL_Rect dataRect5 = { x4 = 920, 0, w1 =GAME->entity[0].essence*(2*SZ)/5000,h1 };
    SDL_RenderFillRect(ren, &dataRect5);

}
    
    



static void draw_entity(int ent_id) {
    static int sp = 0;
    static int tmp;

   if(ent_id == 0){
    SDL_Rect src = {.x = 0, .y = 0, .w = SZ, .h = SZ };
    SDL_Rect dst = {.x = SZ * GAME->entity[ent_id].x, .y = SZ * GAME->entity[ent_id].y, .w = SZ, .h = SZ };
    if(GAME->entity[ent_id].dir==0){
        SDL_RenderCopy(ren, sprites[0], &src, &dst);
    }
    else SDL_RenderCopy(ren, sprites[GAME->entity[ent_id].dir-1], &src, &dst);
    
  }

    else if(ent_id ==1){
        
        SDL_Rect src = {.x = 0, .y = 0, .w = SZ, .h = SZ };
        SDL_Rect dst = {.x = SZ * GAME->entity[ent_id].x, .y = SZ * GAME->entity[ent_id].y, .w = SZ, .h = SZ };
        if(GAME->entity[ent_id].dir != 0){
            SDL_RenderCopy(ren, sprites[4+GAME->entity[ent_id].dir-1], &src, &dst);
            tmp = 4+GAME->entity[ent_id].dir-1;
             
        }
        else
        SDL_RenderCopy(ren, sprites[tmp], &src, &dst);
        
}

else if(ent_id ==2){
        
        SDL_Rect src = {.x = 0, .y = 0, .w = SZ, .h = SZ };
        SDL_Rect dst = {.x = SZ * GAME->entity[ent_id].x, .y = SZ * GAME->entity[ent_id].y, .w = SZ, .h = SZ };
        if(GAME->entity[ent_id].dir != 0){
            SDL_RenderCopy(ren, sprites[4+GAME->entity[ent_id].dir-1], &src, &dst);
            tmp = 4+GAME->entity[ent_id].dir-1;
        }
        else
        SDL_RenderCopy(ren, sprites[tmp], &src, &dst);

        
}

}

static void update(void) {
    SDL_RenderPresent(ren);
}  



