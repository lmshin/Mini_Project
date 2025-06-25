#pragma once
#include "monster.h"

class pikachu : public pokemon {
public:
	pikachu() : pokemon("피카츄 ⚡", 100, 0, 1) {}
	void speak() override {
		std::cout << name << ": 피카피카~! ⚡\n";
	}
};


