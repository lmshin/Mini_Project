#pragma once
#include "MemDao.h"
class Service
{
	MemDao dao;
public:
	void add() {
		std::cout << "�߰�" << std::endl;
		std::string name;
		std::cout << "name";
		std::cin >> name;
		int idx;
		while ((idx = dao.selectByName(name)) >= 0) {
			std::cout << "�̸� �ߺ�, �ٽ� �Է��Ͻÿ�" << std::endl;
			std::cin >> name;
		}
		std::string tel;
		std::cout << "tel:";
		std::cin >> tel;

		std::string address;
		std::cout << "address:";
		std::cin >> address;

		dao.insert(new Member(name, tel, address));
	}

	void printAll() {
		std::cout << "��ü���" << std::endl;
		for (int i = 0; i < dao.cnt; i++) {
			dao.selectByIdx(i)->print();
		}
	}

	void search() {
		std::cout << "�̸����� �˻�" << std::endl;
		std::string name;
		std::cout << "name:";
		std::cin >> name;
		int idx = dao.selectByName(name);
		if (idx > 0) {
			dao.selectByIdx(idx)->print();
		}
		else {
			std::cout << "�ּҷϿ� ��ϵ��� ���� �̸��Դϴ�." << std::endl;
		}
	};

	void edit() {
		std::cout << "����" << std::endl;
		std::string name;
		std::cout << "name:";
		std::cin >> name;
		std::string tel;
		std::cout << "new tel:";
		std::cin >> tel;
		std::string addr;
		std::cout << "new address:";
		std::cin >> addr;
		if (dao.update(new Member(name, tel, addr))) {
			std::cout << "���� �Ϸ�" << std::endl;
		}
		else {
			std::cout << "���� ���" << std::endl;
		}
	}

	void del() {
		std::cout << "����" << std::endl;
		std::string name;
		std::cout << "name:";
		std::cin >> name;
		if (dao.del(name)) {
			std::cout << "���� �Ϸ�" << std::endl;
		}
		else {
			std::cout << "���� ���" << std::endl;
		}
	}
	void delAll() {
		dao.delAll();
	}

};

