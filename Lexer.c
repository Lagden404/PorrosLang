#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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
int getFileLength(FILE *file);
int countTokens(char* fileAsString, char** tokenList);
struct tokenListElement* returnTokenizedArray(char* fileAsString, char** tokenList);
size_t getLongestStringLength(char** stringArray);
int countString (const char* string, const char* substring);

int main (int argc, char *argv[])
{

    int i;
    char* fileAsString;

    //creates variable for file and opens the file specified in the command line arguments
    FILE *file;
    file = fopen(argv[1], "r");

    //token dictionary array
    char* tokens[TOTALTOKENS] = {"(", ")", "[", "]", "+", "-", "*", "/", "^", "<", ">", "=", ">=", "<=", "!=", "==", "OR", "AND", "NOT", "input", "print", "if", "elseif", "else", "do", "true", "false", "define", "return", "\n", ";", " "};

    //struct tokenListElement tokenizedArray[];

    fileAsString = getFileAsString(file); 

//if (file == NULL)
//   {
//        //prints an error message if no file is given and exits the program
//       printf("Error loading file!");

//            exit(1);
//       }

    printf("%d", countTokens("(if (porros == true) do (i + 2))", tokens)); 
    fclose(file);

    return 0;
}

struct tokenListElement* returnTokenizedArray(char* fileAsString, char** tokenList)
{
    struct tokenListElement* tokenizedArray[countTokens(fileAsString, tokenList)];

}

int countTokens(char* fileAsString, char** tokenList)
{
    int count = 0;
    char list[2][3] = {"==", "="};


   // for(int i = 0; i < TOTALTOKENS; i++)
    //{
    //    strcpy(list[i], tokenList[i]);
    //}

    for (int i = 0; i < 2; i++) 
    {
        count += countString(fileAsString, list[i]);
    }

    //count += countString(fileAsString, tokenList[0]);
    
    
    return count;
}

int getFileLength(FILE *file)
{    

    size_t pos = ftell(file);
    fseek(file, 0, SEEK_END);
    size_t fileLength = ftell(file);
    fseek(file, pos, SEEK_SET);

    return fileLength;
}

char* getFileAsString(FILE *file)
{
    //copies file to a string
    char *fileAsString = malloc (sizeof (char) * (getFileLength(file)) );

    fread(fileAsString, (getFileLength(file)), 1 , file);

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

int countString (const char* string, const char* substring)
{
    int count = 0;
    const char *tmp = string;
    
    while (tmp = strstr(tmp, substring))
    {
        count ++;
        tmp += strlen(substring);
    }
    return count;
}