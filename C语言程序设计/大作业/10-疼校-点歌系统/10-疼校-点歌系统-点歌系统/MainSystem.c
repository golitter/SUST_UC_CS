#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
extern int  CHOICE;
void MainMenu()         //主菜单
{
    system("cls");
    puts("\t\t\t        大一下大作业:点歌系统");
    puts("\t\t\t=================================");
    puts("\t\t\t*         1  管理员系统\t\t*");
    puts("\t\t\t*         2  点歌\t\t*");
    puts("\t\t\t*         3  退出系统\t\t*");
    puts("\t\t\t=================================");
    printf("\t\t\t请输入选项[  ]\b\b");
    char CHCH;
    while(CHCH = getch()) {
        /**
         * @brief 
         * IMPR:缓冲区有换行键 -- '\n';
         */
        CHOICE = CHCH - '0';
        if(CHOICE >= 0 && CHOICE <= 3) {
            putchar(CHCH);
            //Sleep(1000);
            if(CHOICE != 3) {
                {
                    printf("\n\t\t\t");
                    printf("正在加载中...\n\t\t\t");
                    int i;
                    for(i = 0; i < 10; i++) {
                        printf("***");
                        Sleep(100);
                    }
                }
            }
            system("cls");
            break;
        }
    }
    system("cls");
    
}