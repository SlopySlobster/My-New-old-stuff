//dumb java stuff you have to set up first
import java.util.Scanner;
import java.util.Random;

class Main {
  public static void main(String[] args) {

    Scanner Doggo = new Scanner(System.in); // create this thing to get user input
    
    System.out.println("Java Text Based Game!"); // prints to screen

    // game variables
    Random rand = new Random();
    int room = 1;
    int money = rand.nextInt(5);

    String input = "glurbaburbal!"; // dummy value for game loop
    String[] inventory = { " ", " ", " ", " " }; // use this to hold player items

    while (input != "quit") { // OMG GAME LOOP-----------------------------------------

      // print inventory
      System.out.println("Your inventory:");
      for (int i = 0; i <= 3; i++)
        System.out.println(inventory[i]);

      switch (room) {
        case 1:
          System.out.println("You're in room 1, you can go East");
          input = Doggo.nextLine();
          System.out.println("You got: " +money);
          if (input.equals("East"))
            room = 2;
          break;
        case 2:
          System.out.println("You're in room 2, you can go West or South");
          input = Doggo.nextLine();
          if (input.equals("South"))
            room = 3;
          else if (input.equals("West"))
            room = 1;
          break;
        case 3:
          System.out.println("You're in room 3, you can go North or South.");
          // check if they already have the gun, if not tell them they got it
          if (!inventory[0].equals("marshmallow gun")) {
            System.out.println("OMG you got the marshmallow gun!");
            inventory[0] = "marshmallow gun";
            break;
          }

          input = Doggo.nextLine();
          if (input.equals("North"))
            room = 2;
          else if (input.equals("South"))
            room = 4;
          break;
        case 4:
          System.out.println("You're in room 4, you can go North, East or West");
          input = Doggo.nextLine();
          if (input.equals("North"))
            room = 3;
          else if (input.equals("East"))
            room = 5;
          else if (input.equals("West"))
            room = 6;
          break;
        case 5:
          System.out.println("You're in room 5, you can go West");
          if (!inventory[1].equals("Ikea key")) {
            System.out.println("OMG you found an ikea and got a key");
            inventory[1] = "Ikea key";
            break;
          }
          input = Doggo.nextLine();
          if (input.equals("West"))
            room = 4;

        case 6:
          System.out.println("You're in room 6, you can go  East or South");
          input = Doggo.nextLine();
          if (input.equals("East"))
            room = 4;
          else if (input.equals("South"))
            room = 7;
          break;

        case 7:
          System.out.println("You're in room 7, you can go  North or West");
          input = Doggo.nextLine();
          if (input.equals("North"))
            room = 6;
          else if (input.equals("West"))
            room = 8;
          break;

        case 8:
          System.out.println("You're in room 8 and you need a key to get past, you can go East or West");
          input = Doggo.nextLine();
          if (input.equals("East"))
            room = 7;
          if (!inventory[1].equals("Ikea key")) {
            System.out.println("DOUY HAV KEE");
          }

          if (inventory[1].equals("Ikea key")) {
            if (input.equals("West"))
              System.out.println("YOU GOT YOUR IKEA HOUSE!!!!!!!!!");
            input = "quit";
            break;

          }
          break;

      }// end bracket for switch
    } // end bracket for OMG GAME
      // LOOP----------------------------------------------------
  }// end bracket for public static void main
}// end bracket for class main
