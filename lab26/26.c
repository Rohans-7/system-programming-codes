#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *executable = "./a.out";
    char *args[] = {executable, "Rohan", NULL};

    if (execvp(executable, args) == -1) {
        perror("Failed to execute");
        exit(1);
    }

    printf("Successful, so passed control to executable\n");

    return 0;
}

