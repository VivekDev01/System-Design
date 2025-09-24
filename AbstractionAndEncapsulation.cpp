#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}  // should make a destructor virtual if your class is meant to be a base class
};

/*
Rule of Thumb
    If a class has any virtual function, always make the destructor virtual.
    This prevents subtle bugs and memory leaks when using polymorphism.
*/


/* 
The = 0 tells the compiler:
    “This is a pure virtual function, and any derived class must provide an implementation.”

Why we use pure virtual functions: 
    To define a common interface for all derived classes.
    It enforces that every subclass implements specific behavior.

A class with at least one pure virtual function becomes an abstract class.
    You cannot create objects of an abstract class.

| Feature   | Meaning                                                                       |
| --------- | ----------------------------------------------------------------------------- |
| `virtual` | Can be overridden in derived class                                            |
| `= 0`     | Pure virtual → must be implemented in derived class; makes the class abstract |
*/


class SportsCar : public Car{
    private:
        string brand;
        int model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
    
    public:
        SportsCar(string b, int m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        void startEngine() override{ //using override helps ensure that your function’s signature exactly matches the base class, if 
            isEngineOn = true;
            cout<<brand<<", "<<model<<", "<<"engine is started"<<endl;
        }

/*
if override keyword is there then the compiler checks:
    “Does a virtual function with this exact name, return type, and parameters exist in the base class?”
    If it doesn’t match, the compiler throws an error. This prevents accidental mistakes.

We should always use override keyword bcz function signature should not be changed.
*/

        void shiftGear(int gear){
            if(!isEngineOn){
                cout<<"engine is not on, pls on the engine first"<<endl;
                return ;
            }
            currentGear=gear;
            cout<<"Gear shifted to "<<currentGear<<endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout<<"engine is not on, pls on the engine first"<<endl;
                return ;
            }
            currentSpeed+=10;
            cout<<"Accelerated by "<<10<<"current speed is "<<currentSpeed<<endl;
        }

        void brake(){
            currentSpeed-=10;
            if(currentSpeed<0) currentSpeed = 0;
            cout<<"brake applied, current speed is "<<currentSpeed<<endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentGear=0;
            currentSpeed = 0;
            cout<<"engine is stopped now"<<endl;
        }
};

int main() {
    Car * newCar = new SportsCar("tata", 23);

/*
1. Avoid Raw new and delete
    Using new and delete manually is error-prone.
    Use smart pointers instead:

    #include <memory>
    unique_ptr<Car> newCar = make_unique<SportsCar>("tata", 23);  
*/

    newCar->startEngine();
    newCar->shiftGear(2);
    newCar->accelerate();
    newCar->accelerate();
    newCar->brake();
    newCar->shiftGear(5);
    newCar->stopEngine();
    newCar->accelerate();
    
    delete newCar;
}
