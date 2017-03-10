#pragma once

#include <SFML/Audio.hpp>
#include <memory>
#include "Actor.h"

class ABalloon : public Actor
{
	public:
		ABalloon();
		void Tick() override;
		void Pop();
		void OnCollectCoin() const;
		void Reset();

	private:
		std::unique_ptr<sf::SoundBuffer> CollectSoundComponent;
		std::unique_ptr<sf::Sound> CollectSound;
		std::unique_ptr<sf::SoundBuffer> PopSoundComponent;
		std::unique_ptr<sf::Sound> PopSound;
};