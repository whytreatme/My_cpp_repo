#include<string>
#ifndef LIST_H_
#define LIST_H_

struct book
{
	std::string book_name;
	double price ;
	book* next ;
} ;

typedef book Item;

class List
{
private:
	int number;
	Item* items;
public:
	List(int num = 0);
	~List();
	void add(Item&);
	bool isempty() const;
	bool isfull() const;
	void visit(void (*pf)(Item&));
};

#endif // !LIST_H_

