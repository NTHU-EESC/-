#include <stdio.h>
int main()
{
	int row , col , in_col;		//incol:�Ĥ@���i�h����
	int i , j , flag , entry , total_entry , before_loop;	//before_loop:�}�l¶��餧�e������l��
	char ch;
    char map[20][20];
    int map2[20][20] = {{0}};	//���Ӧs�񨺤@��O�ĴX�B�Ϊ�

    //�ܼƪ�l�ơA�ڤ@�}�l�S��l�ƴN�]�X�_�Ǫ��ƦrOAQ
	row = col = in_col = i = j = flag = entry = total_entry = before_loop = 0;

	scanf("%d%d%d",&row,&col,&in_col);
	ch = getchar();	//���ӦY������r���K�o�Q�Y�i�h

	//��l�ƨ�Ӱ}�C�z����
	for(i = 0 ; i < row+2 ; i++)
		for(j = 0 ; j < col+2 ; j++){
			map[i][j] = 'O';
			map2[i][j] = 0;
		}

	//��J�a��
	//�a�ϱqmap[1][1]�}�l~map[row][col]
	for(i = 1 ; i <= row ; i++)
		for(j = 1; j <= col+1 ; j++)		//�]���n�P�_��J���O���O'\n'�|��O�@���j�����
			if( (ch = getchar())  != '\n' )	//�ҥH��j�h�]�@���ө�P�P�_'\n'������
				map[i][j] = ch;

	// // ���եΡA�L�a�Ϭݹ藍��
	// for(i = 0 ; i <= row+1 ; i++)
	// {
	// 	for(j = 0 ; j <= col+1 ; j++)
	// 		printf("%c",map[i][j]);
	// 	printf("\n");
	// }

	//�]�w�i�h���Ĥ@��
	//�O�omap�O�q[1][1]�}�l��
	i = 1;
	j = in_col;

	//�i�J�g�c�oOAQ
	//�p�G�٨S���X�g�c�N�~�����
	while(map[i][j] != 'O' ){

		//printf("i = %d j = %d\n",i,j );	//�Ψ��ˬd��g��row�Mcol

		total_entry++ ;	//�u�n�٨S�X�a�ϡA�C���@��total_entry�N++

		//�p�G��F���L���a�I�A�Nbreak�Aflag�ΨӰO���̫�output�n���L
		//�p�G�o�椣�O0���ܴN�N��}�l¶���F
		if(map2[i][j] != 0){
			entry = total_entry - map2[i][j];	//�ھڴ��ܡG�`�����u����=�ثe��entry��h�o�檺entry
			before_loop = map2[i][j]-1 ;	//�i�J¶���e����entry�N�O���i�h���@�檺entry-1
			flag = 1;
			break;
		}

		map2[i][j] = total_entry;

		//�P�_���U�ӭn������
		//�p�G�n�h������O�~���Nbreak�H�O�d�ثe��colum��T(�]�N�Oi)
		if(map[i][j] == 'S' && map[i+1][j] == 'O')
			break;
		else if(map[i][j] == 'W' && map[i][j-1] == 'O')
			break;
		else if(map[i][j] == 'N' && map[i-1][j] == 'O')
			break;
		else if(map[i][j] == 'E' && map[i][j+1] == 'O')
			break;
		//�p�G�S�X�h�N����m
		else if(map[i][j] == 'S' )
			i++;
		else if(map[i][j] == 'W' )
			j--;
		else if(map[i][j] == 'N' )
			i--;
		else if(map[i][j] == 'E' )
			j++;
	}

	if(flag == 1)	//�S�����X�g�c
		printf("%d %d",before_loop,entry);
	else	//�����X�g�c
		printf("%d",total_entry );

	return 0;
}
