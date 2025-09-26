#include<bits/stdc++.h>
using namespace std;

class Singleton{
    static Singleton * s;
    Singleton(){
        cout<<"new object created"<<endl;
    }
public:
    static Singleton* getInstance(){ //It’s a static function — can be called without creating an object.
        if(s==NULL){
            s = new Singleton();
        }
        return s;
    }
};

//Static members must be defined outside the class.
Singleton* Singleton::s=NULL;

int main(){
    Singleton * s1 = Singleton::getInstance(); // call the static function
    Singleton * s2 = Singleton::getInstance();

    cout<< (s1==s2) <<endl;
}