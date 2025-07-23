#include "MemDao.h"
//#include "Member.h"
void MemDao::insert(Member* m) {
	if (cnt >= 29) {
		std::cout << "�ּҷ��� �� á���ϴ�." << std::endl;
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
		std::cout << "�߸��� �ε���" << std::endl;
	}
	else {
		return addr[idx];
	}
}