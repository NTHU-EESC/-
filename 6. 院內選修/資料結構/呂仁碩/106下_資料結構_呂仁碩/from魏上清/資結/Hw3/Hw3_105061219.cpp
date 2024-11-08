#include<iostream>
#include<queue>
#include<string>
#include<stdio.h>
using namespace std;

int matrix[101][101];
int visit[101][101];
int width,height;

class TreeNode{
public:
	TreeNode *L;
	TreeNode *D;
	TreeNode *U;
	TreeNode *R;
	int data;
};
TreeNode *start = new TreeNode;

void build(TreeNode *&node, int x, int y);
void LevelOrder();
void PreOrder(TreeNode *curr);
void PostOrder(TreeNode *curr);
void cleantree(TreeNode *root);
void DeleteNode(TreeNode *curr);

int main(void)
{
	int num;
	string method;
	int i,j,k,x,y;
	
	cin >> num;
	printf("%d\n",num);
	
	for(k = 0; k < num; k++)
	{
		cin >> width >> height;
		printf("%d %d\n",width,height);
		cin >> x >> y;
		printf("%d %d\n",x,y);
		
		for (j = 0; j < 101; j++) //initial
			for (i = 0; i < 101; i++)
			{
				if(i < width && j < height)
				{
					visit[i][j] = 0;
					cin >> matrix[i][j];
				}else{
					matrix[i][j] = 0;
					visit[i][j] = 1;
				}
			}
		for (j = 0; j < height; j++)
		{ 
			for (i = 0; i < width; i++)
			{
				printf("%d", matrix[i][j]);
				if (i < width-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		start->data = matrix[x][y];
		visit[x][y] = 1;
		build(start->L,x-1,y); 
		build(start->D,x,y+1);
		build(start->R,x+1,y); 
		build(start->U,x,y-1);
		cin >> method;
		if (method == "Level-order-traversal")
		{
			printf("Level-order-traversal\n");
			LevelOrder();
			printf("\n");
		}
		else if (method == "Pre-order-traversal")
		{
			printf("Pre-order-traversal\n");
			PreOrder(start);
			printf("\n");
		}
		else if(method == "Post-order-traversal")
		{
			printf("Post-order-traversal\n");
			PostOrder(start);
			printf("\n");
		}
		DeleteNode(start);
	}
	delete start; 
	return 0; 
} 
void build(TreeNode *&node,int x,int y)
{
	if (x < 0 || y < 0 || x >= width || y >= height || matrix[x][y] == 0 || visit[x][y] == 1) 
	{
		node = 0;
		return;
	}
	TreeNode *newnode = new TreeNode;
	node = newnode;
	visit[x][y]++;
	newnode->data = matrix[x][y];
	build(newnode->L,x-1,y);
	build(newnode->D,x,y+1);
	build(newnode->R,x+1,y);
	build(newnode->U,x,y-1);
	return;
}
void LevelOrder()
{
	queue <TreeNode*> q;
	TreeNode *curr = start;
	while(curr)
	{
		if (curr == start) printf("%d",curr->data);			
		else printf(" %d",curr->data);
		if (curr->L) q.push(curr->L);
		if (curr->D) q.push(curr->D);
		if (curr->R) q.push(curr->R);
		if (curr->U) q.push(curr->U);
		if (q.empty()) return;
		curr = q.front();
		q.pop();
	}
}
void PreOrder(TreeNode *curr)
{
	if(!curr) return;
	if (curr == start) printf("%d",curr->data);			
	else printf(" %d",curr->data);
	PreOrder(curr->L);
	PreOrder(curr->D);
	PreOrder(curr->R);
	PreOrder(curr->U);
}
void PostOrder(TreeNode *curr)
{
	if(!curr) return;
	PostOrder(curr->L);
	PostOrder(curr->D);
	PostOrder(curr->R);
	PostOrder(curr->U);
	if (curr == start) printf("%d",curr->data);
	else printf("%d ",curr->data);			
}
void DeleteNode(TreeNode *curr)
{
	if (!curr) return;
	DeleteNode(curr->L);
	DeleteNode(curr->D);
	DeleteNode(curr->R);
	DeleteNode(curr->U);
	if (curr == start) return;
	delete curr;
}
