#include "recite.h"
#include "login.h"
#include "screen.h"

char home_sentence[10][20]={
    "背单词","单词表","\b\b登录/更名\b"," 设置"," 重置","考试周"
    };
char unit_title[10][30]={"Leisure Activities","The Power of Words","Gender Differences","Creativity","Athletes","Risks","College Life","Time","Science and Technology","Literature"};
short Color_ch,
Color_word,
Color_phr,
Color_input,
Color_face,
Color_wrong;

void Select_mode();
short Control_home(short site);    ///获取键盘输入
void frame();   ///打印主页框架
short Get_length_of_mode();     ///加载项：获取主页项目个数
void Print_Select_unit(short x, short y);
void Select_unit();
void Select_order();
void Print_Select_order(short x,short y);

void home(){
    system("cls");
    system("title 主页");
    system("color 87");
    HideCursor();

    Get_length_of_mode();
    //主页主体
    Print_frame();
    //登录状态
    Print_profile(1,5);
    //更改选项
    Select_mode();
    return;
}
//主页主体
void Print_frame(){
    int i,pos_x = 0 ,pos_y = 30;
    menu.mode = 1;
    //顶部欢迎界面
    color(Color_bg_word);
        Goto(pos_y,pos_x);
        printf("%58s","");
        Goto(pos_y,pos_x+1);
        printf("%17s欢迎来到英语词汇复习练习%17s","","");
        Goto(pos_y,pos_x+2);
        printf("%22sW E L C O M E%23s","","");
        Goto(pos_y,pos_x+3);
        printf("%58s","");
    //操作提示栏
    color(Color_bg_home);
        Goto(pos_y,pos_x+5);
        printf("操作      ");
        color(Color_bg_home+14);
        printf("：更改选项        (回车)：进入");
        color(Color_bg_word);
        Goto(pos_y+6,pos_x+5);
        printf("↑↓");
        Goto(pos_y+22,pos_x+5);
        printf("ENTER");
    //左侧选项栏框架
    color(Color_bg_word);
        pos_x = 6 ,pos_y = 5;
        for(i = 0 ; i <= menu.count_mode * 3 + 1 ; i++){
            Goto(pos_y,pos_x + i);
            printf("%18s","");
        }
        Goto(pos_y + 6,pos_x + i + 1);
    //版本信息
    color(Color_bg_home);
        printf("v 2.0");    //2020.3.8
    //选项栏信息
    color(Color_option);
        for(i = 0 ; i < menu.count_mode ; i++){
            Goto(pos_y + 4, pos_x + i * 3 + 2);
            printf("  %-6s  ",home_sentence[i]);
        }
}
//选择模式
void Select_mode(){
    menu.state = 1;
    //打印被选择状态
    color(Color_selected);
        Goto(9 , menu.mode * 3 + 5);
        printf("  %-6s  ",home_sentence[menu.mode - 1]);
    //获取键盘输入
    Control_home(1);
    //判断是否结束（递归）
    if(menu.state == 1)
        Select_mode();
}
//取消选择
void Back_mode(){
    color(Color_option);
        Goto(9 , menu.mode * 3 + 5);
        printf("  %-6s  ",home_sentence[menu.mode - 1]);
}
//总控
short Control_home(short site){
    char operation = getch();  /*键入操作 awsd;*/
    if(site == 1)
        Back_mode();
    if(site == 2)
        Back_unit();
    if(site == 5)
        Back_state(1);
    switch(operation){
    /*向上*/
    case 72:case 'w':case 'W':
        if(site == 1){
            menu.mode += menu.mode>1 ? -1:0;
        }
        else if(site == 2){
            if(menu.unit != 1 && menu.unit != 6)
                menu.unit -- ;
        }
        else if(site == 5){
            reciting.index += reciting.index>0 ? -1:0;
        }else if(site == 6){
            if(menu.setting < 10){
                Back_state(2);
                menu.setting = 10;
            }
        }
        break;
    /*向下*/
    case 80:case 's':case 'S':
        if(site == 1){
            menu.mode += menu.mode<menu.count_mode ? 1:0;
        }
        else if(site == 2){
            if(menu.unit != 5 && menu.unit != 11)
                menu.unit ++;
            else
                menu.unit = 11;
        }
        else if(site == 5){
            reciting.index += reciting.index<reciting.indexs-1 ? 1:0;
        }else if(site == 6){
            if(menu.setting >= 10){
                Back_state(2);
                menu.setting = 1;
            }
        }
        break;
    case 77:case 'd':case 'D':
        if(site == 2){
            menu.unit += menu.unit<=5 ? 5:0;
        }
        else if(site == 3){
            menu.order = 2;
        }
        else if(site == 4){
            reciting.state = 2;
        }
        else if(site == 6){
            if(menu.setting < 4){
                Back_state(2);
                menu.setting ++;
            }else if(menu.setting < 9){
                Back_state(2);
                menu.setting = 9;
            }
        }else if(site == 7){
                menu.setting = 2;
        }
        break;
    case 75:case 'a':case 'A':
        if(site == 2){
            if(menu.unit >= 6 && menu.unit != 11)
                menu.unit -= 5;
            else if(menu.unit == 11)
                menu.unit = 5;
        }
        else if(site == 3){
            menu.order = 1;
        }
        else if(site == 4){
            reciting.state = 1;
        }
        else if(site == 6){
            if(menu.setting <= 4 &&menu.setting > 1){
                Back_state(2);
                menu.setting --;
            }else if(menu.setting == 9)
                menu.setting = 4;
        }else if(site == 7){
                menu.setting = 1;
        }
        break;
    //回车
    case 13:
        menu.state = 0;
        if(site == 5 ){
            menu.state = 1;
            if(mark[menu.unit-1][reciting.index])
                mark[menu.unit-1][reciting.index] = 0;
            else
                mark[menu.unit-1][reciting.index] = 1;
        }else if(site == 6){
            if(menu.setting < 10){
                switch(menu.setting){
                case 1:
                    Color_ch = (Color_ch+1)%255;
                    break;
                case 2:
                    Color_input = (Color_input+1)%255;
                    break;
                case 3:
                    Color_wrong = (Color_wrong+1)%255;
                    break;
                case 4:
                    Color_phr = (Color_phr+1)%255;
                    break;
                case 9:
                    Color_ini();
                    break;
                }
            }else{
                reciting.repeat = reciting.repeat?0:1;
            }
            Update_setting_state(12,30);
        }
        return 0;
    case 27:
        menu.state = 0 ;
        return;
    default:
        break;
    }//end switch
    if(site == 6)
        Update_setting_state(12,30);
    return 1;
}

