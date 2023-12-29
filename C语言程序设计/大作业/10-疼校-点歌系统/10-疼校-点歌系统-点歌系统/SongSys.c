#ifndef _SONGSYS_
#define _SONGSYS_

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//#include "SongSong.c"

#define SINGEROPT 1
#define SINGOPT 2
#define ALLSING 3
#define SINGSWITCH 4
#define SINGEXIT 0
#define SONGERPRINT ("\t\t\t*************���ֵ��*************\t\t\n")
#define SINGPRINT ("\t\t\t*************�������*************\t\t\n")
#define SINGTYPEPRINT ("\t\t\t**********�������͵��*************\t\t\n")
#define ALLPRINT ("\t\t\t***************���*************\t\t\n")
extern int CHOICE;
int SONGCHOICE;

typedef struct song {
    char Name[100]; // ��������
    char SongN[100]; // ������������
    char Type[100]; // ��������
    char address[100]; // ������ַ
    struct song* NextSong; // ����ָ�� ͷ�巨 <----
    int Num; // ��ͨ�û�����ĸ�����ţ�
    //struct song* AdNextSong;
    int SeNum; // ����Ա����ĸ������
} Song, *SongPointer; 
// head -->  SongList;
SongPointer SShead;
SongPointer Ad; // ����Աϵͳ�Ľṹ��ָ�룻

// ��������
void SongMainSys(); 
// ���ֵ��
void SingerOpt(); 
// �������
void SongOpt(); 
// ���и���
void AllSong(); 
// �и裻
int SongSwitch(int number); 
// ��������
int PlayMusic(int number, int StorSt); 
// �������ֿ�
void ImportMusic(); 

// �������� -- > 
/**
 * @brief 
 * char �� wchar �Ƚϣ�
 * ////Ӧ�ò���Ҫ, �ڽṹ�����ڶ���һ��,
 * char Ӧ��Ҳ���ԡ�
 */
// ��������
void SortSong(); 
// ���ַ���
void SortSinger(); 
// �������ͷ���
void SortType(); 

SongPointer OnePointTwo(SongPointer sshead, int singchoice);
SongPointer ListMerge(SongPointer head, SongPointer mid,int singchoice);
SongPointer AddHead(SongPointer sshead); // ����ͷ��㣻
void PrintResult(int songchoice); // ��ӡ���

void SongMainSys() {
    system("cls");
    char SONGCH;
    puts("\t\t\t=================================");
    puts("\t\t\t*         1  ���ֵ��\t\t*");
    puts("\t\t\t*         2  �������\t\t*");
    puts("\t\t\t*         3  ���͵��\t\t*");
    puts("\t\t\t*         0  ��    ��\t\t*");
    puts("\t\t\t=================================");
    printf("\t\t\t������ѡ��[ ]\b\b");
    while(SONGCH = getch()) {

        SONGCHOICE = SONGCH - '0';
        if(SONGCHOICE >= 0 && SONGCHOICE <= 3) {
            putchar(SONGCH);
            Sleep(1000);
            getchar();
            break;
        }
    }
    switch(SONGCHOICE) {
        case SINGEROPT:
            SortSinger();
            break;
        case SINGOPT:
            SortSong();
            break;
        case ALLSING:
            SortType();
            break;
        case SINGSWITCH:
            SongMainSys();
            break;
        case SINGEXIT:
            CHOICE = 0;
            break;
        default:
            SongMainSys();
    }
    if(SONGCHOICE >= 1 && SONGCHOICE <= 3) {
        int SOPT;
        scanf("%d%*c", &SOPT);
        /**
         * @brief Construct a new if object
         * ����Ϊʲô�� �� %*c��
         * �����ʾ�����ַ������ǲ������
         * ��Ϊ�������� '\n', ��������»������������'\n'�ַ��� �ᵼ�µڶ��ν�����ϵͳ��
         * ��������������һ��;
         */
        if(SOPT == 0) {
            SongMainSys();
        } else { 
            int _SONGTRUE_ = 1;
        while(_SONGTRUE_) {

            if(PlayMusic(SOPT,1)) {
           
                int tagSOPT = SOPT;
                printf("\t\t\t���ڲ�������\n");
                printf("\t\t\t�� -1 �и裬�� -2 �˳�����"); // �и貿�� ./
                printf("[    ]\b\b\b");
                scanf("%d%*c",&SOPT);
                if(SOPT == -1) {
                    // �и裻
                    PlayMusic(tagSOPT, 2);
                    printf("\t\t\t��ѡ��Ҫ���ŵ����ֱ�� [   ]\b\b\b");
                    scanf("%d",&SOPT);
                    // ��ֹͣ�������֣�
                    // ���������棬
                    // 
                    //SongMainSys();
                    //getchar();
                } else if(-2 == SOPT) {
                    PlayMusic(tagSOPT, 2);
                    // �˳����棻
                    _SONGTRUE_ = 0;
                    SongMainSys();
                    break;
                    
                }
            } else {
                _SONGTRUE_ = 0;
                SongMainSys();
            }
    }
        }
    }
    
}

int PlayMusic(int number,int StorSt) {
    SongPointer findsg = SShead;//->NextSong;
    int count = 0;
    while(count++ < number && findsg != NULL) {
        findsg = findsg->NextSong;
    }
    if(findsg == NULL) {
        return 0;
    } else {
        // findsg.Address -->;
        char MciMusicpp[101];
        strcpy(MciMusicpp, "open ");
        strcat(MciMusicpp, findsg->address);
        strcat(MciMusicpp, " alias music");
        mciSendString(MciMusicpp, NULL, 0, NULL);
        char playm[101] = "play music";
        char stopm[101] = "close music";
        if(1 == StorSt) {
            mciSendString(playm, NULL, 0, NULL);
        }
        if(2 == StorSt) {
            mciSendString(stopm, NULL, 0, NULL);
        }
        return 1;
    }
}

