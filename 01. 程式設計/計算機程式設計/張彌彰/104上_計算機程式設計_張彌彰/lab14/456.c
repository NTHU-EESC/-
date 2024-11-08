/*EE231002 Lab14. Image Processing
  ID:104061212 Li-Yu,Feng
  Date:2015/12/28
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct sPIXEL { // a single pixel
	unsigned char r,g,b; // three color components
} PIXEL;

typedef struct sIMG { // an image of PPM style
	char header[3]; // header, either P3 or P6
	int W,H; // width and height of the image
	int level; // intensity level of each color component
	PIXEL **PX; // two-dimensional array for all the pixels
} IMG;

IMG *PPMin(char *inFile);
void *PPMout(IMG *p1,char *outFile);
IMG *PPMcvt(IMG *p1,IMG *ee,IMG *nthu);

int main(int argc,char *argv[])
{
	IMG *p1,*ee,*nthu;
	int i,j;

	p1 = PPMin(argv[1]);
	ee = PPMin(argv[2]);
	nthu = PPMin(argv[3]);
	PPMcvt(p1,ee,nthu);
	PPMout(p1,argv[4]);
	
	return 0;
}

IMG *PPMin(char *inFile)
{
	FILE *fin;
	int i,j;
	IMG *pic;

	pic = malloc(sizeof(IMG));
	fin = fopen(inFile,"r");
	fscanf(fin,"%s\n",pic->header);
	fscanf(fin,"%d %d\n",&pic->W , &pic->H);
	fscanf(fin,"%d\n",&pic->level);
	pic->PX = malloc( pic->W * sizeof(PIXEL *) );
	for(i=0; i < pic->W ; i++)
		pic->PX[i] = malloc(pic->H * sizeof(PIXEL));
	for(i=0;i < pic->H;i++)
		for(j=0; j < pic->W;j++){
				fscanf(fin,"%c",&(pic->PX[j][i]).r);
				fscanf(fin,"%c",&(pic->PX[j][i]).g);
				fscanf(fin,"%c",&(pic->PX[j][i]).b);
		}
	fclose(fin);
	return pic;

}

void *PPMout(IMG *p1,char *outFile)
{
	int i,j;
	FILE *fout;

	fout=fopen(outFile,"w");
	fprintf(fout,"%s\n",p1->header);
	fprintf(fout,"%d %d\n",p1->W,p1->H);
	fprintf(fout,"%d\n",p1->level);
	for(i=0;i < p1->H;i++)
		for(j=0; j < p1->W;j++){
			fprintf(fout,"%c",(p1->PX[j][i]).r);
			fprintf(fout,"%c",(p1->PX[j][i]).g);
			fprintf(fout,"%c",(p1->PX[j][i]).b);
	}
	fclose(fout);
}

IMG *PPMcvt(IMG *p1,IMG *ee,IMG *nthu)
{
	int i,j,Gray;

	for(i=0;i < p1->H;i++)
		for(j=0; j < p1->W;j++){
			Gray = p1->PX[j][i].r*0.2126 + p1->PX[j][i].g*0.7152 
				   + p1->PX[i][j].b*0.0722;
			p1->PX[j][i].r = Gray;
			p1->PX[j][i].g = Gray;
			p1->PX[j][i].b = Gray;
		}
	
	for(i=0 ; i < nthu->H;i++)
		for(j=0 ; j < nthu->W;j++)
			if(nthu->PX[i][j].r != 255 ){
			p1->PX[(p1->W-nthu->W)/2+j][(p1->H-nthu->H)/2+i].r =255;
			p1->PX[(p1->W-nthu->W)/2+j][(p1->H-nthu->H)/2+i].b =255;
			}
	for(i=0 ; i < ee->H;i++)
		for(j=0 ; j < ee->W;j++)
			if(ee->PX[j][i].r != 255 ){
				p1->PX[p1->W-ee->W+j][p1->H-ee->H+i].r =ee->PX[j][i].r;
				p1->PX[p1->W-ee->W+j][p1->H-ee->H+i].g =ee->PX[j][i].g;
				p1->PX[p1->W-ee->W+j][p1->H-ee->H+i].b =ee->PX[j][i].b;
			}

	return p1;
}

