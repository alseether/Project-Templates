#include "MenuState.hpp"
#include "ResourceHolder.hpp"

MenuState::MenuState(StateStack& stack, Context context):
State(stack,context)
{
	m_text.setFont(context.fonts->get(Fonts::Main));
	m_text.setString("MenuState: press G to start game");
	m_text.setPosition(10, 10);
	m_text.setFillColor(sf::Color::White);

}

bool MenuState::update(sf::Time dt) {
	return true;
}

void MenuState::draw(){
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(m_text);
}

bool MenuState::handleEvent(const sf::Event &e){
	if (e.type == sf::Event::KeyReleased){
		if (e.key.code == sf::Keyboard::G){
			requestStackPop();
			auto gameState = std::make_shared<GameState>(*_stack, _context);
			requestStackPush(gameState);
		}
	}
	return false;
}
