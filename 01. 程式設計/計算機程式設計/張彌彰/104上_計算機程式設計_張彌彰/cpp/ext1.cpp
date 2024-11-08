/*
 * ext1.c: error handling in associative array
 *
 */

#include <iostream>
#include <cstring>
using std::cout;

class ZipCode {
public:
	int operator[](char *);
	void addZip(int,char *,int);  // add (city, zip) code
private:
	char city[5][10];
	int  zip[5];
};

class ZipNotFound {				  // a new class for error
public:
    char city[10];
	ZipNotFound(char *name) { strcpy(city, name); }
};

int ZipCode::operator[](char *s)
{
	int i;
	for (i=0; i<5; i++) {
		if (strcmp(city[i],s)==0) {
			return zip[i];
		}
	}
	throw ZipNotFound(s);
}

void ZipCode::addZip(int index,char *name,int code)
{
	strcpy(city[index],name);
	zip[index]=code;
}

int main(void)
{
	ZipCode tw;		// new ZipCode object
    int i;

	char c1[10]="台北"; tw.addZip(0,c1,100); // add zip codes
	char c2[10]="桃園"; tw.addZip(1,c2,200);
	char c3[10]="新竹"; tw.addZip(2,c3,300);
	char c4[10]="台中"; tw.addZip(3,c4,400);
	char c5[10]="台南"; tw.addZip(4,c5,500);

	char d1[10]="新竹";
	char d2[10]="花蓮";
	char d3[10]="桃園";
	try {
		i=tw[d1];
		cout << d1 << " zip code is " << i << '\n';
		i=tw[d2];
		cout << d2 << " zip code is " << i << '\n';
		i=tw[d3];
		cout << d3 << " zip code is " << i << '\n';
	}
	catch (ZipNotFound e) {
		cout << "Error: cannot find zip code for "
             << e.city << '\n';
	}

	strcpy(d1,"台南");
	strcpy(d2,"台中");
	try {
		i=tw[d1];
		cout << d1 << " zip code is " << i << '\n';
		i=tw[d2];
		cout << d2 << " zip code is " << i << '\n';
	}
	catch (ZipNotFound e) {
		cout << "Error: cannot find zip code for "
             << e.city << '\n';
	}
}
