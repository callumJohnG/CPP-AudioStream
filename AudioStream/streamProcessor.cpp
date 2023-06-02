#include"streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
using namespace std;

StreamProcessor::StreamProcessor(double audioScalar){
    this->audioScalar = audioScalar;
    cout << "Processor Online..." << endl;
}

void StreamProcessor::PushBlock(double block[]){
    blockQueue.push(block);
}

void StreamProcessor::ProcessSampleBlock(double block[]){
    cout << "New batch recieved" << endl;
    for(int i = 0; i < (sizeof(*block) / sizeof(double)); i++){
        cout << "New Sample" << endl;
        double sample = block[i];

        double scaledSample = sample * audioScalar;

        cout    << i << ", "
                << std::fixed
                << std::showpos
                //<< std::setprecision(std::numeric_limits<double>::digits10 - 1)
                << scaledSample
                << endl;
    }
}