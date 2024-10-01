#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    char message[100];
    int fd;

    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_FILE, 0666) == -1) {
        perror("mkfifo");
    }

    // Open FIFO for writing
    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get a message to write to the FIFO
    printf("Enter message to send: ");
    fgets(message, sizeof(message), stdin);

    // Write message to FIFO
    write(fd, message, strlen(message) + 1);
    
    // Close the FIFO
    close(fd);
    
    return 0;
}
