#include <iostream>
#include <string>
#include "streamGenerator.h"
#include "streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
using namespace std::chrono;

int main(){
    //Create the processor and the generator
    StreamGenerator sineGenerator;
    const float audioScalar = 2.1;
    StreamProcessor sampleProcessor(audioScalar);

    const int frequency = 48000;
    const int blockSize = 480;
    int sampleCounter = 0;

    //const double blockTime = 0.01;
    const milliseconds blockTime = milliseconds(100);//one block every 0.01 seconds = 48000 samples/second
    


    //Start the processor
    //sampleProcessor.StartProcessing();
    //thread processorThread(StreamProcessor::ProcessSamples, sampleProcessor);
    thread processorThread(&StreamProcessor::ProcessSamples, &sampleProcessor);
    processorThread.detach();
    
    //Begin generation/processing loop
    while(true){
        time_t startTime = time(0);
        //cout << startTime << " Time" << endl;

        double sampleBlock[blockSize];

        for(int i = 0; i < blockSize + 1; i++)
        {
            //Calculate next sample point
            double x = (static_cast<double>(i + sampleCounter) / frequency);
            double sample = sineGenerator.GenerateSample(x);
            //cout << sample << endl;
            sampleBlock[i] = sample;
        }
        sampleCounter += blockSize;

        //Send the block to the processor
        sampleProcessor.PushBlock(sampleBlock, blockSize);
        //thread pushThread(StreamProcessor::PushBlock, sampleProcessor, sampleBlock, blockSize);
        //pushThread.join();
        

        //wait until 1/100 of a second has passed (attempt to cap generation speed at 48000/second)
        time_t endTime = time(0);
        time_t elapsedTime = endTime - startTime;
        milliseconds waitTime = blockTime - seconds(elapsedTime);
        //cout << "End Time : " << endTime << endl;
        //cout << "elapsed time : " << elapsedTime << endl;
        //cout << "s:" << startTime << " e:" << endTime << endl; 
        if(waitTime > milliseconds::zero()){
            //cout << "Sleeping for " << (waitTime) << endl;
            this_thread::sleep_for(waitTime);
        }
    }

    return 0;
}