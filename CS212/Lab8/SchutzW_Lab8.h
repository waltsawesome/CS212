#ifndef SCHUTZW_LAB8_H
#define SCHUTZW_LAB8_H

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
	int integer;

} recordType;

typedef struct nodeType
{
	recordType record;

	struct nodeType* pLeft;
	struct nodeType* pRight;

} node;
// Macros
#define TRUE 1
#define FALSE 0

#define SCREEN_WIDTH 80
#define STAR '*'
#define DASH '-'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Walter Schutz"
#define LAB "Lab 7"

// Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);
void OpenDataFiles(FILE ** pointer, char type[]);
void CloseDataFiles(FILE** pointer);



#endif