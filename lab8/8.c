/*
============================================================================
Name : 8.c
Author : Rohan Sonawane
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 11th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

const char EOL='\n';

int main(){
	FILE *fd=fopen("test.txt","r");
	if(fd==NULL){
		perror("program");
		exit(0);
	}
	int c=fgetc(fd);
	char buffer[1024];
	int k=0;
	while(c!=EOF){
		while(c!=EOL){
			buffer[k]=c;
			k++;
			c=fgetc(fd);
		}
		buffer[k++]='\n';
		write(1,buffer,k);
		
		c=fgetc(fd);
		k=0;
	}
	return 0;

}
/*
This is a temp file to print
line by line
all the lines
*/
