#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

void readFromFile(const std::string& pathToFile, std::vector<std::vector<float>>& data) {
    std::ifstream inputFile(pathToFile);
    float x;
    float y;
    char comma;

    std::string line;
    std::getline(inputFile, line); // skip the first line

    while(getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::vector<float> tempVector;

        lineStream >> x >> comma >> y;
        tempVector.push_back(x);
        tempVector.push_back(y);
        data.push_back(tempVector); // Now the data vector has the x and y values
    }

    inputFile.close();
}

void printFromFile(const std::vector<std::vector<float>>& data, const int& nLines, const std::string& pathToFile) {
    if (nLines > data.size()) {
        std::cerr << "Warning: Requested number of lines exceeds available data. Printing only 5 lines." << std::endl;
        
        for (int i = 0; i < 5; i++) {
            std::cout << "x: " << data[i][0] << "\t" << " y: " << data[i][1] << std::endl;
        }
    }
    else {
        for (int i = 0; i < nLines; i++) {
            std::cout << "x: " << data[i][0]  << "\t" << " y: " << data[i][1] << std::endl;
        }
    }
}

// Overloads for printing

void print(const std::vector<float>& data, const std::string& pathToFile) {
    std::ofstream file(pathToFile);
    for (const auto& value : data) {
        std::cout << value << std::endl;
        file << value << std::endl;
    }
    file.close();
}

void print(const std::vector<float>& data, const int& nLines, const std::string& pathToFile) {
    std::ofstream file(pathToFile);

    if (nLines > data.size()) {
        std::cerr << "Warning: Requested number of lines exceeds available data. Printing only 5 lines." << std::endl;

        file << "Warning: Requested number of lines exceeds available data. Printing only 5 lines." << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << data[i] << std::endl;
            file << data[i] << std::endl;
        }
    }
    else {
        for (int i = 0; i < nLines; i++) {
            std::cout << data[i] << std::endl;
            file << data[i] << std::endl;
        }
    }
    file.close();
}

void print(const std::vector<std::vector<float>>& data, const std::string& pathToFile) {
    std::ofstream file(pathToFile);

    for (const auto& vectorPair : data) {
        std::cout << "x: " << vectorPair[0] << "\t" << " y: " << vectorPair[1] << std::endl;
        file << "x: " << vectorPair[0] << "\t" << " y: " << vectorPair[1] << std::endl;
    }
    file.close();
}

void print(const std::vector<std::vector<float>>& data, const int& nLine, const std::string& pathToFile) {
    std::ofstream file(pathToFile);

    if (nLine > data.size()) {
        std::cerr << "Warning: Requested number of lines exceeds available data. Printing only 5 lines." << std::endl;
        file << "Warning: Requested number of lines exceeds available data. Printing only 5 lines." << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "x: " << data[i][0] << "\t" << " y: " << data[i][1] << std::endl;
            file << "x: " << data[i][0] << "\t" << " y: " << data[i][1] << std::endl;
        }
    }
    else {
        for (int i = 0; i < nLine; i++) {
            std::cout << "x: " << data[i][0]  << "\t" << " y: " << data[i][1] << std::endl;
            file << "x: " << data[i][0]  << "\t" << " y: " << data[i][1] << std::endl;
        }
    }
    file.close();
}

void print(const std::string& fitFunction, const float& reducedChiSquared, const std::string& pathToFile) {
    std::ofstream file(pathToFile);

    std::cout << fitFunction << std::endl;
    std::cout << "χ^2/Ndof = " << reducedChiSquared << std::endl;

    file << fitFunction << std::endl;
    file << "χ^2/Ndof = " << reducedChiSquared << std::endl;
    file.close();
}

void getMagnitude(const std::vector<std::vector<float>>& data, std::vector<float>& magnitude) {
    for (const auto& vectorPair : data) {
        auto magn = sqrt(pow(vectorPair[0], 2) + pow(vectorPair[1], 2));
        magnitude.push_back(magn);
    }
}

void leastSquares(const std::vector<std::vector<float>>& data, const std::vector<std::vector<float>>& error, std::string& fitFunction) {
    float sumX = 0;
    float sumY = 0;
    float sumXY = 0;
    float sumX2 = 0;

    for (const auto& vectorPair : data) {
        sumX += vectorPair[0];
        sumY += vectorPair[1];
        sumXY += vectorPair[0] * vectorPair[1];
        sumX2 += pow(vectorPair[0], 2);
    }

    float n = data.size();
    float p = (n * sumXY - sumX * sumY) / (n * sumX2 - pow(sumX, 2));
    float q = (sumX2 * sumY - sumXY * sumX) / (n * sumX2 - pow(sumX, 2));

    // Calculation of reduced χ^2
    float chiSquared = 0;
    for (int i = 0; i < data.size(); i++) {
        float observed = data[i][1];
        float expected = p * data[i][0] + q;
        float sigma = error[i][1];

        chiSquared += pow((observed - expected) / sigma, 2);
    }
    
    int degreesOfFreedom = data.size() - 2;
    float reducedChiSquared = chiSquared / static_cast<float>(degreesOfFreedom);

    std::ostringstream stream;
    stream.precision(2); // Set the number of decimal points

    stream << std::fixed << "y = " << p << " * x + " << q;
    fitFunction = stream.str();
}


float power(float x, int y) {
    if (y == 0) return 1.0f;

    if (y < 0) return 1 / power(x, -y);

    return x * power(x, y - 1);
}

void getVectorPower(const std::vector<std::vector<float>>& data, std::vector<float>& result) {
    for (const auto& pairVec : data) {
        auto x = pairVec[0];
        auto y = pairVec[1];
        y = static_cast<int>(round(y));
        result.push_back(power(x, y));
    }
}