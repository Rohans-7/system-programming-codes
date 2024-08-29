/*
============================================================================
Name : 3.c
Author : Rohan Sonawane
Description : Write a C, Ansi-style program to perform Record locking.
                       a. Implement write lock
Date: 11th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	const char *filename="test.txt";

	int fd=creat(filename,0666);

	if(fd==-1){
		perror("creat");
		return 1;
	}
	printf("File descriptor for file '%s' is %d\n",filename,fd);
	if(close(fd)==-1){
		perror("close");
		return 1;
	}
	return 0;
}

/*
Input: ./file_descriptor
Output: File descriptor for file 'test.txt' is 3
cd: ls
created file "test.txt"

  */
