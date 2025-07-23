#pragma once // ��� ������ ���� �� ���ԵǴ� ���� ����

#include <vector>   // std::vector�� std::string�� ����
#include <string>   // std::string�� ����
#include <iostream> // std::cout�� ����
#include <windows.h> // COORD, GetStdHandle, SetConsoleCursorPosition�� ���� (Windows ����)

// ���� �� ������ (�� ���� �Լ����� ����ϹǷ� ���⿡ �δ� ���� ��)
extern const int MAP_HEIGHT; // �ܺο��� ���ǵ� ������� �˸�
extern const int MAP_WIDTH;  // �ܺο��� ���ǵ� ������� �˸�
extern std::vector<std::string> gameMap; // �ܺο��� ���ǵ� �������� �˸�

// �÷��̾� ���� ��ġ (�� ���� �Լ����� ����ϹǷ� ���⿡ �δ� ���� ��)
extern int playerX;
extern int playerY;

// --- ��ƿ��Ƽ �Լ� ���� ---
void clearScreen();
void gotoxy(int x, int y);
void drawMap();
void updatePlayerPosition(int newX, int newY);