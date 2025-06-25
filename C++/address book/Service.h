#pragma once
#include "MemDao.h"
class Service
{
	MemDao dao;
public:
	void add() {
		std::cout << "추가" << std::endl;
		std::string name;
		std::cout << "name";
		std::cin >> name;
		int idx;
		while ((idx = dao.selectByName(name)) >= 0) {
			std::cout << "이름 중복, 다시 입력하시오" << std::endl;
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
		std::cout << "전체목록" << std::endl;
		for (int i = 0; i < dao.cnt; i++) {
			dao.selectByIdx(i)->print();
		}
	}

	void search() {
		std::cout << "이름으로 검색" << std::endl;
		std::string name;
		std::cout << "name:";
		std::cin >> name;
		int idx = dao.selectByName(name);
		if (idx > 0) {
			dao.selectByIdx(idx)->print();
		}
		else {
			std::cout << "주소록에 등록되지 않은 이름입니다." << std::endl;
		}
	};

	void edit() {
		std::cout << "수정" << std::endl;
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
			std::cout << "수정 완료" << std::endl;
		}
		else {
			std::cout << "수정 취소" << std::endl;
		}
	}

	void del() {
		std::cout << "삭제" << std::endl;
		std::string name;
		std::cout << "name:";
		std::cin >> name;
		if (dao.del(name)) {
			std::cout << "삭제 완료" << std::endl;
		}
		else {
			std::cout << "삭제 취소" << std::endl;
		}
	}
	void delAll() {
		dao.delAll();
	}

};

