#pragma once

#include <SFML/Graphics.hpp>

class Score : public sf::Text
{
	public:
		Score(const sf::Font &font, const unsigned int size);
		void IncrementScore();
		void Tick();
		void Reset();

	private:
		int Value;
};