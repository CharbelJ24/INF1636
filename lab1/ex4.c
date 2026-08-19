#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    int status;

    printf("[PAI] antes do fork(), pid = %d\n", getpid());

    pid = fork();

    if (pid != 0) {/*pai*/
        waitpid(pid, &status, 0);

        if (!WIFEXITED(status))
            printf("[PAI] o processo filho nao terminou corretamente!\n");

        printf("[PAI] filho (pid %d) terminou. Encerrando o pai.\n", pid);
    } else {/*filho*/
        char *argv[] = {"./alomundo", NULL};

        execv("./alomundo", argv);
        perror("execv");
        exit(1);
    }

    return 0;
}