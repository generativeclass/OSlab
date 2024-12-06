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
    
    char str1[80], str2[80];
    
    while (1) {
        // Open FIFO for reading
        fd = open(myfifo, O_RDONLY);
        
        // Read message from user1
        read(fd, str1, 80);
        printf("User1: %s\n", str1);
        close(fd);
        
        // Open FIFO for writing response
        fd = open(myfifo, O_WRONLY);
        
        // Input response message
        printf("You: ");
        fgets(str2, 80, stdin);
        
        // Write response to the FIFO
        write(fd, str2, strlen(str2) + 1);
        close(fd);
    }

    return 0;
}
