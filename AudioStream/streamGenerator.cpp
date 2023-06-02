#include <iostream>
#include <iomanip>
#include <limits>
#include <complex>
#include"streamGenerator.h"

StreamGenerator::StreamGenerator(){
    cout << "Generator Online..." << endl;
}

double StreamGenerator::GenerateSample(double time){
    return sin(time * two_pi);
}

const double StreamGenerator::two_pi = ::atan(1) * 8.0;