#ifndef mini_H
#define mini_h
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>
#include "player.h"

typedef struct{
SDL_Surface * img  ;
SDL_Rect  pos  ;
SDL_Surface * player   ;
SDL_Rect posp ;
} mini  ;


//void update_state(int direction,int *state) ;
mini init_minimap()  ;
void display_minimap(mini M, SDL_Surface *screen) ;
void update_mini(mini *M,player* p ,int input) ;
//void update_mini(mini *M,player p)  ;



#endif
