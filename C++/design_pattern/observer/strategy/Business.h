#pragma once
#include "StrategyClass.h"

class Business
{
private:
	void sort();
	void bubble_sort();
	void quick_sort();

	void createStrategy(); //��ü���� �˰����� ��ü�� �� �־�� �ϱ� ������ �ʼ� �޼���
	void deleteStrategy();

public:
	void engagement();
	void setStrategy(StrategyClass* strategy);
};

