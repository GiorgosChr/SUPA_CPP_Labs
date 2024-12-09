#include "CustomClass.h"

#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <iomanip>

// Constructors
CalculatePi::CalculatePi() {
    m_Npoints = 1000;
    m_R = 1.0;
    counterInCircle = 0;
}

CalculatePi::CalculatePi(int Npoints) {
    m_Npoints = Npoints;
    m_R = 1.0;
    counterInCircle = 0;
}

CalculatePi::CalculatePi(int Npoints, double R) {
    m_Npoints = Npoints;
    m_R = R;
    counterInCircle = 0;
}

// Setters
void CalculatePi::setNpoints(int Npoints) {
    m_Npoints = Npoints;
}

void CalculatePi::setRadius(double R) {
    m_R = R;
}

void CalculatePi::setParameters(int Npoints, double R) {
    m_Npoints = Npoints;
    m_R = R;
}

// Getters
int CalculatePi::getNpoints() {
    return m_Npoints;
}

double CalculatePi::getRadius() {
    return m_R;
}

// First quadrant of the circle
double CalculatePi::circleFunction(double x) {
    /*
    x^2 + y^2 = R^2
    Thus, y = +/- sqrt(R^2 - x^2)
    We are only interested in the first quadrant,
    so we take the positive value
    */
    return sqrt(m_R*m_R - x*x);
}

// Check if a point is inside the circle
bool CalculatePi::isInsideCircle(double x, double y) {
    /*
    x and y are the coordinates of the point
    We want to check if for the same x,
    the y is less than the value of the circle function
    */
    return y < circleFunction(x);
}

// Calculate the value of pi
void CalculatePi::calculatePi() {
    // We generate random numbers between 0 and R
    std::uniform_real_distribution<double> dist(0.0, m_R);

    for (int i = 0; i < m_Npoints; i++) {
        double x = dist(mtEngine);
        double y = dist(mtEngine);

        if (isInsideCircle(x, y)) {
            counterInCircle++;
        }
    }

    m_pi = 4.0 * counterInCircle / m_Npoints;

    std::cout << "Calculated value of Pi: " << std::fixed << std::setprecision(10) << m_pi << std::endl;
    std::cout << "Real value of Pi: " << realPi << std::endl;
}