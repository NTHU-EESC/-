//parentheses handling
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char top_symbol, char cur_symbol);

int main(void)
{
    string str, ans;
    cin >> str;
    stack<char>st;
    for(int i=0; i<str.length(); i++){
        //cout << i << endl;
        //cout << ans << endl;
        if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||     //number
           str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
            ans += str[i];
        }
        else if(str[i]==')'){
            while(st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(str[i]=='(') st.push(str[i]);
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            while((st.size()) && priority(st.top(),str[i])){
                ans += ' ';
                ans += st.top();
                st.pop();
            }
            ans += ' ';
            st.push(str[i]);
        }
    }
    while(st.size()){
        if((st.top()=='(')||(st.top()==')')) st.pop();
        else{
            ans += ' ';
            ans += st.top();
            st.pop();
        }
    }

    //處理空白(完整)
    string space = " ";
    ans += 'E';
    for(int i=0; ans[i]!='E';i++){
        if(ans[i]=='+'||ans[i]=='-'||ans[i]=='*'||ans[i]=='/'){
            if(ans[i-1]!=' '){
                ans.insert(i, space);
                //i--;
            }
            else if((ans[i+1]!=' ')&&(ans[i+1]!='E')){
                ans.insert(i+1, space);
                //i++;
            }
        }
        else continue;
    }
    ans.erase(ans.length()-1, 1);

    cout << "str = " << str << endl;
    cout << "ans = " << ans << endl;
    str = ans;
    cout << "str = " << str << endl;

    return 0;
}

int priority(char top_symbol, char cur_symbol) //priority值越高表示優先順位最低
{
    int pri_top, pri_cur;

    if((top_symbol=='+')||(top_symbol=='-')) pri_top = 3;
    else if((top_symbol=='*')||(top_symbol=='/')) pri_top = 2;
    else if(top_symbol=='(') pri_top = 8;

    if((cur_symbol=='+')||(cur_symbol=='-')) pri_cur = 3;
    else if((cur_symbol=='*')||(cur_symbol=='/')) pri_cur = 2;

    if(pri_top>pri_cur) return 0;
    else return 1;
}
