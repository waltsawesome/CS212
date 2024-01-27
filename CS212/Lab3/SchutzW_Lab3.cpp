/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Lab 3
| Date:             February 12, 2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   This program is made to the specification of Lab 3
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Integers are stored in a data file called Numbers1.txt
|   an additional .txt file stores integers and is called Numbers2.txt
|--------------------------------------------------------------------------------------------------
| Processing:
|   The integers will be read in from a files and stored in arrays
|  
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The contents of the array will be printed to an output file and the screen. 
|
|   Before the program exits, the object will be destroyed. The destructor will print a message
| to the screen.
|
|--------------------------------------------------------------------------------------------------
*/

#include "SchutzW_Lab3.h"

int main(void)
{
	// Create file pointers
	FILE * pFin;
	FILE * pFin2;
	FILE * pFout;
	
	//Create integer arrays
    int intArray1[ARRAY_SIZE];
    int intArray2[ARRAY_SIZE];
	int intArray3[ARRAY_SIZE];

	// Create array lengths
	int Numbers1Length;
	int Numbers2Length;

	//Create array titles for PrintArray
	char title1[] = "1: Numbers1.txt Array";
	char title1a[] = "1: Numbers1.txt Array";
	char title2[] = "2: Random Array";
	char title2a[] = "2: Random Array Sorted";
	char title3[] = "3: Numbers2.txt Array";
	char title3a[] = "3: Numbers2.txt Array Sorted";

	//File names
	char name1[] = "Numbers1.txt";
	char READ[] = "r";
	char WRITE[] = "w";
	char name2[] = "Output.txt";
	char name3[] = "Numbers2.txt";
	
	objectType object;

    OpenFiles(&pFin, name1, READ);
	OpenFiles(&pFout, name2, WRITE);
	OpenFiles(&pFin2, name3, READ);
	
	object.PrintHeader(stdout);
	object.PrintHeader(pFout);
	
	//Read Numbers1.txt and Numbers2.txt
	Numbers1Length = object.ReadDataFromFile(pFin, intArray1);
	Numbers2Length = object.ReadDataFromFile(pFin2, intArray3);
	
	// Print array fron Numbers1.txt
	object.PrintArray(stdout, intArray1, title1, Numbers1Length);
	object.PrintArray(pFout, intArray1, title1, Numbers1Length);

	//Sort Numbers1.txt array
	object.SelectionSort(intArray1, Numbers1Length);
	
	// Print SORTED array fron Numbers1.txt
	object.PrintArray(stdout, intArray1, title1a, Numbers1Length);
	object.PrintArray(pFout, intArray1, title1a, Numbers1Length);

	// Print randomly generated array
	object.GenerateRandomNumbers(intArray2);
	object.PrintArray(stdout, intArray2, title2, ARRAY_SIZE);
	object.PrintArray(pFout, intArray2, title2, ARRAY_SIZE);

	//Sort random array
	object.BubbleSort(intArray2, ARRAY_SIZE);
	
	// Print SORTED random array
	object.PrintArray(stdout, intArray2, title2a, ARRAY_SIZE);
	object.PrintArray(pFout, intArray2, title2a, ARRAY_SIZE);
	
	// Print array form Numbers2.txt
	object.PrintArray(stdout, intArray3, title3, Numbers2Length);
	object.PrintArray(pFout, intArray3, title3, Numbers2Length);	

	//Sort array 3
	object.InsertionSort(intArray3, Numbers2Length);
	
	// Print array form Numbers2.txt
	object.PrintArray(stdout, intArray3, title3a, Numbers2Length);
	object.PrintArray(pFout, intArray3, title3a, Numbers2Length);	
	// Close files
	CloseFiles(&pFin, &pFout);
	
	return 0;
}
