#include "SchutzW_Lab6.h"
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
// Function Name: OpenFile
// Description:
//  Open a file in the current folder with the specified filename and mode
//	Prompts user for input to enter the file name
//-----------------------------------------------------------------------------
void OpenDataFiles(FILE ** pointer, char type[])
	{
		//filename array
		char fileName[30];
    if (type[0] == 'w'){
      // Prompt user
      printf("Enter the name of the output file: ");
    }
    else{
      printf("Enter the name of the input file: ");
    }
		if (scanf("%s", fileName) == 1)
			*pointer = fopen(fileName, type);

		printf("\n");
	}
//-----------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//   Close a files base on one or two input pointers
//
//-----------------------------------------------------------------------------
void CloseDataFiles(FILE** pointer)
{
  // Check to see if file1 is valid
  if (*pointer != NULL)
  {
    // Close file1
    fclose(*pointer);
  }
}
//-----------------------------------------------------------------------------
// Function Name: Push
// Description:
//   Add an item to the top of the stack
//
//-----------------------------------------------------------------------------
void Push(stackType * pData, nodeType * newElement)
{   
     
  //Defensive coding
		if (newElement == NULL){
			printf("ERROR : There is no new data\n");
		}
		else
		{
			// Set the next pointer of the new node to equal top
			newElement->pNext = pData->pTop;

			// Move the top pointer
			pData->pTop = newElement;
		}
	}
//-----------------------------------------------------------------------------
// Function Name: Pop
// Description:
//   Take the top item off the stack
//
//-----------------------------------------------------------------------------
nodeType * Pop(stackType* pData)
  {
  	nodeType* pTemp = NULL;
  	// if the stack empty
  	if (!isEmpty(* pData))
  	{
  		// ptemp is top of the stack
  		pTemp = pData->pTop;
  		// pop pTemp off stack by making pTop = to pNext
  		pData->pTop = pData->pTop->pNext;
  	}

		  // pTemp is the node popped of the stack
	return pTemp;
  }
//-----------------------------------------------------------------------------
// Function Name: ReturnPriority
// Description:
//   return value based on symbol from stack
//
//-----------------------------------------------------------------------------
int ReturnPriority(char symbol)
{
    if (symbol == ('(')){
        return 0;
    }
    else if ((symbol == '+')|(symbol == '-')){
        return 1;
    }
    else if ((symbol == '*')|(symbol == '/')){
        return 2;
    }
	//return -1 if nothing else works
	return -1;
}
//-----------------------------------------------------------------------------
// Function Name: CreateNode
// Description:
//   Create node before pushing to stack
//-----------------------------------------------------------------------------
void CreateNode(nodeType* pNewNode, char symbol)
  {
  	// Assign members of the new node
  	pNewNode->record.symbol = symbol;
  	pNewNode->pNext = NULL;
  }
  //-----------------------------------------------------------------------------
// Function Name: IsEmpty
// Description:
//   Returns true is pointer is not null
//
//-----------------------------------------------------------------------------
int isEmpty(stackType stack)
{
	// check to see if the stack is empty
	return stack.pTop == NULL;
}
//-----------------------------------------------------------------------------
  // Function Name: isdigit
  // Description:
//returns 0 if not a number, 1 if a number
  // based on ASCII values
  //-----------------------------------------------------------------------------
	int isDigit(char symbol){
		//number ascii values
		if (symbol > 47 && symbol < 58)
			return 1;
		else
			return 0;
	}