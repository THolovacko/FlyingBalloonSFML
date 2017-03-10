#include "ASkyDiver.h"

ASkyDiver::ASkyDiver()
{
	LoadTexture("SkyDiver.png");

	Reset();
}

void ASkyDiver::Tick()
{
	Actor::Tick();

	if (getPosition().y > 900)
	{
		Reset();
	}
}

void ASkyDiver::Reset()
{
	setPosition((float) (rand() % 1300) , (float) (rand() % 500) * -1);
	Velocity.y = (float) (rand() % 3) + 1;
}