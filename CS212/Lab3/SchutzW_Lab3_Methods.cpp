

#include "SchutzW_Lab3.h"

//-----------------------------------------------------------------------------
// Function Name: objectType::objectType
// Description:
//   Constructor - this will initialize the array counter to 0
//
//-----------------------------------------------------------------------------
objectType::objectType(void)
{
	// Initialize constructor to 0
	arrayCounter = 0;
}


//-----------------------------------------------------------------------------
// Function Name: objectType::~objectType
// Description:
//   Destructor - this will print a message to the screen
//
//-----------------------------------------------------------------------------
objectType::~objectType(void)
{
	// Print message to the screen
	printf("\nYour object has been destroyed\n");
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void objectType::PrintHeader(FILE* pOutput)
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
// Function Name: objectType::PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void objectType::PrintDivider(FILE* pOutput, char symbol, int numberOf)
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
// Function Name: objectType::CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void objectType::CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	for (int counter = 0; counter < numberOfBlankSpaces; counter++)
	{
		// Print one space
		fprintf(pOutput, " ");
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);
}


//-----------------------------------------------------------------------------
// Function Name: objectType::ReadDataFromFile
// Description:
//   Integers will be read in and stored in the array
//
//-----------------------------------------------------------------------------
int objectType::ReadDataFromFile(FILE * pFin, int intArray[])
{
	int value;
	int arrayCounter = 0;

	// Check to see if we have a valid file pointer
	if (pFin != NULL)
	{
		while (fscanf(pFin, "%d" , &value) == 1 && arrayCounter < ARRAY_SIZE)
		{
			// Assign value to the array
			intArray[arrayCounter] = value;
			
			// Increase the counter of elements by 1
			arrayCounter++;
		}
	}
	return (arrayCounter);
			
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintArray
// Description:
//   This method will be the driver for printing the array 
//
//-----------------------------------------------------------------------------
void objectType::PrintArray(FILE * pOutput, int intArray[], char arrayTitle[], int arrayCounter)
{
	//  Call private methods
	PrintArrayHeader(pOutput, arrayTitle);
	PrintTable(pOutput, intArray, arrayCounter);
}
//-----------------------------------------------------------------------------
// Function Name:PrintTable
// Description:
//   This method will print the array
//
//-----------------------------------------------------------------------------
void objectType::PrintTable(FILE * pOutput, int intArray[], int arrayCounter)
{
	fprintf(pOutput, "        ");
	for (int index = 1; index<= NUMBER_PER_LINE; index++)
	{
		fprintf(pOutput, "|C:%1d|", index);
	}
	for (int index = 0; index < arrayCounter; index++)
	{

		if ((index ) % NUMBER_PER_LINE == 0)
		{
			// Print the enter key
			fprintf(pOutput, "\n");
			// Print Row header
			fprintf(pOutput, "Row %d: ", (index+1)/NUMBER_PER_LINE+1);
		}
		// Print element of the array to the output source
		fprintf(pOutput, "%5d", intArray[index]);
		
	}
	
	// Print the enter key
	fprintf(pOutput, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: objectType::PrintArrayHeader
// Description:
//   The method will print the header for the array output
//
//-----------------------------------------------------------------------------
void objectType::PrintArrayHeader(FILE * pOutput, char arrayTitle[])
{
	PrintDivider(pOutput, DASH, TABLE_WIDTH); 
	
	CenterString(pOutput, arrayTitle, TABLE_WIDTH);
	
	PrintDivider(pOutput, DASH, TABLE_WIDTH);
	
}


//-----------------------------------------------------------------------------
// Function Name: objectType::PrintData
// Description:
//   This method will print the array
//
//-----------------------------------------------------------------------------
void objectType::PrintData(FILE * pOutput)
{
	
	for (int index = 0; index < arrayCounter; index++)
	{
		// Print element of the array to the output source
		fprintf(pOutput, "%5d", intArray[index]);
		
		// Check to see if we need an enter key
		if ((index + 1) % NUMBER_PER_LINE == 0)
		{
			// Print the enter key
			fprintf(pOutput, "\n");
		}
	}
	
	// Print the enter key
	fprintf(pOutput, "\n");
}
//-----------------------------------------------------------------------------
// Function Name: GenerateRandomNumbers
// Description:
//   Fill specified array with 50 random numbers from 1 to 500
//
//-----------------------------------------------------------------------------
void objectType::GenerateRandomNumbers(int intArray[])
{
    time_t myTime;
    srand((unsigned int)time(&myTime));
	
	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		// Set each element of the array to a number between 1 and 500
		intArray[index] = (rand() % 1000)+1;
	}
}
//-----------------------------------------------------------------------------
// Function Name: Swap
// Description:
//   take two pointers to integers and swap them
//
//-----------------------------------------------------------------------------
void objectType::Swap(int *num1, int *num2)
{
	int holdVar = * num1;
	*num1 = *num2;
	*num2 = holdVar;
}
//-----------------------------------------------------------------------------
// Function Name: Selectionsort
// Description:
//   Find smallest element and put it in front of unsorted section
//
//-----------------------------------------------------------------------------
void objectType::SelectionSort(int intArray[], int arrayCounter)
{
	// initialize index variables
    int index, schmindex, mindex;
    
    // Loop for number of elements in array
    for (index = 0; index < arrayCounter-1; index++)
    {
        // Assume current element is minimum
        mindex = index;
        for (schmindex = index+1; schmindex < arrayCounter; schmindex++)
        {
          	if (intArray[schmindex] < intArray[mindex])
				// index of minimum element in remaining array
            	mindex = schmindex;
        }
        // Swap the found minimum element with current element
        if (mindex!=index)
            Swap(&intArray[mindex], &intArray[index]);
    }
}
//-----------------------------------------------------------------------------
// Function Name: Bubblesort
// Description:
//  Sort array from least to greatest by swapping elements if the subsequent 
//	element is less than the current element
//-----------------------------------------------------------------------------
void objectType::BubbleSort(int intArray[], int arrayCounter)
{
	bool notDone = true;
	while (notDone == true)
	{
		notDone = false;
		
		for (int index = 0; index < arrayCounter-1; index++)
		{
			if (intArray[index] > intArray[index+1])
			{
				Swap(&intArray[index], &intArray[index+1]);
				notDone = true;
			}
		}
	}
}
//-----------------------------------------------------------------------------
// Function Name: InsertionSort
// Description:
//   Put current value insot sorted section of arrayS
//
//-----------------------------------------------------------------------------
void objectType::InsertionSort(int intArray[], int arrayCounter)
{
    int index, Current, schmindex;
    for ( index= 1; index < arrayCounter; index++)
    {
        //set current value to sort
		Current = intArray[index];
        schmindex = index - 1;

        while (schmindex >= 0 && intArray[schmindex] > Current)
        {	
			//Shift elements to right until current is greater than or equal to schmindex
            intArray[schmindex + 1] = intArray[schmindex];
            schmindex = schmindex - 1;
        }
		//we know current is greater than or equal to schmindex
		//so it goes to the right of schmindex
		// if there is no value less than current it goes to 
		//index zero because schmindex = -1
        intArray[schmindex + 1] = Current;
    }
}