short Get_length_of_mode(){
    int i=0;
    while(home_sentence[i][0] < 0 || home_sentence[i][0] == ' ' ||home_sentence[i][0] == '\b')
        i++;
    menu.count_mode = i ;
}
//选择单元主体
void Print_Select_unit(short x , short y){
    int pos = 6;
    int i;
    //背景框架
    color(Color_bg_word);
        for(i = 0 ; i < 15 ; i++){
            Goto(y,x+i);
            printf("%58s","");
        }
    color(Color_bg_home + 15);
        Goto(y+18,x+1);
        printf("%16s      ","请选择单元");
    color(Color_option);
        for(i = 0; i < 5 ;i ++){
            Goto(y+1,x+i*2+3);
            printf("%2d. %-23s",i+1,unit_title[i]);
            Goto(y+30,x+i*2+3);
            printf("%2d. %-23s",i+6,unit_title[i+5]);
        }
    color(Color_option);
        Goto(y+18,x+i*2+3);
        printf("%9s%4s%10s","","返回","");
}
//选择单元
void Select_unit(){
    menu.state = 1;
    color(Color_selected);
        if(menu.unit <= 5){
            Goto(35,9 + menu.unit*2);
            printf("%-23s",unit_title[menu.unit-1]);
        }else if(menu.unit <= 10){
            Goto(64,menu.unit*2 - 1);
            printf("%-23s",unit_title[menu.unit-1]);
        }else{
            color(Color_cancel);
                Goto(48,menu.unit*2 - 1);
                printf("%9s%4s%10s","","返回","");
        }
    Control_home(2);
    if(menu.state == 1)
        Select_unit();
}
//取消选择（单元）
void Back_unit(){
    int i ;
    for(i = 0 ; i < 23 ; i++)
        printf("\b");
    color(Color_option);
        if( menu.unit <= 10)
            printf("%-23s",unit_title[menu.unit-1]);
        else
            printf("%9s%4s%10s","","返回","");
}
//选择顺序
void Select_order(){
    menu.state   = menu.order = 1;
    do{
        Print_Select_order(11,38);
        Control_home(3);
    }while(menu.state);
}
//打印选择顺序
void Print_Select_order(short x, short y){
    color(Color_bg_home);
        Goto(y,x);
        printf("%41s","");
        Goto(y,x+1);
        printf("          ");
    color(Color_bg_home + 15);
        printf("        出词顺序     ");
    color(Color_bg_home);
        printf("          ");
        Goto(y,x+2);
        printf("%41s","");
        Goto(y,x+3);
        printf("       ");
    color(Color_option);
    if(menu.order == 1)
        color(Color_selected);
        printf("     顺序     ");
    color(Color_option);
    if(menu.order == 2)
        color(Color_selected);
        printf("     随机     ");
    color(Color_bg_home);
        printf("      ");
        Goto(y,x+4);
        printf("%41s","");
}

void Color_ini(){
    Color_face = Color_tskyblue;
    Color_phr =16 * 7 + 1;
    Color_ch = 5 + 16 * 14;
    Color_input = 16 * 7 + 0;
    Color_wrong = 0 + 16 * 11;
}


