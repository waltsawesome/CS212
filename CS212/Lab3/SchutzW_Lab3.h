
#ifndef SchutzW_Lab3_H
#define SchutzW_Lab3_H

// Include header files 
#include <stdio.h>
#include <string.h>

// Include for the time function
#include <time.h>

// Include for the srand and rand function
#include <stdlib.h>

// Macros
#define SCREEN_WIDTH 80
#define TABLE_WIDTH 60

#define STAR '*'
#define DASH '-'

#define SCHOOL "Binghamton University"
#define PROGRAMMER "Program written by: Walter Schutz"
#define LAB "Lab 3"

#define TABLE_TITLE "Array Output"

#define ARRAY_SIZE 50
#define NUMBER_PER_LINE 10

// Prototypes
void OpenFiles(FILE ** pFin, char fileName[], char mode[]);
void CloseFiles(FILE ** pFin, FILE ** pFout);
	
class objectType
{
	
	public:
	
	// Constructor prototype
	objectType(void);
	
	// Destructor prototype
	~objectType(void);
	
	// Public method prototypes
	void PrintHeader(FILE* pOutput);
	int ReadDataFromFile(FILE * pFin, int intArray[]);
	void PrintArray(FILE * pOutput, int intArray[],  char arrayTitle[] ,int arrayCounter);
	void GenerateRandomNumbers(int intArray[]);
    void InsertionSort(int intArray[], int arrayCounter);
    void BubbleSort(int intArray[], int arrayCounter);
    void SelectionSort(int intArray[], int arrayCounter);
	private:
	
	// Private method prototypes
	void PrintDivider(FILE* pOutput, char symbol, int numberOf);
	void CenterString(FILE* pOutput, const char string[], int lengthToCenterAcross);
	void PrintTable (FILE * pOutput, int intArray[], int arrayCounter);
	void PrintArrayHeader(FILE * pOutput,char arrayTitle[]);
	void PrintData(FILE * pOutput);
    void Swap(int *num1, int *num2);
	
	// Private data
	int intArray[ARRAY_SIZE];
	int arrayCounter;
	
};

#endif