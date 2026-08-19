#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 10
 
int vetor[TAM] = {7, 2, 9, 4, 1, 5, 3, 8, 6, 0};

void imprime_vetor(const char *rotulo) {
    printf("%s: ", rotulo);
    for (int i = 0; i < TAM; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}


void ordena_vetor(void) {
    int i, j, tmp;
    for (i = 0; i < TAM - 1; i++) {
        for (j = 0; j < TAM - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
            }
        }
    }
}


int main(void) {
    pid_t pid;
    int status;

    
    imprime_vetor("[ANTES DO FORK]  vetor (desordenado)");

    pid = fork();

    if (pid != 0) {/*pai*/
        waitpid(pid, &status, 0);

        imprime_vetor("[PAI]  vetor (desordenado)");
    } else {/*filho*/
        ordena_vetor();
        imprime_vetor("[FILHO]  vetor (ordenado)");

        exit(0);
    }

    return 0;
}