#include "Game.h"

Game::Game(sf::String title, sf::VideoMode size, bool fullscreen)
{
	if (fullscreen)
		window.create(sf::VideoMode(size), title, sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
	else
		window.create(sf::VideoMode(size), title, sf::Style::Close | sf::Style::Titlebar);
}

void Game::run()
{
	camera.reset(sf::FloatRect(0, 0, 1920, 1080));
	sf::RectangleShape testRect(sf::Vector2f(1920, 1080));
	testRect.setFillColor(sf::Color(255, 255, 2552, 255));

	load();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed: window.close();
			}
		}

		sf::Time deltaTime = time.restart();
		update(deltaTime.asSeconds());

		float xScale = window.getSize().x / 1920.f;
		float yScale = window.getSize().y / 1080.f;
		if (xScale <= yScale)
		{
			camera.setViewport(sf::FloatRect(0, 0, 1, window.getSize().x / window.getSize().y));
		}
		else
		{
			camera.setViewport(sf::FloatRect(0, 0, window.getSize().y / window.getSize().x, 1));
		}

		window.clear();
		window.setView(camera);
		window.draw(testRect);
		draw();
		window.setView(window.getDefaultView());
		window.display();
	}
}

void Game::render(const sf::Drawable &drawable)
{
	window.draw(drawable);
}

void Game::drawRect(float x, float y, float w, float h)
{
	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(sf::Vector2f(x, y));
	render(rect);
}
void Game::drawRect(sf::Vector2f pos, sf::Vector2f size)
{
	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	render(rect);
}
void Game::drawRect(float x, float y, sf::Vector2f size)
{
	sf::RectangleShape rect(size);
	rect.setPosition(sf::Vector2f(x, y));
	render(rect);
}
void Game::drawRect(sf::Vector2f pos, float w, float h)
{
	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(pos);
	render(rect);
}

void Game::setResolution(sf::Vector2u size)
{
	window.setSize(size);
}