#pragma once // 헤더 파일이 여러 번 포함되는 것을 방지

#include <vector>   // std::vector와 std::string을 위해
#include <string>   // std::string을 위해
#include <iostream> // std::cout을 위해
#include <windows.h> // COORD, GetStdHandle, SetConsoleCursorPosition을 위해 (Windows 전용)

// 전역 맵 데이터 (맵 관련 함수들이 사용하므로 여기에 두는 것이 편리)
extern const int MAP_HEIGHT; // 외부에서 정의될 상수임을 알림
extern const int MAP_WIDTH;  // 외부에서 정의될 상수임을 알림
extern std::vector<std::string> gameMap; // 외부에서 정의될 변수임을 알림

// 플레이어 현재 위치 (맵 관련 함수들이 사용하므로 여기에 두는 것이 편리)
extern int playerX;
extern int playerY;

// --- 유틸리티 함수 선언 ---
void clearScreen();
void gotoxy(int x, int y);
void drawMap();
void updatePlayerPosition(int newX, int newY);