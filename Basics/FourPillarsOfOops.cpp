#include<bits/stdc++.h>

using namespace std;

class Car{ //encapsulation
protected: //encapsulation
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

    virtual void accelerate() = 0; // Abstract method for dynamic polymorphism
    virtual void accelerate(int speed) = 0; // Abstract method for Static polymorphism
    virtual void brake() = 0; // Abstract method for dynamic polymorphism
    virtual ~Car() {};
};

class ManualCar : public Car{ // Inheritence
    int currentGear;
public:
    ManualCar(string br, int mod) : Car(br, mod){
        currentGear=0;
    }
    void changeGear(int g){
        currentGear = g;
        cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"Changed gear to "<<g<<endl;
    }
    void accelerate(){
        if(!isEngineOn){
            cout<<"engine is off, turn it on"<<endl;
            return;
        }
        currentSpeed+=35;
        cout<<"accelerated, current speed is "<<currentSpeed<<endl;
    }
    void accelerate(int speed){
        if(!isEngineOn){
            cout<<"engine is off, turn it on"<<endl;
            return;
        }
        currentSpeed+=speed;
        cout<<"accelerated, current speed is "<<currentSpeed<<endl;
    }
    void brake(){
        currentSpeed-=10;
        cout<<"Brake is applied, current speed is "<<currentSpeed<<endl;
    }
};

class ElecticCar : public Car{ // Inheritence
    int battery;
public:
    ElecticCar(string brand, int model, int battery): Car(brand, model){
        this->battery = battery;
    }

    void chargeBattery(){
        if(isEngineOn){
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"engine is on, first make it off"<<endl;
            return;
        }
        if(battery==100){
            cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"Battery is fully charged, unplug it"<<endl;
            return ;
        }
        battery += 25;
        if(battery>=100) battery = 100;
        cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"battery charged, current battery percentage is "<<battery<<endl;
    }

    int getBattery(){
        cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"current battery is "<<battery<<endl;
        return battery;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<"engine is off, turn it on"<<endl;
            return;
        }
        if(battery<=0){
            cout<<"battery low, charge it first, current battery "<<battery<<endl;
            return;
        }
        currentSpeed+=10;
        battery-=5;
        cout<<"accelerated, current speed is "<<currentSpeed<<", current battery: "<<battery<<endl;
    }

    void accelerate(int speed){
        if(!isEngineOn){
            cout<<"engine is off, turn it on"<<endl;
            return;
        }
        if(battery<=0){
            cout<<"battery low, charge it first, current battery "<<battery<<endl;
            return;
        }
        currentSpeed+=speed;
        battery-=5;
        cout<<"accelerated, current speed is "<<currentSpeed<<", current battery: "<<battery<<endl;
    }

    void brake(){
        currentSpeed-=5;
        cout<<"Brake is applied, current speed is "<<currentSpeed<<endl;
    }
};

int main(){
    ManualCar * manual = new ManualCar("tata", 23);
    manual->changeGear(6); // Abstraction, no need to know how gear is changing under the hood, just know gear can be changed like this
    manual->startEngine();
    manual->accelerate();
    manual->accelerate(100);
    manual->brake();
    manual->stopEngine();


    cout<<"X-------------------X--------------------------X--------------------X"<<endl;

    ElecticCar *electric = new ElecticCar("tesla", 01, 52);
    electric->getBattery();
    electric->startEngine();
    electric->chargeBattery();
    electric->accelerate();
    electric->accelerate(50);
    electric->brake();
    electric->stopEngine();
    electric->chargeBattery();
}

