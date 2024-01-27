/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Simple Array Program
| Date:             1/30/2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   Takes a .txt file as input and stores each line as an element of a 50 length integer array.
|   THe program calculates the average of the array's elements, the number of elements greater 
|   than the average, the number of odd and even numbers, and can create a random 50 array as well.
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   One of the arrays require a .txt file with an integer in each line as input, all other inputs
|   are randomly generated
|--------------------------------------------------------------------------------------------------
| Processing:
|   The values in the input .txt file are unchanged, but the program records the results of the above 
|   calculations.
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The results of all calculations are written to an output file: Output.txt
|
|--------------------------------------------------------------------------------------------------
*/

#include "SchutzW_Lab2.h"
#include "SchutzW_Lab2_Functions.c"

int main(void)
{
    int odd1, even1;
    int odd2, even2;
    int total1, total2;
    double average1, average2;
    int AbvAverage1, AbvAverage2;
    int ARRAY_FILL = 0;

    // Create two arrays of size 50
    int ARRAY_1 [ ARRAY_SIZE ] = {0};
    int ARRAY_2 [ ARRAY_SIZE ] = {0};

    // Declare input and output file pointers
    FILE *pFout;
    FILE *pFin;

    // Open files
    OpenFile(&pFin, "Enter Name of input file: ", "r");
    OpenFile(&pFout, "Enter Name of output file: ", "w");
    

    // Calling functions as specified in lab document
    PrintHeader(pFout);
    
    ReadDataFromFile(pFin, ARRAY_1, &ARRAY_FILL);
    
    FillArrayWithRandomNumbers(ARRAY_2);
    
    PrintArray(pFout, ARRAY_1, ARRAY_FILL);
    PrintArray(pFout, ARRAY_2, ARRAY_FILL);
    
    CountEvenOddNumbers(ARRAY_1, &odd1, &even1, ARRAY_FILL);
    CountEvenOddNumbers(ARRAY_2, &odd2, &even2, ARRAY_FILL);
    
    total1 = TotalArray(ARRAY_1);
    total2 = TotalArray(ARRAY_2);
    
    average1 = CalculateAverage(total1, ARRAY_FILL);
    average2 = CalculateAverage(total2, ARRAY_SIZE);

    AbvAverage1 = CountNumberAboveAverage(ARRAY_1, average1, ARRAY_FILL);
    AbvAverage2 = CountNumberAboveAverage(ARRAY_2, average2, ARRAY_FILL);

    PrintResults(pFout, odd1, even1, total1, average1, AbvAverage1);
    PrintResults(pFout, odd2, even2, total2, average2, AbvAverage2);

    CloseFile(&pFin, &pFout);


    return 0;
}