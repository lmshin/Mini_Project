#include "Member.h"

Member::Member(std::string name, std::string tel, std::string address)
	: name(name), tel(tel), address(address) {
}

std::string Member::getName() {
	return this->name;
}
std::string Member::getTel() {
	return this->tel;
}
std::string Member::getAddress() {
	return this->address;
}
void Member::setter(std::string name, std::string tel, std::string address) {
	this->name = name;
	this->tel = tel;
	this->address = address;
}

void Member::print() {
	std::cout << "name : " << this->name << std::endl;
	std::cout << "tel : " << this->tel << std::endl;
	std::cout << "address : " << this->address << std::endl;
}