#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "GameState.hpp"
#include "Button.hpp"

class MenuState : public State{
public:
	MenuState(StateStack& stack, Context context);

	virtual bool update(sf::Time dt);

	virtual void draw();

	virtual bool handleEvent(const sf::Event &e);

private:
	sf::Text m_text;
	std::shared_ptr<Button> m_btnPlay;
	std::shared_ptr<Button> m_btnExit;
	unsigned m_selectedButton;

};

#endif