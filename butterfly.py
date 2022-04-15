import pygame

pygame.init


#creates game screen and caption
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("simple base code")
screen.fill((0,0,0))
clock = pygame.time.Clock()
#game variables
doExit = False #variable to quit out of game loop

class buterfly:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        
        
    def draw(self):
         pygame.draw.ellipse(screen, (255,100,0), (self.xpos,self.ypos,50,100))
     
     
p1 = buterfly(300, 300)

#BEGIN GAME LOOP######################################################
while not doExit:
   
    clock.tick(60) #FPS (frames per second)
   
    #pygame's way of listening for events (key presses, mouse clicks, etc)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True #lets you quit program

    #keyboard input-----------------------------------
  
     
    #render section-----------------------------------
    screen.fill((0,0,0))
    p1.draw()


    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
