#include<bits/stdc++.h>

using namespace std;

class Car{
protected:
    string brand;
    int model;
    bool isEngineOn;
    int currentSpeed;
public:
    Car(string b, int m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine(){
        if(isEngineOn){
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"engine is already started"<<endl;
        }
        else{
            isEngineOn = true;
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"Engine is started now"<<endl;
        }
    }

    void stopEngine(){
        if(!isEngineOn){
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"engine is already stopped"<<endl;
        }
        else{
            isEngineOn=false;
           cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"engine is stopped"<<endl;
        }
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"engine is not on"<<endl;
        }
        else{
            currentSpeed += 20;
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"Accelerated, current speed is "<<currentSpeed<<endl;
        }
    }

    void accelerate(int speed){ // Static polymorphism - function overloading
        if(!isEngineOn){
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"engine is not on"<<endl;
        }
        else{
            currentSpeed += speed;
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"Accelerated, current speed is "<<currentSpeed<<endl;
        }
    }

    void brake(){
        currentSpeed-=20;
        cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"brake applied, "<<"current speed is "<<currentSpeed<<endl;
    }

    virtual ~Car() {};
};


int main(){
    Car * car = new Car("tata", 23);
    car->startEngine();
    car->accelerate();
    car->accelerate();
    car->accelerate(100); 
    car->brake();
    car->stopEngine();
}

