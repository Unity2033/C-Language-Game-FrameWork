#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

enum color_index 
{
	Black,  // ����
	Blue,   // �Ķ�
	Green,  // �ʷ�
	Silver, // ����
	Red,    // ����
	Often,  // ����
	Yellow, // ���
	White,  // ���
	Gray,   // ȸ��
	Bright_Blue,   // ���� �Ķ�
	Bright_Green,  // ���� �ʷ�
	Bright_Jade,   // ���� ����
	Bright_Red,    // ���� ����
	Bright_Often,  // ���� ����
	Bright_Yellow, // ���� ���
	Bright_White   // ���� Ⱥ��
};

void Random(int Create_Value, int Value)
{
    // time = 1970�� 1�� 1�� 0�� (UTC)���� ������� �帥 �ð��� ��ȯ�մϴ�.
	// ������ ���̸�, ���� ���� �帥 �ð��� ���ϱ� ���� NULL�� �����մϴ�.

	srand(time(NULL));

	for (int i = 1; i <= Create_Value; i++) // Create_Value = ������Ű�� ���� ���� ��
	{
		printf("%d\n", (rand() % Value) + 1); // Value = �ִ� ũ���� ���� ���� �������ִ� ��
	}
}

void gotoxy(int x, int y) // x, y ��ǥ�� �����ϴ� �Լ�
{
	COORD pos = { x,y }; // x, y ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // ��ǥ ��ġ �̵� 
}

void Clear() // ȭ���� ����� �Լ�
{
	system("cls");
}

void Cursor(bool show) // bool = true(Ŀ�� ON), bool = false(Ŀ�� OFF)
{
	// cursor_info.bVisible = Ŀ�� ���� ���ο� ���� ����
	// SetConsoleCursorInfo = �����Ǿ� �ִ� �ܼ� ��ũ�� ���ۿ� ���Ͽ� Ŀ���� ���¸� �����ϴ� �Լ�

	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	cursor_info.bVisible = show; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Size(int width, int Height) // ȭ���� ũ�⸦ �������ִ� �Լ�
{
	// sprintf_s = ����ϴ� ��� ���� ������ �����ϴ� �Լ��̴�.
	// command <- "mode con: cols=%d lines=%d"���� command ���� "mode con: cols=%d lines=%d �̶�� ���� ����ȴ�."
	// cols=%d(����), lines=%d(����) 
	// width, Height �� �Է��� �Ű������� ȭ���� ũ�⸦ �����Ѵ�.
	// system �Լ��� Windows CMD ��ɹ��� �����ϴ� �Լ��ν� ȭ���� ũ�Ⱑ ��Ÿ����.

	char command[100]; // Window CMD ��ɾ ���� ���� �迭�Դϴ�.
	sprintf_s(command, "mode con: cols=%d lines=%d", width, Height);
	system(command);
}

void Road_Text(const char * text) // �ؽ�Ʈ ������ �ҷ����� �Լ�
{
	FILE* file = fopen(text,"r"); // �ܺο� �ִ� �ؽ�Ʈ ������ r(�б�) ���� ����
	char buffer[10000] = { 0, };

	// buffer = char �迭
	// 1 = ũ�⸦ ������ �迭�� ����Ű�� ������ 
	// 1000 = �о���� ������ ũ��� ������ ����Ʈ�̸�, size�� 4 �̸� �ϳ��� ������ ũ��� 4 ����Ʈ�̴�.
	// file = �����͸� �Է¹��� ��Ʈ���� FILE ��ü�� ����Ű�� ������

	fread(buffer, 1, 10000, file); // ��ü �б�
	printf("%s", buffer);

	fclose(file); // ���� �ݱ�
}

void Color(color_index index) // �ؽ�Ʈ ������ �������ִ� �Լ�
{
	// index = ����ǥ ��ȣ�� �Է��ϸ� �˴ϴ�.	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index);
}