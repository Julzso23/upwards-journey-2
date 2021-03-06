#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	sf::String title;
	bool fullscreen;
	std::vector<sf::VideoMode> supportedResolutions;
	sf::Clock time;
	sf::View camera;

	virtual void load() = 0;
	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void drawUnscaled(sf::RenderWindow* window) = 0;
	virtual void mousePressed(sf::Mouse::Button button, sf::Vector2i position) = 0;
	virtual void mouseReleased(sf::Mouse::Button button, sf::Vector2i position) = 0;
	virtual void mouseMoved(int x, int y) = 0;
	virtual void keyPressed(sf::Keyboard::Key key) = 0;
	virtual void keyReleased(sf::Keyboard::Key key) = 0;
	virtual void joystickConnected(int id) = 0;
	virtual void joystickDisconnected(int id) = 0;
	virtual void windowResized(sf::Vector2u size) = 0;
	virtual void onExit() = 0;
public:
	Game(sf::String title, sf::VideoMode size, bool fullscreen);
	void run();

	void render(const sf::Drawable &drawable);

	void setResolution(sf::Vector2u size);

	void setCursorVisible(bool visible);

	void toggleFullscreen();

	std::vector<sf::VideoMode> getSupportedResolutions();

	sf::Vector2i mousePos();

	void exit();
};

#endif