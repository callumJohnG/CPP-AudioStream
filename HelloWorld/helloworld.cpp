#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "I am learning C++" << endl;
    cout << "Hi" << endl;


    int myNum = 15;  // myNum is 15
    myNum = 10;  // Now myNum is 10
    cout << myNum << endl;  // Outputs 10

    cout << "Hi, I am " << (myNum + 1) << " years old next year" << endl;

    int x = 1, y = 2, z = 3;

    cout << "3 little numbers sitting in a tree, " << x << " " << y << " " << z << " pee pee" << endl;

    int age;
    cout << "Enter age:" << endl;
    cin >> age;
    if (age < 18)
    {
        cout << "You are poopy baby" << endl;
    } else {
        cout << "Ok you old as hell boy" << endl;
    }
    
    int num1, num2;
    cout << "Enter num 1:" << endl;
    cin >> num1;
    cout << "Enter num 2:" << endl;
    cin >> num2;
    int sum = num1 + num2;
    cout << "Sum is :" << sum << endl;

    sum++;

    cout << "Sum + 1 is :" << sum << endl;

    return 0;
}