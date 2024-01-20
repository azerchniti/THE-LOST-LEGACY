#ifndef menu_H
#define menu_h
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "button_menu.h"
#include "background_menu.h"
#include "sound.h"
//#include "text.h"

typedef struct {
  background bg;
  button btn_list[5];
  int active_buttons;
  int current_on_button;

}
menu;
typedef struct{
  SDL_Rect rect;
  SDL_Surface * bg_img;
}background2 ;
background2 b ;
SDL_Surface * screen ;
Mix_Music * musics ;

void home_page();
void play_page();
void settings_page();
void display_menu(SDL_Surface * screen);

void display_menu_buttons_off(SDL_Surface* screen);


void onKeyDown(SDL_Event event, int * quit);
void changeButtonState(SDLKey key);
void update_menu(SDL_Surface * screen);
void onButtonActive(int * quit);
void onMouseHover(int x , int y );
int test() ;
background2 i() ;
void animate_bird( background2* b, int speed) ;
void display_bird(background2 b,  SDL_Surface * screen) ;
void init()  ;


void input(SDL_Event event, int *quit)  ;





#endif
