import pygame

pygame.init


#creates game screen and caption
screen = pygame.display.set_mode((800, 800))
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
    
    pygame.draw.rect(screen, (255,255,255), (120,120,100,40))
    pygame.draw.ellipse(screen, (255,255,255), (100,100,60,60))
    pygame.draw.ellipse(screen, (255,255,255), (130,80,80,80))
    pygame.draw.ellipse(screen, (255,255,255), (190,100,60,60))

    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
