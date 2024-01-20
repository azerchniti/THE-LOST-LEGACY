#include "enemy.h"


/* void initback (background *B) //initialize background
{
	B -> pic = IMG_Load ("bg4.jpg");
	if (B ->pic == NULL) { printf ("There has been an error. \n");}
	else { B->pos.x = 0;
		B->pos.y = 0;
		B->pos.w =  1000;
		B->pos.h = 780;}
} */

void initEnemy (Enemy* E)
{
	E -> pic [0] = IMG_Load ("stand.png");
	E -> pic [1] = IMG_Load ("right.png");
	E -> pic [2] = IMG_Load ("right1.png");
	E -> pic [3] = IMG_Load ("right2.png");
	E -> pic [4] = IMG_Load ("left.png");
	E -> pic [5] = IMG_Load ("left1.png");
	E -> pic [6] = IMG_Load ("left2.png");
	E -> pic [7] = IMG_Load ("dead.png");
if ((E->pic [0] == NULL))
	{ printf ("There has been an error. \n");}
	else { E->pos.x = 580;
		E->pos.y = 470;
		E->pos.w = 0;
		E->pos.h = 0;
		E->active_pic =0;
		E->state = 1;
		E->direction = 0;
		E->TotalNumber = 8;}
}


/*void liberateback (background B) //free the background
{
SDL_FreeSurface (B.pic);
} */

void liberateEnemy (Enemy E)
{
int i;
for (i=0;i<E.TotalNumber;i++) SDL_FreeSurface (E.pic[i]);
}

/*void displayback (background B, SDL_Surface* screen) //dipslay picture
{
SDL_BlitSurface (B.pic, NULL, screen, &B.pos);
}*/

void displayEnemy (Enemy E, SDL_Surface* screen) //dipslay picture
{
if (E.state ==1) {SDL_BlitSurface (E.pic[E.active_pic], NULL, screen, &E.pos); }
else {SDL_BlitSurface (E.pic[7], NULL, screen, &E.pos);}
}

void moveEnemy (Enemy* E)
{
	if (E->pos.x > posMax) {E->direction = 1;}
	if (E->pos.x < posMin) {E->direction = 0;}
	if (E->direction == 0) {E->pos.x ++;}
	else {E->pos.x -- ;}
}

void animateEnemy (Enemy* E)
{
	if (E->direction == 0) {if (E->active_pic < 3) {E->active_pic++;}
	else {E->active_pic=1;}}
	if (E->direction == 1) {if ((E->active_pic < 4) || (E->active_pic==6)) {E->active_pic=4;}
	else {E->active_pic++;}}
}

int CollisonBB (player P, Enemy E)
{
	int collision;
if ((P.pos.w + P.pos.x < E.pos.x) || (P.pos.x > E.pos.x + E.pos.w) || (P.pos.h + P.pos.y < E.pos.y) || (P.pos.y > P.pos.y + P.pos.h))
	{collision = 0;}
	else {collision = 1;}
	return collision;
}

/*void initPlayer (Enemy* E)
{
	E -> pic [0] = IMG_Load ("stand.png");
	E -> pic [1] = IMG_Load ("right.png");
	E -> pic [2] = IMG_Load ("right1.png");
	E -> pic [3] = IMG_Load ("right2.png");
	E -> pic [4] = IMG_Load ("left.png");
	E -> pic [5] = IMG_Load ("left1.png");
	E -> pic [6] = IMG_Load ("left2.png");
	E -> pic [7] = IMG_Load ("dead.png");
if ((E->pic [0] == NULL))
	{ printf ("There has been an error. \n");}
	else { E->pos.x = 400;
		E->pos.y = 400;
		E->pos.w = 88;
		E->pos.h = 125;
		E->active_pic =0;
		E->state = 1;
		E->direction = 0;
		E->TotalNumber = 8;}
}

void displayPlayer (Enemy E, SDL_Surface* screen) //dipslay picture
{
SDL_BlitSurface (E.pic[0], NULL, screen, &E.pos);
}*/

void checkcollision (player *P, Enemy E) //P is the player who will look dead if there is a collision
{
int collision;
collision = CollisonBB (*P, E);
if ((collision == 1) && (P->val > 0)) {P->val--;}
}
