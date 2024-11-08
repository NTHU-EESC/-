/*
 * exs2.c: manager class derived
 *           from employee class
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
  string getName() { return name; } ;
  int getEnum() { return eNumber; } ;
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

  cout << e1.getName() << '\n';
  cout << e2.getName() << '\n';
  cout << m1.getName() << "\n";

  Employee e4=m1;
  e4.print(); cout << '\n';
/*  Manager  m2=e1;           */
/*  m2.print(); cout << '\n'; */

  Employee *all[10];
  all[0]=&e1;
  all[1]=&e2;
  all[2]=&m1;
  for (int i=0; i<3; i++) {
  	all[i]->print(); cout << '\n';
  }
}
