import pygame
import random


pygame.init()#set up pygame
pygame.display.set_caption("Space Invaders!")
screen = pygame.display.set_mode((1225, 800))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop


#player variables
xpos = 400
ypos = 750
moveLeft = False
moveRight = False
shoot = False


#game variables
timer = 0

class Bullet:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.isAlive = False

    def move(self, xpos, ypos):
        if self.isAlive == True: # only shoot live bullets
            self.ypos-=5 #move up when shot
        if self.ypos < 0: #check if you've hit the top of the screen
            self.isAlive = False #set to dead
            self.xpos = xpos #reset to player position
            self.ypos = ypos

    def draw(self):
        if self.isAlive == True:
            pygame.draw.rect(screen, (250, 250, 250), (self.xpos, self.ypos-20, 4, 10))


#instantiate bullet object
bullet = Bullet(xpos+28, ypos)#create bullet object and pass player position


class Missile:
    def __init__(self):
        self.xpos = -20
        self.ypos = -20
        self.isAlive = False 

    def move(self, xpos, ypos):
        if self.isAlive == True: # only shoot live bullets
            self.ypos+=5 #move down when shot
        if self.ypos > 800: #check if you've hit the top of the screen
            self.isAlive = False #set to dead
            self.xpos = xpos #reset to player position
            self.ypos = ypos

    def draw(self):
        if self.isAlive == True:
            pygame.draw.rect(screen, (250, 250, 250), (self.xpos, self.ypos-20, 4, 10))

#instantiate missile object
missile = Missile()


class Alien:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.isAlive = True
        self.direction = 1

    def draw(self):
        if self.isAlive == True:
            pygame.draw.rect(screen, (0, 250, 0), (self.xpos, self.ypos, 40, 40))


    def move(self, time):

        #reset what direction you're moving every 8 moves:
        if time % 400 == 0:
            self.ypos += 100 #move down
            self.direction *=-1 #flip direction
            return 0 #resets timer to 0

        #move every time the timer increases by 100:
        if time % 100 == 0:
            self.xpos+=50*self.direction #move right

        return time #doesn't reset if first if statement hasn't executed

    def collide(self, BulletX, BulletY):
        if self.isAlive: #only hit live aliens
            if BulletX > self.xpos: #check if bullet is right of th left side of the alien
                if BulletX < self.xpos + 40: #check if the bullet is left of the right side
                    if BulletY < self.ypos + 40: #check if the bullet is left of the right side
                        if BulletY > self.ypos: #check if the bullet is below the top of the alien
                            print("hit!") #for testing
                            self.isAlive = False #set the alien to dead
                            return False #set the BULLET to dead
        return True #otherwise keep bullet alive


class Wall:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.numHits = 0
        #print("In constructor, numHits is", self.numHits)

    def draw(self):
        print("inside draw, numHits is", self.numHits)
        if self.numHits == 0:
            pygame.draw.rect(screen, (0, 250, 0), (self.xpos, self.ypos, 150, 100))
        elif self.numHits == 1:
            pygame.draw.rect(screen, (0, 150, 0), (self.xpos, self.ypos, 150, 100))
        elif self.numHits == 2:
            pygame.draw.rect(screen, (0, 50, 0), (self.xpos, self.ypos, 150, 100))

    def collide(self, BulletX, BulletY):
        if self.numHits < 3: #only hit if wall has less thant three hits
            if BulletX > self.xpos: #check if bullet is right of th left side of the wall
                if BulletX < self.xpos + 150: #check if the bullet is left of the right side
                    if BulletY < self.ypos + 100: #check if the bullet is left of the right side
                        if BulletY > self.ypos: #check if the bullet is below the top of the wall
                            print("hit!") #for testing
                            self.numHits+=1 #add hit to wall
                            return False #set the BULLET to dead
        return True #otherwise keep bullet alive


armada = [] #creates empty list
for i in range (4): #handles rows
    for j in range(9): #handles columns
        armada.append(Alien(j*75+275, i*75+75))
