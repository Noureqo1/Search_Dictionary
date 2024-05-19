#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>
#include "Background.h"
#include "Search.h"
#include "Trie.h"

class GUI
{
private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	sf::Vector2i mousepos;

	std::vector<std::string> words;
	std::string SearchWord;

	void initWindow();
	void initVariables();
	void pollEvents();

	Background bg;
	Search search;
	Trie trie;

public:

	GUI();
	~GUI();

	std::string Getword();

	void printStrings(const std::vector<std::string>& strings);

	void Coutmousepos();

	void mainProgram();

	void update();
	void render();
	const bool running() const;
};

