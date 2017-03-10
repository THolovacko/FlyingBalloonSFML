#pragma once

#include "BaseGameScene.h"

class MainMenu : public BaseGameScene
{
	public:
		void Initialize(std::unique_ptr<sf::RenderWindow>& Window) override;
		void Tick(class GameInstance& GameManager) override;
		void Render(std::unique_ptr<sf::RenderWindow>& Window) override;

	private:
		std::unique_ptr<sf::Font> Font;
		std::unique_ptr<sf::Text> TitleText;
		std::unique_ptr<sf::Text> PlayText;
		std::unique_ptr<sf::Text> QuitText;
		int SelectedTextID;
		bool bUpKeyPressed;
		bool bDownKeyPressed;
};