#include "ACoin.h"
#include "ABalloon.h"

ACoin::ACoin()
{
	LoadTexture("Coin.png");
	Reset();
}

void ACoin::Tick()
{
	Actor::Tick();

	if (getPosition().y > 900)
	{
		Reset();
	}
}

void ACoin::Reset()
{
	setPosition((float)(rand() % 1200), (float) (rand() % 100) * -1);
	Velocity.y = (float) (rand() % 2) + 1;
}