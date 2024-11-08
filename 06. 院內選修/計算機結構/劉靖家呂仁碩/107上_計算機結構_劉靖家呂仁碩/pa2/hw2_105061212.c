#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void heapify_asm(int64_t nums[], int size);

void print_array(int64_t nums[], int len){
    for (int i = 0; i < len; ++i){
        printf("%lld ", nums[i]);
    }
    printf("\n");
}

int main(){
    int size = 0;
    int K = 0;
    int min = 0;
    int64_t *list = NULL;

    scanf("%d",&size);
    scanf("%d",&K);
    list = (int64_t*) malloc(sizeof(int64_t) * size);

    for(int i = 0; i < size; i++){
        scanf("%lld",&list[i]);
    }

    if(size<K) return -1;
    if(K<=0) return -1;

    while(K>0){
        heapify_asm(list,size);
	if(min==list[0]) K++;
	min = list[0];
	for(int j=0; j<size; j++){
	    list[j] = list[j+1];
	}
	K--;
	size--;
	if(size==0 && K!=0) return -1;
    }

    printf("%d\n",min);
    

    return 0;
}
