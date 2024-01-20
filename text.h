#ifndef text_H
#define text_h

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>
typedef struct
{
  char  str[50] ;
  int score  ;
}set ;
typedef struct{
SDL_Rect pos ;
TTF_Font  * font ;
SDL_Surface * surface ;
SDL_Color color ;
set S ;
} txt ;

txt init_string_input();
void clean_string(txt *t)  ;
void handle_input(txt *t, SDL_Event event , int i , int *loop);
void display_text(txt t ,SDL_Surface* screen )  ;
set* load_file(char file_name[],int *n) ;
set search_user(char file_name[],char name[]) ;
int nbr_users(char file_name[])  ;
void save_data(char file_name[],set s) ;
set best(char file_name[])  ;
#endif
