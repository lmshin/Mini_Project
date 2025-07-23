#include "monster.h"

void pokemon::takeDamage(int dmg) {
	hp -= dmg;
	if (hp < 0) hp = 0;
}

void pokemon::eating() {
	std::cout << name << " 밥 먹음 🍚" << std::endl;
	hp += 10;
	if (hp > 100) hp = 100;
}

void pokemon::sleeping() {
	std::cout << name << " 잠 잠 😴" << std::endl;
	hp += 10;
	if (hp > 100) hp = 100;
}

void pokemon::playing() {
	std::cout << name << " 놀기! 🎮" << std::endl;
	hp -= 5;
	gainExp(5);
}

void pokemon::healthing() {
	std::cout << name << " 헬스!! 💪" << std::endl;
	hp -= 10;
	gainExp(10);
}

void pokemon::level_up() {
	exp = 0;
	lv += 1;
	std::cout << name << " 레벨업! 🎉 → Lv " << lv << std::endl;
}

void pokemon::gainExp(int amount) {
	exp += amount;
	if (exp >= 20) level_up();
}

void pokemon::print_status() {
	std::cout << "\n====== " << name << " 상태 ======\n";
	std::cout << "HP  : " << hp << std::endl;
	std::cout << "EXP : " << exp << std::endl;
	std::cout << "LV  : " << lv << std::endl;
	std::cout << "========================\n";
}
