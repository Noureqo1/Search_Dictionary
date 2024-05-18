#include"GUI.h"

using namespace sf;

int main()
{
	//Initialize random seed
	srand(static_cast<unsigned>(time(0)));
	//Initialize game object

	GUI gui;

	//Game loop
	while (gui.running())
	{
		//game.tests();
		gui.update();
		gui.render();
	}

	//End of application
	return 0;
}
