#pragma once
#include "Engagement.h"
#include "Target.h"
class ConcreateObserver1 : public Engagement
{
private :
	Target* target;
	int posX;
	int posY;
	int info;
	int velocity;

public :
	ConcreateObserver1(Target* target) {
		this->target = target;
	}

	void update() override {
		posX = target->getTargetPosition().first;
		posY = target->getTargetPosition().second;
	}

	void processEngagement() {

	}
};

