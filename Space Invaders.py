import pygame 

pygame.init() #set up pygame
pygame.display.set_caption("Space Invaders!")
screen = pygame.display.set_mode((800, 800))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop

while not gameover:
    clock.tick(60)

    # Render section---------------------------

    screen.fill((0,0,0)) # wipe screen so it doesn't 

    pygame.draw.rect(screen, (0, 200, 0), (400, 750, 60, 20)) #draw player
    pygame.draw.rect(screen, (0, 200, 0), (405, 745, 50, 5)) #draw player
    pygame.draw.rect(screen, (0, 200, 0), (425, 735, 10, 10)) #draw player
    pygame.draw.rect(screen, (0, 200, 0), (428, 730, 4, 5)) #draw player

    pygame.display.flip()#flips buffer (memory) where stuff has been "drawn" to the actual screen

# game loop ends
pygame.quit()
