// 這是參考了debug熊所打出來的code 
#include<iostream>
#include<vector>
using namespace std;

int maze[101][101];
bool route[101][101];
int width;
int height;

bool isRoad(int now, int next);
bool finding(int x, int y, int now);

bool isRoad(int now, int next)
{
	if (next < now ) return 1;
	if (next % now == 0) return 0;
	return 1;
}

bool finding(int x, int y, int now = 0)
{
	int next;
	
	if (x >= width || y >= height || x < 0 || y < 0) return 0;
	if (route[x][y] == 1) return 0;
	next = maze[x][y];
	if (x != 0 || y != 0)
	{
		if(!isRoad(now,next)) return 0;
		route[x][y] = 1;
		if (x == width - 1 && y == height - 1) return 1;
	}
	if (finding(x, y+1, next)) return 1;
	if (finding(x+1, y, next)) return 1;
	if (finding(x-1, y, next)) return 1;
	if (finding(x, y-1, next)) return 1;
	return 0;		
}

int main(void)
{
	int num;
	int i, j, k;
	char ch[100];

	cin >> num;
	cout << num << endl;
	for (k = 0; k < num; k++){
		for (i = 0; i < 101; i++)
			for (j = 0; j < 101; j++)
			{
				maze[i][j] = 0;
				route[i][j] = 1;
			}
		cin >> width >> height;
		cout << width << endl << height << endl;
		for (j = 0; j < height; j++)
		{
			for (i = 0; i < width; i++)
			{
				cin >> maze[i][j];
				cout << maze[i][j];
				if (i != width - 1)
					cout << " ";
				route[i][j] = 0;
			}
			cout << endl;
		}
		if (finding(0,0)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
