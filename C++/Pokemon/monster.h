#pragma once
#include<iostream>
#include<string>

class pokemon
{
public: 
	std::string name;
	int hp;
	int exp;
	int lv;
	pokemon() : name(""), hp(100), exp(0), lv(1) {}
	pokemon(std::string name, int hp, int exp, int lv) :name(name), hp(hp), exp(exp), lv(lv) {}

	void takeDamage(int dmg);
	void eating();
	void sleeping();
	void playing();
	void healthing();
	void level_up();
	void gainExp(int amount);
	virtual void speak() { // virtual은 선언 시에만 붙이고 정의 시에는 붙이지 않습니다.
		std::cout << name << " 아무 말도 안함..." << std::endl;
	}
	void print_status();

	virtual ~pokemon() {}
};
