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
        self.cooldown = 800    

    def fire(self):
        # fire gun, only if cooldown has been 0.3 seconds since last
        now = pygame.time.get_ticks()
        if now - self.last >= self.cooldown:
            self.last = now
            return True
        
class Enemy:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.xmove = -2
        self.width = 50
        self.height = 50
       
        
    def draw (self):
        pygame.draw.ellipse(screen, (255,255,255), (self.xpos,self.ypos,self.width,self.height))
        
            
    def turn(self):
        self.xpos+=self.xmove
        if self.xpos  < 0:
            self.xmove*=-1
        if self.xpos + self.width > 600:
            self.xmove*=-1
        
class Platform:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.blue = random.randrange(0,250)
        self.green = random.randrange(0,250)
        self.red = random.randrange(0,250)
        
    def draw(self):
            pygame.draw.rect(screen, (self.red, self.green, self.blue), (self.xpos, self.ypos,100, 20))

            
    def collide (self, x ,y):
          if x+40>self.xpos and x<self.xpos+100 and y+50 > self.ypos and y< self.ypos + 20:
              return True
          else:
            return False

loop = 6
ppp = Unit()
e1 = Enemy(300, 550)

platfur = list()

#a1 = Platform(200, 400)

for i in range(loop):
    platfur.append(Platform(i * 100, 480))

blam = False

px = 300
py = 300
vx = 0
vy = 0
pwidth = 40
pheight = 50
isOnGround = True
room = 1
      
doExit = False

while not doExit:
    
    clock.tick(60)

    events = pygame.event.get()

    for event in events:
      if event.type == pygame.quit:
        doExit = True

    keys = pygame.key.get_pressed()
    #LEFT MOVEMENT
    if keys[pygame.K_LEFT]==True:
        vx=-3
    #RIGHT MOVEMENT
    elif keys[pygame.K_RIGHT] == True:
        vx = 3
    #turn off velocity
    else:
        vx = 0
        #JUMPING
    if keys[pygame.K_UP] == True and isOnGround == True: #only jump when on the ground
        vy = -8
        isOnGround = False
        
        
        
    if px < 0:
        if room == 2:
            room = 1
            px = 500
        elif room == 3:
            room = 2
            px = 500
        else:
            px = 0
    if px+pwidth > 600:
        if room == 1:
          px = 600 - pwidth
          room = 2
          px = 100
        elif room == 2:
          px = 600 - pwidth
          room = 3
          px = 100
        elif room == 3:
          px = 600 - pwidth
          room = 4
          px = 100
        else:
            px = 600 - pwidth
    
      
    if py < 0:
      py = 0
      
    if py+pheight > 600:
      py = 600 - pheight
      isOnGround = True
    else:
        isOnGround = False
        
    if isOnGround == False:
        vy += .2
    
    if keys[pygame.K_SPACE]:
        if ppp.fire() == True:
            blam = True    
            
    else:
            blam =False
            
    px += vx
    py += vy
    #render------------------------
    screen.fill((0, 0, 0))
    
    if room == 1:
        for i in range(loop):
            platfur[i].draw()
            if platfur[i].collide(px, py) == True:
                isOnGround = True
                py = platfur[i].ypos - pheight 
                vy = 0
    if room == 2:
        for i in range(3):
            platfur[i].draw()
            if platfur[i].collide(px, py) == True:
                isOnGround = True
                py = platfur[i].ypos - pheight 
                vy = 0
    if room == 3:
        #a1.draw()
        for i in range(1):
            platfur[i].draw()
            if platfur[i].collide(px, py) == True:
                isOnGround = True
                py = platfur[i].ypos - pheight 
                vy = 0
    if room == 4:
        #a1.draw()
        for i in range(2):
            platfur[i].draw()
            if platfur[i].collide(px, py) == True:
                isOnGround = True
                py = platfur[i].ypos - pheight 
                vy = 0

    e1.draw()
    e1.turn()
    
        
    pygame.draw.rect(screen, color, (px,py, pwidth, pheight))
    if blam is True:
            shooty = py
            for i in range (600):
                pygame.draw.rect(screen, (255, 50, 50), (px + pwidth*2/5, shooty, 5, 5))
                shooty -= 1 

    pygame.display.flip() 

pygame.quit()
