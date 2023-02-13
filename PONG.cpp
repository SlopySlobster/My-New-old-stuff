// Demonstrate primitve drawing in SFML
#include<iostream>
using namespace std;


#include "SFML/Graphics.hpp"

int main() {

    //game set up (you'll need these two lines in every game)
    sf::RenderWindow renderWindow(sf::VideoMode(500, 500), "Pong Paddle"); //set up screen
    sf::Event event; //set up event queue

    //paddle1 set up
    sf::RectangleShape paddle1(sf::Vector2f(10.0f, 100.0f));
    paddle1.setFillColor(sf::Color::Blue); //other colors: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
    paddle1.setPosition(20.0f, 250.0f); //set position: this is where the top left corner will be


    //paddle2 set up
    sf::RectangleShape paddle2(sf::Vector2f(10.0f, 100.0f));
    paddle2.setFillColor(sf::Color::Blue); //other colors: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
    paddle2.setPosition(470.0f, 250.0f); //set position: this is where the top left corner will be

    //ball set up
    float ballX = 250;
    float ballY = 250;
    float xVel = .1;
    float yVel = .1;
    sf::CircleShape ball(10); //sets radius of circle
    ball.setFillColor(sf::Color(200, 50, 50));//notice you can do numbers here instead of color names
    ball.setPosition(ballX, ballY); //change so it's centered!


    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (renderWindow.isOpen()) {//keep window open until user shuts it down
        while (renderWindow.pollEvent(event)) { //look for events

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();

            //KEYBOARD INPUT (just one key to start
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //checks if "W" is pressed
                paddle1.move(0, -5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving up" << endl; //for Mo's testing, you can take this out
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //checks if "S" is pressed
                paddle1.move(0, 5); //move the rectangle 5 pixels DOWN on the y axis
                cout << "rectangle moving down" << endl; //for Mo's testing, you can take this out
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) { //checks if "W" is pressed
                paddle2.move(0, -5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving up" << endl; //for Mo's testing, you can take this out
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { //checks if "S" is pressed
                paddle2.move(0, 5); //move the rectangle 5 pixels DOWN on the y axis
                cout << "rectangle moving down" << endl; //for Mo's testing, you can take this out
            }
        }

        //physics section

        //paddle collision
        if (ballX - 30 < paddle1.getPosition().x && ballY > paddle1.getPosition().y && ballY < paddle1.getPosition().y + 100) {
            cout << "paddle1 collision!" << endl;
            //eventually add sound effect here
            xVel *= -1;

        }

        if (ballX + 30 > paddle2.getPosition().x && ballY > paddle2.getPosition().y && ballY < paddle2.getPosition().y + 100) {
            cout << "paddle2 collision!" << endl;
            //sound effect
            xVel *= -1;
        }
        
        


        //reflects off left and right walls
        if (ballX < 0 || ballX > 500) {
            xVel *= -1;
        }
        if (ballY < 0 || ballY>500) {
            yVel *= -1;
        }

        //add speed to position
        ballX += xVel;
        ballY += yVel;
        //update ball
        ball.setPosition(ballX, ballY);

        //render section-----------------------------------------
        renderWindow.clear(); //wipes screen, without this things smear
        renderWindow.draw(paddle1); //you gotta drew each object
        renderWindow.draw(paddle2);
        renderWindow.draw(ball);
        renderWindow.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end game
