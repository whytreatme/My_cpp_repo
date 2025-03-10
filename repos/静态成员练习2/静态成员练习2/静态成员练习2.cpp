// 静态成员练习2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Counter {
    
public:
    int mem;
    Counter(int a) {
        mem = a;
    }
    static int semem;
    ~Counter(){};
};
int Counter::semem = 1;
int main()
{ 
    Counter c(5);
    
    for (int i = 0; i < 5; ++i) {
        Counter::semem += i;
        cout << Counter::semem << '\t';
    }
    cout << Counter::semem << endl;
    cout << c.mem << endl;
    
}
