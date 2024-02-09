#include <stdio.h>
#include "asgn5.h"

int atoi_cs330(char* str);

int main() {

    //Test case for "576"
    char input[] = "576";
    int result = atoi_cs330(input);
    printf("The integer representation is %d\n", result);
    
    //Test case for "-576"
    char input2[] = "-576";
    result = atoi_cs330(input2);
    printf("The integer representation is %d\n", result);

    //Test case for "10"
    char input3[] = "10";
    result = atoi_cs330(input3);
    printf("The integer representation is %d\n", result);

    //Test case for "1"
    char input4[] = "1";
    result = atoi_cs330(input4);
    printf("The integer representation is %d\n", result);

    //Test case for """
    char input5[] = "";
    result = atoi_cs330(input5);
    printf("The integer representation is %d\n", result);

    int base = 10; //initialize base numbering system that function will convert to

    //test case for 576
    int num = 576;
    printf("The string representation is %s\n", itoa_cs330(num, base));

    //test case for -576
    num = -576;
    printf("The string representation is %s\n", itoa_cs330(num, base));

    //test case for 10
    num = 10;
    printf("The string representation is %s\n", itoa_cs330(num, base));

    //test case for 1
    num = 1;
    printf("The string representation is %s\n", itoa_cs330(num, base));

    //test case for 0
    num = 0;
    printf("The string representation is %s\n", itoa_cs330(num, base));

    return 0;
}