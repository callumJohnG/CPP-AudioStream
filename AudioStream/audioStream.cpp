#include <iostream>
#include <string>
#include "streamGenerator.h"
#include "streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

int main(){
    cout << "Hello world..." << endl;

    //Create the processor and the generator
    StreamProcessor sampleProcessor(1.5);
    StreamGenerator sineGenerator;

    const int frequency = 48000;
    const int blockSize = 480;
    int sampleCounter = 0;

    //Start the processor
    //sampleProcessor.StartProcessing();
    //thread processorThread(StreamProcessor::ProcessSamples, sampleProcessor);
    thread processorThread(&StreamProcessor::ProcessSamples, &sampleProcessor);
    processorThread.detach();
    //sampleProcessor.ProcessSamples();
    
    while(true){
        double sampleBlock[blockSize];

        for(int i = 0; i < blockSize + 1; i++)
        {
            double x = (static_cast<double>(i + sampleCounter) / frequency);
            double sample = sineGenerator.GenerateSample(x);
            //cout << sample << endl;
            sampleBlock[i] = sample;
        }
        sampleCounter += blockSize;

        //send the block to the processor
        //thread pushThread(StreamProcessor::PushBlock, sampleProcessor, sampleBlock, blockSize);
        //pushThread.join();
        sampleProcessor.PushBlock(sampleBlock, blockSize);
    }

    

    return 0;
}