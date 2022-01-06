﻿#define _CRT_SECURE_NO_WARNINGS
#include "Function.h"

static int Count = 0;

const char bar = '='; // 프로그레스바 문자
const char blank = ' '; // 비어있는 프로그레스바 문자

int count = 0; 

float tick = (float) 100 / 20; // 몇 % 마다 프로그레스바 추가할 지 계산
int bar_count; // 프로그레스바 갯수 저장 변수
float percent; // 퍼센트 저장 변수
int Life = 0;

void Update() // 프레임 마다 업데이트를 해야 하는 함수
{
    char key;
    int y = 29;
    int x = 0;

    Road_Text("Screen.txt");

    while (count <= 100)
    {
        printf("\r\t\t\t      %d/%d [",count, 100); // 진행 상태 출력
        percent = (float)count / 100 * 100; // 퍼센트 계산
        bar_count = percent / tick; // 프로그레스바 갯수 계산

        for (int i = 0; i < 20; i++) // LEN 길이의 프로그레스바 출력
        {
            if (bar_count > i) // 프로그레스바 길이보다 i가 작으면
            {
                printf("%c", bar);
            }
            else // i가 더 커지면
            {
                printf("%c", blank);
            }
        }

        printf("] %0.2f%%", percent); // 퍼센트 출력

        count += 1;
        Sleep(10);    
    }

    while (1)
    {         
        gotoxy(x, y);
        printf("☞");

        if (x > 0)
        {
            key = _getch();

            if (key == -32)
            {
                key = _getch();

                switch (key)
                {
                   case 72 : if (--y < 29) y = 29; break;
                   case 80 : if (++y > 30) y = 30; break;
                }
            }
        }  

        if (GetAsyncKeyState(VK_SPACE))
        {
            Sleep(100);

            if (Life == 0)
            {
                if (y == 29) Count += 1;
                if (y == 30) Count += -10;
            }
            else
            {
                if (y == 29)
                {
                    Life = 0;
                    Count = 0;
                }
                if (y == 30) exit(0);
            }     
        }

        x = 54;

        Clear();

        switch (Count)
        {
            case 0 : 
                Road_Text("Start.txt");
                break;
            case 1 : 
                Road_Text("City.txt"); 
                break;
            case -10 : 
                Road_Text("Model.txt"); 
                break;
            case 2 :
                Road_Text("Statue.txt"); 
                break;
            case -20 : 
                Road_Text("Footprint.txt");
                break;
            case 3 :
                Road_Text("Map.txt");
                break;           
            case -30:
                Road_Text("Map.txt");
                break;
            case -7 :
           
                Sleep(5000);
                return;
            default :
                Road_Text("Death.txt");
                Life = 1;           
        }            
    }
}

int main()
{
    Size(100, 50);  

    system("title metro 2033");

    PlaySound(TEXT("Sound.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생

    Update();

    Road_Text("End.txt");

    return 0;
}