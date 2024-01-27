/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Recursive Functions Lab 7
| Date:             April 22, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|     This program will use the following functions for processing output data files:
|    fopen   : opens an input or output file
|    fgets  :  read a line of a file as string
|    fgetc :  read data from the input file
|    fprintf : print to output file
|    fclose  : close file
|	 malloc : allocate node memory
|	 free : free allocated memory
|
|   The program will fulfill following tasks:
|     create a two queues
|     Use the queues to store nodes with customer data
|     Print the customer outcome from queue and empty the queue
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Data will be taken from input file and put in the happy queue or angry queue
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   Customer information is stored in the queue
|   Malloc is used to reserve memory, and free will free the memory at the end
|	Each queue has its own output file
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The customer ID's and feelings are printed to output files. One file for the angry customers 
|	and another for happy ones.
|--------------------------------------------------------------------------------------------------
*/

#include "SchutzW_Lab7.h"
int main(void)
{
	//Initialize Queue
	queueType angryQueue;
	queueType happyQueue;
	
	happyQueue.pFront = NULL;
	happyQueue.pRear = NULL;

	angryQueue.pFront = NULL;
	angryQueue.pRear = NULL;

	// Create node pointer for new record
	nodeType * pTemp = NULL;

	//Create file pointers

	FILE* pFin = NULL;
	FILE* pFoutHappy = NULL;
	FILE* pFoutAngry = NULL;

	// Open Files
	OpenDataFiles(&pFin, "r");
	OpenDataFiles(&pFoutHappy, "w");
	OpenDataFiles(&pFoutAngry, "w");
	//Print header
	PrintHeader(pFoutHappy);
	PrintHeader(pFoutAngry);
	// Declare variables
	char fileString[MAX];
	unsigned fileCode;
	//File processing loop
	if ((pFin != NULL)){
		while(!feof(pFin))
		{
			fgets(fileString, MAX, pFin);	
			fileCode= atoi(fileString);
			pTemp = (nodeType*) malloc(sizeof(nodeType));
			CreateNodeNode(pTemp,fileCode);
			EnqueueNewNode(&happyQueue,&angryQueue, pTemp, fileCode);

		}
	}
	//Print to output files
	PrintTableHeader(pFoutHappy);
	PrintTableHeader(pFoutAngry);
	while (angryQueue.pFront!=NULL){
		pTemp = angryQueue.pFront;
		PrintRowOfData(pFoutAngry, pTemp);
		Dequeue(&angryQueue);
	}
	while (happyQueue.pFront!=NULL){
		pTemp = happyQueue.pFront;
		PrintRowOfData(pFoutHappy, pTemp);
		Dequeue(&happyQueue);
	}

	// Close Files
    CloseDataFiles(&pFin);
    CloseDataFiles(&pFoutHappy);
	CloseDataFiles(&pFoutAngry);

	return 0;
}
