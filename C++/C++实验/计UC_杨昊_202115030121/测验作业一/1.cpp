#include <iostream>
using namespace std;

// �궨�����������
#define PI 3.1415926
#ifndef MAX_NUM
#define MAX_NUM 50
#endif

int main()
{
    // ��������������ͱ���
    int num1 = 10;
    float num2 = 3.14f;
    double num3 = 5.6789;
    char ch1 = 'A';
    bool flag = true;

    // ����ָ��
    int value1 = 100;
    const int *ptr1 = &value1;
    cout << "ptr1ָ����ڴ浥Ԫ��ֵΪ��" << *ptr1 << endl;
    int value2 = 200;
    ptr1 = &value2;
    cout << "ptr1ָ����ڴ浥Ԫ��ֵΪ��" << *ptr1 << endl;

    // ָ�볣��
    int a = 10, b = 20;
    int *const ptr2 = &a;
    *ptr2 = 30;
    cout << "a��ֵΪ��" << a << endl;
    // ptr2 = &b;  //�������ָ�볣����ֵ���ܱ��޸�

    // if����switch���
    if (num1 > 0)
    {
        cout << "num1������" << endl;
    }
    else if (num1 < 0)
    {
        cout << "num1�Ǹ���" << endl;
    }
    else
    {
        cout << "num1����" << endl;
    }

    switch (ch1)
    {
    case 'A':
        cout << "ch1�Ǵ�д��ĸA" << endl;
        break;
    case 'a':
        cout << "ch1��Сд��ĸa" << endl;
        break;
    default:
        cout << "ch1������ĸ" << endl;
        break;
    }

    return 0;
}
