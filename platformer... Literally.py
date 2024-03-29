import pygame
import random
pygame.init()
pygame.display.set_caption("easy platformer")  # sets the window title
screen = pygame.display.set_mode((800, 800))  # creates game screen
screen.fill((0,0,0))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop

#CONSTANTS
LEFT=0
RIGHT=1
UP = 2
DOWN = 3

class Enemy:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.xmove = -2
        self.width = 50
        self.height = 50
       
        
    def draw (self):
        pygame.draw.ellipse(screen, (100,100,0), (self.xpos,self.ypos,self.width,self.height))
        
            
    def turn(self):
        self.xpos+=self.xmove
        if self.xpos  < 0:
            self.xmove*=-1
        if self.xpos + self.width > 800:
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
    
          if  x>self.xpos-20 and x<self.xpos+100 and y+40> self.ypos and y+40 < self.ypos+20:
              return True
          else:
            return False

#player variables
xpos = 500 #xpos of player
ypos = 200 #ypos of player
vx = 0 #x velocity of player
vy = 0 #y velocity of player
keys = [False, False, False, False] #this list holds whether each key has been pressed
isOnGround = False #this variable stops gravity from pulling you down more when on a platform

p1 = Platform(300, 700)
p2 = Platform(600, 600)
p3 = Platform(400, 500)
p4 = Platform(700, 700)
p5 = Platform(700, 500)

e1 = Enemy(300, 750)
#do 2-3 more times

while not gameover: #GAME LOOP############################################################
    clock.tick(60) #FPS
    
    #Input Section------------------------------------------------------------
    for event in pygame.event.get(): #quit game if x is pressed in top corner
        if event.type == pygame.QUIT:
            gameover = True
      
        if event.type == pygame.KEYDOWN: #keyboard input
            if event.key == pygame.K_LEFT:
                keys[LEFT]=True

            elif event.key == pygame.K_UP:
                keys[UP]=True
            elif event.key == pygame.K_RIGHT:
                keys[RIGHT]=True    
                
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                keys[LEFT]=False

            elif event.key == pygame.K_UP:
                keys[UP]=False
            elif event.key == pygame.K_RIGHT:
                keys[RIGHT]=False
          
    #physics section--------------------------------------------------------------------
    #LEFT MOVEMENT
    if keys[LEFT]==True:
        vx=-3
        direction = LEFT
    elif keys[RIGHT]==True:
        vx=3
    #turn off velocity
    else:
        vx = 0
        #JUMPING
    if keys[UP] == True and isOnGround == True: #only jump when on the ground
        vy = -8
        isOnGround = False
        direction = UP
    
    
    #COLLISION
   

    if p1.collide(xpos, ypos) != False:
        isOnGround = True
        vy = 0
        ypos = p1.ypos-40
    elif p2.collide(xpos, ypos) != False:
        isOnGround = True
        vy = 0
        ypos = p2.ypos-40
    elif p3.collide(xpos, ypos) != False:
        isOnGround = True
        vy = 0
        ypos = p3.ypos-40
    elif p4.collide(xpos, ypos) != False:
        isOnGround = True
        vy = 0
        ypos = p4.ypos-40
    elif p5.collide(xpos, ypos) != False:
        isOnGround = True
        vy = 0
        ypos = p5.ypos-40
    else:
        isOnGround = False


    
    #stop falling if on bottom of game screen
    if ypos > 760:
        isOnGround = True
        vy = 0
        ypos = 760
    
    #gravity
    if isOnGround == False:
        vy+=.2 #notice this grows over time, aka ACCELERATION
    

    #update player position
    xpos+=vx 
    ypos+=vy
    

    # RENDER Section--------------------------------------------------------------------------------
            
    screen.fill((0,0,0)) #wipe screen so it doesn't smear
  
    pygame.draw.rect(screen, (100, 200, 100), (xpos, ypos, 20, 40))
    
    
    
    
    p1.draw()
    
    p2.draw()
    
    p3.draw()
    
    p4.draw()
     
    p5.draw()
    
    e1.draw()
    e1.turn()
    
    
    
    pygame.display.flip()#this actually puts the pixel on the screen
    
#end game loop------------------------------------------------------------------------------
pygame.quit()
