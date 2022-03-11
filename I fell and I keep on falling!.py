import pygame
import random
pygame.init()

screen = pygame.display.set_mode((800,800))
pygame.display.set_caption("Falling")
screen.fill((0,0,0))
clock = pygame.time.Clock()

doExit = False #Game Loop
   
class Platform:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.blue = random.randrange(0,250)
        self.green = random.randrange(0,250)
        self.red = random.randrange(0,250)
        self.size = 0
        num = random.randrange(1,5)
        print("num is ", num)
        if num == 1:
            self.size = 20
        elif num == 2:
            self.size = 40
        elif num == 3:
            self.size = 60
        elif num == 4:
            self.size = 80
        elif num == 5:
            self.size = 100
        
        
    def draw(self):
            pygame.draw.rect(screen, (self.red, self.green, self.blue), (self.xpos, self.ypos,self.size, 20))

            
    def move(self):

        if self.size == 20:
            self.ypos+=5
        elif self.size == 40:
            self.ypos+=3
        elif self.size == 60:
            self.ypos+=2
        elif self.size == 80:
            self.ypos+=1.5
        elif self.size == 100:
            self.ypos+=1
            
    #reset function
        #check if ypos+20 > 800
        #if yes, set ypos to be less than 0
        #maybe randomize the x pos
    def reset(self):
        if self.ypos+20 > 800:
            self.ypos = -20
            self.xpos = random.randrange(0,700)
   
p1 = Platform(200, 0)
p2 = Platform(500, -200)
p3 = Platform(300, -400)
p4 = Platform(300, -200)
p5 = Platform(400, -200)


#game loop--------------------------------------------------------------------------
while not doExit:
    
    clock.tick(60)
      
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True

    #physics section
    p1.move()
    p2.move()
    p3.move()
    p4.move()
    p5.move()
    #call reset function on each platform
    p1.reset()
    p2.reset()
    p3.reset()
    p4.reset()
    p5.reset()
    #render section
    screen.fill((0,0,0))
    p1.draw()
    p2.draw()
    p3.draw()
    p4.draw()
    p5.draw()
    pygame.display.flip()
