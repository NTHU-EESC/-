#include <stdio.h>
char map[105][105]={'*'};
int ans=0;


void solve(int x,int y,int step)
{
	if(map[x][y]=='T')
	{
		ans=step;
	}
	else if(map[x][y]!='#' && map[x][y]!='T')
		return;
	else
	{
		map[x][y]='*';
		solve(x+1,y,step+1);
		solve(x-1,y,step+1);
		solve(x,y+1,step+1);
		solve(x,y-1,step+1);
	}
}

int main(void)
{
	int x,y,M,N;
	int i,j;
	scanf("%d %d", &M,&N);
	char ch;
	ch = getchar();
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%c", &map[i][j]);
			if(map[i][j]=='S')
			{
				x=i;
				y=j;
			}
		}
		ch = getchar();
	}
	map[x][y]='#';
	solve(x,y,0);
	if(ans) printf("yes %d\n",ans);
	else printf("no\n");
	return 0;
}
