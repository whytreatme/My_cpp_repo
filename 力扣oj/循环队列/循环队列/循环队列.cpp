// 循环队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
class MyCircularQueue {
private:
    int* Queue;
    int count;
    int size;
    int front;
    int rear;
public:

    MyCircularQueue(int k) {
        if (k == 0) {
            front = rear = 0;
            count = 0;
            size = 0;
        }
        Queue = new int[k];
        if (Queue) {
            size = k;
            count = 0;
            front = 0;
            rear = 1;
        }
    }

    bool enQueue(int value) {
        if (count == size)return false;
        rear %= size;
        Queue[rear++] = value;
        count += 1;
        return true;
    }

    bool deQueue() {
        if (count == 0)return false;
        front %= size;
        front += 1;
        count -= 1;
        return true;
    }

    int Front() {
        if (count == 0)return -1;
        return Queue[front];
    }

    int Rear() {
        if (count == 0)return -1;
        return Queue[rear - 1];
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main()
{
    using namespace std;
    string str[12],cha[7]={ "MyCircularQueue","enQueue","Rear","Front","deQueue","isEmpty","isFull" };
    for (int i = 0; i < 12; i++)
        cin >> str[i];
    int i = 0,k=0;
    for (int i = 0, j = 0; i < 12; i++) {
        if(str[i]==cha[j])k=
     }


        

    
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
