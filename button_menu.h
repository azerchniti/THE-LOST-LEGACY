#ifndef button_menu_H
#define button_menu_h
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

typedef struct {
  SDL_Rect rect;
  SDL_Surface * button_img[2];
}
button;

button initButton(char * path_off, char* path_on, int x, int y, int w, int h);
void displayButton(button btn, SDL_Surface * screen, int state);
int isMouseOverButton(int mouse_x, int mouse_y, int entity_x, int entity_y, int entity_w, int entity_h);

#endif
