#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/wait.h>
#define BUFFER_SIZE 5
int main() {
    int i;
    int *buffer = mmap(NULL, BUFFER_SIZE * sizeof(int),
PROT_READ | PROT_WRITE,
MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int *in = mmap(NULL, sizeof(int),
PROT_READ | PROT_WRITE,
 MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int *out = mmap(NULL, sizeof(int),
PROT_READ | PROT_WRITE,
MAP_SHARED | MAP_ANONYMOUS, -1, 0);          *in = 0;
 *out = 0;
    sem_t *empty = mmap(NULL, sizeof(sem_t),
                        PROT_READ | PROT_WRITE,
                     MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_t *full = mmap(NULL, sizeof(sem_t),
                       PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_t *mutex = mmap(NULL, sizeof(sem_t),
                        PROT_READ | PROT_WRITE,
                     MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  sem_init(empty, 1, BUFFER_SIZE); 
    sem_init(full, 1, 0);
    sem_init(mutex, 1, 1);
    if (fork() == 0) {
        for (i = 0; i < 10; i++) {
            sem_wait(empty);
            sem_wait(mutex);
            buffer[*in] = i;
            printf("Produced: %d\n", i);
            *in = (*in + 1) % BUFFER_SIZE;
            sem_post(mutex);
            sem_post(full);
            sleep(1); }
        exit(0); }
    if (fork() == 0) {
        for (i = 0; i < 10; i++) {
            sem_wait(full);
            sem_wait(mutex);
            int item = buffer[*out];
            printf("Consumed: %d\n", item);
            *out = (*out + 1) % BUFFER_SIZE;
            sem_post(mutex);
            sem_post(empty);
            sleep(2); }
        exit(0);  }
    wait(NULL);
    wait(NULL);
    sem_destroy(empty);
    sem_destroy(full);
    sem_destroy(mutex);
    return 0; }