#include "MainMenu.h"
#include "GameInstance.h"
#include "BalloonScene.h"

void MainMenu::Initialize(std::unique_ptr<sf::RenderWindow>& Window)
{
	SelectedTextID = 0;

	Font.reset(new sf::Font());
	Font->loadFromFile("Assets/Graphics/font.ttf");

	TitleText.reset(new sf::Text("Flying Balloon", *Font, 256U));
	TitleText->setOrigin(TitleText->getGlobalBounds().width / 2, TitleText->getGlobalBounds().height / 2);
	TitleText->setPosition((float) Window->getSize().x / 2, (float) Window->getSize().y / 8);

	PlayText.reset(new sf::Text("Play", *Font, 128U));
	PlayText->setOrigin(PlayText->getGlobalBounds().width / 2, PlayText->getGlobalBounds().height / 2);
	PlayText->setPosition((float) Window->getSize().x / 2, (float) Window->getSize().y / 2);

	QuitText.reset(new sf::Text("Quit", *Font, 128U));
	QuitText->setOrigin(QuitText->getGlobalBounds().width / 2, QuitText->getGlobalBounds().height / 2);
	QuitText->setPosition((float) Window->getSize().x / 2, (float) (Window->getSize().y / 2) + PlayText->getGlobalBounds().height);
}

void MainMenu::Tick(GameInstance& GameManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !bUpKeyPressed)
	{
		SelectedTextID -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !bDownKeyPressed)
	{
		SelectedTextID += 1;
	}
	if (SelectedTextID > 1)
	{
		SelectedTextID = 0;
	}
	if (SelectedTextID < 0)
	{
		SelectedTextID = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (SelectedTextID)
		{
			case 0:
				GameManager.LoadGameScene(std::unique_ptr<BalloonScene>(new BalloonScene()));
				break;
			case 1:
				GameManager.RequestQuitGame();
				break;
		}
	}

	bUpKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	bDownKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void MainMenu::Render(std::unique_ptr<sf::RenderWindow>& Window)
{
	PlayText->setFillColor(sf::Color::White);
	PlayText->setOutlineColor(sf::Color::Black);
	QuitText->setFillColor(sf::Color::White);
	QuitText->setOutlineColor(sf::Color::Black);
	
	switch (SelectedTextID)
	{
		case 0:
			PlayText->setFillColor(sf::Color::Green);
			break;
		case 1:
			QuitText->setFillColor(sf::Color::Green);
			break;
	}

	Window->draw(*TitleText);
	Window->draw(*PlayText);
	Window->draw(*QuitText);
}