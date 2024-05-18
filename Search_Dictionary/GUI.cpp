#include "GUI.h"


GUI::GUI()
{
	this->initVariables();
	this->initWindow();
}

GUI::~GUI()
{
	delete this->window;
}


void GUI::initWindow()
{
	this->videoMode = sf::VideoMode(960, 640);

	this->window = new sf::RenderWindow(this->videoMode, "Zwailian Life ", sf::Style::Close | sf::Style::Titlebar);

	this->window->setFramerateLimit(60);
}

void GUI::initVariables()
{

}

void GUI::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void GUI::update()
{
	this->pollEvents();
}

void GUI::render()
{
	this->window->clear();
	this->bg.render(*this->window);
	this->window->display();
}

const bool GUI::running() const
{
	return this->window->isOpen();
}
