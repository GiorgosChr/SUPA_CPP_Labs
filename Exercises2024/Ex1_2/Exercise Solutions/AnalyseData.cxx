// Georgios Christou 25/11/2024

#include <string>
#include <vector>
#include <iostream>
#include <limits>

# include "CustomFunctions.h"

int main() {

    const std::string pathToData  = "../input2D_float.txt";
    const std::string pathToError = "../error2D_float.txt";

    // We choose vector of vector of floats to store the data
    // [0] -> x
    // [1] -> y
    std::vector<std::vector<float>> data;
    std::vector<std::vector<float>> error;

    std::vector<float> magnitude;

    std::string userOption;
    int nLines;

    std::string fitFunction;
    float reducedChiSquared;
    readFromFile(pathToData, data);
    readFromFile(pathToError, error);

    while (true) {
        std::cout << "Which function would you like to use?" << std::endl;
        std::cout << "[1]\tPrint n data" << std::endl;
        std::cout << "[2]\tCalculate vector magnitude" << std::endl;
        std::cout << "[3]\tLeast squares fit" << std::endl;
        std::cout << "[4]\tCalculate x^y" << std::endl;
        while(true) {
            std::cin >> userOption;
            if (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4") {
                std::cerr << "Invalid option. Please try again." << std::endl;
                std::cin.clear();
            
                // Discard invalid input from the buffer
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
        if (userOption == "1") {
            std::string fileName = "output1.txt";
            std::cout << "How many lines would you like to print?" << std::endl;
            std::cin >> nLines;
            print(data, nLines, fileName);
        }

        else if (userOption == "2") {
            std::string fileName = "output2.txt";
            getMagnitude(data, magnitude);
            print(magnitude, fileName);
        }

        else if (userOption == "3") {
            std::string fileName = "output3.txt";
            leastSquares(data, error, fitFunction, reducedChiSquared);
            print(fitFunction, reducedChiSquared, fileName);
        }

        else if (userOption == "4") {
            std::string fileName = "output4.txt";
            std::vector<float> result;
            getVectorPower(data, result);
            print(result, fileName);
        }

        std::cout << "Would you like to perform another operation? [y/n]" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> userOption;
        if (userOption == "n") break;

    }
    return 0;
}