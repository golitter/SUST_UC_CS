#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "AdminSys.h"



#define AdminLogTimes 5
#define ADMINACCLENG 10  //  ����Ա�˺ų��ȣ�
#define ADMINPASSLENG 12 // ����Ա���볤��;

// ����Ա�ṹ�壻
typedef struct adm {
    char AdminName[ADMINACCLENG]; // ����Ա���֣�
    char AdminPass[ADMINPASSLENG]; // ����Ա���룻
    struct adm* Next;
}Admin, *AdminNode;
Admin FirstAdmin;
void AdminLogin(); // ����Ա��¼��





FILE *fp_admin = fopen("admin.txt", "r");
fscanf(fp_admin,"%s",FirstAdmin.AdminName);
fscanf(fp_admin, "%s",FirstAdmin.AdminPass);


void AdminLogin() {
    system("cls");
    printf("\t *******����Ա��¼*******\t\n");
    printf("\t administrator: [          ]\b\b\b\b\b\b\b\b\b\b");
    int i = 0;
    char c;
    system("cls");
    char InputAdNa[ADMINACCLENG];
    char InputAdPass[ADMINPASSLENG];
    while(i++ < ADMINACCLENG - 1) {
        c = getch();
        if('\r' == c){
            break;
        }
        printf("%c",c);
        InputAdNa[i - 1] = c;
        
    }
    InputAdNa[i] = '\0';
    putchar('\n');
    printf("\t password: [            ]\b\b\b\b\b\b\b\b\b\b\b\b");
    i = 0;
    while(i++ < ADMINPASSLENG - 1) {
        c = getch();
        if('\r' == c) {
            break;
        }
        printf("*");
        InputAdPass[i - 1] = c;
    }
    InputAdPass[i] = '\0';
    if(0==strcmp(InputAdNa, FirstAdmin.AdminName) && 0==strcmp(InputAdPass, FirstAdmin.AdminPass)) {
        printf("\n \t ��¼�ɹ�������Ϊ����ת����");
    }else {
        printf("\n \t ��¼���󣬻���%d��",AdminLogTimes);
        printf("\n \t ���� 1 ���ԣ�������������");
        char Jud;
        Jud = getch();
        if(Jud == '1') AdminLogin();
        else {
            // ����ԭ������;
        }
    }

}

