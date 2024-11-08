#include<iostream>
using namespace std;

class maze
{
public:
    maze(int wv, int hv);
    ~maze();
    void maze_set(int w, int h);
private:
    int h, w;
    char** infix_maze;
};

maze::maze(int wv, int hv)
{
    w = wv;
    h = hv;
}

maze::~maze()
{
    for(int i=0; i<w; i++) delete [] infix_maze[i];
    delete [] infix_maze;
}

void maze::maze_set(int w, int h)
{
    infix_maze = new char*[w];
    for(int i=0; i<w; i++){
        infix_maze[i] = new char[h];
        for(int j=0; j<h; j++) cin >> infix_maze[i][j];
    }
}

int main(void)
{
    int n;
    cin >> n;

    int width, height;
    maze setting = new maze[n];

    for(int i=0; i<n; i++){
        cin >> width;
        cin >> height;
        setting[i](width, height);
        setting
    }

    for (int i=0; i<n; i++) delete [] parameter[i];  //先將每一個元素所指向的一維陣列先刪除
    delete [] parameter;  //在刪除全部的陣列

    return 0;
}
