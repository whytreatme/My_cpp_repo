#include<string>

#ifndef PERSON_H_
#define PERSON_H_

class Person
{
private:
	static const int LIMITS = 25;
	std::string lname;
	char fname[LIMITS];

public:
	Person() { lname = ""; fname[0] = '\0'; };
	Person(const std::string& ln, const char* fn = "Heyyou");
	~Person();
	void Show() const;
	void FormalShow()const;

};

#endif // !PERSON_H_

