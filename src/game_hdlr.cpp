#include "game_hdlr.hpp"

Game_hdlr::Game_hdlr(Snake *s, sf::RenderWindow* w){
	m_s = s;
	m_w = w;
	s.affichage(&w);
}


