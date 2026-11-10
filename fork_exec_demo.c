// fork_exec_demo.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child: เปลี่ยนตัวเองให้กลายเป็นคำสั่ง "ls -l"
        printf("Child: about to run 'ls -l'\n");
        execlp("ls", "ls", "-l", NULL);

        // บรรทัดนี้จะไม่ถูกรัน ถ้า execlp สำเร็จ
        printf("This never prints if exec succeeded\n");
    } else {
        // Parent: รอ child ทำงานเสร็จ
        wait(NULL);
        printf("Parent: child process finished\n");
    }

    return 0;
}
