#include "recite.h"
#include "screen.h"
///����������ɫ����
int color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

///�ƶ����
void Goto(short x, short y){
    if(x<0)
        x=0;
    if(y<0)
        y=0;
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
///����
void tab(short x, short pre){
    short i;
    color(7);
    for(i=0;i<x;i++)
        printf("\t");
    color(pre);
}
///������
void bar(short x, short pre){
    color(x);
    printf("|");
    color(pre);
}
///����ͬ���Ļ������ʹ��ڴ�С��������ֹ�����
void SetSize(short x, short y)  {
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
   	SMALL_RECT rc = {0, 0, x-1, y-1};
   	SetConsoleWindowInfo(hOut, 1, &rc);
   	SetConsoleScreenBufferSize(hOut, pos);
}
//�������ع�꺯��
void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
//�������ع�꺯��
void ShowCursorA(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = TRUE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
//��̬������
void Role_num(short num , short x , short pre){
    color(x);
    short i,roltime;
    if(num) roltime = 2000 / num;
    if(num < 9)
        roltime = 100;
    printf(" 0");
    for(i = 0 ; i <= num ; i++){
        printf("\b\b%2d",i);
        Sleep(roltime);
    }
    color(pre);
}

short Get_Word_num(short unit){
    short num = 0;
    while(word[unit-1][num][0] >= 'a' && word[unit-1][num][0] <= 'z')
        num++;
    return num;
}



