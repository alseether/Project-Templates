#include "PauseState.hpp"
#include "MenuState.hpp"
#include "ResourceHolder.hpp"


PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
{
	m_text.setFont(context.fonts->get(Fonts::Main));
	m_text.setString("PauseState: press ESC to return, M to menu");
	auto pos = context.window->getSize();
	pos.x *= 0.5;
	pos.y *= 0.5;
	int textSize = m_text.getLocalBounds().width * 0.5;
	m_text.setPosition(pos.x-textSize,pos.y);
	m_text.setFillColor(sf::Color::White);

}

bool PauseState::update(sf::Time dt){
	// By returning false, we prevent States UNDER Pause to update too
	return false;
}

void PauseState::draw(){
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(m_text);
}

bool PauseState::handleEvent(const sf::Event &e){
	if (e.type == sf::Event::KeyReleased){
		if (e.key.code == sf::Keyboard::Escape){
			requestStackPop();
		}
		else if (e.key.code == sf::Keyboard::M){
			requestStateClear();
			auto menuState = std::make_shared<MenuState>(*_stack, _context);
			requestStackPush(menuState);
		}
	}
	return false;
}
