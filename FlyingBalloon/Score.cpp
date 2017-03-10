#include "Score.h"

Score::Score(const sf::Font& TargetFont, const unsigned int TargetSize) : sf::Text("Score: 0", TargetFont, TargetSize)
{
	Value = 0;
}

void Score::IncrementScore()
{
	Value += 1;
}

void Score::Reset()
{
	Value = 0;
}

void Score::Tick()
{
	setString("Score: " + std::to_string(Value));
}