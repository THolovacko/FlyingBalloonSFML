#include <Windows.h>
#include "GameInstance.h"
#include "BaseGameScene.h"

GameInstance::GameInstance(const unsigned int WindowWidth, const unsigned int WindowHeight, const sf::String& GameTitle)
{
	this->Window.reset(new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight), GameTitle));
	this->SetGameState(EGameState::WaitingToLoadScene);
	bIsQuitting = false;
}

inline EGameState GameInstance::GetGameState() const
{
	return this->CurrentState;
}

inline void GameInstance::SetGameState(const EGameState TargetGameState)
{
	if (this->CurrentState != EGameState::Quitting)
	{
		this->CurrentState = TargetGameState;
	}
}

inline void GameInstance::QuitGame()
{
	Window->close();
}

void GameInstance::LoadGameScene(std::unique_ptr<class BaseGameScene> TargetScene)
{
	if (!TargetScene) {return;}

	SetGameState(EGameState::Loading);
	this->CurrentScene = std::move(TargetScene);
	this->CurrentScene->Initialize(Window);
	SetGameState(EGameState::Playing);
}

void GameInstance::UpdateGame()
{
	if (!CurrentScene) {return;}
	
	sf::Event currentEvent;
	while (Window->pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::Closed)
		{
			RequestQuitGame();
		}
	}
	
	Window->clear(sf::Color::Blue);
	CurrentScene->Tick(*this);
	CurrentScene->Render(Window);
	Window->display();

	if (bIsQuitting)
	{
		QuitGame();
	}

	Sleep(5);
}

bool GameInstance::IsWindowOpen() const
{	
	return Window->isOpen();
}

void GameInstance::RequestQuitGame()
{
	SetGameState(EGameState::Quitting);
	bIsQuitting = true;
}