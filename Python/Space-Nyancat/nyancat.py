# coding: utf-8
import pygame
import time
from pygame.locals import *
from random import*


white = (255,255,255)
Black = (0,0,0)
pygame.init()

fenetre_largeur=960
fenetre_hauteur=640
fenetre=pygame.display.set_mode([fenetre_largeur,fenetre_hauteur], RESIZABLE)

fond = pygame.image.load("nyan.jpg").convert()
pygame.display.set_caption("Nyancat")

a = 0
b = 0
fenetre.blit(fond, (a,b))
clock = pygame.time.Clock()

nyan = pygame.image.load('catt2.png')

img_boule = pygame.image.load('boule1.png')
boule_rect = img_boule.get_rect()

img_canon = pygame.image.load('as1.png')
canon_rect = img_canon.get_rect()

img_etoile = pygame.image.load('etoile.png')
etoile_rect = img_etoile.get_rect()

son = pygame.mixer.Sound('song.ogg')
over = pygame.mixer.Sound('over.ogg')
loser =pygame.mixer.Sound('Loser.ogg')
mun = pygame.image.load('Menu5.png')


def perso(x,y,image,rect):
    fenetre.blit(image,rect)

def obs(x,y, image, rect):
    rect.top = y 
    rect.left = x
    fenetre.blit(image,rect)

def collision(perso, objet):
    print "perso", perso.top, perso.bottom, perso.left, perso.right
    print "objet", objet.top, objet.bottom, objet.left, objet.right
    if not(perso.top > objet.bottom - 20 or \
           perso.bottom < objet.top + 20 or \
           perso.left > objet.right - 20 or \
           perso.right < objet.left + 20 ):
        return True
    return False


def QuickFail():
    for event in pygame.event.get():
    	if event.type == QUIT:
                pygame.quit()
                quit()
        if event.type == KEYDOWN:
        	if event.key == K_n :
	            pygame.quit()
	            quit()
		
        	if event.key == K_RETURN:
                    son.play()
                    over.stop()

                    return event.key
        
    return  None

def Police (texte, font):

    texteSurface = font.render(texte,True,white)
    return texteSurface, texteSurface.get_rect()

def stop (texte):
    poTexte = pygame.font.SysFont("Purisa", 50)
    poTexteSurf, poTexteRect = Police(texte, poTexte)
    poTexteRect.center = fenetre_largeur/2, ((fenetre_hauteur/2)-200)
    fenetre.blit(poTexteSurf, poTexteRect)
    
    smallTexte = pygame.font.SysFont("Serif", 30)
    smallTexteSurf, smallTexteRect = Police("Le jeu reprendra dans 5s ...", smallTexte)
    smallTexteRect.center = fenetre_largeur/2, ((fenetre_hauteur/2)+200)
    fenetre.blit(smallTexteSurf, smallTexteRect)
    pygame.display.update()
def pause():
    
    stop("Pause ")
    time.sleep(5)


def message (texte):
    BIGTexte = pygame.font.SysFont("Purisa", 70)
    BIGTexteSurf, BIGTexteRect = Police(texte, BIGTexte)
    BIGTexteRect.center = fenetre_largeur/2, ((fenetre_hauteur/2)-200)
    fenetre.blit(BIGTexteSurf, BIGTexteRect)
   
    smallTexte = pygame.font.SysFont("Serif", 30)
    smallTexteSurf, smallTexteRect = Police("Press Enter to Play else press N, turn up the volume", smallTexte)
    smallTexteRect.center = fenetre_largeur/2, ((fenetre_hauteur/2)+200)
    fenetre.blit(smallTexteSurf, smallTexteRect)
    
    pygame.display.update()
    

    while QuickFail() == None :
        clock.tick()
    main()

def message2 (texte):
    scoreTexte = pygame.font.SysFont("Serif", 40)
    scoreTexteSurf, scoreTexteRect = Police(texte, scoreTexte)
    scoreTexteRect.center = fenetre_largeur/2-400, ((fenetre_hauteur/2)-300)
    fenetre.blit(scoreTexteSurf, scoreTexteRect)

def scored():
    message2("Score :")

