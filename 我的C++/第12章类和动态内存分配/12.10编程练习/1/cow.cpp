#include<iostream>
#include"cow.h"

Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt) 
{
	int len = 0;
	name[19] = '\0';
	if (nm != nullptr)
	{
		len = strlen(nm);
		if (len > 19)
		{
			for (int i = 0; i < 20; i++)
				name[i] = nm[i];
		}
		else
			strcpy_s(name, len + 1, nm);
	}
	len = strlen(ho);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	int len;
	len = strlen(c.name);
	strcpy_s(name, len + 1, c.name);
	len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	using std::cout;

	cout << name << " has dead,unfortuately!\n";
	delete[]hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;

	int len;
	len = strlen(c.name);
	strcpy_s(name, len + 1, c.name);
	len = strlen(c.hobby);
	delete[] hobby;
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow()const
{
	using namespace std;
	cout << "Name: " << name << endl;
	if (hobby == nullptr)
		cout << "Hobby: " << endl;
	else
		cout << "Hobby: " << hobby << endl;
	cout << "Weight: " << weight << endl;
}