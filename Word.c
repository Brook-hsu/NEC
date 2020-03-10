#include "recite.h"
#include "screen.h"

void Screen_show_word();
void Set_bg();
void Update_word_state();

void Show_word(){
    system("cls");
    //���ñ���
    Set_bg();
    system("title �鿴����");
    HideCursor();
    reciting.indexs = Get_Word_num(menu.unit);
    reciting.index = 0;
    Screen_show_word();
    Goto(0,0);
    if(If_file_exist)
        Update_word_state();
    //δ��¼ɶҲ�ɲ���
    else
        getchar();
    //����
    Put_log();
}
/**To do :
  *���ñ���
  *Ԥ�ڹ��ܣ��û��������и��ı���
  */
void Set_bg(){
    char handle[10]="color 70";
    if(Color_bg_word/16 < 10)
        handle[6] = Color_bg_word/16+'0';
    else
        handle[6] = Color_bg_word/16-10+'A';
    system(handle);
}
//����ҳ����
void Screen_show_word(){
    short i;
    //��������״̬��
    tab(1,16 * 9 + 0);
        printf("%68s\n","");
    tab(1,16 * 9 + 0);
        printf("%27s��  ��  ��  ��%27s\n","","");
    tab(1,16 * 9 + 0);
        printf("%68s\n","");
    //˵��
    color(Color_bg_word);
        printf("\t˵�������ʱ��������䵥��");
    color(16 * 8 + 15);
        printf("���鿴�������������¼״̬�£�\n");
    tab(2,16 * 14 );
        printf(" ESC ");
    color(Color_bg_word);
        printf("�����ز�����   ");
    color(16 * 14);
        printf("����");
    color(Color_bg_word);
        printf("���ƶ�   ");
    color(16 * 14);
        printf("�س�/ENTER");
    color(Color_bg_word);
        printf("���ı��״̬\n\n");
    //���ʱ�
    for(i = 0;i < reciting.indexs ;i++){
        if(If_file_exist){
            //��״̬
            if(bingo[menu.unit-1][i] < err[menu.unit-1][i] && err[menu.unit-1][i] > 1)
                color(Color_red);
            else if(bingo[menu.unit-1][i] > 4)
                color(Color_green);
                printf(" ");
            color(Color_bg_word + 2);
                printf("%2d",bingo[menu.unit-1][i]);
            color(Color_bg_word);
                printf("|");
            color(Color_bg_word + 4);
                printf("%-2d",err[menu.unit-1][i]);
        }else{
            color(Color_bg_word + 8);
            printf("  0|0 ");
        }
        color(Color_bg_word);
            printf(" %2d. ",i+1);
        color(Color_phr);
        ChangePhr(i);
            printf("%-6s",reciting.phr);
        color(16 * 14 + 0 );
            printf(" %-19s",word[menu.unit-1][i]);
        color(Color_bg_word);
            printf(" ");
        color(16 * 15 + 0);
            printf(" %-35s",letter[menu.unit-1][i]);
        if(If_file_exist){
            if(mark[menu.unit-1][i]){
                color(Color_bg_word + 10);
                    printf("  ��");
            }else{
                color(Color_bg_word + 9);
                    printf("  ��");
            }
        }else{
            color(Color_bg_word + 8);
            printf("  ��¼�ɼ�   ��(�س�)����");
        }
        color(Color_bg_word);
            printf("\n\n");
    }
}
//ѡ�񵥴�
void Update_word_state(){
    menu.state = 1;
    color(Color_bg_word + 5);
        Goto(76,6 + reciting.index * 2);
        printf("��");
    Control_home(5);
    if(menu.state == 1)
        Update_word_state();
}
//ȡ��ѡ�񣨵��ʣ�
void Back_state(short site){
    printf("\b\b");
    if(site == 1){
        if(mark[menu.unit-1][reciting.index]){
            color(Color_bg_word + 10);
                printf("��");
        }else {
            color(Color_bg_word + 9);
                printf("��");
        }
    }else if(site == 2){
        color(Color_bg_word + 3);
        printf("��");
    }
}
//�������
void ChangePhr(int i){
    switch(phrase[menu.unit-1][i]){
    case 1:
        strcpy(reciting.phr,"n.");
        break;
    case 2:
        strcpy(reciting.phr,"v.");
        break;
    case 3:
        strcpy(reciting.phr,"adj.");
        break;
    case 4:
        strcpy(reciting.phr,"adv.");
        break;
    case 12:
        strcpy(reciting.phr,"n./v.");
        break;
    case 13:
        strcpy(reciting.phr,"n/adj.");
        break;
    }
}
