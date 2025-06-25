//main.cpp
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <algorithm>
#include <limits>

//직접 만든 헤더 파일들
#include "monster.h"
#include "bulbasaur.h"
#include "squirtle.h"
#include "pikachu.h"
#include "Utilities.h"

using namespace std;

//함수 선언
pokemon* chooseStarter(void);
void showMenu(void);


int main() {

	pokemon* myPokemon = chooseStarter();
	cout << "\n✅ 당신의 포켓몬은 " << myPokemon->name << "입니다!\n";
	myPokemon->print_status();

	int choice;
	while (true) {
		clearScreen();
		myPokemon->print_status();
		showMenu();
		cin >> choice;
		// ✅ 여기가 중요: 숫자 입력 후 남은 엔터 문자를 버퍼에서 제거
		char c;
		while (std::cin.get(c) && c != '\n'); 

		if (choice == 7) { // ✅ 맵 탐험 메뉴 선택
			clearScreen(); // 맵으로 진입하기 전에 화면 클리어
			drawMap();     // 맵 초기화 그리기
			gotoxy(playerX, playerY);
			cout << '@';   // 플레이어 그리기

			// 맵 탐험 루프
			while (true) {
				if (_kbhit()) { // 키 입력이 있으면
					char key = _getch(); // 키를 읽음

					int prevX = playerX;
					int prevY = playerY;

					switch (key) {
					case 'w': case 'W': updatePlayerPosition(playerX, playerY - 1); break; // 위
					case 's': case 'S': updatePlayerPosition(playerX, playerY + 1); break; // 아래
					case 'a': case 'A': updatePlayerPosition(playerX - 1, playerY); break; // 왼쪽
					case 'd': case 'D': updatePlayerPosition(playerX + 1, playerY); break; // 오른쪽
					case 'q': case 'Q': gotoxy(0, MAP_HEIGHT); std::cout << "\n맵 탐험을 종료합니다.\n"; break; // 맵 탐험 종료
					}
					if (key == 'q' || key == 'Q') break; // 맵 탐험 루프 탈출
				}
				// 여기에 필요한 다른 맵 관련 로직 (예: 포켓몬 조우 등) 추가 가능
			}
			// 맵 탐험 종료 후 버퍼 비우기 (_getch()는 버퍼를 사용하지 않지만 혹시 몰라)
			
			continue; // 메인 메뉴로 돌아감
		}

		switch (choice) {
		case 1:
			std::cout << "\n[상태 확인 완료]";
			myPokemon->print_status();
			break;
		case 2:
			myPokemon->eating();
			break;
		case 3:
			myPokemon->sleeping();
			break;
		case 4:
			myPokemon->playing();
			break;
		case 5:
			myPokemon->healthing();
			break;
		case 6:
			myPokemon->speak();
			break;
		case 0:
			cout << "게임을 종료합니다. 👋\n";
			delete myPokemon;
			return 0;
		default:
			cout << "❗ 잘못된 입력입니다.\n";
		}

		std::cout << "\n계속하려면 아무 키나 누르세요...";
		std::cin.get(); // 사용자 입력을 기다립니다.
	}
}

void showMenu() {
	cout << "\n📋 메뉴를 선택하세요:\n";
	cout << "1. 상태 보기\n";
	cout << "2. 밥 먹이기\n";
	cout << "3. 재우기\n";
	cout << "4. 놀아주기\n";
	cout << "5. 헬스 시키기\n";
	cout << "6. 포켓몬 울음소리 듣기\n";
	cout << "7. 맵 탐험하기\n";
	cout << "0. 종료\n";
	cout << "입력 >> ";
}

pokemon* chooseStarter(void) { //포켓몬을 입력받아 해당 class의 객체를 반환

	cout << "🌟 포켓몬을 선택하세요!\n";
	cout << "1. 피카츄 ⚡ (HP: 35, ATK: 55)\n";
	cout << "2. 파이리 🔥 (HP: 39, ATK: 52)\n";
	cout << "3. 이상해씨 🍃 (HP: 45, ATK: 49)\n";
	cout << "입력 >> ";

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		return new pikachu();
	case 2:
		return new bulbasaur();
	case 3:
		return new squirtle();
	default:
		cout << "❗잘못된 선택입니다. 기본값으로 피카츄 선택!\n";
		return new pikachu();
	}
}
