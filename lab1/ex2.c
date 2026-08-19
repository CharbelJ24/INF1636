#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int variavel = 1;

int main(void) {
    pid_t pid;
    int status;

    printf("[ANTES DO FORK] pid = %d, variavel = %d\n", getpid(), variavel);

    pid = fork();

    if (pid != 0) {/*pai*/
        waitpid(pid, &status, 0);

        printf("[PAI]  depois do waitpid(), variavel = %d\n", variavel);
    } else {/*filho*/

        variavel = 5;
        printf("[FILHO] variavel alterada para %d\n", variavel);

        exit(0);
    }

    return 0;
}