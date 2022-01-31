/**
 * File:           swap.c
 * Author:         Risto Heinsar
 * Created:        19.08.2014
 * Last edit:      12.09.2018
 *
 * Description:    Partial lab code. Swaps the two numbers using pointers.
 */
 
#include <stdio.h>

// Write your prototypes for the functions here
void ScanVal(int *firstVal, int *secondVal);
void SwapVal(int *firstVal, int *secondVal);


int main(void)
{
    int x, y;
    
    // Write a line here to show the location of the x and y variable
    printf("Location of x is %p and location of y is %p\n", &x, &y);
    
    // Call your first function that scans for the values
    ScanVal(&x,&y);
    
    
    // printout just to verify that the numbers are scanned correctly.
    printf("Original values:\t  x=%3d and y=%3d\n", x, y);
    
    // Call your second function that swaps the numbers
    SwapVal(&x,&y);

    
    // a printout to verify the correctness of this swap
    printf("New: \t  x=%3d and y=%3d\n", x, y);
    return 0;
}


/**
 * Description:    Scan for two integer values and store them to
 *                   locations passed as pointers. It will also print
 *                 out the two locations where the values are stored.
 *
 * Parameters:     a - int pointer, first value
 *                 b - int pointer, second value
 *
 * Notes:          Write this function yourself!
 *
 * Return:         none
 */
void ScanVal(int *firstVal, int *secondVal)
{
	 printf("Enter the first val\n");
	 scanf("%d", firstVal);
	 printf("Enter the second val\n");
	 scanf("%d", secondVal);
	 printf("the location of first val is %p\n", &firstVal);
	 printf("the location of second val is %p\n", &secondVal);
}


/**
 * Description:    Swaps the two values passed using pointers. It will
 *                 also print out the locations of the two variables
 *                 that are about to be swapped.
 *
 * Parameters:     a - int pointer, first value
 *                 b - int pointer, second value
 *
 * Notes:          Write this function yourself!
 *
 * Return:         none
 */
 void SwapVal (int *firstVal, int *secondVal)
 {
	 int temp = 0;
	 
	 printf("the location of first val is %p\n", &firstVal);
	 printf("the location of second val is %p\n", &secondVal);
	 
	 temp = *firstVal;
	 *firstVal = *secondVal;
	 *secondVal = temp;
 }
