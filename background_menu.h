#ifndef background_menu_H
#define background_menu_H
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
background;

background initBackground(char * path, int w, int h);
void displayBackground(background bg, SDL_Surface * screen);
#endif
