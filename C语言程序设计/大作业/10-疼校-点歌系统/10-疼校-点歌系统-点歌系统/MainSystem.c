#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
extern int  CHOICE;
void MainMenu()         //���˵�
{
    system("cls");
    puts("\t\t\t        ��һ�´���ҵ:���ϵͳ");
    puts("\t\t\t=================================");
    puts("\t\t\t*         1  ����Աϵͳ\t\t*");
    puts("\t\t\t*         2  ���\t\t*");
    puts("\t\t\t*         3  �˳�ϵͳ\t\t*");
    puts("\t\t\t=================================");
    printf("\t\t\t������ѡ��[  ]\b\b");
    char CHCH;
    while(CHCH = getch()) {
        /**
         * @brief 
         * IMPR:�������л��м� -- '\n';
         */
        CHOICE = CHCH - '0';
        if(CHOICE >= 0 && CHOICE <= 3) {
            putchar(CHCH);
            //Sleep(1000);
            if(CHOICE != 3) {
                {
                    printf("\n\t\t\t");
                    printf("���ڼ�����...\n\t\t\t");
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