#include "main.h"

#define BUFFER_SIZE 1024

int main(void)
{
    char *buffer;
    size_t bufsize = BUFFER_SIZE;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while (1) {
        printf("#cisfun$ ");

        if (getline(&buffer, &bufsize, stdin) == -1) {
            if (feof(stdin)) {
                printf("\n");
                break;
            } else {
                perror("Error reading input");
                exit(1);
            }
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if (fork() == 0) {
            if (execlp(buffer, buffer, NULL) == -1) {
                printf("%s: command not found\n", buffer);
                exit(2);
            }
        } else {
            wait(NULL);
        }
    }

    free(buffer);
    return 0;
}

