/*
    Georgios Christou
    27 Nov 2024
*/

#include "FiniteFunctions.h"

#include <string>
#include <vector>
#include <fstream>

int main() {

    const std::string pathToData = "./Outputs/data/MysteryData13330.txt";
    const std::string output = "./output.png";
    const double range_min = -5.0;
    const double range_max = 5.0;
    /*
    In order to plot the data we need to make use of the plotData
    member function of the class. Firstly, we need to read the data
    from the file and store them in a vector of doubles.
    To plot the function we can use the plotFunction member function.
    */
    FiniteFunction myFunctionClass;
    myFunctionClass.setRangeMin(range_min);
    myFunctionClass.setRangeMax(range_max);
    myFunctionClass.plotFunction();
    
    std::ifstream dataFile(pathToData);
    std::vector<double> data;
    
    double value;
    while (dataFile >> value) {
        data.push_back(value);
    }
    
    
    myFunctionClass.plotData(data, 50);

    dataFile.close();
    return 0;
}