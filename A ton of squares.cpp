import pygame
pygame.init()
pygame.display.set_caption("for loops")
screen = pygame.display.set_mode((800, 800))
pygame.draw.rect(screen, (0, 0, 200), (0, 0, 800, 800))

while True:

    event =pygame.event.wait()
    
    if event.type == pygame.QUIT:
        break
    
    for i in range(20):
        for j in range(32):
            pygame.draw.rect(screen, (100, 0, 100), (i*40, 25*j, 20, 20))
            pygame.draw.rect(screen, (200, 0, 100), (i*40+5, 25*j+5, 10, 10))
    pygame.display.flip()
    
pygame.quit()
