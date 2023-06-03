#include <iostream>
#include <iomanip>
#include <limits>
#include <complex>
#include"streamGenerator.h"

double StreamGenerator::GenerateSample(double time){
    return sin(time * twoPi);
}

const double StreamGenerator::twoPi = ::atan(1) * 8.0;