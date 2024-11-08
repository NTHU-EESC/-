#include<iostream>
#include<string>
#include<vector>
#define Maxnum 1e9

using namespace std;
	
int cost[101][101];
int next[101][101];
int num;
void showpath(int begin, int end);

int main()
{
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
			else cost[j][i]= Maxnum;		
					
	for (j = 0; j < num; j++)
		for (i = 0; i < num; i++)
			if (cost[j][i] != Maxnum || !cost[j][i]) next[j][i] = i;
			else next[j][i] = -1;
			
	for(k = 0 ;k < num; k++)
        for(i = 0; i < num; i++)
            for(j = 0; j < num; j++)
            	if(i != j && j != k && k != i)
            	    if(cost[i][j] > cost[i][k] + cost[k][j] )
            	    {
            	        cost[i][j] = cost[i][k] + cost[k][j];
            	        next[i][j] = next[i][k];
					}
					else if (cost[i][j] == cost[i][k] + cost[k][j])
						if (next[i][j] > next[i][k]) next[i][j] = next[i][k];

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
	return 0;
}
void showpath(int begin, int end)
{
	cout << begin;
	for(;;)
	{
		if(begin == end) break;
		cout << "->" << next[begin][end];
		begin = next[begin][end];
	}
	cout << endl;	
}
