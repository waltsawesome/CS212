
#include "SchutzW_Lab4.h"

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
//  Open a file in the current folder with the specified filename 
//	Prompts user for input to enter the file name
//-----------------------------------------------------------------------------
void OpenOutputFile(FILE ** pointer, char message[])
{
	char fileName[30];

	printf("%s", message);
	
	// Check to see if one string was read in
	if (scanf("%s", fileName) == 1)
	{
		// Because fileName is a double pointer, we must dereference it 
		*pointer = fopen(fileName, "w");
	}
}
//-----------------------------------------------------------------------------
// Function Name: StarPattern
// Description:
// Recursively generate a pattern of stars : * for a user-entered number of 
//	lines
//-----------------------------------------------------------------------------
void StarPattern(FILE * pFout, int numLines)
{   
    fprintf(pFout,"\n"); 
    if (numLines>=1){
        for (int index = 0; index < numLines; index++){
            fprintf(pFout,"*");
            //printf("*");
        }
        StarPattern(pFout, numLines-1);
    }

	
}
//-----------------------------------------------------------------------------
// Function Name: PrintFunctionHeader
// Description:
//  Print a header similar to PrintHeader but with specified text
//	
//-----------------------------------------------------------------------------
void PrintFunctionHeader(FILE * pFout, char title[]){
	// Call function to print a divider to the screen
	PrintDivider(pFout, DASH,  SCREEN_WIDTH);

	// Call functions to print strings to center to the screen
	CenterString(pFout, title, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pFout, DASH, SCREEN_WIDTH);

} // End PrintHeader
//-----------------------------------------------------------------------------
// Function Name: FillArrayWithRandomNumbers
// Description:
//  Fill an integer array with random numbers from 1 to the user input max
//	Input an integer array, the size, and the maximum value
//-----------------------------------------------------------------------------
void FillArrayWithRandomNumbers(int intArray[], int ArraySize, int max)
{
	for (int index = 0; index < ArraySize; index++)
	{
		// Set each element of the array to a number between 1 and 99
		intArray[index] = (rand() % max+1);
	}
}
//-----------------------------------------------------------------------------
// Function Name: PrintArray
// Description:
//  Print the contents of an integer array to an output file 2 elements per line
//	Maximum length of the integers is 5 digits
//-----------------------------------------------------------------------------
void PrintArray(FILE* pFout, const int ARRAY_OUT[], int arraySize)
{
	
	PrintDivider(pFout, DASH, SCREEN_WIDTH);
	
	CenterString(pFout, "Array Contents", SCREEN_WIDTH);
	
	PrintDivider(pFout, DASH, SCREEN_WIDTH);

	for (int index = 0; index < arraySize; index++)
	{
		// Print one integer to the screen in a width of 5 and right justified
		//fprintf(pFout, "%5d", ARRAY_OUT[index]);

		// Check to see if 2 integers have been printed
		if ((index ) % 2 == 0)
		{
			// Move the cursor down to the next line and print row label

			fprintf(pFout, "\n");

		}
		// Print one integer to the screen in a width of 5 and right justified

		fprintf(pFout, "%5d", ARRAY_OUT[index]);

	}

	// Move the cursor down 

	fprintf(pFout, "\n");

}
//-----------------------------------------------------------------------------
// Function Name: Array_Sum
// Description:
//  Calculate the sum of all elements in an ineger array given the integer array and 
//	array length.
//-----------------------------------------------------------------------------
int Array_Sum(int intArray[], int ArrayLength)
{   
	// Base Case
	if (ArrayLength <= 0){
		return 0;
	}
	// add current element to recursive call (next element)
	return (Array_Sum(intArray, ArrayLength-1) + intArray[ArrayLength - 1]);
	
}
//-----------------------------------------------------------------------------
// Function Name: PrintDigit
// Description:
//  Recursively print the digits of a number in reverse
//	Prints the results to the specified output file 
//-----------------------------------------------------------------------------
void PrintDigit(FILE * pFout, int schumber)
{   
	int lastDigit;

	if (schumber != 0){
	//Last digit
	lastDigit = schumber % 10; 
	fprintf(pFout, "%d", lastDigit);
	//recursion, schumber/10 eliminated current last digit 
	PrintDigit(pFout, (schumber/10));
	}
}
//-----------------------------------------------------------------------------
// Function Name: ReverseString
// Description:
//  Recursively print a user-defined string in reverse and output to and output 
//	file.
//-----------------------------------------------------------------------------
void ReverseString(FILE * pFout, char * Rstring){
	if (*Rstring){
		// Recursive call 
		ReverseString(pFout, Rstring+1);
		// prints the "first" character, *Rstring is one character forward on 
		// each function call. upon base case, the last character is printed first.
		fprintf(pFout,"%c",*Rstring);
	}else{// BASECASE
	fprintf(pFout,"String output: ");}
	
}
//-----------------------------------------------------------------------------
// Function Name: ConvertCustom
// Description:
//  Convert a decimal number into binary, ternary, quatenary... up to base 9
//	The first input is the decimal number to convert, and the second input
//  is the numeral system to convert to. When converting to lower base systems
//  like binary, an input that is too large can cause the output to loop back 
//  and give a wrond result
//-----------------------------------------------------------------------------
int ConvertCustom(int schminput, int base){
	//base case
	if (schminput == 0){
		return 0;
	}else{
		// schminput%base is least significant digit on first call
		// and most significant digit on last call
		return (schminput % base + 10*ConvertCustom(schminput/base, base));
	}
}
//-----------------------------------------------------------------------------
// Function Name: QuickSort
// Description:
//  Sort an array recursively by partitioning and sorting 
//	
//-----------------------------------------------------------------------------
void QuickSort(int intArray[], int Less, int Greater){
	if (Less<Greater){
		// index of partition
		int partIndex = partition(intArray, Less, Greater);

		//Sort elements before partition
		QuickSort(intArray, Less, partIndex-1);
		//sort elements after partition
		QuickSort(intArray, partIndex+1, Greater);
	}
}
//-----------------------------------------------------------------------------
// Function Name: partition
// Description:
//  Find and return partition index and put elements greater than pivot after a
//	and elements less than pivot before pivot
//-----------------------------------------------------------------------------
int partition(int intArray[], int Less, int Greater){
	// current position of the pivot
	int pivot = intArray[Greater];

	int index = (Less-1);
	for (int schmindex = Less; schmindex < Greater; schmindex++){
		//if current element is smaller than pivot
		if (intArray[schmindex] <= pivot){
			// increment index 
			index = index+1;
			// swap elements
			swap(&intArray[index], &intArray[schmindex]);
		}
	}
	swap(&intArray[index+1], &intArray[Greater]);
	return (index+1);
}
//-----------------------------------------------------------------------------
// Function Name: swap
// Description:
//  swap two integers
//	
//-----------------------------------------------------------------------------
void swap(int *aINT, int *bINT){
	// temp valiable
	int buffer=*aINT;
	*aINT=*bINT;
	*bINT=buffer;
}