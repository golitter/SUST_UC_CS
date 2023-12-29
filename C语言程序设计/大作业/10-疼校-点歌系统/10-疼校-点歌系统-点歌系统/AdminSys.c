#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "SongSys.c"
/**
 * @brief 
 * 引入变量 :
 * CHOICE;
 */
extern int CHOICE;
extern SongPointer Ad;
#define AdminLogTimes 5
#define ADMINACCLENG 10  //  管理员账号长度；含'\0'
#define ADMINPASSLENG 12 // 管理员密码长度; 含 '\0'

int ADMINCHOICE; // 管理界面的选择变量；

#define QUIT 0
#define CHANGEPASS 3
#define ADALLSONGS 1
#define DELETESONG 2

// 管理员结构体；
typedef struct adm {
    char AdminName[ADMINACCLENG]; // 管理员名字；
    char AdminPass[ADMINPASSLENG]; // 管理员密码；
    struct adm* Next;
}Admin, *AdminNode;
Admin FirstAdmin;

// 管理员登录；
void AdminLogin(); 
 // 管理员界面;
void AdminMainSys();
// 管理界面退出 -- > 主页面;
void AdminQuit(); 
// 修改管理员密码;
void ChangePass(); 
 // 删除歌曲；
void DeleteSong();
void ListDel(int number);
// 改音乐编号;



int LOGINTIMES = AdminLogTimes; // 输入密码错误次数；
void AdminLogin() {
    system("cls"); // \t -- TAB ;; \b -- 缩进;; \t -- Enter;;
    printf("\t\t\t *******管理员登录*******\t\n");
    printf("\t\t\t administrator: [          ]\b\b\b\b\b\b\b\b\b\b");
    int Places = 0;
    char c;
    char InputAdNa[ADMINACCLENG];
    char InputAdPass[ADMINPASSLENG];
    while(Places++ < ADMINACCLENG - 1) {
        c = getch();
        if('\r' == c){
            break;
        } else {
            if(' ' == c || '\b' == c) {
                Places--;
                continue;
            }
        }
        printf("%c",c);
        InputAdNa[Places - 1] = c;
        
    }
    InputAdNa[Places] = '\0';
    putchar('\n');
    printf("\t\t\t     password: [            ]\b\b\b\b\b\b\b\b\b\b\b\b");
    Places = 0;
    while(Places++ < ADMINPASSLENG - 1) {
        c = getch();
        if('\r' == c) {
            break;
        } else {
            if(' ' == c) {
                Places--;
                continue;
            }
        }
        printf("*");
        InputAdPass[Places - 1] = c;
    }
    InputAdPass[Places] = '\0';
    if(0==strcmp(InputAdNa, FirstAdmin.AdminName) && 0==strcmp(InputAdPass, FirstAdmin.AdminPass)) {
        printf("\n \t\t\t 登录成功！即将为你跳转界面...");
        LOGINTIMES = 5;

        Sleep(1500);
        // 页面;;
        //
        AdminMainSys();

    } else {
        LOGINTIMES--;
        if(LOGINTIMES >= 1) {
            printf("\n \t\t\t 登录错误，还有%d次",LOGINTIMES);
            printf("\n \t\t\t 输入 1 重试，输入其他返回");
            char Jud;
            Jud = getch();
            if('1' == Jud) AdminLogin();
            else {
                // 返回原来界面;
                CHOICE = 0;
                LOGINTIMES = 5;
            }
        } else {
            CHOICE = 0;
        }
        
    }

}

void AdminMainSys() {
    system("cls");
    puts("\t\t\t=================================");
    puts("\t\t\t*         1  所有歌曲\t\t*");
    puts("\t\t\t*         2  删除歌曲\t\t*");
    puts("\t\t\t*         3  修改密码\t\t*");
    puts("\t\t\t*         0  退    出\t\t*");
    puts("\t\t\t=================================");
    printf("\t\t\t请输入选项[ ]\b\b");
    char ADCH;
    while(ADCH = getch()) {
        ADMINCHOICE = ADCH - '0';
        if(ADMINCHOICE >= 0 && ADMINCHOICE <= 6) {
            putchar(ADCH);
            getchar(); // del \n
            Sleep(1000);
            break;
        }
    }
    switch(ADMINCHOICE) {
        case QUIT:
            AdminQuit(); // 退出管理界面
            break;
        case CHANGEPASS:
            ChangePass(); // 修改管理员密码
            break;
        case ADALLSONGS: // 展示全部歌曲;
            AllAdSong();
            break;
        case DELETESONG: // 删除歌曲；
            DeleteSong();
            break;
    }
    if(9 == ADMINCHOICE) {
        AdminMainSys();
    }
}

