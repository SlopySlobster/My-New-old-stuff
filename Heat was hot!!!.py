class Kettle:
    def __init__(self):
        self.Water = 0
        self.IsHot = False
        self.Power = False
    
    
    def PrintKettle(self):
        print("there are", self.Water, "letter of water in the kettle.")
        if self.IsHot == True:
            print("The water is hot")
        elif self.IsHot == False:
            print("The water is cold")
        if self.Power == True:
            print("The power is on")
        elif self.Power == False:
            print("The power is off")
        
        
    def Fill(self):
        print("You fill the Kettle as much a you can")
        self.Water = 20
        
             
    def Pour(self):
        if self.Water > 0:
            if self.IsHot == True:
                print("you pour some hot water")
                self.Water -= 5
                if self.Water == 0:
                    self.IsHot = False
                    self.Power = False
            elif self.IsHot == False:
                print("you pour some cold water")
                self.Water -= 5
        else:
            print("There is no water dumdum")

                    
    def OnOff(self):
        if self.Power == True:
            self.Power = False
        elif self.Power == False:
            self.Power = True
            self.IsHot = True
            
            
      
a1 = Kettle()

a1.PrintKettle()

a1.Fill()

a1.PrintKettle()

a1.Pour()

a1.PrintKettle()

a1.OnOff()

a1.PrintKettle()

a1.Pour()

a1.Pour()

a1.Pour()

a1.PrintKettle()

a1.Fill()

a1.PrintKettle()
