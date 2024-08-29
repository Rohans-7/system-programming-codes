/*
============================================================================
Name : 5.c
Author : Rohan Sonawane
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
Date: 11th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	for(int i=1; i<=5; ++i){
		char filename[20];
		snprintf(filename,sizeof(filename),"file%d.txt",i);
		int fd=open(filename,O_CREAT,O_WRONLY,O_TRUNC,0644);
		if(fd<0){
			perror("open");
			return 1;
		}
		close(fd);
	}
	for(;;){
		sleep(1);
	}

	return 0;
}

/*
Input: ls -l proc/pid/fd
Output: file files created 
lrwx------ 1 rohan-sonawane rohan-sonawane 64 Aug 29 21:30 0 -> /dev/pts/1
lrwx------ 1 rohan-sonawane rohan-sonawane 64 Aug 29 21:30 1 -> /dev/pts/1
lrwx------ 1 rohan-sonawane rohan-sonawane 64 Aug 29 21:30 2 -> /dev/pts/1
*/