walls = [] #creates empty list
for k in range (4): #creates 4 sets
    for i in range (1): #handles rows
        for j in range (1): #handles columns
            walls.append(Wall(j*30+300*k+80, i*30+550)) #push wall objects ino list
missiles = []
for i in range (10):
    missiles.append(Missile())

while not gameover:
    clock.tick(60)
    timer +=1

    # Input Section-----------------------------------------------------------------------------------------------------

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameover = True #quits the game if the x on the top righ corner is pressed

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                moveLeft = True
            if event.key == pygame.K_RIGHT:
                moveRight = True
            if event.key == pygame.K_SPACE:
                shoot = True

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                moveLeft = False
            if event.key == pygame.K_RIGHT:
                moveRight = False
            if event.key == pygame.K_SPACE:
                shoot = False
       
    # Physics section--------------------------------------------------------------------------------------------------


    # checks variables from the input section

    for i in range (len(armada)):
        timer = armada[i].move(timer)

    # Left movement
    if moveLeft == True:
        vx =-3

    # Right movement
    elif moveRight == True:
        vx =+ 3

    else:
        vx = 0


    #shoot bullet
    if shoot == True: #check keyboard input
        bullet.isAlive = True

    if bullet.isAlive == True:
        bullet.move(xpos+28, ypos) #shoot from player position
        if bullet.isAlive == True:
        #check for collision between bullet and enemy
            for i in range (len(armada)): #check bullet with entire armada's positions
                bullet.isAlive = armada[i].collide(bullet.xpos, bullet.ypos) #if we hit, set bullet to false
                if bullet.isAlive == False:
                    break
    
    #picks a random number
    fire = random.randrange(100)

    #shoot missile
    if fire % 100 <=2:
        pick = random.randrange(len(armada))#picks a random alien to fire
        if armada[pick].isAlive == True: #checks if the alien picked is alive
            for i in range(len(missiles)): #finds the first live missile
                if missiles[i].isAlive == False: #will only fire if the alien is not alredy
                    missiles[i].isAlive = True #fires the missile
                    missiles[i].xpos = armada[pick].xpos+5 #draws the missile
                    missiles[i].ypos = armada[pick].ypos
                    break


        #shoot walls
        if bullet.isAlive == True:
        #check for collision between bullet and enemy
            for i in range (len(walls)): #check bullet with entire list of wall positions
                bullet.isAlive = walls[i].collide(bullet.xpos, bullet.ypos) #if we hit, set bullet fo false
                if bullet.isAlive == False:
                    break


    else: #make bullet follow player when not moving up
        bullet.xpos = xpos + 28
        bullet.ypos = ypos - 18

    #Alien collision call
    for i in range (len(armada)):
        armada[i].collide(bullet.xpos, bullet.ypos)

    #Wall collision call
    for i in range (len(walls)):
        walls[i].collide(bullet.xpos, bullet.ypos)

    #updates player's position

    xpos += vx
   
    #Render section--------------------------------------------------------------------------------------------------------

    screen.fill((0,0,0)) # Wipes the screen so it doesn't smear
    #Player
    pygame.draw.rect(screen, (0, 250, 0), (xpos, ypos, 60, 20)) #Draws player
    pygame.draw.rect(screen, (0, 250, 0), (xpos+5, ypos-5, 50, 5)) #Draws player
    pygame.draw.rect(screen, (0, 250, 0), (xpos+25, ypos-15, 10, 10)) #Draws player
    pygame.draw.rect(screen, (0, 250, 0), (xpos+28, ypos-20, 4, 5)) #Draws player

    #Wall
    for i in range (len(walls)):
        walls[i].draw()

    #Allen
    for i in range (len(armada)):
        armada[i].draw()

    #Bullet
    bullet.move(xpos+28, ypos-18)
    bullet.draw()

    #Missile
    for i in range (len(missiles)):
        missile.move(xpos,ypos)
    for i in range (len(missiles)):
        missile.draw()

    pygame.display.flip()#Flips buffer (memory) where sruff has been "drawn" to the actual screen

#Game loop ends
pygame.quit()
