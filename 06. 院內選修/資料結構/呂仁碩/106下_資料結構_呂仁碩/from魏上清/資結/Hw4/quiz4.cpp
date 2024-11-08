#include<iostream>

using namespace std;

int cost[101][101];

int main(void)
{
	int i,j,k,l;
	int num, ver; 
	

	cin >> ver;
	for (j = 0; j < 101; j++)
		for (i = 0; i < 101; i++)
			if(i < ver && j < ver)
			{
				cin >> cost[j][i];
				if(!cost[j][i]) cost[j][i] = 10000;
				else cost[j][i] += j;  
			}
			else cost[j][i] = 10000;

	for (k = 0; k < ver; k++)
		for (i = 0; i < ver; i++)
			for (j = 0; j < ver; j++)
			{
				if(i == j && j == k && k == i) continue;
				if (cost[i][j]) 
					if(cost[i][j] > cost[i][k] + cost[k][j]) 
					{
						cost[i][j] = cost[i][k] + cost[k][j];
					}
			}		
	for (j = 0; j < ver; j++)
		for (i = 0; i < ver; i++)
		{
			if (i == j) continue;
			if (cost[j][i] != 10000)
			{
					cout << "Path(" << j << "," << i << "):" << endl;
					cout << "Cost:" << cost[j][i] + i << endl; 
			}
		}

	return 0;
}

