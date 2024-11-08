#include<sstream>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Tree;
class TreeNode{
friend class Tree;
private:
    int data;
    TreeNode* left;
    TreeNode* down;
    TreeNode* right;
    TreeNode* up;
};

class Tree{
public:
    Tree();
    ~Tree();
    void BuildTree(int** matrix, int start_x, int start_y);
    //void del_node();
    void DFS(TreeNode* p, int** matrix, int cur_x, int cur_y);
    void LevelOrder();
    void PreOrder();
    void PostOrder();
    void Tpr(TreeNode* p);
    void Tpo(TreeNode* p);
private:
    TreeNode* root;
    bool** visit;
};

int width, height;

int main()
{
    int n;
    int start_x, start_y;
    int** matrix;
    string method;
    Tree t;
    cin >> n;

    for(int k=0; k<n; k++){
        //讀值
        cin >> width >> height;
        cin >> start_x >> start_y;
        matrix = new int*[height];
        for(int i=0; i<height; i++){
            matrix[i] = new int[width];
            for(int j=0; j<width; j++) cin >> matrix[i][j];
        }
        cin >> method;

        //輸出
        if(k==0) cout << n << endl;
        cout << width << " " << height << endl;
        cout << start_x << " " << start_y << endl;
        for(int i=0; i<height; i++){
            for(int j=0; j<width-1; j++){
                cout << matrix[i][j] << " " ;
            }
            cout << matrix[i][width-1];
            cout << endl;
        }
        cout << method << endl;

        t.BuildTree(matrix,start_x,start_y);
        if(method=="Level-order-traversal") t.LevelOrder();
        else if(method=="Pre-order-traversal") t.PreOrder();
        else if(method=="Post-order-traversal") t.PostOrder();
        cout << endl;

        //t.del_node();

        for(int i=0; i<height; i++) delete [] matrix[i];
        delete [] matrix;
    }

    return 0;
}

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree(){}

void Tree::BuildTree(int** matrix, int start_x, int start_y)
{
    visit = new bool*[height];
    for(int i=0; i<height; i++){
        visit[i] = new bool[width];
        for(int j=0; j<width; j++) visit[i][j] = 0;
    }

    root = new TreeNode;
    if(matrix[start_y][start_x]) root->data = matrix[start_y][start_x];
    DFS(root, matrix, start_x, start_y);

    for(int i=0; i<height; i++) delete [] visit[i];
    delete [] visit;
}

/*void Tree::del_node()
{
    queue<TreeNode*> q;
    TreeNode* currentNode = root;
    while(currentNode){
        if(currentNode->left) q.push(currentNode->left);
        if(currentNode->down) q.push(currentNode->down);
        if(currentNode->right) q.push(currentNode->right);
        if(currentNode->up) q.push(currentNode->up);
        currentNode = q.front();
    }
    while(!q.empty()){
        currentNode = q.front();
        delete currentNode;
    }
}*/

void Tree::DFS(TreeNode* p, int** matrix, int cur_x, int cur_y)
{
    int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}}; //左下右上(dj,di)
    int dx, dy; //下一步的位置
    p->data = matrix[cur_y][cur_x];
    visit[cur_y][cur_x] = true;
    for(int i=0; i<4; i++){
        dy = cur_y + dir[i][0]; dx = cur_x + dir[i][1];
        if(dy<height && dy>=0 && dx<width && dx>=0){ //判斷邊界條件
            if(matrix[dy][dx]&&(visit[dy][dx]==0)){
                if(i==0){
                    p->left = new TreeNode;
                    DFS(p->left, matrix, dx, dy);
                }
                if(i==1){
                    p->down = new TreeNode;
                    DFS(p->down, matrix, dx, dy);
                }
                if(i==2){
                    p->right = new TreeNode;
                    DFS(p->right, matrix, dx, dy);
                }
                if(i==3){
                    p->up = new TreeNode;
                    DFS(p->up, matrix, dx, dy);
                }
            }
            else{
                if(i==0) p->left = 0;
                if(i==1) p->down = 0;
                if(i==2) p->right = 0;
                if(i==3) p->up = 0;
            }
        }
        else continue;
    }
}

void Tree::LevelOrder()
{
    queue<TreeNode*> q;
    TreeNode* currentNode = root;
    while(currentNode){
        if(currentNode == root) cout << currentNode->data;
        else cout << " " << currentNode->data;

        if(currentNode->left) q.push(currentNode->left);
        if(currentNode->down) q.push(currentNode->down);
        if(currentNode->right) q.push(currentNode->right);
        if(currentNode->up) q.push(currentNode->up);

        if(q.empty()) return;
        currentNode = q.front();
        q.pop();
    }
}

void Tree::PreOrder()
{
    Tpr(root);
}

void Tree::Tpr(TreeNode* currentNode)
{
    if(currentNode == root) cout << currentNode->data;
    else cout << " " << currentNode->data;

    if(currentNode->left) Tpr(currentNode->left);
    if(currentNode->down) Tpr(currentNode->down);
    if(currentNode->right) Tpr(currentNode->right);
    if(currentNode->up) Tpr(currentNode->up);
}

void Tree::PostOrder()
{
    Tpo(root);
}

void Tree::Tpo(TreeNode* currentNode)
{
    if(currentNode->left) Tpo(currentNode->left);
    if(currentNode->down) Tpo(currentNode->down);
    if(currentNode->right) Tpo(currentNode->right);
    if(currentNode->up) Tpo(currentNode->up);
    cout << " " << currentNode->data;
}
