#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "SongSys.c"
/**
 * @brief 
 * ������� :
 * CHOICE;
 */
extern int CHOICE;
extern SongPointer Ad;
#define AdminLogTimes 5
#define ADMINACCLENG 10  //  ����Ա�˺ų��ȣ���'\0'
#define ADMINPASSLENG 12 // ����Ա���볤��; �� '\0'

int ADMINCHOICE; // ��������ѡ�������

#define QUIT 0
#define CHANGEPASS 3
#define ADALLSONGS 1
#define DELETESONG 2

// ����Ա�ṹ�壻
typedef struct adm {
    char AdminName[ADMINACCLENG]; // ����Ա���֣�
    char AdminPass[ADMINPASSLENG]; // ����Ա���룻
    struct adm* Next;
}Admin, *AdminNode;
Admin FirstAdmin;

// ����Ա��¼��
void AdminLogin(); 
 // ����Ա����;
void AdminMainSys();
// ��������˳� -- > ��ҳ��;
void AdminQuit(); 
// �޸Ĺ���Ա����;
void ChangePass(); 
 // ɾ��������
void DeleteSong();
void ListDel(int number);
// �����ֱ��;



int LOGINTIMES = AdminLogTimes; // ����������������
void AdminLogin() {
    system("cls"); // \t -- TAB ;; \b -- ����;; \t -- Enter;;
    printf("\t\t\t *******����Ա��¼*******\t\n");
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
        printf("\n \t\t\t ��¼�ɹ�������Ϊ����ת����...");
        LOGINTIMES = 5;

        Sleep(1500);
        // ҳ��;;
        //
        AdminMainSys();

    } else {
        LOGINTIMES--;
        if(LOGINTIMES >= 1) {
            printf("\n \t\t\t ��¼���󣬻���%d��",LOGINTIMES);
            printf("\n \t\t\t ���� 1 ���ԣ�������������");
            char Jud;
            Jud = getch();
            if('1' == Jud) AdminLogin();
            else {
                // ����ԭ������;
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
    puts("\t\t\t*         1  ���и���\t\t*");
    puts("\t\t\t*         2  ɾ������\t\t*");
    puts("\t\t\t*         3  �޸�����\t\t*");
    puts("\t\t\t*         0  ��    ��\t\t*");
    puts("\t\t\t=================================");
    printf("\t\t\t������ѡ��[ ]\b\b");
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
            AdminQuit(); // �˳��������
            break;
        case CHANGEPASS:
            ChangePass(); // �޸Ĺ���Ա����
            break;
        case ADALLSONGS: // չʾȫ������;
            AllAdSong();
            break;
        case DELETESONG: // ɾ��������
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
    puts("   \t\t\t*******�����޸�*******");
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

        printf("�����Ѹ��£������µ�¼��");
    } else {
        puts("������´�����ѡ�������޸ģ�r������ȡ����c��");
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
    printf("\t\t\t�� 0 �˳� [   ]\b\b");
    char chj;
    chj = getch();
    if('0' == chj) {
        putchar(chj);
        getchar();
        AdminMainSys();
    }
}

void DeleteSong() {
    printf("\t\t\t��������Ҫɾ�������ı�� [   ]\b\b\b");
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
        printf("\n\t\t\tɾ��ʧ��\n");
        return ;
    }
    cur = SShead;
    {
        int i = 1;
        cur = cur->NextSong;
        while(cur) {
            cur->SeNum = i++;
            cur = cur->NextSong; // ���; ;; �ر�ע��ѽ��
        }
    }
    printf("\t\t\tɾ���ɹ�\n");
    AdminMainSys();
}

