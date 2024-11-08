// NTHU EE Data Structures, 2018 spring 

#define PRINT(x) cout << #x " = " << x << endl;

 // =======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  #include <fstream>
 /*||*/  #include <unistd.h>
 /*||*/  char INFILE[]   =  "11860_sampleIn.txt";
 /*||*/  char OUTFILE[]  =  "out.txt";
 /*||*/  char GOLDENFILE[] = "11860_sampleOut.txt";
 /*||*/  #endif
 // =======================================================================
#include<vector>
#define max 800

#include <iostream>
#include <string>
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
int priority(char op);
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
			}
			if(x == width && y == height && brac == 0) flag =1;
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
	if ((n - '0') >= 0 && (n - '0') <= 9) return 1;
	if (n == '+' || n == '-' || n == '*' || n == '/' ) return 2;
	if (n == '(') return 3;
	if (n == ')') return 4;
	if (n == ' ') return 1;
	return 0;	
}
void showPost()
{
	char s[max];
	vector<char> postfix;
    int i, j, top;
    for(i = 0, j = 0, top = 0; i < mystack.size(); i++)
	{
		switch(cate(mystack[i].ele))
		{
        case 1: 
			postfix.push_back(mystack[i].ele); 
			if (cate(mystack[i+1].ele) != 1)
			{
				postfix.push_back(' ');	
			}
			break; 
        case 2:
            while(priority(s[top]) >= priority(mystack[i].ele)) { 
                postfix.push_back(s[top--]);
            } 
            s[++top] = mystack[i].ele;  
            break;         
		case 3:              
            s[++top] = mystack[i].ele;
            break; 
        case 4:
            while(s[top] != '(') {  
                postfix.push_back(s[top--]);
            } 
            top--; 
            break; 
    	}
	}
    while(top > 0) { 
        postfix.push_back(s[top--]);
    }
    for(i = 0; i < postfix.size(); i++)
    {
    	printf("%c", postfix[i]);
    	if (cate(postfix[i]) != 1 && i != postfix.size()-1)
    	{
    		printf(" ");
		}
	}
	printf("\n");
	postfix.clear();
}

int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    } 
} 
void showIn()
{    
	int i;
	for (i = 0; i < mystack.size(); i++)
	{
		if (cate(mystack[i].ele) == 1) cout << mystack[i].ele;
		else if (cate(mystack[i].ele) == 2) cout << " " << mystack[i].ele << " ";
		else if (cate(mystack[i].ele) == 3) cout << mystack[i].ele << " ";
		else if (cate(mystack[i].ele) == 4) cout << " " << mystack[i].ele;
	}
	printf("\n");	
}
