#sometimes it dosen't run
import random

def direction(x,y):
    num = random.randrange(0,3)
    if num == 0:#up
        y -= 1
        return x,y
    if num == 1:#down
        y += 1
        return x,y
    if num == 2:#left
        x -= 1
        return x,y
    if num == 3:#right
        x += 1
        return x,y
    
    


mapGrid = [[0 for i in range(10)] for j in range(10)] #grid to hold starting point

xpos = random.randrange(0,9)
ypos = random.randrange(0,9)
ticker = 0

print("starting at: ", xpos, ", ",ypos)

mapGrid[xpos][ypos] = 1

while ticker != 9:
    xpos,ypos = direction(xpos,ypos)
    if mapGrid[xpos][ypos] == 0 and xpos != 10 and xpos != -1 and ypos != -1 and ypos != 10:
        mapGrid[xpos][ypos] = random.randrange(2,5)
        ticker+=1
    else:
        if ypos > 9:
            ypos -=1
        if ypos < 0:
            ypos +=1
        if xpos > 9:
            xpos -=1
        if xpos < 0:
            xpos +=1

    

for row in mapGrid:
    print(row)
