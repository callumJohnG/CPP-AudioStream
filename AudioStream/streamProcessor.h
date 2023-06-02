#include <iostream>
#include <string>
#include <queue>
#include <mutex>
using namespace std;

class StreamProcessor{
    private:
        double audioScalar;
        queue<double> sampleQueue;
        int sampleCounter = 0;
        void ProcessSample(double sample);
        mutex queueMutex;
    public :
        StreamProcessor(double audioScalar);
        void ProcessSamples();
        void PushBlock(double block[], int size);
};