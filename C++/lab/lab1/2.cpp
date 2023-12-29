#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
namespace golitter {
namespace lab1 {
    using std::cout;
class scoreProcessor {
public:
    scoreProcessor() {}
    scoreProcessor(int M, int N):m_M(M), m_N(N) {
        allocationSpace();
        test_inputOtherInfo();
        // inputOtherInfo();
    }
    void sort_columns(int col);
    void info();
    void input_M_and_N(int M, int N);
    void inputOtherInfo();
    void findName(std::string name);
    ~scoreProcessor() {
        (*d2_score).clear();
        delete d2_score;
        delete [] ptr_nameMap;
    }
private:
    int m_M;
    int m_N;
    std::string *ptr_nameMap = nullptr;
    std::vector< std::vector<double> > *d2_score = nullptr; // ��ѧ�����з���

    void allocationSpace();
    void quick_sort(int l, int r, int col);
    void test_inputOtherInfo();
};
// �����ά����ռ�
void scoreProcessor::allocationSpace() {
    d2_score =  new std::vector< std::vector<double> >(m_M);
    ptr_nameMap = new std::string[m_M];
}
// ����M��N
void scoreProcessor::input_M_and_N(int M, int N) {
    m_M = M;
    m_N = N;
}
// ����
void scoreProcessor::test_inputOtherInfo() {

    ptr_nameMap[0] = "kerwin";
    ptr_nameMap[1] = "golitter";
    ptr_nameMap[2] = "golemon";
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 4; ++j) {
            (*d2_score)[i].push_back(rand());
        }
    }
}
// �����ά������
void scoreProcessor::inputOtherInfo() {
    for(int i = 0; i < m_M; ++i) {
        std::cin>>ptr_nameMap[i]; // ������������ֵ�ӳ��

        double sum(0), inp;
        for(int j = 0; j < m_N; ++j) {
            std::cin>>inp;
            (*d2_score)[2].push_back(inp);
            sum += inp;
        }
        (*d2_score)[2].push_back(sum);
    }
}
// ����
void scoreProcessor::quick_sort(int l, int r, int col) {
    if(l >= r) return ;

    int i = l - 1, j = r + 1;
    double x = (*d2_score)[l + r >> 1][col];
    while(i < j) {
        do i++; while((*d2_score)[i][col] < x);
        do j--; while((*d2_score)[j][col] > x);
        if(i < j) swap(ptr_nameMap[i], ptr_nameMap[j]), swap( (*d2_score)[i], (*d2_score)[j]);
    }
    quick_sort(l, j, col);
    quick_sort(j+1, r, col);
}

/// @brief �������Զ�ѧ��������������
/// @param col 
void scoreProcessor::sort_columns(int col) {
    quick_sort(0, m_M - 1, col);
}
// ��ӡ��Ϣ
void scoreProcessor::info() {
    for(int i = 0; i < m_M; ++i) {
        std::cout<<ptr_nameMap[i]<<" :  ";
        for(int j = 0; j < m_N; ++j) {
            std::cout<<(*d2_score)[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}
// �������� & ��ӡ����
void scoreProcessor::findName(std::string name) {
    int order(0);
    for(order; order < m_M; ++order) {
        if(ptr_nameMap[order] == name) {
            break;
        }
    }
    if(order == m_M) {
        std::cout<<"���޴���"<<std::endl;
        return ;
    }
    for(int i = 0; i < m_N; ++i) {
        std::cout<<(*d2_score)[order][i]<<" ";
    }
    puts("");
}
}} 
using golitter::lab1::scoreProcessor;
void solve() {
    scoreProcessor s(3,4);
    s.info();
    s.sort_columns(3);
    puts("");
    s.info();
    s.findName("kerwin");
}
int main()
{
    solve();
    return 0;
}
