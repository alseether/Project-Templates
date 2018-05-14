#include <SFML/Graphics.hpp>


int main() {
	// Create window object
	sf::RenderWindow window(sf::VideoMode(600, 600), "Title");


	while (window.isOpen()) {
		// Create events object
		sf::Event event;
		// Loop through events
		while (window.pollEvent(event)) {
			// Close window
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		// Clear window
		window.clear(sf::Color::Black);

		// Draw items
		// window.draw(item);

		// Display window contents
		window.display();
	}

	return 0;
}