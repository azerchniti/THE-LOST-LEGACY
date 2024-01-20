#include "player.h"


int main()
{
TTF_Init();
/*Declaration of variables */
TTF_Font *font=NULL;
SDL_Surface *texte1=NULL;
SDL_Surface *number1=NULL;

SDL_Surface *screen;
TTF_Font *text=NULL;
SDL_Surface *texte=NULL;
SDL_Event event;
SDL_Surface *back;
Player p1;

int done=1;


int right1=0,left1=0,up1=0,dir1=2;

Uint32 dt;


Uint32 t_prev;
/*Initialization*/
screen=SDL_SetVideoMode (800,507,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("player\t1",NULL); // NAME OF THE WINDOW
back=IMG_Load("bg.png");
initPlayer(&p1);

/*SCORE*/


font=TTF_OpenFont("outils/arial.ttf",25);
SDL_Color white={255,160,122};
texte1=TTF_RenderText_Blended(font,"SCORE :",white);
p1.position_textt.x=15;
p1.position_textt.y=20;



/*SCORE MANAGEMENT*/



p1.number[20];
p1.value_score=99999; // p1.value_score=p1.value_score+1;
sprintf(p1.number,"%d",(p1.value_score)); // converion of an integer into a string of characters

number1=TTF_RenderText_Blended(font,p1.number,white);

p1.position_number.x=170;
p1.position_number.y=20;
TTF_CloseFont(font);
/*LIFE2*/
text=TTF_OpenFont("outils/arial.ttf",25);
SDL_Color couleur={255,160,122};
texte=TTF_RenderText_Blended(text,"LIFES",couleur);
p1.position_text.x=670;
p1.position_text.y=20;
TTF_CloseFont(text);

/*LIFE PLAYER 1*/
p1.image_life[0]=IMG_Load("outils/heart3.png");
p1.image_life[1]=IMG_Load("outils/heart2.png");
p1.image_life[2]=IMG_Load("outils/heart1.png");
p1.image_life[3]=IMG_Load("outils/heart0.png");
/* POSITION OF LIFE1*/
p1.position_life.x=590;
p1.position_life.y=1;
p1.val=4;

/*LIFE MANAGEMENT*/
int lifes=3;
lifes--;
p1.val--;
if (lifes==3)
 {
  SDL_FreeSurface(p1.image_life[3]);
 }
else if (lifes==2)
 {
  SDL_FreeSurface(p1.image_life[0]);
 }
else if (lifes==1)
 {
  SDL_FreeSurface(p1.image_life[1]);
 }
else if (lifes==0)
 {
  SDL_FreeSurface(p1.image_life[2]);
 }

/*BEGIN GAME LOOP*/
while(done)
{
t_prev=SDL_GetTicks();
while(SDL_PollEvent(&event))
{
 switch(event.type)
   {
     case SDL_QUIT:
       done=0;
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
                   up1=1;
                   break;
              }
      break;
          case SDL_KEYUP:
        switch(event.key.keysym.sym)
             {
                case SDLK_RIGHT:
                   right1=0;
                   dir1=2;
                   p1.speed=0;
                   break;
                case SDLK_LEFT:
                   left1=0;
                   dir1=3;
                   p1.speed=0;
                   break;
                case SDLK_UP:
                   up1=0;
                   break;
              }
      break;
}
}
/*UPDATE*/
if (right1==1)
{
  p1.speed=10;
  p1.acceleration+=0.5;
  p1.direction=0;
}
if (left1==1)
{
  p1.speed=10;
  p1.acceleration+=0.5;
  p1.direction=1;
}
if (up1==1)
{
 jump(&p1);
}


p1.acceleration-=0.3;


if (p1.acceleration<0)
{
  p1.acceleration=0;
}
if (p1.acceleration>4)
{
  p1.acceleration=4;
}



SDL_Delay(1);
dt=SDL_GetTicks()-t_prev; //dt=t2-t1
movePlayer(&p1,dt);
animePlayer(&p1);



if ((p1.speed==0)&&(p1.acceleration==0))
{
   p1.direction=dir1;//MEMORIZATION OF THE DIRECTION OF THE PLAYER 1
}

p1.position.y+=p1.speedV;
p1.speedV+=10;
if (p1.position.y>=300)
{
   p1.speedV=0; //THE PLAYER 1 GO BACK DOWN ALONE
   p1.position.y=300;
}


/*DISPLAY*/
SDL_BlitSurface(back,NULL,screen,NULL);
displayPlayer(p1,screen);


SDL_BlitSurface(p1.image_life[p1.val],NULL,screen,(&p1.position_life));


SDL_BlitSurface(texte,NULL,screen,&(p1.position_text));


SDL_BlitSurface(texte1,NULL,screen,&p1.position_textt);
SDL_BlitSurface(number1,NULL,screen,&p1.position_number);

SDL_Flip(screen);
SDL_Delay(50);


}
TTF_Quit();
}
