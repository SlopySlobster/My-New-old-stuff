import pygame
import random
pygame.init()


screen = pygame.display.set_mode((820,700))
pygame.display.set_caption("PONG")

bx = 350
by = 500

class Platform:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.blue = random.randrange(10,250)
        self.green = random.randrange(10,250)
        self.red = random.randrange(10,250)
        
    def draw(self):
            pygame.draw.rect(screen, (self.red, self.green, self.blue), (self.xpos, self.ypos, 80, 20))

            
    def collide (self, x ,y):
    
          if  x>self.xpos and x<self.xpos+100 and y+40> self.ypos and y+40 < self.ypos+20:
              return True
          else:
            return False
        
p1 = Platform(20, 20)
p2 = Platform(120, 20)
p3 = Platform(220, 20)
p4 = Platform(320, 20)
p5 = Platform(420, 20)
p6 = Platform(520, 20)
p7 = Platform(620, 20)
p8 = Platform(720, 20)

p9 = Platform(20, 50)
p10 = Platform(120, 50)
p11 = Platform(220, 50)
p12 = Platform(320, 50)
p13 = Platform(420, 50)
p14 = Platform(520, 50)
p15 = Platform(620, 50)
p16 = Platform(720, 50)

p17 = Platform(20, 80)
p18 = Platform(120, 80)
p19 = Platform(220, 80)
p20 = Platform(320, 80)
p21 = Platform(420, 80)
p22 = Platform(520, 80)
p23 = Platform(620, 80)
p24 = Platform(720, 80)

p25 = Platform(20, 110)
p26 = Platform(120, 110)
p27 = Platform(220, 110)
p28 = Platform(320, 110)
p29 = Platform(420, 110)
p30 = Platform(520, 110)
p31 = Platform(620, 110)
p32 = Platform(720, 110)


#game loop
doExit = False

#The clock
clock = pygame.time.Clock()

#paddle position
p1x = 340
p1y = 660
bVx = 5
bVy = 5

while not doExit: #GAME LOOP
    
    # event queue
    clock.tick(60)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True
            
    #game logic
    keys = pygame.key.get_pressed()
    if keys[pygame.K_a]:
        p1x-=5
    if keys[pygame.K_d]:
        p1x+=5
        
    #ball movement
    bx += bVx
    by += bVy
    
    #reflect ball off side walls of screen
   
    if by < 0 or by +20 > 700:
        bVy *= -1
        
    if bx < p1x and by > p1y and by < p1y + 100:
        bVx *= -1
        
    if bx > 800:
        bVx *= -1
        
    if bx < 0:
        bVx *= -1
        
    #render section
    screen.fill((0,0,0))
    pygame.draw.rect(screen, (255, 255, 255), (p1x, p1y, 100, 20), 1)
    pygame.draw.rect(screen, (255, 255, 255), (bx, by, 20, 20), 1)
    
    p1.draw()
    p2.draw()
    p3.draw()
    p4.draw()
    p5.draw()
    p6.draw()
    p7.draw()
    p8.draw()
    
    p9.draw()
    p10.draw()
    p11.draw()
    p12.draw()
    p13.draw()
    p14.draw()
    p15.draw()
    p16.draw()
    
    p17.draw()
    p18.draw()
    p19.draw()
    p20.draw()
    p21.draw()
    p22.draw()
    p23.draw()
    p24.draw()
    
    p25.draw()
    p26.draw()
    p27.draw()
    p28.draw()
    p29.draw()
    p30.draw()
    p31.draw()
    p32.draw()
    
    #updates the screen
    pygame.display.flip()
            

#END GAME LOOP
            
pygame.quit()
    
    
    
