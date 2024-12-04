

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// int main() {
//     pid_t pid = fork();  // Fork a child process

//     if (pid == 0) {
//         // Child process
//         sleep(5);  // Child sleeps to ensure the parent exits first
//         printf("Orphan process (PID: %d), adopted by init (PPID: %d)\n", getpid(), getppid());
//         exit(0);
//     } else {
//         // Parent process
//         printf("Parent process (PID: %d) exiting\n", getpid());
//         exit(0);  // Parent exits, making the child an orphan
//     }

//     return 0;
// }
