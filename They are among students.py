class Student:
    def __init__(self, name, ID, color, next = None):
        self.name = name
        self.ID = ID
        self.color = color
        self.next = next
        
class LinkedList:
    def __init__(self):
        self.head = None
        
    def insert(self, name, ID, color):
        newStudent = Student(name, ID, color) #instantiate a new student node
        if self.head: #check if a head exists
            current = self.head #create a temporary pointer to the head node
            #while there's another node in the line, "walk down the line until the end
            while current.next:
                current = current.next
            current.next = newStudent #add the new student to the end
        else:
            self.head = newStudent #if there was no head stdent, insert at front of empty line
    def printList(self):
        current = self.head
        while current:
            print("Student name:", current.name, ", ID:", current.ID, ", Favorite Color:", current.color)
            current = current.next
    def amoung(self, name):
        current = self.head
        task = 1
        while current:
            if current.name != name:
                print("slot ", task, "is not", name)
                current = current.next
                task += 1
            elif current.name == name:
                print("It's true!! slot", task, "is", name)
                break

    def size(self):
        current = self.head
        size = 0
        while current:
            current = current.next
            size += 1
        print("There are:", size, "Students")
        
#instantiate a list
StudentLine = LinkedList()
StudentLine.insert("Lily", 456987, "Red")
StudentLine.insert("Jevin", 123987, "Blue")
StudentLine.insert("Bash", 4, "Orange")
StudentLine.insert("Jon", 1329, "Pink")
StudentLine.insert("Milk", 141437, "White")
StudentLine.insert("Chocolate", 9267701, "Brown")
StudentLine.printList()
StudentLine.size()
StudentLine.amoung("Jon")
