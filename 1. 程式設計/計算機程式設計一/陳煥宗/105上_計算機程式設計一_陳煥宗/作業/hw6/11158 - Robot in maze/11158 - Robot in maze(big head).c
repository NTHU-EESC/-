#include <stdio.h>
int main()
{
	int row , col , in_col;		//incol:第一次進去的行
	int i , j , flag , entry , total_entry , before_loop;	//before_loop:開始繞圈圈之前走的格子數
	char ch;
    char map[20][20];
    int map2[20][20] = {{0}};	//拿來存放那一格是第幾步用的

    //變數初始化，我一開始沒初始化就跑出奇怪的數字OAQ
	row = col = in_col = i = j = flag = entry = total_entry = before_loop = 0;

	scanf("%d%d%d",&row,&col,&in_col);
	ch = getchar();	//拿來吃掉換行字元免得被吃進去

	//初始化兩個陣列理的值
	for(i = 0 ; i < row+2 ; i++)
		for(j = 0 ; j < col+2 ; j++){
			map[i][j] = 'O';
			map2[i][j] = 0;
		}

	//輸入地圖
	//地圖從map[1][1]開始~map[row][col]
	for(i = 1 ; i <= row ; i++)
		for(j = 1; j <= col+1 ; j++)		//因為要判斷輸入的是不是'\n'會花費一次迴圈執行
			if( (ch = getchar())  != '\n' )	//所以讓j多跑一次來抵銷判斷'\n'的那次
				map[i][j] = ch;

	// // 測試用，印地圖看對不對
	// for(i = 0 ; i <= row+1 ; i++)
	// {
	// 	for(j = 0 ; j <= col+1 ; j++)
	// 		printf("%c",map[i][j]);
	// 	printf("\n");
	// }

	//設定進去的第一格
	//記得map是從[1][1]開始的
	i = 1;
	j = in_col;

	//進入迷宮囉OAQ
	//如果還沒走出迷宮就繼續執行
	while(map[i][j] != 'O' ){

		//printf("i = %d j = %d\n",i,j );	//用來檢查行經的row和col

		total_entry++ ;	//只要還沒出地圖，每走一次total_entry就++

		//如果到達走過的地點，就break，flag用來記錄最後output要怎麼印
		//如果這格不是0的話就代表開始繞圈圈了
		if(map2[i][j] != 0){
			entry = total_entry - map2[i][j];	//根據提示：循環路線長度=目前的entry減去這格的entry
			before_loop = map2[i][j]-1 ;	//進入繞圈圈前走的entry就是圈圈進去那一格的entry-1
			flag = 1;
			break;
		}

		map2[i][j] = total_entry;

		//判斷接下來要往哪走
		//如果要去的那格是外面就break以保留目前的colum資訊(也就是i)
		if(map[i][j] == 'S' && map[i+1][j] == 'O')
			break;
		else if(map[i][j] == 'W' && map[i][j-1] == 'O')
			break;
		else if(map[i][j] == 'N' && map[i-1][j] == 'O')
			break;
		else if(map[i][j] == 'E' && map[i][j+1] == 'O')
			break;
		//如果沒出去就更改位置
		else if(map[i][j] == 'S' )
			i++;
		else if(map[i][j] == 'W' )
			j--;
		else if(map[i][j] == 'N' )
			i--;
		else if(map[i][j] == 'E' )
			j++;
	}

	if(flag == 1)	//沒有走出迷宮
		printf("%d %d",before_loop,entry);
	else	//有走出迷宮
		printf("%d",total_entry );

	return 0;
}
