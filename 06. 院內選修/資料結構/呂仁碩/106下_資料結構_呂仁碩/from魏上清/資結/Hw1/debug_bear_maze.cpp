#include<iostream>
#include<vector>
using namespace std;

bool mazeFinding(vector<vector<int> >&maze, vector<vector<bool> > &trace,int x, int y, int w, int h, int n1);
bool isOk(int n1, int n2);


bool mazeFinding(vector<vector<int> >&maze, vector<vector<bool> > &trace,int x, int y, int w, int h, int n1 = 0)
{

	int n2;
	
	if(x >=w || x < 0 || y >= h || y < 0) return 0;
	if(trace[y][x] == 1) return 0;
	
	n2 = maze[y][x];

	if(x != 0 || y != 0)
	{
		if(!isOk(n1, n2) ) return 0;
		trace[y][x] = 1;
		if(x == w - 1 && y == h - 1) return 1;
	}
	if(mazeFinding(maze, trace, x, y+1,w,h,n2)) return 1;
	if(mazeFinding(maze, trace, x+1, y,w,h,n2)) return 1;
	if(mazeFinding(maze, trace, x-1, y,w,h,n2)) return 1;
	if(mazeFinding(maze, trace, x, y-1,w,h,n2)) return 1;
	return 0;
}

bool isOk(int n1, int n2)
{
	if(n2 < n1) return 1;
	if(n2 % n1 == 0) return 0;
	return 1;
}

int main(void)
{
	int cases;
	cin >> cases;
	cout << cases << endl;
	for(int i = 0; i < cases; i++)
	{
		int w,h;
		vector<vector<int> > maze;
		vector<vector<bool> > trace;
		cin >> w >> h;
		cout << w << endl << h << endl;

		maze.resize(h);
		for(int j = 0; j < h; j++)
		{
			maze[j].resize(w);
		}

		trace.resize(h);
		for(int j = 0; j < h; j++)
		{
			trace[j].resize(w);
		}
		
		for(int j = 0; j < h; j++)
		{
			for(int k = 0; k < w; k++)
			{
				cin >> maze[j][k];
			}
		}

		for(int j = 0; j < h; j++)
		{
			for(int k = 0; k < w; k++)
			{
				cout << maze[j][k];
				if(k != w-1) cout << " ";
			}
			cout << endl;
		}		

		if(mazeFinding(maze, trace,0,0,w,h) ) 
		{
			cout << "Yes" << endl;
			for(int j = 0; j < h; j++)
			{
				for(int k = 0; k < w; k++)
				{
					cout << trace[j][k];
					if(k != w-1) 
					cout << " ";
				}
				cout << endl;
			}
		}else{ 
			cout << "No" << endl;
		} 
	}
	
	return 0;
}
