#include <stdio.h>
#include "asgn4.h"

int main() {
    int hexArray[NUMBER_OF_HEX_DIGITS]; // initialize hexadecimal array
    int binArray[NUMBER_OF_BITS];  //intialize binary array

    //convert decimal to binary and print
    printDectoBin(0,convertDectoBin(0, binArray));
    printDectoBin(1,convertDectoBin(1, binArray));
    printDectoBin(16,convertDectoBin(16, binArray));
    printDectoBin(255,convertDectoBin(255, binArray));
    printDectoBin(65535,convertDectoBin(65535, binArray));

    //convert binary to decimal and print
    int binaryNumberArray[NUMBER_OF_BITS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printBintoDec(binaryNumberArray,convertBintoDec(binaryNumberArray));
    int binaryNumberArray2[NUMBER_OF_BITS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    printBintoDec(binaryNumberArray2,convertBintoDec(binaryNumberArray2));
    int binaryNumberArray3[NUMBER_OF_BITS] = {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0};
    printBintoDec(binaryNumberArray3,convertBintoDec(binaryNumberArray3));
    int binaryNumberArray4[NUMBER_OF_BITS] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    printBintoDec(binaryNumberArray4,convertBintoDec(binaryNumberArray4));
    int binaryNumberArray5[NUMBER_OF_BITS] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    printBintoDec(binaryNumberArray5,convertBintoDec(binaryNumberArray5));
    

    //convert decimal to hex and print
    printDectoHex(0,convertDectoHex(0,hexArray));
    printDectoHex(1,convertDectoHex(1,hexArray));
    printDectoHex(16,convertDectoHex(16,hexArray));
    printDectoHex(255,convertDectoHex(255,hexArray));
    printDectoHex(65535,convertDectoHex(65535,hexArray));


    //convert hex to decimal and print
    int hexArrayToConvert[NUMBER_OF_HEX_DIGITS] = {0,0,0,0};
    printHextoDec(hexArrayToConvert, convertHextoDec(hexArrayToConvert));
    int hexArrayToConvert2[NUMBER_OF_HEX_DIGITS] = {0,0,0,1};
    printHextoDec(hexArrayToConvert2, convertHextoDec(hexArrayToConvert2));
    int hexArrayToConvert3[NUMBER_OF_HEX_DIGITS] = {11,10,13,12};
    printHextoDec(hexArrayToConvert3, convertHextoDec(hexArrayToConvert3));
    int hexArrayToConvert4[NUMBER_OF_HEX_DIGITS] = {0,0,1,10};
    printHextoDec(hexArrayToConvert4, convertHextoDec(hexArrayToConvert4));
    int hexArrayToConvert5[NUMBER_OF_HEX_DIGITS] = {15,15,15,15};
    printHextoDec(hexArrayToConvert5, convertHextoDec(hexArrayToConvert5));
    return 0;
}
