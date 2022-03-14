#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
using namespace std;

double area(int r);
double wrong(int r);
double smallC(int r);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circles");
    sf::CircleShape circle;
    sf::CircleShape small;
    //sf::CircleShape flower;

    int xpos = 0;
    int ypos = 0;
    int size = 50;

    int Sxpos = 25;
    int Sypos = 25;
    int Ssize = 25;

    cout << "Your big circle area is " << area(size) << endl;
    cout << "Your small circle area is " << smallC(Ssize) << endl;
    cout << "Your area according to Edwin Goodwin is " << wrong(size) << endl;

    while (window.isOpen())//GAME LOOP--------------------------------
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear();
        //modify these arguments so each is a different slot of the vectors above
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                circle.setRadius(size);
                circle.setFillColor((sf::Color(250, 0, 250, 75)));
                circle.setPosition(xpos + i * 100, ypos + j * 100);
                window.draw(circle);

            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                small.setRadius(Ssize);
                small.setFillColor((sf::Color(250, 150, 0, 75)));
                small.setPosition(Sxpos + i * 100, Sypos + j * 100);
                window.draw(small);

            }
        }
        //for (int i = 0; i < 3; i++) {
          //  for (int j = 0; j < 8; j++) {
            //    flower.setRadius(size);
              //  flower.setFillColor((sf::Color(0, 100, 200, 50)));
                //flower.setPosition(xpos + sin(i), ypos+cos(j), x)


            //}
        //}
       

        window.display();

    }//end game loop-------------------------------------------------

    return 0;
} //end main


double area(int r) {

    return 3.14159265359 * r * r;

}

double smallC(int r) {
    return 3.14159265359 * r * r;
}

double wrong(int r) {

    return 3.2 * r * r;
}
