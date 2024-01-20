#include "text.h"
txt init_string_input()
{ txt t ;
 t.S.str[0]= '\0' ;
 t.surface= NULL ;
 //SDL_EnableUNICODE(SDL_ENABLE);
//position
t.pos.x =  310;
t.pos.y=  310 ;
//Colors
t.color.r= 255  ;
t.color.g= 255  ;
t.color.b==5 ;
t.font= TTF_OpenFont("font.ttf",35)  ;

  return t ;
}
void clean_string(txt *t)
{
SDL_FreeSurface(t->surface) ;

SDL_EnableUNICODE(SDL_DISABLE)  ;

}
void handle_input(txt* t, SDL_Event event , int i , int *loop )
{


switch(event.key.keysym.sym )
{
case SDLK_a :  t->S.str[i]='a' ;
break ;
case SDLK_b:  t->S.str[i]='b' ;
break ;
case SDLK_c:   t->S.str[i]='c' ;
break ;
case SDLK_d:  t->S.str[i]='d' ;
break ;
case SDLK_e:  t->S.str[i]='e' ;
break ;
case SDLK_f :  t->S.str[i]='f' ;
break ;
case SDLK_g :  t->S.str[i]='g' ;
break ;
case SDLK_h:  t->S.str[i]='h' ;
break ;
case SDLK_i:  t->S.str[i]='i' ;
break ;
case SDLK_j:  t->S.str[i]='j' ;
break ;
case SDLK_k :  t->S.str[i]='k' ;
break ;
case SDLK_l:  t->S.str[i]='l' ;
break ;
case SDLK_m :  t->S.str[i]='m' ;
break ;
case SDLK_n :  t->S.str[i]='n' ;
break ;
case SDLK_o:  t->S.str[i]='o' ;
break ;
case SDLK_p:  t->S.str[i]='p' ;
break ;
case SDLK_q :  t->S.str[i]='q' ;
break ;
case SDLK_r:  t->S.str[i]='r' ;
break ;
case SDLK_s:  t->S.str[i]='s' ;
break ;
case SDLK_t:  t->S.str[i]='t' ;
break ;
case SDLK_u:  t->S.str[i]='u' ;
break ;
case SDLK_v:  t->S.str[i]='v' ;
break ;
case SDLK_w:  t->S.str[i]='w' ;
break ;
case SDLK_x:  t->S.str[i]='x' ;
break ;
case SDLK_y:  t->S.str[i]='y' ;
break ;
case SDLK_z:  t->S.str[i]='z' ;
break ;
case SDLK_SPACE: t->S.str[i]=' ' ;
break ;
case SDLK_RETURN : *loop=0 ;
break  ;

} t->S.str[i+1]='\0' ;
}
void display_text(txt t ,SDL_Surface* screen )
{
t.surface= TTF_RenderText_Solid(t.font,t.S.str,t.color)  ;
SDL_BlitSurface(t.surface,NULL,screen,&t.pos) ;


}
int nbr_users(char file_name[])
{  set s ;
FILE *f=NULL ;
int nbr=0 ;
f= fopen(file_name,"r+") ;
if(f!=NULL)
{
while(fscanf(f,"%s %d",s.str,&s.score)){
nbr++ ;

}} else printf("Error message\n") ;
return nbr ;

}
set* load_file(char file_name[],int *n)
{  FILE *f = NULL ;
  set *  s = NULL  ;
  int i=0  ;
  set temp ;

  f = fopen(file_name,"a+")  ;
*n=nbr_users(file_name) ;
if(*n != 0) {
s= (set*)  malloc((*n)*sizeof(set))  ;
if(s!= NULL ){

if(f!=NULL){
while(fscanf(f,"%s %d",temp.str,&temp.score))
{
s[i]=temp ;
  i ++ ;
}}else printf("File not opened\n")  ;
}else printf("Lack of memory space\n")  ;
}  else printf("Empty file\n")  ;



return s ;
}
set search_user(char file_name[],char name[])
{
FILE*f = NULL ;
 set temp ;
 f= fopen(file_name,"a+")  ;
 if(f!= NULL )
 {
while(fscanf(f,"%s %d",temp.str,&temp.score))
{ if (strcmp(temp.str,name)) return temp    ;

}
 } else printf("Error message\n")  ;
 temp.score=-1   ;
 return temp ;

}
void save_data(char file_name[] , set s)
{
 FILE *f= NULL ;
 f= fopen(file_name,"a+")  ;
 if(f!= NULL )
 {

fprintf(f,"%s %d\n",s.str,s.score)   ;


 } else printf("Error message\n") ;

}

set best(char file_name[])
{
 set s  ;
 set max   ;
FILE *f = NULL ;
f=  fopen(file_name,"r+")  ;
if(f!= NULL) {

fscanf(f,"%s %d\n",s.str,&s.score)  ;
 max.score=s.score ;
while(fscanf(f,"%s %d\n",s.str,&s.score) )
{

if(s.score > max.score)  max = s ;


}
} else printf("Error message\n")  ;



return max ;


}
