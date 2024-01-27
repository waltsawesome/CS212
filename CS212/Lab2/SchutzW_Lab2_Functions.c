

#include "SchutzW_Lab2.h"

//int main(void)
//{
//
//return 0;   
//}

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE *pFout)
{
	// Call function to print a divider to the screen
	PrintDivider(pFout, STAR,  SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pFout, SCHOOL, SCREEN_WIDTH);
	CenterString(pFout, PROGRAMMER, SCREEN_WIDTH);
	CenterString(pFout, LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pFout, STAR, SCREEN_WIDTH);

} // End PrintHeader


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* pFout, char symbol, int numberOf)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		fprintf(pFout, "%c", symbol);

		// Increment counter
		counter++;
	}

	// Move the cursor down to the next line
	fprintf(pFout,"\n");

} // END PrintDivider

//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE * pFout, char string[], int lengthToCenterAcross)
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
		fprintf(pFout," ");

		// Increment counter
		counter++;
	}

	// Print the string
	fprintf(pFout,"%s\n", string);

} // END CenterString

//-----------------------------------------------------------------------------
// Function Name: OpenFile
// Description:
//  Open a file in the current folder with the specified filename and mode
//	Prompts user for input to enter the file name
//-----------------------------------------------------------------------------
void OpenFile(FILE ** pointer, char message[], char type[])
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
// Function Name: CloseFile
// Description:
//   Close a files base on one or two input pointers
//
//-----------------------------------------------------------------------------
void CloseFile(FILE** file1, FILE** file2)
{
	// Check to see if file1 is valid
	if (*file1 != NULL)
	{
		// Close file1
		fclose(*file1);
	}

	// Check to see if file2 is valid
	if (*file2 != NULL)
	{
		// Close file2
		fclose(*file2);
	}
}
//-----------------------------------------------------------------------------
// Function Name: ReadDataFromFile
// Description:
//   Read 50 integers from .txt file into array
//
//-----------------------------------------------------------------------------
void ReadDataFromFile(FILE* pFin, int intArray[], int* ARRAY_FILL)
{
	int value;
	int dataReadIn;

	if (pFin == NULL)
	{
		// Print message to the screen
		printf("\nFile does not exist\n");
	}
	else
	{

		// Primer - attempt to read in a value
		dataReadIn = fscanf(pFin, "%d", &value);
		
		// Check to see if the file is empty
		if (dataReadIn == -1)
		{
			// Print message to the screen
			printf("File exist, but it is empty\n\n");
		}

		while (dataReadIn == 1 && *ARRAY_FILL < MAX)
		{
			// Assign the value to an element of the array
			intArray[*ARRAY_FILL] = value;

			// Increase the number of elements by one
			(*ARRAY_FILL)++;

			// Changer - attempt to read in another value
			dataReadIn = fscanf(pFin, "%d", &value);
		}

	}
}
//-----------------------------------------------------------------------------
// Function Name: FillArrayWithRandomNumbers
// Description:
//   Fill specified array with 50 random numbers from 1 to 500
//
//-----------------------------------------------------------------------------
void FillArrayWithRandomNumbers(int intArray[])
{
    time_t Time;
    srand((unsigned int)time(&Time));
	
	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		// Set each element of the array to a number between 1 and 500
		intArray[index] = (rand() % 500)+1;
	}
}
//-----------------------------------------------------------------------------
// Function Name: PrintArray
// Description:
//   Print an array up to 50 elements with 10 elements per row
//
//-----------------------------------------------------------------------------
void PrintArray(FILE* pFout, const int ARRAY_OUT[], int arrayCounter)
{
	
	PrintDivider(pFout, DASH, SCREEN_WIDTH);
	
	CenterString(pFout, "Array Contents", SCREEN_WIDTH);
	
	PrintDivider(pFout, DASH, SCREEN_WIDTH);

	for (int index = 0; index < arrayCounter; index++)
	{
		// Print one integer to the screen in a width of 5 and right justified
		//fprintf(pFout, "%5d", ARRAY_OUT[index]);

		// Check to see if 10 integers have been printed
		if ((index ) % 10 == 0)
		{
			// Move the cursor down to the next line and print row label
			fprintf(pFout, "\n");
			fprintf(pFout, "Row %d: ", (index+1)/10+1);
		}
		// Print one integer to the screen in a width of 5 and right justified
		fprintf(pFout, "%5d", ARRAY_OUT[index]);
	}

	// Move the cursor down 
	fprintf(pFout, "\n");
}
//-----------------------------------------------------------------------------
// Function Name: CountEvenOddNumbers
// Description:
//   Count the number of even and odd numbers in an array
//
//-----------------------------------------------------------------------------
void CountEvenOddNumbers(int ARRAY_OUT[ ], int *odd, int *even, int arrayCounter)
{
	// Loop for all elements of input array
    int index;
    for (index = 0; index < ARRAY_SIZE && index < arrayCounter; index++)
    {
        //Check if even or odd and increment variable
        if (ARRAY_OUT[index] % 2 == 0)
        {
            *even= *even + 1;
        }
        else
        {
            *odd = *odd + 1;
        }     
    }
}
//-----------------------------------------------------------------------------
// Function Name: TotalArray
// Description:
//   Calculate the total of all values in an integer array
//
//-----------------------------------------------------------------------------
int TotalArray(int ARRAY_OUT[ ])
{
    int i;
    int sum = 0;
	
	//Add each array element to sum integer variable
    for (i = 0; i< ARRAY_SIZE; i++)
    {
        sum = sum + ARRAY_OUT[i];
    }
    return sum; 
}
//-----------------------------------------------------------------------------
// Function Name: CalculateAverage
// Description:
//   Calculate the average based on total value of a set of values and the 
//	 number of values in the set
//-----------------------------------------------------------------------------
double CalculateAverage(int total, int max)
{
    // cast integer inputs to double for calculation
	if (max == 0)
	{
		return(0);
	}
	else
	{
		return ((double) total/(double) max);
	}
}
//-----------------------------------------------------------------------------
// Function Name: CountNumberAboveAverage
// Description:
//   Given an array, the number of values in it, and the average of the values 
//	 count the number of values above the average
//-----------------------------------------------------------------------------
int CountNumberAboveAverage(int ARRAY_OUT[ ], int average, int max)
{
    int index;
    int ABOVE_AVERAGE = 0;
	
	//Increment ABOVE_AVERAGE whenever element of array is above average
    for (index = 0; index< ARRAY_SIZE && index < max; index++)
    {
		//cast array integer to double for calculation
        if ((double) ARRAY_OUT[index] > average)
        {
            ABOVE_AVERAGE = ABOVE_AVERAGE + 1;
        }
    }
    return ABOVE_AVERAGE;
}
//-----------------------------------------------------------------------------
// Function Name: PrintResults
// Description:
//   Print the results of the program to the output .txt file.
//	Prints the number of odd and even numbers, the total value, the average value,
// and the number of values greater than the average
//-----------------------------------------------------------------------------
void PrintResults(FILE *pFout, int odd, int even, int total, double average, int numAboveAverage)
{

	// Print results passed into the function
    fprintf(pFout, "\n ODD NUMBERS: %d, EVEN NUMBERS %d:", odd, even);

    fprintf(pFout, "\n TOTAL ARRAY: %d", total);

    fprintf(pFout, "\n AVERAGE: %f", average);

    fprintf(pFout, "\n NUMBER ABOVE AVERAGE: %d", numAboveAverage);

}