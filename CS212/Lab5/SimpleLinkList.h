
#ifndef SIMPLE_LINK_LIST_H
#define SIMPLE_LINK_LIST_H

#define _CRT_SECURE_NO_WARNINGS

// Included for functions printf and scanf
#include <stdio.h>

// Include for functions malloc and free
#include <stdlib.h>

// Include for function strlen
#include <string.h>

typedef struct
{
	int number;
	
} recordType; 

// Declare a node
typedef struct dataType
{
	recordType record;

	struct dataType * pNext;

} linkList;

#define SCREEN_WIDTH 80
#define STAR '*'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Prof. Foos"
#define LAB "Simple Link List"

void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

// Prototypes
void CreateList(linkList** pList);
void InsertNewNode(linkList** pList, linkList** pNewNode);
void CreateNode(linkList* pNewNode, int input);
void PrintList(linkList* pList);
void FreeTheList(linkList** pList);

#endif