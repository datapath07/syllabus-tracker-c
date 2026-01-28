#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fileopen.h"
#define MAX_LENGTH 50
#define LENGTH 20
#define LIMIT 10

//function prototypes

void view_syllabus();
void particular_topic_covered();
void topics_not_covered();
int file_open();

//global variables

FILE *fp;
int i,j;

struct subject
{
	
	
	char uname[MAX_LENGTH],topics[LIMIT][MAX_LENGTH],sdate[LIMIT][LENGTH],fdate[LIMIT][LENGTH];
	
	
}pps;

int main()
{
	int ch,flag=0;
	do{
		flag=0;
		printf("\n\n\n\n\n");
		printf("%-100s <<<MENU>>> \n\n\n"," ");
		printf("%-95s1.view syllabus\n"," ");
		printf("%-95s2.particular topic covered\n"," ");
		printf("%-95s3.topics not covered\n"," ");
		printf("%-95s4.Exit."," ");
		
			printf("\n%-95s>>>select one option: "," ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: view_syllabus();
				break;
				
				case 2: particular_topic_covered();
				break;
				
				case 3: topics_not_covered();
				break;
				
				case 4: return 0;
				//break;
				
				default: flag=1;
				printf("%-95sinvalid option!! "," ");
				break;
			}
			if(flag==1)
			printf("enter again");
			
			else
			{
			printf("\n\n%-95s>>>do you want to enter again yes(1) or no(0): "," ");
			scanf("%d",&ch);
			}
			if(ch==1)
			system("cls");
	}while(ch==1||flag==1);
}



void view_syllabus()
{	
	file_open();
	printf("\n\n%-90ssubject: PROGRAMMING FOR PROBLEM SOLVING\n\n"," ");
	printf("\n%-35s    ->%-28s->%-28s->%-28s->%-28s->%-28s\n"," ","unit 1:","unit 2:","unit 3:","unit 4:","unit 5:");
	printf("\n%-35s    "," ");
	
	
	
	for(i=0;i<5;i++)
	{
		fread(&pps,sizeof(struct subject),1,fp);
		printf("  %-28s",pps.uname);
	}
	printf("\n\n");
		

	for(i=0;i<10;i++)
	{
		rewind(fp);
		printf("%-35s%-2d "," ",i+1);
		for(j=0;j<5;j++)
		{
			fread(&pps,sizeof(struct subject),1,fp);
			printf("-> %-28s",pps.topics[i]);
		}
		printf("\n");
	}
	fclose(fp);
}



void particular_topic_covered()
{
	int ch=1,cond=1,flag=0;
	char temp[MAX_LENGTH];
	file_open();
	
	do{
		printf("\n\n%-95s1.INTRODUCTION TO C\n%-95s2.ARRAYS,STRINGS AND POINTERS\n%-95s3.PREPROCESSOR AND FILE HANDLING IN C\n%-95s4.FUNCTIONS AND DYNAMIC MEMORY ALLOCATION\n%-95s5.SEARCHING AND SORTING\n"," "," "," "," "," ");
		
		if(ch!=1)
			printf("\n%-95sinvalid input!! again \n"," ");
		
		printf("%-95s>>>select the unit: "," ");
		scanf("%d",&ch);
		
		if(ch>0&&ch<6)
		{
			ch--;
			
			rewind(fp);
			fseek(fp,ch*sizeof(struct subject),SEEK_CUR);
			fread(&pps,sizeof(struct subject),1,fp);
			printf("\n\n");
			for(i=0;i<10;i++)
			{
				printf("%-95s>>  %-20s\n"," ",pps.topics[i]);
			}
			i=0;
			
			do{		
				if(i==10)
				printf("%-95senter valid topic name,again "," ");
						
				printf("\n\n%-95s>>>select the topic: "," ");
				fflush(stdin);
				gets(temp);
				
				for(i=0;i<10;i++)
				{
					if(strcasecmp(temp,pps.topics[i])==0)
					{
						printf("%-95sfound %-20s\n"," ",temp);
						if(strlen(pps.sdate[i])==0 && strlen(pps.fdate[i])==0)
							printf("%-95sstatus:topic not covered...\n"," ");
						else if(strlen(pps.sdate[i])>0 && strlen(pps.fdate[i])==0)
						{
							printf("%-95sstarting date %-20s\n"," ",pps.sdate[i]);
							printf("%-95sstatus:ongoing topic\n"," ");
						}
						else
						{
							printf("%-95sstarting date-%-20s\n"," ",pps.sdate[i]);
							printf("%-95sfinishing date-%-20s\n"," ",pps.fdate[i]);
							printf("%-95sstatus: topic covered..\n"," ");
						}
							
							break;
					}
				}
			}while(i==10);
		
			printf("\n\n%-95s>>>do you want to check another topic: yes(1) or no(0): "," ");
			scanf("%d",&ch);
			
			if(ch==1)
			{
				system("cls");
			}
			flag=0;
		}
		else
		flag=1;
		
	}while(ch ==1||flag==1);
	fclose(fp);
}



