#include <stdio.h>
int Ea_a(int,int);
int Ea_b(int,int);

int main (void){
	int x,y,z,gcd,lcm,i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&x,&y,&z);
		gcd = Ea_b(Ea_b(x,y),z);
		x/=gcd;
		y/=gcd;
		z/=gcd;
		lcm = x*y*z/Ea_b(x,y)/Ea_b(x,z)/Ea_b(y,z)*gcd;
		printf("%d %d\n",gcd,lcm);
	}
	
	return 0;
}

int Ea_a(int a, int b){
	if(a%b==0)
		return b;
	return Ea_b(a%b,b);
}
int Ea_b(int a, int b){
	if(b%a==0)
		return a;
	return Ea_a(a,b%a);
}
