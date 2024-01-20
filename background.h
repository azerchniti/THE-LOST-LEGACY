#ifndef background_H
#define background_H
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

typedef struct {
  SDL_Rect rect;
  SDL_Surface * bg_img;
}
background_game;

background_game initBack_game(char * path, int w, int h);
void displayback_game(background_game bg, SDL_Surface * screen);
#endif
