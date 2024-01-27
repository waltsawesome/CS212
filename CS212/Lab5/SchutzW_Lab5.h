
#ifndef SCHUTZW_LAB5_H
#define SCHUTZW_LAB5_H

#define _CRT_SECURE_NO_WARNINGS

// Included for functions printf and scanf
#include <stdio.h>

// Include for functions malloc and free
#include <stdlib.h>

// Include for function strlen
#include <string.h>

#define MAX 50 // Maximum length of a string
typedef struct
{   
	char Book_Title[MAX];
    char Book_Author[MAX];
    char Publisher[MAX];
    int YearPublished;
    char ISBN[MAX];
    double cost;

} recordType;

// Declare a node
typedef struct dataType
{
	recordType record;

	struct dataType* pNext;

} linkList;

// Macros
#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH 80
#define STAR '*'
#define DASH '-'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Walter Schutz"
#define LAB "Lab 5"

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);
void OpenFiles(FILE ** pointer, char message[], char type[]);
void CloseFiles(FILE** file1);

int IsEmpty(linkList* pList);
void ReadDataFromFile(FILE* pFin, linkList** pList);
void CreateNode(linkList* pNewNode, char Book_Title[], char Book_Author[], char Publisher[], int YearPublished, char ISBN[], double cost);
void AddNodeToList(linkList** pList, linkList* pNewNode);
void PrintList(FILE * pFout, linkList* pList, char listTitle []);
void PrintOneRecord(FILE * pFout, linkList* pTemp);
void FreeTheList(linkList** pList);

#endif