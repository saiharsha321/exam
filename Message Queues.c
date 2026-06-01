//Message Queues
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msgbuf message;

    if (fork() == 0) {
        // Child - receive
        msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);
        printf("Received: %s\n", message.mtext);
    } else {
        // Parent - send
        message.mtype = 1;
        strcpy(message.mtext, "Hello Message Queue");
        msgsnd(msgid, &message, sizeof(message.mtext), 0);
    }

    return 0;
}

