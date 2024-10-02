#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
void createProcessTree(int level) {
    if (level > 0) {
        pid_t pid1 = fork();  // First child
        if (pid1 == 0) {
            printf("Child process (PID: %d, Parent PID: %d, Level: %d)\n", getpid(), getppid(), level);
            createProcessTree(level - 1);  // Create subtree for this child
            exit(0);  // Exit after creating subtree
        } 
        
        pid_t pid2 = fork();  // Second child
        if (pid2 == 0) {
            printf("Child process (PID: %d, Parent PID: %d, Level: %d)\n", getpid(), getppid(), level);
            createProcessTree(level - 1);  // Create subtree for this child
            exit(0);  // Exit after creating subtree
        }
        
        // Parent process waits for both children
        wait(NULL);  
        wait(NULL);
    }
}

int main() {
    printf("Main Process process (PID: %d)\n", getpid());

    // Start process tree creation from level 3 (root parent at level 3)
    createProcessTree(3);

    return 0;
}
