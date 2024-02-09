#ifndef __asgn2__
#define __asgn2__
#include<stdio.h>
#include<math.h>
#include<string.h>

/* the two lines above check to ensure
we haven't already included this header*/


/* your functions go here */
// Note: main() goes in the asgn2.c file


/*
Description: This function iterates through every integer 
*/
void cubeOfOdd(int n){
    for (int i = 0; i < n; i++) {
        if (i%2 ==! 0) {
            int nCubed = pow(i,3);
            printf("%d\n",nCubed);
        }
    }
    return;
}

int isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0 && i != n) {
            return 0;
        }
    }
    return 1;
}

void introToCS330(int n) {
    if ((n%7 == 0) && (n%3 == 0)) {
        printf("UAB CS 330\n");
    }
    else if (n%7 == 0) {
        printf("UAB\n");
    }
    else if (n%3 == 0) {
        printf("CS\n");
    }
    else if ((n != 7) && (n != 3) && (isPrime(n) == 1)) {
        printf("Go Blazers\n");
    }
    else {
        int nCubed = pow(n,3);
        printf("%d\n",nCubed);
    }
}

void printHello(int n) {
    char str[100] = "";
    for (int i = 0; i <= n; i++) {
        char current[50];
        sprintf(current, "%d", i);
        if ((i != 0) && ((i &(i - 1)) == 0)) {
            strcat(str, "HELLO");
        }
        else strcat(str, current);
    }
    printf("%s\n", str);
}

int paintGallons(float length, float width, float height) {
    float fbWalls = length * height;
    float lrWalls = width * height;
    float ceiling = width * length;
    float total = 2 * fbWalls + 2 * lrWalls + ceiling;
    int gallons = ceil(total/400);
    printf("%d\n", gallons);
    return gallons;
}

void grader(float avg_exams, float avg_hw, int attendance) {
    if ( (attendance > 20) && (avg_exams > 70) && (avg_hw > 70) && ((avg_exams > 85) || (avg_hw > 85))) {
        printf("PASS\n");
    }
    else printf("FAIL\n");
}

#endif