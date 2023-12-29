#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
namespace golitter {
namespace lab5 {
class FileObject {
public:

    FileObject(const char* filename) { 
        fileptr = new char[strlen(filename) + 1];
        strcpy(fileptr, filename);
        open();
    }
    void open() {
        fo.open(fileptr, ios::out);
    }
    void write(const char* content) {
        fo<<content<<endl;
    }
    void append(const char* content) {
        close();
        fo.open(fileptr, ios::out | ios::app);
        write(content);
    }
    void close() {
        if(!fo.good()) return ;
        fo.close();
    }
    ~FileObject() {fo.close(); delete [] fileptr; }
private:
    ofstream fo;
    char * fileptr;
    FileObject() {}
};
}}
using golitter::lab5::FileObject;
void solve() {
    FileObject a("222.txt");
    a.write("dskljfkldjf");
    a.append("dkjfdlfj");
}
int main()
{
    solve();
}