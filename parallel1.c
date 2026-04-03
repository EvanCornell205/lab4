#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ARRAY_SIZE 1000000
#define THREAD_NO 10
#define CHUNK (ARRAY_SIZE / THREAD_NO)

int sum = 0;

typedef struct {
    int *array;
    int size;
} thread_arg_t;

void *mythread(void *arg) {
    thread_arg_t *targ = (thread_arg_t *)arg;
    for (int i = 0; i < targ->size; i++) {
        sum += targ->array[i];
    }
    return NULL;
}

int main(){
    int num[THREAD_NO][CHUNK];

    srand(100);
    for(int i=0; i < THREAD_NO; i++){
        for(int j=0; j < CHUNK; j++){
            num[i][j] = rand() % 100;
        }
    }

    pthread_t p[THREAD_NO];
    thread_arg_t args[THREAD_NO];

    for (int i = 0; i < THREAD_NO; i++) {
        args[i].array = num[i];
        args[i].size  = CHUNK;
        pthread_create(&p[i], NULL, mythread, &args[i]);
    }

    for (int i = 0; i < THREAD_NO; i++) {
        pthread_join(p[i], NULL);
    }

    printf("sum = %d\n", sum);
    return 0;
}
