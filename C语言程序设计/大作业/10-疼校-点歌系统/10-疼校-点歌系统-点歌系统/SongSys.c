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
#define SONGERPRINT ("\t\t\t*************歌手点歌*************\t\t\n")
#define SINGPRINT ("\t\t\t*************歌名点歌*************\t\t\n")
#define SINGTYPEPRINT ("\t\t\t**********歌曲类型点歌*************\t\t\n")
#define ALLPRINT ("\t\t\t***************点歌*************\t\t\n")
extern int CHOICE;
int SONGCHOICE;

typedef struct song {
    char Name[100]; // 歌曲名字
    char SongN[100]; // 歌曲歌手名字
    char Type[100]; // 歌曲类型
    char address[100]; // 歌曲地址
    struct song* NextSong; // 歌曲指针 头插法 <----
    int Num; // 普通用户界面的歌曲编号；
    //struct song* AdNextSong;
    int SeNum; // 管理员界面的歌曲编号
} Song, *SongPointer; 
// head -->  SongList;
SongPointer SShead;
SongPointer Ad; // 管理员系统的结构体指针；

// 歌主界面
void SongMainSys(); 
// 歌手点歌
void SingerOpt(); 
// 歌曲点歌
void SongOpt(); 
// 所有歌曲
void AllSong(); 
// 切歌；
int SongSwitch(int number); 
// 播放音乐
int PlayMusic(int number, int StorSt); 
// 导入音乐库
void ImportMusic(); 

// 链表排序 -- > 
/**
 * @brief 
 * char 和 wchar 比较；
 * ////应该不需要, 在结构体中在定义一个,
 * char 应该也可以。
 */
// 歌曲分类
void SortSong(); 
// 歌手分类
void SortSinger(); 
// 歌曲类型分类
void SortType(); 

SongPointer OnePointTwo(SongPointer sshead, int singchoice);
SongPointer ListMerge(SongPointer head, SongPointer mid,int singchoice);
SongPointer AddHead(SongPointer sshead); // 增加头结点；
void PrintResult(int songchoice); // 打印结果

void SongMainSys() {
    system("cls");
    char SONGCH;
    puts("\t\t\t=================================");
    puts("\t\t\t*         1  歌手点歌\t\t*");
    puts("\t\t\t*         2  歌名点歌\t\t*");
    puts("\t\t\t*         3  类型点歌\t\t*");
    puts("\t\t\t*         0  退    出\t\t*");
    puts("\t\t\t=================================");
    printf("\t\t\t请输入选项[ ]\b\b");
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
         * 关于为什么有 ： %*c；
         * 这个表示输入字符，但是不输出；
         * 因为缓存区有 '\n', 如果不更新或清除缓冲区的'\n'字符， 会导致第二次进入点歌系统后，
         * 输入歌曲编号在下一行;
         */
        if(SOPT == 0) {
            SongMainSys();
        } else { 
            int _SONGTRUE_ = 1;
        while(_SONGTRUE_) {

            if(PlayMusic(SOPT,1)) {
           
                int tagSOPT = SOPT;
                printf("\t\t\t正在播放音乐\n");
                printf("\t\t\t按 -1 切歌，按 -2 退出界面"); // 切歌部分 ./
                printf("[    ]\b\b\b");
                scanf("%d%*c",&SOPT);
                if(SOPT == -1) {
                    // 切歌；
                    PlayMusic(tagSOPT, 2);
                    printf("\t\t\t请选择要播放的音乐编号 [   ]\b\b\b");
                    scanf("%d",&SOPT);
                    // 先停止播放音乐；
                    // 返回主界面，
                    // 
                    //SongMainSys();
                    //getchar();
                } else if(-2 == SOPT) {
                    PlayMusic(tagSOPT, 2);
                    // 退出界面；
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
    // 导入音乐；
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

            // 链表 头插法;
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
                printf("\t\t\t请输入歌曲编号：[   ]\b\b\b");
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
                printf("\t\t\t请输入歌曲编号：[   ]\b\b\b");
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
                printf("\t\t\t请输入歌曲编号：[   ]\b\b\b");
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

