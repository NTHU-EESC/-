#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
/* ���İO�o�n�[�J�o�� */
#include "audio.h"
/* �t�~�٦����U���]�w */
/* For sound effect: In [Project Options]->[Parameters]->[Linker] add the parameter -lwinmm */


#include "console_draw3.h"
#include "kb_input2.h"
#include "font.h"
#include "image.h"
#include "framework.h"

/*
drawChar()  �̫��ӰѼƤ��O�O�r���I���M�e�����C��
�i�H�ѦҤU�����C��ȹ�Ӫ�ӳ]�w�A�Q�n���C��
   0: ��     1: �t��   2: �t��   3: �t�C
   4: �t��   5: �t��   6: �t��   7: �L��
   8: �t��   9: �G��  10: �G��  11: �G�C
  12: �G��  13: �G��  14: �G��  15: ��
*/

#define WIDTH     30
#define HEIGHT    20
#define OFFSET_X  5
#define OFFSET_Y  5

#define NUM_KEYS 40
#define word_number 100
#define PROP_NUMBER 10 /*7*/
#define initial_rate 66
#define LOSE 8

int REFRESH_RATE(int x);
int timer(void);

int my_game_one(void);
int my_game_two(void);
int game_over(int point);
int win_game(int score);
int pause(Audio a);
int about(void);

void setMainmenu(Menu *m);
void setPausemenu(Menu *m);
void setAbout(Menu *m);
void setGameover(Menu *m);
void setGamewin(Menu *m);

int speed(double x);
void sleep(clock_t wait);

typedef
struct{
    int x;
    int y;
    int symbol;
    int exist;
    int alive;
    //int order;
} letter;

typedef
struct{
    int x;
    int y;
    int symbol;
    int exist;
    int order;
} prop;

//int score;

