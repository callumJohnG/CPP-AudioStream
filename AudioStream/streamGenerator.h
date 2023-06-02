#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <complex>
using namespace std;

class StreamGenerator{
    public :
        StreamGenerator();
        double GenerateSample(double time);
        static const double two_pi;

};