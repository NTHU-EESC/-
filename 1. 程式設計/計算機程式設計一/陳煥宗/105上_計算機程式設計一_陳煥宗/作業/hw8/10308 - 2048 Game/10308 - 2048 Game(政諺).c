#include <stdio.h>
int map[4][4];
int counts[4];

void collapse(void){
    int i , j;

    for(j = 0 ; j < 4 ; j++)
		for(i = 3; i > 0 ; i--)
            if(map[i][j] == 0){
                map[i][j] = map[i-1][j];
            	map[i-1][j] = 0;
            }
}

void slide(void){
    int i , j , k;

    for(j = 0 ; j < 4 ; j++)
	    for(i = 3 ; i > 0 ; i--){
	    	if(map[i-1][j] == map[i][j]){
                map[i][j] *= 2;
                map[i-1][j] = 0;
            } 
        	for(k = 0 ; k < 3 ; k++)
	        	collapse();    
	    }
}

int main()
{
    int N , i , j;

    scanf("%d", &N);
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &map[i][j]);
 
    for(i = 0 ; i < 3 ; i++)
    	collapse();

    for(i = 0; i < N; i++)
        slide();

    for(i = 0 ; i < 4 ; i++)
        for(j = 0 ; j < 4 ; j++)
            if(map[i][j] == 0)
                counts[j]++;

    printf("%d %d %d %d \n",counts[0],counts[1],counts[2],counts[3]);  
    
    return 0;
}