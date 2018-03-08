#include <Windows.h>
#include "game_state.h"
#include "main_menu.h"

game_state coreState;
bool quitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Tennis");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	
	while (window.isOpen())
	{
		//tarkistaa ikkunan eventit jotka triggeröityi loopin viimeisestä iteraatiosta
		sf::Event event;
		while (window.pollEvent(event))
		{		
			if (event.type == sf::Event::Closed)
				window.close();
		}

	
		//ikkunan väri
		window.clear(sf::Color::Black);
		
		coreState.Update();
		coreState.Render();

		window.display();
		//quit
		if (quitGame) {
			window.close();
		}
		//hidastetaan
		Sleep(2);
	}	

	return 0;
}