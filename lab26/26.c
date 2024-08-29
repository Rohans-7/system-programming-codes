/*
====================================================================================================================================================================================
Name : 26.c
Author : Rohan Sonawane
Description :Write a program to create an orphan process.

Date : 28th August 2024
===================================================================================================================================================================================
*/
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

/*
output:
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab26$ ./a.out rohan
Hello, rohan!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab26$ 

*/

