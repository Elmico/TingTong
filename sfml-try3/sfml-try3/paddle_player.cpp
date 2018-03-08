#include "paddle_player.h"

paddle_player ::paddle_player(int playerNumber) {	
		this->playerNumber = playerNumber;
		
		switch (this->playerNumber)
		{
		case 0:
			this->Load("paddle1.png");
			break;
		default:
			this->Load("paddle2.png");
			break;
		}
	}
void paddle_player::Update() {
		switch (this->playerNumber)
		{
		case 0:
			this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
			break;
		default:
			this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
			break;
		}
		Entity::Update();
		//est�� mailojen liikkumisen ulos rajojen ulkopuolelle
		if (this->getPosition().y < 0) {
			this->move(0, 1.0f);
		}
		if (this->getPosition().y + this->getGlobalBounds().height > 800) {
			this->move(0, -1.0f);
		}

	}