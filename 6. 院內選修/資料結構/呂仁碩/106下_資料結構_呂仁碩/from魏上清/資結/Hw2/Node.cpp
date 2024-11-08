#include<iostream> 

using namespace std;
class Node{
public:
	int i; 
	Node*next;
};

int main(void)
{
	Node *px, *py;
	Node q, r;
	px = new Node;
	px->i = 5; q.i = 11; r.i = 13;
	py = &q;
	px->next = py;
	px->next->next = px->next;
	r.next = px;
	cout << "q.i=" << q.i << endl;
	cout << "r.i=" << r.i << endl;
	cout << "px->i=" << px->i << endl;
	cout << "py->i=" << py->i << endl;
	cout << "px->next=" << px->next << endl;
	cout << "py->next=" << py->next << endl;
	cout << "q.next= " << q.next << endl;
	
	
	px = &r;
	px->next = py->next->next;
	px->i = px->next->i + py->next->i;
	cout << "q.i=" << q.i << endl;
	cout << "r.i=" << r.i << endl;
	cout << "px->i=" << px->i << endl;
	cout << "py->i=" << py->i << endl;
	cout << "px->next=" << px->next << endl;
	cout << "py->next=" << py->next << endl;
	cout << "q.next= " << q.next << endl;
		
	return 0; 
}
