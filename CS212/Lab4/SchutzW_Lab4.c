/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    Lab 4 Recursive functions
| Date:             2/22/2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   The program sets up and runs a variety of recursive functions. 
|   THe program calculates the average of the array's elements, the number of elements greater 
|   than the average, the number of odd and even numbers, and can create a random 50 array as well.
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   All "Inputs" are defined as strings and integers in the program, and are defined by the lab 
|   document
|--------------------------------------------------------------------------------------------------
| Processing:
|   The program uses recursive functions to calculate the outputs 
|   calculations.
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The results of all calculations are written to an output file: Output.txt
|
|--------------------------------------------------------------------------------------------------
*/

#include "SchutzW_Lab4.h"
#include "SchutzW_Lab4_Functions.c"

int main(void)
{
    // make time
    time_t myTime;
    srand((unsigned int)time(&myTime));
    
    //Make arrays
    int intArray_1 [ ARRAY_SIZE ] = {0};
    int intArray_2 [ ARRAY_SIZE ] = {0};
    int QuickArray[50] = {0};
    int int1=0;
    int int2=0;
    FillArrayWithRandomNumbers(intArray_1, ARRAY_SIZE, 99);
    FillArrayWithRandomNumbers(intArray_2, ARRAY_SIZE, 99);
    FillArrayWithRandomNumbers(QuickArray, 50, 999);
    // Declare output file pointers
    FILE *pFout;

    // Open files
    OpenOutputFile(&pFout, "Enter Name of output file: ");

    //Print header
    PrintHeader(pFout);

    //FIRST FUNCTION PRINTING
    char title1[] = "Star Pattern - Printed to the output file";
    PrintFunctionHeader(pFout, title1);
    // Function Call
    StarPattern(pFout, 12);
    PrintDivider(pFout, DASH,  SCREEN_WIDTH);
    char title2[] = "Star Pattern - Printed to the screen";
    PrintDivider(stdout, DASH,  SCREEN_WIDTH);
    PrintFunctionHeader(stdout, title2);
    // Function Call
    StarPattern(stdout, 15);
    PrintDivider(stdout, DASH,  SCREEN_WIDTH);
    
    // Second Function
    char title3[] = "2nd Recursive Function: Sum the Array";
    PrintFunctionHeader(pFout, title3);
    PrintArray(pFout, intArray_1, ARRAY_SIZE);
    fprintf(pFout, "Sum of Array One: %d", Array_Sum(intArray_1,ARRAY_SIZE));
    fprintf(pFout, "\n");
    char title4[] = "2nd Recursive Function: Sum the Array";
    PrintFunctionHeader(stdout, title4);
    PrintArray(stdout, intArray_1, ARRAY_SIZE);
    fprintf(stdout, "Sum of Array Two: %d\n", Array_Sum(intArray_2,ARRAY_SIZE));
   
   
    //Third Function
    char title5[] = "3rd Recursive Function: PrintDigit";
    PrintFunctionHeader(pFout, title5);
    fprintf(pFout,"Digits Printed recursively: \n");
    PrintDigit(pFout,1385);
    fprintf(pFout,"\n");
    PrintDivider(pFout, DASH,  SCREEN_WIDTH);
    
    PrintFunctionHeader(stdout, title5);
    fprintf(stdout,"Digits Printed recursively: \n");
    PrintDigit(stdout,1680);
    fprintf(stdout,"\n");
    PrintDivider(stdout, DASH,  SCREEN_WIDTH);
    
    // Fourth Function
    char title6[] = "4th Recursive Function: ReverseString";
    char reverse1[] = "Hello World";
    char reverse2[] = "I love programming";
    
    PrintFunctionHeader(pFout, title6);
    fprintf(pFout,"String input: %s \n",reverse1);
    ReverseString(pFout, reverse1);
    fprintf(pFout,"\n");
    PrintDivider(pFout, DASH,  SCREEN_WIDTH);

    PrintFunctionHeader(stdout, title6);
    fprintf(stdout,"String input: %s \n",reverse2);
    ReverseString(stdout, reverse2);
    fprintf(stdout,"\n");
    PrintDivider(stdout, DASH,  SCREEN_WIDTH);
    
    // Final Fcuntion
    int dec1 = 12;
    int dec2 = 29;
    int bas1 = 2;
    int bas2 = 5;
    char title7[] = "5th Recursive Function: CustomFunky";
    PrintFunctionHeader(pFout, title7);
    int1 = ConvertCustom(dec1,bas1);
    fprintf(pFout, "%d converted to base %d is %d\n", dec1, bas1, int1);
    PrintDivider(pFout, DASH,  SCREEN_WIDTH);

    PrintFunctionHeader(stdout, title7);
    int2 = ConvertCustom(dec2,bas2);
    fprintf(stdout, "%d converted to base %d is %d\n", dec2, bas2, int2);
    PrintDivider(stdout, DASH,  SCREEN_WIDTH);

    // Extra credit
    char title8[] = "Extra Credit before Quicksort:";
    PrintFunctionHeader(pFout, title8);
    PrintFunctionHeader(stdout, title8);
    PrintArray(pFout, QuickArray, 50);
    PrintArray(stdout, QuickArray, 50);
    QuickSort(QuickArray, 0, 50);
    char title9[] = "Extra Credit after Quicksort:";
    PrintFunctionHeader(pFout, title9);
    PrintFunctionHeader(stdout, title9);
    PrintArray(pFout, QuickArray, 50);
    PrintArray(stdout, QuickArray, 50);
    return 0;
}