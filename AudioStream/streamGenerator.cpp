#include <iostream>
#include <iomanip>
#include <limits>
#include <complex>
#include"streamGenerator.h"

StreamGenerator::StreamGenerator(){
    cout << "Generator Online..." << endl;
}

double StreamGenerator::GenerateSample(double time){
    return sin(time * twoPi);
}

const double StreamGenerator::twoPi = ::atan(1) * 8.0;