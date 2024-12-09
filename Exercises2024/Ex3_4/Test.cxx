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
    const double rangeMin = -5.0;
    const double rangeMax = 5.0;
    /*
    In order to plot the data we need to make use of the plotData
    member function of the class. Firstly, we need to read the data
    from the file and store them in a vector of doubles.
    To plot the function we can use the plotFunction member function.
    */

    std::ifstream dataFile(pathToData);
    std::vector<double> data;
    
    double value;
    while (dataFile >> value) {
        data.push_back(value);
    }


    FiniteFunction myFunctionClass;
    myFunctionClass.setRangeMin(rangeMin);
    myFunctionClass.setRangeMax(rangeMax);
    myFunctionClass.plotFunction();
    myFunctionClass.plotData(data, 100, true);
    /*
    For some reason using 50 bins gives me the following error:

    Integral not set, doing it now
    integral: 2.7468, calculated using 10000 divisions
    malloc(): invalid next size (unsorted)
    Aborted (core dumped)

    Perhaps it has to do with the makeHist function.
    */

    // Now doing the same with the custon functions we created
    const std::string outputNormal = "NormalDistribution.png";
    NormalDistribution myNormalClass;
    myNormalClass.setMean(0.0);
    myNormalClass.setSigma(2.0);
    myNormalClass.setOutfile(outputNormal);
    myNormalClass.plotFunction();
    myNormalClass.plotData(data, 100, true);

    // This one matches the data
    const std::string outputCauchy = "CauchyDistribution.png";
    CauchyDistribution myCauchyClass;
    myCauchyClass.setGamma(2.0);
    myCauchyClass.setMean(0.0);
    myCauchyClass.setOutfile(outputCauchy);
    myCauchyClass.plotFunction();
    myCauchyClass.plotData(data, 100, true);


    // I couldn't get the parameters that resemble the distribution
    const std::string outputCB = "CrystalBallDistribution.png";
    CrystalBallDistribution myCBClass;
    myCBClass.setAlpha(0.5);
    myCBClass.setN(1.5);
    myCBClass.setMean(0.5);
    myCBClass.setSigma(2.);
    myCBClass.setOutfile(outputCB);
    myCBClass.plotFunction();
    myCBClass.plotData(data, 100, true);

    const std::string outputFinal = "FinalDistribution.png";
    CauchyDistribution myFinalClass;
    myFinalClass.setGamma(2.0);
    myFinalClass.setMean(0.0);
    myFinalClass.setOutfile(outputFinal);
    myFinalClass.plotFunction();
    myFinalClass.plotData(data, 100, true);
    myFinalClass.sampleFunction(1000000);
    auto samples = myFinalClass.getSamples();
    myFinalClass.plotData(samples, 100, false);

    /*
    I find the metropolis algorithm not working very well.
    I tried various values of the nodmal distribution width,
    and the results were varying from a uniform-like distribution,
    to something resembling a sum of 3 gaussians.
    */

    return 0;
}