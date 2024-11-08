#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef struct{
    string str;
    char symbol;
}tmp;

int main()
{
    int last_one;
    char cur_symbol;
    tmp* st = new tmp;

    cout << "Please decide whether last one or not : " << endl;
    cin >> last_one;
    cout << "Please input current symbol : " << endl;
    cin >> cur_symbol;
    cout << "Please input temporary symbol : " << endl;
    cin >> st->symbol;
    cout << "Please input temporary string : " << endl;
    cin >> st->str;

    int n = st->str.length(); //st->str的長度
    int num_left = 0; int num_right = 0; //左括號右括號
    if(!last_one){
        if(cur_symbol=='1'||cur_symbol=='2'||cur_symbol=='3'||cur_symbol=='4'||cur_symbol=='5'||     //數字
           cur_symbol=='6'||cur_symbol=='7'||cur_symbol=='8'||cur_symbol=='9'){
            if( st->symbol == ')' ) cout << "false" << endl; //前一個symbol為')'
            else cout << "true" << endl;
        }
        else if(cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/'){    //運算符號
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/'||st->symbol=='(') cout << "false" << endl;
            else cout << "true" << endl;
        }
        else if(cur_symbol=='('){    //左括號
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/') cout << "true" << endl;
            else cout << "false" << endl;
        }
        else if(cur_symbol==')'){    //右括號
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/'||st->symbol=='(') cout << "false" << endl;
            else{
                for(int i=0; i<n; i++){
                    if(st->str[i]=='(') num_left++;
                    else if(st->str[i]==')') num_right++;
                }
                if(st->symbol=='(') num_left++;
                else if(st->symbol==')') num_right++;
                if(num_left>num_right) cout << "true" << endl;
                else cout << "false" << endl;
            }
        }
    }
    else{ //check的位置是maze的尾巴
        for(int i=0; i<n; i++){
            if(st->str[i]=='(') num_left++;
            else if(st->str[i]==')') num_right++;
        }
        if(st->symbol=='(') num_left++;
        else if(st->symbol==')') num_right++;
        if(cur_symbol=='(') num_left++;
        else if(cur_symbol==')') num_right++;
        if(num_left==num_right){
            if(cur_symbol=='('||cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/') cout << "false" << endl;
            else if(cur_symbol==')'){
                if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/'||st->symbol=='(') cout << "false" << endl;
                else cout << "true" << endl;
            }
            else if(cur_symbol=='1'||cur_symbol=='2'||cur_symbol=='3'||cur_symbol=='4'||cur_symbol=='5'||     //數字
                    cur_symbol=='6'||cur_symbol=='7'||cur_symbol=='8'||cur_symbol=='9'){
                if( st->symbol == ')' ) cout << "false" << endl; //前一個symbol為')'
                else cout << "true" << endl;
            }
        }
        else cout << "false" << endl;
    }
    return 0;
}
