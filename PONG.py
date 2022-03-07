import pygame
pygame.init()


screen = pygame.display.set_mode((700,500))
pygame.display.set_caption("PONG")

bx = 350
by = 250
bVx = 5
bVy = 5
p1Score = 0
p2Score = 0

#game loop
doExit = False

#The clock
clock = pygame.time.Clock()


#paddle position
p1x = 20
p1y = 200
p2x = 660
p2y = 200


while not doExit: #GAME LOOP
    
    # event queue
    clock.tick(60)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True
            
    #game logic
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        p1y-=5
    if keys[pygame.K_s]:
        p1y+=5
    if keys[pygame.K_i]:
        p2y-=5
    if keys[pygame.K_k]:
        p2y+=5
    
    #ball movement
    bx += bVx
    by += bVy
    
    #reflect ball off side walls of screen
   
    if by < 0 or by +20 > 500:
        bVy *= -1
            
    #ball-paddle reflection
    if bx < p1x + 20 and by + 20 > p1y and by < p1y + 100:
        bVx *= -1
    if bx + 20 > p2x and by + 20 > p2y and by < p2y + 100:
        bVx *= -1
    
    if bx > 680:
        bVx *= -1
        p1Score += 1
    
    
    if bx < 0:
        bVx *= -1
        p2Score += 1
    
    
    #render section
    screen.fill((0,0,0))
    pygame.draw.rect(screen, (255, 255, 255), (p1x, p1y, 20, 100), 1)
    pygame.draw.rect(screen, (255, 255, 255), (p2x, p2y, 20, 100), 1)
    pygame.draw.rect(screen, (255, 255, 255), (bx, by, 20, 20), 1)
    
    font = pygame.font.Font(None, 74)
    text = font.render(str(p1Score), 1, (255, 255, 255))
    screen.blit(text, (250,10))
    text = font.render(str(p2Score), 1, (255, 255, 255))
    screen.blit(text, (420,10))
    
    # line in the middle
    pygame.draw.line(screen, (255, 255, 255), [349, 0], [349, 500], 5)
   
    
    
    #updates the screen
    pygame.display.flip()
            
            
            
            


#END GAME LOOP
            
pygame.quit()
