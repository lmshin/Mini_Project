#include "Utilities.h"

//변수들
const int MAP_HEIGHT = 9;
const int MAP_WIDTH = 20;

std::vector<std::string> gameMap = {
	"####################",
	"#@.................#",
	"#.################.#",
	"#.##...............#",
	"#.##.##############.",
	"#.##...............#",
	"#.##############.###",
	"#..................#",
	"####################",
};

// 플레이어 현재 위치
int playerX = 1;
int playerY = 1;


void clearScreen() {
	system("cls");  // 또는 for (int i = 0; i < 30; ++i) cout << "\n";
}

// gotoxy 함수 (커서 위치 이동)
void gotoxy(int x, int y) {
	COORD coord = { short(x), short(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#include "Utilities.h"

// 맵 그리기 함수
void drawMap() {
	for (int y = 0; y < MAP_HEIGHT; ++y) {
		gotoxy(0, y); // 각 줄의 시작으로 커서 이동
		std::cout << gameMap[y];
	}
}

// 플레이어 그리기 및 이동 함수
void updatePlayerPosition(int newX, int newY) {
	// 맵 경계 체크 및 벽 충돌 체크
	if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT &&
		gameMap[newY][newX] != '#') { // 벽이 아니면 이동

		// 이전 위치를 길로 되돌림 (혹은 원래 맵 타일로)
		gotoxy(playerX, playerY);
		std::cout << '.'; // 이전 위치를 길로 그림

		// 새 위치로 플레이어 이동
		playerX = newX;
		playerY = newY;

		// 새 위치에 플레이어 그림
		gotoxy(playerX, playerY);
		std::cout << '@';
	}
}