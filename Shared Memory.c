//Shared Memory
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char*) shmat(shmid, NULL, 0);

    if (fork() == 0) {
        // Child reads
        sleep(1);
        printf("Child read: %s\n", str);
    } else {
        // Parent writes
        strcpy(str, "Hello Shared Memory");
        printf("Parent wrote data\n");
    }

    return 0;
}

