#include<iostream>
#include<iomanip>
using namespace std;

typedef struct{
    double mass;
}mole;

class Information{
public:
    Information();
    ~Information();
    void SetInfo(); //Åª­È
    void DeleteInfo();
    void find_ans();
    void QuickSort(int left, int right);
    void output();
private:
    int num;
    int num_swap;
    mole* mole_array;
};

int main()
{
    Information info;
    info.SetInfo();
    info.find_ans();
    info.output();
    info.DeleteInfo();
    return 0;
}

Information::Information()
{
    mole_array = NULL;
}

Information::~Information(){}

void Information::SetInfo()
{
    cin >> num;
    mole_array = new mole[num];
    for(int i=0; i<num; i++) cin >> mole_array[i].mass;
    num_swap = 0;
}

void Information::DeleteInfo()
{
    delete [] mole_array;
}

void Information::find_ans()
{
    QuickSort(0, num-1);
}

void Information::QuickSort(int left, int right)
{
    if(left<right){
        double & pivot = mole_array[left].mass;
        int i = left;
        int j = right + 1;
        do{
            do{ j--;                                   //find a key <= pivot
            } while(mole_array[j].mass > pivot);
            do{ i++;                                   //find a key > pivot
            } while(i<j && mole_array[i].mass <= pivot);
            if(i<j){
                if(mole_array[i].mass!=mole_array[j].mass){
                    swap(mole_array[i].mass, mole_array[j].mass);
                    num_swap++;
                }
            }
        } while(i<j); //i¦bjªº¥ªÃä

        if(pivot!=mole_array[j].mass){ //place the pivot between 2 list
            swap(pivot, mole_array[j].mass);
            num_swap++;
        }

        // "j" is the address of pivot
        QuickSort(left, j-1);  //recursion //left sublist
        QuickSort(j+1, right); //recursion //right sublist
    }
}

void Information::output()
{
    for(int i=0; i<num; i++) cout << mole_array[i].mass << " ";
    cout << endl;
    cout << "number of sort = " << num_swap << endl;
}
