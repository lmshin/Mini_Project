#pragma once
#include "Member.h"
#include <vector>
class MemDao
{
public:
	Member* addr[30];
	int cnt = 0;

	void insert(Member* m);

	int selectByName(std::string name);

	Member* selectByIdx(int idx);

    bool update(Member* m) {
        int idx = selectByName(m->getName());
        if (idx < 0) {
            return false;
        }

        delete addr[idx];//±âÁ¸ °´Ã¼¸¦ »èÁ¦
        addr[idx] = m; //»õ °´Ã¼ »ðÀÔ
        return true;
    }

    bool del(std::string name) {
        int idx = selectByName(name);
        if (idx < 0) {
            return false;
        }
        std::cout << "°´Ã¼ »èÁ¦µÊ" << std::endl;
        addr[idx]->print();

        delete addr[idx];
        for (int i = idx; i < cnt - 1; i++) {
            addr[i] = addr[i + 1];
        }
        cnt--;
    }
    //¸ðµç ³ëµå »èÁ¦
    void delAll() {
        for (int i = 0; i < cnt; i++) {
            delete addr[i];
        }
    }
};

