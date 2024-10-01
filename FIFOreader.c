#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    char buffer[100];
    int fd;

    // Open FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read from the FIFO
    read(fd, buffer, sizeof(buffer));

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Close the FIFO
    close(fd);
    
    return 0;
}
