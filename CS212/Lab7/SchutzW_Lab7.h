#ifndef SCHUTZW_LAB7_H
#define SCHUTZW_LAB7_H

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
	//
	// All the data that will be stored in one record
	// will be declared here. 
	//

	int ID;
    int reason_code;
    char message[MAX]; 

} recordType;

typedef struct Node
{
	// Declare a record
	recordType data;

	struct Node* pNext;

} nodeType;

typedef struct
{
	nodeType* pFront;
	nodeType* pRear;

} queueType;
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

void PrintTableHeader(FILE* pOutput);
void SetAngryMessage(nodeType * newMessage);
void SetHappyMessage(nodeType * newMessage);
void Dequeue(queueType * queue);
void EnqueueNewNode(queueType * happyQueue, queueType * angryQueue, nodeType * pNewNode, unsigned code);
void Enqueue(queueType * queue, nodeType * pNewNode);
void CreateNodeNode(nodeType * pNewNode, unsigned code);
int QueueIsEmpty(queueType * queue);
void PrintRowOfData(FILE * pFout, nodeType * pQueue);

#endif