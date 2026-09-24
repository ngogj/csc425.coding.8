#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: memory-user <megabytes>\n");
        exit(1);
    }

    int megabytes = atoi(argv[1]);
    long long bytes = (long long)megabytes * 1024 * 1024;

    char *buffer = (char *)malloc(bytes);
    if (buffer == NULL) {
        fprintf(stderr, "Error: malloc failed to allocate %d MB of memory.\n", megabytes);
        exit(1);
    }

    printf("Successfully allocated %d MB. Running infinite loop to touch memory...\n", megabytes);

    while (1) {
        for (long long i = 0; i < bytes; i++) {
            buffer[i] += 1;
        }
    }

    free(buffer);
    return 0;
}