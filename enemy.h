#ifndef enemy_H
#define enemy_h
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#define posMax 610
#define posMin 300
#include "mini.h"

/*typedef struct {
SDL_Surface* pic;
SDL_Rect pos;
} background;*/

typedef struct {
  SDL_Rect pos;
  SDL_Surface *pic [8];
  int active_pic; //which image is being displaying
  int direction; //in which direction is the enemy moving 0 for right and 1 for left
  int state; //dead or alive 0 if dead and 1 if alive
  int TotalNumber; //of the enemy picture
}
Enemy;

/*void initback (background* B);
void displayback (background B, SDL_Surface * screen);
void liberateback(background B);
void initPlayer (Enemy *P);
void displayPlayer (Enemy P, SDL_Surface * screen);*/
void liberateEnemy (Enemy E);
void initEnemy(Enemy* E);
void displayEnemy(Enemy E, SDL_Surface * screen);
void animateEnemy (Enemy* E);
void moveEnemy (Enemy* E);
int CollisonBB (player P, Enemy E);
void checkcollision (player *P, Enemy E);
void moveIA (Enemy* E, SDL_Rect posPlayer); //still not done


#endif
