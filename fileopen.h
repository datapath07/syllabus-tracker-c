#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 50
#define LENGTH 20
#define LIMIT 10

FILE *fp;
 
int file_open()
{
	fp=fopen("PROJECT.bin","rb+");
	if(fp==NULL)
	{
		printf("unable to open the file..");
		return 0;
	}
	return 1;
}

