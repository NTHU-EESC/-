/*EE231002 Lab11. Academic Competition
  104061212,Li-Yu Feng
  Date:2015/12/7
 */

#include<stdio.h>
#include<string.h>

struct STU {
	char fName[15];
	char lName[15];
	double math,sci,lit;
	double total;
};
struct STU list[100];

int *sort(double score[100]);			// To find Top5
void Print(int prize[5],double *grade);	// To print Top5

int main(void)
{
	int i,j;							//for subscription
	int prize[5]={0},*p=&prize[0];		//for storing Top5
	double temp[100],grade[5],*q=grade;	//temp:store raw score data
										//grade:store Top5's score

	while(getchar() != '\n');			//skip self-explaining title
	for(i=0;i<100;i++){
		scanf("%s",list[i].fName);
		scanf("%s",list[i].lName);
		scanf("%lg", &list[i].math);
		scanf("%lg", &list[i].sci);
		scanf("%lg", &list[i].lit);		
		list[i].total=list[i].math + list[i].sci + list[i].lit;
	}									//fill in list[100]

	printf("Grand Prize Winners:\n");
	for(i=0;i<100;i++)
		temp[i]=list[i].total;			//store raw data
	p=sort(temp);						//transfer data to sort function
	memcpy(prize,p,sizeof(prize));		//somehow I can't use pointer directly
	for( i=0 ; i<5 ; i++ ){				//so I copy the value to array instead
		grade[i]=list[ *(p+i) ].total;	//geanerate Top5 score
	}
	Print(prize,q);						//print name & score

	for(i=0;i<5;i++){					//reset grand prize winners' score
		list[ prize[i] ].math=0;		//,then they won't get any other prizes
		list[ prize[i] ].sci=0;			//
		list[ prize[i] ].lit=0;			//
	}
	/*	By the same token as above*/
	printf("Math Prize Winners:\n");
	for(i=0;i<100;i++)
		temp[i]=list[i].math;
	p=sort(temp);
	memcpy(prize,p,sizeof(prize));
	for( i=0 ; i<5 ; i++ ){
		grade[i]=list[ *(p+i) ].math;
	}
	Print(prize,q);

	printf("Science Prize Winners:\n");
	for(i=0;i<100;i++)
		temp[i]=list[i].sci;
	p=sort(temp);
	memcpy(prize,p,sizeof(prize));
	for( i=0 ; i<5 ; i++ ){
		grade[i]=list[ *(p+i) ].sci;
	}
	Print(prize,q);
	

	printf("Literature Prize Winners:\n");
	for(i=0;i<100;i++)
		temp[i]=list[i].lit;
	p=sort(temp);
	memcpy(prize,p,sizeof(prize));
	for( i=0 ; i<5 ; i++ ){
		grade[i]=list[ *(p+i) ].lit;
	}
	Print(prize,q);

	return 0;
}

int *sort(double score[100])
{
	int i,j,m,winner[5]={0},*p=winner;		//i,j,m for subscription
											//winner to return Top5
	for(i=1;i<100;i++){						//initialize Top5 to be 0 (1st stu)
		for(j=0;j<5;j++){
			if( score[i] >score[ winner[j] ] ){//score >top5
				m=3;
				while(m >= j){					//
					winner[m+1]=winner[m];		//
					m--;						//Losers,step back!
				}
				winner[j]=i;					//replace loser
				j=5;							//terminate loop 2
			}
		}
	}

	return p;									//Top 5s' ID number
}

void Print(int prize[5],double *grade)
{
	int i;

	for(i=0;i<5;i++)
		printf("  %d:%10s%11s %5lg\n",i+1,list[ prize[i] ].fName,																		   list[ prize[i] ].lName , *(grade+i) );
}
