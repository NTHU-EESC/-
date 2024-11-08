/*
 * exs1.c: emplyee and manager classes
 *
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
  cout << eNumber << ", ";
  cout << name << "\n";
}

class Manager {
public:
  Manager(string n, int e, int l) :
  	name(n), eNumber(e), level(l) {};
  void print() const;
private:
  string name;
  int eNumber;
  int level;
};

void Manager::print() const
{
  cout << eNumber << ", ";
  cout << name << ", ";
  cout << "level " << level << "\n";
}

int main(void)
{
  Employee e1("Bob Doe",2001);
  Employee e2("Jane Doe",2002);
  Manager m1("Jone Smith",1001,1);

  e1.print();
  e2.print();
  m1.print();
/*  m1=e1;  */
/*  e1=m1;  */
}
