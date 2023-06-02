#include <iostream>
#include <string>
#include <queue>
using namespace std;

class StreamProcessor{
    private:
        double audioScalar;
        queue<double[]> blockQueue;
    public :
        StreamProcessor(double audioScalar);
        void ProcessSampleBlock(double block[]);
        void PushBlock(double block[]);
};