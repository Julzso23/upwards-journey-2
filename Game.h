#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	sf::Clock time;
	sf::View camera;
public:
	Game(sf::String title, sf::VideoMode size, bool fullscreen);
	void run();

	void render(const sf::Drawable &drawable);

	void setResolution(sf::Vector2u size);

	void setCursorVisible(bool visible);

	sf::Vector2i mousePos();

	void exit();

	virtual void load() = 0;
	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void mousePressed(sf::Mouse::Button button, sf::Vector2i position) = 0;
	virtual void mouseReleased(sf::Mouse::Button button, sf::Vector2i position) = 0;
	virtual void keyPressed(sf::Keyboard::Key key) = 0;
	virtual void keyReleased(sf::Keyboard::Key key) = 0;
};

#endif