import pygame
import math
pygame.init()  
pygame.display.set_caption("sprite sheet")  # sets the window title
screen = pygame.display.set_mode((832, 800))  # creates game screen
screen.fill((0,0,0))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop

#CONSTANTS
LEFT = 0
RIGHT = 1
UP = 2
DOWN = 3
SPACE = 4

class fireball:
    def __init__(self):
        self.xpos = -10 #draw offscreen when not in use
        self.ypos = -10
        self.isAlive = False
        self.direction = RIGHT
    def shoot(self, x, y, dir):
        self.xpos = x + 20
        self.ypos = y + 20
        self.isAlive = True
        self.direction = dir
    def move(self):
        if self.direction == RIGHT:
            self.xpos+=20
        elif self.direction == DOWN:
            self.ypos+=20
        elif self.direction == LEFT:
            self.xpos-=20
        elif self.direction == UP:
            self.ypos-=20
        #add other directions here
    def draw(self):
        pygame.draw.circle(screen, (250, 0, 0), (self.xpos, self.ypos), 10)
        pygame.draw.circle(screen, (250, 250, 0), (self.xpos, self.ypos), 5)
    def collide(self, x, y):
        if math.sqrt((self.xpos - x) ** 2 + (self.ypos - y) ** 2) < 25: #25 is radius of fireball + radius of potato
            print("collision!")
            return True
        else:
            return False
       

ball = fireball()

#MAP: 1 is grass, 2 is brick
map = [[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,2 ,2, 2,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,2 ,2, 2,2],
       [2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 2, 2, 2, 0, 0, 0, 2, 0, 0, 0, 2 ,2 ,2, 2,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 ,0 ,0, 0,0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0 ,0 ,2, 2,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 2, 0, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 ,2 ,2, 0,2],
       [2, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0 ,0 ,2, 2,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 2, 0, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 ,2 ,2, 0,2],
       [2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 ,0 ,0, 0,0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0 ,0 ,0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0 ,0 ,2, 2,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0, 0,2],
       [2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0 ,0 ,0, 0,0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 ,2 ,2, 0,2],
       [2, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 2, 2 ,2 ,0, 0,0, 0, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0 ,2 ,0, 0,2],
       [2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,2 ,2, 2,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 ,2 ,2, 2,2]]

brick = pygame.image.load('brick.png') #load your spritesheet
Link = pygame.image.load('link.png') #load your spritesheet
PotatoPic = pygame.image.load("potato.jpg")
Link.set_colorkey((255, 0, 255)) #this makes bright pink (255, 0, 255) transparent (sort of)

#player variables
xpos = 400 #xpos of player
ypos = 400 #ypos of player
vx = 0 #x velocity of player
vy = 0 #y velocity of player
x_offset = 0
y_offset = 0
keys = [False, False, False, False, False] #this list holds whether each key has been pressed
isOnGround = False #this variable stops gravity from pulling you down more when on a platform
movingx = False
movingy = False

#animation variables variables
frameWidth = 32
frameHeight = 46
RowNum = 0 #for left animation, this will need to change for other animations
frameNum = 0
ticker = 0
direction = DOWN

