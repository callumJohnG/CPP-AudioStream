#include "streamGenerator.h"
#include "streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

int main()
{
    // Create the processor and the generator
    StreamGenerator sineGenerator;
    const double audioScalar = 194;
    StreamProcessor sampleProcessor(audioScalar);

    const int frequency = 48000;
    const int blockSize = 480;
    int sampleCounter = 0;

    // const double blockTime = 0.01;
    const milliseconds blockTime = milliseconds(10); // one block every 0.01 seconds = 48000 samples/second

    // Start the processor
    // thread processorThread(StreamProcessor::ProcessSamples, sampleProcessor);
    thread processorThread(&StreamProcessor::ProcessSamples, &sampleProcessor);
    processorThread.detach(); // Detach since will run indefinately

    // Begin generation/processing loop
    while (true)
    {
        time_t startTime = time(0);

        // Create the next block of samples
        double sampleBlock[blockSize];

        for (int i = 0; i < blockSize + 1; i++)
        {
            // Calculate next sample point based on the frequency of samples/second
            double x = (static_cast<double>(i + sampleCounter) / frequency);
            double sample = sineGenerator.GenerateSample(x);
            sampleBlock[i] = sample;
        }
        sampleCounter += blockSize;

        // Send the block to the processor
        sampleProcessor.PushBlock(sampleBlock, blockSize);
        // thread pushThread(StreamProcessor::PushBlock, sampleProcessor, sampleBlock, blockSize);
        // pushThread.join();

        // wait until 1/100 of a second has passed (attempt to cap generation speed at 48000/second)
        time_t endTime = time(0);
        time_t elapsedTime = endTime - startTime;
        // time_t waitTime = blockTime - elapsedTime;
        milliseconds waitTime = blockTime - seconds(elapsedTime);
        // if(waitTime > 0){
        if (waitTime > milliseconds::zero())
        {
            this_thread::sleep_for(waitTime);
        }
    }

    return 0;
}