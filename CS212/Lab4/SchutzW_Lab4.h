#ifndef SchutzW_Lab4_H
#define SchutzW_Lab4_H

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
#define LAB "Lab 4"
#define ARRAY_SIZE 20

// Constants

const int MAX = 50;
const int SCREEN_WIDTH = 80;


// Prototypes
void PrintHeader(FILE *pFout);

void CenterString(FILE *pFout, char string[], int lengthToCenterAcross);

void PrintDivider(FILE *pFout, char symbol, int numberOf);

void OpenOutputFile(FILE ** pointer, char message[]);

void StarPattern(FILE * pFout, int numLines);

void FillArrayWithRandomNumbers(int intArray[], int ArraySize, int max);

void PrintArray(FILE* pFout, const int ARRAY_OUT[], int arraySize);

int Array_Sum(int intArray[], int arrayLength);

void PrintDigit(FILE * pFout, int schumber);

void PrintFunctionHeader(FILE * pFout, char title[]);

int ConvertCustom(int schminput, int base);

void QuickSort(int intArray[], int Less, int Greater);

int partition(int intArray[], int Less, int Greater);

void swap(int *aINT, int *bINT);
#endif