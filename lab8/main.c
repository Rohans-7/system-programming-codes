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
