#include <iostream>
#include <stack>
using namespace std;
void toPostfix(char *output, int n);
class term
{
	private:
		int row;
		int col;
		int dir;
		char value;
		int kind;
		int priority;
		int inStack;
	public:
		void iniInstack();
		int getRow();
		int getCol();
		int getDir();
		int getKind();
		int getPri();
		char getValue();
		void setAll(int a, int b, int c,char d);
		void setKind();
		void setPri();
		void setInStacK();
};
void term::iniInstack()
{
	inStack = 0;
	return;
}
void term::setInStacK()
{
	inStack=1;
	return;
}
void term::setPri()
{
	switch (value) {
		case '(': {
			if (inStack) {
				priority = 0;
			}
			else {
				priority = 8;
			}
			break;
		}
		case '*': {
			priority = 7;
			break;
		}
		case '/': {
			priority = 7; 
			break;
		}
		case '+': {
			priority = 6; 
			break;
		}
		case '-': {
			priority = 6; 
			break;
		}
		default: {
			priority = -1;
			break;
		}
	}
	return;
}
void term::setKind()
{
	if (value>='1' && value<='9') { //數字 
		kind = 0;
	}
	else if (value=='*' || value=='+' || value=='/' || value=='-') { //加減乘除 
		kind = 1;
	}
	else {
		kind = 2;
	}
} 
void term::setAll(int a, int b, int c,char d)
{
	row = a;
	col = b;
	dir = c;
	value = d;
}

int term::getCol()
{
	return col;
}
int term::getPri()
{
	return priority;
}

int term::getRow()
{
	return row;
}

