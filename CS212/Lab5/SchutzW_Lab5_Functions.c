#include "SchutzW_Lab5.h"
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
void OpenFiles(FILE ** pointer, char message[], char type[])
{
	char fileName[30];

	printf("%s", message);
	
	// Check to see if one string was read in
	if (scanf("%s", fileName) == 1)
	{
		// Because fileName is a double pointer, we must dereference it 
		*pointer = fopen(fileName, type);
	}
}
//-----------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//   Close a files base on one or two input pointers
//
//-----------------------------------------------------------------------------
void CloseFiles(FILE** file1)
{
	// Check to see if file1 is valid
	if (*file1 != NULL)
	{
		// Close file1
		fclose(*file1);
	}
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
// Function Name: ReadDataFromFile
// Description:
//   Read data from .txt file into linked list
//
//-----------------------------------------------------------------------------
void ReadDataFromFile(FILE* pFin, linkList** pList)
{
	char Book_Title[MAX];
	char Book_Author[MAX];
	char Publisher[MAX];
	int YearPublished;
	char ISBN[MAX];
	double cost;
	linkList * newElement;
	if (pFin == NULL)
	{
		printf("\nno File exists\n");
	}
	else
	{	
		fgets(Book_Title, MAX, pFin);	
		while (!feof(pFin))
		{
			newElement = (linkList*)malloc(sizeof(linkList));

			fgets(Book_Author, MAX, pFin);
			fgets(Publisher, MAX, pFin);
			fscanf(pFin, "%d\n", &YearPublished);
			fgets(ISBN, MAX, pFin);
			fscanf(pFin, "%lf\n", &cost);
			
			CreateNode(newElement, Book_Title, Book_Author, Publisher, YearPublished, ISBN, cost);
			AddNodeToList(pList, newElement);

			// Changer
      		fgets(Book_Title, MAX, pFin);
		}
	}
}

//-----------------------------------------------------------------------------
// Function Name:InsertNewNode
// Description:
//   A new node will be inserted to our link list
//
//-----------------------------------------------------------------------------
void AddNodeToList(linkList** pList, linkList* pNewNode)
{
  // Add new node to the link list
  pNewNode->pNext = *pList;
  *pList = pNewNode;
}


//-----------------------------------------------------------------------------
// Function Name:CreateNode
// Description:
//   ALL members of the new node will be initialized. 
//
//-----------------------------------------------------------------------------
void CreateNode(linkList* pNewNode, char Book_Title[], char Book_Author[], char Publisher[], int YearPublished, char ISBN[], double cost)
{
	// Assign members of the new node
	strcpy(pNewNode->record.Book_Title, Book_Title);
    strcpy(pNewNode->record.Book_Author, Book_Author);
    strcpy(pNewNode->record.Publisher, Publisher);
    pNewNode->record.YearPublished = YearPublished;
    strcpy(pNewNode->record.ISBN,ISBN);
    pNewNode->record.cost = cost;
  	pNewNode->pNext = NULL;
}

//-----------------------------------------------------------------------------
// Function Name:PrintList
// Description:
//  This function will take the pointer to our link list and print the list to output file
//  Since the address will not be changing there is no reason for a double 
//  pointer. 
//
//-----------------------------------------------------------------------------
void PrintList(FILE * pFout, linkList* pList, char listTitle [])
{
	PrintDivider(pFout, DASH, SCREEN_WIDTH);
    CenterString(pFout, listTitle, SCREEN_WIDTH);
    PrintDivider(pFout, DASH, SCREEN_WIDTH);

  	// Point to beginning of list
  	linkList* pTemp = pList;

  	// Check to see if the list is empty
  	if (pList == NULL)
  	{
  		fprintf(pFout, "This list is empty: %s\n", listTitle);
  	}
  	else
  	{
  		while (pTemp != NULL)
  		{
  			// Print current record data
  			PrintOneRecord(pFout, pTemp);

  			// Move pointer to the next number in the list
  			pTemp = pTemp->pNext;
  		}
  	}
}
//-----------------------------------------------------------------------------
// Function Name:PrintOneRecord
// Description:
// Prints one record from the linked list passed to the function
//
//-----------------------------------------------------------------------------
void PrintOneRecord(FILE * pFout, linkList* pTemp)
{
		// Print the number of the current number
	fprintf(pFout, "Title: %s ", pTemp->record.Book_Title);
	fprintf(pFout, "Author: %s ", pTemp->record.Book_Author);
	fprintf(pFout, "Company: %s ", pTemp->record.Publisher);
	fprintf(pFout, "Year: %d \n", pTemp->record.YearPublished);
	fprintf(pFout, "ISBN: %s ", pTemp->record.ISBN);
	fprintf(pFout, "Cost: %.2f \n\n", pTemp->record.cost);

	// Move the cursor down to the next line
	printf("\n");
}

//-----------------------------------------------------------------------------
// Function Name: FreeTheList
// Description:
//  This function will delete/free every node in the link list
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
