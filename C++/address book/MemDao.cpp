#include "MemDao.h"
//#include "Member.h"
void MemDao::insert(Member* m) {
	if (cnt >= 29) {
		std::cout << "주소록이 다 찼습니다." << std::endl;
		return;
	}

	addr[cnt++] = m;
}

int MemDao::selectByName(std::string name) {
	int i;
	for (i = 0; i < cnt; i++) {
		if (name == addr[i]->getName()) {
			return i;
		}
	}

	return -1;
}

Member* MemDao::selectByIdx(int idx) {
	if (idx >= cnt || idx < 0) {
		std::cout << "잘못된 인덱스" << std::endl;
	}
	else {
		return addr[idx];
	}
}