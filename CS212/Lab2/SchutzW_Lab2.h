#ifndef SchutzW_Lab2_H
#define SchutzW_Lab2_H

// Include for printf and scanf
#include <stdio.h>

// Include for the srand and rand function
#include <stdlib.h>

// Include for the strlen function
#include <string.h>

// Include for the time function
#include <time.h>

// Macros
#define DASH '-'
#define STAR '*'
#define SCHOOL "Binghamton University"
#define PROGRAMMER "Written by: Walter Schutz"
#define LAB "Lab 2"
#define ARRAY_SIZE 50

// Constants

const int MAX = 50;
const int SCREEN_WIDTH = 80;


// Prototypes
void PrintHeader(FILE *pFout);

void CenterString(FILE *pFout, char string[], int lengthToCenterAcross);

void PrintDivider(FILE *pFout, char symbol, int numberOf);

void OpenFile(FILE ** pointer, char message[], char type[]);

void CloseFile(FILE** file1, FILE** file2);

void ReadDataFromFile(FILE* pFin, int ARRAY_OUT[], int* ARRAY_FILL);

void FillArrayWithRandomNumbers(int intArray[]);

void PrintArray(FILE* pFout, const int ARRAY_OUT[], int arrayCounter);

void CountEvenOddNumbers(int ARRAY_OUT[ ], int *odd, int *even, int arrayCounter);

int TotalArray(int ARRAY_OUT[ ]);

double CalculateAverage(int total, int max);

int CountNumberAboveAverage(int ARRAY_OUT[ ], int average, int max);

void PrintResults(FILE *pFout, int odd, int even, int total, double average, int numAboveAverage);

#endif