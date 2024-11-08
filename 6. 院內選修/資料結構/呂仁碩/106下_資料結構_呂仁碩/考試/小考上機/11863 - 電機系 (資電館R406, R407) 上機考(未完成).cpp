#include <iostream>
//#include <fstream>
using namespace std;

typedef struct{
    int dx, dy;
    int before;
    int now;
}info;

int find_way(int** maze, bool** walk);
int check(int before, int now);
void route(int** maze, bool** walk, info* object);

int h, w; // height represented by h, width represented by w
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}}; //下右左上
int main()
{
    int num, out; //out==1表示有解
    //ifstream fin("my.txt");
    //fin >> num;
    cin >> num;
    int** maze;
    bool** walk;

    cout << num << endl;
    for(int i=0; i<num; i++){
        out = 0; h = 0; w = 0;
        cin >> w >> h;
        //fin >> w >> h;
        maze = new int*[h];
        walk = new bool*[h];
        for(int j=0; j<h; j++){
            maze[j] = new int[w];
            walk[j] = new bool[w];
            for(int k=0; k<w; k++){
                cin >> maze[j][k];
                //fin >> maze[j][k];
                walk[j][k] = false;
            }
        }
        //if(i==1) cout << "2 " << endl;
        out = find_way(maze, walk);
        //if(i==1) cout << "2 out " << endl;
        cout << w << endl << h << endl;
        for(int j=0; j<h; j++){
            for(int k=0; k<w; k++) cout << maze[j][k];
            cout << endl;
        }
        if(out) cout << "Yes" << endl;
        else cout << "No" << endl;

        for(int j=0; j<h; j++) delete [] maze[h];
        for(int j=0; j<h; j++) delete [] walk[h];
        delete [] maze;
        delete [] walk;
    }
    return 0;
}

int find_way(int** maze, bool** walk)
{
    //cout << "find_way" << endl;
    info* object;
    object->dx = 0; object->dy = 0; //x,y座標初始化
    //cout << "find_way-1" << endl;
    object->before = 0; object->now = maze[0][0];
    walk[0][0] = true;
    route(maze, walk, object);
    //cout << "out_route" << endl;
    if(object->before==0) return 0;
    else return 1;
}

int check(int before, int now){
    if(now % before == 0) return 0;
    else return 1;
}

void route(int** maze, bool** walk, info* object)
{
    int x, y;
    int temp;
    //cout << "route" << endl;
    for(int i=0; i<4; i++){
        //cout << i << endl;
        x = object->dx + dir[i][0]; y = object->dy + dir[i][1];
        if(y==h-1 && x==w-1){ // 判斷是否是終點
            if(check(maze[y-dir[i][1]][x-dir[i][0]], maze[y][x])&&(!walk[y][x])){ //表示合法
                break;
            }
            else continue;
        }
        else if(y<h && x<w && y>=0 && x>=0){ // 判斷邊界條件
            if(check(maze[y-dir[i][1]][x-dir[i][0]], maze[y][x])&&(!walk[y][x])){ //表示合法
                temp = object->before;
                object->before = object->now;
                object->now = maze[y][x];
                object->dx = x;
                object->dy = y;
                walk[y][x] = true;
                route(maze, walk, object);
                walk[y][x] = false;
                object->dx -= dir[i][0];
                object->dy -= dir[i][1];
                object->now = object->before;
                object->before = temp;
            }
        }
    }
    return;
}
