// EE231002 Lab14. Image Processing
// 111060023, 黃柏霖
// Date: 2022/12/31

#include <stdio.h>				// i/o header
#include <stdlib.h>				// memory control header

typedef struct sPIXEL {			// a single pixel
	unsigned char r, g, b;		// three color components
} PIXEL;

typedef struct sIMG {			// an image of PPM style
	char header[3];				// header, either P3 or P6
	int W, H;					// width and height of a image
	int level;					// intensity level of each color
	PIXEL **PX;					// two-dimensional array for all the pixels
} IMG;

IMG *PPMin(char *inFile);				// open the inFile
void PPMout(IMG *p1, char *outFile);	// write image p1 to file ourFile 
IMG *PPMcvt(IMG *p1, IMG *ee);			// change T-shirt color and put EE logo

int main(int argc, char **argv)
{
	IMG *p1, *ee;				// to store pic1 and  EE logo
	p1 = PPMin(argv[1]);		// get pic1
	ee = PPMin(argv[2]);		// get EE logo
	p1 = PPMcvt(p1, ee);		// get processed image
	PPMout(p1, argv[3]);		// output the result
	return 0;					// end of main function
}

// to open inFile, read the image data and return a PPM form image
// input: char inFile: the file to input
// return: IMG *pic: a pointer point to image in PPM form
IMG *PPMin(char *inFile)
{
	int i, j;					// loop index
	FILE *fin;					// file variable for inFile
	IMG *pic;					// image in PPM form
	
	pic = (IMG *) malloc(sizeof(IMG));		// get memory space for pic
	fin = fopen(inFile, "r");				// read in inFile to fin
	// get data from fin to pic
	fscanf(fin, "%s", pic->header);			
	fscanf(fin, "%d %d\n%d\n", &pic->W, &pic->H, &pic->level);
	// get memory space for pixels
	pic->PX = (PIXEL **)malloc(pic->W * sizeof(PIXEL *));
	for (i = 0; i < pic->W; i++) {
		pic->PX[i] = (PIXEL *)malloc(pic->H * sizeof(PIXEL));
	}
	// read in color information of pixels
	for (j = 0; j < pic->H; j++) {
		for (i = 0; i < pic->W; i++) {
			pic->PX[i][j].r = getc(fin);	// information of red 
			pic->PX[i][j].g = getc(fin);	// information of green
			pic->PX[i][j].b = getc(fin);	// information of blue
		}
	}
	fclose(fin);				// close file fin
	return pic;					// return pic
}

// to write the image pic in PPM form to the output file outFile
// input: IMG *pic: the image in PPM form
// 		  char *outFile: the output file
// return: no return
void PPMout(IMG *pic, char *outFile)
{
	int i, j;								// loop index 
	FILE *fout;								// file variable for outFile
	
	fout = fopen(outFile, "w");				// write outFile to fout
	// print data from pic to fout
	fprintf(fout, "%s \n%d %d\n%d\n", 
		pic->header, pic->W, pic->H, pic->level);
	// print information of pixels to fout
	for (j = 0; j < pic->H; j++) {
		for (i = 0; i < pic->W; i++) {
			fprintf(fout, "%c%c%c", 
					pic->PX[i][j].r, pic->PX[i][j].g, pic->PX[i][j].b);
		}
	}
	fclose(fout);							// close fout
}

// to put the image ee to the image p1, and change the T-shirt color of p1
// input: IMG *p1: the image in PPM form
// 		  IMF *ee: the image in PPM form
// return: IMG *p1, the image after processing
IMG* PPMcvt(IMG *p1, IMG *ee)
{
	int i, j;						// loop index
	int x_ini;						// the initial pixel to put ee
	int bar = 1;

	x_ini = (p1->W - ee->W) / 2;	// get x_ini
	// put in the ee logo without white background
	for (j = 0; j < ee->H; j++) {
		for (i = 0; i < ee->W; i++) {
			if (ee->PX[i][j].r != 255		// avoid copying white background
				&& ee->PX[i][j].g != 255
				&& ee->PX[i][j].b != 255) {
				p1->PX[x_ini + i][j] = ee->PX[i][j];
			}
		}
	}
	// change T-shirt color
	for (j = 450; j < 650; j++) {					// only change people
		for (i = 30; i < 1400; i++) {
			if (i % 5 == 0) bar *= -1;
			if (!(500 < i && i < 800 && j > 578)) {	// avoid changing "NTHU"
				if (p1->PX[i][j].r > 100			// make sure white enough
					&& p1->PX[i][j].g > 100 
					&& p1->PX[i][j].b > 100) {
					// since RGB for human faces are usually R > G > B, while
					// shirts' RGB are B > G > R. Thus, make sure R 
					// approximately equal to G and B and R isn't too strong can
					// find the white T-shirt 
					if (p1->PX[i][j].r - p1->PX[i][j].g <= 10 
						&& p1->PX[i][j].g - p1->PX[i][j].b <= 15
						&& p1->PX[i][j].r - p1->PX[i][j].b <= 15) {
						if (bar == 1) {
							p1->PX[i][j].r -= 100;
							p1->PX[i][j].g = 255;
							p1->PX[i][j].b = 0;
						}
						else {
							p1->PX[i][j].r = 255;
							p1->PX[i][j].g -= 100;		
							p1->PX[i][j].b = 0;
						}
					}
				}
			}
		}
	}
	return p1;										// return p1
}
