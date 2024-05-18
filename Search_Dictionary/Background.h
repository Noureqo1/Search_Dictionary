#include "GUI.h"

#pragma once


class Background
{
	sf::Sprite BackgroundPic, Search, Icon;
	sf::Texture BackgroundPicTexture, SearchTexture, IconTexture;


	void initTeaxture();
	void initBackground();

public:
	Background();
	~Background();

	void render(sf::RenderTarget& target);
};

