#include "recite.h"
#include "screen.h"

#define ALLRIGHT "��ϲ�㣬ȫ����ȷ"

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
    system("title ��Ԫ����");
    system("cls");
    system("color 80");
    ShowCursorA();
    //�����ʳ�ʼ��
    Ini_recite();
    //������Ϣ��
    Message_recite();
    Order();
    do{
        //������ʾ��
        PrintWord();
        //����
        Input_recite();
        //�ж�
        Judge();
        //������һ������
        Order();
    }while(reciting.state);
    HideCursor();
    //����
    Save_recite();
    //����
    Put_log();
    //�������
    ShowErr();
    Is_next();
}
//�����ʳ�ʼ��
void Ini_recite(){
    int i;
    reciting.indexs = Get_Word_num(menu.unit);
    reciting.index = 0 , reciting.n = -1 , reciting.state = 1;
    reciting.right_ = reciting.wrong_ = 0;
    for(i = 0 ; i < 100 ; i++)
        reciting.cor[i] = reciting.err[i] = 0;
}
//������Ϣ��
void Message_recite(){
    tab(2,7 * 16 + 0);
        printf("%10s��ǰ��Ԫ%10s����˳��%8s������д(repeat)%12s\n","","","","");
    tab(2,11 * 16 + 0);
        printf("%11sUnit %2d%12s","",menu.unit,"");
        if(menu.order == 1){
            printf("˳��%14s","");
        }else{
            printf("���%14s","");
        }
        if(reciting.repeat){
            printf("��%22s","");
        }else{
            printf("��%22s","");
        }
        printf("\n\n");
    tab(2,Color_bg_word);
        printf("ESC");
    color(Color_bg_home+15);
        printf("  �������в�����\t");
        printf("�Ƿ������д(repeat)����");
    color(Color_bg_word);
        printf("����");
    color(Color_bg_home+15);
        printf("�и���\n");
}
//��������
void Order(){
    short i = 0;
    //˳��
    if(menu.order == 1){
        do{
            reciting.n ++;
        }while(mark[(menu.unit)-1][reciting.n] || reciting.cor[reciting.n]);
    }
    //���
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
    //���н���
    if(reciting.index > reciting.indexs || reciting.n > reciting.indexs){
        reciting.state = 0;
        return;
    }
    //��ֵ
    strcpy(reciting.en,word[(menu.unit)-1][reciting.n]);
    strcpy(reciting.ch,letter[(menu.unit)-1][reciting.n]);
    ChangePhr(reciting.n);
}
//��ӡ��������
void PrintWord(){
    color(Color_bg_home + 15);
        printf("\t\t-----------------------------------------\n");
        printf("\t\t��  ��\b\b\b\b");
    color(Color_bg_home+14);
        printf("%2d\n",reciting.index);
    //����
    color(Color_phr);
        printf("\t\t  %-6s",reciting.phr);
    //����
    color(Color_ch);
        printf(" %-30s",reciting.ch);
    color(Color_bg_home);
        printf("\n\t\t\t");
    //����
    color(Color_input);
        printf("%31s\r\t\t\t ","");
}
//�ж�
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
//��ȷ��һ��
void Right(){
    ///��ӡ����
    tab(2,Color_tgreen);
        printf("  ");
    color(Color_bg_home);
        printf("      ");
    color(Color_tgreen);
        printf("%-31s","");
    color(Color_bg_home);
        printf("\n");
}
//�����ƨ��
void Wrong(){
    color(16 * 7 + 15 );
        if(reciting.repeat)
            printf("\r\t\t%68s\r","");
    ///��ӡ����
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
//�������
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
        printf("  �ѹ�");
    tab(1,Color_red);
        printf(" ");
    color(Color_bg_home);
        printf("  ����");
    tab(1,Color_green);
        printf(" ");
    color(Color_bg_home);
        printf("  ��ȷ");
    tab(1,Color_white);
        printf(" ");
    color(Color_bg_home);
        printf("  δ����\n");
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
        printf("\n\n\t\t��һ������  ������\b\b\b\b\b\b\b\b");
        //�������
        Role_num(reciting.wrong_,79,Color_bg_home);
        printf("\t\t�����  ������\b\b\b\b\b\b\b\b");
        //�������
        Role_num(reciting.right_,47,Color_bg_home);
        printf("\n");
}
//�������������е㱻д���ˣ������˵�����þ���
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
        char operation=getch();  /*������� awsd;*/
        if((operation <= 'z' && operation >= 'a')||operation == ' '||operation == '-'){
            printf("%c",operation);
            reciting.input[i] = operation;
            return 1;
        }
        switch(operation){
        //����
        case 75:
            if(i)
                printf("\b");
            return 2;
            break;
        //����
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
        //�س�
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
//����
void Save_recite(){
    int i;
    for(i = 0 ; i < reciting.indexs ; i++){
        if(reciting.err[i])
            err[menu.unit-1][i]++;
        else if(reciting.cor[i])
            bingo[menu.unit-1][i]++;
    }
}
//��һ�ط�
void Is_next(){
    color(Color_bg_home);
        printf("\n\n");
    tab(4,Color_tskyblue );
        printf("  �Ƿ������һ��Ԫ  ");
    color(Color_bg_home);
        printf("\n");
    reciting.state = menu.state= 1;
    do{
        printf("\r");
        tab(4,Color_bg_word);
        if(reciting.state == 1 )
            color(Color_selected);
            printf("    ��    ");
        color(Color_bg_word);
        if(reciting.state == 2 )
            color(Color_selected);
            printf("    ��    ");
        Control_home(4);
    }while(menu.state);
    if(reciting.state == 1 ){
        menu.unit = menu.unit % 10 + 1;
        Recite();
    }
}

