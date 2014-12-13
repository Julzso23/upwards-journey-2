#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>

class Game {
	private:
		sf::RenderWindow window;
		sf::Clock time;
		sf::View camera;
	public:
		Game(sf::String title, sf::VideoMode size, bool fullscreen);
		void run();

		void render(const sf::Drawable &drawable);

		void drawRect(float x, float y, float w, float h);
		void drawRect(sf::Vector2f pos, sf::Vector2f size);
		void drawRect(float x, float y, sf::Vector2f size);
		void drawRect(sf::Vector2f pos, float w, float h);

		void setResolution(sf::Vector2u size);

		virtual void load() = 0;
		virtual void update(float dt) = 0;
		virtual void draw() = 0;
};

#endif