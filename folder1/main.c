
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "entity.h"
#include "ennemy.h"


int main()
{
    int hauteur_fenetre = 765,t,a=1,an=1,done=1,
        largeur_fenetre = 1360;
	

   

	SDL_Init(SDL_INIT_VIDEO);
//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
	SDL_WM_SetCaption("2024", NULL); 
// creation background
 	SDL_Surface *background ;
	SDL_Surface *sorry ;
	SDL_Rect pos_sorry ; 
	SDL_Rect background_pos;
	background = IMG_Load("b1jpg.jpg");
	background_pos.x = 0;
	background_pos.y = 0;
	sorry=IMG_Load("youlost.png");
	pos_sorry.x=300;
	pos_sorry.y=300;

 //initialisation 

 

	
	personnage p;
	entity e;
	Ennemie en;
	 

	initialiser_perso (&p) ;
	initentity (&e) ;
	initEnnemi (&en) ;
 

	
 



	SDL_Event event;
        while (done)
	{ 	 
		
	SDL_PollEvent(&event);

           
                        switch (event.type) 
                        {

                        case SDL_QUIT: 
                                done = 0;
                                break;


                        case SDL_KEYDOWN:                     
                                switch (event.key.keysym.sym) 
                                {                           
                                case SDLK_RIGHT: 
                                         
                                      p.perso_pos.x += 10;
                                      p.Vscore+=1;   p.Vscore+=1;                                                                    
                                        break;

                                case SDLK_LEFT: 
                                        p.perso_pos.x -= 10; 
                                         p.Vscore+=1;    p.Vscore+=1;                                                                    
                                        break;
                                case SDLK_UP: 
                                        p.perso_pos.y -= 10;
                                        p.Vscore+=1;   p.Vscore+=1;                                                                    
                                        break;
                                case SDLK_DOWN: 
                                      p.perso_pos.y += 10;
                                      p.Vscore+=1;       p.Vscore+=1;                                                                    
                                        break;
                                }
                        } 



	update_entity(&e);
        update_ennemie(&en);
 
	
	SDL_BlitSurface(background,NULL,screen,&background_pos);
	if(collisionTri(e,p.perso_pos)) {a=gestion(&e);} 
	if (a){ afficherentity(e ,screen);}
   	
   	if (detect_collision_ennemie(&p,&en)){ an=gerer(&en);}
   	
   	if (an) { 
       afficher_perso(p ,screen);afficherEnnemi (en ,screen);}
   	else{
    	 
   	SDL_BlitSurface(sorry,NULL,screen,&pos_sorry);
 	 
   	}
   	
	
	
 
	
	SDL_Delay(20);

	SDL_Flip(screen);

	}
	
	
	
	SDL_FreeSurface(background);
	SDL_FreeSurface(sorry);
	SDL_Quit();

    return 0;
}
