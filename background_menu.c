#include "background_menu.h"


background initBackground(char * path, int w, int h){
  background bg;
  bg.bg_img = IMG_Load(path);

  if ( bg.bg_img == NULL ){
    printf("Unable to load background: %s\n", SDL_GetError());
    return bg;
  }
  bg.rect.x = 0;
  bg.rect.y = 25;
  bg.rect.w = w;
  bg.rect.h = h;
  return bg;

};
void displayBackground(background bg, SDL_Surface * screen){
  SDL_BlitSurface(bg.bg_img, NULL, screen, &bg.rect);
}
