#include <iostream>
#include <string>
#include <queue>
using namespace std;

class StreamProcessor{
    private:
        double audioScalar;
        queue<double> sampleQueue;
        int sampleCounter = 0;
        void ProcessSample(double sample);
    public :
        StreamProcessor(double audioScalar);
        void ProcessSamples();
        void PushBlock(double block[], int size);
};