/*
 * exs4.c: virtual function
 *
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Employee {
public:
	Employee(string n, int e) : name(n), eNumber(e) {};
	virtual void print() const;
private:
	string name;
	int eNumber;
};

void Employee::print() const
{
    cout << eNumber << ", " << name;
}

class Manager : public Employee {
public:
	Manager(string n, int e, int l) :
		Employee(n,e), level(l) {};
	void print() const;
private:
	int level;
};

void Manager::print() const
{
    Employee::print();
    cout << ", " << level;
}

int main(void)
{
	Employee e1("Bob Doe",2001);
	Employee e2("Jane Doe",2002);
	Manager m1("John Smith",1001,1);

	Employee *all[10];

	all[0]=&e1;
	all[1]=&e2;
	all[2]=&m1;

	for (int i=0; i<3; i++) {
		all[i]->print(); cout << '\n';
	}
}
