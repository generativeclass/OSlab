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

    // Create message queue and return identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    mb.mtype = 1; // Message type

    printf("\nEnter a string: ");
    fgets(mb.mtext, sizeof(mb.mtext), stdin);  // Safe input method

    // Send message to the queue
    c = msgsnd(msgid, &mb, strlen(mb.mtext) + 1, 0);

    printf("Sender wrote the text:\t%s\n", mb.mtext);

    return 0;
}
