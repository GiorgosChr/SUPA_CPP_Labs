/*
Georgios Christou
09 Dec 2024
*/

#include "CustomClass.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <arg1> <arg2>" << std::endl;
        return 1;
    }

    int intArg = std::stoi(argv[1]);
    double doubleArg = std::stod(argv[2]);

    CalculatePi myPiClass(intArg, doubleArg);
    myPiClass.calculatePi();

    return 0;
}