#include <stdio.h>
int q[8] = {0};			//EX: q[2] = 3 -->表示第2個row的棋子放在第3個col
int board[8][8] ;		//因有多筆資料且會被其他函數使用，所以宣告為全域變數
int MAX = 0;			//紀錄一筆測資的最大總和
int temp = 0;			//暫存一筆測資中一項擺法的總和
int arr[8][8] = {{0}};	//把一筆測資的情形放在arr[8][8]的棋盤上，放入1(有)和0(無)，對照board尋找應相加的數

int valid(int row , int col);	//如果可放置回傳值=1，不可放置回傳值=0
void place(int row);			//放置棋子
void find(void);				//尋找總和的最大值

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
		MAX = temp = 0;	//要重新給初始值，否則若有多筆資料，後項MAX若比前項小則不會被存進去
	}

	return 0;
}
int valid(int row , int col){
	int i ;
	//如果同row、同col、同對角線有棋子就回傳0
	//   q[i]  == col 		 --> 同一橫排
	// row - i == col - q[i] --> 在同斜線上
	// row - i == q[i] - col --> 在同斜線上
	// row - i == col - q[i] == q[i] - col  == 0  代表的意思是在對角線上(因為是正方形的矩陣)
	//不需要判別同row的情形，因為在放置棋子的時候就已經是換row放了
	for(i = 0 ; i <= row-1 ; i++)
		if(q[i] == col || row-i == col-q[i] || row-i == q[i]-col)
			return 0;

	return 1;
}
void place(int row){
	int j = 0;
	//如果擺棋子到了最後一行就去找總和
	//這裡的寫法是每排完一種可能就去算那種排法的總和
	if(row == 8)
		find();
	else{
		for(j = 0 ; j < 8 ; j++)
			if(valid(row,j)){
				q[row] = j;		//紀錄第幾row的第幾個col有放棋子
				place(row+1);	//接著擺下一row
			}
	}
}
void find(void){
	temp = 0;
	int i , j;
	//i,j代表從頭開始檢視棋盤的row和col
	for(i = 0 ; i < 8 ; i++){
		for(j = 0 ; j < 8 ; j++){
			if(q[i] == j)			//如果乾淨棋盤的col對應到(當下排法)有其子的話就把他加到temp裡
				temp += board[i][j];
		}
	}
	//如果這一種擺法的總和比原先儲存的MAX還大，就把temp的值assign給MAX
	MAX = temp > MAX ? temp : MAX;
}
