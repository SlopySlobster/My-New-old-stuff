import pygame
pygame.init()
print("Enter your age")
choice = int(input(""))

if choice < 13:
    print("You are too young for this game")
elif choice < 18:
    print("Youre going to need to ask your parent/gaurdien for permition")
elif choice >= 18:
    print ("We welcome you to the game")
else:
    print ("That is not an opption")

