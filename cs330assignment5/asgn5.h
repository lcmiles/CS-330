#ifndef __asgn5__
#define __asgn5__
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* the two lines above check to ensure
we haven't already included this header*/



/* Counts the number of characters in a string array
      Does not count the null character at the end
   Takes a pointer to an array of chars as input
      Assumes the string is properly formatted with a null char at the end
   returns the size (an int)
*/
int sizeOfString(char *arr){
    int numOfChars = 0;             /* variable to hold number of chars in this string */
    int index = 0;                  /* not necessary, could just use numOfChars, but just making it obvious */
    while(*(arr+index) != '\0'){    /* loop through the array until null char */
        numOfChars++;               /* increase the count by 1 */
        index++;                    /* increment index to get ready for the next loop */
    }
    return numOfChars;
}

/* ========================================================================= */
/* your functions go here */
// Note: main() goes in the asgn2.c file

/*
Desc: Uses pointer arithmetic to convert a string to an int
Parameters:
char* str - The string that the function converts to an int
Returns:
int result - The integer represntation of the input string
Sources:
https://www.geeksforgeeks.org/c-program-to-write-your-own-atoi/
*/
int atoi_cs330(char* str) {

    int result = 0; //initialize result integer variable

    int sign = 1; //initialize sign integer variable to positive by default, -1 if negative

    if (*str == '\0') { //if the input string is empty
        return 0; //returns 0
    }

    if (*str == '-') { //if the first character in the string is '-'
        sign = -1; //sets sign variable to -1
        str++; //forward iterates the pointer to the next character
    }

    while (*str >= '0' && *str <= '9') { //iterates through the string while the characters are digits 0-9
        result = result * 10 + (*str - '0'); //multiply the current result by 10 and add the numeric value of the current digit
        str++; //forward iterate pointer
    }

    return sign * result; //multiply the final result by the sign integer and return it

}

/*
Desc: Uses pointer arithmetic to reverse the input string
Parameters:
char* str - The string that the function reverses
Returns:
char* str - The reversed string
Sources:
https://www.geeksforgeeks.org/implement-itoa/
*/
void reverse(char* start, char* end) {
    char temp; //initialize temp variable to hold chars during swap
    while (start < end) { //reverse characters while the start pointer is less than the end pointer
        temp = *start; //store the char at the start pointer in temp
        *start = *end; //set the char at start pointer to the char at the end pointer
        *end = temp; //set the char at the end pointer to the char stored stored in temp
        start++; //forward iterate start pointer
        end--; //backward iterate end pointer
    }
}

/*
Desc: Uses pointer arithmetic to convert an integer to a string
Parameters:
int num - The integer the the function converts to a string
Returns:
char* str - The string representation of the integer
Sources:
https://www.geeksforgeeks.org/implement-itoa/
*/
char* itoa_cs330(int num, int base) {

    bool isNegative = false; //initialize the isNegative boolean to false by default

    if (num == 0) { //if the number is 0
        char* str = (char*)malloc(1); // Allocate memory for '\0'
        if (str == NULL) { // Handle memory allocation failure
            return NULL;
        }
        *str = '\0'; //set the string to be empty
        return str; //return empty string
    }

    if (num < 0 && base == 10) { //if the number negative and the base is 10 (decimal) 
        isNegative = true; //set negative to true
        num = -num; //convert it to a positive number for further processing
    }

    int numDigits = 0; //initialize the digit counter variable
    int temp = num; //initialize the temp veriable to the input number

    while (temp != 0) { //loop until the number is 0
        numDigits++; //iterate digit counter foward
        temp /= base; //divide the number by base to proceed to next digit
    }

    int totalDigits = numDigits + (isNegative ? 1:0); //calculate the total number of digits
    char* str = (char*)malloc(totalDigits + 1); //allocate memory for the string and '\0'

    if (str == NULL) { //handle memory allocation failure
        return NULL;
    }

    char* start = str; //store the starting address of the string

    while (num != 0) {
        int rem = num % base; //calculate remainder when divided by the base
        *str = (rem > 9) ? (rem - 10) + 'a' : rem + '0'; //convert the remainder to character
        str++; //forward iterate the string pointer
        num = num / base; //divide the number by the base to proceed to next digit
    }

    if (isNegative) { //if the number triggered the isNegative flag
        *str = '-'; //add the '-' character
        str++; //forward iterate the string pointer
    }

    *str = '\0'; //null-terminate the resulting string
    reverse(start, str - 1); //reverse the characters in the string
    return start; //return the pointer at the beginning of the string
}

// nothing below this line
#endif