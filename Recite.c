#include "recite.h"
#include "screen.h"

#define ALLRIGHT "恭喜你，全部正确"

struct reciting reciting;

void Ini_recite();
    void Order();
    void PrintWord();
    void Input_recite();
        short Control_recite(short i , short input_num);
        short Get_input_num(char *input);
    void Judge();
        void Right();
        void Wrong();
    void ShowErr();
void Is_next();
void Save_recite();

void Recite(){
    system("title 单元背诵");
    system("cls");
    system("color 80");
    ShowCursorA();
    //背单词初始化
    Ini_recite();
    //顶部信息栏
    Message_recite();
    Order();
    do{
        //中文提示词
        PrintWord();
        //输入
        Input_recite();
        //判断
        Judge();
        //检索下一个单词
        Order();
    }while(reciting.state);
    HideCursor();
    //结账
    Save_recite();
    //保存
    Put_log();
    //秋后算账
    ShowErr();
    Is_next();
}
//背单词初始化
void Ini_recite(){
    int i;
    reciting.indexs = Get_Word_num(menu.unit);
    reciting.index = 0 , reciting.n = -1 , reciting.state = 1;
    reciting.right_ = reciting.wrong_ = 0;
    for(i = 0 ; i < 100 ; i++)
        reciting.cor[i] = reciting.err[i] = 0;
}
//顶部信息栏
void Message_recite(){
    tab(2,7 * 16 + 0);
        printf("%10s当前单元%10s出词顺序%8s错误重写(repeat)%12s\n","","","","");
    tab(2,11 * 16 + 0);
        printf("%11sUnit %2d%12s","",menu.unit,"");
        if(menu.order == 1){
            printf("顺序%14s","");
        }else{
            printf("随机%14s","");
        }
        if(reciting.repeat){
            printf("是%22s","");
        }else{
            printf("否%22s","");
        }
        printf("\n\n");
    tab(2,Color_bg_word);
        printf("ESC");
    color(Color_bg_home+15);
        printf("  结束背诵并保存\t");
        printf("是否错误重写(repeat)可在");
    color(Color_bg_word);
        printf("设置");
    color(Color_bg_home+15);
        printf("中更改\n");
}
//检索单词
void Order(){
    short i = 0;
    //顺序
    if(menu.order == 1){
        do{
            reciting.n ++;
        }while(mark[(menu.unit)-1][reciting.n] || reciting.cor[reciting.n]);
    }
    //随机
    else if (menu.order == 2){
        srand((unsigned)time(NULL));
        do{
            reciting.n = rand() % reciting.indexs;
            i++;
            if(i >= 20)
                reciting.state = 0;
        }while(( mark[(menu.unit)-1][reciting.n] || reciting.cor[reciting.n] )&& i < 20);
    }
    reciting.index ++;
    //背诵结束
    if(reciting.index > reciting.indexs || reciting.n > reciting.indexs){
        reciting.state = 0;
        return;
    }
    //赋值
    strcpy(reciting.en,word[(menu.unit)-1][reciting.n]);
    strcpy(reciting.ch,letter[(menu.unit)-1][reciting.n]);
    ChangePhr(reciting.n);
}
//打印单词中文
void PrintWord(){
    color(Color_bg_home + 15);
        printf("\t\t-----------------------------------------\n");
        printf("\t\t第  个\b\b\b\b");
    color(Color_bg_home+14);
        printf("%2d\n",reciting.index);
    //词性
    color(Color_phr);
        printf("\t\t  %-6s",reciting.phr);
    //中文
    color(Color_ch);
        printf(" %-30s",reciting.ch);
    color(Color_bg_home);
        printf("\n\t\t\t");
    //输入
    color(Color_input);
        printf("%31s\r\t\t\t ","");
}
//判断
void Judge(){
    color(Color_bg_home);
        printf("\n");
    if( !strcmp(reciting.input,reciting.en) ){
        reciting.cor[reciting.n]++;
        reciting.right_++;
        Right();
    }else{
        reciting.err[reciting.n]++;
        reciting.wrong_++;
        Wrong();
    }
}
//正确绿一下
void Right(){
    ///打印绿条
    tab(2,Color_tgreen);
        printf("  ");
    color(Color_bg_home);
        printf("      ");
    color(Color_tgreen);
        printf("%-31s","");
    color(Color_bg_home);
        printf("\n");
}
//错误打屁股
void Wrong(){
    color(16 * 7 + 15 );
        if(reciting.repeat)
            printf("\r\t\t%68s\r","");
    ///打印红条
    tab(2,Color_red);
        printf("  ");
    color(Color_bg_home);
        printf("      ");
    color(Color_wrong);
        if(!reciting.repeat)
            printf(" %-30s",reciting.en);
        else
            printf(" %-21s",reciting.en);
    if(reciting.repeat && reciting.state){
        color(16 * 15 + 1);
            printf(" repeat: ");
            Input_recite();
        if(strcmp(reciting.input,reciting.en)){
            Wrong();
        }else{
            color(Color_bg_home);
                printf("\n");
        }
    }else{
        color(Color_bg_home);
            printf("\n");
    }
}
//秋后算账
void ShowErr(){
    short i;
    color(Color_bg_home);
        printf("\n\n");
    tab(2,Color_bg_home+0);
        printf("---------------------------------------------------------\n");
    for(i = 0 ; i < reciting.indexs ; i++){
        if(reciting.err[i]){
            tab(2,Color_bg_home+15);
                printf("%2d. ",i+1);
            color(Color_wrong);
                printf("% -18s\t",word[menu.unit-1][i]);
            color(Color_ch);
                printf("%-30s",letter[menu.unit-1][i]);
            color(Color_bg_home+7);
                printf("\n\t\t---------------------------------------------------------\n");
        }
    }
    tab(2,Color_purple);
        printf(" ");
    color(Color_bg_home);
        printf("  已过");
    tab(1,Color_red);
        printf(" ");
    color(Color_bg_home);
        printf("  错误");
    tab(1,Color_green);
        printf(" ");
    color(Color_bg_home);
        printf("  正确");
    tab(1,Color_white);
        printf(" ");
    color(Color_bg_home);
        printf("  未出现\n");
    tab(2,1);
        for(i = 0 ; i < reciting.indexs ; i++){
            if(mark[menu.unit-1][i])
                color(Color_purple);
            else if(reciting.err[i])
                color(Color_red);
            else if(reciting.cor[i])
                color(Color_green);
            else
                color(Color_white);
            printf(" ");
            Sleep(25);
        }
    color(Color_bg_home);
        printf("\n\n\t\t你一共错了  个单词\b\b\b\b\b\b\b\b");
        //花里胡哨
        Role_num(reciting.wrong_,79,Color_bg_home);
        printf("\t\t答对了  个单词\b\b\b\b\b\b\b\b");
        //花里胡哨
        Role_num(reciting.right_,47,Color_bg_home);
        printf("\n");
}
//下面三个函数有点被写残了，不想多说，能用就行
void Input_recite(){
    color(Color_input);
    short control , i = 0 ,input_num;
    for(i = 0 ; i < 40; i++)
        reciting.input[i] = '\0';
    i = 0;
    short pos;
    while(1){
        input_num = Get_input_num(reciting.input);
        control = Control_recite( i ,input_num);
        switch(control){
        case 1:
            break;
        case 2:
            if(i)
                i--;
            continue;
        case 3:
            if(i < input_num)
                i++;
            continue;
        case 8:
            if(i){
                for(pos = i; pos <= input_num ; pos++)
                    printf("\b");
                i-=2;
            }
            else
                i--;
            break;
        case 0:
            return;
            break;
        default:
            reciting.state = 0;
            return;
        }
        i++;

    }
}
short Control_recite(short i , short input_num){
    while(1){
        char operation=getch();  /*键入操作 awsd;*/
        if((operation <= 'z' && operation >= 'a')||operation == ' '||operation == '-'){
            printf("%c",operation);
            reciting.input[i] = operation;
            return 1;
        }
        switch(operation){
        //向左
        case 75:
            if(i)
                printf("\b");
            return 2;
            break;
        //向右
        case 77:
            if(i < input_num)
                printf("%c",reciting.input[i]);
            return 3;
            break;
        //backspace
        case 8:        //a b c
            if(i){
                printf("\b \b");
                for(i-- ; i < input_num ; i++){
                    reciting.input[i] = reciting.input[i+1];
                    printf("%c",reciting.input[i]);
                }
            }
            return 8;
            break;
        //回车
        case 13:
            return 0;
        case 27:
            return 9;
        default:
            break;
        }
    }
}
short Get_input_num(char *input){
    short i;
    for(i = 0;input[i] != '\0' ;i++);
    return i;
}
//算账
void Save_recite(){
    int i;
    for(i = 0 ; i < reciting.indexs ; i++){
        if(reciting.err[i])
            err[menu.unit-1][i]++;
        else if(reciting.cor[i])
            bingo[menu.unit-1][i]++;
    }
}
//下一关否
void Is_next(){
    color(Color_bg_home);
        printf("\n\n");
    tab(4,Color_tskyblue );
        printf("  是否进入下一单元  ");
    color(Color_bg_home);
        printf("\n");
    reciting.state = menu.state= 1;
    do{
        printf("\r");
        tab(4,Color_bg_word);
        if(reciting.state == 1 )
            color(Color_selected);
            printf("    是    ");
        color(Color_bg_word);
        if(reciting.state == 2 )
            color(Color_selected);
            printf("    否    ");
        Control_home(4);
    }while(menu.state);
    if(reciting.state == 1 ){
        menu.unit = menu.unit % 10 + 1;
        Recite();
    }
}