void AdminQuit() {
    CHOICE = 0;
    return ;
}

void ChangePass() {
    system("cls");
    puts("   \t\t\t*******密码修改*******");
    printf("\t\t\t old password: [            ]\b\b\b\b\b\b\b\b\b\b\b\b");
    int Places = 0;
    char c;
    char ReInputAdPa[ADMINPASSLENG];
    char NewADPa[ADMINPASSLENG];
    while(Places++ < ADMINPASSLENG - 1) {
        c = getch();
        if('\r' == c) {
            break;
        } else {
            if(' ' == c) {
                Places--;
                continue;
            }
        }
        printf("*");
        ReInputAdPa[Places - 1] = c;
    }
    ReInputAdPa[Places] = '\0';
    Places = 0;
    printf("\n\t\t\t new password: [            ]\b\b\b\b\b\b\b\b\b\b\b\b");
    while(Places++ < ADMINPASSLENG - 1) {
        c = getch();
        if('\r' == c) {
            break;
        } else {
            if(' ' == c) {
                Places--;
                continue;
            }
        }
        printf("*");
        NewADPa[Places - 1] = c;
    }
    NewADPa[Places] = '\0';
    if(0 == strcmp(FirstAdmin.AdminPass, ReInputAdPa)) {
        FILE* fp_updpass = fopen("admin.txt", "r");
        fscanf(fp_updpass,"%s",FirstAdmin.AdminName);
        fscanf(fp_updpass, "%s",FirstAdmin.AdminPass);
        memset(FirstAdmin.AdminPass,0, sizeof(FirstAdmin.AdminPass));
        strcpy(FirstAdmin.AdminPass, NewADPa);
        fclose(fp_updpass);
        fp_updpass = fopen("admin.txt", "w");
        fprintf(fp_updpass, "%s\n", FirstAdmin.AdminName);
        fprintf(fp_updpass, "%s", FirstAdmin.AdminPass);
        fclose(fp_updpass);

        printf("密码已更新，请重新登录！");
    } else {
        puts("密码更新错误，请选择重新修改（r），或取消（c）");
        c = getch();
        if('r' == c) ChangePass();
        else if('c' == c) {
            ADMINCHOICE = 9;
        }
    }


    return ;
}

void AllAdSong() {
    SongPointer adhead = SShead;
    adhead = adhead->NextSong;
    while(adhead) {
        printf("\t\t\t%s -- %s -- %s -- %d\n",adhead->Name, adhead->SongN, adhead->Type,adhead->SeNum);
        adhead = adhead->NextSong;
    }
    printf("\t\t\t按 0 退出 [   ]\b\b");
    char chj;
    chj = getch();
    if('0' == chj) {
        putchar(chj);
        getchar();
        AdminMainSys();
    }
}

void DeleteSong() {
    printf("\t\t\t请输入需要删除歌曲的编号 [   ]\b\b\b");
    int DELSONG;
    scanf("%d%*c",&DELSONG);
    ListDel(DELSONG);
}

void ListDel(int number) {
    // *
    SongPointer cur, last;
    cur = SShead;
    last = cur->NextSong;
    int FlagFinish = 0;
    while(last != NULL) {
        if(number == last->SeNum) {
            SongPointer dfe = last;
            cur->NextSong = last->NextSong;
            free(dfe);
            FlagFinish = 1;
            break;
        } else {
            cur = last;
            last = last->NextSong;
        }
    }
    if(0 == FlagFinish) {
        printf("\n\t\t\t删除失败\n");
        return ;
    }
    cur = SShead;
    {
        int i = 1;
        cur = cur->NextSong;
        while(cur) {
            cur->SeNum = i++;
            cur = cur->NextSong; // 大错; ;; 特别注意呀；
        }
    }
    printf("\t\t\t删除成功\n");
    AdminMainSys();
}

