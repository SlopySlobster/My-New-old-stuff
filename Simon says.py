import pygame
import random
import winsound
pygame.init()#initializes Pygame
pygame.display.set_caption("Simon!")#sets the window title
screen = pygame.display.set_mode((800, 800))#creates game screen

#game variables
xpos = 0
ypos = 0
mousePos = (xpos, ypos) #variable mousePos stores TWO numbers in a TUPLE
turn = False
pattern = [] #this holds the random pattern
pi = 3.1415

#draw everything first so things don't appear one at a time
pygame.draw.arc(screen, (155, 0,0), (200,200,400,400), pi/2, pi, 100)
pygame.draw.arc(screen, (0, 0, 155), (200, 200, 400, 400), pi, (3*pi/2), 100)
pygame.draw.arc(screen, (155, 155, 0), (200, 200, 400, 400), (3*pi/2), 0, 100)
pygame.draw.arc(screen, (0, 155, 0), (200, 200, 400, 400), 0, (pi/2), 100)
#more colors go here!   
pygame.display.flip()

#gameloop###################################################
while True:
    
    event = pygame.event.wait()#event queue 

    #input section----------------------------------------------
    if event.type == pygame.QUIT: #close game window
        break

    if event.type == pygame.MOUSEBUTTONDOWN:
        turn = True

    if event.type == pygame.MOUSEBUTTONUP:
        turn = False

    if event.type == pygame.MOUSEMOTION:
        mousePos = event.pos
    
    #update section---------------------------------------------
    if turn == True:
        pattern.append(random.randrange(0, 2)) #push a new value into the pattern list
        
        #brighten colors and play beep for each number in the pattern
        for i in range(len(pattern)): 
            if pattern[i]==0: #RED
                pygame.draw.arc(screen, (255, 0,0), (200,200,400,400), pi/2, pi, 100)
                pygame.display.flip()
                winsound.Beep(440, 500)
                
            elif pattern[i]==1:#BLUE
                pygame.draw.arc(screen, (0, 0, 255), (200, 200, 400, 400), pi, (3*pi/2), 100)
                pygame.display.flip()
                winsound.Beep(640, 500)

            elif pattern[i]==1:#YELLOW
                pygame.draw.arc(screen, (255, 255, 0), (200, 200, 400, 400), (3*pi/2), 0, 100)
                pygame.display.flip()
                winsound.Beep(840, 500)
                
            #redraw board after every beep
            pygame.draw.arc(screen, (155, 0,0), (200,200,400,400), pi/2, pi, 100)
            pygame.draw.arc(screen, (0, 0, 155), (200, 200, 400, 400), pi, (3*pi/2), 100)
            pygame.draw.arc(screen, (155, 155, 0), (200, 200, 400, 400), (3*pi/2), 0, 100)
            pygame.display.flip()
            pygame.time.wait(200) #slows the game down a bit
        
    turn = False       
    #render section---------------------------------------------
    
    #game board
    pygame.draw.arc(screen, (155, 0,0), (200,200,400,400), pi/2, pi, 100)
    pygame.draw.arc(screen, (0, 0, 155), (200, 200, 400, 400), pi, (3*pi/2), 100)
    pygame.draw.arc(screen, (155, 155, 0), (200, 200, 400, 400), (3*pi/2), 0, 100)
    #more colors go here!
   
    pygame.display.flip()
    

#end game loop##############################################

pygame.quit()
