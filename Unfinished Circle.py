import pygame
import math
pygame.init()



def anbfkjdsanlkfl(x1,x2,y1,y2,radius):
    if (math.sqrt(x2-x1)^2 + (y2 - y1)^2) < radius:
        return True
    else:
        return False
    
a = int(input("Enter your first x:"))
b = int(input("Enter your second x:"))
c = int(input("Enter your first y:"))
d = int(input("Enter your second y:"))
e = int(input("Enter your radius:"))


anbfkjdsanlkfl(a, b, c, d, e)

scree = pygame.display.set_mode((800,800))
pygame.display.set_caption("The Circle")

doExit = False

clock = pygame.time.Clock()

screen.fill((0,0,0))
pygame.draw.circle(screen, (255, 255, 255), (x1, y1, x2, y2), 1)
pygame.display.flip()
            

#END GAME LOOP
            
pygame.quit()
    
