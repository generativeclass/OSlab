#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

struct msgbuff {
    long mtype;
    char mtext[100];
} mb;

int main() {
    key_t key;
    int msgid, c;

    // Generate a unique key
    key = ftok("progfile", 'A');

    // Access the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive the message from the queue (type 1)
    msgrcv(msgid, &mb, sizeof(mb.mtext), 1, 0);

    printf("Data Received is:\t%s\n", mb.mtext);

    // Destroy the message queue after use
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
