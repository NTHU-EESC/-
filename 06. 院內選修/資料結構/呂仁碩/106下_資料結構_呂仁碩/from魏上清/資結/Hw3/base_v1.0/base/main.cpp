// NTHU EE Data Structures, 2018 spring 

#define PRINT(x) cout << #x " = " << x << endl;

 // =======================================================================
 /*||*/  #ifndef ONLINE_JUDGE
 /*||*/  #include <fstream>
 /*||*/  #include <unistd.h>
 /*||*/  char INFILE[]   =  "11901_sampleIn.txt";
 /*||*/  char OUTFILE[]  =  "out.txt";
 /*||*/  char GOLDENFILE[] = "11901_sampleOut.txt";
 /*||*/  #endif
 // =======================================================================

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
					cout << matrix[i][j];
					if (i < width-1)cout << " ";
				}else{
					if (i == width && j < height) cout << endl;
					matrix[i][j] = 0;
					visit[i][j] = 1;
				}
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
