#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;
int compare_a   (const void *a, const void *b);
int compare_d   (const void *a, const void *b);
void sortGrade(Grade *gList, int n, char *order);
int main(){
	int n, i;
	char order[20];
	Grade gradeList[1000];
	//freopen("input", "r", stdin);
	scanf("%d%s", &n, order);
	for(i = 0; i < n; i++)
		scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,
		&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
	sortGrade(gradeList, n, order);
	for(i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,
		gradeList[i].Chinese, gradeList[i].English,
		gradeList[i].math, gradeList[i].science);
	return 0;
}
void sortGrade(Grade *gList, int n, char *order)
{
    int i, j;
    int num;
    for(i=0;i<n;i++) gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    if(order[0]=='a') qsort(gList, n, sizeof(Grade), compare_a);
    else if(order[0]=='d') qsort(gList, n, sizeof(Grade), compare_d);
}
int compare_a (const void *a, const void *b)
{
    const Grade *va = (const Grade *) a;
    const Grade *vb = (const Grade *) b;
    if((va->total)!=(vb->total)) return ((va->total)-(vb->total))/*-((vb->total)-(va->total))*/;
    else{
        if((va->Chinese)!=(vb->Chinese)) return ((va->Chinese)-(vb->Chinese))/*-((vb->Chinese)-(va->Chinese))*/;
        else{
            if((va->English)!=(vb->English)) return ((va->English)-(vb->English))/*-((vb->English)-(va->English))*/;
            else{
                if((va->math)!=(vb->math)) return ((va->math)-(vb->math))/*-((vb->math)-(va->math))*/;
                else{
                    if((va->science)!=(vb->science)) return ((va->science)-(vb->science))/*-((vb->science)-(va->science))*/;
                    else return ((va->ID)-(vb->ID))/*-((vb->ID)-(va->ID))*/;
                }
            }
        }
    }
}
int compare_d (const void *a, const void *b)
{
    const Grade *va = (const Grade *) a;
    const Grade *vb = (const Grade *) b;
    if((va->total)!=(vb->total)) return -((va->total)-(vb->total))+((vb->total)-(va->total));
    else{
        if((va->Chinese)!=(vb->Chinese)) return -((va->Chinese)-(vb->Chinese))+((vb->Chinese)-(va->Chinese));
        else{
            if((va->English)!=(vb->English)) return -((va->English)-(vb->English))+((vb->English)-(va->English));
            else{
                if((va->math)!=(vb->math)) return -((va->math)-(vb->math))+((vb->math)-(va->math));
                else{
                    if((va->science)!=(vb->science)) return -((va->science)-(vb->science))+((vb->science)-(va->science));
                    else return ((va->ID)-(vb->ID))-((vb->ID)-(va->ID));
                }
            }
        }
    }
}

