#include<sstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
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
    string* path;
    string method;
};

string int2str(int &);

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
    path = new string[side];
    matrix = new int*[side];
    for(int i=0; i<side; i++){
        matrix[i] = new int[side];
        for(int j=0; j<side; j++) cin >> matrix[i][j];
    }
    cin >> method;
}

void Graph::DeleteGraph()
{
    for(int i=0; i<side; i++) delete [] matrix[i];
    delete [] matrix;
    delete [] s;
    delete [] dist;
    delete [] path;
}

void Graph::find_ans()
{
    for(int i=0; i<side; i++){
        for(int j=0; j<side; j++) path[j] = ""; //initialize
        ShortestPath(i);
    }
}

void Graph::ShortestPath(int v)
{
    int u, w;
    string str;
    for(int i=0; i<side; i++){
        s[i] = false;
        dist[i] = matrix[v][i]; //從v點至i點的距離
    }
    s[v] = true;
    dist[v] = 0;

    for(int i=0; i<side-1; i++){ //side-1 shortest paths from v
        //choose u that is not in S and has smallest dist[u]
        u = -1;
        for(int j=0; j<side; j++){
            if(dist[j] && !s[j]){ //dist[j] have value
                if((u==-1)||(dist[u]>dist[j])) u = j;
            }
        }
        if(u!=-1){ //當此時u=-1表示路已經走到盡頭了
            s[u] = true;
            for(int w=0; w<side; w++){ //for(each <u,w> in the graph){ //update dist[w]
                if(matrix[u][w] && !s[w]){ //從u點至w點有距離
                    if( ((dist[u]+matrix[u][w])<dist[w]) || (!dist[w]) ) dist[w] = dist[u]+matrix[u][w];//dist[w]==0 也符合
                }
            }
        }
    }
    output(v);
}

void Graph::output(int v)
{
    for(int i=0; i<side; i++){
        if(dist[i]){
            cout << "Path(" << v <<"," << i << "):";
            if(method == "Show-path"){
                for(int j=0; j<path[i].length()-1; j++){
                    cout << path[i][j] << "->";
                }
                cout << i << endl; //path[i][j]
            }
            else if(method == "Hide-path") cout << endl;
            cout << "Cost:" << dist[i] << endl;
        }
    }
}

string int2str(int &i){
    string s;
    stringstream ss(s);
    ss << i;
    return ss.str();
}
