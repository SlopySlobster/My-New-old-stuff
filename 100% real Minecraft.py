import pygame
import math
import random
pygame.init

Monsterlist = [] #a list to hold all the monsters the monstergen makes



#function definition for circular collision-------------------------------------------
def CircularCollision(x1, y1, x2, y2):
    x1+=16 #adjust so center is not top left corner
    y1+=16
    if math.sqrt((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2)) < 50:
        return True
    else:
        return False

# parent class-------------------------------------------------------------------------
class Monster():    
          
        def __init__(self, x, y): #constructor
            self.xpos = x
            self.ypos = y
            self.health = 1000
            self.alive = True
            
            
        def getClicked(self, MouseX, MouseY):
            if CircularCollision(self.xpos, self.ypos, MouseX, MouseY)==True and self.alive==True:
                print("hit!")
                self.health-=10
                
        def ded(self):
            if self.health <= 0 and self.alive == True:
                print("I'm ded.")
                self.alive = False
        
  
# child class--------------------------------------------------------------------------
class Creeper( Monster ):           
        def __init__(self, xpos, ypos):
            self.CreeperPic = pygame.image.load('Danny.jfif')
           
            #call constructor of parent class 
            Monster.__init__(self, xpos, ypos)
            
        
        def draw(self):
            if self.alive == True: #dont draw ded monsters
                screen.blit(self.CreeperPic, (self.xpos, self.ypos))         

#add more child classes here! 

class Spider( Monster ):           
        def __init__(self, xpos, ypos):
            self.SpiderPic = pygame.image.load('Spider.jfif')
            
             #call constructor of parent class 
            Monster.__init__(self, xpos, ypos)
            
        
        def draw(self):
            if self.alive == True: #dont draw ded monsters
                screen.blit(self.SpiderPic, (self.xpos, self.ypos))
                
class Zombie( Monster ):           
        def __init__(self, xpos, ypos):
            self.ZombiePic = pygame.image.load('Zom.jfif')
            
             #call constructor of parent class 
            Monster.__init__(self, xpos, ypos)
            
        
        def draw(self):
            if self.alive == True: #dont draw ded monsters
                screen.blit(self.ZombiePic, (self.xpos, self.ypos))
                
class Skeleton( Monster ):           
        def __init__(self, xpos, ypos):
            self.SkeletonPic = pygame.image.load('Skeli.jfif')
            
             #call constructor of parent class 
            Monster.__init__(self, xpos, ypos)
            
        
        def draw(self):
            if self.alive == True: #dont draw ded monsters
                screen.blit(self.SkeletonPic, (self.xpos, self.ypos))
#Monster gen function definition------------------------------------------------------
def MonsterGen():
    num = random.randrange(0,100)
    if num < 20:
        Monsterlist.append(Creeper(random.randrange(0, 750), random.randrange(0, 750)))
    elif num < 50:
        Monsterlist.append(Spider(random.randrange(0, 500), random.randrange(0, 500)))
    elif num < 80:
        Monsterlist.append(Zombie(random.randrange(0, 500), random.randrange(0, 500)))
    else:
        Monsterlist.append(Skeleton(random.randrange(0, 500), random.randrange(0, 500)))  

#---------------------------------------------------------------------------------------------

# creation of an object variable or an instance for testing (most of the others are made by the monster gen)
#c1 = Creeper(200, 200)

#use monstergen to make the others
for i in range (20):
    MonsterGen()

#creates game screen and caption
screen = pygame.display.set_mode((800, 800))
pygame.display.set_caption("monster gen with inheritance")

#game variables
doExit = False #variable to quit out of game loop
clock = pygame.time.Clock() #sets up a game clock to regulate game speed
pos = pygame.mouse.get_pos()
click = False

#BEGIN GAME LOOP######################################################
while not doExit:
    
    #input section-----------------------------------
    clock.tick(60) #FPS (frames per second)
      
    #pygame's way of listening for events (key presses, mouse clicks, etc)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
           doExit = True #lets you quit program

    if event.type == pygame.MOUSEBUTTONDOWN: #get and store mouse input
        click = True
    
    if event.type == pygame.MOUSEBUTTONUP: #get and store mouse input
        click = False
        
    if click == True:
        pos = pygame.mouse.get_pos()

          
    #physics section----------------------------------
    for i in range (len(Monsterlist)):
        Monsterlist[i].getClicked(pos[0], pos[1])
        Monsterlist[i].ded()
          
    #render section-----------------------------------

    #redraw black background
    screen.fill((0,0,0))
     
    #c1.draw() #draw the test creeper
    
    #draw all the monsters in the list
    for i in range (len(Monsterlist)):
        Monsterlist[i].draw()
  
    pygame.display.flip() #update graphics each game loop

#END GAME LOOP#######################################################
pygame.quit()
