#include<sstream>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Graph{
public:
    Graph();
    ~Graph();
    void SetGraph(); //Ū��
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
int char2int(char c);
int compare_char(char c, char d);

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
        matrix[i] = new int[side];\
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

void Graph::ShortestPath(int v)//�ݭץ�...�i��S��k���L�Ҧ������|
{
    int u, w, length;
    string str, self, buf;
    for(int i=0; i<side; i++){
        s[i] = false;
        dist[i] = matrix[v][i]; //The distance from point v to point i
    }
    s[v] = true;
    dist[v] = 0;
    str = int2str(v);
    for(int i=0; i<side; i++){
        self = int2str(i);
        path[i] += str;
        path[i] += self;
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
                    if( ((dist[u]+matrix[u][w])<dist[w]) || (!dist[w]) ){ //dist[w]==0 �]�ŦX
                        dist[w] = dist[u] + matrix[u][w];
                        path[w] = path[u];
                        self = int2str(w);
                        path[w] += self;
                    }
                    else if( ((dist[u]+matrix[u][w])==dist[w]) ){
                        buf = path[u];
                        self = int2str(w);
                        buf += self;
                        length = ((path[w].length()-buf.length())>0) ? buf.length():path[w].length();
                        for(int l=0; l<length; l++){
                            if((path[w][l]-buf[l])>0){
                                path[w] = buf;
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
