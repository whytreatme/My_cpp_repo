// 书本的练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;
class Goods {    //定义一个类
private:
	int weight;
	static int total_weight;  //静态成员变量（私有）
public:
	Goods* next;//共有指针
	Goods(int w=0):weight(w) {     //构造函数
		cout << "initialized the objection"<<endl;
	this->next = NULL;
		weight = w;
		total_weight += w;
	}
	Goods(Goods& _ok,int w=0):weight(w) {};//复制构造函数，传入一个goods类型的对象引用
	~Goods() {
		cout<<"destructed the objection"<<endl;
		total_weight -= weight;
	}
	static int Total_weight() {
		return total_weight;
	};
	int Weight() {
		return weight;
	}
};

int Goods::total_weight = 0;//在类外对静态成员变量赋值
void purchase(Goods * & f,Goods * & r,int sd) { //传进goods类型指针的引用,f为头指针，r为当前指针
	Goods * p;
	p = new Goods(sd);//申请一块goods类型内存，使用sd(w)初始化该内存
	if (f == NULL)f = r = p;//如果是刚刚创建链表，则指向同一内存
	else {
		r->next = p;//一项一项往后连接
		r = r->next;
	}
}
void sale(Goods * &head) {//使用引用不需要调用复制构造函数，内存安全
	if (head == NULL)cout << "No Goods!" << endl;
	else {
		Goods* q = NULL;//去掉开头
		q = head;
		head = head->next;
		delete q;
		q = NULL;
		cout << "saled"<<"Now Goods is" << Goods::Total_weight() << endl;
	}
}
void Destroyed(Goods* & first) {
	Goods *s=NULL;
	while (first!=NULL) {
	s = first;
	first = first->next;
	delete s;
	}
}
int main()
{
	Goods* front = NULL, * rear = NULL;//一个头，一个当前
	int w;//初始化内存
	int choice;
	do {
		cout << "The key in 1 is purchase"<<'\t'<<"in 2 is sale"<<'\t'<<"in 0 is over : " << '\t' <<"in 3 is show total weight "<<endl<<"Please input your choice : " << endl;
		cin >> choice;
		switch (choice) {
		case 1:
		{   cout << "input w:" << endl;
		cin >> w;
		purchase(front, rear, w);
		break;
		}
		case 2:if(front!=NULL)sale(front); break;//传入头指针
		case 3:cout<<"The total weight is:"<<Goods::Total_weight()<<endl; break;
		case 0: {
			if (front != NULL) {
				rear->next = NULL;
				Destroyed(front);
			}
			std::cout << "your mother is the bitch who I always fuck!" << endl; break;
		}
		default:cout << "error!" << endl; break;
		}
	} while (choice);
}
  


/* 
   char *ch;
  ch= (char*)malloc(sizeof(char))
	

	*/




