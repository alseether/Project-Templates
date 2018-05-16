#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "GameState.hpp"

class MenuState : public State{
public:
	MenuState(StateStack& stack, Context context);

	virtual bool update(sf::Time dt);

	virtual void draw();

	virtual bool handleEvent(const sf::Event &e);

private:
	sf::Text m_text;
};

#endif