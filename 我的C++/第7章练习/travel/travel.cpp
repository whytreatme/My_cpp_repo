// travel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct travel_time
{
    int hours;
    int mins;
};

const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
    using namespace std;

    travel_time day1 = { 5,45 };
    travel_time day2 = { 4,55 };

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = { 4,32 };
    cout << "Three-day total: ";
    show_time(sum(trip, day3));
    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;
    total.hours = t1.hours + t2.hours;
    total.mins = (t1.mins + t2.mins)%Mins_per_hr;
    total.hours += (t1.mins+t2.mins) / Mins_per_hr;

    return total;
}

void show_time(travel_time t)
{
    using namespace std;

    cout << t.hours << " hours, "
        << t.mins << " minutes\n";
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
