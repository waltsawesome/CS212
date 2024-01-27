/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Recursive Functions Lab 5
| Date:             March 13, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|     This program will use the following functions for processing output data files:
|    fopen   : opens an input or output file
|    fgets  :  read a line of a file as string
|    fscanf :  read data from input file
|    fprintf : print to output file
|    fclose  : close file
|
|
|   The program will fulfill following tasks:
|     Build a linked list
|     Display linked lists
|     Free link lists
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Data will be entered through two input files of book data
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   All the integers will be stored in link lists.
|  Malloc is used to reserve memory, and free will free the memory at the end
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The linked list and merged link list will be printed to output file
|
|--------------------------------------------------------------------------------------------------
*/

#include "SchutzW_Lab5.h"
int main(void)
{

	// Create a pointer for our linked list
	// Assign the pointer to NULL
	linkList* pList1 = NULL;
	linkList* pList2 = NULL;
	linkList* pList3 = NULL;
	//create file pointers
	FILE* pFin1;
	FILE* pFin2;
	FILE* pFin1MERGE;
	FILE* pFin2MERGE;
	FILE* pFout;
	//Open Files
	OpenFiles(&pFin1, "Enter Name of first input file: ", "r");
	OpenFiles(&pFin1MERGE, "Enter Name of first input file AGAIN: ", "r");
	OpenFiles(&pFin2, "Enter Name of second input file: ", "r");
	OpenFiles(&pFin2MERGE, "Enter Name of second input file AGAIN: ", "r");
	OpenFiles(&pFout, "Enter Name of output file: ", "w");
	//Print header
	PrintHeader(stdout);
	PrintHeader(pFout);
	// Move cursor down one line
	printf("\n");
	//	Read data into first list
	ReadDataFromFile(pFin1, &pList1);
	// Read data into second list
	ReadDataFromFile(pFin2, &pList2);
	//Merge lists
	ReadDataFromFile(pFin1MERGE, &pList3);
	ReadDataFromFile(pFin2MERGE, &pList3);
	//Print Lists
	PrintList(pFout, pList1, "List 1");
	PrintList(pFout,pList2, "List 2");
	PrintList(pFout,pList3, "List 1 and 2 Merged");
	//Free lists
	FreeTheList(&pList1);
	FreeTheList(&pList2);
	FreeTheList(&pList3);
	//Print Lists
	PrintList(stdout, pList1, "List 1 Free");
	PrintList(stdout,pList2, "List 2 Free");
	PrintList(stdout,pList3, "List Merged Freed");
	PrintList(pFout, pList1, "List 1 Free");
	PrintList(pFout,pList2, "List 2 Free");
	PrintList(pFout,pList3, "List Merged Freed");
	//Close Files
	CloseFiles(&pFin1);
	CloseFiles(&pFout);
	CloseFiles(&pFin2);
	
	
}