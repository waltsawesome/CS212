/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Walter Schutz
| Course:           CS-212: Data Structures for Engineers
| Program  Name:    schutzw_Lab1.c
| Date:             01/18/22
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   The program will display a header and a menu with options to select a shape.
|   The user will be prompted to enter parameters for the selected shape and the program
|   will calculate the shape's area and display the results.
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Input will be provide by the user via the keyboard.
|  
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The calculations use multiplication and division to calculate area.
|  
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The outputs are displayed on the screen as text.
|
|
|--------------------------------------------------------------------------------------------------
*/

//include printf and scanf
#include <stdio.h>

//Prototypes
void Printheader(void);
int PrintMenuAndGetSelection(void);
double ProcessSelection(int selection, int* valueA, int* valueB, int* valueC);
void PrintShape(int selection);
void PrintResults(int selection, int valueA, int valueB, int valueC, double area);

//Macros
#define SCHOOL "Binghamton University"
#define NAME "Walter"
#define LAB "Lab 1"

//Constant
const double PI = 3.14;

int main(void) 
{
    int selection;
    int valueA;
    int valueB;
    int valueC;

    double area;

    Printheader();

    selection = PrintMenuAndGetSelection();

    area = ProcessSelection(selection, &valueA, &valueB, &valueC);

    PrintShape(selection);

    PrintResults(selection, valueA, valueB, valueC, area);

    return 0;
}
//-----------------------------------------------------------------------------
// Function Name: Printheader
// Description: Prints the program header as derermined by macros to 
// the terminal.
//
//-----------------------------------------------------------------------------
void Printheader(void)
{
    //Move cursor down one line 
    printf("\n");
    
    //Print header to screen
    printf("****************************\n");
    printf("%s\n", SCHOOL);
    printf("%s\n", NAME);
    printf("%s\n", LAB);
    printf("****************************\n");

}
//-----------------------------------------------------------------------------
// Function Name: PrintMenuAndGetSelection
// Description: Prints a menu to for user to select a shape and returns 
// the user's selection
//
//-----------------------------------------------------------------------------
int PrintMenuAndGetSelection(void)
{
    int selection;
    
    //Move cursor down one line 
    printf("\n");
   
    //Print menu to screen
    printf("Select a shape to calculate for area calculation:\n");
    printf("1. Parallelogram\n");
    printf("2. Trapezium\n");
    printf("3. Ellipse\n");

    //Prompt user for an answer and store the answer in a variable
    printf("Enter selection: ");
    scanf("%d", &selection);
    
    return selection;
}
//-----------------------------------------------------------------------------
// Function Name: ProcessSelection
// Description: Prompts the user for the necessary parameters to calculate the 
// area for the selected shape. Returns are of the selected shape.
//
//-----------------------------------------------------------------------------
double ProcessSelection(int selection, int* valueA, int* valueB, int* valueC)
{
    double area; 
   
    //Move cursor down one line 
    printf("\n");

    if (selection == 1)
    {
        //Prompt user for the length of the base and vertical height
        printf("Enter the base and vertical height separated by a space: ");
        scanf("%d %d", valueA, valueB);

        //Calculate AREA
        area = *valueA * *valueB;
    }
    
    //If selected Trapezium
    else if (selection ==2)
    {
        // Prompt user for length of sides
        printf("Enter the length of side A, side B, and the height separated by spaces: ");
        scanf("%d %d %d", valueA, valueB, valueC);

        // Calculate the area
        area = (double)((*valueA + *valueB) * *valueC) /2;
    }
    
    //If selected ellipse
    else
    {
        // Prompt user of the minor and major axis data
        printf("Enter the length of the minor and major axis separated by a space: ");
        scanf("%d %d", valueA, valueB);

        //Calculate the area
        area = PI * *valueA * *valueB;
    }
    
    //Move cursor down one line 
    printf("\n");

    return area;
}
//-----------------------------------------------------------------------------
// Function Name: PrintShape
// Description: Prints the name of the shape selected by the user
//
//
//-----------------------------------------------------------------------------
void PrintShape(int selection)
{
    
    //print the shape name
    switch(selection)
    {
        case 1:
            
            //print shape to screen
            printf("Shape: Parallelogram\n");
            break;

        case 2:
            
            //print shape to screen
            printf("Shape: Trapezium\n");
            break;   

        case 3:
            
            //print shape to screen
            printf("Shape: Ellipse\n");
            break;
    }
}
//-----------------------------------------------------------------------------
// Function Name: PrintResults
// Description: Prints results of ProcessSelection function to the terminal.
// what results are printed depends on shape selection.
//
//-----------------------------------------------------------------------------
void PrintResults(int selection, int valueA, int valueB, int valueC, double area)
{
    //Move cursor down one line 
    printf("\n");
    
    // Print results
    if (selection ==1)
    {
        
        // Print results for parallelogram
        printf("Length of the base: %d:\n", valueA);
        printf("Length of the height: %d:\n", valueB);
        printf("Area: %.3lf\n", area);
    }
    else if (selection ==1)
    {
        
        // Print results for trapezium
        printf("Length of side A: %d:\n", valueA);
        printf("Length of side B: %d:\n", valueB);
        printf("Length of the height: %d:\n", valueC);
        printf("Area: %.3lf\n", area);
    }
    else
    {
        
        // Print results for ellipse
        printf("Length of the minor axis: %d:\n", valueA);
        printf("Length of the major axis: %d:\n", valueB);
        printf("Area: %.3lf\n", area);
    }

    //Print divider
    printf("******************************************************");

    //Move cursor down one line 
    printf("\n");

}