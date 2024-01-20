
#include "menu.h"
#include "text.h"
#include "background.h"
//#include "player.h"
#include "enemy.h"

int main(int argc , char ** argv)
{  init() ;
  TTF_Init();
   SDL_Event event ;
    SDL_Surface * screen ;
    background name ,game;
    //background_game game ;
    txt t ;
    mini M ;
    set s ;
    int i=0,direction=0, state=0 ,  start=0, loop=1,page=-1;
    int right1=0,left1=0,up=0,dir1=2;
    player p ;
    Uint32 dt,t_prev ;
Enemy E;
initEnemy(&E);
int amor =0 ;

screen= SDL_SetVideoMode(1920 , 940, 32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
home_page()  ;
display_menu(screen)  ;
SDL_Flip(screen) ;
    while(loop)
    {   input(event,&loop) ;
    update_menu(screen)  ;
   page = test()  ;
 if(page == 1 ) loop=0 ; }
loop=1 ;
name = initBackground("/home/amor/Downloads/test.png",1916,914) ;
t= init_string_input ()  ;
 while(loop)
{   while(SDL_PollEvent( & event) ){
    switch (event.type) {
    case SDL_QUIT:
      loop = 0;
      break;
      case SDL_KEYDOWN:
      handle_input(&t,event,i ,&loop )  ;
      display_text(t,screen)  ;
     SDL_Flip(screen) ;
  i++ ;

    break ;

       } }
}s=t.S  ;
loop=1  ;
game = initBackground("/home/amor/Downloads/b.png",1440,900) ;
//game= initBack_game("home/amor/Downloads/b.png",1000,780) ;

initplayer(&p) ;

//displayback_game(game,screen);
SDL_Flip(screen) ;
M= init_minimap() ;
screen= SDL_SetVideoMode(1000, 780, 32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
//SDL_WM_ToggleFullScreen(screen) ;
while(loop)
{amor=0 ;
  t_prev=SDL_GetTicks()  ;
  printf("%d\n",t_prev)  ;

  while(SDL_PollEvent(&event) )
  {
      switch(event.type)
      {   case SDL_QUIT:
            loop=0;
            break;
            case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                    {
                       case SDLK_RIGHT:
                          right1=1;
                          break;
                       case SDLK_LEFT:
                          left1=1;
                          break;
                       case SDLK_UP:
                          up=1;
                          break;
                     }
             break;
                 case SDL_KEYUP:
               switch(event.key.keysym.sym)
                    {
                       case SDLK_RIGHT:
                          right1=0;
                          dir1=2;
                          p.speed=0;
                          break;
                       case SDLK_LEFT:
                          left1=0;
                          dir1=3;
                          p.speed=0;
                          break;
                       case SDLK_UP:
                          up=0;
                          break;
                     }
             break;  }

          }  if(right1==1)  amor=2  ;
          if(left1== 1) amor= 4 ;

           if (E.state == 1) {moveEnemy (&E); 	//Enemy movement and animation
            		   animateEnemy (&E);
            			checkcollision (&p, E); }
                  update(&p , right1, left1, up) ;   /// AMOR DID THAT
                  update_acceleration(&p)  ;
                  SDL_Delay(1);
                  dt=SDL_GetTicks()-t_prev; //dt=t2-t1
                  moveplayer(&p,dt);
                  animeplayer(&p);
                  check(&p,dir1) ;
        update_mini(&M,&p,amor)  ;
           displayBackground(game,screen)  ;
             display_minimap(M,screen) ;
              SDL_BlitSurface(M.player,NULL,screen,&M.posp) ;
                     displayEnemy (E, screen);
            displayplayer(p ,screen)  ;
            SDL_Flip(screen) ;
            if(t_prev> 17000) loop=0 ;
            display_minimap(M,screen) ;

          //  dt=SDL_GetTicks()- t_prev ;
              }





save_data("players.txt",s)  ;
killMusic();
//liberateEnemy (E); //liberation of Enemy

Mix_FreeMusic(musics);
SDL_Quit();

               return 0  ;  }
