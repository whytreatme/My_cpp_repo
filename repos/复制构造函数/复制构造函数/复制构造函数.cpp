// 复制构造函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;
class Location
{
public:
	Location(int xx,int yy);
	Location(const Location& _Right);
	~Location(){
		cout << "destroyed the objection" << endl;
	}
	int GetX()const { return X; }
	int GetY()const { return Y; }
	friend ostream& operator<<(ostream& _os, Location _nice) {
		_os << "Location is:" << "," << _nice.GetX() << "," << _nice.GetY() << endl;
		return _os;
	}
private:
	int X, Y;
};

Location::Location(int xx,int yy)
{
	X = xx; Y = yy; \
		cout << "constructor objection:" << endl;
}

Location::Location(const Location& _Right)
{
	X = _Right.X;
	Y = _Right.Y;
	cout << "Copy_constructor called"<<endl;
}
/*void f(Location ok) {
	cout << "function:" << "," << ok.GetX() << "," << ok.GetY()<<endl;
}*/
Location g() {
	Location A(1, 2);
	return A;
   }
int main()
{
	cout << g() << endl;
}

