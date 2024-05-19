#pragma once
#include "GUI.h"

class Search
{
private:

	sf::Font font;
	sf::Text text;

	sf::Text button1Text;
	sf::Text button2Text;
	sf::Text button3Text;
	sf::Text button4Text;
	sf::Text button5Text;

	std::string inputString;
	std::string SearchWord;


	sf::Event event;

	sf::Sprite SearchBar,Banner,Button1, Button2, Button3, Button4, Button5;
	sf::Texture SearchBarTexture, BannerTexture, Button1Texture, Button2Texture, Button3Texture, Button4Texture, Button5Texture;
	sf::Vector2f mouseposition;

	bool stop;
	bool Button1Active;
	bool Button2Active;
	bool Button3Active;
	bool Button4Active;
	bool Button5Active;
	bool Active;

	void initText();
	void initVariables();
	void initTeaxture();
	void initSprite();

public:

	 Search();
	~Search();

	
	bool Button1IsActive();
	bool Button2IsActive();
	bool Button3IsActive();
	bool Button4IsActive();
	bool Button5IsActive();

	std::string Getword();

	void getmousepos(sf::RenderWindow& window);
	void EnterWord(sf::RenderWindow& window);

	void UpdateAnimation();
	void render(sf::RenderTarget& target);
};

