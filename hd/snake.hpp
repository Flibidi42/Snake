#include <SFML/Graphics.hpp>
#include <deque>

enum Retour {OK, FIN, FOOD};
enum Dir {LEFT, RIGHT, UP, DOWN};

class Snake{

	std::deque<sf::RectangleShape> file;
	
public:
	
	Snake(int x, int y);
	void affichage(sf::RenderWindow* w);
	Retour moove(Dir direction, int fd_x, int fd_y);
	bool check_food(int x, int y);
};
