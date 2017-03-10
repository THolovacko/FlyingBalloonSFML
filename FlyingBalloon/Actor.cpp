#include "Actor.h"

Actor::Actor()
{
	Texture.reset(new sf::Texture());
}

void Actor::LoadTexture(const std::string& FileName)
{
	Texture->loadFromFile("Assets/Graphics/Sprites/" + FileName);
	setTexture(*Texture);
}

void Actor::Tick()
{
	move(Velocity);
}

bool Actor::CheckCollision(const Actor& OtherActor) const
{
	return getGlobalBounds().intersects(OtherActor.getGlobalBounds());
}