#include "player.h"


void initPlayer (Player *p)
{
 p->spritesheet= IMG_Load("perso.png");

 p->position.x=50;
 p->position.y=300;

 p->direction=2; // right

 p->acceleration=0;
 p->speed=0;
 p->speedV=0;

 p->pos_sprite.x=0;
 p->pos_sprite.y=200;
 p->pos_sprite.h=100;
 p->pos_sprite.w=100;
}

void displayPlayer (Player p,SDL_Surface *screen)
{
  SDL_BlitSurface (p.spritesheet,&p.pos_sprite,screen,&p.position);
}

void movePlayer (Player *p,int dt)
{
 double dx;
 dx=0.5*p->acceleration*dt*dt+p->speed*dt;
 if (p->direction==0) // || (p->direction==2)
   {
     p->position.x+=dx;
    }
else if (p->direction==1)
    {
      p->position.x-=dx;
     }
}

void animePlayer (Player *p)
{
 p->pos_sprite.x+=100;
 if (p->pos_sprite.x>=1500)
   {
     p->pos_sprite.x=0;
    }
  p->pos_sprite.y=p->direction*100;
}

void jump (Player *p)
{
 if (p->position.y==300)
   {
     p->speedV=-50;
    }
}
