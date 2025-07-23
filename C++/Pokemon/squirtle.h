#pragma once
#include "Monster.h"
class squirtle : public pokemon{
public:
    squirtle() : pokemon("꼬부기 💧", 105, 0, 1) {}

    void speak() override {
        std::cout << name << ": 꼬북꼬북~! 💦\n";
    }
};

