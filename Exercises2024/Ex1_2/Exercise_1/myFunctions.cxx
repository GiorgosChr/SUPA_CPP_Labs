#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector> 

void printNLines(const std::string& fileName, const int& numberOfLines){
    std::ifstream file(fileName);    
    std::ofstream output("./part1.txt");

    // check if the file has opened correctly
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    int counter = 0;
    float x;
    float y;
    char comma;

    std::string line;
    std::getline(file, line); // skip the first line

    while(((counter < numberOfLines) && (getline(file, line)))){
        // This might be too much for just printing, but will be useful for accessing
        // x and y for the following exercises
        std::istringstream lineStream(line);

        if (lineStream >> x >> comma >> y && comma == ','){
            std::cout << "x: " << x << "\t" << "y: " << y << std::endl;
            output << "x: " << x << "\t" << "y: " << y << std::endl;
        }
        counter++;
    }

    // Close files
    file.close();
    output.close();
}

void calculateMagnitude(const std::string& fileName){
    std::ifstream file(fileName);
    std::ofstream output("./part2.txt");

    // check if the file has opened correctly
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    float x;
    float y;
    char comma;

    std::string line;
    std::getline(file, line); // skip the first line

    while(getline(file, line)){
        std::istringstream lineStream(line);

        if (lineStream >> x >> comma >> y && comma == ','){
            float magnitude = sqrt(x*x + y*y);
            std::cout << "x: " << x << "\t" << "y: " << y << "\t\t" << "magnitude: " << magnitude << std::endl;
            output << "x: " << x << "\t" << "y: " << y << "\t\t" << "magnitude: " << magnitude << std::endl;
        }
    }

    // Close files
    file.close();
    output.close();
}

void chiSquareTest(const std::string& fileName, const std::string& errorFileName){
    std::ifstream file(fileName);
    std::ifstream errorFile(errorFileName);
    std::ofstream output("./part3.txt");

    float x;
    float y;
    float xError;
    float yError;
    float error;
    char comma;

    float sumX  = 0.;
    float sumY  = 0.;
    float sumXY = 0.;
    float sumX2 = 0.;

    std::vector<float> xVec;
    std::vector<float> yVec;
    std::vector<float> errorVec;

    std::string line;
    std::string lineError;
    std::getline(file, line);
    std::getline(errorFile, lineError);

    while(getline(file, line) && getline(errorFile, lineError)){
        std::istringstream lineStream(line);
        std::istringstream lineErrorStream(lineError);

        if (lineStream >> x >> comma >> y && comma == ',' && lineErrorStream >> xError >> comma >> yError && comma == ','){
            error = sqrt(xError*xError + yError*yError);
            sumX  += x;
            sumY  += y;
            sumXY += x*y;
            sumX2 += x*x;

            xVec.push_back(x);
            yVec.push_back(y);
            errorVec.push_back(error);
        }
    }

    auto nEntries = xVec.size();
    auto p = (nEntries * sumXY - sumX * sumY)/(nEntries * sumX2 - sumX * sumX);
    auto q = (sumX2 * sumY - sumXY * sumX)/(nEntries * sumX2 - sumX * sumX);

    float chiSquare = 0.;
    for (int i = 0; i < nEntries; i++){
        chiSquare += pow((yVec[i] - (p*xVec[i] + q))/errorVec[i], 2);
    }

    std::cout << "χ^2: " << chiSquare << "\tχ^2/Ndof: " << chiSquare/2. <<std::endl;
    output << "χ^2: " << chiSquare << "\tχ^2/Ndof: " << chiSquare/2. <<std::endl;

    // Close files
    file.close();
    errorFile.close();
    output.close();
}

void calculatePower(const std::string& fileName){
    // essentially pow(a, b) = exp(b * log(a))
    std::ifstream file(fileName);
    std::ofstream output("./part4.txt");

    float x;
    float y;
    char comma;
    float result;

    std::string line;
    std::getline(file, line);

    while(getline(file, line)){
        std::istringstream lineStream(line);

        if (lineStream >> x >> comma >> y && comma == ','){
            result = exp(y * log(x));
            auto trueResult = pow(x, y);
            std::cout << "x: " << x << "\t" << "y: " << y << "\t\t" << "result: " << result << "\ttrue value:\t" << trueResult << std::endl;
            output << "x: " << x << "\t" << "y: " << y << "\t\t" << "result: " << result << "\ttrue value:\t" << trueResult << std::endl;
        }
    }
}