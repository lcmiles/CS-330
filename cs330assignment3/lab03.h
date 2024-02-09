#ifndef __lab03__
#define __lab03__

/* the two lines above check to ensure
we haven't already included this header*/


/* your functions go here */


/*
Description: This function prints the Collatz sequence 
Arguments: n represents the integer input that the function will print the Collatz sequence for
Returns: nothing
*/
void printCollatz(int n) {
    printf("%d", n)
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = 3 * n + 1;
        }
    }
    return;
}




#endif