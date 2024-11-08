/* EE231002 Lab12. Linked Lists
   104061212, Li-yu Feng
   Date:2015/12/14
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct factor {				//structure to store
	int prime;						//prime factors & corresponding powers
	int power;								
	struct factor *next;
} FACTOR;

FACTOR *factorize(int N);			//factorization
FACTOR *GCD(FACTOR *A, FACTOR *B);	//finding GCD
FACTOR *LCM(FACTOR *A, FACTOR *B);	//finding LCM
void write(FACTOR *A);				//print out result

int main(int argc,char *argv[])
{
	int A=atoi( argv[1] ),B=atoi( argv[2] );	//Ch26.2 string to int
	FACTOR *p,*q,*r;
	
	p=factorize(A);
	printf("A =");
	write(p);
	q=factorize(B);
	printf("B =");
	write(q);
	r=GCD(p,q);
	printf("GCD =");
	write(r);
	r=LCM(p,q);
	printf("LCM =");
	write(r);

	return 0;
}

FACTOR *factorize(int N)
{
	int i,newlist=0;				//newlist to call for new  node
	FACTOR *p,*q,*r;				//q to assign NULL for the last one's->next
									//r stores the first node's address
	p=malloc(sizeof(FACTOR));		//create node
	r=p;
	for( i = 2 ; N > 1 ; i++){
		while( N%i == 0){				//is factor
			if(newlist == 0)p->power=0;	//init power
			p->prime=i;
			p->power++;
			N /= i;
			newlist=1;					//call for node
		}
		if(newlist){					//new node
			q = p;
			p->next = malloc(sizeof(FACTOR));
			p = p->next;
			newlist=0;
		}
	}
	free(p);							//delete unused node
	q->next=NULL;
	return r;
}

FACTOR *GCD(FACTOR *A, FACTOR *B)
{
	FACTOR *p=A,*q=B,*GCD,*r;				//GCD:first node's address

	GCD=malloc( sizeof(FACTOR) );
	r=GCD;
	/**		Find Common Factors		**/
	do{
		if(p->prime < q->prime){			
			if(p->next != NULL)p=p->next;	//prevent segmentation fault
			else q=q->next;					
		}
		else if(q->prime < p->prime){
			if(q->next!= NULL)q=q->next;
			else p=p->next;
		}
		else {								//same factor
			r->prime = p->prime;			//put down factor & power
			r->power =(p->power >= q->power ? q->power : p->power);
			r->next = malloc(sizeof(FACTOR));	//
			r = r->next;						//new node
			if(p->next != NULL)p = p->next;
			if(q->next !=NULL)q = q->next;
		}
	}while(p->next != NULL || q->next != NULL);
	if(p->prime == q->prime) {					//Are the last factors the same?
		r->prime = p->prime;
		r->power =(p->power >= q->power ? q->power : p->power);
	}
	return GCD;
}

FACTOR *LCM(FACTOR *A, FACTOR *B)
{
	FACTOR *p=A,*q=B,*LCM,*r;	//LCM : first node's address
	int final;					//final :indicates how we escape from loop(p?q?)

	LCM=malloc(sizeof(FACTOR));
	r=LCM;
	while(p->next != NULL || q->next != NULL){
		if(p->prime < q->prime){					//record smaller one
			r->prime = p->prime;
			r->power = p->power;
			while(p->next==NULL && q->next!= NULL){	//p reaches its end
				r->next=malloc(sizeof(FACTOR));		//
				r=r->next;							//
				r->prime = q->prime;				//
				r->power = q->power;				//
				q=q->next;							//record remaining q
			}
			if(p->next != NULL)p = p->next;	//p haven't reach the end
			else final= 0;					//p reaches end , then q follows
		}

		else if(q->prime < p->prime){
			r->prime = q->prime;
			r->power = q->power;
			while(q->next ==NULL && p->next != NULL){
				r->next=malloc(sizeof(FACTOR));
				r=r->next;
				r->prime = p->prime;
				r->power = p->power;
				p=p->next;
			}
			if(q->next != NULL)q = q->next;
			else final= 1;
		}											//similar to upper case

		else{							//same factor
			r->prime = p->prime;		//pick bigger power		
			r->power=(p->power >= q->power ? p->power :q->power );
			while(p->next == NULL && q->next != NULL){	//p reaches its end
				r->next=malloc(sizeof(FACTOR));
				r = r->next;
				r->prime = q->prime;
				r->power = q->power;
				q = q->next;
				final = 0;				//deal with remaining q
			}
			while(q->next == NULL && p->next != NULL){	//q reaches its end
				r->next=malloc(sizeof(FACTOR));
				r = r->next;
				r->prime = p->prime;
				r->power = p->power;
				p = p->next;
				final= 1;				//deal with remaining p
			}
			if(p->next != NULL)p = p->next;	//end hasn't been reached
			if(q->next != NULL)q = q->next;	//
		}
		r->next=malloc(sizeof(FACTOR));	//
		r=r->next;						//new node
	}
	switch(final){									
		case 0 :r->prime=q->prime;										
				r->power =(p->power >= q->power ? p->power : q->power);break;
		case 1 :r->prime=q->prime;		
				r->power =(p->power >= q->power ? q->power : p->power);
												//record the last one....
	}
	return LCM;
}
void write(FACTOR *A)
{
	FACTOR *p=A;
	int product=1,i;

	for( ;p->next != NULL ;p=p->next){				//print factor(s) & power(s)
		printf(" %d",p->prime);						//
		if(p->power > 1)printf("^%d *",p->power);	//
		else printf(" *");							//
	}
	if(p->prime==0)printf(" 1 =");				//In case GCD = 1
	else {
		 printf(" %d",p->prime);
		 if(p->power > 1)printf("^%d =",p->power);	
		 else printf(" =");							
	}
	for( p = A ; p->next != NULL ;p = p->next)	//
		for(i = p->power ; i>0 ; i-- )			//
			product *= p->prime;				//
	for(i = p->power ; i>0 ; i-- )				//
		product *= p->prime;					//generate product through lists
	printf(" %d\n",product);					//print product
}