int term::getDir()
{
	return dir;
}
int term::getKind()
{
	return kind;
}
char term::getValue()
{
	return value;
}
int main(void)
{
	int total;
	int times;
	int nCol,nRow;
	stack<term> route;
	cin >> total;
	cout << total << endl;
	for (times=0; times<total; times++) {
		cin >> nCol >> nRow;
		char maze[nRow][nCol];
		int mark[nRow][nCol];
		int nF=0,flag_F = 0;
		fill(&mark[0][0],&mark[0][0]+nRow*nCol,0);
		cout << nCol << endl << nRow << endl;
		for (int i=0; i<nRow; i++) {
			for (int j=0; j<nCol; j++) {
				cin >> maze[i][j];
			}
		}
		for (int i=0; i<nRow; i++) {
			int f=0;
			for (int j=0; j<nCol; j++) {
				if (f!=nCol-1) cout << maze[i][j] <<' ';
				else cout << maze[i][j];
				f++;
			}
			cout <<endl;
		}
		term t0,tF;
		t0.setAll(0,0,0,maze[0][0]);
		t0.setKind();
		tF.setAll(nRow-1,nCol-1,0,maze[nRow-1][nCol-1]);
		tF.setKind();
		mark[0][0]=1;
		if (t0.getKind()==1 || t0.getValue()==')') {
			cout << "No" << endl;
			flag_F=2;
		}
		else if (tF.getKind()==1 || tF.getValue()=='(') {
			cout << "No" << endl;
			flag_F=2;			
		}
		else if (t0.getValue()=='(') {
			nF++;
			route.push(t0);	
		}
		else {
			route.push(t0);
		}
		while (!route.empty() && flag_F==0) {
			term thisT, pushT,nextT;
			int thisR,thisC,nextR,nextC,thisD,thisV,thisK,nextK;
			thisT = route.top();
			thisR = thisT.getRow();
			thisC = thisT.getCol();
			thisD = thisT.getDir();
			thisV = thisT.getValue();
			thisK = thisT.getKind();
			//cout << thisC<<endl;
			route.pop();
			do {
				int move = 0;
				switch (thisD) {
					case 0: {  						//下 
						if (thisR!=nRow-1) {
							nextR = thisR + 1;
							nextC = thisC;
						}	
						else {
							nextR = -1;
						}
					break;
					}
					case 1: {						//右 
						if (thisC!=nCol-1) {
							nextR = thisR;
							nextC = thisC + 1;
						}
						else {
							nextR = -1;
						}
						break;
					}
					case 2: {						//左 
						if (thisC!=0) {
							nextR = thisR;
							nextC = thisC - 1;
						}
						else {
							nextR = -1;
						}
						break;
					}
					case 3: {						//上 
						if (thisR!=0) {
							nextR = thisR - 1;
							nextC = thisC;
						}
						else {
							nextR = -1;
						}
						break;
					}
					default : {
						nextR = -1;
						break;
					}
				}
				if (nextR == nRow-1 && nextC==nCol-1 && (nF==0 || (nF==1 && maze[nextR][nextC]==')'))) {
					nextT.setAll(nextR,nextC,0,maze[nextR][nextC]);
					nextT.setKind();
					nextK=nextT.getKind();
					switch (thisK) {
						case 0: {
							if (nextK==0)	{
								flag_F=1;
							}
							else if (nF==1 && maze[nextR][nextC]==')') {
								flag_F=1;
							}
							else {
								thisD++;
							}
							break;
						}
						case 1: {
							if (nextK==0) {
								flag_F=1;
							}
							else {
								thisD++;
							}
							break;
						}
						case 2: {
							if (maze[thisR][thisC]==')') {
								if (maze[nextR][nextC] == ')' && nF==1) {
									flag_F = 1;
								}
								else thisD++;
							}
							else thisD++;
							break;
						}
						default:{
							break;
						}
					}
					if (flag_F == 1) {
						int i=1;
						term lastT;
						lastT.setAll(thisR,thisC,0,maze[thisR][thisC]);
						lastT.setKind();
						route.push(lastT);
						lastT.setAll(nextR,nextC,0,maze[nextR][nextC]);
						lastT.setKind();
						route.push(lastT);
						cout << "Yes"<< endl;
						int number = route.size();
						char output[number];
						while (!route.empty()) {
							term t100;
							t100 = route.top();
							output[number-i] = t100.getValue();
							route.pop();
							i++;
						}		
						for (int j=0; j<number-1; j++) {
							if (output[j]>='1' && output[j]<='9') {
								if (output[j+1]>='1' && output[j+1]<='9')
									cout << output[j];
								else cout << output[j]<<' ';
							}
							else cout << output[j] <<' ';
						}
						cout << output[number-1];
						cout << endl;
						toPostfix(output,number);
					}
				}
				else if (nextR!=-1 && (nextR!=nRow-1 || nextC!= nCol-1) && !mark[nextR][nextC]) {
					nextT.setAll(nextR,nextC,0,maze[nextR][nextC]);
					nextT.setKind();
					nextK=nextT.getKind();
					switch (thisK) {
						case 0: {
							if (nextK <= 1)	{
								move = 1;
							}
							else if (nF!=0 && maze[nextR][nextC]==')') {
								move = 1;
								nF--; 
							}
							else;
							break;
						}
						case 1: {
							if (nextK==0) {
								move = 1;
							}
							else if (maze[nextR][nextC]=='(') {
								move = 1;
								nF++;
							}
							else;
							break;
						}
						case 2: {
							if (maze[thisR][thisC]=='(') {
								if (nextK==0) {
									move = 1; 
								}
								else if(maze[nextR][nextC] == '(') {
									move = 1;
									nF++; 
								}
								else;
							}
							else {
								if (nextK==1) {
									move = 1;
									
								}
								else if(maze[nextR][nextC] == ')' && nF!=0) {
									move = 1;
									nF--; 
								}
								else;
							}
							break;
						}
					}
					if (move==1) {
						mark[nextR][nextC] = 1;
						thisD++;
						pushT.setAll(thisR,thisC,thisD,maze[thisR][thisC]);
						pushT.setKind();
						route.push(pushT);
						thisK = nextK;
						thisR = nextR;
						thisC = nextC;
						thisD = 0; 
					}
					else thisD++;
				}
				else thisD++;
				
			} while(thisD<4 && flag_F==0);
			if (maze[thisR][thisC]=='(') {
				nF--;
			}
			else if (maze[thisR][thisC]==')') {
				nF++;
			}
			else;
			mark[thisR][thisC]=0;
		}	
		if (flag_F==0) {
			cout<<"No"<<endl;
		}
	}
	system("pause");
	return 0;
}
void toPostfix(char *inFix, int n)
{
	stack<term> post;
	term output[n];
	int print=0;
	for (int i=0; i<n; i++) {
		output[i].setAll(-1,-1,0,inFix[i]);
		output[i].iniInstack();
		output[i].setPri();
	}
	for (int i=0; i<n; i++) {
		char inC;
		inC = output[i].getValue();
		if (inC>='1' && inC<='9') {
			cout << inC;
			print = 0;
		}
		else if (post.empty()) {
			post.push(output[i]);
			print = 1;
			if (inC!='(') {
				cout << ' ';
				print = 1;
			}
		}
		else if (inC == ')') {
			term get;
			get = post.top();
			while (get.getValue()!='(') {
				cout << " ";
				cout << get.getValue();
				post.pop();
				get = post.top();
			}
			post.pop(); 
		}
		else {
			int inP,outP;
			term top;
			outP = output[i].getPri();
			top = post.top();
			if (print==0) {
				print = 1;
				cout << ' ';
			}
			if (top.getValue()=='(') {
				top.setInStacK();
				top.setPri();
			}
			inP = top.getPri();
			while (inP>=outP && !post.empty()) {
				cout << top.getValue();
				cout << " ";
				post.pop();
				if (!post.empty()) {
					top = post.top();
					if (top.getValue()=='(') {
						top.setInStacK();
						top.setPri();
					}
				}
				inP = top.getPri();
				if (print==1) {
					print = 2;
				}
			}
			post.push(output[i]);
		}
	}
	while (!post.empty()) {
			term a;
			cout << " ";
			a = post.top();
			cout << a.getValue();
			post.pop();
	}
	cout <<endl;
	return;
}