def gameOver():
    son.stop()
    loser.play()
    over.play()
    message("Game Over!")

def Menu():

    menu = True
    while menu:

        for event in pygame.event.get():
            if event.type == KEYDOWN:
                if event.key == K_RETURN:
                    menu = False
                if event.key == K_n:
                    pygame.QUIT()
            if event.type == QUIT:
                pygame.quit()     

        fenetre.blit(mun, (0,0))
        message("Welcome to Nyancat")
        pygame.display.update()

def main():
    x = -50
    y = 100
    position_perso = 0
    nyan_rect = nyan.get_rect()
    x_boule = 950
    y_boule = randint(0,640)
    x_canon = 950
    y_canon = randint(0,640)
    x_etoile = 950
    y_etoile = randint(0,640)

    ck  = pygame.time.Clock()   
    tk  = 0
    offset = 0
    speed  = -2
    width = fond.get_width()
    height = fond.get_height()
    variable = 0
    variable2 = 0
    Policescore = pygame.font.SysFont("Serif",35)
    Policescore2 = pygame.font.SysFont("Serif",70)
    score = Policescore.render(""+str(variable),False,white)
    score2 = Policescore2.render(""+str(variable2),False,white)
    score3 = Policescore2.render(""+str(variable2),False,white)

    pygame.key.set_repeat(400, 30)
    continuer = True

    while continuer:
        #Le score s'affiche dans la boucle
        variable += 0.01
        score = Policescore.render(""+str(variable),False,white)
        variable2 += 0.01
        score2 = Policescore2.render("Score :"+str(variable2),False,white)

        for event in pygame.event.get():
            if event.type == QUIT:
                continuer = False

            if event.type == KEYDOWN:
                if event.key == K_SPACE:
                    pause()
                if event.key == K_UP:
                    nyan_rect = nyan_rect.move(0,-20)
                if event.key == K_DOWN:
                    nyan_rect = nyan_rect.move(0,20)
                if event.key == K_a:
                    nyan_rect = nyan_rect.move(0,80)

        #Defilement du fond
        if tk >= 0:
            offset = (offset+speed)%width
            fenetre.blit(fond,(offset,0))
            fenetre.blit(fond,(offset-width,0))
            perso(x,y,nyan,nyan_rect)
            obs(x_boule,y_boule,img_boule,boule_rect)
            obs(x_canon,y_canon,img_canon,canon_rect)
            obs(x_etoile,y_etoile,img_etoile,etoile_rect)
            fenetre.blit(score,(150 ,4))
            
            scored()
            pygame.display.update()
            tk = 0
    
        x_boule -= 4
        if x_boule < (-1*fenetre_largeur):
            x_boule =fenetre_largeur
            y_boule =randint(0,640)

        x_canon -= 4.5
        if x_canon < (-1*fenetre_largeur):
            x_canon = 940
            y_canon = randint(0,640)
        x_etoile -= 1
        if x_etoile < (-1*fenetre_largeur):
            x_etoile = 940
            y_etoile = randint(0,640)
        tk += ck.tick()

        if collision(nyan_rect, etoile_rect):
            variable += 1.01
            variable2 += 1.01                      
        if  collision(nyan_rect, boule_rect) or \
           collision(nyan_rect, canon_rect): 
           fenetre.blit(score2,(300,300))   
           gameOver()

        # je l'affiche 3fois exprès pour que l'étoile scintille
        obs(x_etoile,y_etoile,img_etoile,etoile_rect)
        obs(x_etoile,y_etoile,img_etoile,etoile_rect)
        obs(x_etoile,y_etoile,img_etoile,etoile_rect)
        
        #si le y de mon perso atteint la hauteur de ma fenetre j'appelle game over 
        if nyan_rect.bottom > fenetre_hauteur +15 or nyan_rect.top < -15 :
            fenetre.blit(score2,(300,300))
            gameOver()

        if variable > 120:
            speed = -4
        if variable > 300:
            speed = -5
        if variable > 722:
            speed = -6
        if variable > 1157:
            speed = -8
        if variable > 2000:
            speed = -10
              
        pygame.display.update()

Menu()
main()   