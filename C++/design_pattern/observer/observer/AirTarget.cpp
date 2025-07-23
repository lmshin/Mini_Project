#include "AirTarget.h"
#include <iostream>

AirTarget::AirTarget() {

}

AirTarget::~AirTarget() {

}

void 
AirTarget::attach(Engagement* observer) {
	observers.push_back(observer);
}

void 
AirTarget::detach(Engagement* observer) {
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void 
AirTarget::notify() {
	//list들에 저장된 observer 들에게 변경을 알린다.
	for (auto& ele : observers) {
		
		ele->update(this);
	}
}

string 
AirTarget::exportTargetInfo() {
	std::cout << "exportTargetInfo" << endl;
	return "info";
}

pair<int, int> 
AirTarget::getTargetPosition() {
	std::cout << "getTargetPosition" << endl;
	return make_pair(1, 1);
}

double 
AirTarget::getTargetVelocity() {
	std::cout << "getTargetVelocity" << endl;
	return 10.0;
}