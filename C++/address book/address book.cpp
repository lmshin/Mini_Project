#include "Member.h"
#include "MemDao.h"
#include "Service.h"

int main() {
    Service s;
    std::string name;
    bool flag = true;
    int x;
    while (flag) {
        std::cout << "1.추가 2.검색 3.수정 4.삭제 5.전체목록 6.종료" << std::endl;
        std::cin >> x;
        switch (x) {
        case 1:
            s.add();
            break;
        case 2:
            s.search();
            break;
        case 3:
            s.edit();
            break;
        case 4:
            s.del();
            break;
        case 5:
            s.printAll();
            break;
        case 6:
            flag = false;
            break;
        }
    }
}