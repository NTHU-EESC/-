// NTHU EE Data Structures, 2018 spring 

#define PRINT(x) cout << #x " = " << x << endl;

 // =======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  #include <fstream>
 /*||*/  #include <unistd.h>
 /*||*/  char INFILE[]   =  "in.txt";
 /*||*/  char OUTFILE[]  =  "out.txt";
 /*||*/  char GOLDENFILE[] = "golden.txt";
 /*||*/  #endif
 // =======================================================================

#include<iostream>
#include<string>
#include<vector>
#define Maxnum 1e9
using namespace std;
int cost[101][101];
int from[101][101];
int num;
void showpath(int begin, int end);

int main()
{

 // =======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  ifstream ftest(INFILE);
 /*||*/  if(ftest.fail()){ cout << "Cannot open input file: " << INFILE << endl; return 0; }
 /*||*/  ftest.close();
 /*||*/  cout << endl << "  Note: cout and printf are redirected to the file: " << OUTFILE << endl << endl;
 /*||*/  freopen(INFILE, "r", stdin);
 /*||*/  int _save_out_ = dup(1);
 /*||*/  freopen(OUTFILE, "w", stdout);
 /*||*/  #endif
 // =======================================================================

    // Your code goes here
	int i,j,k;
	string mode;
	cin >> num;
		
	for (j = 0; j < 101; j++)
		for (i = 0; i < 101; i++)
			if(i < num && j < num)
			{
				cin  >> cost[j][i];
				if(!cost[j][i] && i != j) cost[j][i] = Maxnum;
			}
			else cost[i][j] = Maxnum;		
					
	for (j = 0; j < num; j++)
		for (i = 0; i < num; i++)
			if (cost[j][i] != Maxnum || !cost[j][i]) from[j][i] = j;
			else from[j][i] = -1;
			
	for(k = 0 ;k < num; k++)
        for(i = 0; i < num; i++)
            for(j = 0; j < num; j++)
            	if(i != j && j != k && k != i)
            	    if(cost[i][j] > cost[i][k] + cost[k][j] )
            	    {
            	        cost[i][j] = cost[i][k] + cost[k][j];
            	        from[i][j] = k;
					}
					else if (cost[i][j] == cost[i][k] + cost[k][j])
						if (from[i][j] < from[k][j]) from[i][j] = from[k][j];

	cin >> mode;
	if (mode == "Hide-path")
	{
		for (j = 0; j < num; j++)
			for (i = 0; i < num; i++)
			{
				if(i == j) continue;
				if (cost[j][i] != Maxnum)
				{
					cout << "Path(" << j << "," << i << "):" << endl;
					cout << "Cost:" << cost[j][i] << endl; 
				}
			}
	}
	else if (mode == "Show-path")
	{
		for (j = 0; j < num; j++)
			for (i = 0; i < num; i++)
			{
				if(i == j) continue;
				if (cost[j][i] != Maxnum)
				{
					cout << "Path(" << j << "," << i << "):";
					showpath(j,i);
					cout << "Cost:" << cost[j][i] << endl;; 
				}
			}	
	}
 // ======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  dup2(_save_out_, 1);
 /*||*/  ifstream f1(OUTFILE);
 /*||*/  ifstream f2(GOLDENFILE);
 /*||*/  if(f1.fail() || f2.fail()){
 /*||*/       cout << "  File cannot be open. Comparison is skipped." << endl << endl;
 /*||*/  }else{
 /*||*/    string s1, s2;
 /*||*/    bool mismatch = false;
 /*||*/    for(int i=0; ; i++){
 /*||*/        getline(f1, s1);
 /*||*/        getline(f2, s2);
 /*||*/        if(f1.eof() && f2.eof()) break;
 /*||*/        if(s2.length() && s2[s2.size()-1] == '\r') s2.erase( s2.length()-1, 1);
 /*||*/        if(s1!=s2){
 /*||*/            mismatch = true;
 /*||*/            cout << "L" << i << ":" << endl;
 /*||*/            cout << "  expect: " << s2 << endl;
 /*||*/            cout << "  yours : " << s1 << endl;
 /*||*/        }
 /*||*/    }
 /*||*/    if (!mismatch) cout << endl << "  ^__^ Output file " << OUTFILE << " matches the goden file " << GOLDENFILE << "." << endl << endl;
 /*||*/    else           cout << endl << "  Files mismatch!!!" << endl << endl;
 /*||*/  }
 /*||*/  #endif
 // ======================================================================

    return 0;
}
void showpath(int begin, int end)
{
	vector<int> q;
	for (;;)
		if (from[begin][end] != begin)
		{
			q.push_back(end);
			end = from[begin][end]; 
		}
		else
		{
			q.push_back(end);
			break;
		}
	q.push_back(begin);
	while(!q.empty())
	{
		if(q.size() != 1) cout << q.back() << "->";
		else cout << q.back() << endl;
		q.pop_back();
	}
}
