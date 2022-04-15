import pygame

pygame.init


#creates game screen and caption
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("simple base code")
screen.fill((0,0,100))
clock = pygame.time.Clock()
#game variables
doExit = False #variable to quit out of game loop



class cloud:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        

    def draw(self):
            pygame.draw.arc(screen, (250,0,0), [self.xpos,self.ypos, 190, 240], 0, 3.14, 10)#base arc is at 80, 80
            pygame.draw.arc(screen, (200,100,0), [self.xpos+10,self.ypos+10, 170, 220], 0, 3.14, 10)
            pygame.draw.arc(screen, (200,200,0), [self.xpos+20,self.ypos+20, 150, 200], 0, 3.14, 10)
            pygame.draw.arc(screen, (0,200,0), [self.xpos+30,self.ypos+30, 130, 180], 0, 3.14, 10)
            pygame.draw.arc(screen, (0,100,150), [self.xpos+40,self.ypos+40, 110, 160], 0, 3.14, 10)
            pygame.draw.arc(screen, (0,0,200), [self.xpos+50,self.ypos+50, 90, 140], 0, 3.14, 10)
            pygame.draw.arc(screen, (100,0,100), [self.xpos+60,self.ypos+60, 70, 120], 0, 3.14, 10)




r1 = cloud(400,400)
r2 = cloud(100,100)
r3 = cloud(500,600)

#BEGIN GAME LOOP######################################################
while not doExit:
   
    clock.tick(60) #FPS (frames per second)
   
    #pygame's way of listening for events (key presses, mouse clicks, etc)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True #lets you quit program

    #keyboard input-----------------------------------
  
     
    #render section-----------------------------------


    
    r1.draw()
    r2.draw()
    r3.draw()


    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
