// 含退格的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool Compare(vector<char>a, vector<char>b) {
        int flag = 1;
        if (a.size() != b.size())return false;
        for (int i = 0; i<a.size(); i++)
        {
            if (a[i] != b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)return true;
        if (flag == 0) return false;
    }

    bool backspaceCompare(string s, string t) {
        vector<char>first, second;
        int i = 0, j = 0;
        while (s[i] != '\0' || t[j] != '\0') {
            
            if (s[i] != '\0'){
            if ((s[i] != '#'))first.push_back(s[i]);
            else if(!first.empty()) first.pop_back();
            i++;
            }
            if (t[j] != '\0') {
                if ((t[j] != '#'))second.push_back(t[j]);
                else if(!second.empty()) second.pop_back();
                j++;
            }
        }
        return Compare(first, second);
    }
};

int main()
{
    bool try_abit;
    string a, b;
    cin >> a >> b;
    Solution c;
    try_abit = c.backspaceCompare(a, b);
    if (try_abit)cout << "True";
    else cout << "False";
    return 0;
}

