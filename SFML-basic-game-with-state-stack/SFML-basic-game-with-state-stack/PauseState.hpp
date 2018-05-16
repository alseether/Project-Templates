#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include <SFML\Graphics.hpp>
#include "State.hpp"

class PauseState : public State{
public:
	PauseState(StateStack& stack, Context context);

	virtual bool update(sf::Time dt);

	virtual void draw();

	virtual bool handleEvent(const sf::Event &e);

private:
	sf::Text m_text;
};

#endif