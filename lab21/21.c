/*
====================================================================================================================================================================================
Name : 21.c
Author : Rohan Sonawane
Description :
Write a program, call fork and print the parent and child process id.

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(){
	printf("The parent process pid is :%d\n",getpid());
	int f=fork();
	if(f==0){
		printf("We're in the child process wit pid:%d\n",getpid());
	}
	else if(f>0){
		printf("W're in the parent process with Child pid: %d and parent pid :%d\n",f,getppid());
	}
	else{
		printf("We're in the parent process but child was not created\n");
	}
	return 0;
}

/*
Output:
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab21$ ./a.out
The parent process pid is :15558
W're in the parent process with Child pid: 15559 and parent pid :15552
We're in the child process wit pid:15559
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab21$ 

*/
