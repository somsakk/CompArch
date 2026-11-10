// race_demo.c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: about to run 'ls -l'\n");
        execlp("ls", "ls", "-l", NULL);
    } else {
        printf("Parent: not waiting\n");
    }

    return 0;
}
