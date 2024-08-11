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
