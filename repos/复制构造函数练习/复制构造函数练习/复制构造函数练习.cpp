// 复制构造函数练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstring>
using namespace std;
class Name {
public:
	Name(const char* pn);
	Name(const Name & _name);
	~Name();
	void setName(const char*);
	void showName();
	friend ostream& operator <<(ostream& _ok, Name& _nice) {
		_ok<< _nice.pName << endl;
		return _ok;
	}
protected:
	char* pName;
	int size;
};
Name::Name( const char* pn) {
	cout << "Constructing" <<pn<< endl;
	pName = new char[strlen(pn) + 1];
	if(this->pName!=NULL)strcpy_s(pName, strlen(pn) + 1, pn);
	this->size =(int) strlen(pn);
}
Name::Name(const Name& _name) {
	cout << "Copying" << _name.pName<<"into its own block"<<endl;
	this->pName = new char[_name.size + 1];
	if (pName != NULL)strcpy_s(pName, _name.size + 1, _name.pName);
	size = _name.size;
}
Name::~Name() {
	cout << "destructing" << pName<<endl;
	delete[] pName;
	pName = NULL;
	size = 0;
}
void Name::setName(const char* _str) {
	delete this->pName;
	pName = new char[strlen( _str) + 1];
	if (pName != NULL)strcpy_s(pName, strlen(_str) + 1, _str);
}
void Name::showName() {
	cout << "the name is" << this->pName << endl;
}
int main()
{
	Name Obj1("NoName");
	Name Obj2 = Obj1;
	Obj1.showName();
	Obj2.showName();
	Obj1.setName("SuDongPo");
	Obj1.showName();
	Obj2.setName("苍天之子：李俊宏");
	Obj2.showName();
	Name Obj("Girl");
	cout << Obj << endl;

}


