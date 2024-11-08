#include <stdio.h>
int q[8] = {0};			//EX: q[2] = 3 -->��ܲ�2��row���Ѥl��b��3��col
int board[8][8] ;		//�]���h����ƥB�|�Q��L��ƨϥΡA�ҥH�ŧi�������ܼ�
int MAX = 0;			//�����@�����ꪺ�̤j�`�M
int temp = 0;			//�Ȧs�@�����ꤤ�@���\�k���`�M
int arr[8][8] = {{0}};	//��@�����ꪺ���Ω�barr[8][8]���ѽL�W�A��J1(��)�M0(�L)�A���board�M�����ۥ[����

int valid(int row , int col);	//�p�G�i��m�^�ǭ�=1�A���i��m�^�ǭ�=0
void place(int row);			//��m�Ѥl
void find(void);				//�M���`�M���̤j��

int main()
{
	int N , i , j ,k ;

	scanf("%d",&N);

	for(k = 0 ; k < N ; k++){
		for(i = 0 ; i < 8 ; i++)
			for ( j = 0; j < 8; j++)
				scanf("%d",&board[i][j]);
		place(0);
		printf("%d\n",MAX);
		MAX = temp = 0;	//�n���s����l�ȡA�_�h�Y���h����ơA�ᶵMAX�Y��e���p�h���|�Q�s�i�h
	}

	return 0;
}
int valid(int row , int col){
	int i ;
	//�p�G�Prow�B�Pcol�B�P�﨤�u���Ѥl�N�^��0
	//   q[i]  == col 		 --> �P�@���
	// row - i == col - q[i] --> �b�P�׽u�W
	// row - i == q[i] - col --> �b�P�׽u�W
	// row - i == col - q[i] == q[i] - col  == 0  �N���N��O�b�﨤�u�W(�]���O����Ϊ��x�})
	//���ݭn�P�O�Prow�����ΡA�]���b��m�Ѥl���ɭԴN�w�g�O��row��F
	for(i = 0 ; i <= row-1 ; i++)
		if(q[i] == col || row-i == col-q[i] || row-i == q[i]-col)
			return 0;

	return 1;
}
void place(int row){
	int j = 0;
	//�p�G�\�Ѥl��F�̫�@��N�h���`�M
	//�o�̪��g�k�O�C�Ƨ��@�إi��N�h�⨺�رƪk���`�M
	if(row == 8)
		find();
	else{
		for(j = 0 ; j < 8 ; j++)
			if(valid(row,j)){
				q[row] = j;		//�����ĴXrow���ĴX��col����Ѥl
				place(row+1);	//�����\�U�@row
			}
	}
}
void find(void){
	temp = 0;
	int i , j;
	//i,j�N��q�Y�}�l�˵��ѽL��row�Mcol
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 8 ; j++){
			if(q[i] == j)			//�p�G���b�ѽL��col������(��U�ƪk)����l���ܴN��L�[��temp��
				temp += board[i][j];
		}
	}
	//�p�G�o�@���\�k���`�M�����x�s��MAX�٤j�A�N��temp����assign��MAX
	MAX = temp > MAX ? temp : MAX;
}
