#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

class BaseGameScene
{
	public:
		virtual void Initialize(std::unique_ptr<sf::RenderWindow>& Window) {}
		virtual void Tick(class GameInstance& GameManager) {}
		virtual void Render(std::unique_ptr<sf::RenderWindow>& Window) {}
		virtual ~BaseGameScene() {std:: cout << "A Scene Was Destroyed" << std:: endl;}

	protected:
		BaseGameScene() {}
};