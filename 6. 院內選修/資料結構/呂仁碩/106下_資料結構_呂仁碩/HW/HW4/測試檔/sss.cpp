#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(void)
{
    int num = 15;
	char maze[num][num];
	//cout <<"1" <<endl << "9"<<endl << "9" <<endl;
	cout << num << endl;
	unsigned  t = (unsigned) time(NULL);
	srand(t);
	for (int i=0; i<num; i++) {
		for (int j=0; j<num; j++) {
			switch(rand()%10) {
				case 0: {
					maze[i][j]='1';
					break;
				}
				case 1: {
					maze[i][j]='2';
					break;
				}
				case 2: {
					maze[i][j]='3';
					break;
				}
				case 3: {
					maze[i][j]='4';
					break;
				}
				case 4: {
					maze[i][j]='5';
					break;
				}
				case 5: {
					maze[i][j]='6';
					break;
				}
				case 6: {
					maze[i][j]='7';
					break;
				}
				case 7: {
					maze[i][j]='8';
					break;
				}
				case 8: {
					maze[i][j]='9';
					break;
				}
				case 9: {
					maze[i][j]='0';
					break;
				}
			}
			if(i==j) maze[i][j]='0';
			cout << maze[i][j]<<' ';
		}
		cout << endl;
	}
	cout << "Show-path" << endl;
	system("pause");
	return 0;
}
