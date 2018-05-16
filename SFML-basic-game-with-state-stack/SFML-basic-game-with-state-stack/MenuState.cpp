#include "MenuState.hpp"
#include "ResourceHolder.hpp"

MenuState::MenuState(StateStack& stack, Context context) :
State(stack, context),
m_selectedButton(0)
{
	m_text.setFont(context.fonts->get(Fonts::Main));
	m_text.setString("MenuState: press G to start game");
	m_text.setPosition(10, 10);
	m_text.setFillColor(sf::Color::White);

	m_btnPlay = std::make_shared<Button>(*context.fonts, *context.textures);
	auto windowSize = context.window->getSize();
	m_btnPlay->setPosition(windowSize.x*0.27, windowSize.y*0.5);
	m_btnPlay->setText("Play");
	m_btnPlay->setCallback([this]()
	{
		requestStackPop();
		auto gameState = std::make_shared<GameState>(*_stack, _context);
		requestStackPush(gameState);
	});
	m_btnPlay->select();

	m_btnExit = std::make_shared<Button>(*context.fonts, *context.textures);
	float gap = m_btnPlay->getSize().height + 10;
	m_btnExit->setPosition(m_btnPlay->getPosition().x, m_btnPlay->getPosition().y + gap);
	m_btnExit->setText("Exit");
	m_btnExit->setCallback([this]()
	{
		requestStackPop();
	});
}

bool MenuState::update(sf::Time dt) {
	return true;
}

void MenuState::draw(){
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(*m_btnPlay);
	window.draw(*m_btnExit);
}

bool MenuState::handleEvent(const sf::Event &e){
	if (e.type == sf::Event::KeyReleased){
		if (e.key.code == sf::Keyboard::W || e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::S || e.key.code == sf::Keyboard::Down)
		{
			m_selectedButton = (m_selectedButton != 1) ? 1 : 0;
			if (m_selectedButton == 0){
				m_btnPlay->select();
				m_btnExit->deselect();
			}
			else if (m_selectedButton == 1){
				m_btnPlay->deselect();
				m_btnExit->select();
			}
		}
		else if (e.key.code == sf::Keyboard::Return || e.key.code == sf::Keyboard::Space)
		{
			if (m_selectedButton == 0){
				m_btnPlay->activate();
			}
			else if (m_selectedButton == 1){
				m_btnExit->activate();
			}
		}
	}
	return false;
}
