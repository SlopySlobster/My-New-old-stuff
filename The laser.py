import pygame
import random

pygame.init()
pygame.display.set_caption("FLOPPA FINAL")
screen = pygame.display.set_mode((600,600))
clock = pygame.time.Clock()

col1 = random.randrange(0,255)
col2 = random.randrange(0,255)
col3 = random.randrange(0,255)

color = (col1, col2, col3)

BLACK = (0,0,0)

class Unit():
    def __init__(self):
        self.last = pygame.time.get_ticks()
        self.cooldown = 300    

    def fire(self):
        # fire gun, only if cooldown has been 0.3 seconds since last
        now = pygame.time.get_ticks()
        if now - self.last >= self.cooldown:
            self.last = now
            return True


ppp = Unit()

px = 300
py = 300
pwidth = 40
pheight = 50
isOnGround = False

     
doExit = False

enem = list()

while not doExit:
   
    clock.tick(60)

    events = pygame.event.get()

    for event in events:
      if event.type == pygame.quit:
        doExit = True

    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        px -= 5
    if keys[pygame.K_RIGHT]:
      px +=5
    if keys[pygame.K_UP]:
      py -=8
      isOnGround = False
    if px < 0:
      px = 0
    if px+pwidth > 600:
      px = 560
    if py < 0:
      py = 0
    if py+pheight > 600:
      py = 550


    if py > 550:
        isOnGround = False
        vy = 0
        py = 550
    
    #gravity
    if isOnGround == False:
        py+=.2 #notice this grows over time, aka ACCELERATION

    if keys[pygame.K_SPACE]:
        if ppp.fire() == True:
            blam = True    
            
    else:
            blam =False

    #render------------------------
    screen.fill((0, 0, 0))

       
    pygame.draw.rect(screen, color, (px,py, pwidth, pheight))
    if blam is True:
            shooty = py
            for i in range (600):
                pygame.draw.rect(screen, (255, 50, 50), (px + pwidth*2/5, shooty, 5, 5))
                shooty -= 1

    pygame.display.flip()

pygame.quit()
