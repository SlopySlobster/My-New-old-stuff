import pygame


pygame.init()#set up pygame
pygame.display.set_caption("Space Invaders!")
screen = pygame.display.set_mode((800, 800))
clock = pygame.time.Clock() #set up clock
gameover = False #variable to run our game loop


#player variables
xpos = 400
ypos = 750
moveLeft = False
moveRight = False


while not gameover:
    clock.tick(60)

    # Input Section-----------------------------

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameover = True #quits the game if the x on the top righ corner is pressed

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                moveLeft = True

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                moveLeft = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                moveRight = True

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT:
                moveRight = False


    # Physics section---------------------------

    # checks variables from the input section

    # Left movement
    if moveLeft == True:
        vx =- 3

    if moveRight == True:
        vx =+ 3

    else:
        vx = 0

    #updates player's position

    xpos += vx
    
    #Render section-----------------------------

    screen.fill((0,0,0)) # Wipes the screen so it doesn't smear

    pygame.draw.rect(screen, (0, 200, 0), (xpos, ypos, 60, 20)) #Draws player
    pygame.draw.rect(screen, (0, 200, 0), (xpos+5, ypos-5, 50, 5)) #Draws player
    pygame.draw.rect(screen, (0, 200, 0), (xpos+25, ypos-15, 10, 10)) #Draws player
    pygame.draw.rect(screen, (0, 200, 0), (xpos+28, ypos-20, 4, 5)) #Draws player

    pygame.display.flip()#Flips buffer (memory) where sruff has been "drawn" to the actual screen

#Game loop ends
pygame.quit()
