#include "GUI.h"

void Background::initTeaxture()
{
	if (!this->BackgroundPicTexture.loadFromFile("Assets/PICS/background.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->IconTexture.loadFromFile("Assets/PICS/icon.png"))
	{
		std::cout << "ERROR::MAP::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Background::initBackground()
{
	BackgroundPic.setTexture(BackgroundPicTexture);
	BackgroundPic.setPosition(0, 0);

	Icon.setTexture(IconTexture);
	Icon.setPosition(401,19);
}

Background::Background()
{
	this->initTeaxture();
	this->initBackground();
}

Background::~Background()
{
}

void Background::render(sf::RenderTarget& target)
{
	target.draw(this->BackgroundPic);
	target.draw(this->Icon);
}
