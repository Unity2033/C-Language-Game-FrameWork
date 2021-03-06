#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

const char bar = '='; // 프로그레스바 문자
const char blank = ' '; // 비어있는 프로그레스바 문자

float tick = (float)100 / 20; // 몇 % 마다 프로그레스바 추가할 지 계산
int bar_count; // 프로그레스바 갯수 저장 변수
float percent; // 퍼센트 저장 변수

enum color_index 
{
	Black,  // 검정
	Blue,   // 파랑
	Green,  // 초록
	Silver, // 은색
	Red,    // 빨강
	Often,  // 자주
	Yellow, // 노랑
	White,  // 흰색
	Gray,   // 회색
	Bright_Blue,   // 밝은 파랑
	Bright_Green,  // 밝은 초록
	Bright_Jade,   // 밝은 옥색
	Bright_Red,    // 밝은 빨강
	Bright_Often,  // 밝은 자주
	Bright_Yellow, // 밝은 노랑
	Bright_White   // 밝은 횐색
};

void Random(int Create_Value, int Value)
{
    // time = 1970년 1월 1일 0시 (UTC)부터 현재까지 흐른 시간을 반환합니다.
	// 단위는 초이며, 현재 까지 흐른 시간을 구하기 위해 NULL을 전달합니다.

	srand(time(NULL));

	for (int i = 1; i <= Create_Value; i++) // Create_Value = 생성시키고 싶은 랜덤 수
	{
		printf("%d\n", (rand() % Value) + 1); // Value = 최대 크기의 랜덤 값을 지정해주는 수
	}
}

void gotoxy(int x, int y) // x, y 좌표를 정의하는 함수
{
	COORD pos = { x,y }; // x, y 좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 좌표 위치 이동 
}

void Clear() // 화면을 지우는 함수
{
	system("cls");
}

void Cursor(bool show) // bool = true(커서 ON), bool = false(커서 OFF)
{
	// cursor_info.bVisible = 커서 노출 여부에 대한 변수
	// SetConsoleCursorInfo = 지정되어 있는 콘솔 스크린 버퍼에 대하여 커서의 형태를 설정하는 함수

	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	cursor_info.bVisible = show; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Size(int width, int Height) // 화면의 크기를 지정해주는 함수
{
	// sprintf_s = 출력하는 결과 값을 변수에 저장하는 함수이다.
	// command <- "mode con: cols=%d lines=%d"으로 command 에는 "mode con: cols=%d lines=%d 이라는 값이 저장된다."
	// cols=%d(가로), lines=%d(세로) 
	// width, Height 에 입력한 매개변수로 화면의 크기를 결정한다.
	// system 함수는 Windows CMD 명령문을 실행하는 함수로써 화면의 크기가 나타난다.

	char command[100]; // Window CMD 명령어를 담을 문자 배열입니다.
	sprintf_s(command, "mode con: cols=%d lines=%d", width, Height);
	system(command);
}

void Load_Text(const char * text) // 텍스트 파일을 불러오는 함수
{
	FILE* file = fopen(text,"r"); // 외부에 있는 텍스트 파일을 r(읽기) 모드로 열기
	char buffer[10000] = { 0, };

	// buffer = char 배열
	// 1 = 크기를 가지는 배열을 가리키는 포인터 
	// 10000 = 읽어들일 원소의 크기로 단위는 바이트이며, size가 4 이면 하나의 원소의 크기는 4 바이트이다.
	// file = 데이터를 입력받을 스트림의 FILE 객체를 가리키는 포인터

	fread(buffer, 1, 10000, file); // 전체 읽기
	printf("%s", buffer);

	fclose(file); // 파일 닫기
}

void Typing(const char * text)
{
	int i = 0;

	while (text[i] != 0)
    {
	   printf("%c", text[i++]);
	   fflush(stdout);
	   Sleep(10);
    }
}

void Color(color_index index) // 텍스트 색상을 변경해주는 함수
{
	// index = 색상표 번호를 입력하면 됩니다.	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index);
}
