#ifndef RECITE_H_INCLUDED
#define RECITE_H_INCLUDED


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
//µ¥´Ê³¤¶È
#define WORDLENGTH 25
#define LETTERLENGTH 80

extern const char word[10][100][25];
extern const char letter[10][100][80];
extern const int phrase[10][100];
extern short mark[10][100],err[10][100],bingo[10][100];

extern short If_file_exist;

struct reciting{
    int index , indexs , n;
    char input[40];
    char en[WORDLENGTH],ch[LETTERLENGTH],phr[10];
    int right_,wrong_;
    int err[100] , cor[100];
    int state , repeat;
};
extern struct reciting reciting;

void Color_ini();
void Recite();
void Show_word();


short Get_Word_num(short unit);


int color(int c);
void tab(short x,short pre);
void SetSize(short x, short y);
void HideCursor();
void ShowCursorA();

void Goto(short x , short y);
void bar(short x,short pre);

#endif // RECITE_H_INCLUDED
