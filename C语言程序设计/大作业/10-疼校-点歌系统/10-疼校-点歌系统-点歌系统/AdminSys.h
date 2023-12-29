#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "AdminSys.h"



#define AdminLogTimes 5
#define ADMINACCLENG 10  //  管理员账号长度；
#define ADMINPASSLENG 12 // 管理员密码长度;

// 管理员结构体；
typedef struct adm {
    char AdminName[ADMINACCLENG]; // 管理员名字；
    char AdminPass[ADMINPASSLENG]; // 管理员密码；
    struct adm* Next;
}Admin, *AdminNode;
Admin FirstAdmin;
void AdminLogin(); // 管理员登录；





FILE *fp_admin = fopen("admin.txt", "r");
fscanf(fp_admin,"%s",FirstAdmin.AdminName);
fscanf(fp_admin, "%s",FirstAdmin.AdminPass);


void AdminLogin() {
    system("cls");
    printf("\t *******管理员登录*******\t\n");
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
        printf("\n \t 登录成功！即将为你跳转界面");
    }else {
        printf("\n \t 登录错误，还有%d次",AdminLogTimes);
        printf("\n \t 输入 1 重试，输入其他返回");
        char Jud;
        Jud = getch();
        if(Jud == '1') AdminLogin();
        else {
            // 返回原来界面;
        }
    }

}

