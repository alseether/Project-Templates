#ifndef GAME_HPP
#define GAME_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "StateStack.hpp"

#include "MenuState.hpp"


const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

const std::string MEDIA_FOLDER = "Media/";
const std::string FONTS_FOLDER = MEDIA_FOLDER + "Fonts/";
const std::string MUSIC_FOLDER = MEDIA_FOLDER + "Sounds/";
const std::string SOUNDS_FOLDER = MEDIA_FOLDER + "Sounds/";
const std::string TEXTURES_FOLDER = MEDIA_FOLDER + "Textures/";

class Game {
public:
	Game() :
		_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game"),
		_stateStack(State::Context(_window, _textures, _fonts, _musics, _sounds))
	{
		_fonts.load(Fonts::Main, FONTS_FOLDER + "Roboto-Regular.ttf");

		// EXAMPLES
		//_musics.load(Musics::Game, MUSIC_FOLDER + "main.ogg");
		//_musics.get(Musics::Game).setLoop(true);

		//_sounds.load(Sounds::Key, SOUNDS_FOLDER + "key.wav");
		

		_textures.load(Textures::GUI, TEXTURES_FOLDER + "GUI.png");
		
		auto menuState = std::make_shared<MenuState>(_stateStack, State::Context(_window, _textures, _fonts, _musics, _sounds));
		_stateStack.pushState(menuState);
	}

	void run(){
		sf::Clock clk;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		while (_window.isOpen())
		{

			sf::Time dt = clk.restart();
			timeSinceLastUpdate += dt;
			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;

				processInput();
				update(TimePerFrame);

				// Check inside this loop, because stack might be empty before update() call
				if (_stateStack.isEmpty())
					_window.close();
			}
			render();
		}
	}
private:
	void update(sf::Time dt){
		_stateStack.update(dt);
	}

	void processInput(){
		sf::Event event;
		while (_window.pollEvent(event))
		{
			_stateStack.handleEvent(event);

			if (event.type == sf::Event::Closed)
				_window.close();
		}
	}

	void render(){
		_window.clear(sf::Color::Black);
		_stateStack.draw();
		_window.display();
	}

	sf::RenderWindow _window;
	TextureHolder _textures;
	FontHolder _fonts;
	MusicHolder _musics;
	SoundHolder _sounds;
	StateStack _stateStack;
};

#endif