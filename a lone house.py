#a silly set of shapes
#by Dr. Mo, Aug 2020

#pygame is a bunch of pre-written python code that makes coding games easier
import pygame #handles graphics, sound, game timings, keyboard input, etc
pygame.init()

#creates game screen and caption
screen = pygame.display.set_mode((500, 500))
pygame.display.set_caption("Silly Shapes")

while True: #sortof a game loop
    
  #a few example shapes
  pygame.draw.ellipse(screen, (255, 255, 0), (400, 100, 40, 40))
   
  pygame.draw.rect(screen, (150, 150, 150), (100, 400, 300, 300))
  
  pygame.draw.polygon(screen, (100, 0, 0), ((100, 400), (250, 300), (400, 400)))
  
  pygame.draw.rect(screen, (150, 150, 255), (150, 420, 40, 60))

  pygame.display.flip() #update graphics 

pygame.quit()
