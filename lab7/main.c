#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){
	int file1=open(argv[1],O_RDONLY);
	if(file1==-1){
		printf("Opening error");
		exit(0);
	}
	int file2=open(argv[2],O_WRONLY | O_EXCL | O_CREAT,0600);
	if(file2==-1){
		printf("Opening file2 error");
		exit(0);
	}
	char buffer[1024];
	int size_r;
	while(size_r==read(file1,buffer,sizeof(buffer))>0){
		write(file2,buffer,size_r);
	}
	close(file1);
	close(file2);
	return 0;
}
