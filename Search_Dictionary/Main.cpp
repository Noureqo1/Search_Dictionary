#include"GUI.h"

using namespace sf;

int main()
{
	Trie trie;
	GUI gui;
	Search s;
	trie.insert("hello");
	trie.insert("world");
	trie.insert("apple");
	trie.insert("banana");
	trie.insert("cat");
	trie.insert("carrot");
	trie.insert("bean");

	/*gui.printStrings(trie.searchMisspelledWord("apple", 1));*/

	//Initialize random seed
	srand(static_cast<unsigned>(time(0)));
	//Initialize game object

	

	//Game loop
	while (gui.running())
	{
		//game.tests();
		gui.update();
		gui.render();
		


			// Retrieve misspelled words
			std::vector<std::string> misspelledWords = trie.searchMisspelledWord(gui.Getword(), 1);

			std::cout << gui.Getword() << std::endl;
			// Check if misspelledWords is empty
			if (misspelledWords.empty()) {
				std::cout << "No misspelled words found." << std::endl;
			}
			else {
				// Print the misspelled words
				gui.printStrings(misspelledWords);
			}

	}

	//End of application
	return 0;
}