while not gameover:
    clock.tick(60) #FPS
   
    for event in pygame.event.get(): #quit game if x is pressed in top corner
        if event.type == pygame.QUIT:
            gameover = True
     
        if event.type == pygame.KEYDOWN: #keyboard input
            if event.key == pygame.K_LEFT:
                keys[LEFT] = True
            elif event.key == pygame.K_RIGHT:
                keys[RIGHT] = True
            elif event.key == pygame.K_UP:
                keys[UP] = True
            elif event.key == pygame.K_DOWN:
                keys[DOWN] = True
            elif event.key == pygame.K_SPACE:
                keys[SPACE] = True
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                keys[LEFT] = False
            elif event.key == pygame.K_RIGHT:
                keys[RIGHT] = False
            elif event.key == pygame.K_UP:
                keys[UP] = False
            elif event.key == pygame.K_DOWN:
                keys[DOWN] = False
            elif event.key == pygame.K_SPACE:
                keys[SPACE] = False
         

    #LEFT MOVEMENT
    if keys[LEFT] == True:
        if xpos > 400:
            vx = -3
        elif x_offset < 0:
            x_offset+=3
            vx = 0
        else:
            vx = -3
        RowNum = 0
        direction = LEFT
        movingx = True
       
    #RIGHT MOVEMENT
    elif keys[RIGHT] == True:
        if xpos < 400:
            vx = 3
        elif x_offset > -800:
            x_offset-=3
            vx = 0
        else:
            vx = 3
        RowNum = 1
        direction = RIGHT
        movingx = True
    #turn off velocity
    else:
        vx = 0
        movingx = False

    #check space for shooting
    if keys[SPACE] == True:
        ball.shoot(xpos, ypos, direction)
       
    ball.move()

       
    #DOWN MOVEMENT
    if keys[DOWN] == True:
        if ypos < 400:
            vy = 3
        elif y_offset > -800:
            y_offset-=3
            vy = 0
        else:
            vy = 3
        RowNum = 1
        RowNum = 3
        direction = DOWN
        movingy = True

         #UP MOVEMENT
    elif keys[UP] == True:
        if ypos > 400:
            vy = -3
        elif y_offset < 0:
            y_offset+=3
            vy = 0
        else:
            vy = -3
        RowNum = 0
        RowNum = 2
        direction = UP
        movingy = True
    #turn off velocity
    else:
        vy = 0
        movingy = False
       



    xpos+=vx #update player xpos
    ypos+=vy

   
    #COLLISION
   
    #down collision
    if map[int((ypos - y_offset + frameHeight) / 50)][int((xpos - x_offset + frameWidth / 2) / 50)] == 2:
        ypos-=3
   
    #up collision
    if map[int((ypos - y_offset) / 50)][int((xpos - x_offset + frameWidth / 2) / 50)] == 2:
        ypos+=3
       
    #left collision
    if map[int((ypos - y_offset + frameHeight - 10) / 50)][int((xpos - x_offset - 10) / 50)] == 2 :
        xpos+=3
       
    #right collision
    if map[int((ypos - y_offset) / 50)][int((xpos - x_offset + frameWidth + 5) / 50)] == 2:
        xpos-=3    

    #stop moving if you hit edge of screen (will be removed for scrolling)
    if xpos + frameWidth > 800:
        xpos-=3
    if xpos < 0:
        xpos+=3

    #potato collision!
    if ball.collide(215, 215) == True:
        ball.isAlive = False
        #you probably want to do other stuff here too, like kill the potato
        #eventually


    #ANIMATION-------------------------------------------------------------------
       
    # Update Animation Information

    if movingx == True or movingy == True: #animate when moving
        ticker+=1
        if ticker % 10 == 0: #only change frames every 10 ticks
          frameNum+=1
        if frameNum > 7:
           frameNum = 0
 
    # RENDER--------------------------------------------------------------------------------
    # Once we've figured out what frame we're on and where we are, time to
    # render.
           
    screen.fill((0,0,0)) #wipe screen so it doesn't smear
   
    #draw map
    for i in range(28):
        for j in range(33):
            if map[i][j] == 1:
                screen.blit(dirt, (j * 50 + x_offset, i * 50 + y_offset), (0, 0, 50, 50))
            if map[i][j] == 2:
                screen.blit(brick, (j * 50 + x_offset, i * 50 + y_offset), (0, 0, 50, 50))
   
    #draw fireball
    if ball.isAlive == True:
        ball.draw()
    #draw player
    screen.blit(Link, (xpos, ypos), (frameWidth * frameNum, RowNum * frameHeight, frameWidth, frameHeight))
    #draw potato
    screen.blit(PotatoPic, (200 + x_offset, 200 + y_offset))
    pygame.display.flip()#this actually puts the pixel on the screen
   
#end game
#loop------------------------------------------------------------------------------
pygame.quit()
