#ifndef player_H_INCLUDED
#define player_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct player
{
 int nb; //  player number
 SDL_Surface *spritesheet;
 SDL_Rect position; // position of the player in the background
 int direction;
 SDL_Rect pos_sprite;
 double speed,acceleration;
 int speedV;
// life
 SDL_Surface *image_life[4];
 SDL_Rect position_life;
 int val;
 SDL_Rect position_text;
// score
  char number[20];
  SDL_Rect position_textt;
  SDL_Rect position_number;
  int value_score;
}Player;


void initPlayer(Player *p);
void displayPlayer(Player p,SDL_Surface *screen);
void movePlayer(Player *p,int dt);
void animePlayer(Player* p);
void jump(Player* p);


#endif
