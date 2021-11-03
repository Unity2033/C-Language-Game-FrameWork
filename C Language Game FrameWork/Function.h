#pragma once
#include <stdio.h>
#include <windows.h>


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

void Waiting(int Count) // ��� ���¸� ������ִ� �Լ�
{
	// Sleep(1000) = 1000ms (1��) ���� ���α׷� ���
    // 100 = 0.1��, 10000 = 10��

	Sleep(Count); // ��Ÿ��(���� ���� ��) ���α׷��� �Ͻ������� ����ϴ�.
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
	char buffer[1000] = { 0, };

	// buffer = char �迭
	// 1 = ũ�⸦ ������ �迭�� ����Ű�� ������ 
	// 1000 = �о���� ������ ũ��� ������ ����Ʈ�̸�, size�� 4 �̸� �ϳ��� ������ ũ��� 4 ����Ʈ�̴�.
	// file = �����͸� �Է¹��� ��Ʈ���� FILE ��ü�� ����Ű�� ������

	fread(buffer, 1, 1000, file); // ��ü �б�
	printf("%s", buffer);

	fclose(file); // ���� �ݱ�
}

void Color(int index) // �ؽ�Ʈ ������ �������ִ� �Լ�
{
	// index = ����ǥ ��ȣ�� �Է��ϸ� �˴ϴ�.
	// 0 = ����, 1 = �Ķ�, 2 = �ʷ�, 3 = ����, 4 = ����, 5 = ����, 6 = ���, 7 = Ⱥ��
	// 8 = ȸ��, 9 = ���� �Ķ�, 10 = ���� �ʷ�, 11 = ���� ����, 12 = ���� ����, 13 = ���� ����, 14 = ���� ���, 15 = ���� ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index);
}