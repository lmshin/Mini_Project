#include "Utilities.h"

//������
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

// �÷��̾� ���� ��ġ
int playerX = 1;
int playerY = 1;


void clearScreen() {
	system("cls");  // �Ǵ� for (int i = 0; i < 30; ++i) cout << "\n";
}

// gotoxy �Լ� (Ŀ�� ��ġ �̵�)
void gotoxy(int x, int y) {
	COORD coord = { short(x), short(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#include "Utilities.h"

// �� �׸��� �Լ�
void drawMap() {
	for (int y = 0; y < MAP_HEIGHT; ++y) {
		gotoxy(0, y); // �� ���� �������� Ŀ�� �̵�
		std::cout << gameMap[y];
	}
}

// �÷��̾� �׸��� �� �̵� �Լ�
void updatePlayerPosition(int newX, int newY) {
	// �� ��� üũ �� �� �浹 üũ
	if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT &&
		gameMap[newY][newX] != '#') { // ���� �ƴϸ� �̵�

		// ���� ��ġ�� ��� �ǵ��� (Ȥ�� ���� �� Ÿ�Ϸ�)
		gotoxy(playerX, playerY);
		std::cout << '.'; // ���� ��ġ�� ��� �׸�

		// �� ��ġ�� �÷��̾� �̵�
		playerX = newX;
		playerY = newY;

		// �� ��ġ�� �÷��̾� �׸�
		gotoxy(playerX, playerY);
		std::cout << '@';
	}
}