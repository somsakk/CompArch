// fork_demo.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Before fork: PID = %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    } else if (pid == 0) {
        // นี่คือ child process
        printf("I am the CHILD, my PID = %d, my parent's PID = %d\n", getpid(), getppid());
    } else {
        // นี่คือ parent process
        printf("I am the PARENT, my PID = %d, my child's PID = %d\n", getpid(), pid);
        wait(NULL); // รอให้ child ทำงานเสร็จก่อน
    }

    printf("This line runs in BOTH processes, PID = %d\n", getpid());

    return 0;
}
