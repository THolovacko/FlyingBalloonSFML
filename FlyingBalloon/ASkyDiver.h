#pragma once

#include "Actor.h"
#include "ISkyDanger.h"

class ASkyDiver : public Actor, ISkyDanger
{
	public:
		ASkyDiver();
		void Tick() override;
		void Reset();
};