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

    int n = st->str.length(); //st->str������
    int num_left = 0; int num_right = 0; //���A���k�A��
    if(!last_one){
        if(cur_symbol=='1'||cur_symbol=='2'||cur_symbol=='3'||cur_symbol=='4'||cur_symbol=='5'||     //�Ʀr
           cur_symbol=='6'||cur_symbol=='7'||cur_symbol=='8'||cur_symbol=='9'){
            if( st->symbol == ')' ) cout << "false" << endl; //�e�@��symbol��')'
            else cout << "true" << endl;
        }
        else if(cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/'){    //�B��Ÿ�
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/'||st->symbol=='(') cout << "false" << endl;
            else cout << "true" << endl;
        }
        else if(cur_symbol=='('){    //���A��
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/') cout << "true" << endl;
            else cout << "false" << endl;
        }
        else if(cur_symbol==')'){    //�k�A��
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
    else{ //check����m�Omaze������
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
            else if(cur_symbol=='1'||cur_symbol=='2'||cur_symbol=='3'||cur_symbol=='4'||cur_symbol=='5'||     //�Ʀr
                    cur_symbol=='6'||cur_symbol=='7'||cur_symbol=='8'||cur_symbol=='9'){
                if( st->symbol == ')' ) cout << "false" << endl; //�e�@��symbol��')'
                else cout << "true" << endl;
            }
        }
        else cout << "false" << endl;
    }
    return 0;
}