int main(void)
{
    int IsEnding = 0;
    int k;
    char str[40] = {'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_UP, VK_DOWN, VK_ESCAPE, VK_RETURN, VK_SPACE, VK_TAB};
    int cur_tick, last_tick;
    int return_num;
    //int reslut;
    //int state;
    Menu mainmenu;
    Image* background;
    background = read_image("background-2.pixel", "background-2.color");

    Audio audio;
    openAudioFile("background.wav", &audio);
    playAudio(&audio);

    /* �Ұ���L���� ��ӵ{�����u�n���@���N��F*/
    initializeKeyInput();
    cur_tick = last_tick = timer();

    setMainmenu(&mainmenu);

    show_image(background, 49, 0);

    showMenu(&mainmenu);
    drawCmdWindow();
    saveScreen();


    /* �L�a�j��  �̭��]�t�F�o�ӵ{�����D�n�u�@
    �ӥB�C���j��|���_��̷s���e����ܨ�ù��W
    ���O���ʵe�@�� �C���j���s�@���e�� */
    /*while(1){
        game_over();
    }*/
    while (!IsEnding) {
        /* �C�g�L REFRESH_RATE �� ticks �~�|��s�@���e�� */
        cur_tick = timer(); /* �C�� tick 0.01 �� */
        sprintf(str, "%10d", cur_tick/1000);

        if (cur_tick -last_tick > REFRESH_RATE(initial_rate)) {

            last_tick = cur_tick;

            clearScreen();
            restoreScreen();

            putStringLarge(mainmenu.large_font, OFFSET_X+24, OFFSET_Y-1, str, 14);

            /* ����e�X�� */
            showMenu(&mainmenu);

            /* ���F�n���@�s�� drawChar() ���ʧ@���ͮĪG
               �����n�I�s�@�� drawCmdWindow() �⤧�e�e���������e�@����ܨ�ù��W */
            drawCmdWindow();

        } /* end of if (cur_tick % REFRESH_RATE == 0 ... */

        for (k=0; k<NUM_KEYS; k++) {
            /* ����q�쥻�Q���U�����A �ܦ���}�����A  �o�O���F�B�z���ۤ��񪺱��p */
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }


        /* ��L���� �B�z���ۤ��񪺪��p */
        for (k=0; k<NUM_KEYS; k++) {
            /* ����q�쥻�Q���U�����A �ܦ���}�����A  �o�O���F�B�z���ۤ��񪺱��p */
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;

                switch (key_val[k]) {
                case VK_UP:
                    scrollMenu(&mainmenu, -1);
                    break;
                case VK_DOWN:
                    scrollMenu(&mainmenu, +1);
                    break;
                case VK_RETURN:
                    //if (IsOnItem(&mainmenu, 2)) {
                        if (IsOnItem(&mainmenu, 0)) {
                            pauseAudio(&audio);
                            //openAudioFile("", &audio);
                            playAudio(&audio);
                            /*my_game_one();
                            openAudioFile("background.wav", &audio);
                            playAudio(&audio);
                            show_image(background, 49, 0);
                            showMenu(&mainmenu);
                            drawCmdWindow();
                            saveScreen();*/
                            switch(my_game_one()){
                            case 0:
                                openAudioFile("background.wav", &audio);
                                playAudio(&audio);
                                show_image(background, 49, 0);
                                showMenu(&mainmenu);
                                drawCmdWindow();
                                saveScreen();
                                break;
                            case 3:
                                pauseAudio(&audio);
                                drawCmdWindow();
                                saveScreen();
                                clearScreen();
                                Sleep(2);
                                IsEnding = 1;
                                break;
                            }
                        }
                        else if (IsOnItem(&mainmenu, 1)) {
                            /*pauseAudio(&audio);
                            playAudio(&audio);
                            reslut = my_game_two();
                            if(reslut==LOSE){
                                IsEnding = 1;
                                pauseAudio(&audio);
                                openAudioFile("Game_over_screen.wav", &audio);
                                restartAudio(&audio);
                                playAudio(&audio);
                                //while(1)
                                state = game_over(score);
                                //pauseAudio(&audio);
                                //clearScreen();
                                switch(state){
                                case 2:
                                    //pauseAudio(&audio);
                                    openAudioFile("background.wav", &audio);
                                    playAudio(&audio);
                                    show_image(background, 49, 0);
                                    showMenu(&mainmenu);
                                    drawCmdWindow();
                                    saveScreen();
                                    break;
                                case 3:
                                    pauseAudio(&audio);
                                    drawCmdWindow();
                                    saveScreen();
                                    clearScreen();
                                    Sleep(2);
                                    IsEnding = 1;
                                    break;
                                }
                                break;
                            }*/
                            pauseAudio(&audio);
                            playAudio(&audio);
                            switch(my_game_two()){
                            case 0:
                                openAudioFile("background.wav", &audio);
                                playAudio(&audio);
                                show_image(background, 49, 0);
                                showMenu(&mainmenu);
                                drawCmdWindow();
                                saveScreen();
                                break;
                            case 3:
                                pauseAudio(&audio);
                                drawCmdWindow();
                                saveScreen();
                                clearScreen();
                                Sleep(2);
                                IsEnding = 1;
                                break;
                            }
                        }
                        else if (IsOnItem(&mainmenu, 2)) {
                            pauseAudio(&audio);
                            drawCmdWindow();
                            saveScreen();
                            clearScreen();
                            Sleep(2);
                            IsEnding = 1;
                        }
                        else if (IsOnItem(&mainmenu, 3)) {
                            pauseAudio(&audio);
                            playAudio(&audio);
                            about();
                            openAudioFile("background.wav", &audio);
                            playAudio(&audio);
                            show_image(background, 49, 0);
                            showMenu(&mainmenu);
                            drawCmdWindow();
                            saveScreen();
                        }
                    break;
                /*case VK_SPACE:
                    radioMenu(&mainmenu);
                    break;*/
                /*case VK_TAB:
                    pauseAudio(&audio);
                    openAudioFile("Game_over_screen.wav", &audio);
                    restartAudio(&audio);
                    playAudio(&audio);
                    while(1)
                    game_over();
                    break;*/
                }
            }
        }
    } /* while (IsEnding) */

    return 0;
}
int timer(void)
{
    return (clock()/(0.001*CLOCKS_PER_SEC));
}
void setMainmenu(Menu *m)
{
    int i;

    m->large_font = read_font("font.txt");
    m->x = 5;
    m->y = 2;
    m->fgcolor = 15;
    m->bgcolor = 11;
    m->num_options = 4;
    m->cursor = 0;
    for (i=0; i<m->num_options; i++) {
        m->state[i] = 0;
    }
    m->state[m->cursor] = m->state[m->cursor] | 1;  /* �ثe��ܪ����� */

    strcpy(m->text[0], "normal mode");
    strcpy(m->text[1], "special mode");
    //strcpy(m->text[2], "START");
    strcpy(m->text[2], "EXIT");
    strcpy(m->text[3], "instruction");
    /*strcpy(m->alt_text[0], "drawCm *");
    strcpy(m->alt_text[1], "TWO PLAYERS *");
    strcpy(m->alt_text[2], "START *");
    strcpy(m->alt_text[3], "EXIT *");
    strcpy(m->alt_text[4], "ABOUT *");*/
}
/*--------------------------------------------------------------*/
int my_game_one(void)
{
    Font * font = read_font("font.txt");
    //char c[1] = "a";
    int IsEnding = 0;
    //char logo[] = "MY BRILLIANT (OR FUNNY) GAME";
    char pt[]="point";
    char poi[40]={'\0'};
    int i, j, k, l, b, check;
    char str[40] = {'\0'};
    char lif[]="life";
    char live[5]={'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_ESCAPE, VK_A, VK_B, VK_C, VK_D, VK_E, VK_F, VK_G, VK_H, VK_I, VK_J, VK_K, VK_L,
                             VK_M, VK_N, VK_O, VK_P, VK_Q, VK_R, VK_S, VK_T, VK_U, VK_V, VK_W, VK_X, VK_Y, VK_Z};
    int cur_tick, last_tick;

    int dead = 0;
    int win;
    int state;
    int point;
    int life;
    char ch;
    letter object[10000];

    /* �Ұ���L���� ��ӵ{�����u�n���@���N��F*/
    initializeKeyInput();
    cur_tick = last_tick = timer();
    clearScreen();
    Audio audio;
    openAudioFile("game_voice.wav", &audio);
    playAudio(&audio);
    Image* block;
    block = read_image("block-1.pixel", "block-1.color");
    /*for(i=0;i<100;i++){
        show_image(block, i, 50);
    }
    drawCmdWindow();*/
    saveScreen();
    srand(time(NULL));
    for(i=0;i<word_number;i++){
        object[i].x = 10+((rand()*10)%90);
        object[i].symbol = rand()%26+65;
        object[i].y = 0;
        object[i].exist = 1;
        object[i].alive = 1;
    }
    i=0;
    state = 1;
    point = 0;
    life = 3;


//drawChar(object[1].symbol,object[1].x,object[1].y,0,15);
    while (!IsEnding) {
        /* �C�g�L REFRESH_RATE �� ticks �~�|��s�@���e��  */
        win = 1;
        cur_tick = timer();
        if(i<10) state = 1;
        else if(10<=i&&i<20) state = 2;
        else if(20<=i&&i<30) state = 3;
        else if(30<=i&&i<40) state = 4;
        else if(40<=i&&i<50) state = 5;
        else state = 6;
        if (cur_tick-last_tick > REFRESH_RATE(state)) {
            clearScreen();
            for(j=0;j<=min(i,word_number);j++){
                if(object[j].exist==1){
                    //putStringLarge(font_game,object[j].x,object[j].y,c,15); //��
                    show_font2(font,object[j].symbol,object[j].x,object[j].y,15);
                    //drawChar(object[j].symbol,object[j].x,object[j].y,0,15);
                    object[j].y+=6;
                }
            }
            for(b=0;b<100;b=b+20){
                show_image(block, b, 65);
            }
            sprintf(poi, "%4d", point);
            //putStringLarge(font, 110, 25, lif, 12);
            putStringLarge(font, 110, 10, pt, 14);
            putStringLarge(font, 150, 10, poi, 6);
            sprintf(live, "%4d", life);
            //putStringLarge(font, 150, 25, live, 12);
            putStringLarge(font, 110, 25, lif, 12);//???
            putStringLarge(font, 150, 25, live, 12);
            //show_font2(font_game,'c',50,20,15);
            last_tick = cur_tick;
            drawCmdWindow();
            i++;
        } /* end of if (cur_tick % REFRESH_RATE == 0 ...*/
        k = i;
        l = i;
        for(check=0;check<word_number;check++){
            if(object[check].exist == 1){
                win = 0;
                break;
            }
        }
        for(j=0;j<=k;j++){
            if((object[j].y >= 62)&&(object[j].exist==1)&&(object[j].alive==1)){
                object[j].alive = 0;
                object[j].exist = 0;
                life--;
                if(life==-1){
                    IsEnding = 1;
                    pauseAudio(&audio);
                    openAudioFile("Game_over_screen.wav", &audio);
                    restartAudio(&audio);
                    playAudio(&audio);
                    //while(1){
                        switch(game_over(point)){
                            /*case 1:
                                pauseAudio(&audio);
                                clearScreen();
                                my_game_one();
                                restoreScreen();
                                srand(time(NULL));
                                for(i=0;i<word_number;i++){
                                    object[i].x = 10+((rand()*10)%90);
                                    object[i].symbol = rand()%26+65;
                                    object[i].y = 0;
                                    object[i].exist = 1;
                                    object[i].alive = 1;
                                }
                                i=0;
                                state = 1;
                                point = 0;
                                life = 3;
                                return 1;
                                break;*/
                            case 2:
                                pauseAudio(&audio);
                                clearScreen();
                                IsEnding = 1;
                                return 0;
                                break;
                            case 3:
                                pauseAudio(&audio);
                                clearScreen();
                                /*drawCmdWindow();
                                saveScreen();
                                clearScreen();
                                Sleep(2);*/
                                IsEnding = 1;
                                return 3;
                                break;
                        }
                        break;
                    //}
                }
            }
            if(life>-1 && win==1){
                IsEnding = 1;
                pauseAudio(&audio);
                openAudioFile("win_voice.wav", &audio);
                restartAudio(&audio);
                playAudio(&audio);
                switch(win_game(point)){
                    case 2:
                        pauseAudio(&audio);
                        clearScreen();
                        IsEnding = 1;
                        return 0;
                        break;
                    case 3:
                        pauseAudio(&audio);
                        clearScreen();
                        IsEnding = 1;
                        return 3;
                        break;
                }
                break;
            }
            clearScreen();
        }
        for (k=0; k<NUM_KEYS; k++) {
            /* ����q�쥻�Q���U�����A �ܦ���}�����A  �o�O���F�B�z���ۤ��񪺱��p */
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;
                //min(l,word_number)
                switch (key_val[k]) {
                case VK_ESCAPE:
                    switch(pause(audio)){
                    case 1:
                        openAudioFile("game_voice.wav", &audio);
                        playAudio(&audio);
                        srand(time(NULL));
                        for(i=0;i<word_number;i++){
                            object[i].x = 10+((rand()*10)%90);
                            object[i].symbol = rand()%26+65;
                            object[i].y = 0;
                            object[i].exist = 1;
                            object[i].alive = 1;
                        }
                        i=0;
                        state = 1;
                        point = 0;
                        life = 3;
                        break;
                    case 2:
                        openAudioFile("game_voice.wav", &audio);
                        playAudio(&audio);
                        break;
                    case 3:
                        clearScreen();
                        pauseAudio(&audio);
                        IsEnding = 1;
                        break;
                    }
                break;
                case VK_A:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==65){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_B:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==66){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_C:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==67){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_D:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==68){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_E:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==69){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_F:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==70){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_G:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==71){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_H:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==72){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_I:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==73){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_J:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==74){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_K:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==75){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_L:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==76){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_M:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==77){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_N:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==78){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_O:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==79){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_P:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==80){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                    case VK_Q:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==81){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_R:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==82){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_S:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==83){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_T:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==84){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_U:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==85){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_V:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==86){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_W:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==87){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_X:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==88){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_Y:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==89){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_Z:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==90){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;


            }
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }

     }

/*    clearScreen();
    srand(time(NULL));
    for(i=0;i<100;i++){
        object[i].x = (rand()%200);
        object[i].symbol = rand()%26+97;
        object[i].y = 0;
        object[i].exist = 1;
    }*/
    /*i=0;
    while(dead==0){
        //clearScreen();
        i++;
        clearScreen();
        if(i<10) state = 1;
            else if(10<=i&&i<20) state = 2;
            else if(20<=i&&i<30) state = 3;
            else if(30<=i&&i<40) state = 4;
            else if(40<=i&&i<50) state = 5;
            else state = 6;
            for(j=0;j<=min(i,100);j++){
                if(object[j].exist==1){
                    drawChar(object[j].symbol,object[j].x,object[j].y,0,15);
                    object[j].y++;
                }
                //while(ch==object[j].symbol) object[j].exist = 0;
                for (k=0; k<NUM_KEYS; k++) {
                    if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                        key_down[k] = 1;
                        switch (key_val[k]) {
                            case VK_ESCAPE:
                                dead = 1;
                                break;
                            case VK_a:
                                if(object[j].symbol==97){
                                    object[j].exist = 0;
                                }
                        }
                    }
                    if(KEY_UP(key_val[k]) && key_down[k]) {
                        key_down[k] = 0;
                    }
                }
            }
            drawCmdWindow();
            sleep(speed(state));

        if(object[i].y == 15) dead = 1; //??
    }*/
    /*while(dead){
        pauseAudio(&audio);
        openAudioFile("Game_over_screen.wav", &audio);
        restartAudio(&audio);
        playAudio(&audio);
        while(1) game_over();
    }*/
    }
    return 0;
}
int my_game_two(void)
{
    Font * font = read_font("font.txt");
    int IsEnding = 0;
    char pt[]="point";
    char poi[40]={'\0'};
    int i, j, k, l, b, n, check;
    char str[40] = {'\0'};
    char lf[]="life";
    char live[5]={'\0'};
    //char object_num[10]={'\0'};
    //char prop_num[10]={'\0'};
    //char k_number[10]={'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_ESCAPE, VK_A, VK_B, VK_C, VK_D, VK_E, VK_F, VK_G, VK_H, VK_I, VK_J, VK_K, VK_L,
                             VK_M, VK_N, VK_O, VK_P, VK_Q, VK_R, VK_S, VK_T, VK_U, VK_V, VK_W, VK_X, VK_Y, VK_Z,
                             VK_TAB, VK_CONTROL};
    int cur_tick, last_tick;

    int dead = 0;
    //int lose = LOSE;
    int state;
    int point;
    int life;
    int win;
    char ch;
    char button[2][10]={"TAB","ctrl"};
    letter object[10000];
    prop property[PROP_NUMBER];

    initializeKeyInput();
    cur_tick = last_tick = timer();
    clearScreen();
    Audio audio;
    openAudioFile("game_voice.wav", &audio);
    playAudio(&audio);
    Image* block;
    block = read_image("block-1.pixel", "block-1.color");

    Image* heart;
    heart = read_image("heart.pixel", "heart.color");
    //show_image(heart, 49, 0);

    Image* fire;
    fire = read_image("fire.pixel", "fire.color");
    //show_image(fire, 49, 20);

    srand(time(NULL));

    for(i=0;i<PROP_NUMBER;i++){
        property[i].order = (i+1)*20;
        property[i].x = 10+((rand()*10)%90);
        property[i].symbol = rand()%2;
        property[i].y = 0;
        property[i].exist = 1;
    }

    j = 0;
    for(i=0;i<word_number;i++){
        if(i==property[j].order) j++;
        else{
            object[i].x = 10+((rand()*10)%90);
            object[i].symbol = rand()%26+65;
            object[i].y = 0;
            object[i].exist = 1;
            object[i].alive = 1;
            //object[i].order = i;
        }
    }
    i=0;
    state = 1;
    point = 0;
    life = 3;
    n = 0;
    while (!IsEnding) {
        /* �C�g�L REFRESH_RATE �� ticks �~�|��s�@���e��  */
        cur_tick = timer();
        if(i<10) state = 1;
        else if(10<=i&&i<20) state = 2;
        else if(20<=i&&i<30) state = 3;
        else if(30<=i&&i<40) state = 4;
        else if(40<=i&&i<50) state = 5;
        else state = 6;
        if (cur_tick-last_tick > REFRESH_RATE(state)) {
            clearScreen();
            win = 1;
            for(j=0,n=0;j<=min(i,word_number);j++){
                if(object[j].exist==1){
                    show_font2(font,object[j].symbol,object[j].x,object[j].y,15);
                    object[j].y+=6;
                    continue;
                }
                if((j == property[n].order)/*&&(property[n].exist==1)*/){
                    if((property[n].symbol == 0)&&(property[n].exist==1)){
                        show_image(heart, property[n].x, property[n].y);
                        property[n].y+=6;
                    }
                    else if((property[n].symbol == 1)&&(property[n].exist==1)){
                        show_image(fire, property[n].x, property[n].y);
                        property[n].y+=6;
                    }
                    n++;
                }
            }
            for(b=0;b<100;b=b+20){
                show_image(block, b, 65);
            }

            /*sprintf(k_number, "%4d", n);
            putStringLarge(font, 110, 37, k_number, 14);*/
            /*sprintf(prop_num, "%4d", property[2].order);
            putStringLarge(font, 110, 37, prop_num, 14);*/
            /*sprintf(object_num, "%4d", object[2].order);
            putStringLarge(font, 110, 37, object_num, 14);*/

            sprintf(poi, "%4d", point);
            putStringLarge(font, 110, 10, pt, 14);
            putStringLarge(font, 150, 10, poi, 6);
            sprintf(live, "%4d", life);
            putStringLarge(font, 110, 25, lf, 12);//???
            putStringLarge(font, 150, 25, live, 12);
            putStringLarge(font, 110, 45, button[0], 15);//???
            putStringLarge(font, 110, 55, button[1], 15);
            show_image(fire, 140, 40);
            show_image(heart, 150, 53);

            last_tick = cur_tick;
            drawCmdWindow();
            i++;
        }
        for(check=0;check<word_number;check++){
            if(object[check].exist == 1){
                win = 0;
                break;
            }
        }
        //n = i;
        l = i;
        for(j=0;j<=l;j++){
            if((object[j].y >= 62)&&(object[j].exist==1)&&(object[j].alive==1)){
                object[j].alive = 0;
                object[j].exist = 0;
                life--;
                if(life==-1){
                    IsEnding = 1;
                    pauseAudio(&audio);
                    openAudioFile("Game_over_screen.wav", &audio);
                    restartAudio(&audio);
                    playAudio(&audio);
                    switch(game_over(point)){
                    case 2:
                        pauseAudio(&audio);
                        clearScreen();
                        IsEnding = 1;
                        return 0;
                        break;
                    case 3:
                        pauseAudio(&audio);
                        clearScreen();
                        IsEnding = 1;
                        return 3;
                        break;
                    }
                    break;
                }
            }
            clearScreen();
        }
        if(life>-1 && win==1){
            IsEnding = 1;
            pauseAudio(&audio);
            openAudioFile("win_voice.wav", &audio);
            restartAudio(&audio);
            playAudio(&audio);
            switch(win_game(point)){
                case 2:
                    pauseAudio(&audio);
                    clearScreen();
                    IsEnding = 1;
                    return 0;
                    break;
                case 3:
                    pauseAudio(&audio);
                    clearScreen();
                    IsEnding = 1;
                    return 3;
                    break;
            }
            break;
        }
        for (k=0; k<NUM_KEYS; k++) {
            /* ����q�쥻�Q���U�����A �ܦ���}�����A  �o�O���F�B�z���ۤ��񪺱��p */
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;
                //min(l,word_number)
                switch (key_val[k]) {
                case VK_ESCAPE:
                    switch(pause(audio)){
                    case 1:
                        openAudioFile("game_voice.wav", &audio);
                        playAudio(&audio);
                        for(i=0;i<PROP_NUMBER;i++){
                            property[i].order = (i+1)*20;
                            property[i].x = 10+((rand()*10)%90);
                            property[i].symbol = rand()%2;
                            property[i].y = 0;
                            property[i].exist = 1;
                        }

                        j = 0;
                        for(i=0;i<word_number;i++){
                            if(i==property[j].order) j++;
                            else{
                                object[i].x = 10+((rand()*10)%90);
                                object[i].symbol = rand()%26+65;
                                object[i].y = 0;
                                object[i].exist = 1;
                                object[i].alive = 1;
                            }
                        }
                        i=0;
                        state = 1;
                        point = 0;
                        life = 3;
                        break;
                    case 2:
                        openAudioFile("game_voice.wav", &audio);
                        playAudio(&audio);
                        break;
                    case 3:
                        clearScreen();
                        pauseAudio(&audio);
                        IsEnding = 1;
                        break;
                    }
                break;
                case VK_CONTROL:
                    for(j=0;j<=PROP_NUMBER;j++){
                        if(((property[j].order)<l)&&(property[j].exist==1)&&(property[j].symbol==0)){
                            life++;
                            property[j].exist=0;
                        }
                    }
                break;
                case VK_TAB:
                    for(j=0;j<=PROP_NUMBER;j++){
                        if(((property[j].order)<l)&&(property[j].exist==1)&&(property[j].symbol==1)){
                            for(k=0;k<=l;k++){
                                if(object[k].exist==1){
                                    point++;
                                    object[k].exist = 0;
                                }
                            }
                            property[j].exist=0;
                        }
                    }
                break;
                case VK_A:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==65){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_B:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==66){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_C:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==67){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_D:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==68){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_E:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==69){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_F:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==70){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_G:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==71){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                break;
                case VK_H:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==72){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_I:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==73){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_J:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==74){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_K:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==75){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_L:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==76){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_M:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==77){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_N:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==78){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_O:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==79){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_P:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==80){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                    case VK_Q:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==81){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_R:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==82){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_S:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==83){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_T:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==84){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_U:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==85){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_V:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==86){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_W:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==87){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_X:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==88){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_Y:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==89){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;
                case VK_Z:
                    //check(j,'a');
                    for(j=0;j<=l;j++){
                        if(object[j].symbol==90){
                            object[j].exist = 0;
                            point++;
                        }
                    }
                    break;


                }
            }
        }
    }
    return 0;
}
int game_over(int point)
{
    Font * font = read_font("font.txt");
    //clearScreen();
    Image* over;
    over = read_image("over.pixel", "over.color");
    /*Image* background;
    background = read_image("background-2.pixel", "background-2.color");
    show_image(background, 44, 0);*/
    int IsEnding = 0;
    int k;
    char str[40] = {'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_UP, VK_DOWN, VK_ESCAPE, VK_RETURN, VK_SPACE, VK_TAB};
    int cur_tick, last_tick;
    Menu gameover;
    char ID[10]="105060012";
    char id[10]="105060020";
    char pt[10]="point";
    char poi[40]={'\0'};
    //Audio audio;
    //openAudioFile("Game_over_screen.wav", &audio);
    //restartAudio(&audio);
    //playAudio(&audio);

    /*show_image(over, 30, 0);
    drawString(ID,5,6,0,15);
    drawChar(0xB1,15,6,0,15);
    drawChar(0x69,16,6,0,15);
    drawChar(0xA8,17,6,0,15);
    drawChar(0x7C,18,6,0,15);
    drawChar(0xDB,19,6,0,15);
    drawChar(0x70,20,6,0,15);
    drawString(id,5,7,0,15);
    drawChar(0xAA,15,7,0,15);
    drawChar(0x4C,16,7,0,15);
    drawChar(0xAA,17,7,0,15);
    drawChar(0xDA,18,7,0,15);
    drawChar(0xB7,19,7,0,15);
    drawChar(0xEC,20,7,0,15);
    sprintf(poi, "%4d", point);
    putStringLarge(font, 110, 10, pt, 14);
    putStringLarge(font, 150, 10, poi, 6);
    drawCmdWindow();*/

    //Image* background;//??
    //background = read_image("background-2.pixel", "background-2.color");//??
    initializeKeyInput();
    cur_tick = last_tick = timer();
    setGameover(&gameover);
    //show_image(background, 19, 0);//??
    showMenu(&gameover);
    drawCmdWindow();
    saveScreen();
    while (!IsEnding) {
        cur_tick = timer();
        if (cur_tick -last_tick > REFRESH_RATE(initial_rate)) {
            last_tick = cur_tick;
            clearScreen();
            restoreScreen();
            show_image(over, 30, 0);
            drawString(ID,5,6,0,15);
            drawChar(0xB1,15,6,0,15);
            drawChar(0x69,16,6,0,15);
            drawChar(0xA8,17,6,0,15);
            drawChar(0x7C,18,6,0,15);
            drawChar(0xDB,19,6,0,15);
            drawChar(0x70,20,6,0,15);
            drawString(id,5,7,0,15);
            drawChar(0xAA,15,7,0,15);
            drawChar(0x4C,16,7,0,15);
            drawChar(0xAA,17,7,0,15);
            drawChar(0xDA,18,7,0,15);
            drawChar(0xB7,19,7,0,15);
            drawChar(0xEC,20,7,0,15);
            sprintf(poi, "%4d", point);
            putStringLarge(font, 110, 10, pt, 14);
            putStringLarge(font, 150, 10, poi, 6);
            showMenu(&gameover);
            drawCmdWindow();
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;
                switch (key_val[k]) {
                    case VK_UP:
                        scrollMenu(&gameover, -1);
                        break;
                    case VK_DOWN:
                        scrollMenu(&gameover, +1);
                        break;
                    case VK_RETURN:
                            if (IsOnItem(&gameover, 0)) {  //menu
                                clearScreen();
                                return 2;
                            }
                            else if (IsOnItem(&gameover, 1)) {//exit
                                clearScreen();
                                return 3;
                            }
                            /*else if (IsOnItem(&gameover, 2)) {  //exit
                                clearScreen();
                                return 3;
                            }*/
                        break;
                }
            }
        }
    }
}
void setGameover(Menu *m)
{
    int i;

    m->large_font = read_font("font.txt");
    m->x = 13;
    m->y = 8;
    m->fgcolor = 15;
    m->bgcolor = 11;
    m->num_options = 2;
    m->cursor = 0;
    for (i=0; i<m->num_options; i++) {
        m->state[i] = 0;
    }
    m->state[m->cursor] = m->state[m->cursor] | 1;  /* �ثe��ܪ����� */

    /*strcpy(m->text[0], "retry");
    strcpy(m->text[1], "menu");
    strcpy(m->text[2], "exit");*/
    strcpy(m->text[0], "menu");
    strcpy(m->text[1], "exit");
}
void sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() );
}
int win_game(int score)
{
    Font * font = read_font("font.txt");
    Image* win_p;
    win_p = read_image("win-2.pixel", "win-2.color");
    int IsEnding = 0;
    int k;
    char str[40] = {'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_UP, VK_DOWN, VK_ESCAPE, VK_RETURN, VK_SPACE, VK_TAB};
    int cur_tick, last_tick;
    Menu win;
    char ID[10]="105060012";
    char id[10]="105060020";
    char pt[10]="point";
    char poi[40]={'\0'};
    initializeKeyInput();
    cur_tick = last_tick = timer();
    setGamewin(&win);
    showMenu(&win);
    drawCmdWindow();
    saveScreen();
    while (!IsEnding) {
        cur_tick = timer();
        if (cur_tick -last_tick > REFRESH_RATE(initial_rate)) {
            last_tick = cur_tick;
            clearScreen();
            restoreScreen();
            show_image(win_p, -15, 0);
            drawString(ID,5,6,0,15);
            drawChar(0xB1,15,6,0,15);
            drawChar(0x69,16,6,0,15);
            drawChar(0xA8,17,6,0,15);
            drawChar(0x7C,18,6,0,15);
            drawChar(0xDB,19,6,0,15);
            drawChar(0x70,20,6,0,15);
            drawString(id,5,7,0,15);
            drawChar(0xAA,15,7,0,15);
            drawChar(0x4C,16,7,0,15);
            drawChar(0xAA,17,7,0,15);
            drawChar(0xDA,18,7,0,15);
            drawChar(0xB7,19,7,0,15);
            drawChar(0xEC,20,7,0,15);
            sprintf(poi, "%4d", score);
            putStringLarge(font, 53, 50, pt, 13);
            putStringLarge(font, 90, 50, poi, 10);
            showMenu(&win);
            drawCmdWindow();
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;
                switch (key_val[k]) {
                    case VK_UP:
                        scrollMenu(&win, -1);
                        break;
                    case VK_DOWN:
                        scrollMenu(&win, +1);
                        break;
                    case VK_RETURN:
                            if (IsOnItem(&win, 0)) {  //menu
                                clearScreen();
                                return 2;
                            }
                            else if (IsOnItem(&win, 1)) {//exit
                                clearScreen();
                                return 3;
                            }
                        break;
                }
            }
        }
    }
}
void setGamewin(Menu *m)
{
    int i;
    m->large_font = read_font("font.txt");
    m->x = 7.5;
    m->y = 3;
    m->fgcolor = 15;
    m->bgcolor = 11;
    m->num_options = 2;
    m->cursor = 0;
    for (i=0; i<m->num_options; i++) {
        m->state[i] = 0;
    }
    //m->state[m->cursor] = m->state[m->cursor] | 1;
    strcpy(m->text[0], "menu");
    strcpy(m->text[1], "exit");
}
int pause(Audio a)
{
    int IsEnding = 0;
    int k;
    char str[40] = {'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_UP, VK_DOWN, VK_ESCAPE, VK_RETURN, VK_SPACE, VK_TAB};
    int cur_tick, last_tick;
    Menu suspend;
    Audio audio;
    pauseAudio(&a);
    openAudioFile("pause.wav", &audio);
    playAudio(&audio);
    //Image* background;//??
    //background = read_image("background-2.pixel", "background-2.color");//??
    initializeKeyInput();
    cur_tick = last_tick = timer();
    setPausemenu(&suspend);
    //show_image(background, 19, 0);//??
    showMenu(&suspend);
    drawCmdWindow();
    saveScreen();
    while (!IsEnding) {
        cur_tick = timer();
        sprintf(str, "%10d", cur_tick/1000);
        if (cur_tick -last_tick > REFRESH_RATE(initial_rate)) {
            last_tick = cur_tick;
            clearScreen();
            restoreScreen();
            putStringLarge(suspend.large_font, OFFSET_X, OFFSET_Y-1, str, 14);
            showMenu(&suspend);
            drawCmdWindow();
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;
                switch (key_val[k]) {
                    case VK_UP:
                        scrollMenu(&suspend, -1);
                        break;
                    case VK_DOWN:
                        scrollMenu(&suspend, +1);
                        break;
                    case VK_RETURN:
                            if (IsOnItem(&suspend, 0)) {  //retry
                                pauseAudio(&audio);
                                //playAudio(&audio);
                                return 1;
                            }
                            else if (IsOnItem(&suspend, 1)) {  //continue //??
                                pauseAudio(&audio);
                                //playAudio(&audio);
                                return 2;
                            }
                            else if (IsOnItem(&suspend, 2)) {  //�^��menu //??
                                pauseAudio(&audio);
                                return 3;
                            }
                        break;
                }
            }
        }
    }
}
void setPausemenu(Menu *m)
{
    int i;

    m->large_font = read_font("font.txt");
    m->x = 2;
    m->y = 2;
    m->fgcolor = 15;
    m->bgcolor = 11;
    m->num_options = 3;
    m->cursor = 0;
    for (i=0; i<m->num_options; i++) {
        m->state[i] = 0;
    }
    m->state[m->cursor] = m->state[m->cursor] | 1;  /* �ثe��ܪ����� */

    strcpy(m->text[0], "retry");
    strcpy(m->text[1], "continue");
    strcpy(m->text[2], "menu");
}
int about(void)
{
    Font * font = read_font("font.txt");
    int IsEnding = 0;
    int k;
    char str[40] = {'\0'};
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_UP, VK_DOWN, VK_ESCAPE, VK_RETURN};
    int cur_tick, last_tick;
    //char detail[10][200]={"Normal mode","try to avoid the letters bumping into the ground,","you only have three lives.",
                     //"Special mode:","you will have some special props.","TAB->fire all the letters�Fctrl->one more heart"};//??
    //char detail[]={"Normal mode"};
    char detail[10][200]={"Three lives","fire all letters","heart",
                          "Special mode","Normal mode","TAB","ctrl"};
    Menu anent;
    //Image* about;
    //about = read_image("about-2.pixel", "about-2.color");//??

    initializeKeyInput();
    cur_tick = last_tick = timer();
    clearScreen();
    Audio audio;
    openAudioFile("about.wav", &audio);
    playAudio(&audio);
    setAbout(&anent);
    //show_image(about, 22, 0);//??
    showMenu(&anent);
    drawCmdWindow();
    saveScreen();
    while (!IsEnding) {
        cur_tick = timer();
        sprintf(str, "%10d", cur_tick/1000);
        if (cur_tick -last_tick > REFRESH_RATE(initial_rate)) {
            last_tick = cur_tick;
            clearScreen();
            restoreScreen();
            putStringLarge(anent.large_font, OFFSET_X, OFFSET_Y-1, str, 14);
            putStringLarge(anent.large_font, 10, 15, detail[4], 9);
            putStringLarge(anent.large_font, 20, 23, detail[0], 12);
            putStringLarge(anent.large_font, 10, 31, detail[3], 9);
            putStringLarge(anent.large_font, 55, 39, detail[1], 4);
            putStringLarge(anent.large_font, 55, 47, detail[2], 4);
            putStringLarge(anent.large_font, 20, 39, detail[5], 12);
            putStringLarge(anent.large_font, 20, 47, detail[6], 12);
            //putStringLarge(anent.large_font, 2, 5, detail[1], 9);
            //putStringLarge(anent.large_font, 2, 6, detail[2], 9);
            //putStringLarge(anent.large_font, 2, 7, detail[3], 9);
            //putStringLarge(anent.large_font, 2, 8, detail[4], 9);
            //putStringLarge(anent.large_font, 2, 9, detail[5], 9);
            showMenu(&anent);
            drawCmdWindow();
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_UP(key_val[k]) && key_down[k]) {
                key_down[k] = 0;
            }
        }
        for (k=0; k<NUM_KEYS; k++) {
            if(KEY_DOWN(key_val[k]) && !key_down[k]) {
                key_down[k] = 1;
                switch (key_val[k]) {
                    case VK_UP:
                        scrollMenu(&anent, -1);
                        break;
                    case VK_DOWN:
                        scrollMenu(&anent, +1);
                        break;
                    case VK_RETURN:
                            if (IsOnItem(&anent, 0)) {
                                clearScreen();
                                pauseAudio(&audio);
                                IsEnding = 1;
                            }
                        break;
                }
            }
        }
    }
    return 0;
}
void setAbout(Menu *m)
{
    int i;

    m->large_font = read_font("font.txt");
    m->x = 13;
    m->y = 8;
    m->fgcolor = 15;
    m->bgcolor = 11;
    m->num_options = 1;
    m->cursor = 0;
    for (i=0; i<m->num_options; i++) {
        m->state[i] = 0;
    }
    //m->state[m->cursor] = m->state[m->cursor] | 1;  /* �ثe��ܪ����� */

    strcpy(m->text[0], "back");
}
int REFRESH_RATE(int x)
{
    return 670-10*x;
}
