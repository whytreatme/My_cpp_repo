// 2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstring>

struct CandyBar
{
    char brand_name[100];
    double weight;
    int heat;
};

void set_candy(CandyBar&, const char* name = "Millennium Munch", double weight = 2.85, int heat = 350);
void show_candy(const CandyBar&);

int main()
{
    CandyBar as, ad;

    set_candy(as);
    show_candy(as);

    set_candy(ad, "一辈子忘不了柯春蕊", 9.98, 520);
    show_candy(ad);

    return 0;
}

void set_candy(CandyBar& obj , const char* name , double weight , int heat )
{
    strcpy_s(obj.brand_name, name);
    obj.weight = weight;
    obj.heat = heat;

}

void show_candy(const CandyBar& obj)
{
    using namespace std;

    cout << "Name: " << obj.brand_name << endl;
    cout << "Weight: " << obj.weight << endl;
    cout << "Heat: " << obj.heat << endl;

   
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
