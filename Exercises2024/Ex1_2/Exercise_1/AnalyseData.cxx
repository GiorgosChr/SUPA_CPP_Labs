/*
    Exercise 1 Georgios Christou
*/

#include "myFunctions.h"

#include <string>
#include <iostream>

int main() {
    const std::string pathToData  = "../input2D_float.txt";
    const std::string pathToError = "../error2D_float.txt";

    int printN = 150;

    std::cout << "Part 1:" << std::endl;
    printNLines(pathToData, printN);

    std::cout << "Part 2:" << std::endl;
    calculateMagnitude(pathToData);

    std::cout << "Part 3:" << std::endl;
    chiSquareTest(pathToData, pathToError);

    std::cout << "Part 4:" << std::endl;
    calculatePower(pathToData);

    return 0;
}