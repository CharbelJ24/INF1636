#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pid_t pid, meu_pid;
    int status;

    pid = fork();

    if (pid != 0) { /*pai*/
        meu_pid = getpid();
        printf("[PAI]  meu pid = %d\n", meu_pid);

        waitpid(pid, &status, 0);

        printf("[PAI] FIM\n");
    } else { /*filho*/
        meu_pid = getpid();
        printf("[FILHO] meu pid = %d\n", meu_pid);

        exit(0);
    }

    return 0;
}