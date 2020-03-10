#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

enum color{black = 0 , blue , green , skyblue , red , purple , orange , white ,
           tblack , tblue , tgreen , tskyblue , tred , tpurple , torange , twhite};

#define Color_blue  16 * blue
#define Color_green 16 * green
#define Color_skyblue  16 * skyblue
#define Color_red   16 * red
#define Color_purple  16 * purple
#define Color_orange  16 * orange
#define Color_white  16 * white
#define Color_tblack  16 * tblack
#define Color_tblue  16 * tblue
#define Color_tgreen  16 * tgreen
#define Color_tskyblue  16 * tskyblue
#define Color_tred  16 * tred
#define Color_tpurple  16 * tpurple
#define Color_torange  16 * torange
#define Color_twhite  16 * twhite

#define Color_bg_home Color_tblack
#define Color_bg_word Color_white
#define Color_option Color_twhite
#define Color_selected Color_skyblue
#define Color_cancel Color_tred + twhite

extern short Color_ch,
            Color_word,
            Color_phr,
            Color_input,
            Color_face,
            Color_wrong;

struct menu{
    int mode;
    int unit;
    int order;
    int count_mode;
    int state;
    int setting;
    char name[40];
};
extern struct menu menu;
void home();
#endif // SCREEN_H_INCLUDED
