// NTHU EE Data Structures, 2018 spring 

#define PRINT(x) cout << #x " = " << x << endl;

 // =======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  #include <fstream>
 /*||*/  #include <unistd.h>
 /*||*/  char INFILE[]   =  "11876_sampleIn.txt";
 /*||*/  char OUTFILE[]  =  "out.txt";
 /*||*/  char GOLDENFILE[] = "11876_sampleOut.txt";
 /*||*/  #endif
 // =======================================================================

#include <iostream>
#include <string>
using namespace std;
struct Node{
	string gift;
	int price;
	Node *next;
};
void Reverse();
void InsertBack(string gift, int price);
void InsertAfter(string gift, int price, int price2);
void Delete(int price);
bool search(int price);
void ShowList();
Node *first = 0;
int main()
{

 // =======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  ifstream ftest(INFILE);
 /*||*/  if(ftest.fail()){ cout << "Cannot open input file: " << INFILE << endl; return 0; }
 /*||*/  ftest.close();
 /*||*/  cout << endl << "  Note: cout and printf are redirected to the file: " << OUTFILE << endl << endl;
 /*||*/  freopen(INFILE, "r", stdin);
 /*||*/  int _save_out_ = dup(1);
 /*||*/  freopen(OUTFILE, "w", stdout);
 /*||*/  #endif
 // =======================================================================

    // Your code goes here
    string mode;
	string gift;
	int price;
	int price2;
	bool flag = 0;
	
	while(!flag)
	{
		cin >> mode;
		if(mode == "End")
		{
			flag = 1;
		}
		else if(mode == "InsertBack")
		{
			cin >> gift >> price;
			InsertBack(gift, price);
		}
		else if(mode == "InsertAfter")
		{
			cin >> gift >> price >> price2;
			InsertAfter(gift, price, price2);
		}
		else if(mode == "Delete")
		{
			cin >> price;
			Delete(price);
		}
		else if(mode == "Reverse")
		{
			Reverse();
		}
	}
	ShowList();
	return 0;

 // ======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  dup2(_save_out_, 1);
 /*||*/  ifstream f1(OUTFILE);
 /*||*/  ifstream f2(GOLDENFILE);
 /*||*/  if(f1.fail() || f2.fail()){
 /*||*/       cout << "  File cannot be open. Comparison is skipped." << endl << endl;
 /*||*/  }else{
 /*||*/    string s1, s2;
 /*||*/    bool mismatch = false;
 /*||*/    for(int i=0; ; i++){
 /*||*/        getline(f1, s1);
 /*||*/        getline(f2, s2);
 /*||*/        if(f1.eof() && f2.eof()) break;
 /*||*/        if(s2.length() && s2[s2.size()-1] == '\r') s2.erase( s2.length()-1, 1);
 /*||*/        if(s1!=s2){
 /*||*/            mismatch = true;
 /*||*/            cout << "L" << i << ":" << endl;
 /*||*/            cout << "  expect: " << s2 << endl;
 /*||*/            cout << "  yours : " << s1 << endl;
 /*||*/        }
 /*||*/    }
 /*||*/    if (!mismatch) cout << endl << "  ^__^ Output file " << OUTFILE << " matches the goden file " << GOLDENFILE << "." << endl << endl;
 /*||*/    else           cout << endl << "  Files mismatch!!!" << endl << endl;
 /*||*/  }
 /*||*/  #endif
 // ======================================================================

    return 0;
}
void InsertBack(string gift, int price)
{
	Node *newNode = new Node;
	Node *current = first;
	
	newNode->gift = gift;
	newNode->price = price;
	newNode->next = 0;
	if (first == 0)
	{
		first = newNode;
		return;
	}
	if(search(price)) return;
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = newNode;
}

void InsertAfter(string gift, int price, int price2)
{
	if (first == 0) return;
	if(search(price)) return;
	Node *newNode = new Node;
	Node *current = first;
	Node *previous;
	newNode->gift = gift;
	newNode->price = price;
	while (current->next != 0)
	{
		if(current->price == price2)
		{
			newNode->next = current->next; 
			current->next = newNode;
			return;		
		}
		previous = current;
		current = current->next;
	}
}

void Reverse()
{	
	if (first == 0 || first->next == 0) return;

    Node *previous = 0;
    Node *current = first;
    Node *preceding = first->next;

    while (preceding != 0) {
        current->next = previous;  
        previous = current;            
        current = preceding;           
        preceding = preceding->next;   
    }                                 

    current->next = previous;          
    first = current; 
}

void Delete(int price)
{
	if(first == 0) return;
	Node *current = first;
	Node *previous;
	while(current->next != 0)
	{
		if (current == first)
		{
			first = current->next;
			delete current;
			current = 0;
			return;
		}else{
			previous->next = current->next;
			delete current;
			current = 0;
			return; 
		}
		if(price)
		previous = current;
		current = current->next;
	}
}

bool search(int price)
{
	Node *current = first;
	Node *previous;
	if (first == 0) return 0;
	while(current->next != 0)
	{
		if(current->price == price) return 1;
		previous = current;
		current = current->next;
	}
	return 0;
}

void ShowList()
{
	if(first == 0) 
	{
		cout << "Empty\n";
		return;
	}
	Node *current = first;
	cout << "List\n";
	while(current != 0)
	{
		if(current != first) cout <<"->";
		cout << "(" << current->gift << "," << current->price << ")";
		current = current->next;
	}
	cout << endl; 
} 
