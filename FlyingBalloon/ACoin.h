#pragma once

#include "Actor.h"

class ACoin : public Actor
{
	public:
		ACoin();
		void Tick() override;
		void Reset();
};