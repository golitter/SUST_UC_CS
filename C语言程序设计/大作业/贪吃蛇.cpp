#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define frame_height 30
#define frame_width 50
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

int i,j,k,sp,score;
char ch=UP,state=UP,choo,n;//��ʼ������
int grow=0;

struct Food//ʳ��
{
    int x;//������
    int y;//������
} food;

struct Snake//��
{
    /*�����鴢���ߵ�ÿһ���ֵ�����*/
    int x[100];
    int y[100];
    int len;//����
    int speed;//�ٶ�
} snake;

void map(void);//��ͼ
void update_food(void);//����ʳ��
void move_snake(void);//�ߵ��ƶ�
int alive(void);//�ж����Ƿ�����
void get_speed(void);//�����ٶ�
void gotoxy(int x,int y);//�ƶ���꣬������Ϸ����Ĵ�ӡ


int main()
{
    do
    {
        score=0;//��ʼ������Ϊ0
        /*���û������Ѷ�ѡ���вʵ�*/
        printf("Choose the degree of difficulty:\n1:easy\t2:middle  3:difficult\n");
        n=getch();
        switch(n)
        {
        case '1':
        {
            sp=300;
            break;
        }
        case '2':
        {
            sp=230;
            break;
        }
        case '3':
        {
            sp=180;
            break;
        }
        default:
        {
            printf("Congratulations!Welcome to Devil's difficulty\n");
            sp=120;
            break;
        }
        }
        system("cls");//ÿ����һ����Ϸ������,������<stdlib.h>
        map();//��ӡ��ͼ
        /*��ʼ��Ϸ*/
        while(1)
        {
            update_food();//����ʳ��
            get_speed();//��ȡ�ٶ�
            move_snake();//�ƶ�
            Sleep(snake.speed);//��ʱ����,speed��ֵԽ����ʱԽ��
            if(!(alive()))//�ж����Ƿ�����
            {
                break;//�������˳�ѭ��
            }
        }
        printf("Game Over!\n");
        printf("1:Restart\t2:exit");
        choo=getch();
    }
    while(choo=='1');
    return 0;
}

