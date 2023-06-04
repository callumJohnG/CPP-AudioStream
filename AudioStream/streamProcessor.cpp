#include "streamProcessor.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

StreamProcessor::StreamProcessor(double audioScalar)
{
    this->audioScalar = audioScalar;
}

// Need to pass in block size before array is passed in cause it decays into a pointer
void StreamProcessor::PushBlock(double block[], int size)
{
    for (int i = 0; i < size; i++)
    {
        double sample = block[i];
        lock_guard<mutex> lock(queueMutex); // Lock starts here
        sampleQueue.push(sample);
    } // Lock ends here
}

void StreamProcessor::ProcessSamples()
{
    // wait 100 milliseconds before processing/outputting to create a delay
    this_thread::sleep_for(chrono::milliseconds(100));

    while (true)
    {
        // Wait if there are no samples to process in the queue
        if (sampleQueue.size() == 0)
        {
            continue;
        }

        // Pop the next sample and process it
        double sample;

        // if(true) {//Scope limit the lock
        {
            lock_guard<mutex> lock(queueMutex);
            sample = sampleQueue.front();
            sampleQueue.pop();
        } // Lock ends here?

        ProcessSample(sample);
    }
}

void StreamProcessor::ProcessSample(double sample)
{
    // Multiply (scale) the sample by the processors scale factor
    double scaledSample = sample * audioScalar;
    sampleCounter++;

    // Final output of the sample
    cout << "Sample " << sampleCounter << ", " << scaledSample << endl;
}