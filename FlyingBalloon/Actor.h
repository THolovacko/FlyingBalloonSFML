#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class Actor : public sf::Sprite
{
	public:
		sf::Vector2f Velocity;
		void LoadTexture(const std::string& FileName);
		virtual void Tick();
		bool CheckCollision(const Actor& OtherActor) const;
		virtual ~Actor() {}

	protected:
		Actor();

	private:
		std::unique_ptr<sf::Texture> Texture;
};