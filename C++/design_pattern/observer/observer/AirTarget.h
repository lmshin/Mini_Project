#pragma once
#include "Engagement.h"
#include "Target.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

class AirTarget : public Target
{
public:
	int Element_cnt = 0;
	//map으로 나중에 변경해보기
	vector<Engagement*> observers;

	AirTarget();
	~AirTarget();

	virtual void attach(Engagement* observer) override;
	virtual void detach(Engagement* observer) override;
	virtual void notify() override;

	virtual string exportTargetInfo() override;
	virtual pair<int, int> getTargetPosition() override;
	virtual double getTargetVelocity() override;
};

