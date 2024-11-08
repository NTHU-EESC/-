#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLUE 1
#define MAX_FLOOR_NUM 20000
//#include "function.h"

typedef struct {
    char color;
    unsigned int size;
} Floor;

int compare(const void *a, const void *b);

int design(int floorNum, Floor floorArr[]);

int main() {
    int floorNum;
    int i;
    Floor floorArr[MAX_FLOOR_NUM];
    scanf("%d", &floorNum);
    for (i = 0; i < floorNum; i++) {
        scanf(" %c %d", &floorArr[i].color, &floorArr[i].size);
    }
    printf("%d", design(floorNum, floorArr));
    return 0;
}
// Modify the design function
int design(int floorNum, Floor floorArr[]) {
    int height, color, size;
    int idx;
    qsort(floorArr, floorNum, sizeof(Floor), compare);
    height = 0;
    color = (floorArr[0].color == 'B') ? 1 : 0;
    size = ((floorArr[0].size % 2) == 0) ? 0 : 1;
    for (idx = 0; idx < floorNum; idx++) {
        if (color == 1 && floorArr[idx].color == 'B') {
            if (size == 1 && (floorArr[idx].size % 2) == 1){
                height++;
                color = 0;
                size = 0;
            }
            else if (size == 0 && (floorArr[idx].size % 2) == 0){
                height++;
                color = 0;
                size = 1;
            }
        }
        else if (color == 0 && floorArr[idx].color == 'R') {
            if (size == 1 && (floorArr[idx].size % 2) == 1){
                height++;
                color = 1;
                size = 0;
            }
            else if (size == 0 && (floorArr[idx].size % 2) == 0){
                height++;
                color = 1;
                size = 1;
            }
        }
    }
    return height;
}
int compare(const void *a, const void *b) {
    const Floor *fa = (const Floor *) a;
    const Floor *fb = (const Floor *) b;
    return fa->size - fb->size;
}


