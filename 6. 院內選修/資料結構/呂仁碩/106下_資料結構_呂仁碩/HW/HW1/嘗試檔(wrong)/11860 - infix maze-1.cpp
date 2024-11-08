#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct{
    string str;
    char symbol;
    int sym_x, sym_y;
    bool** visit;
}tmp;

typedef struct{
    int di, dj;
}offset;

int find_way(char** maze, char*way);
int check(tmp st, char symbol, int last_one); //判斷是否合法
int infix(char*way);
int width, height;

int main(void)
{
    int n;
    cin >> n;

    char** maze;
    char* way;
    int out; //out=1 represented have a way out

    for(int i=0; i<n; i++){
        //讀值
        cin >> width;
        cin >> height;
        maze = new char*[height];
        way = new char[height*width];
        for(int j=0; j<height; j++){
            maze[j] = new char[width];
            for(int k=0; k<width; k++) cin >> maze[j][k];
        }

        //輸出
        /*if(i==0) cout << n << endl;
        cout << width << endl << height << endl;
        for(int j=0; j<height; j++){
            for(int k=0; k<width; k++){
                cout << maze[j][k] << " " ;
            }
            cout << endl;
        }*/
        out = find_way(maze, way);  //判斷是否有出口
        if(out){
            cout << "Yes" << endl;
            for(int j=0; way[j]!='#'; j++) cout << way[j];
            cout << endl;
            //infix(way);
            //for(int j=0; way[j]!='#'; j++) cout << way[j];
        }
        else cout << "No" << endl;

        for(int j=0; j<height; j++) delete [] maze[j];
        delete [] maze;
        delete [] way;
    }

    return 0;
}

int find_way(char** maze, char*way)
{
    //判斷maze[0][0](起始位置)是否為"數字"
    if(maze[0][0]=='+'||maze[0][0]=='-'||maze[0][0]=='*'||maze[0][0]=='/'||maze[0][0]=='('||maze[0][0]==')') return 0;

    int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}}; //下右左上(dj,di)
    int dx, dy;
    queue<tmp> qu;

    tmp* temp = new tmp[height*width];
    temp[0].str = ""; //temp[0].str[0] = '';
    temp[0].symbol = maze[0][0];
    temp[0].sym_y = 0; temp[0].sym_x = 0;
    for(int k=0; k<height*width; k++){      //記錄圖上的點是否遍歷過，有遍歷過為true。
        temp[k].visit = new bool*[height];
        for(int i=0; i<height; i++){    //全部的點都初始化為尚未遍歷
            temp[k].visit[i] = new bool[width];
            for(int j=0; j<width; j++) temp[k].visit[i][j] = false;
        }
        temp[k].visit[0][0] = true;
    }
    qu.push(temp[0]);

    int num = 1;
    cout << "path: " ;
    while(!qu.empty()){
        tmp current = qu.front(); qu.pop();
        for(int i=0; i<4; i++){
            dy = current.sym_y+dir[i][0]; dx = current.sym_x+dir[i][1];
            if(dy==height-1 && dx==width-1){
                if(check(current, maze[dy][dx], 1)){
                    for(int j=0; j<current.str.length(); j++) way[j] = current.str[j];
                    way[current.str.length()] = current.symbol;
                    way[current.str.length()+1] = maze[dy][dx];
                    way[current.str.length()+2] = '#';
                    delete [] temp;
                    return 1;
                }
                else continue;
            }
            else if(dy<height && dy>=0 && dx<width && dx>=0){ //判斷邊界條件
                if(check(current,maze[dy][dx],0) && !current.visit[dy][dx]){
                    cout << maze[dy][dx] << " ";
                    for(int j=0; j<height; j++)
                        for(int k=0; k<width; k++) temp[num].visit[j][k] = current.visit[j][k];
                    temp[num].visit[dy][dx] = true;
                    temp[num].str = current.str + current.symbol;
                    temp[num].symbol = maze[dy][dx];
                    temp[num].sym_y = dy; temp[num].sym_x = dx;
                    qu.push(temp[num]);
                }
            }
            num ++;
        }
        for(int j=0; j<height; j++) delete [] current.visit[j];
        delete [] current.visit;
    }
    delete [] temp;
    return 0;

}

int check(tmp st, char cur_symbol, int last_one)
{
    int n = st.str.length(); //st.str的長度
    int num_left = 0; int num_right = 0; //左括號右括號
    if(!last_one){
        if(cur_symbol=='1'||cur_symbol=='2'||cur_symbol=='3'||cur_symbol=='4'||cur_symbol=='5'||     //數字
           cur_symbol=='6'||cur_symbol=='7'||cur_symbol=='8'||cur_symbol=='9'){
            if( st.symbol == ')' ) return 0; //前一個symbol為')'
            else return 1;
        }
        else if(cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/'){    //運算符號
            if(st.symbol=='+'||st.symbol=='-'||st.symbol=='*'||st.symbol=='/'||st.symbol=='(') return 0;
            else return 1;
        }
        else if(cur_symbol=='('){    //左括號
            if(st.symbol=='+'||st.symbol=='-'||st.symbol=='*'||st.symbol=='/') return 1;
            else return 0;
        }
        else if(cur_symbol==')'){    //右括號
            if(st.symbol=='+'||st.symbol=='-'||st.symbol=='*'||st.symbol=='/'||st.symbol=='(') return 0;
            else{
                for(int i=0; i<n; i++){
                    if(st.str[i]=='(') num_left++;
                    else if(st.str[i]==')') num_right++;
                }
                if(st.symbol=='(') num_left++;
                else if(st.symbol==')') num_right++;
                if(num_left<num_right) return 1;
                else return 0;
            }
        }
    }
    else{
        if(st.symbol=='(') return 0;
        if(cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/'||cur_symbol=='(') return 0;

        for(int i=0; i<n; i++){
            if(st.str[i]=='(') num_left++;
            else if(st.str[i]==')') num_right++;
        }
        if(st.symbol=='(') num_left++;
        else if(st.symbol==')') num_right++;

        if(num_left==num_right){
            if(cur_symbol==')'||cur_symbol=='('||st.symbol==')') return 0;
            else return 1;
        }
        else if(num_left==(num_right-1)){
            if(st.symbol!='+'&&st.symbol!='-'&&st.symbol!='*'&&st.symbol!='/'&&st.symbol!='('&&cur_symbol==')') return 1;
            else return 0;
        }
        else return 0;
    }
}

int infix(char*way);