void ImportMusic() {
    // �������֣�
    SShead = (SongPointer)malloc(sizeof(Song));
    SShead->NextSong = NULL;
    char SongTxtInp[100];
    FILE *fp_Song = fopen("Song.txt","r");
    {
        int i = 1;


        while(0 == feof(fp_Song)) {
            SongPointer song = (SongPointer)malloc(sizeof(Song));
            fscanf(fp_Song, "%[^\n]%*c",song->Name);
            //getchar();
            fscanf(fp_Song, "%[^\n]%*c",song->SongN);
            //getchar();
            fscanf(fp_Song, "%[^\n]%*c",song->Type);
            //getchar();
            fscanf(fp_Song,"%[^\n]%*c",song->address);
            song->SeNum = i++;

            // ���� ͷ�巨;
            song->NextSong = SShead->NextSong;
            SShead->NextSong = song;

            if(feof(fp_Song)) {
                break;
            }
            if(ferror(fp_Song)) {
                printf("Error!");
                break;
            }
        }
    }
    fclose(fp_Song);
    
    return ;
}

void PrintResult(int singchoice) {
    SongPointer SongPP = SShead;
    SongPP = SongPP->NextSong;  // ***************
    system("cls");
    switch(singchoice) {
        case SINGEROPT:
            printf(SONGERPRINT);
            {
                int i = 1;
                while(SongPP != NULL) {
                    SongPP->Num = i++;
                    printf("\t\t\t%s ----%s ----%s -- %d\n ",SongPP->SongN,SongPP->Name,SongPP->Type,SongPP->Num);
                    SongPP = SongPP->NextSong;
                }
                printf("\t\t\t�����������ţ�[   ]\b\b\b");
            }
            break;
        case SINGOPT:
            printf(SINGPRINT);
            {
                int i = 1;
                while(SongPP) {
                    SongPP->Num = i++;
                    printf("\t\t\t%s ----%s ----%s --%d\n",SongPP->Name,SongPP->SongN,SongPP->Type,SongPP->Num);
                    SongPP = SongPP->NextSong;
                }
                printf("\t\t\t�����������ţ�[   ]\b\b\b");
                // getchar();
            }
            break;
        case ALLSING:
            printf(SINGTYPEPRINT);
            {
                int i = 1;
                while(SongPP) {
                    SongPP->Num = i++;
                    printf("\t\t\t%s ----%s ---- %s --%d\n",SongPP->Type,SongPP->Name,SongPP->SongN,SongPP->Num);
                    SongPP = SongPP->NextSong;
                }
                printf("\t\t\t�����������ţ�[   ]\b\b\b");
                // getchar();
            }
            break;
    }
}
void SortSong() {
    SShead = SShead->NextSong;
    SShead = OnePointTwo(SShead,SINGOPT);    
    SShead = AddHead(SShead);
    PrintResult(SINGOPT);
}
void SortSinger() {
    SShead = SShead->NextSong;
    SShead = OnePointTwo(SShead,SINGEROPT);
    SShead = AddHead(SShead);
    PrintResult(SINGOPT);
}
void SortType() {
    SShead = SShead->NextSong;
    SShead = OnePointTwo(SShead,ALLSING);
    SShead = AddHead(SShead);
    PrintResult(ALLSING);
}
SongPointer OnePointTwo(SongPointer sshead, int singchoice) {
    if(sshead == NULL) {
        return sshead;
    }
    if(sshead->NextSong == NULL) {
        return sshead;
    }
    SongPointer Left = sshead;
    SongPointer Mid = sshead->NextSong;
    SongPointer Right = Mid->NextSong;
    while(Right != NULL && Right->NextSong != NULL) {
        Left = Left->NextSong;
        Mid = Mid->NextSong;
        Right = Right->NextSong->NextSong;
    }
    Left->NextSong = NULL;

    return ListMerge(OnePointTwo(sshead, singchoice),OnePointTwo(Mid,singchoice),singchoice);
}
SongPointer ListMerge(SongPointer head, SongPointer mid, int singchoice) {
    if(head == NULL) {
        return mid;
    }
    if(mid == NULL) {
        return head;
    }
    SongPointer hhead = (SongPointer)malloc(sizeof(Song));
    hhead->NextSong = NULL;
    SongPointer Cur = hhead;
    if(SINGEROPT == singchoice) {
        while(head && mid) {
            if(strcmp(head->SongN,mid->SongN) <= 0) {
                Cur->NextSong = head;
                head = head->NextSong;
            } else {
                Cur->NextSong = mid;
                mid = mid->NextSong;
            }
            Cur = Cur->NextSong;
        }
    } else if(SINGOPT == singchoice) {
            while(head && mid) {
                if(strcmp(head->Name,mid->Name) <= 0) {
                    Cur->NextSong = head;
                    head = head->NextSong;
                } else {
                    Cur->NextSong = mid;
                    mid = mid->NextSong;
                }
                Cur = Cur->NextSong;
            }
    } else if(ALLSING == singchoice) {
        while(head && mid) {
            if(strcmp(head->Type,mid->Type) <= 0) {
                Cur->NextSong = head;
                head = head->NextSong;
            } else {
                Cur->NextSong = mid;
                mid = mid->NextSong;
            }
            Cur = Cur->NextSong;
        }
    }
    Cur->NextSong = head? head: mid;
    hhead = hhead->NextSong;
    return hhead;

}
SongPointer AddHead(SongPointer sshead) {
    SongPointer Shead = (SongPointer)malloc(sizeof(Song));
    Shead->NextSong = sshead;
    sshead = Shead;
    return sshead;
}
#endif

