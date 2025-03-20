// strc_ref.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>

struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);

int main()
{
    free_throws one = { "Ifelsa Branch",13,14 };
    free_throws two = { "Andor Knott",10,16 };
    free_throws three = { "Minnie Max",7,9 };
    free_throws four = { "Whily Looper",5,9 };
    free_throws five = { "Long Long",6,14 };
    free_throws team = { "Throwgoods",0,0 };

    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);
    //use return value as argument
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);
    //use return value as assignment
    dup = accumulate(team, five);
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignmnet:\n";
    display(dup);
    set_pc(four);
    //ill-advised assigment
    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);

    return 0;

}

void display(const free_throws& ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << "Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws& ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);

    return target;
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
