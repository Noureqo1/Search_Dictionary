#include "GUI.h"

void Search::initText()
{
	if (!font.loadFromFile("Assets/Fonts/Barlock.otf")) {
		std::cerr << "Error loading font file" << std::endl;
		return;
	}

	text.setFont(font);
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::Black);
	text.setPosition(170, 340);

	button1Text.setFont(font);
	button1Text.setCharacterSize(12);
	button1Text.setFillColor(sf::Color::Black);
	button1Text.setPosition(150, 540);
	button1Text.setString("Multiple Word");
	
	button2Text.setFont(font);
	button2Text.setCharacterSize(12);
	button2Text.setFillColor(sf::Color::Black);
	button2Text.setPosition(300, 540);
	button2Text.setString("felling lucky");

	button3Text.setFont(font);
	button3Text.setCharacterSize(12);
	button3Text.setFillColor(sf::Color::Black);
	button3Text.setPosition(435, 540);
	button3Text.setString("Prifix Search");

	button4Text.setFont(font);
	button4Text.setCharacterSize(12);
	button4Text.setFillColor(sf::Color::Black);
	button4Text.setPosition(575, 540);
	button4Text.setString("Surfix Search");

	button5Text.setFont(font);
	button5Text.setCharacterSize(12);
	button5Text.setFillColor(sf::Color::Black);
	button5Text.setPosition(730, 535);
	button5Text.setString("Wildcard\n    Search");
}

void Search::initVariables()
{
	bool stop = false;
	this->SearchWord = this->inputString;
	Active = false;
	this->Button1Active = false;
	this->Button2Active = false;
	this->Button3Active = false;
	this->Button4Active = false;
	this->Button5Active = false;
}

void Search::initTeaxture()
{
	if (!this->SearchBarTexture.loadFromFile("Assets/PICS/search.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->BannerTexture.loadFromFile("Assets/PICS/banner.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->Button1Texture.loadFromFile("Assets/PICS/button.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->Button2Texture.loadFromFile("Assets/PICS/button.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->Button3Texture.loadFromFile("Assets/PICS/button.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->Button4Texture.loadFromFile("Assets/PICS/button.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->Button5Texture.loadFromFile("Assets/PICS/button.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Search::initSprite()
{
	SearchBar.setTexture(SearchBarTexture);
	this->SearchBar.setTextureRect(sf::IntRect(0, 0, 922, 100));
	SearchBar.setPosition(15,334);

	Banner.setTexture(BannerTexture);
	Banner.setPosition(100,500);

	Button1.setTexture(Button1Texture);
	this->Button1.setTextureRect(sf::IntRect(0, 0, 130, 72));
	Button1.setPosition(145,513);

	Button2.setTexture(Button1Texture);
	this->Button2.setTextureRect(sf::IntRect(0, 0, 130, 72));
	Button2.setPosition(285, 513);

	Button3.setTexture(Button1Texture);
	this->Button3.setTextureRect(sf::IntRect(0, 0, 130, 72));
	Button3.setPosition(425, 513);

	Button4.setTexture(Button1Texture);
	this->Button4.setTextureRect(sf::IntRect(0, 0, 130, 72));
	Button4.setPosition(565, 513);

	Button5.setTexture(Button1Texture);
	this->Button5.setTextureRect(sf::IntRect(0, 0, 130, 72));
	Button5.setPosition(705, 513);
}

Search::Search()
{
	this->initTeaxture();
	this->initSprite();
	this->initText();
}

Search::~Search()
{
}


bool Search::Button1IsActive()
{
	return Button1Active;
}

bool Search::Button2IsActive()
{
	return Button2Active;
}

bool Search::Button3IsActive()
{
	return Button3Active;
}

bool Search::Button4IsActive()
{
	return Button4Active;
}

bool Search::Button5IsActive()
{
	return Button5Active;
}

std::string Search::Getword()
{
	this->SearchWord = this->inputString;
	return this->inputString;
}


void Search::getmousepos(sf::RenderWindow& window)
{
	mouseposition = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}

void Search::EnterWord(sf::RenderWindow& window)
{
	while (window.pollEvent(event) && !stop)
	{
		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode == '\b' && !inputString.empty()) { // Handle backspace
				inputString.pop_back();
			}
			else if (event.text.unicode < 128) {
				inputString += static_cast<char>(event.text.unicode);
			}
			text.setString(inputString);
		}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		//{
		//	stop = true;
		//	break;
		//}
	}
}

void Search::UpdateAnimation()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Button1.getGlobalBounds().contains(mouseposition) && !Active)
	{	
		Button1.setTextureRect(sf::IntRect(150, 0, 130, 72));
		Active = true;
		Button1Active = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Button2.getGlobalBounds().contains(mouseposition) && !Active)
	{
		Button2.setTextureRect(sf::IntRect(150, 0, 130, 72));
		Active = true;
		Button2Active = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Button3.getGlobalBounds().contains(mouseposition) && !Active)
	{
		Button3.setTextureRect(sf::IntRect(150, 0, 130, 72));
		Active = true;
		Button3Active = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Button4.getGlobalBounds().contains(mouseposition) && !Active)
	{
		Button4.setTextureRect(sf::IntRect(150, 0, 130, 72));
		Active = true;
		Button4Active = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Button5.getGlobalBounds().contains(mouseposition) && !Active)
	{
		Button5.setTextureRect(sf::IntRect(150, 0, 130, 72));
		Active = true;
		Button5Active = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Active = false;
		Button1.setTextureRect(sf::IntRect(0, 0, 130, 72));
		Button1Active = false;
		Button2.setTextureRect(sf::IntRect(0, 0, 130, 72));
		Button2Active = false;
		Button3.setTextureRect(sf::IntRect(0, 0, 130, 72));
		Button3Active = false;
		Button4.setTextureRect(sf::IntRect(0, 0, 130, 72));
		Button4Active = false;
		Button5.setTextureRect(sf::IntRect(0, 0, 130, 72));
		Button5Active = false;
	}
}

void Search::render(sf::RenderTarget& target)
{
	target.draw(this->SearchBar);
	target.draw(this->Banner);
	target.draw(this->Button1);
	target.draw(this->Button2);
	target.draw(this->Button3);
	target.draw(this->Button4);
	target.draw(this->Button5);
	target.draw(this->text);

	target.draw(this->button1Text);
	target.draw(this->button2Text);
	target.draw(this->button3Text);
	target.draw(this->button4Text);
	target.draw(this->button5Text);
}


