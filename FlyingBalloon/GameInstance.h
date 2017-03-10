#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "EGameState.h"

class GameInstance
{
	public:
		GameInstance(const unsigned int WindowWidth, const unsigned int WindowHeight, const sf::String& GameTitle);
		void RequestQuitGame();
		inline EGameState GetGameState() const;
		void LoadGameScene(std::unique_ptr<class BaseGameScene> TargetScene);
		void UpdateGame();
		bool IsWindowOpen() const;

	private:
		std::unique_ptr<sf::RenderWindow> Window;
		EGameState CurrentState;
		std::unique_ptr<class BaseGameScene> CurrentScene;

		inline void SetGameState(const EGameState TargetState);
		inline void QuitGame();
		bool bIsQuitting;
};