#include <stdio.h>
#include <stdlib.h>

typedef struct sPIXEL {		// a single pixel
	unsigned char r,g,b; 	// three color components
} PIXEL;

typedef struct sIMG {		// an image of PPM style
	char header[3];		// header, either P3 or P6
	int W,H;			// width and height of the image
	int level;			// intensity level of each color component
	PIXEL **PX;			// two-dimensional array for all pixels
} IMG;

IMG *PPMin(char *inFile); 				// read image
void *PPMout(IMG *p1,char *outFile);    //print image
IMG *PPMcvt(IMG *p1,IMG *ee,IMG *nthu); //compose image

int main(int argc,char *argv[])
{	
	IMG *pic1, *ee, *nthu, *out;
	pic1 = PPMin(argv[1]);	// read background photo
	ee = PPMin(argv[2]);	// read ee photo
	nthu = PPMin(argv[3]);	// read nthu photo
	out = PPMcvt(pic1, ee, nthu);	// compose image
	PPMout(out, argv[4]);	// print finished image

	return 0;				
} 

IMG *PPMin(char *inFile)
{
	IMG *pic = (IMG*)malloc(sizeof(IMG));	// malloc a IMG size to store info
	FILE *fin;								// fin = input file
	int i, j;								// loops
	
	fin = fopen(inFile, "r"); 			// open file, read mode
	fscanf(fin, "%s", pic->header);		// read header
	fscanf(fin, "%d %d\n%d\n", &pic->W, &pic->H, &pic->level);
										// read width, height and level
	// prepare PX
	pic->PX = (PIXEL**)malloc(pic->W * sizeof(PIXEL*));  // malloc a W * pixel* size
	for (i = 0; i < pic->W; i++)	{
		pic->PX[i] = malloc(pic->H * sizeof(PIXEL));	
	}	// now we have a two dimensional array of pixels
	
	for(j = 0; j < pic->H; j++){			// store pixels
		for(i = 0; i < pic->W; i++){		// store in column major fashion		
			pic->PX[i][j].r=fgetc(fin);	 	// get pixel
			pic->PX[i][j].g=fgetc(fin);	 
			pic->PX[i][j].b=fgetc(fin);	 
		}
	}
	fclose(fin);	// close file
	return pic;		// return IMG pointer
}

void *PPMout(IMG *p1,char *outFile)
{
	FILE *fout;	// fout = output file
	int i, j;	// loops
	
	fout = fopen(outFile, "w");					// open file, write mode
	fprintf(fout, "%s\n", p1->header);    		// header
    fprintf(fout,"%d %d\n", p1->W, p1->H);  	// width and height
    fprintf(fout, "%d\n", p1->level);       	// color level
    for(j = 0; j < p1->H; j++){               	// pixel
    	for(i = 0; i < p1->W; i++){				// first store W then store H
            fprintf(fout,"%c",p1->PX[i][j].r);	// in column major fashion
			fprintf(fout,"%c",p1->PX[i][j].g);
			fprintf(fout,"%c",p1->PX[i][j].b);
       	}
   	}
   	fclose(fout);	// close file
   	return NULL;	
}

IMG *PPMcvt(IMG *p1,IMG *ee,IMG *nthu)
{
	int i, j;
	double gray;					// i j = loops, gray = gray color
	int nthuH, nthuW, eeH, eeW;		// store location for each small photos
	
	// find location for each small photos
	nthuH = (p1->H - nthu->H) / 2 + 1;
	nthuW = (p1->W - nthu->W) / 2 + 1;
	eeH = p1->H - ee->H;
	eeW = p1->W - ee->W;
	
	// set color to gray
	for(j = 0; j < p1->H; j++) {
        for (i = 0; i < p1->W; i++) {
        	gray = p1->PX[i][j].r * 0.2126 + p1->PX[i][j].g * 0.7152 + 
			p1->PX[i][j].b * 0.0722;
            p1->PX[i][j].r = gray;
            p1->PX[i][j].g = gray;
            p1->PX[i][j].b = gray;
        }
	}
	
	// place NTHU logo
	for(i=0;i<nthu->H;i++){				// first W then H, in column major
		for(j=0;j<nthu->W;j++){	
 			// if NTHU logo is not white, set color to purple
            if (!(nthu->PX[j][i].r == 255 && nthu->PX[j][i].g == 255 
				&& nthu->PX[j][i].b == 255)) {
					p1->PX[(j+nthuW)][(i+nthuH)].r=255;
					p1->PX[(j+nthuW)][(i+nthuH)].b=255;
			}
		}
	}

	// place EE logo
	for(i=0;i<ee->H;i++){				
		for(j=0;j<ee->W;j++){
            // if EE logo is not white, set color to EE pixel color
            if (!(ee->PX[j][i].r == 255 
				&& ee->PX[j][i].g == 255 
				&& ee->PX[j][i].b == 255)) {
					// copy EE pixel color to p1
					p1->PX[(j+eeW)][(i+eeH)].r = ee->PX[j][i].r;
					p1->PX[(j+eeW)][(i+eeH)].g = ee->PX[j][i].g;
					p1->PX[(j+eeW)][(i+eeH)].b = ee->PX[j][i].b;		
			}
    	}
	}
	
	// add a box around my own picture
   for(j = 5154; j < 5456; j++){               	// W
    	for(i = 852; i < 1195; i++){			// H
			if (!(j > 5154+15 && j <5456-15 && i > 852+15 && i < 1195-15)) {
				p1->PX[j][i].r = 255;			// set box color to red
				p1->PX[j][i].g = 0;
				p1->PX[j][i].b = 0;
			}
		}
	}
	return p1;
}
