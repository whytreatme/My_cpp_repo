// 胡光做法括号画家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
using namespace std;

#define MAX_N 10000
char str[MAX_N + 5];
int match[MAX_N + 5] = { 0 };
stack<int>s;

int main()
{
    cin >> (str + 1);
    for (int i = 1; str[i]; i++) {
        switch (str[i]) {
        case '(':
        case '[':
        case '{':
            s.push(i);
            break;
        case ')': {
            if (!s.empty() && str[s.top()] == '(') {
                match[s.top()] = i;
                match[i] = s.top(); // delete
                s.pop();
            }
            else
                s.push(i);
            break;
        }
        case ']': {
            if (!s.empty() && str[s.top()] == '[') {
                match[s.top()] = i;
                match[i] = s.top(); // delete
                s.pop();
            }
            else
                s.push(i);
            break;
        }
        case '}': {
            if (!s.empty() && str[s.top()] == '{') {
                match[s.top()] = i;
                match[i] = s.top(); // delete
                s.pop();
            }
            else
                s.push(i);
            break;
        }
        }
    }
    int temp_ans = 0, ans = 0;
    for (int i=1; str[i];) {
        if (match[i]) {
            temp_ans += (match[i] - i )+ 1;
            i = match[i] + 1;
        }
        else {
            i += 1;
            temp_ans = 0;
        }
        if (temp_ans > ans)ans = temp_ans;
   }
  
     cout << ans << endl;
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
