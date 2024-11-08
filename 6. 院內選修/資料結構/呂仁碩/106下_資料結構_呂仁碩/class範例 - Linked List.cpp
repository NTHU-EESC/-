#include<iostream>
#include<string>
using namespace std;
class ChainNode;
//private是只有在寫class的function才拿得到，其他的話要用get的方式拿
class Chain
{
public:
    Chain();
    ~Chain();
    void InsertBack(string gift, int price);
    void InsertAfter(string gift, int price, int priceToInsertAfter);
    void Delete(int priceToDelet);
    void Reverse();
    ChainNode* getFirst();
private:
    ChainNode* first;
};

class ChainNode
{
friend class Chain;
public:
    ChainNode(string gift, int price = 0, ChainNode* next = 0);
    ~ChainNode();
    string getName();
    int getMoney();
    ChainNode* getLink();
private:
    string name;
    int money;
    ChainNode* link;
};

//Chain function
Chain::Chain()
{
    first = NULL;
}

Chain::~Chain(){}

ChainNode* Chain::getFirst()
{
    return first;
}

void Chain::InsertBack(string gift, int price)
{
    ChainNode* temp;
    temp = first;
    if(first){ //nonempty chain
        while(temp->link) temp = temp->link;
        temp->link = new ChainNode(gift,price,0);
    }
    else{
        first = new ChainNode(gift,price,0);
    }
}

void Chain::InsertAfter(string gift, int price, int priceToInsertAfter)
{
    ChainNode* temp;
    temp = first;
    while(temp!=0){
        if(temp->money == priceToInsertAfter){
            temp->link = new ChainNode(gift,price,temp->link);
            break;
        }
        else{
            temp = temp->link;
            continue;
        }
    }
}

void Chain::Delete(int priceToDelet)
{
    ChainNode* temp;
    ChainNode* prev;
    temp = first;
    prev = 0;
    while(temp!=0){
        if(temp->money == priceToDelet){
            if(temp==first) first = first->link;
            else prev->link = temp->link;
            delete temp;
            break;
        }
        else{
            prev = temp;
            temp = temp->link;
            continue;
        }
    }
}

void Chain::Reverse()
{
    ChainNode* curr = first;
    ChainNode* prev = 0;
    ChainNode* r = 0;
    while(curr){
        r = prev;
        prev = curr;
        curr = curr->link;
        prev->link = r;
    }
    first = prev;
}

//ChainNode function
ChainNode::ChainNode(string gift, int price, ChainNode* next)
{
    name = gift;
    money = price;
    link = next;
}

ChainNode::~ChainNode(){}

string ChainNode::getName()
{
    return name;
}

int ChainNode::getMoney()
{
    return money;
}

ChainNode* ChainNode::getLink()
{
    return link;
}

int main()
{
    string func;
    string gift;
    int price;
    int priceToInsertAfter;
    int priceToDelet;
    Chain c;

    cin >> func;
    while((func=="End")==0){
        if(func=="InsertBack"){
            cin >> gift >> price;
            c.InsertBack(gift,price);
        }
        else if(func=="InsertAfter"){
            cin >> gift >> price >> priceToInsertAfter;
            c.InsertAfter(gift,price,priceToInsertAfter);
        }
        else if(func=="Delete"){
            cin >> priceToDelet;
            c.Delete(priceToDelet);
        }
        else if(func=="Reverse"){
            c.Reverse();
        }
        cin >> func;
    }

    ChainNode* temp = c.getFirst();

    if(c.getFirst()==0) cout << "Empty" << endl;
    else cout << "List" << endl;
    while(temp->getLink() != 0){
        cout << "(" << temp->getName() << "," << temp->getMoney() << ")" << "->";
        temp = temp->getLink();
    }
    cout << "(" << temp->getName() << "," << temp->getMoney() << ")" << endl;

    return 0;
}
