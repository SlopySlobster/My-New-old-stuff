import random

numbers = []
for i in range(12):
    numbers.append( random.randrange(1,11))

numbers2 = []
for i in range(12):
    numbers2.append(numbers[11-i])

print("original list: ", numbers)
print("Reversed list: ", numbers2)

numbers.sort()

largest = numbers[-1]
smallest = numbers[0]

print("The largest number is:", largest, "The smallest number is:", smallest)

for i in range(10):
    if numbers[i]+1 == numbers[i+1]:
        if numbers[i+1]+1 == numbers[i+2]:
            print("This list contains", numbers[i], numbers[i+1], numbers[i+2])
