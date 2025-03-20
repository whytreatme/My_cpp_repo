// 栈的序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#include<vector>
using namespace std;
//bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//    std::stack<int> s1;
//        
//    for(int i=0,j=0;j<popped.size();)
//    {
//        while((i<pushed.size())&&pushed[i] <= popped[j]) {
//            s1.push(pushed[i]);
//            i++;
//        }
//        if(s1.empty()||s1.top()!=popped[j])return false;
//        s1.pop();
//        j++;
//    }
//    return true;
//   
//}
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    std::stack<int> s1;
    for (int i = 0, j = 0; j < popped.size();)
    {
        if (s1.empty() || popped[j] != s1.top())
        {
            while ((i < pushed.size()) && pushed[i] != popped[j]) {
                s1.push(pushed[i]);
                i++;
            }
            if (i == pushed.size())return false;
            s1.push(pushed[i]);
            i++;
        }
           
        s1.pop();
        j++;
    }
    return true;
}
int main()
{
    bool flag = false;
    std::stack<int> s1;
    vector<int>pushed = { 1,2,3,4,5};
    vector<int> popped = { 4,5,3,2,1};
    
   
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
