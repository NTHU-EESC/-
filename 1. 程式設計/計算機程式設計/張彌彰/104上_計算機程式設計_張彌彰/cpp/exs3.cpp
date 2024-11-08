/*
 * exs3.c: manager and employee classes
 *      assigning base to derived class
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Employee {
public:
    Employee(string n, int e) :
      name(n), eNumber(e) {};
    void print() const;
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
    Manager(Employee e,int l) :
        Employee(e), level(l) {};
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

    e1.print(); cout << '\n';
    e2.print(); cout << '\n';
    m1.print(); cout << '\n';

    Employee e4=m1;
    e4.print(); cout << '\n';
    Manager m2(e1,1);
    m2.print(); cout << '\n';

    Manager *all[10];
    all[0]=static_cast<Manager*>(&e1);
    all[1]=static_cast<Manager*>(&e2);
    all[2]=static_cast<Manager*>(&e4);
    all[3]=&m2;
    for (int i=0; i<4; i++) {
        all[i]->print(); cout << '\n';
    }
}
