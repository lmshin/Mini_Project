#include "ConcreateObserver1.h"

Target* target;
int posX;
int posY;
int info;
int velocity;

void ConcreateObserver1(Target* target) {
	this->target = target;
}

void update() override {
	posX = target->getTargetPosition().first;
	posY = target->getTargetPosition().second;
}

void processEngagement() {

}
	