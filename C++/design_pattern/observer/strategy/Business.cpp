#include "Business.h"
#include <iostream>

void 
Business::engagement() {
	std::cout << "Business::engagement" << std::endl;
	this->sort();
}

void 
Business::setStrategy(StrategyClass* strategy) {
	std::cout << "Business::setStrategy" << std::endl;

}


//private methods
void
Business::sort() {
	std::cout << "Business::sort()" << std::endl;
	//bubble sort
}

void 
Business::bubble_sort() {
	std::cout << "Business::bubble_sort()" << std::endl;
}

void 
Business::quick_sort() {
	std::cout << "Business::quick_sort()" << std::endl;
}