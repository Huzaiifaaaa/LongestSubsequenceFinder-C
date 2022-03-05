#include <stdio.h>
#include "LCS.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])//main function, execution starts here
{
    int count=0;
    char *subsequence;//declaring variables
    char firstfile[100];
    char secondfile[100];
    char firstdata[100];
    char seconddata[100];

    FILE *firstptr;
    FILE *secondptr;
    FILE *outputptr;

    char *data1="" ;//= "yesterday";
    char *data2="" ;//= "hesllo";

    do
    {
        printf("Enter Path To First File: ");//asking for path
        scanf("%s", firstfile);//getting input
        firstptr=fopen(firstfile,"rb");//opening file
    }
    while(firstptr==NULL);//looping till correct path is entered

    fscanf(firstptr,"%s",&firstdata);//reading file
    fclose(firstptr);//closing the first file

    do
    {
        printf("Enter Path To Second File: ");//asking for path
        scanf("%s", secondfile);//getting input
        secondptr=fopen(secondfile,"rb");//opening file
    }
    while(secondptr==NULL);//looping till correct path is entered

    fscanf(secondptr,"%s",&seconddata);//getting data
    fclose(secondptr);//closing the second file

    printf("\n");//new line
    printf("First File Data: %s\n", firstdata);//printing data from first file
    printf("Second File Data: %s\n", seconddata);//printing data from second file

    data1=&firstdata;
    data2=&seconddata;

    int length = LCS(data1, data2, &subsequence);//calling the function, passing the data strings

    printf("\n");//new line
    printf("Subsequence Is: %s\n", subsequence);//printing subsequence//printing the subsequence
    printf("\n");//new line

    outputptr=fopen("output","w");//opening file
    fprintf(outputptr,"%s\n",subsequence);//writing to the file
    fclose(outputptr);//closing the output file

    printf("Subsequence Saved In The File!");//printing message

    return 0;//returning zero
}//end of function
