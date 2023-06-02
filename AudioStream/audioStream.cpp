#include <iostream>
#include <string>
#include "streamGenerator.h"
#include "streamProcessor.h"
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main(){
    cout << "Hello world..." << endl;

    StreamGenerator gen;
    StreamProcessor pro;

    double sample1, sample2;

    sample1 = gen.GenerateSample(time(NULL));
    sleep_for(nanoseconds(100000000));
    sample2 = gen.GenerateSample(time(NULL));

    if(sample1 == sample2){
        cout << "Hmm, they are the same" << endl;
    } else {
        cout << "Yippe they are different" << endl;
    }

    return 0;
}