void topics_not_covered()
{
	int ch,k,cond=0,flag=0;
	char temp[MAX_LENGTH];
	file_open();
	
	do{
		printf("\n\n%-95s1.INTRODUCTION TO C\n%-95s2.ARRAYS,STRINGS AND POINTERS\n%-95s3.PREPROCESSOR AND FILE HANDLING IN C\n%-95s4.FUNCTIONS AND DYNAMIC MEMORY ALLOCATION\n%-95s5.SEARCHING AND SORTING\n\n"," "," "," "," "," ");
		printf("%-95s>>>select the unit: "," ");
		scanf("%d",&ch);
		if(ch>0&&ch<6)
		{
			flag=0;
			ch--;
			rewind(fp);
			fseek(fp,ch*sizeof(struct subject),SEEK_CUR);
			fread(&pps,sizeof(struct subject),1,fp);
			k=ch;
			
			for(i=0;i<10;i++)
			{
				if(strlen(pps.sdate[i])==0)
				{
					if(strlen(pps.fdate[i])==0)
					printf("%-95s>>%-2d%-20s\n"," ",i+1,pps.topics[i]);
				}
			}
			do{
				
				printf("%-95s>>>enter a topic :"," ");
				fflush(stdin);
				fgets(temp, MAX_LENGTH, stdin);
				temp[strcspn(temp, "\n")] = 0;

				
				for(i=0;i<10;i++)
				{
					if(strcasecmp(temp,pps.topics[i])==0)
					{
						cond=4;
						printf("%-95sfound %-20s\n"," ",pps.topics[i]);
						printf("%-95sdid the topic start, yes(1) or no(0) : "," ");
						scanf("%d",&ch);
						if(ch==1)
						{
							ch=0;
							printf("%-95senter starting date in (dd/mm/yyyy) format: "," ");
							fflush(stdin);
							fgets(temp, MAX_LENGTH, stdin);
							temp[strcspn(pps.sdate[i], "\n")] = 0;

							printf("%-95sdid the topic end, yes(1) or no(0) : "," ");
							scanf("%d",&ch);
							if(ch==1)
							{
								printf("%-95senter finishing date in (dd/mm/yyyy) format: "," ");
								fflush(stdin);
								fgets(temp, MAX_LENGTH, stdin);
								temp[strcspn(pps.fdate[i], "\n")] = 0;
								
							}
						}
							rewind(fp);
							fseek(fp,k*sizeof(struct subject),SEEK_CUR);
							fwrite(&pps,sizeof(struct subject),1,fp);
							break;
					}
				}
				
				if(cond!=4)
					printf("%-95sinvalid topic name, again\n"," ");
			}while(cond!=4);
			
			if(strlen(pps.sdate[i])>0)
				printf("%-95sstarting date %-20s\n"," ",pps.sdate[i]);
			if(strlen(pps.fdate[i])>0)
				printf("%-95sfinishing date %-20s\n"," ",pps.fdate[i]);
			
			printf("%-95supdated successfuly...\n"," ");
			
			fclose(fp);
			printf("\n\n%-95s>>>do you want to chack another topic yes(1) or no(0): "," ");
			scanf("%d",&ch);
			if(ch==1)
				system("cls");
		}
		else
		{
			flag=1;
			printf("\n\n%-95sinvalid input!! again \n"," ");		
		}

			
	}while(ch==1||flag==1);
	fclose(fp);
}

