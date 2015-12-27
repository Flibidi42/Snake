#include <SFML/Graphics.hpp>
#include <deque>

class snake{

	std::deque<sf::RectangleShape> file;
	
public:
	
	snake(int x, int y);
	void affichage(sf::RenderWindow* w);

};
