// C program to demonstrate working of wait()
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Forking to create a child process
    
    if (pid == 0) {
        // Child process block
        printf("Child pid = %d\n", getpid());
        exit(0);  // Terminate child
    } else if (pid > 0) {
        // Parent process block
        wait(NULL);  // Wait for the child process to terminate
        printf("Parent pid = %d\n", getpid());
    } else {
        // Fork failed
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}
