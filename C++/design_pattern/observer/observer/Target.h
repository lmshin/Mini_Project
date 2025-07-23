#pragma once
#include "Engagement.h"
#include <string>
using namespace std;

class Target
{
	virtual void attach(Engagement* observer) = 0;
	virtual void detach(Engagement* observer) = 0;
	virtual void notify() = 0;

	virtual string exportTargetInfo();
	virtual pair<int, int> getTargetPosition();
	virtual double getTargetVelocity();
	~Target();
};

