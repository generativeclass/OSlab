#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2], n;
    char buffer[100];
    pid_t p;
    
    pipe(fd);
    p = fork();
    
    if (p > 0) {  // Parent process
        printf("Enter a string: ");
        fgets(buffer, 100, stdin);  // Get user input
        n = write(fd[1], buffer, strlen(buffer));  // Write the input to the pipe
        printf("Parent writes %d bytes\n", n);
        close(fd[1]);  // Close the write end of the pipe
        wait(NULL);  // Wait for the child process
    } 
    else {  // Child process
        n = read(fd[0], buffer, 100);  // Read from the pipe
        write(1, buffer, n);  // Print the string
        printf("Child reads %d bytes\n", n);
        close(fd[0]);  // Close the read end of the pipe
    }
    
    return 0;
}
