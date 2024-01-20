#include "button_menu.h"


button initButton(char * path_off, char* path_on, int x, int y, int w, int h){
  button btn;
  btn.button_img[0] = IMG_Load(path_off);
  btn.button_img[1] = IMG_Load(path_on);
  if ((btn.button_img[0] == NULL) || (btn.button_img[1] == NULL)){
    printf("Unable to load button: %s\n", SDL_GetError());
    return btn;
  }
  btn.rect.x = x;
  btn.rect.y = y;
  btn.rect.w = w;
  btn.rect.h = h;
  return btn;
}

void displayButton(button btn, SDL_Surface * screen, int state){
  SDL_BlitSurface(btn.button_img[state], NULL, screen, &btn.rect);
}

int isMouseOverButton(int mouse_x, int mouse_y, int entity_x, int entity_y, int entity_w, int entity_h){
  printf("%d %d\n", mouse_x, mouse_y);

  if ((mouse_x >= entity_x) && (mouse_x <= entity_x + entity_w)) {
    if ((mouse_y >= entity_y) && (mouse_y <= entity_y + entity_h)) {
      return 1;
    }
  }
  return 0;
}
