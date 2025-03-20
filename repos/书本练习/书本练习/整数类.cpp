#include<iostream>
using namespace std;
class MyInt {
	int integer;
public:
	MyInt(int a=0):integer(a) {
		;
	}
	MyInt(MyInt& ok) {
		integer = ok.integer;
	}
	~MyInt() {
		;
	}
	int operator+(MyInt m) {
		int c;
		c=this->integer + m.integer ;
		return c;
	}
	friend ostream& operator<<(ostream& _os, MyInt cok) {
		_os << cok.integer << endl;
		return _os;
	}
};
int main() {
	
	MyInt as(0);
	cout << as;

}

