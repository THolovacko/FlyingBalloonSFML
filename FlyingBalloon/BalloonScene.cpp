#include "GameInstance.h"
#include "MainMenu.h"
#include "BalloonScene.h"

void BalloonScene::Initialize(std::unique_ptr<sf::RenderWindow>& Window)
{
	bEnterKeyPressed = false;

	Font.reset(new sf::Font());
	Font->loadFromFile("Assets/Graphics/font.ttf");

	PauseText.reset(new sf::Text("Press Escape to Quit\nPress Enter to Continue or Pause", *Font, 64U));
	PauseText->setOrigin(PauseText->getGlobalBounds().width / 2, PauseText->getGlobalBounds().height / 2);
	PauseText->setPosition((float) Window->getSize().x / 2, (float) Window->getSize().y / 2);

	Balloon.reset(new ABalloon());
	Balloon->setPosition(600.0f, 700.0f);

	CurrentScore.reset(new Score(*Font, 64U));
	CurrentScore->setPosition(1000.0f, 0.0f);

	Coins = std::vector<ACoin>(5);
	SkyDivers = std::vector<ASkyDiver>(10);
}

void BalloonScene::Tick(GameInstance& GameManager)
{
	if (bIsPaused)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !bEnterKeyPressed)
		{
			bIsPaused = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			GameManager.LoadGameScene(std::unique_ptr<MainMenu>(new MainMenu()));
		}
	}
	else
	{
		Balloon->Tick();
		CurrentScore->Tick();

		for (ACoin& currentCoin : Coins)
		{
			currentCoin.Tick();
			if (currentCoin.CheckCollision(*Balloon))
			{
				CurrentScore->IncrementScore();
				Balloon->OnCollectCoin();
				currentCoin.Reset();
			}
		}

		for (ASkyDiver& currentSkyDiver : SkyDivers)
		{
			currentSkyDiver.Tick();
			if (currentSkyDiver.CheckCollision(*Balloon))
			{
				Balloon->Pop();
				CurrentScore->Reset();

				for (ACoin& resettingCoin : Coins)
				{
					resettingCoin.Reset();
				}

				for (ASkyDiver& resettingSkyDiver : SkyDivers)
				{
					resettingSkyDiver.Reset();
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !bEnterKeyPressed)
		{
			bIsPaused = true;
		}
	}

	bEnterKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}

void BalloonScene::Render(std::unique_ptr<sf::RenderWindow>& Window)
{
	Window->draw(*Balloon);
	Window->draw(*CurrentScore);
	
	for (ACoin& currentCoin : Coins)
	{
		Window->draw(currentCoin);
	}

	for (ASkyDiver& currentSkyDiver : SkyDivers)
	{
		Window->draw(currentSkyDiver);
	}

	if (bIsPaused)
	{
		Window->draw(*PauseText);
	}
}