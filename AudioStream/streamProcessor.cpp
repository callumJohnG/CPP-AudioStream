#include"streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <mutex>
using namespace std;

StreamProcessor::StreamProcessor(double audioScalar){
    this->audioScalar = audioScalar;
}

//Need to pass in block size before array is passed in cause it turns into a pointer reference
void StreamProcessor::PushBlock(double block[], int size){
    //cout << "New block recieved" << endl;
    for(int i = 0; i < size; i++){
        double sample = block[i];

        lock_guard<mutex> lock(queueMutex);
        
        sampleQueue.push(sample);
    }
    //cout << sampleQueue.size() << "----------" << endl;
}

void StreamProcessor::ProcessSamples(){
    //wait 100 milliseconds before processing/outputting
    std::this_thread::sleep_for(chrono::milliseconds(100));

    while(true){

        if(sampleQueue.size() == 0){
            //cout << sampleQueue.size() << endl;
            continue;
        }

        //cout << "Popping block and processing it" << endl;

        //Pop the next sample and process it
        double sample;

        //if(true) {//Scope limit the lock
        {
            lock_guard<mutex> lock(queueMutex);
            sample = sampleQueue.front();
            sampleQueue.pop();
        }//Lock ends here?

        ProcessSample(sample);

    }
}

void StreamProcessor::ProcessSample(double sample){
    //Multiply (scale) the sample by the processors scale factor
    double scaledSample = sample * audioScalar;
    sampleCounter++;

    //Final output of the sample
    cout << "Sample " << sampleCounter << ", " << scaledSample << endl;
}