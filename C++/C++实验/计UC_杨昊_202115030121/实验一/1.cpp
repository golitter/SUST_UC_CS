#include <iostream>

namespace golitter {
namespace lab1 {

class primPrinter {

public:
    
    primPrinter(): m_n(100) { sum = 0; }
    primPrinter(int n): m_n(n) { sum = 0; }
    void info();
    ~primPrinter() {
        clear_Allocate_Space();
        }

private:
    int m_n; // �жϴ�1��n������;
    bool *ptr_size = nullptr; // ����СΪn��bool��������ָ��
    int *ptr_prime = nullptr; // ������
    int sum;
    bool allocate_Space_For_boolArray(); 
    void clear_Allocate_Space(); 
    void linear_Screen();
    
};

// ��ӡ��Ϣ
void primPrinter::info() {
    linear_Screen();
    std::cout<<"���������� "<<sum<<'\n';
    int cnt(0);
    for(int i = 0; i < sum; ++i) {
        cnt++;
        if(cnt %6 == 0) std::cout<<'\n';
        std::cout<<ptr_prime[i]<<" ";
    }
}
// ���
void primPrinter::clear_Allocate_Space() {
    if(this->ptr_size != nullptr) {
        delete [] this->ptr_size;
        delete [] this->ptr_prime;
    }
}
// �����СΪn��������
bool primPrinter::allocate_Space_For_boolArray() {
    if(this->ptr_size != nullptr) {
        clear_Allocate_Space();
    }
    
    this->ptr_size = new bool[this->m_n + 1];
    this->ptr_prime = new int [this->m_n + 1];

    for(int i = 0; i <= this->m_n; ++i) {
        ptr_size[i] = false;
    }
    
    return true;
}
// ����ɸ������
void primPrinter::linear_Screen() {
    if(!allocate_Space_For_boolArray()) { // err
        return ;
    }
    int n = m_n;
    for(int i = 2; i <= n; ++i) {
        if(!ptr_size[i]) ptr_prime[sum++] = i;

        for(int j = 0; ptr_prime[j] <= n/i; ++j) {
            ptr_size[ ptr_prime[j] * i] = true;
            if(i % ptr_prime[j] == 0) break;
        }
    }
}
}}

using golitter::lab1::primPrinter;
int main()
{
    primPrinter a(34);
    a.info();
       
    std::cout<<"hello world"<<std::endl;
}