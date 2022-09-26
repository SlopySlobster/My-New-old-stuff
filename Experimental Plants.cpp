#include <SFML/Graphics.hpp>

class tree {
private:
	int xpos;
	int ypos;
	int size;
	sf::CircleShape circle;
	sf::RectangleShape rect;
public:
	tree(int x, int y, int s); //constructor
	void draw(sf::RenderWindow& window);
};

class bush {
private:
	int xpos;
	int ypos;
	int size;
	sf::CircleShape circle;
public:
	bush(int x, int y, int s);
	void draw(sf::RenderWindow& window);
};


tree::tree(int x, int y, int s) {
	xpos = x;
	ypos = y;
	size = s;
}

bush::bush(int x, int y, int s) {
	xpos = x;
	ypos = y;
	size = s;
}

void tree::draw(sf::RenderWindow& window) {

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos, ypos-50);
	window.draw(circle);

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos-30, ypos-70);
	window.draw(circle);

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos-70, ypos-50);
	window.draw(circle);

	rect.setPosition(xpos, ypos);
	rect.setFillColor(sf::Color(100, 80, 0));
	rect.setSize(sf::Vector2f(20, 100));
	window.draw(rect);
}

void bush::draw(sf::RenderWindow& window) {

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos, ypos);
	window.draw(circle);

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos-20, ypos-10);
	window.draw(circle);

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos+20, ypos - 15);
	window.draw(circle);

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos + 20, ypos - 30);
	window.draw(circle);

	circle.setRadius(size);
	circle.setFillColor((sf::Color(0, 100, 0)));
	circle.setPosition(xpos - 20, ypos - 35);
	window.draw(circle);
}

tree t1(100, 100, 50);
tree t2(300, 300, 50);
tree t3(500, 300, 50);
tree t4(400, 400, 30);
bush b1(100, 500, 40);
bush b2(300, 500, 30);


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Trees"); //set up screen
	sf::CircleShape circle;
	sf::RectangleShape rect;



	while (window.isOpen())//GAME LOOP--------------------------------
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		//render section-------------------------------
		window.clear();
		t1.draw(window);
		t2.draw(window);
		t3.draw(window);
		t4.draw(window);
		b1.draw(window);
		b2.draw(window);


		window.display(); //flip the buffer

	}//end game loop-------------------------------------------------

	return 0;
} //end main
