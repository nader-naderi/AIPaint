#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <ctime>
#include <list>


class PaintEngine
{
public:
	PaintEngine();
	~PaintEngine();
	PaintEngine(const PaintEngine&) = delete;
	PaintEngine& operator=(const PaintEngine&) = delete;
	PaintEngine(PaintEngine&&) {}

	void Run();
	void Draw();
	void Update();
	void Paint(sf::Color color, sf::Vector2f targetPosition, float strength);
	void add(sf::CircleShape shape);

	float x, y;
	sf::Vector2f prevMousePosition;

	int r, g, b;

	sf::RenderWindow window;

	std::list<sf::CircleShape> circles;
	std::list<sf::CircleShape>::iterator iter;


private:

};

