#include<stdio.h>
#include<stdlib.h>

int main(){

	int Nplayers,Ntour;
	char **NameList;
	int i;
	char *temp1, *temp2;

	temp1 = malloc(sizeof(char *));
	temp2 = malloc(sizeof(char *));

	scanf("%d", &Nplayers);
	printf("%d\n",Nplayers );
	NameList = (char **)malloc(Nplayers * sizeof(char *));
	for (i = 0; i < Nplayers; ++i)
	{
		NameList[i] = malloc(sizeof(char *));
	}

	for (i = 0; i < Nplayers; ++i)
	{
		scanf("%s", NameList[i]);
		printf("i = %d ", i);
		printf("%s\n",NameList[i] );
	}
	for (i = 0; i < Nplayers; ++i)
	{
		printf("%s\n",NameList[i] );
	}

	scanf(" %d", &Ntour);
	//scanf(" %s", temp1);
	//Ntour = atoi(temp1);
	printf("%d\n",Ntour );

	for (i = 0; i < Ntour; ++i)
	{
		scanf("%s %s %s",temp1, temp2, temp2 );
		printf("%d : %s wins %s\n",i, temp1, temp2);
	}


	return 0;
}
