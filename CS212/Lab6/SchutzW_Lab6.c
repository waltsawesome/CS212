/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Recursive Functions Lab 6
| Date:             March 31, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|     This program will use the following functions for processing output data files:
|    fopen   : opens an input or output file
|    fgets  :  read a line of a file as string
|    fgetc :  read data from the input file
|    fprintf : print to output file
|    fclose  : close file
|
|
|   The program will fulfill following tasks:
|     create a new stack
|     use the stack to encode an equation
|     Free all allocated memory
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Data will be taken from input file and put in the stack or printed depending on symbol
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   All the characters are stored in the stack
|  Malloc is used to reserve memory, and free will free the memory at the end
|	stack is printed to output
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The stack is printed to the output file
|
|--------------------------------------------------------------------------------------------------
*/

#include "SchutzW_Lab6.h"
int main(void)
{

	//create file pointers
	FILE* pFin;
	FILE* pFout;
	//Open Files
	OpenDataFiles(&pFin, "r");
	OpenDataFiles(&pFout, "w");
	//OpenDataFiles(&pFout, "Enter Name of output file FOR EXTRA CREDIT: ", "w+");
	//pFin = fopen('input.txt', "r");
	//Stack struct
	stackType stack;
	// Node pointers
	nodeType * pTemp = NULL;
	stack.pTop=NULL;
	//other variables
	char fileString[MAX];
	//Print Header
	PrintHeader(stdout);
	PrintHeader(pFout);
	if ((pFin != NULL)){
		while(!feof(pFin))
		{
			fgets(fileString, MAX, pFin);	
			for (int index=0; index<strlen(fileString); index++)
			{
				char character = fileString[index];
				
				if ((character != ' ') && (character != 0 ) && (character != 13)){
					pTemp=NULL;
					if (isDigit(character)){ // print character if it is a number
						fprintf(pFout,"%c ",character);
					}
					else if ((character== '(')){ // Push to stack
						// Create new node
						pTemp = (nodeType*) malloc(sizeof(nodeType));
						CreateNode(pTemp, character);
						Push(&stack,pTemp);

					}else if ((character == ')')){ //pop until symbol no longer this
						pTemp  = Pop(&stack);
						while ((pTemp-> record.symbol) !='('){
							fprintf(pFin,"%c ",pTemp->record.symbol);
							free(pTemp);
							pTemp  = Pop(&stack);
						}
						free(pTemp);
					} else if ((character == '-' )||(character  == '+')|| (character  == '/') || (character =='*'))
              		{
						pTemp=stack.pTop;
						while(ReturnPriority((pTemp->record.symbol)) >= ReturnPriority(character))
						{ // Print top of stack and pop
							pTemp = Pop (&stack);
							fprintf(pFout, "%c ", (pTemp->record.symbol));
							free(pTemp);
							pTemp = stack.pTop;
						}
					//Push current symbol to stack
					pTemp = (nodeType*) malloc(sizeof(nodeType));
					CreateNode(pTemp, character);
					Push (&stack, pTemp);

					}
				}
			}
			 // Restart For Loop at Next Character
			while (stack.pTop != NULL){ //pop from stack until stack is empty 
				pTemp = Pop(&stack);
				fprintf(pFout, "%c", pTemp->record.symbol);
				free(pTemp);
			}
			if (!feof(pFin)){
				fprintf(pFout, "\n");
			}
		// if not EOF loop restarts
		}
	}

    //Close Files
    CloseDataFiles(&pFin);
    CloseDataFiles(&pFout);

	return 0;
}
