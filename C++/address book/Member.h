#pragma once
#include<string>
#include<iostream>

class Member
{
private:
	std::string name;
	std::string tel;
	std::string address;
	

public:
	Member(std::string name, std::string tel, std::string address);
	std::string getName();
	std::string getTel();
	std::string getAddress();
	void setter(std::string name, std::string tel, std::string address);
	void print();

};

