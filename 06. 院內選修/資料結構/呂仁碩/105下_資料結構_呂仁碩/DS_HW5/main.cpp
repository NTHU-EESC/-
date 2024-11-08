#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <fstream>
using namespace std;

struct MyGraph{
  map<int, set<int> > vertics;          //Student No. , friend set
  void insert_edge(int u, int v) {
    vertics[u].insert(v);   //vertices[key] returns the specified set<int>
    vertics[v].insert(u);
  }
};

int num_edges (MyGraph & g)
{
  int nEdges = 0;
  for(map<int, set<int> >::iterator i=g.vertics.begin(); i!=g.vertics.end(); i++){
    nEdges += i->second.size();
  }
  return nEdges/2;
}

const int max_Friends(MyGraph &g){
    map<int, set<int> >::iterator i=g.vertics.begin();
    int Maxfriends = i->second.size();i++;

    for(;i!=g.vertics.end();i++){
        if(i->second.size() > Maxfriends) {
            Maxfriends = i->second.size();
        }
    }
    return Maxfriends;
}

const int MD2(MyGraph &g,int nV, int nE){      //max depth-2
    map<int, set<int> >::iterator a,b;
    set<int>::iterator x,y;
    map<int, bool > FriendList;
    map<int, bool >::iterator FriendIdx;
    int N_MD2 = 1;
    int counter = 0;

    for(a = g.vertics.begin(); a!=g.vertics.end();a++)
        FriendList.insert(pair<int, bool>(a->first,false));

    for(a = g.vertics.begin(); a != g.vertics.end(); a++,counter = 0){
        for(x = a->second.begin(); x != a->second.end();x++){      //depth-1 friend
            if(FriendList[*x]==false){
                //FriendList.insert(pair<int, bool>(*x,true));
                FriendList[*x] = true;
                counter++;
            }
            //for(b = g.vertics.begin();b.first != *x ;b++);

            for(y = g.vertics[*x].begin();y != g.vertics[*x].end(); y++)
                if(FriendList[*y]==false){
                    //FriendList.insert(pair<int, bool>(*y,true));
                    FriendList[*y] = true;
                    counter++;
                }
        }
        if(counter > N_MD2) N_MD2 = counter;
        for(FriendIdx = FriendList.begin()
            ;FriendIdx!=FriendList.end();FriendIdx++)
            FriendIdx->second = false;
    }

    return N_MD2;
}

void DFS(map<int, bool > &Visited ,MyGraph &g,int N){
    set<int>::iterator seti;

    Visited[N] = true;
        for(seti = g.vertics[N].begin();seti != g.vertics[N].end();seti++)
            if(!Visited[*seti]) DFS(Visited,g, *seti);
}

const int Ngroup(MyGraph &g){
    map<int, bool > Visited;
    map<int, bool >::iterator booli;
    map<int, set<int> >::iterator IDi;
    set<int>::iterator seti;
    int ngroup = 0;

    for(IDi = g.vertics.begin(); IDi!=g.vertics.end();IDi++)
        Visited.insert(pair<int, bool>(IDi->first,false));

    for(booli = Visited.begin();booli != Visited.end();booli++){
        if(!booli->second){
            DFS(Visited , g, booli->first);
            ngroup++;
        }
    }
    //delete[] Visited;
    return ngroup;
}



void process(MyGraph & g)
{
  int nV, nE;
  nV = g.vertics.size();
  nE = num_edges(g);
  cout << "- Number of students               : " << nV << endl;

  cout << "- Number of friendship connections : " << nE << endl;

  cout << "- Average friends per student      : " << setprecision(3) << float(nE) / nV << endl;

  cout << "- Max. friends per student         : " << max_Friends(g)<< endl;

  cout << "- Max. depth-2 friendship group    : " << MD2(g,nV,nE) << endl;

  cout << "- Number of separate groups        : " << Ngroup(g)<<endl;

  return;
}

void process_a_graph()
{
    int nV;
    cin >> nV;
    MyGraph g;
    for(; nV>0; nV--){
      int u, v;
      cin >> u >> v;
      g.insert_edge(u, v);
    }
    process(g);

}

int main()
{
  int n;

  freopen("t8.txt", "r", stdin);
  freopen("o8.txt", "w", stdout);
  cin >> n;
  for(int i=0; i<n; i++){
    cout << "School " << i << endl;
    process_a_graph();
  }
  return 0;
}
