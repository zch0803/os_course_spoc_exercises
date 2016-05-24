#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

sem_t mutex_AM;
sem_t mutex_BM;
sem_t mutex_A2B;
sem_t mutex_B2A;
sem_t print_lock;

// NKU A
// TJU B
// M

#define WORK_THREAD 5
void* work_A2B(void* param);
void* work_B2A(void* param);
int main(){
	pthread_t thread_A2B[WORK_THREAD], thread_B2A[WORK_THREAD];
	int id[WORK_THREAD];
	sem_init(&print_lock, 0, 1);
	sem_init(&mutex_A2B, 0, 1);
	sem_init(&mutex_B2A, 0, 1);
	if(sem_init(&mutex_AM, 0, 1) < 0 || sem_init(&mutex_BM, 0, 1) < 0){
		printf("init error\n");
		exit(1);
	}

	for(int i = 0; i < WORK_THREAD; i++){
		id[i] = i;
		pthread_create(&thread_A2B[i], NULL, &work_A2B, (void*)&id[i]);
		pthread_create(&thread_B2A[i], NULL, &work_B2A, (void*)&id[i]);
	}
	
	for(int i = 0; i < WORK_THREAD; i++){
		pthread_join(thread_A2B[i], NULL);
		pthread_join(thread_B2A[i], NULL);
	}
	sem_destroy(&mutex_AM);
	sem_destroy(&mutex_BM);
	return 0;
}


void print_road(){

	return;
	sem_wait(&print_lock);
	int semvalue1, semvalue2;
	sem_getvalue(&mutex_AM, &semvalue1);
	sem_getvalue(&mutex_BM, &semvalue2);
	printf("        road: A-%c-M-%c-B\n", semvalue1 <= 0 ? '*':'-', semvalue2 <= 0 ? '*':'-');
	sem_post(&print_lock);
}

void* work_A2B(void* param){
	usleep(rand() % 1000000);
	int i = *(int *) param;
	int semvalue;
	
	sem_wait(&mutex_A2B);	

	sem_wait(&mutex_AM);
	printf("thread %d AtoB: A-*->M--->B\n", i);
	print_road();
	usleep(rand() % 1000000);
	sem_post(&mutex_AM);

	printf("thread %d AtoB: at M\n", i);
	print_road();
	usleep(rand() % 1000000);

	sem_wait(&mutex_BM);
	printf("thread %d AtoB: A--->M-*->B\n", i);
	print_road();
	usleep(rand() % 1000000);
	sem_post(&mutex_BM);

	sem_post(&mutex_A2B);

	printf("thread %d AtoB: at B\n", i);
	print_road();
	return NULL; 
}

void* work_B2A(void* param){
	usleep(rand() % 1000000);
	int i = *(int *) param + WORK_THREAD;

	sem_wait(&mutex_B2A);

	sem_wait(&mutex_BM);
	printf("thread %d BtoA: A<---M<-*-B\n", i);
	print_road();
	usleep(rand() % 1000000);
	sem_post(&mutex_BM);

	printf("thread %d BtoA: at M\n", i);
	print_road();
	usleep(rand() % 1000000);

	sem_wait(&mutex_AM);
	printf("thread %d BtoA: A<-*-M<---B\n", i);
	print_road();
	usleep(rand() % 1000000);
	sem_post(&mutex_AM);

	sem_post(&mutex_B2A);

	printf("thread %d BtoA: at A\n", i);
	print_road();
}