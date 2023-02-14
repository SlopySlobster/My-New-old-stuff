#pygame hearts
#gets you started to draw a valentine's day card

import pygame #gaming module (aka library) 
import random

pygame.init() #initializes Pygame
pygame.display.set_caption("Valentine's day card") #sets the window title
screen = pygame.display.set_mode((800, 800)) #creates game screen

font = pygame.font.Font('freesansbold.ttf', 32) #load font
img = pygame.image.load("dogo.png") #make sure this is saved to the same folder as your code
img2 = pygame.image.load("evil.jfif")

screen.fill((0,0,0))
clock = pygame.time.Clock()

doExit = False #Game Loop

#first Heart

class heart:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.blue = random.randrange(0,250)
        self.green = random.randrange(0,250)
        self.red = random.randrange(0,250)

    def draw(self):
        pygame.draw.circle(screen, (self.red,self.green,self.blue), (self.xpos, self.ypos), 20) #top left circle
        pygame.draw.circle(screen, (self.red,self.green,self.blue), (self.xpos+40, self.ypos), 20) #top right circle
        pygame.draw.polygon(screen, (self.red,self.green,self.blue), ((self.xpos-20, self.ypos+5),(self.xpos+59, self.ypos+5), (self.xpos+20, self.ypos+50))) #triangle to form base

    def move(self):
        self.ypos+=3

    def reset(self):
        if self.ypos-50 > 800:
            self.ypos = -50
            self.xpos = random.randrange (0,700)



#text
text1 = font.render('I Love You!', True, (250, 100, 100)) #numbers give color
text2 = font.render('Happy Valentines Day', True, (250, 0, 0), (200,150,150)) #this one includes background color

h1 = heart(200, 200)
h2 = heart(400, 200)
h3 = heart(400, 500)

herts = []
for i in range(50):
    herts.append(heart(random.randrange(0, 800),random.randrange(0, 800)))


#Game loop ---------------------------------
while not doExit:

    clock.tick(60)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True



    for i in range(50):
        herts[i].move()

   

    for i in range(50):
        herts[i].reset()



    screen.fill((0,0,0))

    screen.blit(text1, (200, 100)) #numbers give position
    screen.blit(text2, (400, 300))

    #image
    screen.blit(img, (0, 400))#draw pic
    screen.blit(img2, (400, 500))


    for i in range(50):
        herts[i].draw()

    pygame.display.flip() #this flips all those shapes onto the game screen (needed for every game)
