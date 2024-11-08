//a[3][3] is input, nu[3][3] is the numerator of output, de[3][3] is the denominator of input, div[3][3] is gcd of nu[3][3] and de[3][3]
#include <stdio.h>

int a[3][3]={0},nu[3][3]={0},de[3][3]={0},div[3][3]={0};
int i,j,det=0;
void show();
void simple();
int gcd(int x,int y);
int formula( int a,int b,int c,int d);
int main(void)
{
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
	int deta;
	deta=a[0][0]*a[1][1]*a[2][2]+a[0][2]*a[1][0]*a[2][1]+a[0][1]*a[1][2]*a[2][0]-a[1][1]*a[0][2]*a[2][0]-a[1][0]*a[0][1]*a[2][2]-a[0][0]*a[2][1]*a[1][2];
	for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            de[i][j]=deta;
        }
    }
	nu[0][0]=formula(a[1][1],a[1][2],a[2][1],a[2][2]);
	nu[0][1]=-formula(a[0][1],a[0][2],a[2][1],a[2][2]);
	nu[0][2]=formula(a[0][1],a[0][2],a[1][1],a[1][2]);
	nu[1][0]=-formula(a[1][0],a[1][2],a[2][0],a[2][2]);
	nu[1][1]=formula(a[0][0],a[0][2],a[2][0],a[2][2]);
	nu[1][2]=-formula(a[0][0],a[0][2],a[1][0],a[1][2]);
	nu[2][0]=formula(a[1][0],a[1][1],a[2][0],a[2][1]);
	nu[2][1]=-formula(a[0][0],a[0][1],a[2][0],a[2][1]);
	nu[2][2]=formula(a[0][0],a[0][1],a[1][0],a[1][1]);
    simple();
    show();

    return 0;
}

void show(){
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%4d",nu[i][j]/div[i][j]);
        printf("\n --- --- ---\n");
        for(j=0;j<3;j++)
            printf("%4d",de[i][j]/div[i][j]);
        printf("\n\n");
    }
}

void simple(){
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(nu[i][j]!=0)
                if(de[i][j]>0)
                    div[i][j]=gcd(abs(nu[i][j]),abs(de[i][j]));
                else
                    div[i][j]=-gcd(abs(nu[i][j]),abs(de[i][j]));
            else{
                de[i][j]=0;
                div[i][j]=1;
            }
        }
    }
}

int gcd(int x,int y){
    if(x%y==0) return y;
    else
	return gcd(y,x%y);
}

int formula( int a,int b,int c,int d){
	int answer;
	answer=a*d-b*c;
	return answer;
}
