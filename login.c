#include "recite.h"
#include "login.h"
#include "screen.h"

void Login(){
    if(!If_file_exist){
        If_file_exist = 1;

    }
    Print_login(7,40);
    Put_log();
    Print_loading(7,40);
}

void Print_login(short x , short y){
    int i = 0;
    color(16 * 11 + 5);
        for(i = 0 ; i<5 ; i++){
            Goto(y,x+i);
            printf("%44s","");
        }
        Goto(y,x+1);
        printf("         给自己起个响亮的英文名吧           ");
    color(Color_option);
        Goto(y+14,x+3);
        printf("%15s","");
    //获取输入信息
    Goto(y+14,x+3);
    ShowCursorA();
    gets(menu.name);
    if(!strcmp(menu.name,"") || !strcmp(menu.name," "))
        strcpy(menu.name , "NULL");
    HideCursor();
}
//显示登录过程（炫技用）
void Print_loading(short x ,short y ){
    int i = 0;
    color(16 * 11 + 8);
        for( i = 0 ; i < 7 ; i++){
            Goto(y,x+i);
            printf("%44s","");
        }
        Goto(y,x+1);
        printf("%19s登录中%19s","","");
    Goto(y+4,x+3);
    for(i = 0 ; i < 18 ; i++){
        color(Color_green);
            printf(" ");
        color(Color_tskyblue);
            printf(" ");
        Sleep(80);
    }
        Goto(y,x+1);
        printf("%18s登录成功%18s","","");
    color(Color_selected);
        Goto(y+18,x+5);
        printf("  确定  ");
    getch();
}
//登录状态
void Print_profile(short x , short y){
    if(If_file_exist)
        color(Color_tskyblue);
    else
        color(Color_white);
        Goto(y,x);
        printf("%6s","");
        Goto(y,x+1);
        printf("%6s","");
        Goto(y,x+2);
        printf("%6s","");
    color(Color_tblack);
        Goto(y+1,x+1);
        printf(" ");
        Goto(y+4,x+1);
        printf(" ");
    if(If_file_exist)
        color(16 * 12);
    else
        color(Color_bg_word);
        Goto(y+2,x+2);
        printf("  ");
    if(If_file_exist){
        color(Color_bg_home +15);
            Goto(y+1,x+3);
            printf("欢迎！ ");
        color(Color_white);
            printf(" %-9s",menu.name);
            Goto(y+7,x+1);
        color(Color_tgreen + 5);
            printf("  已登录  ");
    }else{
        color(Color_bg_word + 8);
            Goto(y+7,x+1);
            printf("  未登录  ");
    }
}

void Setting(){
    menu.setting = 10;
    Print_setting(12,30);
    Update_setting_state(12,30);
    Put_log();
}
//设置模块
void Print_setting(short x, short y){
    int i = 0;
    color(Color_bg_word);
        Goto(y+4,x-2);
        printf(" ↑ ↓ ← →：控制\tENTER：更改\tESC：返回 ");
        for(i = 0 ;i < 9;i++){
            Goto(y,x+i);
            printf("%58s","");
        }
    //设置框架
    color(Color_bg_home);
        while(i < 15){
            Goto(y,x+i);
            printf("%58s","");
            i++;
        }
    color(Color_bg_word + 12);
        Goto(y+2,x+1);
        printf("● ");
    color(Color_bg_word);
        printf("%s","拼 错 单 词 重 新 拼 写 （repeat）");
    color(Color_bg_word + 3);
        printf("         □");
    color(Color_bg_word + 12);
        Goto(y+2,x+3);
        printf("● ");
    color(Color_bg_word);
        printf("颜 色 设 置");
        Goto(y+2,x+4);
        printf("\t中文\t输入\t校正\t词性");
        Goto(y+10,x+5);
    color(Color_ch);
        printf("demo");
    color(Color_input);
        Goto(y+18,x+5);
        printf("demo");
    color(Color_wrong);
        Goto(y+26,x+5);
        printf("demo");
    color(Color_phr);
        Goto(y+34,x+5);
        printf("demo");
    color(Color_bg_word + 3);
        Goto(y+11,x+6);
        printf("□%6s□%6s□%6s□%5s","","","","");
    color(Color_white);
        printf("恢复默认");
    color(Color_bg_word);
        Goto(y+4,x+8);
        printf("示 例");
}

void Update_setting_state(short x, short y){
    Goto(y+42,x+1);
    if(reciting.repeat){
        color(16 * 11 + 0);
        printf(" 是 ");
    }else{
        color(Color_bg_home + 0);
        printf(" 否 ");
    }
    color(Color_ch);
        Goto(y+10,x+5);
        printf("demo");
    color(Color_input);
        Goto(y+18,x+5);
        printf("demo");
    color(Color_wrong);
        Goto(y+26,x+5);
        printf("demo");
    color(Color_phr);
        Goto(y+34,x+5);
        printf("demo");
    if(menu.setting == 9)
        color(Color_purple);
    else
        color(Color_twhite);
        Goto(y+42,x+6);
        printf("恢复默认");
    color(Color_bg_home);
        Goto(y+4,x+9);
        printf("第 0个");
    color(Color_phr);
        Goto(y+5,x+10);
        printf("yysy.");
    color(Color_ch);
        Goto(y+14,x+10);
        printf("%-30s"," 你 真 帅");
    color(Color_input);
        Goto(y+14,x+11);
        printf("%-30s"," thank you");
    color(Color_wrong);
        Goto(y+14,x+12);
        printf("%-30s"," you are welcome");
    color(Color_bg_word + 5);
        if(menu.setting < 9){
            Goto(y+menu.setting*8+3,x+6);
        }else if(menu.setting == 10){
            Goto(y+48,x+1);
        }
        if(menu.setting != 9)
            printf("●");
    Control_home(6);
}

void Reset(){
    menu.state = 1 ,menu.setting = 2;
    color(Color_bg_word);
        Goto(30,18);
        printf("  确认重置吗？重置后答题记录将被清空  ");
    do{
        color(Color_bg_word);
        if(menu.setting == 1)
            color(Color_green + 15);
            Goto(40,20);
            printf("  确认  ");
        color(Color_bg_word);
        if(menu.setting == 2)
            color(Color_cancel);
            printf("  取消  ");
        Control_home(7);
    }while(menu.state);
    //毁灭数据，重头再来
    if(menu.setting == 1){
        Ini();
        Put_log();
    }
}
