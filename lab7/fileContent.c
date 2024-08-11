#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *ptr1,*ptr2;
	char filename[20];
	int c;
	
	printf("Enter the filename for reading: \n");
	scanf("%s",filename);

	ptr1=fopen(filename,"r");
	if(ptr1==NULL){
		printf("Cannot open file for reading\n");
		exit(1);
	}

	printf("Enter the filename for writing: \n");
	scanf("%s",filename);

	ptr2=fopen(filename,"w");
		
	if(ptr2==NULL){
		printf("Cannot open file for writing\n");
		exit(1);
	}

	while((c=fgetc(ptr1))!=EOF){
		fputc(c,ptr2);
	}

	printf("Content copies to %s.\n",filename);

	fclose(ptr1);
	fclose(ptr2);
	return 0;;;
}
