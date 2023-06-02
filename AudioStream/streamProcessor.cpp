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

void StreamProcessor::PushBlock(double block[], int size){
    cout << "New block recieved" << endl;
    for(int i = 0; i < size; i++){
        double sample = block[i];
        sampleQueue.push(sample);
    }
}

void StreamProcessor::ProcessSamples(){
    cout << "Starting to process" << endl;
    while(true){

        if(sampleQueue.size() == 0){
            cout << "Nothing to process" << endl;
            continue;
        }

        //Pop the next sample and process it
        double sample = sampleQueue.front();
        sampleQueue.pop();
        ProcessSample(sample);

    }
}

void StreamProcessor::ProcessSample(double sample){

    double scaledSample = sample * audioScalar;
    sampleCounter++;

    cout    << sampleCounter << ", "
            << std::fixed
            << std::showpos
            //<< std::setprecision(std::numeric_limits<double>::digits10 - 1)
            << scaledSample
            << endl;

}