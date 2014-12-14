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

		if (window.getSize().x / 1920.f <= window.getSize().y / 1080.f)
		{
			float yScale = (window.getSize().x * (9.f / 16.f)) / window.getSize().y;
			camera.setViewport(sf::FloatRect(0.f, (1.f - yScale) / 2, 1.f, yScale));
		}
		else
		{
			float xScale = (window.getSize().y * (16.f / 9.f)) / window.getSize().x;
			camera.setViewport(sf::FloatRect((1.f - xScale) / 2, 0.f, xScale, 1.f));
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

void Game::setResolution(sf::Vector2u size)
{
	window.setSize(size);
}