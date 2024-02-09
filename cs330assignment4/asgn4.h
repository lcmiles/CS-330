#ifndef __asgn4__
#define __asgn4__
/* the two lines above check to ensure
we haven't already included this header*/

/* any needed include statements can go here */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>         /* for malloc() */


/* some helper define statements */
#define NUMBER_OF_BITS 16          /* since we're using 16 bit binary numbers */
#define NUMBER_OF_HEX_DIGITS 4     /* 16 bit numbers are 2 bytes, or 4 hex digits */


/* helper function, prints a 16 bit binary number in a reasonably nice format
Takes an integer array, where each element represents one binary bit
Returns nothing, but as a side-effect it prints the number
*/
void printMyBinaryNum(int *myNumArray){
    /* loop through the number, one element (bit) at a time */
    for(int i = 0; i < NUMBER_OF_BITS; i++){
        /* lets print a space before every 4th digit (except the first, i==0), for readability */
        if(i % 4 == 0 && i != 0) {
            /* retrieve this element and print it */            
            printf(" %d", *(myNumArray + i));
        } else {          
            /* else, this is not a 4th digit, just print it with no space */ 
            printf("%d", *(myNumArray + i));
        }
    }  // end for-i loop
    //printf("\n");      /* and a newline when we're done, because it's kind to the reader */
}  // end printMyBinaryNum()



/* helper function, prints a 4 bit hex number 
Takes an integer array, where each element represents one hex digit
Returns nothing, but as a side-effect it prints the number
*/
void printMyHexNum(int *myNumArray){
    /* start by printing a sign to inform the reader that what follows is a hex number */
    printf("0x");
    /* loop through the number, one element (digit) at a time */
    for(int i = 0; i < NUMBER_OF_HEX_DIGITS; i++){
        /* print it out, %X is the conversion specifier for hex, in captital letters */
        printf("%X", *(myNumArray + i));
    }
    //removed this printf("\n") to make the print statements look better in my main()       
}  // end printMyHexNum()



/* Helper function to reverse an array 
Takes two arguments:
    an int size:  the size of the array, or number of elements
    an int pointer: the array
Returns a int pointer to the reverse array
Note: the return array is malloc'd and it is expected the user will free() the memory
    when no longer required
*/
int* reverseMyArrayPlease(int size, int *myArray){
    /* allocate memory, one int for each element, size*4 bytes */
    int *reversedArray = malloc( size * sizeof(int));
    /* loop through the array, extract one element, place it in the new array */  
    for(int i = 0; i < size; i++){
        /* -1 since the end of the array is at (size-1),
         -i since we want to reverse the array */
        *(reversedArray + (size - 1) - i) = *(myArray + i);
    }
    return reversedArray;
}  // end reverseMyArrayPlease()




/* ========================================================================= */
/* ~~~~~~~~~~~~~~~~~~~~~ your functions go here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note: main() goes in the asgn4.c file                                     */

int* convertDectoBin(int num, int *binArray) {
    for (int *ptr = binArray; ptr < binArray + NUMBER_OF_BITS; ++ptr) { // initialize the binary array to all zeros
        *ptr = 0;
    }
    int index = 0; //start at the beginning of the array
    if (num == 0) { //special case for handling 0
        *binArray = 0;
        return binArray;
    }
    while (num > 0 && index < NUMBER_OF_BITS) { //convert the decimal number to binary and store it in binArray in forward order
        *(binArray + index++) = num % 2;
        num = num / 2;
    }
    int* reversedBinArray = reverseMyArrayPlease(NUMBER_OF_BITS, binArray); //reverse the binary array
    return reversedBinArray;
}

int convertBintoDec(int *binArray) {
    int decimalNumber = 0; //intialize decimalNumber to 0
    for (int *ptr = binArray; ptr < binArray + NUMBER_OF_BITS; ++ptr) { //iterate through the array
        decimalNumber = decimalNumber * 2 + *ptr; // calculate the decimal number from the binary array
    }
    return decimalNumber;
}

int* convertDectoHex(int num, int *hexArray) {
    for (int *ptr = hexArray; ptr < hexArray + NUMBER_OF_BITS; ++ptr) { // initialize the binary array to all zeros
        *ptr = 0;
    }
    int hexChars[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // define hexadecimal characters as integers
    int *ptr = hexArray + NUMBER_OF_HEX_DIGITS - 1; // pointer to the end of the hexArray (the last integer)
    while (num > 0) { // convert the decimal number to hexadecimal and store as integers
        *ptr = hexChars[num % 16];  // get the corresponding hex digit as an integer
        num = num / 16; 
        ptr--;  // move the pointer to the previous element of the array
    }
    return hexArray;
}

int convertHextoDec(int *hexArray) {
    int decimalNumber = 0; //initialize decimalNumber to 0
    int *ptr = hexArray; //create pointer to start of hexArray
    for (int i = 0; i < NUMBER_OF_HEX_DIGITS; i++) { //iterate through the array
        decimalNumber = decimalNumber * 16 + *ptr; //calculate decimal value 
        ptr++; //move pointer to next element of the array
    }
    return decimalNumber;
}

void printDectoBin(int decimalNumber, int* result) {
    printf("Binary representation of %d: ", decimalNumber);
    printMyBinaryNum(result);
    printf("\n");
}

void printBintoDec(int* binaryNumberArray, int convertedDecimal) {
    printf("Decimal Representation of ");
    printMyBinaryNum(binaryNumberArray);
    printf(": %d", convertedDecimal);
    printf("\n");
}

void printDectoHex(int decimalNumber2, int* result) {
    printf("Hexadecimal representation of %d: ", decimalNumber2);
    printMyHexNum(result);
    printf("\n");
}

void printHextoDec( int* hexArrayToConvert, int decimalNum) {
    printf("Decimal Representation of ");
    printMyHexNum(hexArrayToConvert);
    printf(": %d", decimalNum);
    printf("\n");
}

#endif