#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include<ctime>
#include "Background.h"

class GUI
{
private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	void initWindow();
	void initVariables();
	void pollEvents();

	Background bg;

public:

	GUI();
	~GUI();

	void update();
	void render();
	const bool running() const;
};

