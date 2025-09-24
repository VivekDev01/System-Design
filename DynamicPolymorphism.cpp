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

    virtual void accelerate() = 0; // Abstract method for dynamic polymorphism
    virtual void brake() = 0; // Abstract method for dynamic polymorphism
    virtual ~Car() {}; //Rule of thumb: If your class "owns" something that requires manual release, write a destructor.
};

/*
If your class only uses: Primitive types (int, double, bool), Standard library objects (std::string, std::vector, std::map, etc.)
Reason: These types automatically clean themselves up when they go out of scope.

Virtual destructors Needed only for base classes when objects are deleted through a base class pointer.

Best Practices
1. Default destructor is enough if your class only uses standard types.
2. Use destructors for cleanup only if your class owns manual resources.
3. Always delete what you new somewhere:
    In destructor if object is owned by class
    Or in main / wherever you new it, if ownership is external

Virtual destructor in base classes if you intend to delete derived objects through base pointers.

| Situation                        | Destructor Needed? | Notes                                    |
| -------------------------------- | ------------------ | ---------------------------------------- |
| Only primitive and STL members   | ❌                  | Compiler handles cleanup                 |
| Dynamic memory / files / sockets | ✅                  | Free resources in destructor             |
| Base class for polymorphism      | ✅ (virtual)        | Ensure derived destructor called         |
| Empty body                       | Optional           | Still calls member destructors           |
| Using smart pointers             | ❌                  | They auto-clean, no manual delete needed |

*/

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
    void accelerate(){
        if(!isEngineOn){
            cout<<"engine is off, turn it on"<<endl;
            return;
        }
        currentSpeed+=35;
        cout<<"accelerated, current speed is "<<currentSpeed<<endl;
    }
    void brake(){
        currentSpeed-=10;
        cout<<"Brake is applied, current speed is "<<currentSpeed<<endl;
    }
};

class ElecticCar : public Car{
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
        cout<<"accelerated, current speed is "<<currentSpeed<<"current battery: "<<battery<<endl;
    }

    void brake(){
        currentSpeed-=5;
        cout<<"Brake is applied, current speed is "<<currentSpeed<<endl;
    }
};

int main(){
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

