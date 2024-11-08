#include<iostream>
#include<string>

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
  
int main(void)
{
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
	newNode->gift = gift;
	newNode->price = price;
	while (current)
	{
		if(current->price == price2)
		{
			newNode->next = current->next; 
			current->next = newNode;
			return;		
		}
		current = current->next;
	}
}

void Reverse()
{	
	if (first == 0 || first->next == 0) return;

    Node *previous = 0;
    Node *current = first;
    Node *r = 0;

    while (current) {
        r = previous;
		previous = current;
		current = current->next;
		previous->next = r;    
    }          
    first = previous; 
}

void Delete(int price)
{
	if(first == 0) return;
	Node *current = first;
	Node *previous;
	while(current)
	{
		if (current->price == price)
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
		}
		previous = current;
		current = current->next;
	}
}

bool search(int price)
{
	Node *current = first;
	Node *previous;
	if (first == 0) return 0;
	while(current)
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
