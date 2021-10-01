import pygame
import random
pygame.init()
pygame.display.set_caption("A bad Corn dog")
screen = pygame.display.set_mode((800, 800))

while True:
    for i in range(95):
        num = random.randrange(3, 800)
        hig = random.randrange(3, 800)
        col = random.randrange(0, 255)
        cil = random.randrange(0, 255)
        cel = random.randrange(0, 255)
        pygame.draw.ellipse(screen, (col,cil,cel), (num,hig,50,50))
        
        pygame.display.flip()
        
pygame.quit()
