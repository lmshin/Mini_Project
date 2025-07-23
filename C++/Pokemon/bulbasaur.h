#pragma once
#include "Monster.h"
class bulbasaur : public pokemon{
public:
	bulbasaur() : pokemon("이상해씨 🍃", 110, 0, 1) {}
	void speak() override {
		std::cout << name << ": 이상해~씨! 🌱\n";
	}
};

