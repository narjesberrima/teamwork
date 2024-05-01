#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>
#include "entity.h"


typedef struct {
	
	int direction;
	int colis ;
	int type;
	int maxi_up,maxi_down;
	int show;
        SDL_Surface *image_EN;  
	SDL_Rect pos_image_EN;
	SDL_Rect single_EN;	
	int EN_num;

}Ennemie;


void initEnnemi  (Ennemie *e) ;
void afficherEnnemi (Ennemie e, SDL_Surface *screen);
void animerEnnemi (Ennemie *e);
void update_ennemie(Ennemie *e);
void deplacere(Ennemie *e);


int detect_collision_ennemie(personnage *p, Ennemie *e);

int gerer(Ennemie *e) ; 


#endif 
