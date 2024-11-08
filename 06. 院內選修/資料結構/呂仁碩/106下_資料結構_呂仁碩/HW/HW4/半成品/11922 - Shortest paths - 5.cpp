#include<sstream>
#include<iostream>
#include<string>
//#include<stdlib.h>
using namespace std;

class Graph{
public:
    Graph();
    ~Graph();
    void SetGraph(); //讀值
    void DeleteGraph();
    void find_ans();
    void ShortestPath(int v); //Dijkstra's algorithm
    void output(int v);
private:
    int** matrix;
    int side;
    bool* s; //set
    int* dist; //distance
    int** path;
    string method;
};

int main()
{
    string method;
    Graph g;
    g.SetGraph();
    g.find_ans();
    g.DeleteGraph();
    return 0;
}

Graph::Graph()
{
    matrix = NULL;
}

Graph::~Graph(){}

void Graph::SetGraph()
{
    cin >> side;
    s = new bool[side];
    dist = new int[side];
    path = new int*[side];
    matrix = new int*[side];
    for(int i=0; i<side; i++){
        path[i] = new int[side+1];
        matrix[i] = new int[side];
        for(int j=0; j<side; j++) cin >> matrix[i][j];
    }
    cin >> method;
}

void Graph::DeleteGraph()
{
    for(int i=0; i<side; i++){
        delete [] matrix[i];
        delete [] path[i];
    }
    delete [] matrix;
    delete [] s;
    delete [] dist;
    delete [] path;
}

void Graph::find_ans()
{
    for(int i=0; i<side; i++){
        for(int j=0; j<side; j++){ //initialize
            for(int k=0; k<=side; k++)path[j][k] = 200;
        }
        ShortestPath(i);
    }
}

void Graph::ShortestPath(int v)//待修正...可能沒辦法走過所有的路徑
{
    int u, w, length;
    //string str, self, buf;
    int* buf = new int[side];

    for(int i=0; i<side; i++){
        s[i] = false;
        dist[i] = matrix[v][i]; //The distance from point v to point i
    }
    s[v] = true;
    dist[v] = 0;
    for(int i=0; i<side; i++){
        path[i][0] = v;
        path[i][1] = i;
    }

    for(int i=0; i<side; i++){ //side-1 shortest paths from v
        //choose u that is not in S and has smallest dist[u]
        u = -1;
        for(int j=0; j<side; j++){
            if(dist[j] && !s[j]){ //dist[j] have value
                if((u==-1)||(dist[u]>dist[j])) u = j;
            }
        }
        if(u!=-1){ //When u = -1 means that the road has come to an end.
            s[u] = true;
            for(int w=0; w<side; w++){ //for(each <u,w> in the graph){ //update dist[w]
                if(matrix[u][w] && !s[w]){ //There is a distance from point u to point w
                    if( ((dist[u]+matrix[u][w])<dist[w]) || (!dist[w]) ){ //dist[w]==0 也符合
                        dist[w] = dist[u] + matrix[u][w];
                        for(int num=0; num<=side; num++) path[w][num] = path[u][num];
                        for(int num=0; num<=side; num++){
                            if(path[w][num]==200){
                                    //cout << num << "," << path[w][num] << endl;
                                path[w][num] = w;
                                break;
                            }
                        }
                    }
                    else if( ((dist[u]+matrix[u][w])==dist[w]) ){
                        for(int num=0; num<=side; num++) buf[num] = path[u][num];
                        for(int num=0; num<=side; num++){
                            if(buf[num]==200){
                                buf[num] = w;
                                break;
                            }
                        }
                        for(int l=0; l<side; l++){
                            if((path[w][l]-buf[l])>0){
                                for(int num=0; num<=side; num++) path[w][num] = buf[num];
                                break;
                            }
                            else if((path[w][l]-buf[l])<0) break;
                            else if((path[w][l]-buf[l])==0) continue;
                        }
                    }
                    else continue;
                }
                else continue;
            }
        }
        else break;
    }
    output(v);
}

void Graph::output(int v)
{
    for(int i=0; i<side; i++){
        if(dist[i]){
            cout << "Path(" << v <<"," << i << "):";
            if(method == "Show-path"){
                for(int j=0; j<side; j++){
                    if((path[i][j]!=200)&&(path[i][j+1]!=200)) cout << path[i][j] << "->";
                    else break;
                }
                cout << i << endl; //path[i][j]
            }
            else if(method == "Hide-path") cout << endl;
            cout << "Cost:" << dist[i] << endl;
        }
    }
}
