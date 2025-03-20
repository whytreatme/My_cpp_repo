// 胡光做法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
#define INF 0x3f3f3f3f
#define DEBUG 0

using namespace std;
long long calcu(string& s,int l,int r) {
    int pos = -1, pri = INF-1, cur_pri, temp_pri=0;
    for (int i = l; i < r; i++) {
        cur_pri = INF;
        switch (s[i]) {
        case '+':
        case '-':
            cur_pri = 1 + temp_pri;
            break;
        case '*':
        case '/':
            cur_pri = 2 + temp_pri;
            break;
        case '^':
            cur_pri = 3 + temp_pri;
            break;
        case '(':
            temp_pri += 100;
            break;
        case ')':
            temp_pri -= 100;
            break;
        }
        if (pri >= cur_pri) {
            pos = i;
            pri = cur_pri;
        }
#if DEBUG
        {
            cout << "now s[i] is " << s[i] << endl
                << "now pos is " << pos << endl
                << "pri is " << pri << endl;
        }
#endif
    }
    
    if (pos == -1) {
        long long sum = 0;
        for (int i = l; i < r; i++) {
            if (s[i] < '0' || s[i]>'9')continue;
            sum = sum * 10 + (s[i]-'0');
        }
        return sum;
    }
    else {
        long long a = calcu(s, l, pos), b=calcu(s, pos + 1, r);
        switch (s[pos])
        {
        case '+':return (a + b);
        case '-':return (a - b);
        case '*':return (a * b);
        case '/':return (a / b);
        case '^':return pow(a, b);

        }
    }
}

int main()
{
    string str;
    cin >> str;
    cout << calcu(str, 0, str.size()) << endl;
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
