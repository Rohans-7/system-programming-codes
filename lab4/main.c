#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	const char *file_add="/home/rohan-sonawane/SS hands on lab/lab4/test.txt";

	int fd=open(file_add,O_RDWR,O_EXCL);

	if(fd==-1){
		perror("open");
		return 1;

	}

	printf("File opened in read and write mode with fd: %d\n",fd);


	return 0;
}
