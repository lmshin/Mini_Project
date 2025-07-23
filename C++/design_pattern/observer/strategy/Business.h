#pragma once
#include "StrategyClass.h"

class Business
{
private:
	void sort();
	void bubble_sort();
	void quick_sort();

	void createStrategy(); //객체마다 알고리즘을 교체할 수 있어야 하기 때문에 필수 메서드
	void deleteStrategy();

public:
	void engagement();
	void setStrategy(StrategyClass* strategy);
};

