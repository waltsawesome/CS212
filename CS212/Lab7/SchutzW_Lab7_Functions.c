#include "SchutzW_Lab7.h"
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
//-----------------------------------------------------------------------------
  // Function Name: PrintTableHeader	
  // Description:
  // Print the header for the results table to the file passed as a pointer to 
  // the function.
  //-----------------------------------------------------------------------------
void PrintTableHeader(FILE* pOutput){
	fprintf(pOutput,"Customer ID		Reason\n");
	PrintDivider(pOutput,DASH,SCREEN_WIDTH);
}
//-----------------------------------------------------------------------------
  // Function Name: SetAngryMessage	
  // Description:
  // Copy a string to the message field of the node
  // based on the reason_code field of the node
  //-----------------------------------------------------------------------------
void SetAngryMessage(nodeType * newMessage){
	int integer = newMessage -> data.reason_code;
	switch(integer){
		case 0:
			strcpy(newMessage -> data.message,"This store is terrible, I’m never coming back!");
		break;
		case 1:	
			strcpy(newMessage -> data.message,"I’m too busy for this! Maybe I come back later");
		break;
		case 2:
			strcpy(newMessage -> data.message,"Too much to do, too little time!");
		break;
		case 3:
			strcpy(newMessage -> data.message,"<yawn> I’m too lazy to wait in line.");
		break;
		default:
		break;

	}
}
//-----------------------------------------------------------------------------
  // Function Name: SetHappyMessage	
  // Description:
  // Copy a string to the message field of the node
  // based on the reason_code field of the node
  //-----------------------------------------------------------------------------
void SetHappyMessage(nodeType * newMessage){
	int integer = newMessage -> data.reason_code;
	switch(integer){
		case 0:
			strcpy(newMessage -> data.message,"AWESOME SERVICE! Can’t wait to come back.");
		break;
		case 1:	
			strcpy(newMessage -> data.message,"Checkout was a breeze! ");
		break;
		case 2:
			strcpy(newMessage -> data.message,"Got what I needed, very good store! ");
		break;
		case 3:
			strcpy(newMessage -> data.message,"Smiling customer will be happy to return");
		break;
		default:
		break;

	}
}
//-----------------------------------------------------------------------------
  // Function Name: Dequeue
  // Description:
  // Remove node from front of queue
  // Free allocated memort for the node
  //-----------------------------------------------------------------------------
void Dequeue(queueType * queue)
{
	nodeType* pTemp;

	if (queue->pFront == NULL)
	{
		// Print error message to the screen
		printf("ERROR, queue is empty\n");
	}
	else
	{
		// Assign temp to the front of the queue
		pTemp = queue->pFront;

		// Move the front pointer forward one
		queue->pFront = queue->pFront->pNext;

		// Check to see if the list is now empty
		if (queue->pFront == NULL)
		{
			// Set the rear pointer to NULL
			queue->pRear = NULL;
		}
		// Delete the temp pointer
		free(pTemp);
	}
}
//-----------------------------------------------------------------------------
  // Function Name: EnqueueNewNode
  // Description:
  // Determine which queue to add the node to
  // Add the node to that queue
  //-----------------------------------------------------------------------------
void EnqueueNewNode(queueType * happyQueue, queueType * angryQueue, nodeType * pNewNode, unsigned code)
{
	if (((1<<7)&code)!=0){ 
		Enqueue(angryQueue, pNewNode);
	}else if (((1<<6)&code)!=0){ 
		Enqueue(happyQueue, pNewNode);
	}
}
//-----------------------------------------------------------------------------
  // Function Name: Enqueue
  // Description:
  // Add new node to the queue 
  // Adds the mode passed to the function to the queue passed to the function
  //-----------------------------------------------------------------------------
void Enqueue(queueType * queue, nodeType * pNewNode)
{
	if (pNewNode == NULL)
	{
		// Print error message
		printf("ERROR, temp is NULL\n");
	}
	else
	{
		// Check to see if the queue is empty
		if (queue->pFront == NULL)
		{
			// Assign both pointers to our temp node
			queue->pFront = pNewNode;
			queue->pRear = pNewNode;
		}
		else
		{
			// Add new node to the queue
			queue->pRear->pNext = pNewNode;
			queue->pRear = pNewNode;
		}
	}
}
//-----------------------------------------------------------------------------
  // Function Name: CreateNodeNode
  // Description:
  // Create a new node that will be added to the queue
  // Fill the data fields of the node with data base on code.
  //-----------------------------------------------------------------------------
void CreateNodeNode(nodeType * pNewNode, unsigned code){
	if (((1<<7)&code)!=0){ 
		// Red bits 2 and 3 
		pNewNode->data.reason_code = ((code&6)>>1);
		SetAngryMessage(pNewNode);
	}else if (((1<<6)&code)!=0){ 
		pNewNode->data.reason_code = ((code&24)>>3);
		SetHappyMessage(pNewNode);
	}
	// Assign members of the new node
  	pNewNode->data.ID = ((code&65280)>>8);
  	pNewNode->pNext = NULL;
}
//-----------------------------------------------------------------------------
  // Function Name: PrintRowOfData
  // Description:
  // Print a row of data from one node to an output file
  // 
  //-----------------------------------------------------------------------------
void PrintRowOfData(FILE * pFout, nodeType * pQueue)
{
	fprintf(pFout, "	%d		%s	\n",pQueue->data.ID, pQueue -> data.message);
}
//-----------------------------------------------------------------------------
  // Function Name: QueueIsEmpty
  // Description:
  // Check if the queue is empty
  // 
  //-----------------------------------------------------------------------------
int QueueIsEmpty(queueType * queue)
{
	// Check to see if pointer is NULL
	return queue->pFront == NULL;
}