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

    void brake(){
        currentSpeed-=20;
        cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"brake applied, "<<"current speed is "<<currentSpeed<<endl;
    }

    virtual ~Car() {};
};

class ManualCar : public Car{
    int currentGear;
public:
    ManualCar(string br, int mod) : Car(br, mod){
        currentGear=0;
    }
    void changeGear(int g){
        currentGear = g;
        cout<<"brand: "<<brand<<" | "<<"model: "<<model <<" | "<<"Changed gear to "<<g<<endl;
    }
};

class ElecticCar : public Car{
    int battery;
public:
    ElecticCar(string brand, int model, int battery): Car(brand, model){
        this->battery = battery;
    }

/*
this-> is used only to resolve ambiguity between member variables and parameters.

Another way (without ambiguity) :
    ElecticCar(string brand, int model, int b): Car(brand, model){
        battery = b;
    }

Using initializer list
    ElectricCar(string brand, int model, int battery) 
        : Car(brand, model), battery(battery) {
        
    }
Here, battery(battery) directly initializes the member variable battery.
No need for this-> because you are in the initializer list, not inside the function body.
*/

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
};

int main(){
    /*
    Car * manual = new ManualCar("tata", 23); 
    X WRONG WAY X
    A base class pointer can only call methods that are declared in the base class interface (and possibly overridden in derived).
    so will thro error for 
    manual->changeGear(6);
    or you need to make a virtual function inside the Car and then override in subclass.
    
    */
    ManualCar * manual = new ManualCar("tata", 23);
    manual->changeGear(6);
    manual->startEngine();
    manual->accelerate();
    manual->accelerate();
    manual->brake();
    manual->stopEngine();


    cout<<"X-------------------X--------------------------X--------------------X"<<endl;

    ElecticCar *electric = new ElecticCar("tesla", 01, 52);
    electric->getBattery();
    electric->startEngine();
    electric->chargeBattery();
    electric->accelerate();
    electric->accelerate();
    electric->brake();
    electric->stopEngine();
    electric->chargeBattery();
}

