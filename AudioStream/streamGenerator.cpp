#include"streamGenerator.h"

StreamGenerator::StreamGenerator(){
    cout << "Generator Online..." << endl;
}

double StreamGenerator::GenerateSample(double time){
    return time;
}