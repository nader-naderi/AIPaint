#include "PaintEngine.hpp"

PaintEngine::PaintEngine()
{
	window.create(sf::VideoMode(800, 600), "Paint Application");
	Run();
}

PaintEngine::~PaintEngine()
{
}

void PaintEngine::Run()
{
    sf::Vector2i mousePos;
    sf::Event ev;

    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                switch (ev.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                }
                break;

            case sf::Event::MouseButtonReleased:
                if (ev.mouseButton.button == sf::Mouse::Left)
                {
                    mousePos = sf::Mouse::getPosition(window);
                    prevMousePosition = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (ev.mouseButton.button == sf::Mouse::Left)
                {
                    mousePos = sf::Mouse::getPosition(window);
                    prevMousePosition = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                }
                break;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mousePos = sf::Mouse::getPosition(window);
            Paint(sf::Color(255, 255, 255), sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)), 2);
        }

        window.clear();
        Update();
        window.display();
    }
}


void PaintEngine::Draw()
{
}

void PaintEngine::Update()
{
	iter = circles.begin();

	while (iter != circles.end())
	{
		window.draw(*iter);
		iter++;
	}
}

void PaintEngine::Paint(sf::Color color, sf::Vector2f targetPosition, float strength)
{
	sf::Vector2f delta = targetPosition - prevMousePosition;
	float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

	// Adjust the step size based on the distance between current and previous positions
	float step = 1.0f;
	if (distance > 0) {
		step = strength / distance;
	}

	for (float t = 0.0f; t < 1.0f; t += step) {
		sf::Vector2f interpolatedPosition = prevMousePosition + t * delta;
		sf::CircleShape point(strength);
		point.setPosition(interpolatedPosition);
		point.setFillColor(color);
		add(point);
	}

	prevMousePosition = targetPosition;
}

void PaintEngine::add(sf::CircleShape shape)
{
	circles.push_back(shape);
}
