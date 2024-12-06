#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    
    // Create the FIFO (named pipe)
    mkfifo(myfifo, 0666);
    
    char arr1[80], arr2[80];
    
    while (1) {
        // Open FIFO for writing
        fd = open(myfifo, O_WRONLY);
        
        // Input message
        printf("You: ");
        fgets(arr2, 80, stdin);
        
        // Write the message to the FIFO
        write(fd, arr2, strlen(arr2) + 1);
        close(fd);
        
        // Open FIFO for reading response
        fd = open(myfifo, O_RDONLY);
        
        // Read response from user2
        read(fd, arr1, sizeof(arr1));
        printf("User2: %s\n", arr1);
        close(fd);
    }

    return 0;
}
