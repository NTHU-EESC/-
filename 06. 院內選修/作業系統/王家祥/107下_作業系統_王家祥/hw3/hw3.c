#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <signal.h>
#include <string.h>
#include <sys/time.h>

// array to store the information of subarray
typedef struct sArray{
	int low, mid, high;
} Array;

int arr[10050];
int arr_size = 0;

void* merge_sort1(void* arr_data);
void* merge_sort2(void* arr_data);
void* merge_thread(void* arr_data);
void mergesort(int low, int high);
void merge(int low, int high, int mid);
double GetTime(void);

int main(int argc, char* argv[])
{
	FILE* input, * output;
	char buff[200000];
	int buff_size = 0;
	char* line;
	int i;
	double time0, time1;
	pthread_t thread1, thread2, thread3;
	Array arr0, arr1, arr2;
	
	
	if (argc != 3) {  // format not correct
		printf("ERROR!\n");
		return -1;
	}
	else {  // open input and output files
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");
	}
	
	while ((buff[buff_size] = fgetc(input)) != EOF) {  // read input
		if (buff[buff_size] == '\n') {  // end of line
			line = buff;
			arr_size = 0;
			buff_size = 0;
			while (sscanf(line, " %d%n", &arr[arr_size], &buff_size) == 1) {  // convert strings to integers
				arr_size++;
				line += buff_size;
			}
			
			// set subarray range
			arr0.low = 0;
			arr0.high = arr_size - 1;
			arr0.mid = (arr0.low + arr0.high) / 2;
			arr1.low = 0;
			arr1.high = arr0.mid;
			arr1.mid = (arr1.low + arr1.high) / 2;
			arr2.low = arr0.mid + 1;
			arr2.high = arr_size - 1;
			arr2.mid = (arr2.low + arr2.high) / 2;

			time0 = GetTime();  // get current time
			
			// two threads for merge sort, one thread for merge them together
			pthread_create(&thread1, NULL, merge_sort1, &arr1);
			pthread_create(&thread2, NULL, merge_sort2, &arr2);
			
			pthread_join(thread1, NULL);
			pthread_join(thread2, NULL);
			
			pthread_create(&thread3, NULL, merge_thread, &arr0);
			pthread_join(thread3, NULL);
			
			time1 = GetTime();  // get current time
			printf("time: %e seconds\n", time1 - time0);
			
			for (i = 0; i < arr_size; i++) {  // output results
				fprintf(output, "%d ", arr[i]);
			}
			fprintf(output, "\n");
			
			buff_size = 0;
		}
		else buff_size++;
	}
	
	// close file
	fclose(input);
	fclose(output);
}

void* merge_sort1(void* arr_data)  // first thread for the former half
{	
	Array* a = arr_data;
	
	// merge sort
	if (a->low < a->high) {
		mergesort(a->low, a->mid);
		mergesort(a->mid + 1, a->high);
		merge(a->low, a->high, a->mid);
	}

	pthread_exit(NULL);
}

void* merge_sort2(void* arr_data)  // second thread for the latter half
{
	Array* a = arr_data;
	
	// merge sort
	if (a->low < a->high) {
		mergesort(a->low, a->mid);
		mergesort(a->mid + 1, a->high);
		merge(a->low, a->high, a->mid);
	}

	pthread_exit(NULL);
}

void* merge_thread(void* arr_data)  // merge two threads
{	
	Array* a = arr_data;

	merge(a->low, a->high, a->mid);  // merge them
	
	pthread_exit(NULL);
}

void mergesort(int low, int high)  // merge sort algorithm
{
	int mid;
	
	if (low < high) {
		mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, high, mid);
	}
}

void merge(int low, int high, int mid)  // merge to subarrays
{
	int h = low;
	int i = low;
	int j = mid + 1;
	int k;
	int* b = (int*)malloc(sizeof(int) * 10050);
	
	while (h <= mid && j <= high) {
		if (arr[h] < arr[j]) {
			b[i] = arr[h];
			h++;
		}
		else {
			b[i] = arr[j];
			j++;
		}
		i++;
	}
	
	if (h > mid) {
		for (k = j; k <= high; k++) {
			b[i] = arr[k];
			i++;
		}
	}
	else {
		for (k = h; k <= mid; k++) {
			b[i] = arr[k];
			i++;
		}
	}
	for (k = low; k <= high; k++) arr[k] = b[k];
	
	free(b);
}

double GetTime(void)  // get local time in seconds
{
    struct timeval tv;  // time interval structure

    gettimeofday(&tv, NULL);  // write local time into tv

	// return time with microsecond
    return tv.tv_sec + tv.tv_usec * 0.000001;
}