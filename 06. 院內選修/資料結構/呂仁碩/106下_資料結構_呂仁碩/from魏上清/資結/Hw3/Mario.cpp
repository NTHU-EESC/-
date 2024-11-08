#include<iostream>

using namespace std;

int matrix[101][101];
bool visit[101][101];
int width,height,step,maxnum;

struct TreeNode{
	TreeNode *L;
	TreeNode *D;	
	TreeNode *U;
	TreeNode *R;
	int data;
};

TreeNode *start = new TreeNode;

void build(TreeNode *&node, int x, int y, int rank);
void findmax(TreeNode *curr, int rank);

int main(void)
{
	int num;
	int i,j,k,x,y;

	cin  >> num;

	for(k = 0; k < num; k++)
	{
		maxnum = 0;
		cin >> width >> height >> x >> y;
		for(j = 0; j < 101; j++)
			for(i = 0; i < 101; i++)
			{
				if(i < width && j < height)
				{
					visit[i][j] = 0;
					cin >> matrix[i][j]; 
				}else{
					visit[i][j] = 1;
					matrix[i][j] = 0;
				}
			}
		cin >> step;
	
		start->data = matrix[x][y];
		visit[x][y] = 1;
		build(start->L,x-1,y,1);	
		build(start->D,x,y+1,1);	
		build(start->R,x+1,y,1);	
		build(start->U,x,y-1,1);
		//findmax(start, 0);
		step = 0;
		cout << maxnum << endl;	
	}

	return 0;
}
void build(TreeNode *&node, int x, int y, int rank)
{
	if(rank > step || x < 0 || y < 0 || x >= width || y >= height || matrix[x][y] == 0 || visit[x][y] == 1)
	{
		node = 0;
		return;
	}
	TreeNode *p = new TreeNode;
	node = p;
	visit[x][y] = 1;
	p->data = matrix[x][y];
	if(rank == step)
	{
		if(p->data > maxnum)
		{
			maxnum = p->data;
			return;
		}
	}	
	build(p->L,x-1,y,rank+1);	
	build(p->D,x,y+1,rank+1);	
	build(p->R,x+1,y,rank+1);	
	build(p->U,x,y-1,rank+1);
}
