	
import pygame
import time
from pygame.locals import*
from random import*

pygame.init()
#les constantes du jeu
surfaceW =1000
surfaceH = 800
obstaclW = 100
obstaclH = 700
cote_rect = 35
couleur = (254, 50, 0)
couleur1 = (58, 2, 13)
couleur2 = (253, 241, 184)
couleur3 = (30, 20, 48)

#les elements/couches
surface = pygame.display.set_mode((surfaceW,surfaceH),RESIZABLE)
pygame.display.set_caption("flappy bird")
sot = pygame.mixer.Sound('sot.ogg')
sot2 = pygame.mixer.Sound('sot2.ogg')
sot3 = pygame.mixer.Sound('sot3.ogg')
img = pygame.Surface((cote_rect,cote_rect))
pygame.draw.rect(img, couleur1,(0, 0 , 35, 35))
obstacl1 = pygame.Surface((obstaclW,obstaclH))
pygame.draw.rect(obstacl1, couleur, (0 ,0, 700, 700))
obstacl2 = pygame.Surface((obstaclW,obstaclH))
pygame.draw.rect(obstacl2, couleur,(0, 0, 700, 700))
obstacl3 = pygame.Surface((obstaclW,obstaclH))
pygame.draw.rect(obstacl3,couleur,(0, 0, 700, 700))
obstacl4 = pygame.Surface((obstaclW,obstaclH))
pygame.draw.rect(obstacl4,couleur,(0, 0, 700, 700))

horloge = pygame.time.Clock()

#methodes
def rejoue_quit():
	for event in pygame.event.get([pygame.KEYDOWN,pygame.KEYUP,pygame.QUIT]):
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
			 	pygame.QUIT
				quit()
		if event.type == KEYDOWN:
			if event.key == K_RETURN:
				return event.key
	
	return None

def sawbtexte (texte,police):
	texteSurface = police.render(texte,True,couleur3)
	return texteSurface,texteSurface.get_rect()

def message (texte):

	texte01 = pygame.font.SysFont('Serif',85)
	texte02 = pygame.font.SysFont('Serif',40)
	texte03 = pygame.font.SysFont('Serif',40)


	texte01Surt,texte01Rect = sawbtexte(texte,texte01)
	texte01Rect.center = surfaceW/2,((surfaceH/2)-100)
	surface.blit(texte01Surt,texte01Rect)
	texte02Surt,texte02Rect = sawbtexte("<*> Pour jouer appuez sur *Entree*",texte02)
	texte02Rect.center = surfaceW/2,((surfaceH/2)+100)
	surface.blit(texte02Surt,texte02Rect)
	texte03Surt,texte03Rect = sawbtexte("<*> Pour quitter appuez sur *Echap*",texte03)
	texte03Rect.center = surfaceW/2,((surfaceH/2)+150)
	surface.blit(texte03Surt,texte03Rect)

	pygame.display.update()
	
	while rejoue_quit() == None :
		horloge.tick()

	totale()
def perdu  ():
	sot3.play()
	message ("*GAME*  *OVER*")


def obstacl00 (x_obstacl0,y_obstacl0,espace):
	surface.blit(obstacl3,(x_obstacl0,y_obstacl0))
	surface.blit(obstacl4,(x_obstacl0,y_obstacl0+espace+obstaclH))

def obstacl0 (x_obstacl,y_obstacl,espace):
	surface.blit(obstacl1,(x_obstacl,y_obstacl))
	surface.blit(obstacl2,(x_obstacl,y_obstacl+espace+obstaclH))

def objet (x,y,img):
	surface.blit(img, (x,y))
# la fonction du menu
def accueil():
	bienvenue = True
	while  bienvenue :
  	    for event in pygame.event.get():
	        if event.type == KEYDOWN:
	    		if event.key == K_RETURN:
	    			bienvenue = False
	    		if event.key == K_ESCAPE:
	    			pygame.quit()

	    surface.fill(couleur2)
	    message("*Welcome the flappyBird*")

# la fonction principale	    
def totale():
    x = 100
    y = 350
    y_mouvement = 0
    x_obstacl0 = (surfaceW+800)
    y_obstacl0 = -200       
    x_obstacl = (surfaceW+1500)
    y_obstacl = -300
    espace = 230
    obstacl_vitesse = 0.55
    game_over = False
    var = 0
    ktba = pygame.font.SysFont('Serif',200)
    score = ktba.render(""+ str (var),False,couleur3)
#la boucle principale
    while not game_over :
  	    for event in pygame.event.get():
	        if event.type == pygame.QUIT:
	    	    game_over = True
	    	if event.type == pygame.KEYDOWN :
	    		if event.key == pygame.K_SPACE:
	    			y_mouvement = - 0.8
	    			sot.play()	    		
	        if event.type == pygame.KEYUP :
	        	y_mouvement = 0.8	        			        		        		    
	    y += y_mouvement


        # personnage principale (le petit rectangle)         	    	    			    
	    objet(x,y,img)
	    if y > 770:
	    	perdu()

	    if y < 0:
	    	y = 0
	    	
	    # les coditions de mes obstacles
	    obstacl0(x_obstacl,y_obstacl,espace)
	    x_obstacl -= obstacl_vitesse
	    if x_obstacl < (-1*obstaclW):
	    	x_obstacl = surfaceW	    		    	
	    	y_obstacl = randint(-680,-130)
	    	var +=1
	    	score = ktba.render(""+ str (var),False,couleur3)
	    	sot2.play()
	    	surface.blit(score, (surfaceW/2-50,50))
	    	

	    # les coditions de mes obstacles 
	    obstacl00(x_obstacl0,y_obstacl0,espace)
	    x_obstacl0 -= obstacl_vitesse
	    if x_obstacl0 < (-1*obstaclW):
	    	x_obstacl0 = (x_obstacl+500)
	    	y_obstacl0 = randint(-680,-130)
	    	var += 1
	    	score = ktba.render(""+ str(var),False,couleur3)
	    	sot2.play()
	    surface.blit(score, (surfaceW/2-50,50))
	    pygame.display.flip()
	    surface.fill(couleur2)
	     
        #les colisions
	    if x + cote_rect > x_obstacl :
	    	if y < y_obstacl+obstaclH :
	    		if x - cote_rect < x_obstacl+obstaclW :
	    			surface.blit(score, (surfaceW/2-50,50))
	    			perdu()

	    if x + cote_rect > x_obstacl:
	    	if y + cote_rect > y_obstacl+obstaclH+espace:
	    		if x - cote_rect < x_obstacl + obstaclW:
	    			surface.blit(score, (surfaceW/2-50,50))
	    			perdu()
	    				    
	    if x + cote_rect > x_obstacl0 :
	    	if y< y_obstacl0+obstaclH :
	    		if x - cote_rect < x_obstacl0+obstaclW :
	    			surface.blit(score, (surfaceW/2-50,50))
	    			perdu()
	    			
	    if x + cote_rect > x_obstacl0:
	    	if y + cote_rect > y_obstacl0+obstaclH+espace:
	    		if x - cote_rect < x_obstacl0 + obstaclW:
	    			surface.blit(score, (surfaceW/2-50,50))
	    			perdu()
	    # la difficulte du jeu (augmentation de la vitesse)			
	    if var == 1:
	    	obstacl_vitesse +=0.00001
	    		
	    	

#appel des fonctions	
accueil()
totale()   
pygame.quit
quit()