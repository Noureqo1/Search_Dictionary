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

std::string GUI::Getword()
{
	return SearchWord;
}

void GUI::printStrings(const std::vector<std::string>& strings)
{
	for (const auto& word : strings)
	{
		std::cout << word << std::endl;
	}
}

void GUI::Coutmousepos()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousepos = sf::Mouse::getPosition(*window);

		std::cout << mousepos.x << " " << mousepos.y << std::endl;

	}
}

void GUI::mainProgram()
{
	this->SearchWord = search.Getword();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && search.Button1IsActive())
	{
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && search.Button2IsActive())
	{
		// Retrieve misspelled words
		std::vector<std::string> misspelledWords = trie.searchMisspelledWord(this->SearchWord, 1);

		// Check if misspelledWords is empty
		if (misspelledWords.empty()) {
			std::cout << "No misspelled words found." << std::endl;
		}
		else {
			// Print the misspelled words
			printStrings(misspelledWords);
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && search.Button3IsActive())
	{
		words = trie.prefixPatternSearch(search.Getword());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && search.Button4IsActive())
	{
		words = trie.suffixPatternSearch(search.Getword());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && search.Button5IsActive())
	{
		words = trie.getWildcardMatches(search.Getword());
	}
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
	mainProgram();
	this->search.EnterWord(*this->window);
	this->pollEvents();
	this->Coutmousepos();
	search.getmousepos(*this->window);
	search.UpdateAnimation();
}

void GUI::render()
{
	this->window->clear();
	this->bg.render(*this->window);		
	this->search.render(*this->window);
	this->window->display();
}

const bool GUI::running() const
{
	return this->window->isOpen();
}
