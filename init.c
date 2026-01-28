#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define LENGTH 20
#define LIMIT 10

struct subject
{
    char uname[MAX_LENGTH];
    char topics[LIMIT][MAX_LENGTH];
    char sdate[LIMIT][LENGTH];
    char fdate[LIMIT][LENGTH];
};

int main()
{
    FILE *fp = fopen("PROJECT.bin", "wb");
    if(fp == NULL)
    {
        printf("Cannot create file\n");
        return 1;
    }

    struct subject s;

    char units[5][MAX_LENGTH] = {
        "INTRODUCTION TO C",
        "ARRAYS, STRINGS AND POINTERS",
        "PREPROCESSOR AND FILE HANDLING",
        "FUNCTIONS AND DYNAMIC MEMORY",
        "SEARCHING AND SORTING"
    };

    char topics[5][LIMIT][MAX_LENGTH] = {
        {"C Basics","History of C","Tokens","Keywords","Identifiers","Constants","Data Types","Variables","Operators","Expressions"},
        {"Arrays","2D Arrays","Strings","String Functions","Pointers","Pointer Arithmetic","Array of Strings","Dynamic Arrays","Pointer to Pointer","Command Line Args"},
        {"Macros","Preprocessor Directives","File Open","File Close","File Read","File Write","Text Files","Binary Files","File Modes","EOF"},
        {"Functions","Call by Value","Call by Reference","Recursion","Malloc","Calloc","Realloc","Free","DMA Examples","Memory Leaks"},
        {"Linear Search","Binary Search","Bubble Sort","Selection Sort","Insertion Sort","Merge Sort","Quick Sort","Time Complexity","Space Complexity","Stability"}
    };
    int i=0,j=0;
    for(i=0;i<5;i++){
        memset(&s, 0, sizeof(s));
        strcpy(s.uname, units[i]);
        for(j=0;j<10;j++)
        {
            strcpy(s.topics[j], topics[i][j]);
            s.sdate[j][0] = '\0';
            s.fdate[j][0] = '\0';
        }
        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);
    printf("PROJECT.bin created successfully!\n");
    return 0;
}
