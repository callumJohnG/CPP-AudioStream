#include <iostream>
#include <string>
#include <thread>
#include <time.h>
#include <chrono>
#include <queue>
using namespace std;

//Like python, functions need to be declared before (above) they're called
//But to organise code you can declare functions above main and then define them below
//Declaration
void MyFunction();


int Sum(int a, int b = 3){
    return a + b;
}

//You can take in references to the variables
//Similar to "out" in C#
void SwapNums(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}

class MyClass{
    private : //Everything here is private
        int privateNum;

    public : //Everything here is public
        int myNum;
        string myString;

        //Constructor
        MyClass(int myNum, string myString, int privateNum){
            cout << "Im Alive!" << endl;
            this->myNum = myNum;
            this->myString = myString;
            this->privateNum = privateNum;
        }

        void InPrint(){
            cout << myNum << " " << myString << privateNum << endl;
        }
        //Declaration
        //void MyClass::OutPrint();
};

//Definition
// :: = scope resolution operator
/*void MyClass::OutPrint(){
    cout << myNum << " " << myString << privateNum << endl;
}*/


//Inheritance
class Vehicle {
    public :
        string brand = "Ford";
        void Honk(){
            cout << "Honk Honk" << endl;
        }
};

class Car : public Vehicle{
    public:
        string model = "Mustang";
        //Overriding method
        void Honk(){
            cout << "Honky honky" << endl;
        }
};

class Fruit {
    public :
        string name = "Apple";
        void Eat(){
            cout << "Yum yum" << endl;
        }
};

//A class can inherit from more than 1 base class
class PotatoCar : public Car, public Fruit{
    public :
        void DriveAndEat(){
            cout <<" lol" << endl;
        }
};


void ThreadFunction(){
    
    cout << "Thread :)" << endl;
}

int main() {
    /*
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


    float big = 53E12;
    cout << big << endl;

    char a = 65;
    if(a > 66){
        cout << "WOW";
    }

    string greeting = "Hello";
    cout << greeting << endl;

    string greeting2 = greeting.append(" World.");
    greeting2 = greeting2 + "!!!";
    cout << greeting2 << endl;
    greeting2[0] = 'K';
    cout << greeting2 << endl;


    string fullname;
    cout << "Enter your full name :";
    getline(cin, fullname);
    cout << "Your name is : " << fullname << endl;

    int age;
    cout << "How old are you? : ";
    cin >> age;

    switch (age)
    {
    case 18:
        cout << "Hello Sir" << endl;
        break;
    case 19:
        cout << "Hello Ma\'am" << endl;
    default:
        break;
    }
    

    for(int i = 0; i < 10; i++){
        if(i == 4){ continue; }
        else if (i == 7){ break; }
        cout << i << endl;
    }

    string cars[4] = {"car1", "car2", "van", "plane"};
    cars[3] = "Truck";
    cout << cars[3] << endl;
    for(string car : cars){
        cout << car << endl;
    }

    int numbers[3];
    numbers[0] = 1;
    numbers[2] = 3;
    for(int number : numbers){
        //cout << number << endl;
    }

    cout << sizeof(numbers) << endl; // <------- SIZE IN BYTES
    cout << (sizeof(numbers) / sizeof(int)) << endl; // <---------- REAL SIZE
    

    //                             Single struct
    struct{
        int myNum;
        string myString;
    } myStruct;

    myStruct.myNum = 1;
    myStruct.myString = "Hello World!";

    cout << myStruct.myNum << endl;
    cout << myStruct.myString << endl;

    //                          Reusable struct
    struct myDataType {
        int myNum;
        string myString;
    };

    myDataType myVar;
    myVar.myNum = 12;
    myVar.myString = "Goodbye World.";

    cout << myVar.myNum << endl;
    cout << myVar.myString << endl;


    //                          References
    string food = "Pizza";// real variable
    string &meal = food; // reference

    cout << food << endl;
    cout << meal << endl;
    cout << &food << endl; // Memory address    

    //                              Pointers
    string* foodPointer = &food; //Stores memory address of food
    cout << food << endl;
    cout << &food << endl;
    cout << foodPointer << endl;
    cout << *foodPointer << endl; //Gets the value stored in that memory address
    *foodPointer = "Burger"; //Change the value stored at this memory address
    cout << meal << endl; //Changed the original value

    

    MyFunction();
    
    cout << Sum(12, 3) << endl;
    cout << Sum(1,1) << endl;
    cout << Sum(2) << endl;

    int firstNum = 10;
    int secondNum = 20;

    cout << "Before swap: " << "\n";
    cout << firstNum << secondNum << "\n";

    // Call the function, which will change the values of firstNum and secondNum
    SwapNums(firstNum, secondNum);

    cout << "After swap: " << "\n";
    cout << firstNum << secondNum << "\n";

    

    //Create a class and assign to it
    MyClass cuteClass(14, "cute",123);

    cuteClass.InPrint();
    cuteClass.myString = "cuter";
    //cuteClass.OutPrint();

    

    Car car;
    car.Honk();
    cout << car.brand << " " << car.model << endl;


    Vehicle vehicle;
    vehicle.Honk();

    PotatoCar potatoCar;
    potatoCar.DriveAndEat();
    potatoCar.Honk();
    potatoCar.Eat();

    double block[9];
    cout << sizeof(block) << endl;
    cout << sizeof(block) / sizeof(double) << endl;

    

    thread t1(ThreadFunction);

    t1.join();
    */

    queue<int> tempQueue;
    
    
    cout << tempQueue.size() << endl;

    tempQueue.push(1);
    cout << tempQueue.size() << endl;

    
    tempQueue.pop();
    cout << tempQueue.size() << endl;
    

    return 0;
}




//Definition
void MyFunction(){
    cout << "HELLO MODERATION" << endl;
}
