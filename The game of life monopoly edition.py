import pygame
import random

pygame.init()
pygame.display.set_caption("Game Of Life")
screen = pygame.display.set_mode((800, 800))
clock = pygame.time.Clock()

map = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
       [0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
       [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

#game loop-------------------------------------
while True:
    clock.tick(60)
    event = pygame.event.get()
    #input section------------------------------
    for event in pygame.event.get():
        break
    #update section-----------------------------------
    for i in range(16):
        for j in range(16):
            counter = 0
            if i < 15 and map[i+1][j] == 1: #check above
                counter += 1
            if i > 0 and map[i-1][j] == 1: #check bottom
                counter += 1
            if j<15 and map [i][j+1] == 1: #check right
                counter += 1
            if j > 0 and map [i][j-1] == 1: #check left
                counter += 1
            if i<15 and j<15 and map [i+1][j+1] == 1: #check top right corner
                counter += 1
            if i < 15 and j<15 and map [i-1][j+1] == 1: #check bottom right corner
                counter += 1
            if i < 15 and j>= 0 and map[i+1][j-1] ==1: #check top left coprner
                counter += 1
            if i > 0 and j>=0 and map[i-1][j-1] == 1: #check bottom left corner
                counter += 1

            #kill, live, or grow cells
            if map[i][j] ==1 and counter <= 1:
                map[i][j] = 0
                print("I died because I am lonely")

            if map[i][j] ==1 and counter == 2 or counter == 3:
                map[i][j] = 1
                print("I live")

            if map[i][j] ==1 and counter >= 4:
                map[i][j] = 0
                print("I died because I am too popular")

            if map[i][j] ==0 and counter == 3:
                map[i][j] = 1
                print("I came back to life!")
            



    pygame.time.wait(200)


    #render section ---------------------------------
    screen.fill((0,0,0))
    #draw section------------------------------------
    for i in range (16):
        for j in range (16):
            if map[i][j]==0:
                pygame.draw.rect(screen, (0,0,0), (j*50, i*50, 50, 50))
                pygame.draw.rect(screen, (255,255,255), (j*50, i*50, 50, 50), 1)
            if map[i][j]==1:
                pygame.draw.rect(screen, (0,200,200), (j*50, i*50, 50, 50))
    pygame.display.flip()




pygame.quit()
