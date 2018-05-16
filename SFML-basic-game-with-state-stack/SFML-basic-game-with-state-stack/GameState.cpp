#include "GameState.hpp"
#include "PauseState.hpp"
#include "MenuState.hpp"
#include "ResourceHolder.hpp"

GameState::GameState(StateStack& stack, Context context) :
State(stack,context)
{
	m_count = 0;

	m_text.setFont(context.fonts->get(Fonts::Main));
	m_text.setString("GameState: " + std::to_string(m_count) + " Esc = Pause, M = Menu");
	m_text.setPosition(10, 10);
	m_text.setFillColor(sf::Color::White);

}

bool GameState::update(sf::Time dt) {
	m_count++;
	m_text.setString("GameState: " + std::to_string(m_count) + " Esc = Pause, M = Menu");
	return true;
}


void GameState::draw(){
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(m_text);
}

bool GameState::handleEvent(const sf::Event &e){
	if (e.type == sf::Event::KeyReleased){
		if (e.key.code == sf::Keyboard::Escape){
			auto pauseState = std::make_shared<PauseState>(*_stack, _context);
			requestStackPush(pauseState);
		}
		else if (e.key.code == sf::Keyboard::M){
			requestStateClear();
			auto menuState = std::make_shared<MenuState>(*_stack, _context);
			requestStackPush(menuState);
		}
	}
	return false;
}
