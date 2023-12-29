#include <iostream>
using namespace std;

// 宏定义和条件编译
#define PI 3.1415926
#ifndef MAX_NUM
#define MAX_NUM 50
#endif

int main()
{
    // 定义各种数据类型变量
    int num1 = 10;
    float num2 = 3.14f;
    double num3 = 5.6789;
    char ch1 = 'A';
    bool flag = true;

    // 常量指针
    int value1 = 100;
    const int *ptr1 = &value1;
    cout << "ptr1指向的内存单元的值为：" << *ptr1 << endl;
    int value2 = 200;
    ptr1 = &value2;
    cout << "ptr1指向的内存单元的值为：" << *ptr1 << endl;

    // 指针常量
    int a = 10, b = 20;
    int *const ptr2 = &a;
    *ptr2 = 30;
    cout << "a的值为：" << a << endl;
    // ptr2 = &b;  //编译错误，指针常量的值不能被修改

    // if语句和switch语句
    if (num1 > 0)
    {
        cout << "num1是正数" << endl;
    }
    else if (num1 < 0)
    {
        cout << "num1是负数" << endl;
    }
    else
    {
        cout << "num1是零" << endl;
    }

    switch (ch1)
    {
    case 'A':
        cout << "ch1是大写字母A" << endl;
        break;
    case 'a':
        cout << "ch1是小写字母a" << endl;
        break;
    default:
        cout << "ch1不是字母" << endl;
        break;
    }

    return 0;
}