void map()
{
    srand(time(NULL));
    /*��ӡ��һ��ʳ��*/
    /*Attention!�˴�����һ��bug:����ʳ��
    ��λ�����ʼ�����غϣ�Ȼ��ʳ��ͻ���
    ʧ�����߿��Լ��ԸĽ�*/
    food.x=rand()%(frame_height-2)+1;
    food.y=rand()%(frame_width-2)+1;//�ڿ���
    gotoxy(food.x,food.y);//�ѹ���ƶ���������
    printf("$");//��ӡʳ��

    /*snake�ĳ�ʼ��*/
    snake.x[0]=frame_height/2;
    snake.y[0]=frame_width/2;
    gotoxy(snake.x[0],snake.y[0]);
    printf("@");
    snake.len=3;
    snake.speed=200;
    for(k=1; k<snake.len; k++)
    {
        snake.x[k]=snake.x[k-1]+1;
        snake.y[k]=snake.y[k-1];
        gotoxy(snake.x[k],snake.y[k]);
        printf("@");
    }
    /*ǽ��*/
    for(j=0; j<frame_width; j++)
    {
        gotoxy(0,j);
        printf("#");
        gotoxy(frame_height-1,j);
        printf("#");
    }
    for(i=0; i<frame_height-1; i++)
    {
        gotoxy(i,0);
        printf("#");
        gotoxy(i,frame_width-1);
        printf("#");
    }
    gotoxy(2,frame_width+3);
    if(n=='1') printf("Difficulty:   easy");
    else if(n=='2') printf("Difficulty:   middle");
    else if(n=='3') printf("Difficulty:   difficult");
    else printf("Welcome to the Devil's difficulty");
    gotoxy(4,frame_width+3);
    printf("UP:   w");
    gotoxy(6,frame_width+3);
    printf("DOWN: s");
    gotoxy(8,frame_width+3);
    printf("LEFT: a");
    gotoxy(10,frame_width+3);
    printf("RIGHT:d");
    gotoxy(12,frame_width+3);
    printf("Your score:%d",score);
    gotoxy(28,frame_width+3);
    printf("Made by ����� �º� ֣����");
}
/*ʳ��*/
void update_food()
{
    if(snake.x[0]==food.x&&snake.y[0]==food.y)//�Ե�ʳ��
    {
        score+=10;
        gotoxy(12,frame_width+3);
        printf("Your score:%d",score);
        srand(time(NULL));
        /*�����Ǹ���ʳ��Ĵ���,�����ų���
        ʳ�������غϵ����,���߿��Բο���
        �´�����ɶ�����bug�ĸĽ�*/
        int flag=1;//��Ǳ���
        do
        {
        food.x=rand()%(frame_height-2)+1;
        food.y=rand()%(frame_width-2)+1;//�ڿ���
        for(i=0; i<snake.len; i++)
        {
            if(food.x==snake.x[i]&&food.y==snake.y[i])
            {
                flag=0;//���غ�
                break;
            }
        }
        }
        while(flag==0);
        /*��ӡʳ��*/
        gotoxy(food.x,food.y);
        printf("$");
        snake.len++;
        grow=1;//�������ˣ���move_snake���������õ�
    }
}
/*�ƶ���*/
void move_snake()
{
    while(kbhit())//����������
    {
        ch=getch();
    }
    if(!grow)//û�г�
    {
        gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
        printf(" ");//���ˣ������������ӡ�ո����ԭ�е���β
    }
    for(k=snake.len-1; k>0; k--)//�����ߵ����꣬������ͷ,����λ�ü̳���һ���������
    {
        snake.x[k]=snake.x[k-1];
        snake.y[k]=snake.y[k-1];//�ƶ�λ��
    }
    switch(ch)//�ı䷽��
    {
    case UP:
    {
        if(state==DOWN)//�����ʱ�������£��������ϵ�����Ҫ������
        {
            snake.x[0]++;
            break;
        }
        else
        {
            snake.x[0]--;
            state=UP;//����ĸı�״̬Ϊ����
            break;
        }
    }
    case DOWN:
    {
        if(state==UP)
        {
            snake.x[0]--;
            break;
        }
        else
        {
            snake.x[0]++;
            state=DOWN;
            break;
        }
    }
    case LEFT:
    {
        if(state==RIGHT)
        {
            snake.y[0]++;
            break;
        }
        else
        {
            snake.y[0]--;
            state=LEFT;
            break;
        }
    }
    case RIGHT:
    {
        if(state==LEFT)
        {
            snake.y[0]--;
            break;
        }
        else
        {
            snake.y[0]++;
            state=RIGHT;
            break;
        }
    }
    /*�������,����ԭ��״̬*/
    default:
    {
        if(state==DOWN)
        {
            snake.x[0]++;
            break;
        }
        else if(state==UP)
        {
            snake.x[0]--;
            break;
        }
        else if(state==LEFT)
        {
            snake.y[0]--;
            break;
        }
        else if(state==RIGHT)
        {
            snake.y[0]++;
            break;
        }

    }
    }
    gotoxy(snake.x[0],snake.y[0]);
    printf("@");//��ӡ��ͷ
    grow=0;//��ʼ�ɳ�״̬Ϊ0
    gotoxy(frame_height,0);//����ƶ�����ͼ���½��·�
}
/*���״̬*/
int alive(void)
{
    if(snake.x[0]==0||snake.x[0]==frame_height-1||snake.y[0]==0||snake.y[0]==frame_width-1)//ײǽ
        return 0;
    for(k=1; k<snake.len; k++) //ҧ���Լ�
    {
        if(snake.x[0]==snake.x[k]&&snake.y[0]==snake.y[k])
            return 0;
    }
    return 1;
}
/*����*/
/*speedԽ��,�ߵ��ٶ�ԽС*/
void get_speed()
{
    if(snake.len<=6)
        snake.speed=sp;
    else if(snake.len<=10)
        snake.speed=sp-20;
    else if(snake.len<=20)
        snake.speed=sp-50;
    else if(snake.len<=30)
        snake.speed=sp-60;
    else
        snake.speed=sp-70;
}
/*�ƶ����*/
void gotoxy(int x,int y)
{
    HANDLE hout;
    COORD cor;
    /*
    typedef struct _COORD
    {
        SHORT X; // horizontal coordinate
        SHORT Y; // vertical coordinate
    } COORD;
    �øýṹ������������
    */
    hout=GetStdHandle(STD_OUTPUT_HANDLE);//�ӱ�׼����豸��ȡ��һ�����
    /*������x,y�ĸ�ֵ����Ҫע��,�����ĺú�����*/
    cor.X=y;
    cor.Y=x;
    SetConsoleCursorPosition(hout,cor);//��λ���ĺ���
}



