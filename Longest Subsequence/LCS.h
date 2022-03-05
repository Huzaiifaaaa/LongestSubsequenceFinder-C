static char *string1;
static char *string2;
static int length1;
static int length2;
static int **matrix;
static int row = 0;
static int column = 0;


//LCSStart function
//Takes two strings
//called in LCS function
//returns nothing
static void LCSStart(char *s1, char *s2)
{
    string1 = s1;//assigning string
    string2 = s2;//assigning string
    length1 = strlen(string1);//getting length of first string
    length2 = strlen(string2);//getting length of second string

    if (length1 > row|| length2 > column)//if length of string1>row OR length of string2 >column
    {
        for (int i = 0; i < row; i++)
        {
            free(matrix[i]);//freeing memory
        }

        free(matrix);//freeing memory

        matrix = (int **)malloc(length1 * sizeof(int *));//dynamic memory allocation

        for (int i = 0; i < length1; i++)//looping length of string1 times
	    {
	        matrix[i] = (int *)malloc(length2 * sizeof(int));//creating 2D array
	    }

        row = length1;//assigning to row
        column = length2;//assigning to column
    }//end of if

    for (int i = 0; i < length1; i++)//looping length1 times
    {
        for (int j = 0; j < length2; j++)//looping length times
        {
            matrix[i][j] = -1;//initializing array with -1
        }
    }
}//end of function


//function LCSLength
//takes two integer values
//called in LCS function
//returns int i.e., length
static int LCSLength(int index1, int index2)
{
    if (index1 >= length1 || index2 >= length2)//if length1 < index1 OR length2 < index2
    {
        return 0;//returning
    }

    if (matrix[index1][index2] != -1)
    {
        return matrix[index1][index2];//returning
    }

    if (string1[index1] == string2[index2])//if equal
    {
        return matrix[index1][index2] = LCSLength(index1+1, index2+1) + 1;
    }
    else
    {
        int a = LCSLength(index1, index2+1);//getting length
        int b = LCSLength(index1+1, index2);//getting length
        return matrix[index1][index2] = a>=b?a:b;//returning
    }
}//end of function


//function to find the sequence
//takes nothing as argument
//called in LCS function
//returns the string
static char* LCSSequence()
{
    int i = 0;
    int j = 0;
    int index = 0;//declaring & initializing variable

    char *sequence = (char *)malloc(sizeof(char) * length1>=length2?length1:length2);//creating dynamic string

    while(i < length1 && j < length2)//looping till i < length1 & j < length2
    {
        if (string1[i] == string2[j])//if string[i]==string2[j]
        {
            sequence[index++] = string1[i];//assigning to third string
            i++;//incrementing
            j++;//incrementing
            continue;
        }

        if(i+1 == length1 || matrix[i][j] != matrix[i+1][j])
        {
            j++;//incrementing
        }
        else
        {
            i++;//incrementing
        }
    }//end of while

    sequence[index] = '\0';//storing new line character
    return sequence;//returning
}//end of function


//LCS Function
//Takes 3 arguments
//pointer to character strings
//called in main function
//returns int i.e., length of longest subsequence
static int LCS(char *s1, char *s2, char **longest_common_subsequence)
{
    if (s1 == NULL || s2 == NULL || strlen(s1) == 0 || strlen(s2) == 0)//checking the length of s1 & s2, if its zero return
    {
        return 0;//returning, if null
    }

    LCSStart(s1, s2);//calling initializer function,passing the strings
    int longestlength = LCSLength(0, 0);//getting length
    *longest_common_subsequence = LCSSequence();//getting longest sequence
    return longestlength;//returning longest sequence
}//end of function
