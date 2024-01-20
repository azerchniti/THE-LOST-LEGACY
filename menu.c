#include "menu.h"


#define BUTTON_W 225
#define BUTTON_H 80
menu game_menu;
int page = 0;
int change = 0;
int old_active = 0;


void home_page(){
  game_menu.current_on_button = -1;
  game_menu.bg = initBackground("/home/amor/Downloads/bg25.png", 1916, 914);
  game_menu.btn_list[0] = initButton("/home/amor/Downloads/newgameoff.png", "/home/amor/Downloads/newgameon.png", 810, 322, 394, 98  );
  game_menu.btn_list[1] = initButton("/home/amor/Downloads/bestoff.png", "/home/amor/Downloads/beston.png", 810, 420, 394, 98);
  game_menu.btn_list[2] = initButton("/home/amor/Downloads/settingsoff.png", "/home/amor/Downloads/settingson.png", 850, 515,306, 98);
  game_menu.btn_list[3] = initButton("/home/amor/Downloads/quitoff.png", "/home/amor/Downloads/quiton.png", 870, 620,210, 97);


  game_menu.active_buttons = 4;
  page = 0;
}

void play_page(){
  game_menu.current_on_button = -1;
  game_menu.bg = initBackground("/home/amor/Downloads/test.png", 1916,914);
  game_menu.btn_list[0] = initButton("/home/amor/Downloads/homeoff.png", "/home/amor/Downloads/homeon.png", 475, 400, BUTTON_W, BUTTON_H);

  game_menu.active_buttons = -1;
  page = 1;
}

void settings_page(){
  game_menu.current_on_button = -1;
  game_menu.bg = initBackground("/home/amor/Downloads/bg2.png", 1440, 900);
  game_menu.btn_list[0] = initButton("/home/amor/Downloads/homeoff.png", "/home/amor/Downloads/homeon.png", 475, 400, BUTTON_W, BUTTON_H);
game_menu.btn_list[1] = initButton("/home/amor/Downloads/fulloff.png", "/home/amor/Downloads/fullon.png", 475, 550, BUTTON_W, BUTTON_H);
  game_menu.active_buttons = 2;
  page = 2;
}

void display_menu(SDL_Surface * screen){
//int p=0 ;

  displayBackground(game_menu.bg, screen);
  display_menu_buttons_off(screen);


}

void display_menu_buttons_off(SDL_Surface* screen){
  for (int i = 0; i < game_menu.active_buttons; i++){
    if (i == game_menu.current_on_button){
      displayButton(game_menu.btn_list[i],screen, 1);
      continue;
    }
    displayButton(game_menu.btn_list[i],screen, 0);
  }
}

void onKeyDown(SDL_Event event, int * quit){
  //int current_on_button;
  if ((event.key.keysym.sym == SDLK_DOWN) || (event.key.keysym.sym == SDLK_UP) ){
    changeButtonState(event.key.keysym.sym);
  } else if (event.key.keysym.sym == SDLK_RETURN){
    onButtonActive(quit);
  }
}


void changeButtonState(SDLKey key){
  if (key == SDLK_DOWN){
    if (game_menu.current_on_button == game_menu.active_buttons){
      game_menu.current_on_button = 0;

    } else {
      (game_menu.current_on_button)++;
    }
  } else if (key == SDLK_UP) {
    if (game_menu.current_on_button == -1){
      game_menu.current_on_button = game_menu.active_buttons - 1;
    } else {
      (game_menu.current_on_button)--;
    }
  }


  change = 1;
}

void update_menu(SDL_Surface * screen){






  if (change){
    display_menu(screen);
    SDL_Flip(screen);
//if(page == 1) displaytext(game_menu.t,screen)  ;
    change = 0;
  }

}

void onButtonActive(int * quit){
  switch(page){
    case 0:
      switch(game_menu.current_on_button){
        case 0:
          play_page();
          change = 1;
          break;
        case 1:
          settings_page();
          change = 1;
          break;
          case 2 :
          break ;
        case 3:
          *quit = 0;
          break;
      }
      break;
    case 1:
      if (game_menu.current_on_button == 0){
        home_page();
        change = 1; }

      break;

    case 2:
      if (game_menu.current_on_button == 0){
        home_page();
        change = 1;
      }
      break;
  }
}
void init(){
    if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0))
    printf("Could not initialize SDL: %s.\n", SDL_GetError());

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
 printf("%s", Mix_GetError()); }

void onMouseHover(int x, int y){
  old_active = game_menu.current_on_button;
  for (int i = 0; i < game_menu.active_buttons; i++)
    if (isMouseOverButton(x, y, game_menu.btn_list[i].rect.x,game_menu.btn_list[i].rect.y,game_menu.btn_list[i].rect.w,game_menu.btn_list[i].rect.h)){
      game_menu.current_on_button = i;
      change = 1;
initSound("game-menu-select-sound-effect.wav");
      return;
    }

  game_menu.current_on_button = -1;
  change = 1;
}
int test()
{ int x ;
  x = page ;


  return x ;
}
/*background2 i()
{
 background2 b ;
 b.bg_img = IMG_Load("/home/amor/game/resources/BIRD3.png");
 b.rect.w = 400;
 b.rect.h = 400;
 b.rect.x = 0;
 b.rect.y = 200;


return b ;

} */

void animate_bird( background2* b, int speed)
{
  b->rect.x += speed;



  if (b->rect.x >= 300){
    b->rect.x= 0;
    b->rect.y= 200;
  }
}
void display_bird(background2 b,  SDL_Surface * screen)
{SDL_BlitSurface(b.bg_img, NULL, screen, &b.rect);}
void input(SDL_Event event, int *quit)
{
  while (SDL_PollEvent( & event)) {
    switch (event.type) {
    case SDL_QUIT:
      *quit = 0;
      break;
    case SDL_KEYDOWN:
      onKeyDown(event, quit);
      break ;
      case SDL_MOUSEMOTION:
        onMouseHover(event.motion.x, event.motion.y);
        break;
      case SDL_MOUSEBUTTONUP:
        onButtonActive(quit); break ;
       }
     }
   }
