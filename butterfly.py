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
         pygame.draw.ellipse(screen, (200,0,200), (self.xpos-60,self.ypos+60,100,100))
         pygame.draw.ellipse(screen, (150,0,250), (self.xpos-60,self.ypos,100,100))
         pygame.draw.ellipse(screen, (200,0,200), (self.xpos+10,self.ypos+60,100,100))
         pygame.draw.ellipse(screen, (150,0,250), (self.xpos+10,self.ypos,100,100))
         pygame.draw.ellipse(screen, (250,225,0), (self.xpos,self.ypos,50,150))
         pygame.draw.arc(screen, (250,125,0), [self.xpos+10,self.ypos+10, 30, 20], 7*3.14/6, 11*3.14/6, 4)
         pygame.draw.arc(screen, (250,125,0), [self.xpos+10,self.ypos+30, 30, 20], 7*3.14/6, 11*3.14/6, 4)
         pygame.draw.arc(screen, (250,125,0), [self.xpos+10,self.ypos+50, 30, 20], 7*3.14/6, 11*3.14/6, 4)
         pygame.draw.arc(screen, (250,125,0), [self.xpos+10,self.ypos+70, 30, 20], 7*3.14/6, 11*3.14/6, 4)
         pygame.draw.arc(screen, (250,125,0), [self.xpos+10,self.ypos+90, 30, 20], 7*3.14/6, 11*3.14/6, 4)
         pygame.draw.line(screen, (20,250,20), (self.xpos-30, self.ypos-50), (self.xpos+20, self.ypos+10))
         pygame.draw.line(screen, (20,250,20), (self.xpos+30, self.ypos+10), (self.xpos+80, self.ypos-50))

        

     
     
p1 = buterfly(400, 450)
p2 = buterfly(200, 200)
p3 = buterfly(500, 200)

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
    p2.draw()
    p3.draw()
    


    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
