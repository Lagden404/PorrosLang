#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TOTALTOKENS 31

/*
types of tokens:
0 - separators
1 - operators
2 - literals
3 - keyword
4 - special

*/
struct tokenListElement
{
    int type;
    char* token;
} tokenList[TOTALTOKENS];



const char *getFileAsString(FILE *file);
bool isAToken (char c, struct tokenListElement* tokenList);
int getTokenType(char* token, struct tokenListElement* tokenList);
bool compareTokenWithLists (char* token, char** list);


int main (int argc, char *argv[])
{

    int i;
    char c;

    //creates variable for file and opens the file specified in the command line arguments
    FILE *file;
    file = fopen(argv[1], "r");



    //dictionary of tokens
    //implement a better way to list tokens and their types
    tokenList[0].token = "(";
    tokenList[1].token = ")";

    tokenList[2].token = "+";
    tokenList[3].token = "-";
    tokenList[4].token = "*";
    tokenList[5].token = "/";

    //gets the token type and puts it in the tokenList type

    for (i = 0; i < TOTALTOKENS; i++)
    {
        tokenList[i].type = getTokenType(tokenList[i].token, tokenList);
    }


    for (i = 0; (c = getc(file)) != EOF; i++)
        {
            if (isAToken(c, tokenList)) {printf("is a token\n");
        }
        }





    //for (i = 0; i < TOTALTOKENS; i++) printf("%d %s\n", tokenList[i].type, tokenList[i].token);



    getFileAsString(file);




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

const char* getFileAsString(FILE *file)
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

bool isAToken (char c, struct tokenListElement* tokenList)
{
    //you have to compare as strings, not characters
    //or you can make a condition based on its first char
    int i;

    for (i = 0; i < TOTALTOKENS; i++)
        {
            if (c == tokenList[i].token[0])
                {
                    return true;
                }
        }

    return false;

}

int getTokenType(char* token, struct tokenListElement* tokenList)
{
    int i;
    //lists for token types

    char *separators[4] = {"(", ")", "[", "]"};
    char *operators[16] = {"+", "-", "*", "/", "^", "<", ">", "=", ">=", "<=", "!=", "==", "OR", "AND", "NOT"};
    //literals
    char *keywords[10] = {"input", "print", "if", "elseif", "else", "do", "true", "false", "define", "return"};
    char *specials[2] = {"\n", ";"};
    char *space[1] = {' '};

    //if (compareTokenWithLists(token, separators)) {return 0;} 
    //else if (compareTokenWithLists(token, operators)) {return 1;} 
    //else if (compareTokenWithLists(token, keywords)) {return 3;} 
    //else if (compareTokenWithLists(token, specials)) {return 4;} 
    //else if (compareTokenWithLists(token, space)) {return 5;}
    //else return 2;

}

bool compareTokenWithLists (char* token, char** list)
{
    int i;
    size_t listSize = sizeof(list) / sizeof(list[0]);
    bool isInList = false;

    for (i = 0; i < listSize; i++)
    {
        if (strcmp(token, list[i]) == 0) isInList = true;
    }

    //segmentation fault

    return isInList;

}