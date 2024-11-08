#include<iostream>
#include<vector>
using namespace std;

struct position{
	int x, y;
	char ele;
};

int direct[101][101];
char maze[101][101];
bool visit[101][101];
int brac;
int width,height;
vector<position> mystack;

bool isroad(int x, int y, int nx, int ny);
int cate(char n);
void showIn();
void showPost();

int main(void)
{
	int num;
	int k,j,i;
	int x=1,y=1;
	bool flag=0;
	position next; 
	
	cin >> num;
	cout << num << endl;

	for (k = 0; k < num; k++)
	{
		cin >> width >> height;
		for (j = 0; j < 101; j++) //initial
		{
			for (i = 0; i < 101; i++)
			{
				if (i > 0 && j > 0 && i < width+1 && j < height+1)
				{
					cin >> maze[i][j];
					visit[i][j] = 0;
					direct[i][j] = 0;
				}else{
					maze[i][j] = '#';
					visit[i][j] = 1;
					direct[i][j] = 4;
				}
			}
		}
		mystack.clear();
		brac = 0;
		next.x = 1;
		next.y = 1;
		next.ele = maze[1][1];
		flag = 0;
		mystack.push_back(next);
		while(!flag)
		{
			if(x == width && y == height && brac == 0) break;;
			if (cate(maze[1][1]) == 2 || cate(maze[1][1]) == 4 || cate(maze[width][height]) == 3|| cate(maze[width][height]) == 2)
			{
				break;
			}
			if (direct[1][1] == 4) break;
			if (direct[x][y] == 0)
			{
				if (isroad(x, y, x, y+1))
				{
					next.x = x; 
					next.y = y+1;
					next.ele = maze[x][y+1];
					direct[x][y]++;
					visit[x][y] = 1;
					y++;
					mystack.push_back(next);
				}else{
					direct[x][y]++;					
				}
				continue;
			}
			else if (direct[x][y] == 1)
			{
				if (isroad(x, y, x+1, y))
				{
					next.x = x+1; 
					next.y = y;
					next.ele = maze[x+1][y];
					direct[x][y]++;	
					visit[x][y] = 1;				
					x++;
					mystack.push_back(next);					
				}else{
					direct[x][y]++;
				}
				continue;
			}
			else if (direct[x][y] == 2)
			{
				if (isroad(x, y, x-1, y))
				{
					next.x = x-1; 
					next.y = y;	
					next.ele = maze[x-1][y];				
					direct[x][y]++;
					visit[x][y] = 1;				
					x--;
					mystack.push_back(next);
				}else{
					direct[x][y]++;
				}
				continue;
			}
			else if (direct[x][y] == 3)
			{
				if (isroad(x, y, x, y-1))
				{
					next.x = x; 
					next.y = y-1;
					next.ele = maze[x][y-1];
					direct[x][y]++;
					visit[x][y] = 1;				
					y--;
					mystack.push_back(next);					
				}else{
					direct[x][y]++;
				}
				continue;
			}
			else if (direct[x][y] == 4)
			{
				if(x == 1 && y == 1)
				{
					break;
				}
				if (maze[x][y] == '(')
				{
					brac--;
				}
				else if (maze[x][y] == ')')
				{
					brac++;
				}
				visit[x][y] = 0;
				direct[x][y] = 0;
				mystack.pop_back();
				x = mystack.back().x;
				y = mystack.back().y;
				continue;
			}
		}
		cout << width << endl << height <<endl;
		for (j = 1; j <= height; j++)
		{
			for (i = 1; i <= width; i++)
			{
				cout << maze[i][j];
				if (i < width)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		if(x == 1 && y == 1)
		{
			cout << "No\n";
		}else{
			cout << "Yes\n";
			showIn();
			showPost();
		}
		x = 1;
		y = 1;
		mystack.clear();
	}
	
	return 0; 
}

bool isroad(const int x,const int y,const int nx,const int ny)
{
	if (nx < 1 || ny < 1 || nx > width || ny > height) return 0;
	if (visit[nx][ny]) return 0;
	if (cate(maze[x][y]) == 1)
	{
		if (cate(maze[nx][ny]) == 1) return 1;
		if (cate(maze[nx][ny]) == 2) return 1;
		if (cate(maze[nx][ny]) == 3) return 0;
		if (cate(maze[nx][ny]) == 4 && brac > 0) 
		{
			brac--; 
			return 1; 
		}
		return 0;		
	}
	else if (cate(maze[x][y]) == 2)
	{	
		if (cate(maze[nx][ny]) == 1) return 1;
		if (cate(maze[nx][ny]) == 2) return 0;
		if (cate(maze[nx][ny]) == 3) 
		{
			brac++; return 1;
		}
		if (cate(maze[nx][ny]) == 4) return 0;
		return 0;
	}
	else if (cate(maze[x][y]) == 3)
	{
		if (cate(maze[nx][ny]) == 1) return 1;
		if (cate(maze[nx][ny]) == 2) return 0;
		if (cate(maze[nx][ny]) == 3) 
		{
			brac++; return 1;
		}
		if (cate(maze[nx][ny]) == 4) return 0;
		return 0;
	}
	else if (cate(maze[x][y]) == 4)
	{
		if (cate(maze[nx][ny]) == 1) return 0;
		if (cate(maze[nx][ny]) == 2) return 1;
		if (cate(maze[nx][ny]) == 3) return 0;
		if (cate(maze[nx][ny]) == 4 && brac > 0) 
		{
			brac--; return 1;
		}
		return 0;
	}else{
		return 0;
	}
}

int cate(char n)
{
	switch (n)
	{
		case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '0':case ' ': return 1;
		case '+':case '-':case '*':case '/': return 2;
		case '(': return 3;
		case ')': return 4;
		default: return 0;
	}
}
void showPost()
{
	vector<char> tmp;
	if (!mystack.empty())
	{
		if(mystack.back().ele == '(') cout << " ";
	}
	for (int i=0; i <mystack.size(); i++)
	{
		switch(mystack[i].ele)
		{
			case '(':
				tmp.push_back(mystack[i].ele);
				break;
			case ')':
				while(!tmp.empty() && tmp.back() != '(')
				{
					cout << " " << tmp.back();
					tmp.pop_back();
				}
				if(tmp.back() == '(')
				{
					tmp.pop_back();
				}
				break;
			case '*': case '/':
				while(!tmp.empty() && (tmp.back() == '*' || tmp.back() == '/'))
				{
					cout << " " << tmp.back();
					tmp.pop_back();
				}
				cout << " ";
				tmp.push_back(mystack[i].ele);
				break;
			case '+': case '-':
				while(!tmp.empty() && cate(tmp.back()) == 2) 
				{
					cout << " " << tmp.back();
					tmp.pop_back();	
				}
				cout << " ";
				tmp.push_back(mystack[i].ele);
				break;
			default:
				cout << mystack[i].ele;
				break;
		}
	}
	while(!tmp.empty())
	{
		cout << " " << tmp.back();
		tmp.pop_back();
	}
	cout << endl;
}
void showIn()
{    
	int i;
	for (i = 0; i < mystack.size(); i++)
	{
		switch (cate(mystack[i].ele))
		{
			case 1:
				cout << mystack[i].ele;
				break;
			case 2:
				cout << " " << mystack[i].ele << " ";
				break;
			case 3:
				cout << mystack[i].ele << " ";
				break;
			case 4:
				cout << " " << mystack[i].ele;
				break;
		}
	}
	printf("\n");	
}
