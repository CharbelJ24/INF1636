#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    printf("alo mundo (pid = %d)\n", getpid());
    exit(0);
}