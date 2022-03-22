import pygame
pygame.init

Screenwidth = 800
Screenhight = 800



Red = 200
Green = 0
Blue = 200


Xpos = 200
Ypos = 400

With = 300
Hight = 300

Thickness = 10 



#creates game screen and caption
screen = pygame.display.set_mode((Screenwidth, Screenhight))
pygame.display.set_caption("simple base code")
#game variables
doExit = False #variable to quit out of game loop

#BEGIN GAME LOOP######################################################
while not doExit:
   
    #pygame's way of listening for events (key presses, mouse clicks, etc)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True #lets you quit program

    #keyboard input-----------------------------------
  
     
    #render section-----------------------------------
    pygame.draw.rect(screen, (Red, Green, Blue), (Xpos, Ypos, With, Hight), Thickness)


    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
