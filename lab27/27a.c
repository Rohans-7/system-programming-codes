/*
====================================================================================================================================================================================
Name : 27a.c
Author : Rohan Sonawane
Description :Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
   printf("Output using execl system call.\n");
   if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
       perror("execl failed");
     exit(1);
   }


    return 0;
}

/*

rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ gcc 27a.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ ./a.out
Output using execl system call.
.:
total 296
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    287 Aug 30 00:08  27a.c
-rwxrwxr-x 1 rohan-sonawane rohan-sonawane  16088 Aug 30 00:08  a.out
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane 282119 Aug 25 23:00 'Pasted image.png'
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ 

*/
