#include "ABalloon.h"

ABalloon::ABalloon()
{
	LoadTexture("Balloon.png");

	CollectSoundComponent.reset(new sf::SoundBuffer());
	CollectSoundComponent->loadFromFile("Assets/Audio/CollectCoin.wav");
	CollectSound.reset(new sf::Sound(*CollectSoundComponent));

	PopSoundComponent.reset(new sf::SoundBuffer());
	PopSoundComponent->loadFromFile("Assets/Audio/Pop.wav");
	PopSound.reset(new sf::Sound(*PopSoundComponent));
}

void ABalloon::Tick()
{
	Actor::Tick();

	Velocity.x = (float) sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) * 2 - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) * 2;

	if (getPosition().x < 0)
	{
		move(2.0f, 0);
	}
	if (getPosition().x + getGlobalBounds().width > 1200)
	{
		move(-2.0f, 0);
	}
}

void ABalloon::Pop()
{
	PopSound->play();
	Reset();
}

void ABalloon::Reset()
{
	setPosition(600,700);
}

void ABalloon::OnCollectCoin() const
{
	CollectSound->play();
}