/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Written by Prof. Foos
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Simple Link List
| Date:             12, 12, 2022
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|  This program will allow the user to enter integer values and place those numbers at the front
| of the link list.
|
|   This program will call functions to complete the following tasks:
|     - Create a link list
|     - Print the link list to the screen
|     - Free (or delete) the link list
|     - Print the link list, showing that the list is empty
|
|   For more assistance with this program read the provided notes:
|     Notes for the Simple Link List Program.docx
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Users will enter integers until they enter a 0.
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   All the integers will be stored in a link list using dynamic memory
|  The functions malloc will be used to reserve memory at run-time and the function free will
|  will be used to free memory.
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The link list will be printed to the screen.
|   After the link list is destroyed a message will be displayed to the screen stating that
|   the list is empty.
|
|--------------------------------------------------------------------------------------------------
*/

#include "AdvancedLinkList.h"

int main(void)
{

	// Create a pointer for our linked list
	// Assign the pointer to NULL
	linkList* pList = NULL;

	PrintHeader(stdout);

	// Move cursor down one line
	printf("\n");

	/*
	   NOTE:

	   When creating a link list, the value of the pointer will be changing.

	   Therefore, you will need pass the address of the pointer.

	   The function header will have a double pointer as a parameter.

	*/

	CreateList(&pList);

	// Print message to the screen
	printf("\nPrint the list after entering all the data:\n\n");

	PrintList(pList);

	FreeTheList(&pList);

	// Print message to the screen	
	printf("\nPrint the list after freeing all the data:\n\n");

	PrintList(pList);

	return 0;
}


//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput)
{
	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pOutput, SCHOOL, SCREEN_WIDTH);
	CenterString(pOutput, PROGRAMMER, SCREEN_WIDTH);
	CenterString(pOutput, LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

}


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* pOutput, char symbol, int numberOf)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		fprintf(pOutput, "%c", symbol);

		// Increment counter
		counter++;
	}

	// Move the cursor down to the next line
	fprintf(pOutput, "\n");

}


//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print the spaces needed to center the string
	while (counter < numberOfBlankSpaces)
	{
		// Print one space
		fprintf(pOutput, " ");

		// Increment counter
		counter++;
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);
}


//-----------------------------------------------------------------------------
// Function Name:IsEmpty
// Description:
//   Returns if a link list is empty
//
//-----------------------------------------------------------------------------
int IsEmpty(linkList* pList)
{
	// Check to see if the link list is empty
	return pList == NULL;
}


//-----------------------------------------------------------------------------
// Function Name:CreateList
// Description:
//   This function will act as the driver to adding numbers to our link list. 
//
//-----------------------------------------------------------------------------
void CreateList(linkList** pList)
{
	int input;
	linkList* pTemp;

	linkList* pPrev;;
	linkList* pCurrent;

	do
	{
		// Enter a number to put into the list
		printf("Enter a number (zero to stop): ");
		scanf("%d", &input);

		if (input != 0)
		{
			// Set pPrev and pCurrent to NULL
			pPrev = NULL;
			pCurrent = NULL;
			
			// Create a new node
			pTemp = (linkList*)malloc(sizeof(linkList));

			CreateNode(pTemp, input);

			FindLocation(*pList, &pCurrent, &pPrev, pTemp->record.number);

			InsertNewNode(pList, &pCurrent, &pPrev, &pTemp);

		}

	} while (input != 0);

}


//-----------------------------------------------------------------------------
// Function Name:FindLocation
// Description:
//   The pointers pCurrent and pPrev will be positioned to that the new node
//  can be inserted into the link list. 
//
//-----------------------------------------------------------------------------
void FindLocation(linkList* pList, linkList** pCurrent, linkList** pPrev, int value)
{
	int done = FALSE;

	// Assign pCurrent to the list
	*pCurrent = pList;

	// Check to see if our link list is empty
	if (!IsEmpty(pList))
	{
		while ((*pCurrent)->pNext != NULL && done == FALSE)
		{
			if (value > (*pCurrent)->record.number)
			{
				// Assign previous to current
				*pPrev = *pCurrent;

				// Move current down one node
				*pCurrent = (*pCurrent)->pNext;

			}
			else
			{
				// Found where current is less than our new value
				done = TRUE;
			}
		}
	}
}


//-----------------------------------------------------------------------------
// Function Name: InsertNewNode
// Description:
//   A new node will be inserted to our link list. The number will be inserted
// in order.
//
//-----------------------------------------------------------------------------
void InsertNewNode(linkList** pList, linkList** pCurrent, linkList** pPrev, linkList** pTemp)
{
	// Check to see if the list is empty
	if (IsEmpty(*pList))
	{
		// Start the link list by pointing to a new node
		*pList = *pTemp;
	}

	// Check to see if their is only one node in the list
	else if (*pPrev == NULL)
	{
		if ((*pTemp)->record.number > (*pCurrent)->record.number)
		{
			// Place the new node after the first node
			(*pList)->pNext = *pTemp;

		}
		else
		{
			// Place the new node before the first node
			(*pTemp)->pNext = *pList;
			*pList = *pTemp;
		}
	}
	else if ((*pCurrent)->pNext == NULL &&
		(*pTemp)->record.number > (*pCurrent)->record.number)
	{
		// We can assume there is more than one node in the list

		// Add new node to the end of the list
		(*pCurrent)->pNext = *pTemp;

	}
	else
	{
		// Add new node before the current node
		(*pTemp)->pNext = *pCurrent;
		(*pPrev)->pNext = *pTemp;
	}

}


//-----------------------------------------------------------------------------
// Function Name:CreateNode
// Description:
//   Both members of the new node will be initialized. 
//
//-----------------------------------------------------------------------------
void CreateNode(linkList* pNewNode, int input)
{
	// Assign members of the new node
	pNewNode->record.number = input;
	pNewNode->pNext = NULL;
}


//-----------------------------------------------------------------------------
// Function Name:PrintList
// Description:
//  This function will take the pointer to our link list. 
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//  Every item of the link list will be printed to the screen
//
//-----------------------------------------------------------------------------
void PrintList(linkList* pList)
{
	// Assign a temp pointer to the beginning of our list
	linkList* pTemp = pList;

	// Check to see if the list is empty
	if (IsEmpty(pList))
	{
		// Print message to the screen
		printf("The list is empty.\n");
	}
	else
	{
		while (pTemp != NULL)
		{
			// Print the number of the current number
			printf("%d ", pTemp->record.number);

			// Move pointer to the next number in the list
			pTemp = pTemp->pNext;
		}
	}

	// Move the cursor down to the next line
	printf("\n");
}


//-----------------------------------------------------------------------------
// Function Name: FreeTheList
// Description:
//  This function will delete every node in the link list
//
//-----------------------------------------------------------------------------
void FreeTheList(linkList** pList)
{
	linkList* pTemp;

	while (*pList != NULL)
	{
		// Assign pTemp to pList
		pTemp = *pList;

		// Move pList to the next element
		*pList = (*pList)->pNext;

		// Delete pTemp
		free(pTemp);
	}
}
