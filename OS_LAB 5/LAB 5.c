#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t x, y;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;

void *reader(void *param) {
    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y);
    sem_post(&x);

    printf("%d reader is inside\n", readercount);
    usleep(300000);  // Simulate reading

    sem_wait(&x);
    readercount--;
    if (readercount == 0)
        sem_post(&y);
    sem_post(&x);

    printf("%d Reader is leaving\n", readercount + 1);
    return NULL;
}

void *writer(void *param) {
    printf("Writer is trying to enter\n");
    sem_wait(&y);
    printf("Writer has entered\n");
    usleep(300000);  // Simulate writing
    printf("Writer is leaving\n");
    sem_post(&y);
    return NULL;
}

int main() {
    int n, i;
    printf("Enter the number of readers/writers: ");
    scanf("%d", &n);

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    for (i = 0; i < n; i++) {
        pthread_create(&readerthreads[i], NULL, reader, NULL);
        pthread_create(&writerthreads[i], NULL, writer, NULL);
    }

    for (i = 0; i < n; i++) {
        pthread_join(readerthreads[i], NULL);
        pthread_join(writerthreads[i], NULL);
    }

    sem_destroy(&x);
    sem_destroy(&y);

    return 0;
}
