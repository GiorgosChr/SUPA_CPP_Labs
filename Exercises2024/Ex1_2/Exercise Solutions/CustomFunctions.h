#pragma once


void readFromFile(const std::string& pathToFile, std::vector<std::vector<float>>& data);


void printFromFile(const std::vector<std::vector<float>>& data, const int& nLines);


void getMagnitude(const std::vector<std::vector<float>>& data, std::vector<float>& magnitude);


void leastSquares(const std::vector<std::vector<float>>& data, const std::vector<std::vector<float>>& error, std::string& fitFunction);


// Define overloads for printing

void print(const std::vector<float>& data, const std::string& pathToFile);

void print(const std::vector<float>& data, const int& nLines, const std::string& pathToFile);

void print(const std::vector<std::vector<float>>& data, const std::string& pathToFile);

void print(const std::vector<std::vector<float>>& data, const int& nLines, const std::string& pathToFile);

void print(const std::string& fitFunction, const float& reducedChiSquared, const std::string& pathToFile);

// Calculate power without pow function
float power(float x, int y);
void getVectorPower(const std::vector<std::vector<float>>& data, std::vector<float>& result);