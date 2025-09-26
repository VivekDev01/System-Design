#include<bits/stdc++.h>
using namespace std;

class Singleton{
    static Singleton * s;
    static mutex mtx;
    Singleton(){
        cout<<"new object created"<<endl;
    }
public:
    static Singleton* getInstance(){ //It’s a static function — can be called without creating an object.
        if(s==NULL){
            lock_guard<mutex> lock(mtx);  // Lock only if needed
            if(s==NULL){ // Second check (after acquiring lock)
                s = new Singleton();
            }
        }
        return s;
    }
};

//Static members must be defined outside the class.
Singleton* Singleton::s=NULL;
mutex Singleton::mtx;

int main(){
    Singleton * s1 = Singleton::getInstance(); // call the static function
    Singleton * s2 = Singleton::getInstance();

    cout<< (s1==s2) <<endl;
}