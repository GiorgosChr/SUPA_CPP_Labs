/*
Georgios Christou 
09 Dec 2024
*/

# pragma once

#include <random>
#include <vector>
#include <cmath>

/*
In order to calculate pi we can think of the ratio of
the area of the circle to the area of the square.

Each side of the square is 2R, so the area of the square
is 4R^2. The area of the circle is pi*R^2.

Thus, the ratio should be pi/4. If we randomly sample
points in the square, the ratio of points in the circle
to the total number of points should be pi/4.

To make the problem easier, we can consider only the 
first quadrant of the circle. The area  of the first
quadrant of the circle is 1/4 * pi*R^2. The area of the
first quadrant of the square is R^2. So again, the 
ratio should be pi/4.
*/

class CalculatePi {
    public :
        // Constructor Overloading
        // Default values for the number of points and the radius is 1000 and 1.0 respectively
        CalculatePi();
        CalculatePi(int Npoints);
        CalculatePi(int Npoints, double R);

        // Setters
        void setNpoints(int Npoints);
        void setRadius(double R);
        void setParameters(int Npoints, double R);

        // Getters
        int getNpoints();
        double getRadius();

        // Calculate the value of pi
        void calculatePi();

    private:
        int m_Npoints;
        double m_R;
        double m_pi;
        double realPi = M_PI;
        int counterInCircle;
        
        // Random number generator
        std::mt19937 mtEngine{1234};

        // Function for first quadrant of the circle
        double circleFunction(double x);

        // Function to check if a point is inside the circle
        bool isInsideCircle(double x, double y);

};