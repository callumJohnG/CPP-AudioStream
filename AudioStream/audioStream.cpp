#include <iostream>
#include <string>
#include "streamGenerator.h"
#include "streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;

int main(){
    cout << "Hello world..." << endl;

    StreamProcessor sampleProcessor(1.5);

    StreamGenerator sineGen;

    const int frequency = 48000;

    const int blockSize = 480;
    int sampleCounter = 0;

    while(true){
        double sampleBlock[blockSize];

        for(int i = 0; i < blockSize + 1; i++)
        {
            double x = (static_cast<double>(i + sampleCounter) / frequency);
            //Wrap around when we surpass frequency limit
            double sample = sineGen.GenerateSample(x);
            //cout << sample << endl;
            sampleBlock[i] = sample;
            /*
            cout    << i + sampleCounter << ", "
                    << std::fixed
                    << std::showpos
                    << std::setprecision(7)
                    << x << ", "
                    << std::setprecision(std::numeric_limits<double>::digits10 - 1)
                    << sample
                    << std::endl;

            
            std::this_thread::sleep_for(std::chrono::milliseconds(0));

            */
        }
        sampleCounter += blockSize;

        //send the batch to the processor
        sampleProcessor.ProcessSampleBlock(sampleBlock);
    }

    

    return 0;
}