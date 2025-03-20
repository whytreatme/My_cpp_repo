// 3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct box
{
    char maker[40];
    float height;
    float length;
    float width;
    float volume;
};

box show_box(box as);
void set_volume(box* pb);

int main()
{
    box mine{"Arthur Lee",25.98,50.92,21.17};

   
    set_volume(&mine);
    mine = show_box(mine);

    return 0;
}

box show_box(box ps)
{
    using namespace std;

    cout << "The box was made by " << ps.maker << endl
        << "Its height is " << ps.height << endl
        << "Its length is " << ps.length << endl
        << "Its width is " << ps.width << endl
        << "Its volume is " << ps.volume << endl;

        return ps;
}

void set_volume(box* pb)
{
    float mv = 0;
    mv = pb->height * pb->length * pb->width;

    pb->volume = mv;
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
