import random

class chicken:
    def __init__(self, name):
        self.name = name
        self.hunger = 0

    def update(self, hunger):
        self.hunger += 5
        if self.hunger < 30:
           i = random.randrange(1, 3)
           if i == 1:
               print("bok BOK!")
               return 1
           else:
               return 0
    def feed(self, guh,):
        self.hunger -= guh
        print("peck peck!")
        print("Chicken:", self.name,"hunger's ", self.hunger)

    def pet(self):
        print("bawk bawk")
        
    def printinfo(self, name):
        print(self.name)
        print("Chicken:", self.name,"hunger's ", self.hunger)

numEggs = 0

c1 = chicken("Kevin")
c2 = chicken("Alex")
c3 = chicken("Alan")


gameloop = True
while gameloop == True:
    numEggs += c1.update("Kevin")
    numEggs += c2.update("Alex")
    numEggs += c3.update("Alan")
    print(numEggs)
    choice = input("What would you like to do with your chicken?: Pet, Feed, Printinfo: ")
    if choice == "Pet" or choice == 'pet':
        c1.pet("Kevin")
        c2.pet("Alex")
        c3.pet("Alan")
    elif choice == "Feed":
        c1.feed(5)
        c2.feed(10)
        c3.feed(6)
    elif choice == "Printinfo":
        c1.printinfo("Kevin")
        c2.printinfo("Alex")
        c3.printinfo("Alan")
     
