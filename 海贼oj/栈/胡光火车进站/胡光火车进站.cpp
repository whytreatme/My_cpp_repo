// 胡光火车进站.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*************************************************************************
    > File Name : 8.HZOJ - 263.cpp
    > Author: huguang
    > Mail: hug@haizeix.com
    > Created Time :
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

bool isValid(int a[], int n) {
    stack<int> s;
    int x = 1;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s.top() < a[i]) {
            while (x <= a[i]) s.push(x), x += 1;
        }
        if (s.empty() || s.top() != a[i]) return false;
        s.pop();
    }
    return true;
}

int main() {
    int n, a[25], cnt = 20;
    cin >> n;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        if (isValid(a, n)) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
            }
            cout << endl;
            cnt -= 1;
        }
    } while (next_permutation(a, a + n) && cnt);
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
