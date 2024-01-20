#include "mini.h"


mini init_minimap()
{ mini M  ;
  M.img=IMG_Load("/home/amor/Downloads/med.png") ;
  if(M.img != NULL) printf("Success\n") ;
  else printf("no \n") ;
  M.pos.x=  0 ;
  M.pos.y=   0;
  M.pos.w=200  ;  /// factor : 5   width :  200  height :156
  M.pos.h=   156;
M.player= IMG_Load("/home/amor/Downloads/point.png") ;
M.posp.x = 0  ;
M.posp.y=    98 ;
M.posp.w =   18  ;
M.posp.h =    18 ;

  return M ;
}
void display_minimap(mini M, SDL_Surface *screen)
{
SDL_BlitSurface(M.img,NULL,screen,&M.pos)  ;
}
//void update_mini(mini *M,player p)
//{M->posp.x+=(p.pos.x*38.6)/100 ;}
void update_mini(mini *M,player *p ,int input)
{
 if (input==2)
      M->posp.x+=1;
  else if (input==4)
      M->posp.x-=1 ;

  //if(p->pos.x>1000) {p->pos.x=0  ; M->posp.x=311 ; }
//  if(M->posp.x<311) M->posp.x=311  ;
}
