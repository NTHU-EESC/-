#include <iostream>
#include <string>
#include <stack>
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
void DFS(char** maze, tmp* now);
int check(tmp* st, char symbol, int last_one); //判斷是否合法
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
    tmp* temp = new tmp ;
    (temp->symbol) = maze[0][0];
    (temp->sym_y) = 0; (temp->sym_x) = 0;
    temp->visit = new bool*[height];      //記錄圖上的點是否遍歷過，有遍歷過為true。
    for(int i=0; i<height; i++){    //全部的點都初始化為尚未遍歷
        temp->visit[i] = new bool[width];
        for(int j=0; j<width; j++) temp->visit[i][j] = false;
    }
    temp->visit[0][0] = true;
    cout << temp->visit[5][0] << endl;
    cout << "path: " ;
    DFS(maze, temp);
    if(temp->visit[0][0]){
        for(int i=0; i<height; i++) delete []temp->visit[i];
        delete [] temp->visit;
        for(int i=0, j=0; i<temp->str.length(); i++){
            if(temp->str[i] != '\0'){
                way[j] = temp->str[i];
                j++;
            }
            else continue;
        }
        way += '#';
        return 1;
    }
    else{
        for(int i=0; i<height; i++) delete []temp->visit[i];
        delete [] temp->visit;
        return 0;
    }
}

int check(tmp* st, char cur_symbol, int last_one)
{
    int n = st->str.length(); //st.str的長度
    int num_left = 0; int num_right = 0; //左括號右括號
    if(!last_one){
        if(cur_symbol=='1'||cur_symbol=='2'||cur_symbol=='3'||cur_symbol=='4'||cur_symbol=='5'||     //數字
           cur_symbol=='6'||cur_symbol=='7'||cur_symbol=='8'||cur_symbol=='9'){
            if( st->symbol == ')' ) return 0; //前一個symbol為')'
            else return 1;
        }
        else if(cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/'){    //運算符號
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/'||st->symbol=='(') return 0;
            else return 1;
        }
        else if(cur_symbol=='('){    //左括號
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/') return 1;
            else return 0;
        }
        else if(cur_symbol==')'){    //右括號
            if(st->symbol=='+'||st->symbol=='-'||st->symbol=='*'||st->symbol=='/'||st->symbol=='(') return 0;
            else{
                for(int i=0; i<n; i++){
                    if(st->str[i]=='(') num_left++;
                    else if(st->str[i]==')') num_right++;
                }
                if(st->symbol=='(') num_left++;
                else if(st->symbol==')') num_right++;
                if(num_left<num_right) return 1;
                else return 0;
            }
        }
    }
    else{
        if(st->symbol=='(') return 0;
        if(cur_symbol=='+'||cur_symbol=='-'||cur_symbol=='*'||cur_symbol=='/'||cur_symbol=='(') return 0;

        for(int i=0; i<n; i++){
            if(st->str[i]=='(') num_left++;
            else if(st->str[i]==')') num_right++;
        }
        if(st->symbol=='(') num_left++;
        else if(st->symbol==')') num_right++;

        if(num_left==num_right){
            if(cur_symbol==')'||cur_symbol=='('||st->symbol==')') return 0;
            else return 1;
        }
        else if(num_left==(num_right-1)){
            if(st->symbol!='+'&&st->symbol!='-'&&st->symbol!='*'&&st->symbol!='/'&&st->symbol!='('&&cur_symbol==')') return 1;
            else return 0;
        }
        else return 0;
    }
}

void DFS(char** maze, tmp* temp)
{
    int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}}; //下右左上(dj,di)
    int dx, dy;
    for(int i=0; i<4; i++){
        dy = temp->sym_y + dir[i][0]; dx = (temp->sym_x) + dir[i][1];
        if(dy==height-1 && dx==width-1){
            if(check(temp, maze[dy][dx], 1)){
                temp->str += temp->symbol;
                temp->str += maze[dy][dx];
                return;
            }
            else continue;
        }
        else if(dy<height && dy>=0 && dx<width && dx>=0){ //判斷邊界條件
            if(check(temp,maze[dy][dx],0) && !temp->visit[dy][dx]){
                cout << maze[dy][dx] << " ";
                temp->visit[dy][dx] = true;
                for(int j=temp->str.length()-1; j>=0; j--){
                    if(temp->str[j]=='\0'){
                        temp->str[j] = temp->symbol;
                        break;
                    }
                    else{
                        if(j==0) temp->str += temp->symbol;
                    }
                }
                temp->symbol = maze[dy][dx];
                temp->sym_y += dir[i][0]; temp->sym_x += dir[i][1];
                DFS(maze, temp);
                temp->sym_y -= dir[i][0]; temp->sym_x -= dir[i][1];
                temp->symbol = temp->str[temp->str.length()-1];
                temp->str[temp->str.length()-1] = '\0';
                temp->visit[dy][dx] = false;
            }
        }
    }
    temp->visit[temp->sym_y][temp->sym_x] = false;
    return;
}

int infix(char*way);

