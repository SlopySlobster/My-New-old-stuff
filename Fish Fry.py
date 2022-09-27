import pygame
import random
#import myFunctions

pygame.init()
pygame.display.set_caption("bruh") 
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

doExit = False

cheems = pygame.image.load ("Fish Fryer 2 electic bogalloo.png")
cheesy = cheems.get_rect(topleft = (0,0))

#myFunctions.PlayIntro()
class fish:
  def __init__(self):
    self.xpos = random.randrange(0, 700)
    self.ypos = random.randrange(100, 450)
    self.xvel = random.randrange(-3, 3)
    self.yvel = random.randrange(-3, 3)
    self.ticker = random.randrange(0, 100)
    self.red = random.randrange(0, 100)
    self.green = random.randrange(100, 250)
    self.blue = random.randrange(50, 200)
    self.isdead = False
    self.onhook = False

  def draw(self):
    
    if self.xvel < 0:
      pygame.draw.ellipse(screen, (self.red, self.green, self.blue), (self.xpos, self.ypos, 25, 15))
      pygame.draw.ellipse(screen, (self.red, self.green, self.blue), (self.xpos + 5, self.ypos + 2, 5, 5))
      pygame.draw.polygon(screen, (self.red,self.green,self.blue), ((self.xpos + 25,self.ypos + 6), (self.xpos + 30,self.ypos + 1), (self.xpos + 30, self.ypos + 9)))
    else:
      pygame.draw.ellipse(screen, (self.red, self.green, self.blue), (self.xpos, self.ypos, 25, 15))
      pygame.draw.ellipse(screen, (self.red, self.green, self.blue), (self.xpos + 15, self.ypos + 2, 5, 5))
      pygame.draw.polygon(screen, (self.red, self.green, self.blue), ((self.xpos,self.ypos + 6), (self.xpos - 5,self.ypos + 1), (self.xpos - 5, self.ypos + 9)))


  def move(self):
    if self.xpos>680:
      self.xpos = 680
      self.xvel *=-1
    if self.xpos < 0:
      self.xpos = 0
      self.xvel *=-1
    if self.ypos < 100:
      self.ypos = 100
      self.yvel *= -1
    if self.ypos > 500:
      self.ypos = 500
      self.yvel *= -1
    self.ticker +=1
    if self.ticker > 100:
      self.xvel = random.randrange(-2, 3)
      self.yvel = random.randrange(-2, 3)
      self.ticker = 0
    self.xpos += self.xvel
    self.ypos += self.yvel
       



#f1 = fish()
#f2 = fish()
#f3 = fish()
lefesh = list()

fisham = 5 # fish ammount

for i in range (fisham):
  lefesh.append(fish())

while not doExit:
    clock.tick(60)

    events = pygame.event.get()

    for event in events:
      if event.type == pygame.quit:
        doExit = True


   # f1.move()
   # f2.move()
   # f3.move()

    for i in range(fisham):
     lefesh[i].move()

    screen.blit(cheems, cheesy)

    #f1.draw()
    #f2.draw()
    #f3.draw()

    for i in range(fisham):
      lefesh[i].draw()


    pygame.display.flip() 


pygame.quit()
