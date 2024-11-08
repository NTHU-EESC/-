#include <iostream>
#include <vector>
using namespace std;

struct point{
   int x;
   int y;
   point(int x, int y):x(x), y(y) {}; // constructor of a point object
};

int main()
{
    cout << "Hello vector!" << endl;

    vector<point> mystack;

    mystack.push_back(point(1, 2)); // equivalent to stack.push()
    mystack.push_back(point(3, 4));
    mystack.pop_back(); // equivalent to stack.pop()
    mystack.push_back(point(5, 6));
    while(!mystack.empty()){
        cout << "stack (vector) size is " << mystack.size() << endl;
        cout << mystack.back().x << ", " << mystack.back().y << endl; // equivalent to stack.top()
        mystack.pop_back();
    }

    return 0;
}
