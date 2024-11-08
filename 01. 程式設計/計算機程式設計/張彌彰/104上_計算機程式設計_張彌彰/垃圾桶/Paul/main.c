#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
	int number;
	char name[NAME_LEN+1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts=0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
FILE *dump(void);
FILE *recover(void);

int main(void)
{
	FILE *fp;
	char code;
	for(;;)
	{
		printf("Enter operation code: ");
		scanf(" %c",&code);
		while(getchar()!='\n')
			;
		switch(code)
		{
			case 'i':
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'p':
				print();
				break;
			case 'q':
				fclose(fp);
				return 0;
			case 'd' :
				fp=dump();
				break;
			case 'r' :
				fp=recover();
				break;
			default : printf("Illegal code\n");
		}
		printf("\n");
	}
}

int find_part(int number)
{
	int i;
	for(i=0;i<num_parts;i++)
		if(inventory[i].number==number)
			return 0;
	return -1;
}

void insert(void)
{
	int part_number;

	if(num_parts== MAX_PARTS)
	{
		printf("Database is full; can't add more parts.\n");
		return ;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if(find_part(part_number)>=0)
	{
		printf("Part already exists.\n");
		return ;
	}

	inventory[num_parts].number=part_number;
	printf("Enter part number name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d",&inventory[num_parts].on_hand);
	num_parts++;
}

void search(void)
{
	int i,number;
	printf("Enter part number: ");
	scanf("%d",&number);
	i=find_part(number);
	if(i>=0)
	{
		printf("Part name: %s\n",inventory[i].name);
		printf("Quantity on hand: %d\n",inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d",&number);
	i=find_part(number);
	if(i>=0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d",&change);
		inventory[i].on_hand+=change;
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	int i;

	printf("Part Number   Part Name                 "
			"Quantity on hand\n");
	for (i=0;i<num_parts;i++)
		printf("%7d     %-25s%11d\n",inventory[i].number,inventory[i].name, inventory[i].on_hand);
}

FILE *dump()
{
	char filename[20];
	struct part *p= inventory;
	FILE *fp;

	printf("Enter name of output file: ");
	read_line( filename , 20 );
	fp=fopen(filename,"w");
	fwrite(p,sizeof(inventory[0]),num_parts,fp);
	
	return fp;
}

FILE *recover()
{
	char filename[20];
	FILE *fp;
	int i;
	struct part *p=inventory;

	printf("Enter name of input file: ");
	read_line(filename,20);
	fp=fopen(filename,"r");
	if(fp == NULL )printf("Can't open file\n");
	for(i=0;i<100;i++)
	fread(&inventory[i],sizeof(inventory[0]),1,fp);
	
	return fp;
}

