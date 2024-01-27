
#ifndef SCHUTZW_LAB6_H
#define SCHUTZW_LAB6_H

#define _CRT_SECURE_NO_WARNINGS

// Included for functions printf and scanf
#include <stdio.h>

// Include for functions malloc and free
#include <stdlib.h>

// Include for function strlen
#include <string.h>

#define MAX 100 // Maximum length of a string
typedef struct
{   
    char symbol;
    double number;

} recordType;
typedef struct node
{   
    recordType record;
    struct node* pNext;

} nodeType;
typedef struct
{
	nodeType* pTop;

} stackType;
// Macros
#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH 80
#define STAR '*'
#define DASH '-'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Walter Schutz"
#define LAB "Lab 6"

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);
void OpenDataFiles(FILE ** pointer, char type[]);
void CloseDataFiles(FILE** pointer);
 
void Push(stackType * pData, nodeType * newElement);

nodeType* Pop(stackType* pData);
void CreateNode(nodeType* pNewNode, char symbol);
int ReturnPriority(char symbol);
int isEmpty(stackType stack);
int isDigit(char symbol);

#endif