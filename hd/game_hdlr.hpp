#include "..hd/snake.hpp"


class Game_hdlr{

	Snake *m_s;
	sf::RenderWindow *m_w;
	Dir dir_courante;
	bool ajout;
	
	public:
	
	Game_hdlr(Snake* s, sf::RenderWindow *w);
	void iteration();

};
