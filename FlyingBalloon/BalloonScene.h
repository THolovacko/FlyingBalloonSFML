#pragma once

#include "BaseGameScene.h"
#include "ASkyDiver.h"
#include "ACoin.h"
#include "Score.h"
#include "ABalloon.h"
#include <memory>

class BalloonScene : public BaseGameScene
{
	public:
		void Initialize(std::unique_ptr<sf::RenderWindow>& Window) override;
		void Tick(class GameInstance& GameManager) override;
		void Render(std::unique_ptr<sf::RenderWindow>& Window) override;

	private:
		bool bIsPaused;
		bool bEnterKeyPressed;
		std::unique_ptr<sf::Font> Font;
		std::unique_ptr<sf::Text> PauseText;
		std::unique_ptr<ABalloon> Balloon;
		std::unique_ptr<Score> CurrentScore;
		std::vector<ACoin> Coins;
		std::vector<ASkyDiver> SkyDivers;
};