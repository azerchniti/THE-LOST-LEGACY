#include "background.h"
background_game initBack_game(char * path, int w, int h)
{background_game bg;
bg.bg_img = IMG_Load(path);

if ( bg.bg_img == NULL ){
  printf("Unable to load background: %s\n", SDL_GetError());
  return bg;
}
bg.rect.x = 0;
bg.rect.y = 0;
bg.rect.w = w;
bg.rect.h = h;
return bg;






}
void displayback_game( background_game bg, SDL_Surface * screen)
{
    SDL_BlitSurface(bg.bg_img, NULL, screen, &bg.rect);
}
