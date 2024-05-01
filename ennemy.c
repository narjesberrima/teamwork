
#include "ennemy.h"







void initEnnemi(Ennemie *e)
{

    e->image_EN = IMG_Load("ENNEMIE2.png");

    e->pos_image_EN.x = 900;
    e->pos_image_EN.y = 400;

        e->single_EN.w=68;
	e->single_EN.h=60;
	e->single_EN.x=0;
	e->single_EN.y=0;
	e->EN_num=0;
       e->direction=0;  
       e->colis=0;
       e->show=1;
    
    
}



void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.image_EN,&e.single_EN, screen, &e.pos_image_EN);
  
  

}


void animerEnnemi(Ennemie *e)
{   if (e->EN_num >=0 && e->EN_num <9)
{ 
	e->single_EN.x=e->EN_num * e->single_EN.w;
 e->EN_num++;
}
    if ( e->EN_num ==9) 
{
       e->EN_num=0;
	e->single_EN.x=e->EN_num * e->single_EN.w;

}
}

void deplacere(Ennemie *e)
{	
	srand (time(0));

	int maxi_down=400+rand()%600; 
	int maxi_up=10+rand()%600; 

  	printf("maxup : %d\tmaxdown : %d\n",maxi_up,maxi_down );


if(e->pos_image_EN.x>= maxi_down)
{
e->direction =1;
	e->single_EN.y=60;
}
if(e->pos_image_EN.x<=maxi_up) 
{
e->direction =0;
	e->single_EN.y=0;
}

if(e->direction==1)
{   
	e->pos_image_EN.x-=5;

}
if(e->direction==0)
{
        
	e->pos_image_EN.x+=5;

}
}


void update_ennemie(Ennemie *e)
{ 	
	deplacere(e);
	animerEnnemi(e);	
}


int detect_collision_ennemie(personnage *p, Ennemie *e)
{
	

if ((p->perso_pos.x + p->perso_pos. w< e->pos_image_EN. x) || (p->perso_pos.x> e->pos_image_EN. x + e->pos_image_EN. w) ||
(p->perso_pos.y + p->perso_pos.h< e->pos_image_EN. y) || (p->perso_pos.y> e->pos_image_EN. y + e->pos_image_EN. h ))
return 0;
else 
return 1;
 
}

int gerer(Ennemie *e) {
	
	e->show=0;
	
	return 0; 
}








