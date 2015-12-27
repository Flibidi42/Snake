#include <SFML/Graphics.hpp>
#include <deque>

enum Dir {LEFT, RIGHT, UP, DOWN};

class Snake{

	std::deque<sf::RectangleShape> file;
	
public:
	
	Snake(int x, int y);
	void affichage(sf::RenderWindow* w);
	bool moove(Dir direction, bool ajout);
};
