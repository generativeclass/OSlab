// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <sys/wait.h>

// int main() {
//     pid_t pid = fork();  // Fork a child process

//     if (pid == 0) {
//         // Child process
//         printf("Child process (PID: %d) is exiting\n", getpid());
//         exit(0);  // Child exits immediately
//     } else {
//         // Parent process sleeps without calling wait()
//         printf("Parent process (PID: %d) sleeping, child (PID: %d) becomes zombie\n", getpid(), pid);
//         sleep(5);  // During this time, the child will be a zombie
//         // Parent can later call wait() to clean up the zombie
//         wait(NULL);
//         printf("Parent process cleaned up child zombie process\n");
//     }

//     return 0;
// }
