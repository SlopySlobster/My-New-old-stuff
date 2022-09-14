#We did it diffrently than you did and we it's not perfect but it does work.... mostly.


def culump(num, am):
    bru = 0
    while num >= am:
        bru+=1
        num-=am
    return bru


def letta(numb):
    if numb == 1:
        return ("one")
    if numb == 2:
        return ("two")
    if numb == 3:
        return ("three")
    if numb == 4:
        return ("four")
    if numb == 5:
        return ("five")
    if numb == 6:
        return ("six")
    if numb == 7:
        return ("seven")
    if numb == 8:
        return ("eight")
    if numb == 9:
        return ("nine")

    
def funtion(num):
    if num >=1000:
       thou = culump(num, 1000)
       num-=thou*1000
       tlet = letta(thou)
    if num >=100:
        hun = culump(num, 100)
        num-=hun*100
        hlet = letta(hun)
    if num >=10:
        ten = culump(num, 10)
        num-=ten*10
        telet = letta(ten)
    print(tlet,"thousand",hlet,"hundred",telet,"ten and ",num, " dolla")
doExit = False    
    
while doExit == False:
    num = float(input("\n\nPlease enter dollar amount for check, 0 to quit:"))
    if num!=0:
        funtion(num)
    else:
        print("Hank you")
        doExit = True
        
print("see ya suckerrrrrrrrrrrrrrrrrrr!!!!")
