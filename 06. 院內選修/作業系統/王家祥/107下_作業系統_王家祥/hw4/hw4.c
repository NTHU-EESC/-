#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

enum {thinking, hungry, eating} state[5];  // current state

void init(void);  // initialize
void* philosophers(void* num);  // thread for each philosopher
void pickup_forks(int i);  // try to eat
void return_forks(int i);  // end of eating
void test(int i);  // test if he can eat

// mutex lock and condition variables to avoid deadlock
pthread_mutex_t mutex;
pthread_cond_t cond_var[5];

int main(void)
{
    int i;
    int number[5];
    pthread_t ph[5];  // philosopher thread

    init();  // initialize

    for (i = 0; i < 5; i++) {
        number[i] = i;
        pthread_create(&ph[i], NULL, philosophers, &number[i]);  // create thread
    }

    for (i = 0; i < 5; i++) {
        pthread_join(ph[i], NULL);  // end of thread
    }

    return 0;
}

void init(void)  // initialize
{
    int i;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < 5; i++) {
        state[i] = thinking;  // set the state to thinking
        pthread_cond_init(&cond_var[i], NULL);
    }
}

void* philosophers(void* num)  // philosopher thread
{
    int* iptr = (int*) num;  // philosopher number
    int sleep_time = (rand() % 3) + 1;  // random sleep time

    // thinking for random seconds
    printf("Philosopher %d is now THINKING for %d seconds\n", *iptr, sleep_time);
    sleep(sleep_time);

    pickup_forks(*iptr);  // try to eat

    // eating for random seconds
    sleep_time = (rand() % 3) + 1;
    sleep(sleep_time);

    return_forks(*iptr);  // end of eating

    pthread_exit(NULL);
}

void pickup_forks(int i)  // try to eat
{
    pthread_mutex_lock(&mutex);  // lock mutex

    // hungry, try to eat
    state[i] = hungry;
    printf("Philosopher %d is now HUNGRY and trying to pick up forks\n", i);

    test(i);  // test if he can eat

    if (state[i] != eating) {  // if can't eat
        // wait fot the signal
        printf("Philosopher %d can't pick up forks and start waiting\n", i);
        pthread_cond_wait(&cond_var[i], &mutex);
    }

    pthread_mutex_unlock(&mutex);  // unlock
}

void return_forks(int i)  // end of eating
{
    pthread_mutex_lock(&mutex);  // lock

    // neighbor number
    int neighbor1 = (i + 4) % 5;
    int neighbor2 = (i + 1) % 5;

    // resume to thinking
    state[i] = thinking;
    printf("Philosopher %d returns forks and then starts TESTING %d and %d\n", i, neighbor1, neighbor2);

    // test the neighbors
    test(neighbor1);
    test(neighbor2);

    pthread_mutex_unlock(&mutex);  // unlock
}

void test(int i)  // test if he can eat
{
    // if he is hungry and the neighbors are not eating
    if (state[(i + 4) % 5] != eating && state[(i + 1) % 5] != eating && state[i] == hungry) {
        state[i] = eating;  // start eating
        printf("Philosopher %d is now EATING\n", i);
        pthread_cond_signal(&cond_var[i]);  // resume the suspend thread
    }
}
