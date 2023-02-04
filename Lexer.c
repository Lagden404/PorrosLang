#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TOTALTOKENS 32

/*
types of tokens:
0 - separators
1 - operators
2 - spaces
3 - keyword
4 - special
5 - literals
*/
struct tokenListElement
{
    int type;
    char* token;
};

char *getFileAsString(FILE *file);
int getTokenType(char* token, char** list);

int main (int argc, char *argv[])
{

    int i;
    char* fileAsString;

    //creates variable for file and opens the file specified in the command line arguments
    FILE *file;
    file = fopen(argv[1], "r");

    //token dictionary array
    char* tokens[TOTALTOKENS] = {"(", ")", "[", "]", "+", "-", "*", "/", "^", "<", ">", "=", ">=", "<=", "!=", "==", "OR", "AND", "NOT", "input", "print", "if", "elseif", "else", "do", "true", "false", "define", "return", "\n", ";", " "};

    printf("%d\n", getTokenType("", tokens));

    fileAsString = getFileAsString(file);

    if (file == NULL)
        {
            //prints an error message if no file is given and exits the program
            printf("Error loading file!");

            exit(1);
        }


    fclose(file);

    return 0;
}

int countTokens (FILE *file)
{
    int numTokens = 0;

    /* while (c != EOF)
        {
            if ()
        }

    */

    return numTokens;
}

char* getFileAsString(FILE *file)
{
    //copies file to a string

    size_t pos = ftell(file);
    fseek(file, 0, SEEK_END);
    size_t fileLength = ftell(file);
    fseek(file, pos, SEEK_SET);

    char *fileAsString = malloc (sizeof (char) * fileLength);

    fread(fileAsString, fileLength, 1, file);

    return fileAsString;

};

int getTokenType(char* token, char** tokenList)
{
    int i, indexOnTokenList, comparisonCondition;

    for (i = 0; i < TOTALTOKENS; i++)
    {
        comparisonCondition = (strcmp (token, tokenList[i]));
        
        if ((comparisonCondition) == 0)
        {
            indexOnTokenList = i;
            break;
        }
    }

    if (i >= 0 && i <= 3) return 0;
    else if (i >= 4 && i <= 18) return 1;
    else if (i == 31) return 2;
    else if (i >= 19 && i <= 28) return 3;
    else if (i == 29 || i == 30) return 4; 
    else return 5;

}
